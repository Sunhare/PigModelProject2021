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
include src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/depend.make

# Include the progress variables for this target.
include src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/progress.make

# Include the compile flags for this target's objects.
include src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/flags.make

src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/sunmatrix_sparse.c.o: src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/flags.make
src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/sunmatrix_sparse.c.o: ../src/sunmatrix/sparse/sunmatrix_sparse.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/sunmatrix_sparse.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunmatrix/sparse && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_sunmatrixsparse_static.dir/sunmatrix_sparse.c.o -c /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sunmatrix/sparse/sunmatrix_sparse.c

src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/sunmatrix_sparse.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_sunmatrixsparse_static.dir/sunmatrix_sparse.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunmatrix/sparse && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sunmatrix/sparse/sunmatrix_sparse.c > CMakeFiles/sundials_sunmatrixsparse_static.dir/sunmatrix_sparse.c.i

src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/sunmatrix_sparse.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_sunmatrixsparse_static.dir/sunmatrix_sparse.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunmatrix/sparse && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sunmatrix/sparse/sunmatrix_sparse.c -o CMakeFiles/sundials_sunmatrixsparse_static.dir/sunmatrix_sparse.c.s

src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_nvector.c.o: src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/flags.make
src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_nvector.c.o: ../src/sundials/sundials_nvector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_nvector.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunmatrix/sparse && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_nvector.c.o -c /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sundials/sundials_nvector.c

src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_nvector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_nvector.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunmatrix/sparse && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sundials/sundials_nvector.c > CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_nvector.c.i

src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_nvector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_nvector.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunmatrix/sparse && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sundials/sundials_nvector.c -o CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_nvector.c.s

src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_matrix.c.o: src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/flags.make
src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_matrix.c.o: ../src/sundials/sundials_matrix.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_matrix.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunmatrix/sparse && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_matrix.c.o -c /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sundials/sundials_matrix.c

src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_matrix.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunmatrix/sparse && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sundials/sundials_matrix.c > CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_matrix.c.i

src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_matrix.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunmatrix/sparse && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sundials/sundials_matrix.c -o CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_matrix.c.s

src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_math.c.o: src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/flags.make
src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_math.c.o: ../src/sundials/sundials_math.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_math.c.o"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunmatrix/sparse && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_math.c.o -c /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sundials/sundials_math.c

src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_math.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_math.c.i"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunmatrix/sparse && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sundials/sundials_math.c > CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_math.c.i

src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_math.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_math.c.s"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunmatrix/sparse && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sundials/sundials_math.c -o CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_math.c.s

# Object files for target sundials_sunmatrixsparse_static
sundials_sunmatrixsparse_static_OBJECTS = \
"CMakeFiles/sundials_sunmatrixsparse_static.dir/sunmatrix_sparse.c.o" \
"CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_nvector.c.o" \
"CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_matrix.c.o" \
"CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_math.c.o"

# External object files for target sundials_sunmatrixsparse_static
sundials_sunmatrixsparse_static_EXTERNAL_OBJECTS =

src/sunmatrix/sparse/libsundials_sunmatrixsparse.a: src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/sunmatrix_sparse.c.o
src/sunmatrix/sparse/libsundials_sunmatrixsparse.a: src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_nvector.c.o
src/sunmatrix/sparse/libsundials_sunmatrixsparse.a: src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_matrix.c.o
src/sunmatrix/sparse/libsundials_sunmatrixsparse.a: src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/__/__/sundials/sundials_math.c.o
src/sunmatrix/sparse/libsundials_sunmatrixsparse.a: src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/build.make
src/sunmatrix/sparse/libsundials_sunmatrixsparse.a: src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C static library libsundials_sunmatrixsparse.a"
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunmatrix/sparse && $(CMAKE_COMMAND) -P CMakeFiles/sundials_sunmatrixsparse_static.dir/cmake_clean_target.cmake
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunmatrix/sparse && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sundials_sunmatrixsparse_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/build: src/sunmatrix/sparse/libsundials_sunmatrixsparse.a

.PHONY : src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/build

src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/clean:
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunmatrix/sparse && $(CMAKE_COMMAND) -P CMakeFiles/sundials_sunmatrixsparse_static.dir/cmake_clean.cmake
.PHONY : src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/clean

src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/depend:
	cd /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sunmatrix/sparse /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunmatrix/sparse /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/sunmatrix/sparse/CMakeFiles/sundials_sunmatrixsparse_static.dir/depend

