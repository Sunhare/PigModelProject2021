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
include examples/cvode/serial/CMakeFiles/cvKrylovDemo_ls.dir/depend.make

# Include the progress variables for this target.
include examples/cvode/serial/CMakeFiles/cvKrylovDemo_ls.dir/progress.make

# Include the compile flags for this target's objects.
include examples/cvode/serial/CMakeFiles/cvKrylovDemo_ls.dir/flags.make

examples/cvode/serial/CMakeFiles/cvKrylovDemo_ls.dir/cvKrylovDemo_ls.c.o: examples/cvode/serial/CMakeFiles/cvKrylovDemo_ls.dir/flags.make
examples/cvode/serial/CMakeFiles/cvKrylovDemo_ls.dir/cvKrylovDemo_ls.c.o: ../examples/cvode/serial/cvKrylovDemo_ls.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/cvode/serial/CMakeFiles/cvKrylovDemo_ls.dir/cvKrylovDemo_ls.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/examples/cvode/serial && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cvKrylovDemo_ls.dir/cvKrylovDemo_ls.c.o -c /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/examples/cvode/serial/cvKrylovDemo_ls.c

examples/cvode/serial/CMakeFiles/cvKrylovDemo_ls.dir/cvKrylovDemo_ls.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cvKrylovDemo_ls.dir/cvKrylovDemo_ls.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/examples/cvode/serial && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/examples/cvode/serial/cvKrylovDemo_ls.c > CMakeFiles/cvKrylovDemo_ls.dir/cvKrylovDemo_ls.c.i

examples/cvode/serial/CMakeFiles/cvKrylovDemo_ls.dir/cvKrylovDemo_ls.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cvKrylovDemo_ls.dir/cvKrylovDemo_ls.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/examples/cvode/serial && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/examples/cvode/serial/cvKrylovDemo_ls.c -o CMakeFiles/cvKrylovDemo_ls.dir/cvKrylovDemo_ls.c.s

# Object files for target cvKrylovDemo_ls
cvKrylovDemo_ls_OBJECTS = \
"CMakeFiles/cvKrylovDemo_ls.dir/cvKrylovDemo_ls.c.o"

# External object files for target cvKrylovDemo_ls
cvKrylovDemo_ls_EXTERNAL_OBJECTS =

examples/cvode/serial/cvKrylovDemo_ls: examples/cvode/serial/CMakeFiles/cvKrylovDemo_ls.dir/cvKrylovDemo_ls.c.o
examples/cvode/serial/cvKrylovDemo_ls: examples/cvode/serial/CMakeFiles/cvKrylovDemo_ls.dir/build.make
examples/cvode/serial/cvKrylovDemo_ls: src/cvode/libsundials_cvode.a
examples/cvode/serial/cvKrylovDemo_ls: src/nvector/serial/libsundials_nvecserial.a
examples/cvode/serial/cvKrylovDemo_ls: examples/cvode/serial/CMakeFiles/cvKrylovDemo_ls.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable cvKrylovDemo_ls"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/examples/cvode/serial && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cvKrylovDemo_ls.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/cvode/serial/CMakeFiles/cvKrylovDemo_ls.dir/build: examples/cvode/serial/cvKrylovDemo_ls

.PHONY : examples/cvode/serial/CMakeFiles/cvKrylovDemo_ls.dir/build

examples/cvode/serial/CMakeFiles/cvKrylovDemo_ls.dir/clean:
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/examples/cvode/serial && $(CMAKE_COMMAND) -P CMakeFiles/cvKrylovDemo_ls.dir/cmake_clean.cmake
.PHONY : examples/cvode/serial/CMakeFiles/cvKrylovDemo_ls.dir/clean

examples/cvode/serial/CMakeFiles/cvKrylovDemo_ls.dir/depend:
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/examples/cvode/serial /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/examples/cvode/serial /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/examples/cvode/serial/CMakeFiles/cvKrylovDemo_ls.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/cvode/serial/CMakeFiles/cvKrylovDemo_ls.dir/depend

