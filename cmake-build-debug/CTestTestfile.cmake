# CMake generated Testfile for 
# Source directory: /Users/chenzhuo/work/Awesome-Pascal-Compiler
# Build directory: /Users/chenzhuo/work/Awesome-Pascal-Compiler/cmake-build-debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(apc-test "sh" "-c" "apc < ./test/pasfile/stmtTest.pas")
set_tests_properties(apc-test PROPERTIES  _BACKTRACE_TRIPLES "/Users/chenzhuo/work/Awesome-Pascal-Compiler/CMakeLists.txt;13;add_test;/Users/chenzhuo/work/Awesome-Pascal-Compiler/CMakeLists.txt;0;")
subdirs("src")
