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
include src/idas/CMakeFiles/sundials_idas_obj_shared.dir/depend.make

# Include the progress variables for this target.
include src/idas/CMakeFiles/sundials_idas_obj_shared.dir/progress.make

# Include the compile flags for this target's objects.
include src/idas/CMakeFiles/sundials_idas_obj_shared.dir/flags.make

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas.c.o: src/idas/CMakeFiles/sundials_idas_obj_shared.dir/flags.make
src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas.c.o: ../../src/idas/idas.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas.c.o"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_idas_obj_shared.dir/idas.c.o -c /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas.c

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_idas_obj_shared.dir/idas.c.i"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas.c > CMakeFiles/sundials_idas_obj_shared.dir/idas.c.i

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_idas_obj_shared.dir/idas.c.s"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas.c -o CMakeFiles/sundials_idas_obj_shared.dir/idas.c.s

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idaa.c.o: src/idas/CMakeFiles/sundials_idas_obj_shared.dir/flags.make
src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idaa.c.o: ../../src/idas/idaa.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idaa.c.o"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_idas_obj_shared.dir/idaa.c.o -c /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idaa.c

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idaa.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_idas_obj_shared.dir/idaa.c.i"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idaa.c > CMakeFiles/sundials_idas_obj_shared.dir/idaa.c.i

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idaa.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_idas_obj_shared.dir/idaa.c.s"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idaa.c -o CMakeFiles/sundials_idas_obj_shared.dir/idaa.c.s

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_direct.c.o: src/idas/CMakeFiles/sundials_idas_obj_shared.dir/flags.make
src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_direct.c.o: ../../src/idas/idas_direct.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_direct.c.o"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_idas_obj_shared.dir/idas_direct.c.o -c /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas_direct.c

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_direct.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_idas_obj_shared.dir/idas_direct.c.i"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas_direct.c > CMakeFiles/sundials_idas_obj_shared.dir/idas_direct.c.i

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_direct.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_idas_obj_shared.dir/idas_direct.c.s"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas_direct.c -o CMakeFiles/sundials_idas_obj_shared.dir/idas_direct.c.s

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_io.c.o: src/idas/CMakeFiles/sundials_idas_obj_shared.dir/flags.make
src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_io.c.o: ../../src/idas/idas_io.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_io.c.o"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_idas_obj_shared.dir/idas_io.c.o -c /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas_io.c

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_io.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_idas_obj_shared.dir/idas_io.c.i"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas_io.c > CMakeFiles/sundials_idas_obj_shared.dir/idas_io.c.i

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_io.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_idas_obj_shared.dir/idas_io.c.s"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas_io.c -o CMakeFiles/sundials_idas_obj_shared.dir/idas_io.c.s

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_ic.c.o: src/idas/CMakeFiles/sundials_idas_obj_shared.dir/flags.make
src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_ic.c.o: ../../src/idas/idas_ic.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_ic.c.o"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_idas_obj_shared.dir/idas_ic.c.o -c /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas_ic.c

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_ic.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_idas_obj_shared.dir/idas_ic.c.i"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas_ic.c > CMakeFiles/sundials_idas_obj_shared.dir/idas_ic.c.i

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_ic.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_idas_obj_shared.dir/idas_ic.c.s"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas_ic.c -o CMakeFiles/sundials_idas_obj_shared.dir/idas_ic.c.s

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idaa_io.c.o: src/idas/CMakeFiles/sundials_idas_obj_shared.dir/flags.make
src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idaa_io.c.o: ../../src/idas/idaa_io.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idaa_io.c.o"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_idas_obj_shared.dir/idaa_io.c.o -c /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idaa_io.c

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idaa_io.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_idas_obj_shared.dir/idaa_io.c.i"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idaa_io.c > CMakeFiles/sundials_idas_obj_shared.dir/idaa_io.c.i

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idaa_io.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_idas_obj_shared.dir/idaa_io.c.s"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idaa_io.c -o CMakeFiles/sundials_idas_obj_shared.dir/idaa_io.c.s

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_ls.c.o: src/idas/CMakeFiles/sundials_idas_obj_shared.dir/flags.make
src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_ls.c.o: ../../src/idas/idas_ls.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_ls.c.o"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_idas_obj_shared.dir/idas_ls.c.o -c /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas_ls.c

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_ls.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_idas_obj_shared.dir/idas_ls.c.i"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas_ls.c > CMakeFiles/sundials_idas_obj_shared.dir/idas_ls.c.i

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_ls.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_idas_obj_shared.dir/idas_ls.c.s"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas_ls.c -o CMakeFiles/sundials_idas_obj_shared.dir/idas_ls.c.s

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_bbdpre.c.o: src/idas/CMakeFiles/sundials_idas_obj_shared.dir/flags.make
src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_bbdpre.c.o: ../../src/idas/idas_bbdpre.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_bbdpre.c.o"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_idas_obj_shared.dir/idas_bbdpre.c.o -c /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas_bbdpre.c

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_bbdpre.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_idas_obj_shared.dir/idas_bbdpre.c.i"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas_bbdpre.c > CMakeFiles/sundials_idas_obj_shared.dir/idas_bbdpre.c.i

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_bbdpre.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_idas_obj_shared.dir/idas_bbdpre.c.s"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas_bbdpre.c -o CMakeFiles/sundials_idas_obj_shared.dir/idas_bbdpre.c.s

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_nls.c.o: src/idas/CMakeFiles/sundials_idas_obj_shared.dir/flags.make
src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_nls.c.o: ../../src/idas/idas_nls.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_nls.c.o"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_idas_obj_shared.dir/idas_nls.c.o -c /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas_nls.c

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_nls.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_idas_obj_shared.dir/idas_nls.c.i"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas_nls.c > CMakeFiles/sundials_idas_obj_shared.dir/idas_nls.c.i

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_nls.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_idas_obj_shared.dir/idas_nls.c.s"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas_nls.c -o CMakeFiles/sundials_idas_obj_shared.dir/idas_nls.c.s

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_nls_sim.c.o: src/idas/CMakeFiles/sundials_idas_obj_shared.dir/flags.make
src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_nls_sim.c.o: ../../src/idas/idas_nls_sim.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_nls_sim.c.o"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_idas_obj_shared.dir/idas_nls_sim.c.o -c /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas_nls_sim.c

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_nls_sim.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_idas_obj_shared.dir/idas_nls_sim.c.i"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas_nls_sim.c > CMakeFiles/sundials_idas_obj_shared.dir/idas_nls_sim.c.i

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_nls_sim.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_idas_obj_shared.dir/idas_nls_sim.c.s"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas_nls_sim.c -o CMakeFiles/sundials_idas_obj_shared.dir/idas_nls_sim.c.s

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_nls_stg.c.o: src/idas/CMakeFiles/sundials_idas_obj_shared.dir/flags.make
src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_nls_stg.c.o: ../../src/idas/idas_nls_stg.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_nls_stg.c.o"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_idas_obj_shared.dir/idas_nls_stg.c.o -c /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas_nls_stg.c

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_nls_stg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_idas_obj_shared.dir/idas_nls_stg.c.i"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas_nls_stg.c > CMakeFiles/sundials_idas_obj_shared.dir/idas_nls_stg.c.i

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_nls_stg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_idas_obj_shared.dir/idas_nls_stg.c.s"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas_nls_stg.c -o CMakeFiles/sundials_idas_obj_shared.dir/idas_nls_stg.c.s

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_spils.c.o: src/idas/CMakeFiles/sundials_idas_obj_shared.dir/flags.make
src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_spils.c.o: ../../src/idas/idas_spils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_spils.c.o"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_idas_obj_shared.dir/idas_spils.c.o -c /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas_spils.c

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_spils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_idas_obj_shared.dir/idas_spils.c.i"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas_spils.c > CMakeFiles/sundials_idas_obj_shared.dir/idas_spils.c.i

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_spils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_idas_obj_shared.dir/idas_spils.c.s"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas/idas_spils.c -o CMakeFiles/sundials_idas_obj_shared.dir/idas_spils.c.s

sundials_idas_obj_shared: src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas.c.o
sundials_idas_obj_shared: src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idaa.c.o
sundials_idas_obj_shared: src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_direct.c.o
sundials_idas_obj_shared: src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_io.c.o
sundials_idas_obj_shared: src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_ic.c.o
sundials_idas_obj_shared: src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idaa_io.c.o
sundials_idas_obj_shared: src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_ls.c.o
sundials_idas_obj_shared: src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_bbdpre.c.o
sundials_idas_obj_shared: src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_nls.c.o
sundials_idas_obj_shared: src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_nls_sim.c.o
sundials_idas_obj_shared: src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_nls_stg.c.o
sundials_idas_obj_shared: src/idas/CMakeFiles/sundials_idas_obj_shared.dir/idas_spils.c.o
sundials_idas_obj_shared: src/idas/CMakeFiles/sundials_idas_obj_shared.dir/build.make

.PHONY : sundials_idas_obj_shared

# Rule to build all files generated by this target.
src/idas/CMakeFiles/sundials_idas_obj_shared.dir/build: sundials_idas_obj_shared

.PHONY : src/idas/CMakeFiles/sundials_idas_obj_shared.dir/build

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/clean:
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas && $(CMAKE_COMMAND) -P CMakeFiles/sundials_idas_obj_shared.dir/cmake_clean.cmake
.PHONY : src/idas/CMakeFiles/sundials_idas_obj_shared.dir/clean

src/idas/CMakeFiles/sundials_idas_obj_shared.dir/depend:
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/idas /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/idas/CMakeFiles/sundials_idas_obj_shared.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/idas/CMakeFiles/sundials_idas_obj_shared.dir/depend
