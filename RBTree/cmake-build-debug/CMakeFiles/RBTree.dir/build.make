# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "F:\software\CLion 2020.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "F:\software\CLion 2020.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\CLionProjects\RBTree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CLionProjects\RBTree\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RBTree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RBTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RBTree.dir/flags.make

CMakeFiles/RBTree.dir/RBTree.cpp.obj: CMakeFiles/RBTree.dir/flags.make
CMakeFiles/RBTree.dir/RBTree.cpp.obj: ../RBTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionProjects\RBTree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RBTree.dir/RBTree.cpp.obj"
	F:\software\x86_64-6.4.0-release-posix-sjlj-rt_v5-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\RBTree.dir\RBTree.cpp.obj -c D:\CLionProjects\RBTree\RBTree.cpp

CMakeFiles/RBTree.dir/RBTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RBTree.dir/RBTree.cpp.i"
	F:\software\x86_64-6.4.0-release-posix-sjlj-rt_v5-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CLionProjects\RBTree\RBTree.cpp > CMakeFiles\RBTree.dir\RBTree.cpp.i

CMakeFiles/RBTree.dir/RBTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RBTree.dir/RBTree.cpp.s"
	F:\software\x86_64-6.4.0-release-posix-sjlj-rt_v5-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CLionProjects\RBTree\RBTree.cpp -o CMakeFiles\RBTree.dir\RBTree.cpp.s

# Object files for target RBTree
RBTree_OBJECTS = \
"CMakeFiles/RBTree.dir/RBTree.cpp.obj"

# External object files for target RBTree
RBTree_EXTERNAL_OBJECTS =

RBTree.exe: CMakeFiles/RBTree.dir/RBTree.cpp.obj
RBTree.exe: CMakeFiles/RBTree.dir/build.make
RBTree.exe: CMakeFiles/RBTree.dir/linklibs.rsp
RBTree.exe: CMakeFiles/RBTree.dir/objects1.rsp
RBTree.exe: CMakeFiles/RBTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CLionProjects\RBTree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable RBTree.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\RBTree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RBTree.dir/build: RBTree.exe

.PHONY : CMakeFiles/RBTree.dir/build

CMakeFiles/RBTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\RBTree.dir\cmake_clean.cmake
.PHONY : CMakeFiles/RBTree.dir/clean

CMakeFiles/RBTree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CLionProjects\RBTree D:\CLionProjects\RBTree D:\CLionProjects\RBTree\cmake-build-debug D:\CLionProjects\RBTree\cmake-build-debug D:\CLionProjects\RBTree\cmake-build-debug\CMakeFiles\RBTree.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RBTree.dir/depend
