cmake_minimum_required(VERSION 3.10)

project(shader)

set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})


#
# Dependencies
#


# Projects
#
add_subdirectory(src)