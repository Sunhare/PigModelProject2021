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
include examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/depend.make

# Include the progress variables for this target.
include examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/progress.make

# Include the compile flags for this target's objects.
include examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/flags.make

examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/test_sunmatrix_dense.c.o: examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/flags.make
examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/test_sunmatrix_dense.c.o: /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/sunmatrix/dense/test_sunmatrix_dense.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/test_sunmatrix_dense.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunmatrix/dense && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_sunmatrix_dense.dir/test_sunmatrix_dense.c.o   -c /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/sunmatrix/dense/test_sunmatrix_dense.c

examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/test_sunmatrix_dense.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_sunmatrix_dense.dir/test_sunmatrix_dense.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunmatrix/dense && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/sunmatrix/dense/test_sunmatrix_dense.c > CMakeFiles/test_sunmatrix_dense.dir/test_sunmatrix_dense.c.i

examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/test_sunmatrix_dense.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_sunmatrix_dense.dir/test_sunmatrix_dense.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunmatrix/dense && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/sunmatrix/dense/test_sunmatrix_dense.c -o CMakeFiles/test_sunmatrix_dense.dir/test_sunmatrix_dense.c.s

examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/__/test_sunmatrix.c.o: examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/flags.make
examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/__/test_sunmatrix.c.o: /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/sunmatrix/test_sunmatrix.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/__/test_sunmatrix.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunmatrix/dense && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_sunmatrix_dense.dir/__/test_sunmatrix.c.o   -c /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/sunmatrix/test_sunmatrix.c

examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/__/test_sunmatrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_sunmatrix_dense.dir/__/test_sunmatrix.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunmatrix/dense && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/sunmatrix/test_sunmatrix.c > CMakeFiles/test_sunmatrix_dense.dir/__/test_sunmatrix.c.i

examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/__/test_sunmatrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_sunmatrix_dense.dir/__/test_sunmatrix.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunmatrix/dense && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/sunmatrix/test_sunmatrix.c -o CMakeFiles/test_sunmatrix_dense.dir/__/test_sunmatrix.c.s

examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/__/__/__/src/sundials/sundials_matrix.c.o: examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/flags.make
examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/__/__/__/src/sundials/sundials_matrix.c.o: /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_matrix.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/__/__/__/src/sundials/sundials_matrix.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunmatrix/dense && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_sunmatrix_dense.dir/__/__/__/src/sundials/sundials_matrix.c.o   -c /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_matrix.c

examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/__/__/__/src/sundials/sundials_matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_sunmatrix_dense.dir/__/__/__/src/sundials/sundials_matrix.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunmatrix/dense && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_matrix.c > CMakeFiles/test_sunmatrix_dense.dir/__/__/__/src/sundials/sundials_matrix.c.i

examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/__/__/__/src/sundials/sundials_matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_sunmatrix_dense.dir/__/__/__/src/sundials/sundials_matrix.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunmatrix/dense && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_matrix.c -o CMakeFiles/test_sunmatrix_dense.dir/__/__/__/src/sundials/sundials_matrix.c.s

examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/__/__/__/src/sundials/sundials_nvector.c.o: examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/flags.make
examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/__/__/__/src/sundials/sundials_nvector.c.o: /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nvector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/__/__/__/src/sundials/sundials_nvector.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunmatrix/dense && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_sunmatrix_dense.dir/__/__/__/src/sundials/sundials_nvector.c.o   -c /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nvector.c

examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/__/__/__/src/sundials/sundials_nvector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_sunmatrix_dense.dir/__/__/__/src/sundials/sundials_nvector.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunmatrix/dense && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nvector.c > CMakeFiles/test_sunmatrix_dense.dir/__/__/__/src/sundials/sundials_nvector.c.i

examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/__/__/__/src/sundials/sundials_nvector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_sunmatrix_dense.dir/__/__/__/src/sundials/sundials_nvector.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunmatrix/dense && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nvector.c -o CMakeFiles/test_sunmatrix_dense.dir/__/__/__/src/sundials/sundials_nvector.c.s

# Object files for target test_sunmatrix_dense
test_sunmatrix_dense_OBJECTS = \
"CMakeFiles/test_sunmatrix_dense.dir/test_sunmatrix_dense.c.o" \
"CMakeFiles/test_sunmatrix_dense.dir/__/test_sunmatrix.c.o" \
"CMakeFiles/test_sunmatrix_dense.dir/__/__/__/src/sundials/sundials_matrix.c.o" \
"CMakeFiles/test_sunmatrix_dense.dir/__/__/__/src/sundials/sundials_nvector.c.o"

# External object files for target test_sunmatrix_dense
test_sunmatrix_dense_EXTERNAL_OBJECTS =

examples/sunmatrix/dense/test_sunmatrix_dense: examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/test_sunmatrix_dense.c.o
examples/sunmatrix/dense/test_sunmatrix_dense: examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/__/test_sunmatrix.c.o
examples/sunmatrix/dense/test_sunmatrix_dense: examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/__/__/__/src/sundials/sundials_matrix.c.o
examples/sunmatrix/dense/test_sunmatrix_dense: examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/__/__/__/src/sundials/sundials_nvector.c.o
examples/sunmatrix/dense/test_sunmatrix_dense: examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/build.make
examples/sunmatrix/dense/test_sunmatrix_dense: src/nvector/serial/libsundials_nvecserial.5.0.0.dylib
examples/sunmatrix/dense/test_sunmatrix_dense: src/sunmatrix/dense/libsundials_sunmatrixdense.3.0.0.dylib
examples/sunmatrix/dense/test_sunmatrix_dense: examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable test_sunmatrix_dense"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunmatrix/dense && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_sunmatrix_dense.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/build: examples/sunmatrix/dense/test_sunmatrix_dense

.PHONY : examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/build

examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/clean:
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunmatrix/dense && $(CMAKE_COMMAND) -P CMakeFiles/test_sunmatrix_dense.dir/cmake_clean.cmake
.PHONY : examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/clean

examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/depend:
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0 /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/sunmatrix/dense /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunmatrix/dense /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/sunmatrix/dense/CMakeFiles/test_sunmatrix_dense.dir/depend

