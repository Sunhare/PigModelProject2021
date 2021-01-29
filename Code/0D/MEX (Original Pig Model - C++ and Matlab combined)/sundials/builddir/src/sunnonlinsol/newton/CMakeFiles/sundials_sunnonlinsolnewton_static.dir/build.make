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
include src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/depend.make

# Include the progress variables for this target.
include src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/progress.make

# Include the compile flags for this target's objects.
include src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/flags.make

src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/sunnonlinsol_newton.c.o: src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/flags.make
src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/sunnonlinsol_newton.c.o: /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sunnonlinsol/newton/sunnonlinsol_newton.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/sunnonlinsol_newton.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunnonlinsol/newton && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_sunnonlinsolnewton_static.dir/sunnonlinsol_newton.c.o   -c /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sunnonlinsol/newton/sunnonlinsol_newton.c

src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/sunnonlinsol_newton.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_sunnonlinsolnewton_static.dir/sunnonlinsol_newton.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunnonlinsol/newton && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sunnonlinsol/newton/sunnonlinsol_newton.c > CMakeFiles/sundials_sunnonlinsolnewton_static.dir/sunnonlinsol_newton.c.i

src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/sunnonlinsol_newton.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_sunnonlinsolnewton_static.dir/sunnonlinsol_newton.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunnonlinsol/newton && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sunnonlinsol/newton/sunnonlinsol_newton.c -o CMakeFiles/sundials_sunnonlinsolnewton_static.dir/sunnonlinsol_newton.c.s

src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_math.c.o: src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/flags.make
src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_math.c.o: /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_math.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_math.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunnonlinsol/newton && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_math.c.o   -c /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_math.c

src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_math.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_math.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunnonlinsol/newton && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_math.c > CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_math.c.i

src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_math.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_math.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunnonlinsol/newton && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_math.c -o CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_math.c.s

src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nvector.c.o: src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/flags.make
src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nvector.c.o: /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nvector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nvector.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunnonlinsol/newton && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nvector.c.o   -c /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nvector.c

src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nvector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nvector.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunnonlinsol/newton && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nvector.c > CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nvector.c.i

src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nvector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nvector.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunnonlinsol/newton && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nvector.c -o CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nvector.c.s

src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nvector_senswrapper.c.o: src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/flags.make
src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nvector_senswrapper.c.o: /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nvector_senswrapper.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nvector_senswrapper.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunnonlinsol/newton && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nvector_senswrapper.c.o   -c /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nvector_senswrapper.c

src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nvector_senswrapper.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nvector_senswrapper.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunnonlinsol/newton && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nvector_senswrapper.c > CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nvector_senswrapper.c.i

src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nvector_senswrapper.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nvector_senswrapper.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunnonlinsol/newton && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nvector_senswrapper.c -o CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nvector_senswrapper.c.s

src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nonlinearsolver.c.o: src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/flags.make
src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nonlinearsolver.c.o: /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nonlinearsolver.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nonlinearsolver.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunnonlinsol/newton && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nonlinearsolver.c.o   -c /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nonlinearsolver.c

src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nonlinearsolver.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nonlinearsolver.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunnonlinsol/newton && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nonlinearsolver.c > CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nonlinearsolver.c.i

src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nonlinearsolver.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nonlinearsolver.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunnonlinsol/newton && /Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nonlinearsolver.c -o CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nonlinearsolver.c.s

# Object files for target sundials_sunnonlinsolnewton_static
sundials_sunnonlinsolnewton_static_OBJECTS = \
"CMakeFiles/sundials_sunnonlinsolnewton_static.dir/sunnonlinsol_newton.c.o" \
"CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_math.c.o" \
"CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nvector.c.o" \
"CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nvector_senswrapper.c.o" \
"CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nonlinearsolver.c.o"

# External object files for target sundials_sunnonlinsolnewton_static
sundials_sunnonlinsolnewton_static_EXTERNAL_OBJECTS =

src/sunnonlinsol/newton/libsundials_sunnonlinsolnewton.a: src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/sunnonlinsol_newton.c.o
src/sunnonlinsol/newton/libsundials_sunnonlinsolnewton.a: src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_math.c.o
src/sunnonlinsol/newton/libsundials_sunnonlinsolnewton.a: src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nvector.c.o
src/sunnonlinsol/newton/libsundials_sunnonlinsolnewton.a: src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nvector_senswrapper.c.o
src/sunnonlinsol/newton/libsundials_sunnonlinsolnewton.a: src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/__/__/sundials/sundials_nonlinearsolver.c.o
src/sunnonlinsol/newton/libsundials_sunnonlinsolnewton.a: src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/build.make
src/sunnonlinsol/newton/libsundials_sunnonlinsolnewton.a: src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C static library libsundials_sunnonlinsolnewton.a"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunnonlinsol/newton && $(CMAKE_COMMAND) -P CMakeFiles/sundials_sunnonlinsolnewton_static.dir/cmake_clean_target.cmake
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunnonlinsol/newton && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sundials_sunnonlinsolnewton_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/build: src/sunnonlinsol/newton/libsundials_sunnonlinsolnewton.a

.PHONY : src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/build

src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/clean:
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunnonlinsol/newton && $(CMAKE_COMMAND) -P CMakeFiles/sundials_sunnonlinsolnewton_static.dir/cmake_clean.cmake
.PHONY : src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/clean

src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/depend:
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0 /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sunnonlinsol/newton /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunnonlinsol/newton /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/sunnonlinsol/newton/CMakeFiles/sundials_sunnonlinsolnewton_static.dir/depend

