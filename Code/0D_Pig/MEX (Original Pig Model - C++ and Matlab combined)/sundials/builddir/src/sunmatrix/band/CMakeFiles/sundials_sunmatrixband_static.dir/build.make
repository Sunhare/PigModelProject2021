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
include src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/depend.make

# Include the progress variables for this target.
include src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/progress.make

# Include the compile flags for this target's objects.
include src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/flags.make

src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/sunmatrix_band.c.o: src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/flags.make
src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/sunmatrix_band.c.o: /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sunmatrix/band/sunmatrix_band.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/sunmatrix_band.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunmatrix/band && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_sunmatrixband_static.dir/sunmatrix_band.c.o   -c /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sunmatrix/band/sunmatrix_band.c

src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/sunmatrix_band.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_sunmatrixband_static.dir/sunmatrix_band.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunmatrix/band && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sunmatrix/band/sunmatrix_band.c > CMakeFiles/sundials_sunmatrixband_static.dir/sunmatrix_band.c.i

src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/sunmatrix_band.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_sunmatrixband_static.dir/sunmatrix_band.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunmatrix/band && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sunmatrix/band/sunmatrix_band.c -o CMakeFiles/sundials_sunmatrixband_static.dir/sunmatrix_band.c.s

src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_nvector.c.o: src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/flags.make
src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_nvector.c.o: /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nvector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_nvector.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunmatrix/band && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_nvector.c.o   -c /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nvector.c

src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_nvector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_nvector.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunmatrix/band && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nvector.c > CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_nvector.c.i

src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_nvector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_nvector.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunmatrix/band && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nvector.c -o CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_nvector.c.s

src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_matrix.c.o: src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/flags.make
src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_matrix.c.o: /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_matrix.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_matrix.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunmatrix/band && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_matrix.c.o   -c /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_matrix.c

src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_matrix.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunmatrix/band && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_matrix.c > CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_matrix.c.i

src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_matrix.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunmatrix/band && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_matrix.c -o CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_matrix.c.s

src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_math.c.o: src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/flags.make
src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_math.c.o: /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_math.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_math.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunmatrix/band && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_math.c.o   -c /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_math.c

src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_math.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_math.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunmatrix/band && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_math.c > CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_math.c.i

src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_math.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_math.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunmatrix/band && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_math.c -o CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_math.c.s

# Object files for target sundials_sunmatrixband_static
sundials_sunmatrixband_static_OBJECTS = \
"CMakeFiles/sundials_sunmatrixband_static.dir/sunmatrix_band.c.o" \
"CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_nvector.c.o" \
"CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_matrix.c.o" \
"CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_math.c.o"

# External object files for target sundials_sunmatrixband_static
sundials_sunmatrixband_static_EXTERNAL_OBJECTS =

src/sunmatrix/band/libsundials_sunmatrixband.a: src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/sunmatrix_band.c.o
src/sunmatrix/band/libsundials_sunmatrixband.a: src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_nvector.c.o
src/sunmatrix/band/libsundials_sunmatrixband.a: src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_matrix.c.o
src/sunmatrix/band/libsundials_sunmatrixband.a: src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/__/__/sundials/sundials_math.c.o
src/sunmatrix/band/libsundials_sunmatrixband.a: src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/build.make
src/sunmatrix/band/libsundials_sunmatrixband.a: src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C static library libsundials_sunmatrixband.a"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunmatrix/band && $(CMAKE_COMMAND) -P CMakeFiles/sundials_sunmatrixband_static.dir/cmake_clean_target.cmake
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunmatrix/band && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sundials_sunmatrixband_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/build: src/sunmatrix/band/libsundials_sunmatrixband.a

.PHONY : src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/build

src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/clean:
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunmatrix/band && $(CMAKE_COMMAND) -P CMakeFiles/sundials_sunmatrixband_static.dir/cmake_clean.cmake
.PHONY : src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/clean

src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/depend:
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0 /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sunmatrix/band /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunmatrix/band /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/sunmatrix/band/CMakeFiles/sundials_sunmatrixband_static.dir/depend
