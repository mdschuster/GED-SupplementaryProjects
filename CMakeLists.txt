cmake_minimum_required(VERSION 3.10)
project(SupplementaryProjects)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

#libraries
add_subdirectory(external/raylib)
add_subdirectory(external/imgui)

# Add each sub-project folder
add_subdirectory(opengl)
add_subdirectory(particleSystem)
add_subdirectory(shadertest)
add_subdirectory(steering)