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
include CMakeFiles/test23.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test23.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test23.dir/flags.make

CMakeFiles/test23.dir/test23.cpp.o: CMakeFiles/test23.dir/flags.make
CMakeFiles/test23.dir/test23.cpp.o: ../test23.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bruno/Documents/TestesCpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test23.dir/test23.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test23.dir/test23.cpp.o -c /home/bruno/Documents/TestesCpp/test23.cpp

CMakeFiles/test23.dir/test23.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test23.dir/test23.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bruno/Documents/TestesCpp/test23.cpp > CMakeFiles/test23.dir/test23.cpp.i

CMakeFiles/test23.dir/test23.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test23.dir/test23.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bruno/Documents/TestesCpp/test23.cpp -o CMakeFiles/test23.dir/test23.cpp.s

# Object files for target test23
test23_OBJECTS = \
"CMakeFiles/test23.dir/test23.cpp.o"

# External object files for target test23
test23_EXTERNAL_OBJECTS =

test23: CMakeFiles/test23.dir/test23.cpp.o
test23: CMakeFiles/test23.dir/build.make
test23: libCGAL_Qt5_moc_and_resources.a
test23: /usr/lib/x86_64-linux-gnu/libmpfr.so
test23: /usr/lib/x86_64-linux-gnu/libgmp.so
test23: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.12.8
test23: /usr/lib/x86_64-linux-gnu/libQt5Svg.so.5.12.8
test23: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.12.8
test23: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.12.8
test23: /usr/lib/x86_64-linux-gnu/libQt5Xml.so.5.12.8
test23: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
test23: CMakeFiles/test23.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bruno/Documents/TestesCpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test23"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test23.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test23.dir/build: test23

.PHONY : CMakeFiles/test23.dir/build

CMakeFiles/test23.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test23.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test23.dir/clean

CMakeFiles/test23.dir/depend:
	cd /home/bruno/Documents/TestesCpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bruno/Documents/TestesCpp /home/bruno/Documents/TestesCpp /home/bruno/Documents/TestesCpp/build /home/bruno/Documents/TestesCpp/build /home/bruno/Documents/TestesCpp/build/CMakeFiles/test23.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test23.dir/depend
