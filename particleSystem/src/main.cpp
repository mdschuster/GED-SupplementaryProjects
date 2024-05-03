#include <include/raylib.h>
#include <imgui/imgui.h>
#include <imgui/rlImGui.h>
#include <imgui/imgui_stdlib.h>
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include "vec2.hpp"
#include "particlesystem.hpp"
#include "profiler.hpp"


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    
    int screenWidth =1280;
    int screenHeight=720;

   
    // Initialization
    //--------------------------------------------------------------------------------------
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    InitWindow(screenWidth, screenHeight, "Steering");
    
    //initialize the raylib ImGui backend
    rlImGuiSetup(true);
    //increase ImGui item size to 2x
    ImGui::GetStyle().ScaleAllSizes(2);

    // Set raylib to target 60 frames-per-second (this does not mean it will actually RUN at 60 fps)
    SetTargetFPS(60);               

    // variables
    //--------------------------------------------------------------------------------------
    bool pause=false;
    bool attach=false;
    bool blue=false;
    bool red=true;
    bool green=false;
    std::string domColor="RED";
    ParticleSystem ps = ParticleSystem();
    ps.init({(float)screenWidth/2,(float)screenHeight/2},{(float)screenWidth,(float)screenHeight});
    

    // Main game loop
    //--------------------------------------------------------------------------------------
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if(!pause){
            if(blue) domColor="BLUE";
            if(red) domColor="RED";
            if(green) domColor="GREEN";
            if(attach){
                Vector2 mousePos=GetMousePosition();
                ps.position=Vec2(mousePos.x,mousePos.y);
            }
            ps.update(domColor);
        }


        if(GetKeyPressed()==KEY_SPACE) {
            pause=!pause;
        }


        // Draw
        //----------------------------------------------------------------------------------
        {
        PROFILE_SCOPE("All Drawing");
        BeginDrawing();
            ClearBackground(BLACK);

            //********** Raylib Drawing Content **********
            DrawFPS(10,10);
            ps.draw();

            //********** ImGUI Content *********
            
            //Draw imgui stuff last so it is over the top of everything else
            rlImGuiBegin();

                //sets the next window to be at this position
                //also uses the imgui.ini that gets created at first run
                ImGui::SetNextWindowSize(ImVec2(300, 250));
                //creates a new window
                ImGui::Begin("Particle System",NULL,ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoCollapse);
                ImGui::SeparatorText("PS Properties");
                if(ImGui::RadioButton("Blue",blue)){
                    blue=true;
                    red=false;
                    green=false;
                }
                ImGui::SameLine();
                if(ImGui::RadioButton("Red",red)){
                    blue=false;
                    red=true;
                    green=false;
                }
                ImGui::SameLine();
                if(ImGui::RadioButton("Green",green)){
                    blue=false;
                    red=false;
                    green=true;
                }
                ImGui::SeparatorText("PS Controls");
                ImGui::Checkbox("Attach To Mouse",&attach);
                if(ImGui::Button("Reset")){
                    ps.resetParticles();
                    ps.position=Vec2(screenWidth/2,screenHeight/2);
                }

                    
                ImGui::End();

            // end ImGui Content
            rlImGuiEnd();

        EndDrawing();
        }
        //----------------------------------------------------------------------------------
    }

    // Clean Up
    //--------------------------------------------------------------------------------------
    rlImGuiShutdown();    // Shuts down the raylib ImGui backend
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}


