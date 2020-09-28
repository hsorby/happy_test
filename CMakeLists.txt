
cmake_minimum_required(VERSION 3.10.2)

project(HappyTest LANGUAGES CXX)

if(POLICY CMP0078)
  cmake_policy(SET CMP0078 NEW)
endif()
if(POLICY CMP0086)
  cmake_policy(SET CMP0086 NEW)
endif()

set(CMAKE_CXX_STANDARD 17)

add_library(libhappy happy.cpp happy.h projecttypes.h)

target_include_directories(libhappy
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

find_package(Python COMPONENTS Interpreter Development)

find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})

set(PYTHON_PACKAGE_NAME charles)
set(SWIG_INTERFACE_SRCS projecttypes.i happy.i)

foreach(SWIG_INTERFACE_SRC ${SWIG_INTERFACE_SRCS})

  set_source_files_properties(${SWIG_INTERFACE_SRC} PROPERTIES
    CPLUSPLUS ON
    INCLUDE_DIRECTORIES "${PROJECT_SOURCE_DIR}"
  )

  get_filename_component(MODULE_TARGET ${SWIG_INTERFACE_SRC} NAME_WE)

  swig_add_library(${MODULE_TARGET}
    LANGUAGE python
    OUTPUT_DIR ${PYTHON_PACKAGE_NAME}
    OUTFILE_DIR swig_int
    SOURCES ${SWIG_INTERFACE_SRC}
  )

  target_link_libraries(${MODULE_TARGET} Python::Python libhappy)

  set_target_properties(${MODULE_TARGET} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PYTHON_PACKAGE_NAME}
    LIBRARY_OUTPUT_DIRECTORY ${PYTHON_PACKAGE_NAME}
  )

endforeach()
