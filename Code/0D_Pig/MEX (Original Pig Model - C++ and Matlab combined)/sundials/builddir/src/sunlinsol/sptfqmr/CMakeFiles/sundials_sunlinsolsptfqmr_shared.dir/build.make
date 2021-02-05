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
include src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/depend.make

# Include the progress variables for this target.
include src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/progress.make

# Include the compile flags for this target's objects.
include src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/flags.make

src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/sunlinsol_sptfqmr.c.o: src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/flags.make
src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/sunlinsol_sptfqmr.c.o: /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sunlinsol/sptfqmr/sunlinsol_sptfqmr.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/sunlinsol_sptfqmr.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunlinsol/sptfqmr && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/sunlinsol_sptfqmr.c.o   -c /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sunlinsol/sptfqmr/sunlinsol_sptfqmr.c

src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/sunlinsol_sptfqmr.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/sunlinsol_sptfqmr.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunlinsol/sptfqmr && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sunlinsol/sptfqmr/sunlinsol_sptfqmr.c > CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/sunlinsol_sptfqmr.c.i

src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/sunlinsol_sptfqmr.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/sunlinsol_sptfqmr.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunlinsol/sptfqmr && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sunlinsol/sptfqmr/sunlinsol_sptfqmr.c -o CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/sunlinsol_sptfqmr.c.s

src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_math.c.o: src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/flags.make
src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_math.c.o: /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_math.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_math.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunlinsol/sptfqmr && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_math.c.o   -c /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_math.c

src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_math.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_math.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunlinsol/sptfqmr && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_math.c > CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_math.c.i

src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_math.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_math.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunlinsol/sptfqmr && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_math.c -o CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_math.c.s

src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_nvector.c.o: src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/flags.make
src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_nvector.c.o: /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nvector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_nvector.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunlinsol/sptfqmr && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_nvector.c.o   -c /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nvector.c

src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_nvector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_nvector.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunlinsol/sptfqmr && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nvector.c > CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_nvector.c.i

src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_nvector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_nvector.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunlinsol/sptfqmr && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nvector.c -o CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_nvector.c.s

src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_linearsolver.c.o: src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/flags.make
src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_linearsolver.c.o: /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_linearsolver.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_linearsolver.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunlinsol/sptfqmr && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_linearsolver.c.o   -c /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_linearsolver.c

src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_linearsolver.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_linearsolver.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunlinsol/sptfqmr && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_linearsolver.c > CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_linearsolver.c.i

src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_linearsolver.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_linearsolver.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunlinsol/sptfqmr && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_linearsolver.c -o CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_linearsolver.c.s

src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_iterative.c.o: src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/flags.make
src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_iterative.c.o: /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_iterative.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_iterative.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunlinsol/sptfqmr && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_iterative.c.o   -c /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_iterative.c

src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_iterative.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_iterative.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunlinsol/sptfqmr && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_iterative.c > CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_iterative.c.i

src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_iterative.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_iterative.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunlinsol/sptfqmr && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_iterative.c -o CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_iterative.c.s

# Object files for target sundials_sunlinsolsptfqmr_shared
sundials_sunlinsolsptfqmr_shared_OBJECTS = \
"CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/sunlinsol_sptfqmr.c.o" \
"CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_math.c.o" \
"CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_nvector.c.o" \
"CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_linearsolver.c.o" \
"CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_iterative.c.o"

# External object files for target sundials_sunlinsolsptfqmr_shared
sundials_sunlinsolsptfqmr_shared_EXTERNAL_OBJECTS =

src/sunlinsol/sptfqmr/libsundials_sunlinsolsptfqmr.3.0.0.dylib: src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/sunlinsol_sptfqmr.c.o
src/sunlinsol/sptfqmr/libsundials_sunlinsolsptfqmr.3.0.0.dylib: src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_math.c.o
src/sunlinsol/sptfqmr/libsundials_sunlinsolsptfqmr.3.0.0.dylib: src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_nvector.c.o
src/sunlinsol/sptfqmr/libsundials_sunlinsolsptfqmr.3.0.0.dylib: src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_linearsolver.c.o
src/sunlinsol/sptfqmr/libsundials_sunlinsolsptfqmr.3.0.0.dylib: src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/__/__/sundials/sundials_iterative.c.o
src/sunlinsol/sptfqmr/libsundials_sunlinsolsptfqmr.3.0.0.dylib: src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/build.make
src/sunlinsol/sptfqmr/libsundials_sunlinsolsptfqmr.3.0.0.dylib: src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C shared library libsundials_sunlinsolsptfqmr.dylib"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunlinsol/sptfqmr && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunlinsol/sptfqmr && $(CMAKE_COMMAND) -E cmake_symlink_library libsundials_sunlinsolsptfqmr.3.0.0.dylib libsundials_sunlinsolsptfqmr.3.dylib libsundials_sunlinsolsptfqmr.dylib

src/sunlinsol/sptfqmr/libsundials_sunlinsolsptfqmr.3.dylib: src/sunlinsol/sptfqmr/libsundials_sunlinsolsptfqmr.3.0.0.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate src/sunlinsol/sptfqmr/libsundials_sunlinsolsptfqmr.3.dylib

src/sunlinsol/sptfqmr/libsundials_sunlinsolsptfqmr.dylib: src/sunlinsol/sptfqmr/libsundials_sunlinsolsptfqmr.3.0.0.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate src/sunlinsol/sptfqmr/libsundials_sunlinsolsptfqmr.dylib

# Rule to build all files generated by this target.
src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/build: src/sunlinsol/sptfqmr/libsundials_sunlinsolsptfqmr.dylib

.PHONY : src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/build

src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/clean:
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunlinsol/sptfqmr && $(CMAKE_COMMAND) -P CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/cmake_clean.cmake
.PHONY : src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/clean

src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/depend:
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0 /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sunlinsol/sptfqmr /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunlinsol/sptfqmr /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/sunlinsol/sptfqmr/CMakeFiles/sundials_sunlinsolsptfqmr_shared.dir/depend
