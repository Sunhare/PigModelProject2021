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
include examples/cvodes/serial/CMakeFiles/cvsFoodWeb_ASAp_kry.dir/depend.make

# Include the progress variables for this target.
include examples/cvodes/serial/CMakeFiles/cvsFoodWeb_ASAp_kry.dir/progress.make

# Include the compile flags for this target's objects.
include examples/cvodes/serial/CMakeFiles/cvsFoodWeb_ASAp_kry.dir/flags.make

examples/cvodes/serial/CMakeFiles/cvsFoodWeb_ASAp_kry.dir/cvsFoodWeb_ASAp_kry.c.o: examples/cvodes/serial/CMakeFiles/cvsFoodWeb_ASAp_kry.dir/flags.make
examples/cvodes/serial/CMakeFiles/cvsFoodWeb_ASAp_kry.dir/cvsFoodWeb_ASAp_kry.c.o: ../../examples/cvodes/serial/cvsFoodWeb_ASAp_kry.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/cvodes/serial/CMakeFiles/cvsFoodWeb_ASAp_kry.dir/cvsFoodWeb_ASAp_kry.c.o"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/cvodes/serial && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cvsFoodWeb_ASAp_kry.dir/cvsFoodWeb_ASAp_kry.c.o -c /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/cvodes/serial/cvsFoodWeb_ASAp_kry.c

examples/cvodes/serial/CMakeFiles/cvsFoodWeb_ASAp_kry.dir/cvsFoodWeb_ASAp_kry.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cvsFoodWeb_ASAp_kry.dir/cvsFoodWeb_ASAp_kry.c.i"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/cvodes/serial && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/cvodes/serial/cvsFoodWeb_ASAp_kry.c > CMakeFiles/cvsFoodWeb_ASAp_kry.dir/cvsFoodWeb_ASAp_kry.c.i

examples/cvodes/serial/CMakeFiles/cvsFoodWeb_ASAp_kry.dir/cvsFoodWeb_ASAp_kry.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cvsFoodWeb_ASAp_kry.dir/cvsFoodWeb_ASAp_kry.c.s"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/cvodes/serial && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/cvodes/serial/cvsFoodWeb_ASAp_kry.c -o CMakeFiles/cvsFoodWeb_ASAp_kry.dir/cvsFoodWeb_ASAp_kry.c.s

# Object files for target cvsFoodWeb_ASAp_kry
cvsFoodWeb_ASAp_kry_OBJECTS = \
"CMakeFiles/cvsFoodWeb_ASAp_kry.dir/cvsFoodWeb_ASAp_kry.c.o"

# External object files for target cvsFoodWeb_ASAp_kry
cvsFoodWeb_ASAp_kry_EXTERNAL_OBJECTS =

examples/cvodes/serial/cvsFoodWeb_ASAp_kry: examples/cvodes/serial/CMakeFiles/cvsFoodWeb_ASAp_kry.dir/cvsFoodWeb_ASAp_kry.c.o
examples/cvodes/serial/cvsFoodWeb_ASAp_kry: examples/cvodes/serial/CMakeFiles/cvsFoodWeb_ASAp_kry.dir/build.make
examples/cvodes/serial/cvsFoodWeb_ASAp_kry: src/cvodes/libsundials_cvodes.5.7.0.dylib
examples/cvodes/serial/cvsFoodWeb_ASAp_kry: src/nvector/serial/libsundials_nvecserial.5.7.0.dylib
examples/cvodes/serial/cvsFoodWeb_ASAp_kry: examples/cvodes/serial/CMakeFiles/cvsFoodWeb_ASAp_kry.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable cvsFoodWeb_ASAp_kry"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/cvodes/serial && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cvsFoodWeb_ASAp_kry.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/cvodes/serial/CMakeFiles/cvsFoodWeb_ASAp_kry.dir/build: examples/cvodes/serial/cvsFoodWeb_ASAp_kry

.PHONY : examples/cvodes/serial/CMakeFiles/cvsFoodWeb_ASAp_kry.dir/build

examples/cvodes/serial/CMakeFiles/cvsFoodWeb_ASAp_kry.dir/clean:
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/cvodes/serial && $(CMAKE_COMMAND) -P CMakeFiles/cvsFoodWeb_ASAp_kry.dir/cmake_clean.cmake
.PHONY : examples/cvodes/serial/CMakeFiles/cvsFoodWeb_ASAp_kry.dir/clean

examples/cvodes/serial/CMakeFiles/cvsFoodWeb_ASAp_kry.dir/depend:
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/cvodes/serial /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/cvodes/serial /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/cvodes/serial/CMakeFiles/cvsFoodWeb_ASAp_kry.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/cvodes/serial/CMakeFiles/cvsFoodWeb_ASAp_kry.dir/depend

