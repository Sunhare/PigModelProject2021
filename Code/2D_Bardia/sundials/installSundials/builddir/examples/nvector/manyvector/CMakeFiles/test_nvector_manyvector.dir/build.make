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
include examples/nvector/manyvector/CMakeFiles/test_nvector_manyvector.dir/depend.make

# Include the progress variables for this target.
include examples/nvector/manyvector/CMakeFiles/test_nvector_manyvector.dir/progress.make

# Include the compile flags for this target's objects.
include examples/nvector/manyvector/CMakeFiles/test_nvector_manyvector.dir/flags.make

examples/nvector/manyvector/CMakeFiles/test_nvector_manyvector.dir/test_nvector_manyvector.c.o: examples/nvector/manyvector/CMakeFiles/test_nvector_manyvector.dir/flags.make
examples/nvector/manyvector/CMakeFiles/test_nvector_manyvector.dir/test_nvector_manyvector.c.o: ../../examples/nvector/manyvector/test_nvector_manyvector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/nvector/manyvector/CMakeFiles/test_nvector_manyvector.dir/test_nvector_manyvector.c.o"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/nvector/manyvector && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_nvector_manyvector.dir/test_nvector_manyvector.c.o -c /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/nvector/manyvector/test_nvector_manyvector.c

examples/nvector/manyvector/CMakeFiles/test_nvector_manyvector.dir/test_nvector_manyvector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_nvector_manyvector.dir/test_nvector_manyvector.c.i"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/nvector/manyvector && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/nvector/manyvector/test_nvector_manyvector.c > CMakeFiles/test_nvector_manyvector.dir/test_nvector_manyvector.c.i

examples/nvector/manyvector/CMakeFiles/test_nvector_manyvector.dir/test_nvector_manyvector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_nvector_manyvector.dir/test_nvector_manyvector.c.s"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/nvector/manyvector && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/nvector/manyvector/test_nvector_manyvector.c -o CMakeFiles/test_nvector_manyvector.dir/test_nvector_manyvector.c.s

examples/nvector/manyvector/CMakeFiles/test_nvector_manyvector.dir/__/test_nvector.c.o: examples/nvector/manyvector/CMakeFiles/test_nvector_manyvector.dir/flags.make
examples/nvector/manyvector/CMakeFiles/test_nvector_manyvector.dir/__/test_nvector.c.o: ../../examples/nvector/test_nvector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object examples/nvector/manyvector/CMakeFiles/test_nvector_manyvector.dir/__/test_nvector.c.o"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/nvector/manyvector && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_nvector_manyvector.dir/__/test_nvector.c.o -c /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/nvector/test_nvector.c

examples/nvector/manyvector/CMakeFiles/test_nvector_manyvector.dir/__/test_nvector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_nvector_manyvector.dir/__/test_nvector.c.i"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/nvector/manyvector && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/nvector/test_nvector.c > CMakeFiles/test_nvector_manyvector.dir/__/test_nvector.c.i

examples/nvector/manyvector/CMakeFiles/test_nvector_manyvector.dir/__/test_nvector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_nvector_manyvector.dir/__/test_nvector.c.s"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/nvector/manyvector && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/nvector/test_nvector.c -o CMakeFiles/test_nvector_manyvector.dir/__/test_nvector.c.s

# Object files for target test_nvector_manyvector
test_nvector_manyvector_OBJECTS = \
"CMakeFiles/test_nvector_manyvector.dir/test_nvector_manyvector.c.o" \
"CMakeFiles/test_nvector_manyvector.dir/__/test_nvector.c.o"

# External object files for target test_nvector_manyvector
test_nvector_manyvector_EXTERNAL_OBJECTS =

examples/nvector/manyvector/test_nvector_manyvector: examples/nvector/manyvector/CMakeFiles/test_nvector_manyvector.dir/test_nvector_manyvector.c.o
examples/nvector/manyvector/test_nvector_manyvector: examples/nvector/manyvector/CMakeFiles/test_nvector_manyvector.dir/__/test_nvector.c.o
examples/nvector/manyvector/test_nvector_manyvector: examples/nvector/manyvector/CMakeFiles/test_nvector_manyvector.dir/build.make
examples/nvector/manyvector/test_nvector_manyvector: src/nvector/serial/libsundials_nvecserial.5.7.0.dylib
examples/nvector/manyvector/test_nvector_manyvector: src/nvector/manyvector/libsundials_nvecmanyvector.5.7.0.dylib
examples/nvector/manyvector/test_nvector_manyvector: examples/nvector/manyvector/CMakeFiles/test_nvector_manyvector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable test_nvector_manyvector"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/nvector/manyvector && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_nvector_manyvector.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/nvector/manyvector/CMakeFiles/test_nvector_manyvector.dir/build: examples/nvector/manyvector/test_nvector_manyvector

.PHONY : examples/nvector/manyvector/CMakeFiles/test_nvector_manyvector.dir/build

examples/nvector/manyvector/CMakeFiles/test_nvector_manyvector.dir/clean:
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/nvector/manyvector && $(CMAKE_COMMAND) -P CMakeFiles/test_nvector_manyvector.dir/cmake_clean.cmake
.PHONY : examples/nvector/manyvector/CMakeFiles/test_nvector_manyvector.dir/clean

examples/nvector/manyvector/CMakeFiles/test_nvector_manyvector.dir/depend:
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/nvector/manyvector /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/nvector/manyvector /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/nvector/manyvector/CMakeFiles/test_nvector_manyvector.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/nvector/manyvector/CMakeFiles/test_nvector_manyvector.dir/depend

