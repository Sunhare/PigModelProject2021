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
include examples/cvodes/serial/CMakeFiles/cvsKrylovDemo_prec.dir/depend.make

# Include the progress variables for this target.
include examples/cvodes/serial/CMakeFiles/cvsKrylovDemo_prec.dir/progress.make

# Include the compile flags for this target's objects.
include examples/cvodes/serial/CMakeFiles/cvsKrylovDemo_prec.dir/flags.make

examples/cvodes/serial/CMakeFiles/cvsKrylovDemo_prec.dir/cvsKrylovDemo_prec.c.o: examples/cvodes/serial/CMakeFiles/cvsKrylovDemo_prec.dir/flags.make
examples/cvodes/serial/CMakeFiles/cvsKrylovDemo_prec.dir/cvsKrylovDemo_prec.c.o: ../../examples/cvodes/serial/cvsKrylovDemo_prec.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/cvodes/serial/CMakeFiles/cvsKrylovDemo_prec.dir/cvsKrylovDemo_prec.c.o"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/cvodes/serial && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cvsKrylovDemo_prec.dir/cvsKrylovDemo_prec.c.o -c /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/cvodes/serial/cvsKrylovDemo_prec.c

examples/cvodes/serial/CMakeFiles/cvsKrylovDemo_prec.dir/cvsKrylovDemo_prec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cvsKrylovDemo_prec.dir/cvsKrylovDemo_prec.c.i"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/cvodes/serial && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/cvodes/serial/cvsKrylovDemo_prec.c > CMakeFiles/cvsKrylovDemo_prec.dir/cvsKrylovDemo_prec.c.i

examples/cvodes/serial/CMakeFiles/cvsKrylovDemo_prec.dir/cvsKrylovDemo_prec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cvsKrylovDemo_prec.dir/cvsKrylovDemo_prec.c.s"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/cvodes/serial && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/cvodes/serial/cvsKrylovDemo_prec.c -o CMakeFiles/cvsKrylovDemo_prec.dir/cvsKrylovDemo_prec.c.s

# Object files for target cvsKrylovDemo_prec
cvsKrylovDemo_prec_OBJECTS = \
"CMakeFiles/cvsKrylovDemo_prec.dir/cvsKrylovDemo_prec.c.o"

# External object files for target cvsKrylovDemo_prec
cvsKrylovDemo_prec_EXTERNAL_OBJECTS =

examples/cvodes/serial/cvsKrylovDemo_prec: examples/cvodes/serial/CMakeFiles/cvsKrylovDemo_prec.dir/cvsKrylovDemo_prec.c.o
examples/cvodes/serial/cvsKrylovDemo_prec: examples/cvodes/serial/CMakeFiles/cvsKrylovDemo_prec.dir/build.make
examples/cvodes/serial/cvsKrylovDemo_prec: src/cvodes/libsundials_cvodes.5.7.0.dylib
examples/cvodes/serial/cvsKrylovDemo_prec: src/nvector/serial/libsundials_nvecserial.5.7.0.dylib
examples/cvodes/serial/cvsKrylovDemo_prec: examples/cvodes/serial/CMakeFiles/cvsKrylovDemo_prec.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable cvsKrylovDemo_prec"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/cvodes/serial && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cvsKrylovDemo_prec.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/cvodes/serial/CMakeFiles/cvsKrylovDemo_prec.dir/build: examples/cvodes/serial/cvsKrylovDemo_prec

.PHONY : examples/cvodes/serial/CMakeFiles/cvsKrylovDemo_prec.dir/build

examples/cvodes/serial/CMakeFiles/cvsKrylovDemo_prec.dir/clean:
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/cvodes/serial && $(CMAKE_COMMAND) -P CMakeFiles/cvsKrylovDemo_prec.dir/cmake_clean.cmake
.PHONY : examples/cvodes/serial/CMakeFiles/cvsKrylovDemo_prec.dir/clean

examples/cvodes/serial/CMakeFiles/cvsKrylovDemo_prec.dir/depend:
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/cvodes/serial /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/cvodes/serial /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/cvodes/serial/CMakeFiles/cvsKrylovDemo_prec.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/cvodes/serial/CMakeFiles/cvsKrylovDemo_prec.dir/depend
