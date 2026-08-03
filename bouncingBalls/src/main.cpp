#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory>

#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>
#include <imgui_stdlib.h>
#include <iostream>
#include <random>
#include <vector>

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

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float> dist(0, 1);

    Physics physics(1.0f);

    std::vector<std::shared_ptr<Ball>> balls;

    for (int i=0;i<20;i++) {
        float radius=25+dist(mt)*25;
        float x=dist(mt)*screenWidth;
        float y=dist(mt)*screenHeight;
        float vx=(dist(mt)*2-1)*100;
        float vy=(dist(mt)*2-1)*100;
        float mass=radius/50;
        auto ball = std::make_shared<Ball>(Vec2(x,y),Vec2(vx,vy),radius,mass,screenWidth,screenHeight);
        balls.push_back(ball);
    }

    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        Physics::deltaTime=GetFrameTime();

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            //use black background
            ClearBackground(BLACK);

            for (auto& ball : balls) {
                ball->move();
            }

            for (int i=0;i<balls.size();i++) {
                auto& a=balls[i];
                for (int j=i+1;j<balls.size();j++) {
                    auto& b=balls[j];
                    Contact c=physics.ballCollision(a,b);
                    physics.ballResolution(c);
                }
            }

            for (auto& ball : balls) {
                ball->draw();
            }

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

