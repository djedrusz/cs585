# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/dom/Desktop/cs585

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dom/Desktop/cs585

# Include any dependencies generated for this target.
include CMakeFiles/game.m.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/game.m.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game.m.dir/flags.make

CMakeFiles/game.m.dir/game.m.cpp.o: CMakeFiles/game.m.dir/flags.make
CMakeFiles/game.m.dir/game.m.cpp.o: game.m.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dom/Desktop/cs585/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/game.m.dir/game.m.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/game.m.dir/game.m.cpp.o -c /home/dom/Desktop/cs585/game.m.cpp

CMakeFiles/game.m.dir/game.m.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.m.dir/game.m.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dom/Desktop/cs585/game.m.cpp > CMakeFiles/game.m.dir/game.m.cpp.i

CMakeFiles/game.m.dir/game.m.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.m.dir/game.m.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dom/Desktop/cs585/game.m.cpp -o CMakeFiles/game.m.dir/game.m.cpp.s

CMakeFiles/game.m.dir/game.m.cpp.o.requires:
.PHONY : CMakeFiles/game.m.dir/game.m.cpp.o.requires

CMakeFiles/game.m.dir/game.m.cpp.o.provides: CMakeFiles/game.m.dir/game.m.cpp.o.requires
	$(MAKE) -f CMakeFiles/game.m.dir/build.make CMakeFiles/game.m.dir/game.m.cpp.o.provides.build
.PHONY : CMakeFiles/game.m.dir/game.m.cpp.o.provides

CMakeFiles/game.m.dir/game.m.cpp.o.provides.build: CMakeFiles/game.m.dir/game.m.cpp.o

# Object files for target game.m
game_m_OBJECTS = \
"CMakeFiles/game.m.dir/game.m.cpp.o"

# External object files for target game.m
game_m_EXTERNAL_OBJECTS =

game.m: CMakeFiles/game.m.dir/game.m.cpp.o
game.m: CMakeFiles/game.m.dir/build.make
game.m: CMakeFiles/game.m.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable game.m"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game.m.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game.m.dir/build: game.m
.PHONY : CMakeFiles/game.m.dir/build

CMakeFiles/game.m.dir/requires: CMakeFiles/game.m.dir/game.m.cpp.o.requires
.PHONY : CMakeFiles/game.m.dir/requires

CMakeFiles/game.m.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game.m.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game.m.dir/clean

CMakeFiles/game.m.dir/depend:
	cd /home/dom/Desktop/cs585 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dom/Desktop/cs585 /home/dom/Desktop/cs585 /home/dom/Desktop/cs585 /home/dom/Desktop/cs585 /home/dom/Desktop/cs585/CMakeFiles/game.m.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/game.m.dir/depend
