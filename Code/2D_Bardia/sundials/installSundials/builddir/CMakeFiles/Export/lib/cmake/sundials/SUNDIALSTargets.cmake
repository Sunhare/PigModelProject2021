# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.5)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6...3.17)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget SUNDIALS::generic_shared SUNDIALS::nvecserial_shared SUNDIALS::nvecmanyvector_shared SUNDIALS::sunmatrixband_shared SUNDIALS::sunmatrixdense_shared SUNDIALS::sunmatrixsparse_shared SUNDIALS::sunlinsolband_shared SUNDIALS::sunlinsoldense_shared SUNDIALS::sunlinsolpcg_shared SUNDIALS::sunlinsolspbcgs_shared SUNDIALS::sunlinsolspfgmr_shared SUNDIALS::sunlinsolspgmr_shared SUNDIALS::sunlinsolsptfqmr_shared SUNDIALS::sunnonlinsolnewton_shared SUNDIALS::sunnonlinsolfixedpoint_shared SUNDIALS::arkode_shared SUNDIALS::cvode_shared SUNDIALS::cvodes_shared SUNDIALS::ida_shared SUNDIALS::idas_shared SUNDIALS::kinsol_shared)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  unset(_targetsDefined)
  unset(_targetsNotDefined)
  unset(_expectedTargets)
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Compute the installation prefix relative to this file.
get_filename_component(_IMPORT_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
if(_IMPORT_PREFIX STREQUAL "/")
  set(_IMPORT_PREFIX "")
endif()

# Create imported target SUNDIALS::generic_shared
add_library(SUNDIALS::generic_shared SHARED IMPORTED)

set_target_properties(SUNDIALS::generic_shared PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
)

# Create imported target SUNDIALS::nvecserial_shared
add_library(SUNDIALS::nvecserial_shared SHARED IMPORTED)

set_target_properties(SUNDIALS::nvecserial_shared PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
)

# Create imported target SUNDIALS::nvecmanyvector_shared
add_library(SUNDIALS::nvecmanyvector_shared SHARED IMPORTED)

set_target_properties(SUNDIALS::nvecmanyvector_shared PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
)

# Create imported target SUNDIALS::sunmatrixband_shared
add_library(SUNDIALS::sunmatrixband_shared SHARED IMPORTED)

set_target_properties(SUNDIALS::sunmatrixband_shared PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
)

# Create imported target SUNDIALS::sunmatrixdense_shared
add_library(SUNDIALS::sunmatrixdense_shared SHARED IMPORTED)

set_target_properties(SUNDIALS::sunmatrixdense_shared PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
)

# Create imported target SUNDIALS::sunmatrixsparse_shared
add_library(SUNDIALS::sunmatrixsparse_shared SHARED IMPORTED)

set_target_properties(SUNDIALS::sunmatrixsparse_shared PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
)

# Create imported target SUNDIALS::sunlinsolband_shared
add_library(SUNDIALS::sunlinsolband_shared SHARED IMPORTED)

set_target_properties(SUNDIALS::sunlinsolband_shared PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "SUNDIALS::sunmatrixband_shared"
)

# Create imported target SUNDIALS::sunlinsoldense_shared
add_library(SUNDIALS::sunlinsoldense_shared SHARED IMPORTED)

set_target_properties(SUNDIALS::sunlinsoldense_shared PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "SUNDIALS::sunmatrixdense_shared"
)

# Create imported target SUNDIALS::sunlinsolpcg_shared
add_library(SUNDIALS::sunlinsolpcg_shared SHARED IMPORTED)

set_target_properties(SUNDIALS::sunlinsolpcg_shared PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
)

# Create imported target SUNDIALS::sunlinsolspbcgs_shared
add_library(SUNDIALS::sunlinsolspbcgs_shared SHARED IMPORTED)

set_target_properties(SUNDIALS::sunlinsolspbcgs_shared PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
)

# Create imported target SUNDIALS::sunlinsolspfgmr_shared
add_library(SUNDIALS::sunlinsolspfgmr_shared SHARED IMPORTED)

set_target_properties(SUNDIALS::sunlinsolspfgmr_shared PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
)

# Create imported target SUNDIALS::sunlinsolspgmr_shared
add_library(SUNDIALS::sunlinsolspgmr_shared SHARED IMPORTED)

set_target_properties(SUNDIALS::sunlinsolspgmr_shared PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
)

# Create imported target SUNDIALS::sunlinsolsptfqmr_shared
add_library(SUNDIALS::sunlinsolsptfqmr_shared SHARED IMPORTED)

set_target_properties(SUNDIALS::sunlinsolsptfqmr_shared PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
)

# Create imported target SUNDIALS::sunnonlinsolnewton_shared
add_library(SUNDIALS::sunnonlinsolnewton_shared SHARED IMPORTED)

set_target_properties(SUNDIALS::sunnonlinsolnewton_shared PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
)

# Create imported target SUNDIALS::sunnonlinsolfixedpoint_shared
add_library(SUNDIALS::sunnonlinsolfixedpoint_shared SHARED IMPORTED)

set_target_properties(SUNDIALS::sunnonlinsolfixedpoint_shared PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
)

# Create imported target SUNDIALS::arkode_shared
add_library(SUNDIALS::arkode_shared SHARED IMPORTED)

set_target_properties(SUNDIALS::arkode_shared PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
)

# Create imported target SUNDIALS::cvode_shared
add_library(SUNDIALS::cvode_shared SHARED IMPORTED)

set_target_properties(SUNDIALS::cvode_shared PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
)

# Create imported target SUNDIALS::cvodes_shared
add_library(SUNDIALS::cvodes_shared SHARED IMPORTED)

set_target_properties(SUNDIALS::cvodes_shared PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
)

# Create imported target SUNDIALS::ida_shared
add_library(SUNDIALS::ida_shared SHARED IMPORTED)

set_target_properties(SUNDIALS::ida_shared PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
)

# Create imported target SUNDIALS::idas_shared
add_library(SUNDIALS::idas_shared SHARED IMPORTED)

set_target_properties(SUNDIALS::idas_shared PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
)

# Create imported target SUNDIALS::kinsol_shared
add_library(SUNDIALS::kinsol_shared SHARED IMPORTED)

set_target_properties(SUNDIALS::kinsol_shared PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
)

if(CMAKE_VERSION VERSION_LESS 2.8.12)
  message(FATAL_ERROR "This file relies on consumers using CMake 2.8.12 or greater.")
endif()

# Load information for each installed configuration.
get_filename_component(_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
file(GLOB CONFIG_FILES "${_DIR}/SUNDIALSTargets-*.cmake")
foreach(f ${CONFIG_FILES})
  include(${f})
endforeach()

# Cleanup temporary variables.
set(_IMPORT_PREFIX)

# Loop over all imported files and verify that they actually exist
foreach(target ${_IMPORT_CHECK_TARGETS} )
  foreach(file ${_IMPORT_CHECK_FILES_FOR_${target}} )
    if(NOT EXISTS "${file}" )
      message(FATAL_ERROR "The imported target \"${target}\" references the file
   \"${file}\"
but this file does not exist.  Possible reasons include:
* The file was deleted, renamed, or moved to another location.
* An install or uninstall procedure did not complete successfully.
* The installation package was faulty and contained
   \"${CMAKE_CURRENT_LIST_FILE}\"
but not all the files it references.
")
    endif()
  endforeach()
  unset(_IMPORT_CHECK_FILES_FOR_${target})
endforeach()
unset(_IMPORT_CHECK_TARGETS)

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)