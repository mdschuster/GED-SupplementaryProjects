#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../include/raylib.h"


#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600

#define GLSL_VERSION  330

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void) 
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = SCREEN_WIDTH;
    const int screenHeight = SCREEN_HEIGHT;

    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    InitWindow(screenWidth, screenHeight, "Shader Test");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    Shader shader=LoadShader(0,TextFormat("assets/shaders/testShader.fs",GLSL_VERSION));
    Texture2D tex =  LoadTexture("assets/megaStand.png");
    
    
    int timeLoc=GetShaderLocation(shader,"time");
                                    
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        float time=GetTime();
        SetShaderValue(shader,timeLoc,&time,SHADER_UNIFORM_FLOAT);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(BLACK);


            BeginShaderMode(shader);
                DrawTexturePro(tex, {0,0,(float)tex.width,(float)tex.height}, {(float)screenWidth/2,(float)screenHeight/2,(float)tex.width*4,(float)tex.height*4}, {(float)tex.width/2*4,(float)tex.height/2*4}, 0, WHITE);
            EndShaderMode();

            DrawFPS(20, 20);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadShader(shader);
    UnloadTexture(tex);
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

