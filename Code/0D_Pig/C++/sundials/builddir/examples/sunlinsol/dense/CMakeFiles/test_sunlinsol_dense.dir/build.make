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
CMAKE_SOURCE_DIR = /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir

# Include any dependencies generated for this target.
include examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/depend.make

# Include the progress variables for this target.
include examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/progress.make

# Include the compile flags for this target's objects.
include examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/flags.make

examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/test_sunlinsol_dense.c.o: examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/flags.make
examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/test_sunlinsol_dense.c.o: ../examples/sunlinsol/dense/test_sunlinsol_dense.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/test_sunlinsol_dense.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/examples/sunlinsol/dense && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_sunlinsol_dense.dir/test_sunlinsol_dense.c.o -c /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/examples/sunlinsol/dense/test_sunlinsol_dense.c

examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/test_sunlinsol_dense.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_sunlinsol_dense.dir/test_sunlinsol_dense.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/examples/sunlinsol/dense && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/examples/sunlinsol/dense/test_sunlinsol_dense.c > CMakeFiles/test_sunlinsol_dense.dir/test_sunlinsol_dense.c.i

examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/test_sunlinsol_dense.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_sunlinsol_dense.dir/test_sunlinsol_dense.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/examples/sunlinsol/dense && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/examples/sunlinsol/dense/test_sunlinsol_dense.c -o CMakeFiles/test_sunlinsol_dense.dir/test_sunlinsol_dense.c.s

examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/__/test_sunlinsol.c.o: examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/flags.make
examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/__/test_sunlinsol.c.o: ../examples/sunlinsol/test_sunlinsol.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/__/test_sunlinsol.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/examples/sunlinsol/dense && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_sunlinsol_dense.dir/__/test_sunlinsol.c.o -c /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/examples/sunlinsol/test_sunlinsol.c

examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/__/test_sunlinsol.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_sunlinsol_dense.dir/__/test_sunlinsol.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/examples/sunlinsol/dense && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/examples/sunlinsol/test_sunlinsol.c > CMakeFiles/test_sunlinsol_dense.dir/__/test_sunlinsol.c.i

examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/__/test_sunlinsol.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_sunlinsol_dense.dir/__/test_sunlinsol.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/examples/sunlinsol/dense && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/examples/sunlinsol/test_sunlinsol.c -o CMakeFiles/test_sunlinsol_dense.dir/__/test_sunlinsol.c.s

examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_matrix.c.o: examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/flags.make
examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_matrix.c.o: ../src/sundials/sundials_matrix.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_matrix.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/examples/sunlinsol/dense && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_matrix.c.o -c /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sundials/sundials_matrix.c

examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_matrix.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/examples/sunlinsol/dense && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sundials/sundials_matrix.c > CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_matrix.c.i

examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_matrix.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/examples/sunlinsol/dense && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sundials/sundials_matrix.c -o CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_matrix.c.s

examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_linearsolver.c.o: examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/flags.make
examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_linearsolver.c.o: ../src/sundials/sundials_linearsolver.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_linearsolver.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/examples/sunlinsol/dense && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_linearsolver.c.o -c /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sundials/sundials_linearsolver.c

examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_linearsolver.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_linearsolver.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/examples/sunlinsol/dense && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sundials/sundials_linearsolver.c > CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_linearsolver.c.i

examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_linearsolver.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_linearsolver.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/examples/sunlinsol/dense && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sundials/sundials_linearsolver.c -o CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_linearsolver.c.s

examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_nvector.c.o: examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/flags.make
examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_nvector.c.o: ../src/sundials/sundials_nvector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_nvector.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/examples/sunlinsol/dense && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_nvector.c.o -c /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sundials/sundials_nvector.c

examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_nvector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_nvector.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/examples/sunlinsol/dense && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sundials/sundials_nvector.c > CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_nvector.c.i

examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_nvector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_nvector.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/examples/sunlinsol/dense && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sundials/sundials_nvector.c -o CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_nvector.c.s

# Object files for target test_sunlinsol_dense
test_sunlinsol_dense_OBJECTS = \
"CMakeFiles/test_sunlinsol_dense.dir/test_sunlinsol_dense.c.o" \
"CMakeFiles/test_sunlinsol_dense.dir/__/test_sunlinsol.c.o" \
"CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_matrix.c.o" \
"CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_linearsolver.c.o" \
"CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_nvector.c.o"

# External object files for target test_sunlinsol_dense
test_sunlinsol_dense_EXTERNAL_OBJECTS =

examples/sunlinsol/dense/test_sunlinsol_dense: examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/test_sunlinsol_dense.c.o
examples/sunlinsol/dense/test_sunlinsol_dense: examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/__/test_sunlinsol.c.o
examples/sunlinsol/dense/test_sunlinsol_dense: examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_matrix.c.o
examples/sunlinsol/dense/test_sunlinsol_dense: examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_linearsolver.c.o
examples/sunlinsol/dense/test_sunlinsol_dense: examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/__/__/__/src/sundials/sundials_nvector.c.o
examples/sunlinsol/dense/test_sunlinsol_dense: examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/build.make
examples/sunlinsol/dense/test_sunlinsol_dense: src/nvector/serial/libsundials_nvecserial.a
examples/sunlinsol/dense/test_sunlinsol_dense: src/sunlinsol/dense/libsundials_sunlinsoldense.a
examples/sunlinsol/dense/test_sunlinsol_dense: src/sunmatrix/dense/libsundials_sunmatrixdense.a
examples/sunlinsol/dense/test_sunlinsol_dense: examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable test_sunlinsol_dense"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/examples/sunlinsol/dense && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_sunlinsol_dense.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/build: examples/sunlinsol/dense/test_sunlinsol_dense

.PHONY : examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/build

examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/clean:
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/examples/sunlinsol/dense && $(CMAKE_COMMAND) -P CMakeFiles/test_sunlinsol_dense.dir/cmake_clean.cmake
.PHONY : examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/clean

examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/depend:
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/examples/sunlinsol/dense /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/examples/sunlinsol/dense /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/sunlinsol/dense/CMakeFiles/test_sunlinsol_dense.dir/depend

