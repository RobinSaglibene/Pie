# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vboxuser/pie_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vboxuser/pie_project

# Include any dependencies generated for this target.
include CMakeFiles/TPC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TPC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TPC.dir/flags.make

CMakeFiles/TPC.dir/main.c.o: CMakeFiles/TPC.dir/flags.make
CMakeFiles/TPC.dir/main.c.o: main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vboxuser/pie_project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/TPC.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/TPC.dir/main.c.o -c /home/vboxuser/pie_project/main.c

CMakeFiles/TPC.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TPC.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vboxuser/pie_project/main.c > CMakeFiles/TPC.dir/main.c.i

CMakeFiles/TPC.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TPC.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vboxuser/pie_project/main.c -o CMakeFiles/TPC.dir/main.c.s

# Object files for target TPC
TPC_OBJECTS = \
"CMakeFiles/TPC.dir/main.c.o"

# External object files for target TPC
TPC_EXTERNAL_OBJECTS =

TPC: CMakeFiles/TPC.dir/main.c.o
TPC: CMakeFiles/TPC.dir/build.make
TPC: CMakeFiles/TPC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vboxuser/pie_project/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable TPC"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TPC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TPC.dir/build: TPC

.PHONY : CMakeFiles/TPC.dir/build

CMakeFiles/TPC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TPC.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TPC.dir/clean

CMakeFiles/TPC.dir/depend:
	cd /home/vboxuser/pie_project && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vboxuser/pie_project /home/vboxuser/pie_project /home/vboxuser/pie_project /home/vboxuser/pie_project /home/vboxuser/pie_project/CMakeFiles/TPC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TPC.dir/depend

