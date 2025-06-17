#include<raylib.h>
#include"globals.h"

void DrawButton(Rectangle button,char* text) {
    DrawRectangleRec(button,BLACK);
    DrawText(text, button.x + 20, button.y + 10, 20, WHITE);
}

void pausegame() {
        Vector2 mousePoint = GetMousePosition();
        if (CheckCollisionPointRec(mousePoint, pauseButton)) {
            isPaused = !isPaused;
            if (isPaused) {
                strncpy(pauseButtonText, "Resume", sizeof(pauseButtonText) - 1);
                pauseButtonText[sizeof(pauseButtonText) - 1] = '\0';
            } else {
                strncpy(pauseButtonText, "Pause", sizeof(pauseButtonText) - 1);
                pauseButtonText[sizeof(pauseButtonText) - 1] = '\0';
            }
    }
}

