# Implicit-Ctor-Checker
# Implicit Constructor Invocation Detector

This project is a **Clang-based static analysis tool** that detects **implicit constructor invocations** in C++ code. It identifies cases where default or copy constructors are **called implicitly** (without explicit `()` or function-style syntax).

---

🔍 Purpose

In C++, constructors can be invoked **implicitly** during object creation. These calls are not always visible in the source code, which can make debugging and code analysis difficult.  
This tool helps developers and students understand **where** and **how** implicit constructor calls occur in C++ programs.

---

📁 Directory Structure
#implicit-ctor-checker/
#├── CMakeLists.txt # Build configuration for the tool
#├── ImplicitCtorReporter.cpp # Main source file for the Clang AST-based plugin
#├── test.cpp # Sample C++ test file
#├── test2.cpp # More test files to validate behavior
#├── test3.cpp
#├── ...
#└── README.md # This file

🔧Building the Plugin
cd /home/ubuntu/work/projects/assignments/implicit-ctor-checker/
mkdir BUILD && cd BUILD
cmake .. -DCMAKE_PREFIX_PATH=/home/ubuntu/work/projects/llvm_install
make

🚀 Running the Tool
Run the analysis on any C++ file:
./implicit_ctor ../test.cpp -- -std=c++17
