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
include CMakeFiles/test55.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test55.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test55.dir/flags.make

CMakeFiles/test55.dir/test55.cpp.o: CMakeFiles/test55.dir/flags.make
CMakeFiles/test55.dir/test55.cpp.o: ../test55.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bruno/Documents/TestesCpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test55.dir/test55.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test55.dir/test55.cpp.o -c /home/bruno/Documents/TestesCpp/test55.cpp

CMakeFiles/test55.dir/test55.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test55.dir/test55.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bruno/Documents/TestesCpp/test55.cpp > CMakeFiles/test55.dir/test55.cpp.i

CMakeFiles/test55.dir/test55.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test55.dir/test55.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bruno/Documents/TestesCpp/test55.cpp -o CMakeFiles/test55.dir/test55.cpp.s

# Object files for target test55
test55_OBJECTS = \
"CMakeFiles/test55.dir/test55.cpp.o"

# External object files for target test55
test55_EXTERNAL_OBJECTS =

test55: CMakeFiles/test55.dir/test55.cpp.o
test55: CMakeFiles/test55.dir/build.make
test55: libCGAL_Qt5_moc_and_resources.a
test55: /usr/lib/x86_64-linux-gnu/libmpfr.so
test55: /usr/lib/x86_64-linux-gnu/libgmp.so
test55: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.12.8
test55: /usr/lib/x86_64-linux-gnu/libQt5Svg.so.5.12.8
test55: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.12.8
test55: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.12.8
test55: /usr/lib/x86_64-linux-gnu/libQt5Xml.so.5.12.8
test55: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
test55: CMakeFiles/test55.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bruno/Documents/TestesCpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test55"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test55.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test55.dir/build: test55

.PHONY : CMakeFiles/test55.dir/build

CMakeFiles/test55.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test55.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test55.dir/clean

CMakeFiles/test55.dir/depend:
	cd /home/bruno/Documents/TestesCpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bruno/Documents/TestesCpp /home/bruno/Documents/TestesCpp /home/bruno/Documents/TestesCpp/build /home/bruno/Documents/TestesCpp/build /home/bruno/Documents/TestesCpp/build/CMakeFiles/test55.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test55.dir/depend

