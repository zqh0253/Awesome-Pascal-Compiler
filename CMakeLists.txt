cmake_minimum_required(VERSION 3.14)
project(awesome-pascal-compiler)

set(CMAKE_CXX_STANDARD 14)

# LLVM
find_package(LLVM REQUIRED)
include_directories(${LLVM_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})

add_subdirectory(src)
add_subdirectory(test)
