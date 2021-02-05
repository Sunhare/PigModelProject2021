# Install script for directory: /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/arkode/cmake_install.cmake")
  include("/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/cvode/cmake_install.cmake")
  include("/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/cvodes/cmake_install.cmake")
  include("/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/ida/cmake_install.cmake")
  include("/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/idas/cmake_install.cmake")
  include("/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/kinsol/cmake_install.cmake")
  include("/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/nvector/cmake_install.cmake")
  include("/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/sunmatrix/cmake_install.cmake")
  include("/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/sunlinsol/cmake_install.cmake")
  include("/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/sunnonlinsol/cmake_install.cmake")

endif()
