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
#include "ball.hpp"
#include "physics.hpp"

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

    Physics physics(1.0f);

    auto ballA=std::make_shared<Ball>(Vec2(200,200),25.0f,1.0f);
    auto ballB=std::make_shared<Ball>(Vec2(100,100),25.0f,1.0f);

    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            Physics::deltaTime=GetFrameTime();
            //use black background
            ClearBackground(BLACK);

            ballA->move();
            ballB->move();
            ballA->draw();
            ballB->draw();

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

