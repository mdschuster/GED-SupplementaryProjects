# Game Engine Development: Supplementary Projects

## Purpose
This repository contains four separate C++ projects that are used to demonstrate concepts in the Game Engine Development course. Each project is self-contained and can be used, compiled, and executed independently. Except for the OpenGL project, each uses raylib (https://www.raylib.com/) for graphics and user input and Dear ImGui (https://github.com/ocornut/imgui) for their debug GUI. The four project are:

* `opengl` - Beginner OpenGL project that draws an orange triangle to a window created with GLFW. The project is based on content from "Learn OpenGL: Learn modern OpenGL graphics programming in a step-by-step fashion." by Joey De Vries.
* `particleSystem` - Demonstrates the creation of particle systems using a few simple classes. Since raylib batches draw calls within the library, the particle system is very performant.
* `shadertest` - Illustrates fragment shader usage when using raylib.
* `steering` - Shows several AI movement behaviors and is based on the seminal game AI book: "Artificial Intelligence for Games, 2nd Edition" by Ian Millington and John Funge.

## Usage

The root directory of the project contains a CMake project that will compile all four projects. In your IDE of choice, load the root CMakeLists and select the desired project.