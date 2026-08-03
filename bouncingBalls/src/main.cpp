#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory>

#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>
#include <imgui_stdlib.h>
#include <iostream>

#include "vec2.hpp"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

int main(void) 
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 900;
    const int screenHeight = 900;

    //initialize OpenGL window through raylib
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    InitWindow(screenWidth, screenHeight, "Minimal Project");
    //initialize ImGui support with raylib
    rlImGuiSetup(true);

    // Set our game to run at 60 frames-per-second
    SetTargetFPS(60);               

    //load the megaman texture using the relative path from the exe

    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            //use black background
            ClearBackground(BLACK);

            //draw fps at window pixel point (20,20)
            DrawFPS(20, 20);


            //********** ImGUI Content *********
            //Draw imgui stuff last so it is over the top of everything else
            rlImGuiBegin();

                //show ImGui Demo Content if you want to see it
                // bool open = true;
                // ImGui::ShowDemoWindow(&open);

            // end ImGui Content
            rlImGuiEnd();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

