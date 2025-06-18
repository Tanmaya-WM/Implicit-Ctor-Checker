#include "clang/AST/AST.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/Frontend/FrontendActions.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "clang/Tooling/AllTUsExecution.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/raw_ostream.h"

using namespace clang;
using namespace clang::tooling;
using namespace clang::ast_matchers;

static llvm::cl::OptionCategory Category("implicit-ctor-reporter");

class ImplicitCtorCallback : public MatchFinder::MatchCallback {
public:
    void run(const MatchFinder::MatchResult &Result) override {
        const auto *Var = Result.Nodes.getNodeAs<VarDecl>("varWithCtor");
        if (!Var)
            return;

        const auto *CtorExpr = dyn_cast_or_null<CXXConstructExpr>(Var->getInit());
        if (!CtorExpr)
            return;

        // Heuristic: if no parens or braces, it's likely implicit
        if (CtorExpr->getParenOrBraceRange().isValid())
            return;

        const auto *CtorDecl = CtorExpr->getConstructor();
        if (!CtorDecl)
            return;

        const auto *SM = Result.SourceManager;
        SourceLocation Loc = Var->getLocation();
        if (!Loc.isValid() || !SM || !Loc.isFileID())
            return;

        std::string File = SM->getFilename(Loc).str();
        unsigned Line = SM->getSpellingLineNumber(Loc);
        unsigned Col = SM->getSpellingColumnNumber(Loc);
        std::string VarName = Var->getNameAsString();
        std::string ClassName = CtorDecl->getParent()->getQualifiedNameAsString();

        llvm::outs() << File << ":" << Line << ":" << Col
                     << ": note: '" << VarName
                     << "' initialized using implicit constructor '"
                     << ClassName << "::" << CtorDecl->getNameAsString() << "'\n";
    }
};

int main(int argc, const char **argv) {
    auto ExpectedParser = CommonOptionsParser::create(argc, argv, Category);
    if (!ExpectedParser) {
        llvm::errs() << ExpectedParser.takeError();
        return 1;
    }

    ClangTool Tool(ExpectedParser->getCompilations(),
                   ExpectedParser->getSourcePathList());

    MatchFinder Finder;
    ImplicitCtorCallback Callback;

    Finder.addMatcher(
        varDecl(
            hasInitializer(
                cxxConstructExpr().bind("ctorExpr")
            )
        ).bind("varWithCtor"),
        &Callback
    );

    return Tool.run(newFrontendActionFactory(&Finder).get());
}

