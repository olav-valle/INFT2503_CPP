# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/olav/git/INFT2503_CPP/01/lesson/toerpot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/olav/git/INFT2503_CPP/01/lesson/toerpot/build

# Include any dependencies generated for this target.
include CMakeFiles/toerpot.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/toerpot.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/toerpot.dir/flags.make

CMakeFiles/toerpot.dir/toerpot.cpp.o: CMakeFiles/toerpot.dir/flags.make
CMakeFiles/toerpot.dir/toerpot.cpp.o: ../toerpot.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/olav/git/INFT2503_CPP/01/lesson/toerpot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/toerpot.dir/toerpot.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/toerpot.dir/toerpot.cpp.o -c /home/olav/git/INFT2503_CPP/01/lesson/toerpot/toerpot.cpp

CMakeFiles/toerpot.dir/toerpot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/toerpot.dir/toerpot.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/olav/git/INFT2503_CPP/01/lesson/toerpot/toerpot.cpp > CMakeFiles/toerpot.dir/toerpot.cpp.i

CMakeFiles/toerpot.dir/toerpot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/toerpot.dir/toerpot.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/olav/git/INFT2503_CPP/01/lesson/toerpot/toerpot.cpp -o CMakeFiles/toerpot.dir/toerpot.cpp.s

# Object files for target toerpot
toerpot_OBJECTS = \
"CMakeFiles/toerpot.dir/toerpot.cpp.o"

# External object files for target toerpot
toerpot_EXTERNAL_OBJECTS =

toerpot: CMakeFiles/toerpot.dir/toerpot.cpp.o
toerpot: CMakeFiles/toerpot.dir/build.make
toerpot: CMakeFiles/toerpot.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/olav/git/INFT2503_CPP/01/lesson/toerpot/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable toerpot"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/toerpot.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/toerpot.dir/build: toerpot

.PHONY : CMakeFiles/toerpot.dir/build

CMakeFiles/toerpot.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/toerpot.dir/cmake_clean.cmake
.PHONY : CMakeFiles/toerpot.dir/clean

CMakeFiles/toerpot.dir/depend:
	cd /home/olav/git/INFT2503_CPP/01/lesson/toerpot/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/olav/git/INFT2503_CPP/01/lesson/toerpot /home/olav/git/INFT2503_CPP/01/lesson/toerpot /home/olav/git/INFT2503_CPP/01/lesson/toerpot/build /home/olav/git/INFT2503_CPP/01/lesson/toerpot/build /home/olav/git/INFT2503_CPP/01/lesson/toerpot/build/CMakeFiles/toerpot.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/toerpot.dir/depend
