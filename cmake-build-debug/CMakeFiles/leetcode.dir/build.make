# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/main/cpp/src/leetcode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/main/cpp/src/leetcode/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/leetcode.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/leetcode.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/leetcode.dir/flags.make

CMakeFiles/leetcode.dir/swordOffer/dfs/maxDepth.cc.o: CMakeFiles/leetcode.dir/flags.make
CMakeFiles/leetcode.dir/swordOffer/dfs/maxDepth.cc.o: ../swordOffer/dfs/maxDepth.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/main/cpp/src/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/leetcode.dir/swordOffer/dfs/maxDepth.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/leetcode.dir/swordOffer/dfs/maxDepth.cc.o -c /Users/main/cpp/src/leetcode/swordOffer/dfs/maxDepth.cc

CMakeFiles/leetcode.dir/swordOffer/dfs/maxDepth.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/leetcode.dir/swordOffer/dfs/maxDepth.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/main/cpp/src/leetcode/swordOffer/dfs/maxDepth.cc > CMakeFiles/leetcode.dir/swordOffer/dfs/maxDepth.cc.i

CMakeFiles/leetcode.dir/swordOffer/dfs/maxDepth.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/leetcode.dir/swordOffer/dfs/maxDepth.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/main/cpp/src/leetcode/swordOffer/dfs/maxDepth.cc -o CMakeFiles/leetcode.dir/swordOffer/dfs/maxDepth.cc.s

# Object files for target leetcode
leetcode_OBJECTS = \
"CMakeFiles/leetcode.dir/swordOffer/dfs/maxDepth.cc.o"

# External object files for target leetcode
leetcode_EXTERNAL_OBJECTS =

leetcode: CMakeFiles/leetcode.dir/swordOffer/dfs/maxDepth.cc.o
leetcode: CMakeFiles/leetcode.dir/build.make
leetcode: CMakeFiles/leetcode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/main/cpp/src/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable leetcode"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/leetcode.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/leetcode.dir/build: leetcode

.PHONY : CMakeFiles/leetcode.dir/build

CMakeFiles/leetcode.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/leetcode.dir/cmake_clean.cmake
.PHONY : CMakeFiles/leetcode.dir/clean

CMakeFiles/leetcode.dir/depend:
	cd /Users/main/cpp/src/leetcode/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/main/cpp/src/leetcode /Users/main/cpp/src/leetcode /Users/main/cpp/src/leetcode/cmake-build-debug /Users/main/cpp/src/leetcode/cmake-build-debug /Users/main/cpp/src/leetcode/cmake-build-debug/CMakeFiles/leetcode.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/leetcode.dir/depend

