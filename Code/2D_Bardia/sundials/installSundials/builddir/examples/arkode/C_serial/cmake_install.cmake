# Install script for directory: /Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial

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
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/ark_analytic.c;/usr/local/examples/arkode/C_serial/ark_analytic.out")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_analytic.c"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_analytic.out"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/ark_analytic_nonlin.c;/usr/local/examples/arkode/C_serial/ark_analytic_nonlin.out")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_analytic_nonlin.c"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_analytic_nonlin.out"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/ark_brusselator.c;/usr/local/examples/arkode/C_serial/ark_brusselator.out")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_brusselator.c"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_brusselator.out"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/ark_brusselator_fp.c;/usr/local/examples/arkode/C_serial/ark_brusselator_fp.out")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_brusselator_fp.c"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_brusselator_fp.out"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/ark_brusselator1D.c;/usr/local/examples/arkode/C_serial/ark_brusselator1D.out")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_brusselator1D.c"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_brusselator1D.out"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/ark_heat1D.c;/usr/local/examples/arkode/C_serial/ark_heat1D.out")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_heat1D.c"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_heat1D.out"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/ark_heat1D_adapt.c;/usr/local/examples/arkode/C_serial/ark_heat1D_adapt.out")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_heat1D_adapt.c"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_heat1D_adapt.out"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/ark_KrylovDemo_prec.c;/usr/local/examples/arkode/C_serial/ark_KrylovDemo_prec.out")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_KrylovDemo_prec.c"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_KrylovDemo_prec.out"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/ark_KrylovDemo_prec.c;/usr/local/examples/arkode/C_serial/ark_KrylovDemo_prec.out")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_KrylovDemo_prec.c"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_KrylovDemo_prec.out"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/ark_KrylovDemo_prec.c;/usr/local/examples/arkode/C_serial/ark_KrylovDemo_prec.out")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_KrylovDemo_prec.c"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_KrylovDemo_prec.out"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/ark_robertson.c;/usr/local/examples/arkode/C_serial/ark_robertson.out")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_robertson.c"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_robertson.out"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/ark_robertson_constraints.c;/usr/local/examples/arkode/C_serial/ark_robertson_constraints.out")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_robertson_constraints.c"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_robertson_constraints.out"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/ark_robertson_root.c;/usr/local/examples/arkode/C_serial/ark_robertson_root.out")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_robertson_root.c"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_robertson_root.out"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/ark_brusselator_mri.c;/usr/local/examples/arkode/C_serial/ark_brusselator_mri.out")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_brusselator_mri.c"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_brusselator_mri.out"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/ark_onewaycouple_mri.c;/usr/local/examples/arkode/C_serial/ark_onewaycouple_mri.out")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_onewaycouple_mri.c"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_onewaycouple_mri.out"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/ark_twowaycouple_mri.c;/usr/local/examples/arkode/C_serial/ark_twowaycouple_mri.out")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_twowaycouple_mri.c"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_twowaycouple_mri.out"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/ark_reaction_diffusion_mri.c;/usr/local/examples/arkode/C_serial/ark_reaction_diffusion_mri.out")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_reaction_diffusion_mri.c"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_reaction_diffusion_mri.out"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/ark_brusselator_1D_mri.c;/usr/local/examples/arkode/C_serial/ark_brusselator_1D_mri.out")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_brusselator_1D_mri.c"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_brusselator_1D_mri.out"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/ark_kpr_mri.c;/usr/local/examples/arkode/C_serial/ark_kpr_mri.out")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_kpr_mri.c"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_kpr_mri.out"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/ark_kpr_mri.c;/usr/local/examples/arkode/C_serial/ark_kpr_mri.out")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_kpr_mri.c"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_kpr_mri.out"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/ark_kpr_mri.c;/usr/local/examples/arkode/C_serial/ark_kpr_mri.out")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_kpr_mri.c"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_kpr_mri.out"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/ark_kpr_mri.c;/usr/local/examples/arkode/C_serial/ark_kpr_mri.out")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_kpr_mri.c"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_kpr_mri.out"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/ark_kpr_mri.c;/usr/local/examples/arkode/C_serial/ark_kpr_mri.out")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_kpr_mri.c"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_kpr_mri.out"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/ark_kpr_mri.c;/usr/local/examples/arkode/C_serial/ark_kpr_mri.out")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_kpr_mri.c"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_kpr_mri.out"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/ark_kpr_mri.c;/usr/local/examples/arkode/C_serial/ark_kpr_mri.out")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_kpr_mri.c"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_kpr_mri.out"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/ark_kpr_mri.c;/usr/local/examples/arkode/C_serial/ark_kpr_mri.out")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_kpr_mri.c"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_kpr_mri.out"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/ark_kpr_mri.c;/usr/local/examples/arkode/C_serial/ark_kpr_mri.out")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_kpr_mri.c"
    "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/ark_kpr_mri.out"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/README")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/README")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/plot_brusselator1D.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/plot_brusselator1D.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/plot_brusselator1D_FEM.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/plot_brusselator1D_FEM.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/plot_heat1D.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/plot_heat1D.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/plot_heat1D_adapt.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/plot_heat1D_adapt.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/plot_sol.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/plot_sol.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/plot_sol_log.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/examples/arkode/C_serial/plot_sol_log.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/CMakeLists.txt")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE FILES "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/arkode/C_serial/CMakeLists.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/examples/arkode/C_serial/Makefile")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/examples/arkode/C_serial" TYPE FILE RENAME "Makefile" FILES "/Users/satolab/Documents/Projects/PigModelProject2021/Code/2D_Bardia/sundials/installSundials/builddir/examples/arkode/C_serial/Makefile_ex")
endif()

