# Install script for directory: /Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/sunmatrix/dense

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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/sunmatrix/dense/test_sunmatrix_dense.c;/usr/local/examples/sunmatrix/dense/test_sunmatrix.c;/usr/local/examples/sunmatrix/dense/test_sunmatrix.h;/usr/local/examples/sunmatrix/dense/sundials_matrix.c;/usr/local/examples/sunmatrix/dense/sundials_nvector.c")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/sunmatrix/dense" TYPE FILE FILES
    "/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/sunmatrix/dense/test_sunmatrix_dense.c"
    "/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/sunmatrix/dense/../test_sunmatrix.c"
    "/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/sunmatrix/dense/../test_sunmatrix.h"
    "/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_matrix.c"
    "/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nvector.c"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/sunmatrix/dense/test_sunmatrix_dense.c;/usr/local/examples/sunmatrix/dense/test_sunmatrix.c;/usr/local/examples/sunmatrix/dense/test_sunmatrix.h;/usr/local/examples/sunmatrix/dense/sundials_matrix.c;/usr/local/examples/sunmatrix/dense/sundials_nvector.c")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/sunmatrix/dense" TYPE FILE FILES
    "/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/sunmatrix/dense/test_sunmatrix_dense.c"
    "/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/sunmatrix/dense/../test_sunmatrix.c"
    "/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/sunmatrix/dense/../test_sunmatrix.h"
    "/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_matrix.c"
    "/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nvector.c"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/sunmatrix/dense/test_sunmatrix_dense.c;/usr/local/examples/sunmatrix/dense/test_sunmatrix.c;/usr/local/examples/sunmatrix/dense/test_sunmatrix.h;/usr/local/examples/sunmatrix/dense/sundials_matrix.c;/usr/local/examples/sunmatrix/dense/sundials_nvector.c")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/sunmatrix/dense" TYPE FILE FILES
    "/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/sunmatrix/dense/test_sunmatrix_dense.c"
    "/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/sunmatrix/dense/../test_sunmatrix.c"
    "/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/examples/sunmatrix/dense/../test_sunmatrix.h"
    "/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_matrix.c"
    "/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/cvode-5.0.0/src/sundials/sundials_nvector.c"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/sunmatrix/dense/CMakeLists.txt")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/sunmatrix/dense" TYPE FILE FILES "/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunmatrix/dense/CMakeLists.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/sunmatrix/dense/Makefile")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/sunmatrix/dense" TYPE FILE RENAME "Makefile" FILES "/Users/satolab/Desktop/ShannonPigModel/Cpp_files/sundials/builddir/examples/sunmatrix/dense/Makefile_ex")
endif()

