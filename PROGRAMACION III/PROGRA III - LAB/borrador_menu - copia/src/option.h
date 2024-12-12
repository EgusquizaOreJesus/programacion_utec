/*
//
// Created by Jesus on 15/02/2023.
//

#ifndef EXAMPLES_OPTION_H
#define EXAMPLES_OPTION_H
#include "raylib.h"
#include <stdlib.h>
#include <stdint.h>
#include "string.h"
#include "iostream"
#include "global.h"
#include "vector"
using namespace std;

#define PONG_THEME_POCKET_GB "BochiGD"
#define PONG_THEME_RUSTIC_GB "RapGodd"
#define PONG_THEME_MIST_GB "OST-Myhero"
#define PONG_THEME_CRIMSON_GB "Clannad"

static bool finished_option = false;
const static char *LEFT = "< ";
const static char *RIGHT = " >";
const static int32_t DIFF_LEFT = 60;
const static int32_t DIFF_RIGHT = 60;
static const int32_t FONTSIZE = 24;
typedef enum OptionItems {
    ITEM_PTOS = 0,
    ITEM_THEME,
    ITEM_GAME_MODE,
    ITEM_FULLSCREEN,
} OptionItems;

class Option {
    inline static OptionItems item;
    inline static GlTheme temas;
    inline static GlTheme internalTheme = static_cast<GlTheme>(-1);

    inline static char *themeData = NULL;

public:
    static void Start(){
        initTheme();
        cout << temas;
        while (!WindowShouldClose() && !finished_option) {
            BeginDrawing();
            updateTheme();
            updateThemeData();
            drawOptionTheme(100);

            closeOptions();
            EndDrawing();
        }
        cout<<"hla";

    }
    static void closeOptions() {
        if (IsKeyPressed(KEY_ESCAPE)) {
            finished_option = true;
        }
    }

    static void drawOptionTheme(const int32_t posY) {

        Color selected = (item == ITEM_THEME) ? (Color){ 224, 219, 205, 255 } : (Color){ 112, 107, 102, 255 };
        DrawText("THEME:", DIFF_LEFT, posY, FONTSIZE, selected);
        DrawText(themeData, GetScreenWidth() - MeasureText(themeData, FONTSIZE) - DIFF_RIGHT, posY, FONTSIZE, selected);
    }
    static void updateTheme() {
        if (item == ITEM_THEME) {
            const int32_t minTheme = (int32_t) THEME_POCKET_GB;
            const int32_t maxTheme = (int32_t) THEME_CRIMSON_GB;
            const int32_t theme = (int32_t) temas;
            if (IsKeyPressed(KEY_LEFT) && theme > minTheme) {
                temas = static_cast<GlTheme>(temas - 1);
                cout << temas;
            } else if (IsKeyPressed(KEY_RIGHT) && theme < maxTheme) {
                temas = static_cast<GlTheme>(temas + 1);
            }
        }
    }
    static void updateThemeData(void) {
        if (internalTheme != temas) {
            cout << "hola";
            internalTheme = temas;
            const int32_t minTheme = (int32_t) THEME_POCKET_GB;
            const int32_t maxTheme = (int32_t) THEME_CRIMSON_GB;

            strcpy(themeData, "");
            if ((int32_t)internalTheme > minTheme) {
                strcat(themeData, LEFT);
            }

            switch (internalTheme) {
                case THEME_POCKET_GB:
                    strcat(themeData, PONG_THEME_POCKET_GB);
                    break;
                case THEME_RUSTIC_GB:
                    strcat(themeData, PONG_THEME_RUSTIC_GB);
                    break;
                case THEME_MIST_GB:
                    strcat(themeData, PONG_THEME_MIST_GB);
                    break;
                case THEME_CRIMSON_GB:
                    strcat(themeData, PONG_THEME_CRIMSON_GB);
                    break;
            }

            if ((int32_t)internalTheme < maxTheme) {
                strcat(themeData, RIGHT);
            }
        }
    }
    static void initTheme() {
        const int32_t size = 20;
        themeData = static_cast<char *>(malloc(sizeof(char) * size));
        themeData[size - 1] = '\0';
    }
    static Music music(vector<Music>& songs) {
        return songs[temas];
    }

};


#endif //EXAMPLES_OPTION_H
 */