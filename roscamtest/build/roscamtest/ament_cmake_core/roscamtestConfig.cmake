# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_roscamtest_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED roscamtest_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(roscamtest_FOUND FALSE)
  elseif(NOT roscamtest_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(roscamtest_FOUND FALSE)
  endif()
  return()
endif()
set(_roscamtest_CONFIG_INCLUDED TRUE)

# output package information
if(NOT roscamtest_FIND_QUIETLY)
  message(STATUS "Found roscamtest: 0.0.0 (${roscamtest_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'roscamtest' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${roscamtest_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(roscamtest_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${roscamtest_DIR}/${_extra}")
endforeach()
