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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.15.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.15.5/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir

# Include any dependencies generated for this target.
include examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/depend.make

# Include the progress variables for this target.
include examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/progress.make

# Include the compile flags for this target's objects.
include examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/flags.make

examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/test_sunlinsol_spbcgs_serial.c.o: examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/flags.make
examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/test_sunlinsol_spbcgs_serial.c.o: /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/sunlinsol/spbcgs/serial/test_sunlinsol_spbcgs_serial.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/test_sunlinsol_spbcgs_serial.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunlinsol/spbcgs/serial && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_sunlinsol_spbcgs_serial.dir/test_sunlinsol_spbcgs_serial.c.o   -c /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/sunlinsol/spbcgs/serial/test_sunlinsol_spbcgs_serial.c

examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/test_sunlinsol_spbcgs_serial.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_sunlinsol_spbcgs_serial.dir/test_sunlinsol_spbcgs_serial.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunlinsol/spbcgs/serial && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/sunlinsol/spbcgs/serial/test_sunlinsol_spbcgs_serial.c > CMakeFiles/test_sunlinsol_spbcgs_serial.dir/test_sunlinsol_spbcgs_serial.c.i

examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/test_sunlinsol_spbcgs_serial.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_sunlinsol_spbcgs_serial.dir/test_sunlinsol_spbcgs_serial.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunlinsol/spbcgs/serial && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/sunlinsol/spbcgs/serial/test_sunlinsol_spbcgs_serial.c -o CMakeFiles/test_sunlinsol_spbcgs_serial.dir/test_sunlinsol_spbcgs_serial.c.s

examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/test_sunlinsol.c.o: examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/flags.make
examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/test_sunlinsol.c.o: /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/sunlinsol/test_sunlinsol.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/test_sunlinsol.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunlinsol/spbcgs/serial && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/test_sunlinsol.c.o   -c /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/sunlinsol/test_sunlinsol.c

examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/test_sunlinsol.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/test_sunlinsol.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunlinsol/spbcgs/serial && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/sunlinsol/test_sunlinsol.c > CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/test_sunlinsol.c.i

examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/test_sunlinsol.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/test_sunlinsol.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunlinsol/spbcgs/serial && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/sunlinsol/test_sunlinsol.c -o CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/test_sunlinsol.c.s

examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/__/__/src/sundials/sundials_linearsolver.c.o: examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/flags.make
examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/__/__/src/sundials/sundials_linearsolver.c.o: /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_linearsolver.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/__/__/src/sundials/sundials_linearsolver.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunlinsol/spbcgs/serial && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/__/__/src/sundials/sundials_linearsolver.c.o   -c /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_linearsolver.c

examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/__/__/src/sundials/sundials_linearsolver.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/__/__/src/sundials/sundials_linearsolver.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunlinsol/spbcgs/serial && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_linearsolver.c > CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/__/__/src/sundials/sundials_linearsolver.c.i

examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/__/__/src/sundials/sundials_linearsolver.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/__/__/src/sundials/sundials_linearsolver.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunlinsol/spbcgs/serial && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_linearsolver.c -o CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/__/__/src/sundials/sundials_linearsolver.c.s

examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/__/__/src/sundials/sundials_nvector.c.o: examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/flags.make
examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/__/__/src/sundials/sundials_nvector.c.o: /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nvector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/__/__/src/sundials/sundials_nvector.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunlinsol/spbcgs/serial && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/__/__/src/sundials/sundials_nvector.c.o   -c /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nvector.c

examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/__/__/src/sundials/sundials_nvector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/__/__/src/sundials/sundials_nvector.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunlinsol/spbcgs/serial && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nvector.c > CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/__/__/src/sundials/sundials_nvector.c.i

examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/__/__/src/sundials/sundials_nvector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/__/__/src/sundials/sundials_nvector.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunlinsol/spbcgs/serial && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nvector.c -o CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/__/__/src/sundials/sundials_nvector.c.s

# Object files for target test_sunlinsol_spbcgs_serial
test_sunlinsol_spbcgs_serial_OBJECTS = \
"CMakeFiles/test_sunlinsol_spbcgs_serial.dir/test_sunlinsol_spbcgs_serial.c.o" \
"CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/test_sunlinsol.c.o" \
"CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/__/__/src/sundials/sundials_linearsolver.c.o" \
"CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/__/__/src/sundials/sundials_nvector.c.o"

# External object files for target test_sunlinsol_spbcgs_serial
test_sunlinsol_spbcgs_serial_EXTERNAL_OBJECTS =

examples/sunlinsol/spbcgs/serial/test_sunlinsol_spbcgs_serial: examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/test_sunlinsol_spbcgs_serial.c.o
examples/sunlinsol/spbcgs/serial/test_sunlinsol_spbcgs_serial: examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/test_sunlinsol.c.o
examples/sunlinsol/spbcgs/serial/test_sunlinsol_spbcgs_serial: examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/__/__/src/sundials/sundials_linearsolver.c.o
examples/sunlinsol/spbcgs/serial/test_sunlinsol_spbcgs_serial: examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/__/__/__/__/src/sundials/sundials_nvector.c.o
examples/sunlinsol/spbcgs/serial/test_sunlinsol_spbcgs_serial: examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/build.make
examples/sunlinsol/spbcgs/serial/test_sunlinsol_spbcgs_serial: src/nvector/serial/libsundials_nvecserial.5.0.0.dylib
examples/sunlinsol/spbcgs/serial/test_sunlinsol_spbcgs_serial: src/sunlinsol/spbcgs/libsundials_sunlinsolspbcgs.3.0.0.dylib
examples/sunlinsol/spbcgs/serial/test_sunlinsol_spbcgs_serial: examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable test_sunlinsol_spbcgs_serial"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunlinsol/spbcgs/serial && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_sunlinsol_spbcgs_serial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/build: examples/sunlinsol/spbcgs/serial/test_sunlinsol_spbcgs_serial

.PHONY : examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/build

examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/clean:
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunlinsol/spbcgs/serial && $(CMAKE_COMMAND) -P CMakeFiles/test_sunlinsol_spbcgs_serial.dir/cmake_clean.cmake
.PHONY : examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/clean

examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/depend:
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0 /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/sunlinsol/spbcgs/serial /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunlinsol/spbcgs/serial /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/sunlinsol/spbcgs/serial/CMakeFiles/test_sunlinsol_spbcgs_serial.dir/depend

