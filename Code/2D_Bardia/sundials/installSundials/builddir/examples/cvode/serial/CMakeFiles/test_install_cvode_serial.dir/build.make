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

# Utility rule file for test_install_cvode_serial.

# Include the progress variables for this target.
include examples/cvode/serial/CMakeFiles/test_install_cvode_serial.dir/progress.make

examples/cvode/serial/CMakeFiles/test_install_cvode_serial:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running cvode installation tests"
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/Testing_Install/cvode/serial && /usr/local/Cellar/cmake/3.18.4/bin/cmake /usr/local/examples/cvode/serial > cmake.out
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/Testing_Install/cvode/serial && /usr/local/Cellar/cmake/3.18.4/bin/cmake --build /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/Testing_Install/cvode/serial --target cvRoberts_dns > make.out
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/Testing_Install/cvode/serial && /usr/local/Cellar/cmake/3.18.4/bin/ctest -R "^cvRoberts_dns\$$"

test_install_cvode_serial: examples/cvode/serial/CMakeFiles/test_install_cvode_serial
test_install_cvode_serial: examples/cvode/serial/CMakeFiles/test_install_cvode_serial.dir/build.make

.PHONY : test_install_cvode_serial

# Rule to build all files generated by this target.
examples/cvode/serial/CMakeFiles/test_install_cvode_serial.dir/build: test_install_cvode_serial

.PHONY : examples/cvode/serial/CMakeFiles/test_install_cvode_serial.dir/build

examples/cvode/serial/CMakeFiles/test_install_cvode_serial.dir/clean:
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/cvode/serial && $(CMAKE_COMMAND) -P CMakeFiles/test_install_cvode_serial.dir/cmake_clean.cmake
.PHONY : examples/cvode/serial/CMakeFiles/test_install_cvode_serial.dir/clean

examples/cvode/serial/CMakeFiles/test_install_cvode_serial.dir/depend:
	cd /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/cvode/serial /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/cvode/serial /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/cvode/serial/CMakeFiles/test_install_cvode_serial.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/cvode/serial/CMakeFiles/test_install_cvode_serial.dir/depend
