# Install script for directory: /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/sundials

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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  MESSAGE("
Install shared components
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/sundials" TYPE FILE FILES
    "/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/include/sundials/sundials_band.h"
    "/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/include/sundials/sundials_dense.h"
    "/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/include/sundials/sundials_direct.h"
    "/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/include/sundials/sundials_fnvector.h"
    "/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/include/sundials/sundials_futils.h"
    "/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/include/sundials/sundials_iterative.h"
    "/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/include/sundials/sundials_linearsolver.h"
    "/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/include/sundials/sundials_math.h"
    "/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/include/sundials/sundials_matrix.h"
    "/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/include/sundials/sundials_nonlinearsolver.h"
    "/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/include/sundials/sundials_mpi_types.h"
    "/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/include/sundials/sundials_nvector.h"
    "/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/include/sundials/sundials_types.h"
    "/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/include/sundials/sundials_version.h"
    )
endif()

