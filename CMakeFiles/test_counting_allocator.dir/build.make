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
include CMakeFiles/test_counting_allocator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_counting_allocator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_counting_allocator.dir/flags.make

CMakeFiles/test_counting_allocator.dir/test_counting_allocator.cpp.o: CMakeFiles/test_counting_allocator.dir/flags.make
CMakeFiles/test_counting_allocator.dir/test_counting_allocator.cpp.o: test_counting_allocator.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/dom/Desktop/cs585/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test_counting_allocator.dir/test_counting_allocator.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test_counting_allocator.dir/test_counting_allocator.cpp.o -c /home/dom/Desktop/cs585/test_counting_allocator.cpp

CMakeFiles/test_counting_allocator.dir/test_counting_allocator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_counting_allocator.dir/test_counting_allocator.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/dom/Desktop/cs585/test_counting_allocator.cpp > CMakeFiles/test_counting_allocator.dir/test_counting_allocator.cpp.i

CMakeFiles/test_counting_allocator.dir/test_counting_allocator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_counting_allocator.dir/test_counting_allocator.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/dom/Desktop/cs585/test_counting_allocator.cpp -o CMakeFiles/test_counting_allocator.dir/test_counting_allocator.cpp.s

CMakeFiles/test_counting_allocator.dir/test_counting_allocator.cpp.o.requires:
.PHONY : CMakeFiles/test_counting_allocator.dir/test_counting_allocator.cpp.o.requires

CMakeFiles/test_counting_allocator.dir/test_counting_allocator.cpp.o.provides: CMakeFiles/test_counting_allocator.dir/test_counting_allocator.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_counting_allocator.dir/build.make CMakeFiles/test_counting_allocator.dir/test_counting_allocator.cpp.o.provides.build
.PHONY : CMakeFiles/test_counting_allocator.dir/test_counting_allocator.cpp.o.provides

CMakeFiles/test_counting_allocator.dir/test_counting_allocator.cpp.o.provides.build: CMakeFiles/test_counting_allocator.dir/test_counting_allocator.cpp.o

# Object files for target test_counting_allocator
test_counting_allocator_OBJECTS = \
"CMakeFiles/test_counting_allocator.dir/test_counting_allocator.cpp.o"

# External object files for target test_counting_allocator
test_counting_allocator_EXTERNAL_OBJECTS =

test_counting_allocator: CMakeFiles/test_counting_allocator.dir/test_counting_allocator.cpp.o
test_counting_allocator: CMakeFiles/test_counting_allocator.dir/build.make
test_counting_allocator: CMakeFiles/test_counting_allocator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable test_counting_allocator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_counting_allocator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_counting_allocator.dir/build: test_counting_allocator
.PHONY : CMakeFiles/test_counting_allocator.dir/build

CMakeFiles/test_counting_allocator.dir/requires: CMakeFiles/test_counting_allocator.dir/test_counting_allocator.cpp.o.requires
.PHONY : CMakeFiles/test_counting_allocator.dir/requires

CMakeFiles/test_counting_allocator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_counting_allocator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_counting_allocator.dir/clean

CMakeFiles/test_counting_allocator.dir/depend:
	cd /home/dom/Desktop/cs585 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dom/Desktop/cs585 /home/dom/Desktop/cs585 /home/dom/Desktop/cs585 /home/dom/Desktop/cs585 /home/dom/Desktop/cs585/CMakeFiles/test_counting_allocator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_counting_allocator.dir/depend

