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
CMAKE_SOURCE_DIR = /home/myung/repos/volvo-boot-camp-2022-smokey-lab

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/myung/repos/volvo-boot-camp-2022-smokey-lab/build

# Include any dependencies generated for this target.
include CMakeFiles/input_handler_app.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/input_handler_app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/input_handler_app.dir/flags.make

CMakeFiles/input_handler_app.dir/main.cpp.o: CMakeFiles/input_handler_app.dir/flags.make
CMakeFiles/input_handler_app.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/myung/repos/volvo-boot-camp-2022-smokey-lab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/input_handler_app.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/input_handler_app.dir/main.cpp.o -c /home/myung/repos/volvo-boot-camp-2022-smokey-lab/main.cpp

CMakeFiles/input_handler_app.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/input_handler_app.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/myung/repos/volvo-boot-camp-2022-smokey-lab/main.cpp > CMakeFiles/input_handler_app.dir/main.cpp.i

CMakeFiles/input_handler_app.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/input_handler_app.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/myung/repos/volvo-boot-camp-2022-smokey-lab/main.cpp -o CMakeFiles/input_handler_app.dir/main.cpp.s

CMakeFiles/input_handler_app.dir/src/checkInput.cpp.o: CMakeFiles/input_handler_app.dir/flags.make
CMakeFiles/input_handler_app.dir/src/checkInput.cpp.o: ../src/checkInput.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/myung/repos/volvo-boot-camp-2022-smokey-lab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/input_handler_app.dir/src/checkInput.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/input_handler_app.dir/src/checkInput.cpp.o -c /home/myung/repos/volvo-boot-camp-2022-smokey-lab/src/checkInput.cpp

CMakeFiles/input_handler_app.dir/src/checkInput.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/input_handler_app.dir/src/checkInput.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/myung/repos/volvo-boot-camp-2022-smokey-lab/src/checkInput.cpp > CMakeFiles/input_handler_app.dir/src/checkInput.cpp.i

CMakeFiles/input_handler_app.dir/src/checkInput.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/input_handler_app.dir/src/checkInput.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/myung/repos/volvo-boot-camp-2022-smokey-lab/src/checkInput.cpp -o CMakeFiles/input_handler_app.dir/src/checkInput.cpp.s

# Object files for target input_handler_app
input_handler_app_OBJECTS = \
"CMakeFiles/input_handler_app.dir/main.cpp.o" \
"CMakeFiles/input_handler_app.dir/src/checkInput.cpp.o"

# External object files for target input_handler_app
input_handler_app_EXTERNAL_OBJECTS =

input_handler_app: CMakeFiles/input_handler_app.dir/main.cpp.o
input_handler_app: CMakeFiles/input_handler_app.dir/src/checkInput.cpp.o
input_handler_app: CMakeFiles/input_handler_app.dir/build.make
input_handler_app: CMakeFiles/input_handler_app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/myung/repos/volvo-boot-camp-2022-smokey-lab/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable input_handler_app"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/input_handler_app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/input_handler_app.dir/build: input_handler_app

.PHONY : CMakeFiles/input_handler_app.dir/build

CMakeFiles/input_handler_app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/input_handler_app.dir/cmake_clean.cmake
.PHONY : CMakeFiles/input_handler_app.dir/clean

CMakeFiles/input_handler_app.dir/depend:
	cd /home/myung/repos/volvo-boot-camp-2022-smokey-lab/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/myung/repos/volvo-boot-camp-2022-smokey-lab /home/myung/repos/volvo-boot-camp-2022-smokey-lab /home/myung/repos/volvo-boot-camp-2022-smokey-lab/build /home/myung/repos/volvo-boot-camp-2022-smokey-lab/build /home/myung/repos/volvo-boot-camp-2022-smokey-lab/build/CMakeFiles/input_handler_app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/input_handler_app.dir/depend

