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
CMAKE_SOURCE_DIR = D:\CLionProjects\winnerTree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CLionProjects\winnerTree\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/winnerTree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/winnerTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/winnerTree.dir/flags.make

CMakeFiles/winnerTree.dir/main.cpp.obj: CMakeFiles/winnerTree.dir/flags.make
CMakeFiles/winnerTree.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CLionProjects\winnerTree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/winnerTree.dir/main.cpp.obj"
	F:\software\x86_64-6.4.0-release-posix-sjlj-rt_v5-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\winnerTree.dir\main.cpp.obj -c D:\CLionProjects\winnerTree\main.cpp

CMakeFiles/winnerTree.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/winnerTree.dir/main.cpp.i"
	F:\software\x86_64-6.4.0-release-posix-sjlj-rt_v5-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\CLionProjects\winnerTree\main.cpp > CMakeFiles\winnerTree.dir\main.cpp.i

CMakeFiles/winnerTree.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/winnerTree.dir/main.cpp.s"
	F:\software\x86_64-6.4.0-release-posix-sjlj-rt_v5-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\CLionProjects\winnerTree\main.cpp -o CMakeFiles\winnerTree.dir\main.cpp.s

# Object files for target winnerTree
winnerTree_OBJECTS = \
"CMakeFiles/winnerTree.dir/main.cpp.obj"

# External object files for target winnerTree
winnerTree_EXTERNAL_OBJECTS =

winnerTree.exe: CMakeFiles/winnerTree.dir/main.cpp.obj
winnerTree.exe: CMakeFiles/winnerTree.dir/build.make
winnerTree.exe: CMakeFiles/winnerTree.dir/linklibs.rsp
winnerTree.exe: CMakeFiles/winnerTree.dir/objects1.rsp
winnerTree.exe: CMakeFiles/winnerTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CLionProjects\winnerTree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable winnerTree.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\winnerTree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/winnerTree.dir/build: winnerTree.exe

.PHONY : CMakeFiles/winnerTree.dir/build

CMakeFiles/winnerTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\winnerTree.dir\cmake_clean.cmake
.PHONY : CMakeFiles/winnerTree.dir/clean

CMakeFiles/winnerTree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CLionProjects\winnerTree D:\CLionProjects\winnerTree D:\CLionProjects\winnerTree\cmake-build-debug D:\CLionProjects\winnerTree\cmake-build-debug D:\CLionProjects\winnerTree\cmake-build-debug\CMakeFiles\winnerTree.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/winnerTree.dir/depend

