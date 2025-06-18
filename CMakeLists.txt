cmake_minimum_required(VERSION 3.13)
project(ImplicitCtorChecker)

find_package(LLVM REQUIRED CONFIG)
find_package(Clang REQUIRED CONFIG)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${LLVM_INCLUDE_DIRS} ${CLANG_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

add_executable(implicit_ctor ImplicitCtorReporter.cpp)

llvm_map_components_to_libnames(llvm_libs
  Support
  )

target_link_libraries(implicit_ctor
  PRIVATE
  clangTooling
  clangBasic
  clangASTMatchers
  ${llvm_libs}
)


