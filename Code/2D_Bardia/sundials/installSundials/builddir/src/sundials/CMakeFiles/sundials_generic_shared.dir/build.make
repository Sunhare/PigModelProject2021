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
include src/sundials/CMakeFiles/sundials_generic_shared.dir/depend.make

# Include the progress variables for this target.
include src/sundials/CMakeFiles/sundials_generic_shared.dir/progress.make

# Include the compile flags for this target's objects.
include src/sundials/CMakeFiles/sundials_generic_shared.dir/flags.make

# Object files for target sundials_generic_shared
sundials_generic_shared_OBJECTS =

# External object files for target sundials_generic_shared
sundials_generic_shared_EXTERNAL_OBJECTS = \
"/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/sundials/CMakeFiles/sundials_generic_obj_shared.dir/sundials_band.c.o" \
"/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/sundials/CMakeFiles/sundials_generic_obj_shared.dir/sundials_dense.c.o" \
"/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/sundials/CMakeFiles/sundials_generic_obj_shared.dir/sundials_direct.c.o" \
"/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/sundials/CMakeFiles/sundials_generic_obj_shared.dir/sundials_futils.c.o" \
"/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/sundials/CMakeFiles/sundials_generic_obj_shared.dir/sundials_iterative.c.o" \
"/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/sundials/CMakeFiles/sundials_generic_obj_shared.dir/sundials_linearsolver.c.o" \
"/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/sundials/CMakeFiles/sundials_generic_obj_shared.dir/sundials_math.c.o" \
"/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/sundials/CMakeFiles/sundials_generic_obj_shared.dir/sundials_matrix.c.o" \
"/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/sundials/CMakeFiles/sundials_generic_obj_shared.dir/sundials_memory.c.o" \
"/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/sundials/CMakeFiles/sundials_generic_obj_shared.dir/sundials_nonlinearsolver.c.o" \
"/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/sundials/CMakeFiles/sundials_generic_obj_shared.dir/sundials_nvector.c.o" \
"/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/sundials/CMakeFiles/sundials_generic_obj_shared.dir/sundials_nvector_senswrapper.c.o" \
"/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/sundials/CMakeFiles/sundials_generic_obj_shared.dir/sundials_version.c.o"

src/sundials/libsundials_generic.5.7.0.dylib: src/sundials/CMakeFiles/sundials_generic_obj_shared.dir/sundials_band.c.o
src/sundials/libsundials_generic.5.7.0.dylib: src/sundials/CMakeFiles/sundials_generic_obj_shared.dir/sundials_dense.c.o
src/sundials/libsundials_generic.5.7.0.dylib: src/sundials/CMakeFiles/sundials_generic_obj_shared.dir/sundials_direct.c.o
src/sundials/libsundials_generic.5.7.0.dylib: src/sundials/CMakeFiles/sundials_generic_obj_shared.dir/sundials_futils.c.o
src/sundials/libsundials_generic.5.7.0.dylib: src/sundials/CMakeFiles/sundials_generic_obj_shared.dir/sundials_iterative.c.o
src/sundials/libsundials_generic.5.7.0.dylib: src/sundials/CMakeFiles/sundials_generic_obj_shared.dir/sundials_linearsolver.c.o
src/sundials/libsundials_generic.5.7.0.dylib: src/sundials/CMakeFiles/sundials_generic_obj_shared.dir/sundials_math.c.o
src/sundials/libsundials_generic.5.7.0.dylib: src/sundials/CMakeFiles/sundials_generic_obj_shared.dir/sundials_matrix.c.o
src/sundials/libsundials_generic.5.7.0.dylib: src/sundials/CMakeFiles/sundials_generic_obj_shared.dir/sundials_memory.c.o
src/sundials/libsundials_generic.5.7.0.dylib: src/sundials/CMakeFiles/sundials_generic_obj_shared.dir/sundials_nonlinearsolver.c.o
src/sundials/libsundials_generic.5.7.0.dylib: src/sundials/CMakeFiles/sundials_generic_obj_shared.dir/sundials_nvector.c.o
src/sundials/libsundials_generic.5.7.0.dylib: src/sundials/CMakeFiles/sundials_generic_obj_shared.dir/sundials_nvector_senswrapper.c.o
src/sundials/libsundials_generic.5.7.0.dylib: src/sundials/CMakeFiles/sundials_generic_obj_shared.dir/sundials_version.c.o
src/sundials/libsundials_generic.5.7.0.dylib: src/sundials/CMakeFiles/sundials_generic_shared.dir/build.make
src/sundials/libsundials_generic.5.7.0.dylib: src/sundials/CMakeFiles/sundials_generic_shared.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking C shared library libsundials_generic.dylib"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/sundials && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sundials_generic_shared.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/sundials && $(CMAKE_COMMAND) -E cmake_symlink_library libsundials_generic.5.7.0.dylib libsundials_generic.5.dylib libsundials_generic.dylib

src/sundials/libsundials_generic.5.dylib: src/sundials/libsundials_generic.5.7.0.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate src/sundials/libsundials_generic.5.dylib

src/sundials/libsundials_generic.dylib: src/sundials/libsundials_generic.5.7.0.dylib
	@$(CMAKE_COMMAND) -E touch_nocreate src/sundials/libsundials_generic.dylib

# Rule to build all files generated by this target.
src/sundials/CMakeFiles/sundials_generic_shared.dir/build: src/sundials/libsundials_generic.dylib

.PHONY : src/sundials/CMakeFiles/sundials_generic_shared.dir/build

src/sundials/CMakeFiles/sundials_generic_shared.dir/clean:
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/sundials && $(CMAKE_COMMAND) -P CMakeFiles/sundials_generic_shared.dir/cmake_clean.cmake
.PHONY : src/sundials/CMakeFiles/sundials_generic_shared.dir/clean

src/sundials/CMakeFiles/sundials_generic_shared.dir/depend:
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/sundials /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/sundials /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/sundials/CMakeFiles/sundials_generic_shared.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/sundials/CMakeFiles/sundials_generic_shared.dir/depend

