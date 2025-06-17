#include<raylib.h>
#include"globals.h"

void DrawMaze() {
    for (int y = 0; y < 28; y++) {
        for (int x = 0; x < 52; x++) {
            if (maze[y][x] == 1) {
                DrawRectangle(x * tileSize, y * tileSize, tileSize, tileSize, BLUE);
            } else if (maze[y][x] == 0 && pelletExists) {
                DrawCircle(x * tileSize + tileSize / 2, y * tileSize + tileSize / 2, 5, ORANGE);
            }
        }
    }
}

void DrawLives(int n)
{
    int i;
    DrawText(TextFormat("LIVES:"),300,10,25,RAYWHITE);
    for(i=0;i<n;i++)
    {   DrawCircle(400+i*30,20,10,YELLOW);
    }
}

void UpdateSuperPellet() {
    if (superPelletExists) {
        blinkTimer += GetFrameTime();
        if (blinkTimer >= blinkInterval) {
            superPelletVisible = !superPelletVisible;
            blinkTimer = 0.0f;
        }
    }
}

