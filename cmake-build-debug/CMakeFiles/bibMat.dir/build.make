# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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

#Suppress display of executed commands.
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
CMAKE_SOURCE_DIR = "/Users/mateipruteanu/Documents/Clion Projects/bibMat"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/mateipruteanu/Documents/Clion Projects/bibMat/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/bibMat.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/bibMat.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bibMat.dir/flags.make

CMakeFiles/bibMat.dir/main.cpp.o: CMakeFiles/bibMat.dir/flags.make
CMakeFiles/bibMat.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/mateipruteanu/Documents/Clion Projects/bibMat/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bibMat.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bibMat.dir/main.cpp.o -c "/Users/mateipruteanu/Documents/Clion Projects/bibMat/main.cpp"

CMakeFiles/bibMat.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bibMat.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/mateipruteanu/Documents/Clion Projects/bibMat/main.cpp" > CMakeFiles/bibMat.dir/main.cpp.i

CMakeFiles/bibMat.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bibMat.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/mateipruteanu/Documents/Clion Projects/bibMat/main.cpp" -o CMakeFiles/bibMat.dir/main.cpp.s

# Object files for target bibMat
bibMat_OBJECTS = \
"CMakeFiles/bibMat.dir/main.cpp.o"

# External object files for target bibMat
bibMat_EXTERNAL_OBJECTS =

bibMat: CMakeFiles/bibMat.dir/main.cpp.o
bibMat: CMakeFiles/bibMat.dir/build.make
bibMat: CMakeFiles/bibMat.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/mateipruteanu/Documents/Clion Projects/bibMat/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bibMat"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bibMat.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bibMat.dir/build: bibMat
.PHONY : CMakeFiles/bibMat.dir/build

CMakeFiles/bibMat.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bibMat.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bibMat.dir/clean

CMakeFiles/bibMat.dir/depend:
	cd "/Users/mateipruteanu/Documents/Clion Projects/bibMat/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/mateipruteanu/Documents/Clion Projects/bibMat" "/Users/mateipruteanu/Documents/Clion Projects/bibMat" "/Users/mateipruteanu/Documents/Clion Projects/bibMat/cmake-build-debug" "/Users/mateipruteanu/Documents/Clion Projects/bibMat/cmake-build-debug" "/Users/mateipruteanu/Documents/Clion Projects/bibMat/cmake-build-debug/CMakeFiles/bibMat.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/bibMat.dir/depend

