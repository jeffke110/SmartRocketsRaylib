/*******************************************************************************************
*
*   Smart Rockets - Jeffrey Kedda
*
*   Simple AI genetic algorithm for several rockets to reach the enemy spaceship.
*   After each round or generation, rockets pass on and crossover dna from the mating pool
*   that is created based on the distance and collision of the enemy spaceship for each rocket. 
*   In addition, each rocket must avoid the planet in the middle of the screen. Each rocket must
*   reach the enemy spaceship within a certain time limit.
*
*   
*
********************************************************************************************/

#include "Rockets.h"
#include "Stars.h"

const int screenWidth = 1200;
const int screenHeight = 800;

void setupWindow() {
    const int screenWidth = 1200;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Smart Rockets - Jeffrey Kedda");
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    SetWindowMinSize(screenWidth, screenHeight);
    SetTargetFPS(60);
}

int main(void)
{
    setupWindow();
    Random::Init();
    
    Texture2D spaceship = LoadTexture("resources/spaceship.png");
    Texture2D planet = LoadTexture("resources/planet.png");

    Stars stars = Stars();
    Rockets rockets = Rockets();

    int prevScreenWidth = screenWidth;
    int prevScreenHeight = screenHeight;

    while (!WindowShouldClose())        
    {
     
        BeginDrawing();
        ClearBackground(BLACK);

        stars.draw();
        rockets.draw();

        //draw spaceship and planet
        DrawTexture(planet, GetScreenWidth() / 2 - 50, GetScreenHeight() / 2 - 50, WHITE);
        DrawTexture(spaceship, GetScreenWidth() / 2 - 123/2, 50, WHITE);
        DrawRectangleLines(GetScreenWidth() / 2 - 123 / 2, 50, 123, 80, RED);

        EndDrawing();

        rockets.update();

        if (prevScreenWidth != GetScreenWidth() || prevScreenHeight != GetScreenHeight()) {
            stars = Stars();
            prevScreenWidth = GetScreenWidth();
            prevScreenHeight = GetScreenHeight();
        }


    }
    CloseWindow();      

    return 0;
}