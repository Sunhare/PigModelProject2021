# Install script for directory: /Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/src/cvode

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
Install CVODE
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/builddir/src/cvode/libsundials_cvode.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsundials_cvode.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsundials_cvode.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsundials_cvode.a")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cvode" TYPE FILE FILES
    "/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/include/cvode/cvode.h"
    "/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/include/cvode/cvode_bandpre.h"
    "/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/include/cvode/cvode_bbdpre.h"
    "/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/include/cvode/cvode_diag.h"
    "/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/include/cvode/cvode_direct.h"
    "/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/include/cvode/cvode_ls.h"
    "/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/include/cvode/cvode_proj.h"
    "/Users/satolab/Desktop/ShannonPigModel/draft_pig_model_code/sundials/include/cvode/cvode_spils.h"
    )
endif()

