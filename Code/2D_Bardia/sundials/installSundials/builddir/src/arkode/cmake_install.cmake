# Install script for directory: /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/src/arkode

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
Install ARKODE
")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/arkode/libsundials_arkode.4.7.0.dylib"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/arkode/libsundials_arkode.4.dylib"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsundials_arkode.4.7.0.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsundials_arkode.4.dylib"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      execute_process(COMMAND "/usr/bin/install_name_tool"
        -id "/usr/local/lib/libsundials_arkode.4.dylib"
        "${file}")
      execute_process(COMMAND /usr/bin/install_name_tool
        -add_rpath "/usr/local/lib"
        "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -x "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/src/arkode/libsundials_arkode.dylib")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsundials_arkode.dylib" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsundials_arkode.dylib")
    execute_process(COMMAND "/usr/bin/install_name_tool"
      -id "/usr/local/lib/libsundials_arkode.4.dylib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsundials_arkode.dylib")
    execute_process(COMMAND /usr/bin/install_name_tool
      -add_rpath "/usr/local/lib"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsundials_arkode.dylib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -x "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libsundials_arkode.dylib")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/arkode" TYPE FILE FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/include/arkode/arkode_arkstep.h"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/include/arkode/arkode_bandpre.h"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/include/arkode/arkode_bbdpre.h"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/include/arkode/arkode_butcher_dirk.h"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/include/arkode/arkode_butcher_erk.h"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/include/arkode/arkode_butcher.h"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/include/arkode/arkode_erkstep.h"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/include/arkode/arkode_ls.h"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/include/arkode/arkode_mristep.h"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/include/arkode/arkode.h"
    )
endif()
