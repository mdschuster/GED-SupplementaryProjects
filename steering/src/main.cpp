#include <include/raylib.h>
#include <imgui/imgui.h>
#include <imgui/rlImGui.h>
#include <imgui/imgui_stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <map>
#include "mover.hpp"
#include "kinematic.hpp"
#include "seek.hpp"
#include "flee.hpp"
#include "arrive.hpp"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    
    int screenWidth =1280;
    int screenHeight=720;

   
    // Initialization
    //--------------------------------------------------------------------------------------

    InitWindow(screenWidth, screenHeight, "Steering");
    
    //initialize the raylib ImGui backend
    rlImGuiSetup(true);
    //increase ImGui item size to 2x
    ImGui::GetStyle().ScaleAllSizes(2);

    // Set raylib to target 60 frames-per-second (this does not mean it will actually RUN at 60 fps)
    SetTargetFPS(60);               

    // Statelike variables
    //--------------------------------------------------------------------------------------

    bool drawShapes=true;
    bool simulate=true;
    bool drawText=true;
    int currentItem=0;
    auto target = std::make_shared<Kinematic>(Vec2(0.0f,0.0f),0.0f,Vec2(0.0f,0.0f),0.0f);
    auto behavior = std::make_shared<Seek>();
    Mover mover=Mover(behavior,target,Vec2(500,500));
    bool pause = false;
    bool arrive=true;

    // Main game loop
    //--------------------------------------------------------------------------------------
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        if(!pause){
            //mover.update();
            target->position.x=GetMouseX();
            target->position.y=GetMouseY();

            //update mover
            mover.update();
        }

        if(GetKeyPressed()==KEY_SPACE) {
            pause=!pause;
        }


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);

            //********** Raylib Drawing Content **********
            DrawCircle(target->position.x,target->position.y,10,GREEN);

            //draw the cricle (center x, center y, radius, color)
            DrawCircle(mover.kinematic->position.x,mover.kinematic->position.y,20,RED);


            //********** ImGUI Content *********
            
            //Draw imgui stuff last so it is over the top of everything else
            rlImGuiBegin();

                //sets the next window to be at this position
                //also uses the imgui.ini that gets created at first run
                ImGui::SetNextWindowSize(ImVec2(420, 350));
                //creates a new window
                ImGui::Begin("Steering Controls",NULL,ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoCollapse);
                ImGui::SeparatorText("Mover Properties");
                ImGui::SliderFloat("Max Speed",&(mover.behavior->maxSpeed),0.0f,1000.0f);
                ImGui::SliderFloat("Max Acceleration",&(mover.behavior->maxAcceleration),0.0f,2000.0f);
                if(mover.behavior->getType()=="ARRIVE"){
                    ImGui::SliderFloat("Target Radius",&(mover.behavior->targetRadius),0.0f,1000.0f);
                    ImGui::SliderFloat("Slow Radius",&(mover.behavior->slowRadius),0.0f,1000.0f);
                    ImGui::SliderFloat("Time To Target",&(mover.behavior->timeToTarget),0.0f,10.0f);
                }
                ImGui::SeparatorText("Steering Behaviors");
                if(ImGui::Button("Seek")){
                    mover.changeBehavior(std::make_shared<Seek>());
                }
                ImGui::SameLine();
                if(ImGui::Button("Flee")){
                    mover.changeBehavior(std::make_shared<Flee>());
                }
                ImGui::SameLine();
                if(ImGui::Button("Arrive")){
                    mover.changeBehavior(std::make_shared<Arrive>());
                }
                    
                ImGui::End();

            // end ImGui Content
            rlImGuiEnd();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // Clean Up
    //--------------------------------------------------------------------------------------
    rlImGuiShutdown();    // Shuts down the raylib ImGui backend
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}


