//
// Created by Jesus on 15/02/2023.
//

#ifndef EXAMPLES_MENU2_H
#define EXAMPLES_MENU2_H

#include "global.h"

class Menu {
public:
    OptionEvent option;
};

Menu *initMenu(void);

void updateMenu(Menu *const menu);

void drawMenu(const Menu *const menu);

void freeMenu(Menu **menu);

OptionEvent finishMenu(void);
// funciones

/*
static void start(){
        InitAudioDevice();  //Inicializo
        Music sond2 = LoadMusicStream("../sounds/sound2.mp3");
        //Music bochigod2 = LoadMusicStream("../sounds/BOCCHIGOD.mp3");

        InitWindow(480, 360, "MAZE");
        Image waifuI = LoadImage("../textures/loli.png");
        Texture2D waifu = LoadTextureFromImage(waifuI);  // Upload CPU (RAM) image to GPU (VRAM)
        UnloadImage(waifuI);
        PlayMusicStream(sond2);
        SetExitKey(KEY_F8);
        while (!WindowShouldClose() && !finished_main) {
            UpdateMusicStream(sond2);
            BeginDrawing();
            ClearBackground(BLACK);
            DrawTexture(waifu, 800, -30, WHITE);
            drawTitle();
            updateMenu();
            drawMenuOptions();
            EndDrawing();

        }
        UnloadMusicStream(sond2);   // Unload music stream buffers from RAM
        UnloadTexture(waifu);    // Texture unloading
        CloseWindow();
    }
 */





// CREO EL ESPACIO DE MEMORIA DE MENU




/*
class menu {
    inline static OptionEvent option;
    inline static vector<Music> a;

public:
    static void start(){
        InitAudioDevice();  //Inicializo
        Music sond2 = LoadMusicStream("../sounds/sound2.mp3");
        //Music bochigod2 = LoadMusicStream("../sounds/BOCCHIGOD.mp3");

        InitWindow(480, 360, "MAZE");
        Image waifuI = LoadImage("../textures/loli.png");
        Texture2D waifu = LoadTextureFromImage(waifuI);  // Upload CPU (RAM) image to GPU (VRAM)
        UnloadImage(waifuI);
        PlayMusicStream(sond2);
        SetExitKey(KEY_F8);
        while (!WindowShouldClose() && !finished_main) {
            UpdateMusicStream(sond2);
            BeginDrawing();
            ClearBackground(BLACK);
            DrawTexture(waifu, 800, -30, WHITE);
            drawTitle();
            updateMenu();
            drawMenuOptions();
            EndDrawing();

        }
        UnloadMusicStream(sond2);   // Unload music stream buffers from RAM
        UnloadTexture(waifu);    // Texture unloading
        CloseWindow();
    }
    static void drawTitle() {
        const int32_t fontSize = 128;
        const int32_t middle = GetScreenWidth() / 2;
        const int32_t titleLen = MeasureText("MAZE", fontSize);
        const int32_t posX = middle - titleLen / 2;
        const int32_t posYBase = 20;
        const int32_t posY = 30;
        const int32_t height = 15;
        DrawRectangle(posX, posYBase + 20, titleLen, height, (Color){ 168, 159, 148, 255 });
        DrawText("MAZE", posX, posYBase + posY, fontSize, (Color){ 112, 107, 102, 255 });
        DrawRectangle(posX, posYBase + fontSize + 10, titleLen, height, (Color){ 168, 159, 148, 255 });
    }
    static void drawMenuOptions(){
        const int32_t middleWidth = GetScreenWidth() / 2;
        const int32_t middleHeight = GetScreenHeight() / 2;
        const int32_t fontSize = 24;
        const int32_t posY = middleHeight + 45;
        const int32_t posXStart = middleWidth - MeasureText("START", fontSize) / 2;
        const int32_t posXOptions = middleWidth - MeasureText("OPTIONS", fontSize) / 2;
        const int32_t posXExit = middleWidth - MeasureText("EXIT", fontSize) / 2;

        const Color startColor = (option == OPT_START) ? (Color){ 224, 219, 205, 255 } : (Color){ 112, 107, 102, 255 };
        const Color optionsColor = (option == OPT_OPTIONS) ? (Color){ 224, 219, 205, 255 } : (Color){ 112, 107, 102, 255 };
        const Color endColor = (option == OPT_EXIT) ? (Color){ 224, 219, 205, 255 } : (Color){ 112, 107, 102, 255 };

        DrawText("START", posXStart, posY, fontSize, startColor);
        DrawText("OPTIONS", posXOptions, posY + fontSize + 5, fontSize, optionsColor);
        DrawText("EXIT", posXExit, posY + (fontSize * 2) + 10, fontSize, endColor);
    }

    static void updateMenu() {
        updateMenuOptions();
        if (IsKeyPressed(KEY_ENTER)) {
            if (option == OPT_START) {
                onOptionEvent = OPT_START;
            }
            else if (option == OPT_OPTIONS) {
                onOptionEvent = OPT_OPTIONS;
                Option::Start();
            }
            else if (option == OPT_EXIT) {
                onOptionEvent = OPT_EXIT;
                finished_main = true;
            }
        }
    }
    static void updateMenuOptions() {
        const auto min = (int32_t) OPT_START;
        const auto max = (int32_t) OPT_EXIT;
        if (IsKeyPressed(KEY_UP)) {
            const int32_t value = option - 1;
            if (value >= min) {
                option = static_cast<OptionEvent>(option - 1);
            } else {
                option = OPT_EXIT;
            }
        } else if (IsKeyPressed(KEY_DOWN)) {
            const int32_t value = option + 1;
            if (value <= max) {
                option = static_cast<OptionEvent>(option + 1);
            } else {
                option = OPT_START;
            }
        }
    }
};
 */


#endif //EXAMPLES_MENU2_H
