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
CMAKE_SOURCE_DIR = D:\CLionProjects\BiSortTree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CLionProjects\BiSortTree\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BiSortTree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BiSortTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BiSortTree.dir/flags.make

CMakeFiles/BiSortTree.dir/BiSortT.cpp.obj: CMakeFiles/BiSortTree.dir/flags.make
CMakeFiles/BiSortTree.dir/BiSortT.cpp.obj: ../BiSortT.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionProjects\BiSortTree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BiSortTree.dir/BiSortT.cpp.obj"
	F:\software\x86_64-6.4.0-release-posix-sjlj-rt_v5-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\BiSortTree.dir\BiSortT.cpp.obj -c D:\CLionProjects\BiSortTree\BiSortT.cpp

CMakeFiles/BiSortTree.dir/BiSortT.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BiSortTree.dir/BiSortT.cpp.i"
	F:\software\x86_64-6.4.0-release-posix-sjlj-rt_v5-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CLionProjects\BiSortTree\BiSortT.cpp > CMakeFiles\BiSortTree.dir\BiSortT.cpp.i

CMakeFiles/BiSortTree.dir/BiSortT.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BiSortTree.dir/BiSortT.cpp.s"
	F:\software\x86_64-6.4.0-release-posix-sjlj-rt_v5-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CLionProjects\BiSortTree\BiSortT.cpp -o CMakeFiles\BiSortTree.dir\BiSortT.cpp.s

# Object files for target BiSortTree
BiSortTree_OBJECTS = \
"CMakeFiles/BiSortTree.dir/BiSortT.cpp.obj"

# External object files for target BiSortTree
BiSortTree_EXTERNAL_OBJECTS =

BiSortTree.exe: CMakeFiles/BiSortTree.dir/BiSortT.cpp.obj
BiSortTree.exe: CMakeFiles/BiSortTree.dir/build.make
BiSortTree.exe: CMakeFiles/BiSortTree.dir/linklibs.rsp
BiSortTree.exe: CMakeFiles/BiSortTree.dir/objects1.rsp
BiSortTree.exe: CMakeFiles/BiSortTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CLionProjects\BiSortTree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BiSortTree.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BiSortTree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BiSortTree.dir/build: BiSortTree.exe

.PHONY : CMakeFiles/BiSortTree.dir/build

CMakeFiles/BiSortTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BiSortTree.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BiSortTree.dir/clean

CMakeFiles/BiSortTree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CLionProjects\BiSortTree D:\CLionProjects\BiSortTree D:\CLionProjects\BiSortTree\cmake-build-debug D:\CLionProjects\BiSortTree\cmake-build-debug D:\CLionProjects\BiSortTree\cmake-build-debug\CMakeFiles\BiSortTree.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BiSortTree.dir/depend

