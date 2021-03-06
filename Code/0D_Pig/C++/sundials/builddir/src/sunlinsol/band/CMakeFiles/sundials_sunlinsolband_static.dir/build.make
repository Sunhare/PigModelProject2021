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
include src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/depend.make

# Include the progress variables for this target.
include src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/progress.make

# Include the compile flags for this target's objects.
include src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/flags.make

src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/sunlinsol_band.c.o: src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/flags.make
src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/sunlinsol_band.c.o: ../src/sunlinsol/band/sunlinsol_band.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/sunlinsol_band.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunlinsol/band && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_sunlinsolband_static.dir/sunlinsol_band.c.o -c /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sunlinsol/band/sunlinsol_band.c

src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/sunlinsol_band.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_sunlinsolband_static.dir/sunlinsol_band.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunlinsol/band && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sunlinsol/band/sunlinsol_band.c > CMakeFiles/sundials_sunlinsolband_static.dir/sunlinsol_band.c.i

src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/sunlinsol_band.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_sunlinsolband_static.dir/sunlinsol_band.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunlinsol/band && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sunlinsol/band/sunlinsol_band.c -o CMakeFiles/sundials_sunlinsolband_static.dir/sunlinsol_band.c.s

src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/__/__/sundials/sundials_linearsolver.c.o: src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/flags.make
src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/__/__/sundials/sundials_linearsolver.c.o: ../src/sundials/sundials_linearsolver.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/__/__/sundials/sundials_linearsolver.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunlinsol/band && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_sunlinsolband_static.dir/__/__/sundials/sundials_linearsolver.c.o -c /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sundials/sundials_linearsolver.c

src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/__/__/sundials/sundials_linearsolver.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_sunlinsolband_static.dir/__/__/sundials/sundials_linearsolver.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunlinsol/band && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sundials/sundials_linearsolver.c > CMakeFiles/sundials_sunlinsolband_static.dir/__/__/sundials/sundials_linearsolver.c.i

src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/__/__/sundials/sundials_linearsolver.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_sunlinsolband_static.dir/__/__/sundials/sundials_linearsolver.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunlinsol/band && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sundials/sundials_linearsolver.c -o CMakeFiles/sundials_sunlinsolband_static.dir/__/__/sundials/sundials_linearsolver.c.s

src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/__/__/sundials/sundials_band.c.o: src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/flags.make
src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/__/__/sundials/sundials_band.c.o: ../src/sundials/sundials_band.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/__/__/sundials/sundials_band.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunlinsol/band && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_sunlinsolband_static.dir/__/__/sundials/sundials_band.c.o -c /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sundials/sundials_band.c

src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/__/__/sundials/sundials_band.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_sunlinsolband_static.dir/__/__/sundials/sundials_band.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunlinsol/band && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sundials/sundials_band.c > CMakeFiles/sundials_sunlinsolband_static.dir/__/__/sundials/sundials_band.c.i

src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/__/__/sundials/sundials_band.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_sunlinsolband_static.dir/__/__/sundials/sundials_band.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunlinsol/band && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sundials/sundials_band.c -o CMakeFiles/sundials_sunlinsolband_static.dir/__/__/sundials/sundials_band.c.s

# Object files for target sundials_sunlinsolband_static
sundials_sunlinsolband_static_OBJECTS = \
"CMakeFiles/sundials_sunlinsolband_static.dir/sunlinsol_band.c.o" \
"CMakeFiles/sundials_sunlinsolband_static.dir/__/__/sundials/sundials_linearsolver.c.o" \
"CMakeFiles/sundials_sunlinsolband_static.dir/__/__/sundials/sundials_band.c.o"

# External object files for target sundials_sunlinsolband_static
sundials_sunlinsolband_static_EXTERNAL_OBJECTS =

src/sunlinsol/band/libsundials_sunlinsolband.a: src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/sunlinsol_band.c.o
src/sunlinsol/band/libsundials_sunlinsolband.a: src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/__/__/sundials/sundials_linearsolver.c.o
src/sunlinsol/band/libsundials_sunlinsolband.a: src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/__/__/sundials/sundials_band.c.o
src/sunlinsol/band/libsundials_sunlinsolband.a: src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/build.make
src/sunlinsol/band/libsundials_sunlinsolband.a: src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C static library libsundials_sunlinsolband.a"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunlinsol/band && $(CMAKE_COMMAND) -P CMakeFiles/sundials_sunlinsolband_static.dir/cmake_clean_target.cmake
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunlinsol/band && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sundials_sunlinsolband_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/build: src/sunlinsol/band/libsundials_sunlinsolband.a

.PHONY : src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/build

src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/clean:
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunlinsol/band && $(CMAKE_COMMAND) -P CMakeFiles/sundials_sunlinsolband_static.dir/cmake_clean.cmake
.PHONY : src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/clean

src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/depend:
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sunlinsol/band /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunlinsol/band /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/sunlinsol/band/CMakeFiles/sundials_sunlinsolband_static.dir/depend

