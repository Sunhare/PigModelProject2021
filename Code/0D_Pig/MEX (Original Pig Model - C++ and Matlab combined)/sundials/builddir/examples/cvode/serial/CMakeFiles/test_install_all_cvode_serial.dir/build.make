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

# Utility rule file for test_install_all_cvode_serial.

# Include the progress variables for this target.
include examples/cvode/serial/CMakeFiles/test_install_all_cvode_serial.dir/progress.make

examples/cvode/serial/CMakeFiles/test_install_all_cvode_serial:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running cvode installation tests"
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/Testing_Install_All/cvode/serial && /usr/local/Cellar/cmake/3.15.5/bin/cmake /usr/local/examples/cvode/serial > cmake.out
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/Testing_Install_All/cvode/serial && /usr/local/Cellar/cmake/3.15.5/bin/cmake --build /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/Testing_Install_All/cvode/serial > make.out

test_install_all_cvode_serial: examples/cvode/serial/CMakeFiles/test_install_all_cvode_serial
test_install_all_cvode_serial: examples/cvode/serial/CMakeFiles/test_install_all_cvode_serial.dir/build.make

.PHONY : test_install_all_cvode_serial

# Rule to build all files generated by this target.
examples/cvode/serial/CMakeFiles/test_install_all_cvode_serial.dir/build: test_install_all_cvode_serial

.PHONY : examples/cvode/serial/CMakeFiles/test_install_all_cvode_serial.dir/build

examples/cvode/serial/CMakeFiles/test_install_all_cvode_serial.dir/clean:
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/cvode/serial && $(CMAKE_COMMAND) -P CMakeFiles/test_install_all_cvode_serial.dir/cmake_clean.cmake
.PHONY : examples/cvode/serial/CMakeFiles/test_install_all_cvode_serial.dir/clean

examples/cvode/serial/CMakeFiles/test_install_all_cvode_serial.dir/depend:
	cd /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0 /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/cvode/serial /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/cvode/serial /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/cvode/serial/CMakeFiles/test_install_all_cvode_serial.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/cvode/serial/CMakeFiles/test_install_all_cvode_serial.dir/depend
