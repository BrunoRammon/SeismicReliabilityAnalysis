# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/bruno/SCIEnCE/petsc/arch-linux2-c-opt/bin/cmake

# The command to remove a file.
RM = /home/bruno/SCIEnCE/petsc/arch-linux2-c-opt/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bruno/Documents/TestesCpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bruno/Documents/TestesCpp/build

# Include any dependencies generated for this target.
include CMakeFiles/test32.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test32.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test32.dir/flags.make

CMakeFiles/test32.dir/test32.cpp.o: CMakeFiles/test32.dir/flags.make
CMakeFiles/test32.dir/test32.cpp.o: ../test32.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bruno/Documents/TestesCpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test32.dir/test32.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test32.dir/test32.cpp.o -c /home/bruno/Documents/TestesCpp/test32.cpp

CMakeFiles/test32.dir/test32.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test32.dir/test32.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bruno/Documents/TestesCpp/test32.cpp > CMakeFiles/test32.dir/test32.cpp.i

CMakeFiles/test32.dir/test32.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test32.dir/test32.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bruno/Documents/TestesCpp/test32.cpp -o CMakeFiles/test32.dir/test32.cpp.s

# Object files for target test32
test32_OBJECTS = \
"CMakeFiles/test32.dir/test32.cpp.o"

# External object files for target test32
test32_EXTERNAL_OBJECTS =

test32: CMakeFiles/test32.dir/test32.cpp.o
test32: CMakeFiles/test32.dir/build.make
test32: libCGAL_Qt5_moc_and_resources.a
test32: /usr/lib/x86_64-linux-gnu/libmpfr.so
test32: /usr/lib/x86_64-linux-gnu/libgmp.so
test32: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.12.8
test32: /usr/lib/x86_64-linux-gnu/libQt5Svg.so.5.12.8
test32: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.12.8
test32: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.12.8
test32: /usr/lib/x86_64-linux-gnu/libQt5Xml.so.5.12.8
test32: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
test32: CMakeFiles/test32.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bruno/Documents/TestesCpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test32"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test32.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test32.dir/build: test32

.PHONY : CMakeFiles/test32.dir/build

CMakeFiles/test32.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test32.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test32.dir/clean

CMakeFiles/test32.dir/depend:
	cd /home/bruno/Documents/TestesCpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bruno/Documents/TestesCpp /home/bruno/Documents/TestesCpp /home/bruno/Documents/TestesCpp/build /home/bruno/Documents/TestesCpp/build /home/bruno/Documents/TestesCpp/build/CMakeFiles/test32.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test32.dir/depend

