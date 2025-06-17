#include<raylib.h>
#include"globals.h"

void instructions()
{
    Rectangle button = {600,500,200,50};
    BeginDrawing();
    ClearBackground(BLACK);
    DrawRectangleLines(200,150,1200,500,RAYWHITE);
    DrawText("WELCOME TO PACMAN GAME!", 500, 40, 35, GOLD);
    DrawText("*Use the arrow keys to move Pacman", 400, 200, 30, SKYBLUE);
    DrawText("*Eat the pellets to gain score", 400, 250, 30, SKYBLUE);
    DrawText("*Escape from the ghosts...They will cost you a life", 400, 300, 30, SKYBLUE);
    DrawText("*Press the start button to enter the game", 400, 350, 30, SKYBLUE);
    DrawText("*After consuming all the pellets exit by the doorway", 400, 400, 30, SKYBLUE);
    DrawRectangleRec(button , LIGHTGRAY);
    int textWidth = MeasureText("START", 20);
    int textX = button.x + (button.width - textWidth) / 2;
    int textY = button.y + (button.height - 20) / 2;
    DrawText("START", textX, textY, 20, BLACK);
    EndDrawing();
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 mousePoint = GetMousePosition();
        if (CheckCollisionPointRec(mousePoint, button))
        {
            screen = false;
        }
    }
}
