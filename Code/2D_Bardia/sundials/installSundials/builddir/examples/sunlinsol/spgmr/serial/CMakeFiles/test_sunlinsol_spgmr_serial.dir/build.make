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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.18.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.18.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir

# Include any dependencies generated for this target.
include examples/sunlinsol/spgmr/serial/CMakeFiles/test_sunlinsol_spgmr_serial.dir/depend.make

# Include the progress variables for this target.
include examples/sunlinsol/spgmr/serial/CMakeFiles/test_sunlinsol_spgmr_serial.dir/progress.make

# Include the compile flags for this target's objects.
include examples/sunlinsol/spgmr/serial/CMakeFiles/test_sunlinsol_spgmr_serial.dir/flags.make

examples/sunlinsol/spgmr/serial/CMakeFiles/test_sunlinsol_spgmr_serial.dir/test_sunlinsol_spgmr_serial.c.o: examples/sunlinsol/spgmr/serial/CMakeFiles/test_sunlinsol_spgmr_serial.dir/flags.make
examples/sunlinsol/spgmr/serial/CMakeFiles/test_sunlinsol_spgmr_serial.dir/test_sunlinsol_spgmr_serial.c.o: ../../examples/sunlinsol/spgmr/serial/test_sunlinsol_spgmr_serial.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/sunlinsol/spgmr/serial/CMakeFiles/test_sunlinsol_spgmr_serial.dir/test_sunlinsol_spgmr_serial.c.o"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/sunlinsol/spgmr/serial && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_sunlinsol_spgmr_serial.dir/test_sunlinsol_spgmr_serial.c.o -c /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/sunlinsol/spgmr/serial/test_sunlinsol_spgmr_serial.c

examples/sunlinsol/spgmr/serial/CMakeFiles/test_sunlinsol_spgmr_serial.dir/test_sunlinsol_spgmr_serial.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_sunlinsol_spgmr_serial.dir/test_sunlinsol_spgmr_serial.c.i"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/sunlinsol/spgmr/serial && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/sunlinsol/spgmr/serial/test_sunlinsol_spgmr_serial.c > CMakeFiles/test_sunlinsol_spgmr_serial.dir/test_sunlinsol_spgmr_serial.c.i

examples/sunlinsol/spgmr/serial/CMakeFiles/test_sunlinsol_spgmr_serial.dir/test_sunlinsol_spgmr_serial.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_sunlinsol_spgmr_serial.dir/test_sunlinsol_spgmr_serial.c.s"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/sunlinsol/spgmr/serial && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/sunlinsol/spgmr/serial/test_sunlinsol_spgmr_serial.c -o CMakeFiles/test_sunlinsol_spgmr_serial.dir/test_sunlinsol_spgmr_serial.c.s

examples/sunlinsol/spgmr/serial/CMakeFiles/test_sunlinsol_spgmr_serial.dir/__/__/test_sunlinsol.c.o: examples/sunlinsol/spgmr/serial/CMakeFiles/test_sunlinsol_spgmr_serial.dir/flags.make
examples/sunlinsol/spgmr/serial/CMakeFiles/test_sunlinsol_spgmr_serial.dir/__/__/test_sunlinsol.c.o: ../../examples/sunlinsol/test_sunlinsol.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object examples/sunlinsol/spgmr/serial/CMakeFiles/test_sunlinsol_spgmr_serial.dir/__/__/test_sunlinsol.c.o"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/sunlinsol/spgmr/serial && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_sunlinsol_spgmr_serial.dir/__/__/test_sunlinsol.c.o -c /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/sunlinsol/test_sunlinsol.c

examples/sunlinsol/spgmr/serial/CMakeFiles/test_sunlinsol_spgmr_serial.dir/__/__/test_sunlinsol.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_sunlinsol_spgmr_serial.dir/__/__/test_sunlinsol.c.i"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/sunlinsol/spgmr/serial && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/sunlinsol/test_sunlinsol.c > CMakeFiles/test_sunlinsol_spgmr_serial.dir/__/__/test_sunlinsol.c.i

examples/sunlinsol/spgmr/serial/CMakeFiles/test_sunlinsol_spgmr_serial.dir/__/__/test_sunlinsol.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_sunlinsol_spgmr_serial.dir/__/__/test_sunlinsol.c.s"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/sunlinsol/spgmr/serial && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/sunlinsol/test_sunlinsol.c -o CMakeFiles/test_sunlinsol_spgmr_serial.dir/__/__/test_sunlinsol.c.s

# Object files for target test_sunlinsol_spgmr_serial
test_sunlinsol_spgmr_serial_OBJECTS = \
"CMakeFiles/test_sunlinsol_spgmr_serial.dir/test_sunlinsol_spgmr_serial.c.o" \
"CMakeFiles/test_sunlinsol_spgmr_serial.dir/__/__/test_sunlinsol.c.o"

# External object files for target test_sunlinsol_spgmr_serial
test_sunlinsol_spgmr_serial_EXTERNAL_OBJECTS =

examples/sunlinsol/spgmr/serial/test_sunlinsol_spgmr_serial: examples/sunlinsol/spgmr/serial/CMakeFiles/test_sunlinsol_spgmr_serial.dir/test_sunlinsol_spgmr_serial.c.o
examples/sunlinsol/spgmr/serial/test_sunlinsol_spgmr_serial: examples/sunlinsol/spgmr/serial/CMakeFiles/test_sunlinsol_spgmr_serial.dir/__/__/test_sunlinsol.c.o
examples/sunlinsol/spgmr/serial/test_sunlinsol_spgmr_serial: examples/sunlinsol/spgmr/serial/CMakeFiles/test_sunlinsol_spgmr_serial.dir/build.make
examples/sunlinsol/spgmr/serial/test_sunlinsol_spgmr_serial: src/nvector/serial/libsundials_nvecserial.5.7.0.dylib
examples/sunlinsol/spgmr/serial/test_sunlinsol_spgmr_serial: src/sunlinsol/spgmr/libsundials_sunlinsolspgmr.3.7.0.dylib
examples/sunlinsol/spgmr/serial/test_sunlinsol_spgmr_serial: examples/sunlinsol/spgmr/serial/CMakeFiles/test_sunlinsol_spgmr_serial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable test_sunlinsol_spgmr_serial"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/sunlinsol/spgmr/serial && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_sunlinsol_spgmr_serial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/sunlinsol/spgmr/serial/CMakeFiles/test_sunlinsol_spgmr_serial.dir/build: examples/sunlinsol/spgmr/serial/test_sunlinsol_spgmr_serial

.PHONY : examples/sunlinsol/spgmr/serial/CMakeFiles/test_sunlinsol_spgmr_serial.dir/build

examples/sunlinsol/spgmr/serial/CMakeFiles/test_sunlinsol_spgmr_serial.dir/clean:
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/sunlinsol/spgmr/serial && $(CMAKE_COMMAND) -P CMakeFiles/test_sunlinsol_spgmr_serial.dir/cmake_clean.cmake
.PHONY : examples/sunlinsol/spgmr/serial/CMakeFiles/test_sunlinsol_spgmr_serial.dir/clean

examples/sunlinsol/spgmr/serial/CMakeFiles/test_sunlinsol_spgmr_serial.dir/depend:
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/sunlinsol/spgmr/serial /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/sunlinsol/spgmr/serial /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/sunlinsol/spgmr/serial/CMakeFiles/test_sunlinsol_spgmr_serial.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/sunlinsol/spgmr/serial/CMakeFiles/test_sunlinsol_spgmr_serial.dir/depend

