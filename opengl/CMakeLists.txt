cmake_minimum_required(VERSION 3.24)
include(FetchContent)

project(opengl)

set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED true)

#GLFW
#set(GLFW_INSTALL "OFF")
#set(GLFW_BUILD_EXAMPLES "OFF")
#set(GLFW_BUILD_TESTS "OFF")
#set(GLFW_BUILD_DOCS "OFF")
#add_subdirectory(external/glfw)
#set_target_properties(glfw PROPERTIES FOLDER "Dependencies")

# OpenGL
find_package(OpenGL REQUIRED)

#glad
add_subdirectory(external/glad)
set_target_properties(glad PROPERTIES FOLDER "Dependencies")

add_subdirectory(src)