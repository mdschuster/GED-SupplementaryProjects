# Game Engine Development: Supplementary Projects

## Purpose
This repository contains four separate C++ projects that are used to demonstrate concepts in the Game Engine Development course. Each project is self-contained and can be used, compiled, and executed independently. Except for the OpenGL project, each uses raylib (https://www.raylib.com/) for graphics and user input and Dear ImGui (https://github.com/ocornut/imgui) for their debug GUI. The four project are:

* `opengl` - Beginner OpenGL project that draws an orange triangle to a window created with GLFW. The project is based on content from "Learn OpenGL: Learn modern OpenGL graphics programming in a step-by-step fashion." by John De Vries.
* `particleSystem` - Demonstrates the creation of particle systems using a few simple classes. Since raylib batches draw calls within the library, the particle system is very performant.
* `shadertest` - Illustrates fragment shader usage when using raylib.
* `steering` - Shows several AI movement behaviors and is based on the seminal game AI book: "Artificial Intelligence for Games, 2nd Edition" by Ian Millington and John Funge.

## Usage

Each project contains two ways to build the executable:

* A `makefile` intended for use with Mac and Linux
* A preconfigured Visual Studio project intended for use with Windows

### Notes:

All libraries are statically linked, so the project executables should be portable.

**For Windows**, the Visual Studio `sln` file is located in the `visualstudio` directory. The projects have been properly configured to include all required libraries to create a 64-bit executable, which will be placed in the `bin` directory.

**For Mac**, I have included raylib libraries for Arm, x86, and x86_64. The makefile will automatically determine the architecture and link as appropriate. The final executable will have a `.x` extension and be located in the `bin` directory.

**For Linux**, I have not included the appropriate static libraries. The GLFW and raylib libraries will need to be added and properly linked. Upon successful compilation, the final executable will have a `.x` extension and be located in the `bin` directory.
