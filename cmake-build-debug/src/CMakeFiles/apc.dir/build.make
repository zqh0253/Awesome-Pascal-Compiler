# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.14.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.14.5/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/chenzhuo/work/Awesome-Pascal-Compiler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/chenzhuo/work/Awesome-Pascal-Compiler/cmake-build-debug

# Include any dependencies generated for this target.
include src/CMakeFiles/apc.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/apc.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/apc.dir/flags.make

src/CMakeFiles/apc.dir/main.cpp.o: src/CMakeFiles/apc.dir/flags.make
src/CMakeFiles/apc.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chenzhuo/work/Awesome-Pascal-Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/apc.dir/main.cpp.o"
	cd /Users/chenzhuo/work/Awesome-Pascal-Compiler/cmake-build-debug/src && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/apc.dir/main.cpp.o -c /Users/chenzhuo/work/Awesome-Pascal-Compiler/src/main.cpp

src/CMakeFiles/apc.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/apc.dir/main.cpp.i"
	cd /Users/chenzhuo/work/Awesome-Pascal-Compiler/cmake-build-debug/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chenzhuo/work/Awesome-Pascal-Compiler/src/main.cpp > CMakeFiles/apc.dir/main.cpp.i

src/CMakeFiles/apc.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/apc.dir/main.cpp.s"
	cd /Users/chenzhuo/work/Awesome-Pascal-Compiler/cmake-build-debug/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chenzhuo/work/Awesome-Pascal-Compiler/src/main.cpp -o CMakeFiles/apc.dir/main.cpp.s

# Object files for target apc
apc_OBJECTS = \
"CMakeFiles/apc.dir/main.cpp.o"

# External object files for target apc
apc_EXTERNAL_OBJECTS =

src/apc: src/CMakeFiles/apc.dir/main.cpp.o
src/apc: src/CMakeFiles/apc.dir/build.make
src/apc: src/ast/libast.a
src/apc: src/gen/libgen.a
src/apc: src/parser/libparser.a
src/apc: src/sem/libsem.a
src/apc: src/ast/libast.a
src/apc: src/CMakeFiles/apc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/chenzhuo/work/Awesome-Pascal-Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable apc"
	cd /Users/chenzhuo/work/Awesome-Pascal-Compiler/cmake-build-debug/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/apc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/apc.dir/build: src/apc

.PHONY : src/CMakeFiles/apc.dir/build

src/CMakeFiles/apc.dir/clean:
	cd /Users/chenzhuo/work/Awesome-Pascal-Compiler/cmake-build-debug/src && $(CMAKE_COMMAND) -P CMakeFiles/apc.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/apc.dir/clean

src/CMakeFiles/apc.dir/depend:
	cd /Users/chenzhuo/work/Awesome-Pascal-Compiler/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chenzhuo/work/Awesome-Pascal-Compiler /Users/chenzhuo/work/Awesome-Pascal-Compiler/src /Users/chenzhuo/work/Awesome-Pascal-Compiler/cmake-build-debug /Users/chenzhuo/work/Awesome-Pascal-Compiler/cmake-build-debug/src /Users/chenzhuo/work/Awesome-Pascal-Compiler/cmake-build-debug/src/CMakeFiles/apc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/apc.dir/depend

