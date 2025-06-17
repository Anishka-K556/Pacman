#include<raylib.h>
#include<time.h>
#include"globals.h"

void DrawPacman(int x, int y) {
    static bool opening = true;
    static float timer = 0.0f;
    float delay = 0.3f;
    int segments=20;
    timer+=GetFrameTime();
    if(timer>=delay)
    {
        timer=0.0f;
        opening=!opening;
    }
    if(pacman_exist)
    {
    DrawCircle(x*tileSize+tileSize/2,y*tileSize+tileSize/2,15,pacmanColor);
    DrawCircleSector((Vector2){x * tileSize + tileSize / 2, y * tileSize + tileSize / 2}, 15, startangle,opening?endangle:startangle, 15, BLACK);
    }

}

void UpdatePacman(Sound pelletSound,Sound superpelletSound)
{
    static int frameCounter = 0;
    static int moveSpeed = 5;

    if (frameCounter >= moveSpeed) {

        if (IsKeyDown(KEY_RIGHT) && maze[pacmanY][pacmanX + 1] != 1)
        {
            pacmanX++;
            startangle=-45;
            endangle=45;
        }
        if (IsKeyDown(KEY_LEFT) && maze[pacmanY][pacmanX - 1] != 1)
        {
            pacmanX--;
            startangle=135;
            endangle=225;
        }
        if (IsKeyDown(KEY_UP) && maze[pacmanY - 1][pacmanX] != 1)
        {
            pacmanY--;
            startangle=225;
            endangle=315;
        }
        if (IsKeyDown(KEY_DOWN) && maze[pacmanY + 1][pacmanX] != 1)
        {
            pacmanY++;
            startangle=45;
            endangle=135;
        }


        if (maze[pacmanY][pacmanX] == 0) {
            maze[pacmanY][pacmanX] = 2;
            score++;
            PlaySound(pelletSound);
            if (score >= 50 && !superPelletExists)
            {
                srand(time(NULL));
                superPelletX = rand() % 50;
                superPelletY = rand() % 20;
                while (maze[superPelletY][superPelletX] != 0)
                {
                    superPelletX = rand() % 50;
                    superPelletY = rand() % 20;
                }
                    superPelletExists = true;
            }


           if (superPelletExists && pacmanX == superPelletX && pacmanY == superPelletY)
            {
                superpelletcount++;
                superPelletExists = false;
                score+=4;
                PlaySound(superpelletSound);
                if(superpelletcount==5)
                {
                    superPelletExists2=true;
                    ghostr=BLUE;
                    ghostp=BLUE;
                    ghostg=BLUE;
                    canConsumeGhosts=true;
                    ghostConsumptionTimer=10.0f;
                    superpelletcount=0;
                }
            }
        }


        frameCounter = 0;
    }
    else {
        frameCounter++;
    }
}

