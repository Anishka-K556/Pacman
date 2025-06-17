#include<raylib.h>
#include"globals.h"

void drawconfetti()
{   int fr=0;
    int gx,gy,yy,yx,px,py,by,bx;
    gx=GetRandomValue(1, 48);
    gy=GetRandomValue(1, 28);
    px=GetRandomValue(1, 48);
    py=GetRandomValue(1, 28);
    bx=GetRandomValue(1, 48);
    by=GetRandomValue(1, 28);
    yx=GetRandomValue(1, 48);
    yy=GetRandomValue(1, 28);
    if(fr<=20)
    {
    DrawCircle(yx*tileSize,yy*tileSize,10,YELLOW);
    DrawCircle(px*tileSize,py*tileSize,10,PINK);
    DrawCircle(gx*tileSize,gy*tileSize,10,GREEN);
    DrawCircle(bx*tileSize,by*tileSize,10,BLUE);
    fr++;
    }
    fr=0;

}

void ResetGame() {
    pacmanX = 1;
    pacmanY = 1;
    ghostrx = 48;
    ghostry = 1;
    ghostpx = 5;
    ghostpy = 22;
    ghostgx = 24;
    ghostgy = 13;
    superPelletExists = false;
    superPelletExists2 = false;
    ghostg = GREEN;
    pacmanColor = YELLOW;
    ghostr = RED;
    ghostp = PINK;
    score = 0;
    n = 3;
    ch = true;
    screen = true;
    gameover = false;
    introPlayed = false;
    pacman_exist = true;
    isPaused = false;
    count = 0;
    ghostConsumptionTimer = 0.0f;
    canConsumeGhosts = false;
    for (int y = 0; y < 28; y++) {
        for (int x = 0; x < 52; x++) {
            if (maze[y][x] != 1 && maze[y][x]!=0) {
                maze[y][x]=0;
            }
        }
    }
}

int main(void) {
    InitWindow(screenWidth, screenHeight, "Pacman Game");
    InitAudioDevice();

    Music backgroundMusic = LoadMusicStream("C:\\Users\\anush\\Downloads\\pacman background music.mp3");
    Music IntroMusic = LoadMusicStream("C:\\Users\\anush\\Downloads\\Pac-Man-Intro.mp3");
    Sound pelletSound = LoadSound("C:\\Users\\anush\\Downloads\\pellet.mp3");
    Sound superpelletSound = LoadSound("C:\\Users\\anush\\Downloads\\super pellet sound.mp3");
    Sound ghost_eaten = LoadSound("C:\\Users\\anush\\Downloads\\ghost_eaten.mp3");
    Sound pacman_eaten = LoadSound("C:\\Users\\anush\\Downloads\\pacman_eaten.mp3");
    SetMusicVolume(backgroundMusic, 1.0f);

    PlayMusicStream(backgroundMusic);
    SetTargetFPS(60);

    bool restartGame = false;

    Rectangle restartButton = {700,500,100, 40};
    Rectangle exitButton = {850,500,100, 40};
    const char *restartButtonText = "RESTART";
    const char *exitButtonText = "EXIT";

    while (!WindowShouldClose()) {
        if (restartGame) {
            ResetGame();
            restartGame = false;
        }

        if (screen) {
            instructions();
            if (!introPlayed) {
                PlayMusicStream(IntroMusic);
                introPlayed = true;
            }
            UpdateMusicStream(IntroMusic);
        } else if (gameover) {
            BeginDrawing();
            ClearBackground(BLACK);
            DrawText("GAME OVER", screenWidth / 2 - MeasureText("GAME OVER", 40) / 2, screenHeight / 2 - 50, 40, WHITE);
            DrawText(TextFormat(" YOUR SCORE: %d", score), screenWidth / 2 - 280 / 2, screenHeight / 2, 40, RAYWHITE);

            DrawRectangleRec(restartButton, GRAY);
            DrawText(restartButtonText, restartButton.x + 10, restartButton.y + 10, 15, WHITE);

            DrawRectangleRec(exitButton, GRAY);
            DrawText(exitButtonText, exitButton.x + 25, exitButton.y + 10, 20, WHITE);

            if(score>100 && pacmanX>48)
            {
                drawconfetti();
            }
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                if (CheckCollisionPointRec(GetMousePosition(), restartButton)) {
                    restartGame = true;
                    gameover = false;
                } else if (CheckCollisionPointRec(GetMousePosition(), exitButton)) {
                    break;
                }
            }
            EndDrawing();
        } else {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                pausegame();
            }
            if (!isPaused) {
                UpdateMusicStream(backgroundMusic);
                UpdatePacman(pelletSound, superpelletSound);
                moveGhost(&ghostry, &ghostrx);
                UpdateGhost(&ghostpx, &ghostpy, 1);
                GhostChasePacman(pacmanX, pacmanY, &ghostgx, &ghostgy);
                UpdateSuperPellet();
            }

            BeginDrawing();
            ClearBackground(BLACK);

            if (isPaused) {
                DrawText("PAUSED", screenWidth / 2 - MeasureText("PAUSED", 40) / 2, screenHeight / 2 - 20, 40, WHITE);
            } else {
                DrawMaze();
                if (score >= 5000 && n < 3 && ch) {
                    n += 1;
                    ch = false;
                }
                DrawPacman(pacmanX, pacmanY);
                Drawghost(ghostrx, ghostry, ghostr);
                Drawghost(ghostpx, ghostpy, ghostp);
                Drawghost(ghostgx, ghostgy, ghostg);
                DrawLives(n);
                GhostCollidePacman(pacman_eaten, ghost_eaten);

                if (superPelletExists && superPelletVisible) {
                    DrawCircle(superPelletX * tileSize + tileSize / 2, superPelletY * tileSize + tileSize / 2, 13, ORANGE);
                }

                if (ghostConsumptionTimer > 0.0f) {
                    ghostConsumptionTimer -= GetFrameTime();
                    if (ghostConsumptionTimer <= 0.0f) {
                        canConsumeGhosts = false;
                        superPelletExists2 = false;
                        ghostr = RED;
                        ghostp = PINK;
                        ghostg = GREEN;
                    }
                }
            }

            DrawButton(pauseButton, pauseButtonText);
            DrawText(TextFormat("Score: %d", score), 10, 10, 20, WHITE);

            EndDrawing();

            if (n == 0 || (score > 100 && pacmanX > 49)) {
                gameover = true;
            }
        }
    }

    UnloadMusicStream(backgroundMusic);
    UnloadMusicStream(IntroMusic);
    UnloadSound(pelletSound);
    UnloadSound(superpelletSound);
    UnloadSound(ghost_eaten);
    UnloadSound(pacman_eaten);
    CloseAudioDevice();

    CloseWindow();
    return 0;
}
