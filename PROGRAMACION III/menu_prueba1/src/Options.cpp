#include "Options.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "iostream"

extern Global globalData;

using namespace std;
#define PONG_THEME_POCKET_GB "Megalovania "
#define PONG_THEME_RUSTIC_GB "MusumeOST 1"
#define PONG_THEME_MIST_GB "MusumeOST 2"
#define PONG_THEME_CRIMSON_GB "Bad Apple"

static bool finished = false;
static const int32_t FONTSIZE = 24;
static int32_t internalPto = 0;
static GlTheme internalTheme = static_cast<GlTheme>(-1);
static GlMode internalMode = static_cast<GlMode>(-1);

static void resetValue(void);
static void drawTitle(void);
//static void drawOptionPtos(const Options *const options, const int32_t posY);
static void drawOptionTheme(const Options *const options, const int32_t posY);
//static void drawOptionGameMode(const Options *const options, const int32_t posY);
//static void drawOptionFullScreen(const Options *const options, const int32_t posY);
//static void updateItemSelected(Options *const options);
static void closeOptions(void);
//static void changeValueItem(Options *const options);
//static void changePtos(void);
//static void updatePtos(void);
//static void initPtos(void);
//static void freePtos(void);
static void initTheme(void);
static void freeTheme(void);
static void updateTheme( Options *const options);
static void updateThemeData();
//static void updateMode(const Options *const options);
//static void updateModeData(void);
//static void initGameMode(void);
//static void freeGameMode(void);
//static void updateFullScreen(const Options *const options);

static char *ptoData = NULL;
static char *themeData = NULL;
static char *modeData = NULL;

const static char *LEFT = "< ";
const static char *RIGHT = " >";
const static int32_t DIFF_LEFT = 60;
const static int32_t DIFF_RIGHT = 60;

Options *initOptions(void) {
    cout << "iniciando options" << endl;
    resetValue();
    //Options *options = static_cast<Options *>(malloc(sizeof(Options)));
    Options* options = new Options;
    if (options == NULL) {
        return NULL;
    }

    //initPtos();
    initTheme();
    //initGameMode();

    options->item = ITEM_THEME;

    return options;
}

void updateOptions(Options *const options) {
    //updateItemSelected(options);
    //changeValueItem(options);
    updateTheme(options);
    updateThemeData();
    //updateMode(options);
    //updateModeData();
    //updateFullScreen(options);
    closeOptions();
}
bool finishOptions(void) {
    return finished;
}
void drawOptions(const Options *const options) {
    int32_t posY = 100;
    drawTitle();
    //drawOptionPtos(options, posY);
    posY += FONTSIZE + 10;
    drawOptionTheme(options, posY);
    posY += FONTSIZE + 10;
    //drawOptionGameMode(options, posY);
    posY += FONTSIZE + 10;
    //drawOptionFullScreen(options, posY);
}

void freeOptions(Options **options) {
    if (*options != NULL) {
        //freePtos();
        freeTheme();
        //freeGameMode();
        free(*options);
        *options = NULL;
#ifdef PONG_DEBUG
        TraceLog(LOG_INFO, PONG_SCENE_OPTIONS_DELETED);
#endif
    }
}
/*


bool finishOptions(void) {
    return finished;
}

 */

static void resetValue(void) {
    finished = false;
}

static void drawTitle(void) {
    const int32_t middle = GetScreenWidth() / 2;
    const int32_t posX = middle - TextLength("Options") * (FONTSIZE / 2) / 2;

    DrawText("Options", posX, 10, FONTSIZE,  (Color){ 168, 159, 148, 255 });
}



static void drawOptionTheme(const Options *const options, const int32_t posY) {
    Color selected = options->item == ITEM_THEME ? (Color){ 224, 219, 205, 255 } : (Color){ 112, 107, 102, 255 };;
    DrawText("Theme:", DIFF_LEFT, posY, FONTSIZE, selected);
    DrawText(themeData, GetScreenWidth() - MeasureText(themeData, FONTSIZE) - DIFF_RIGHT, posY, FONTSIZE, selected);
}

static void drawOptionGameMode(const Options *const options, const int32_t posY) {
    Color selected = options->item == ITEM_GAME_MODE ? (Color){ 224, 219, 205, 255 } : (Color){ 112, 107, 102, 255 };;
    DrawText("GAME MODE:", DIFF_LEFT, posY, FONTSIZE, selected);
    DrawText(modeData, GetScreenWidth() - MeasureText(modeData, FONTSIZE) - DIFF_RIGHT, posY, FONTSIZE, selected);
}



static void closeOptions(void) {
    if (IsKeyPressed(KEY_ESCAPE)) {
        if (!IsMusicStreamPlaying(globalData.music[internalTheme])){
            UnloadMusicStream(globalData.music[globalData.theme]);
            globalData.theme = internalTheme;
            globalData.resetMusic();
            PlayMusicStream(globalData.music[globalData.theme]);
        }
        finished = true;
    }
}

static void initTheme(void) {
    const int32_t size = 20;
    //themeData = static_cast<char *>(malloc(sizeof(char) * size));
    themeData = new char[size];
    themeData[size - 1] = '\0';
}
static void freeTheme(void) {
    free(themeData);
    themeData = NULL;
    internalTheme = static_cast<GlTheme>(-1);
#ifdef PONG_DEBUG
    TraceLog(LOG_INFO, "->\t deleted themeData.");
#endif
}

static void initGameMode(void) {
    const int32_t size = 4;
    //modeData = static_cast<char *>(malloc(sizeof(char) * size));
    modeData = new char[size];
    modeData[size - 1] = '\0';
}

static void freeGameMode(void) {
    free(modeData);
    modeData = NULL;
    internalMode = static_cast<GlMode>(-1);
#ifdef PONG_DEBUG
    TraceLog(LOG_INFO, "->\t deleted modeData.");
#endif
}

static void updateTheme(Options *const options) {
    if (options->item == ITEM_THEME) {
        const int32_t minTheme = (int32_t) THEME_POCKET_GB;
        const int32_t maxTheme = (int32_t) THEME_CRIMSON_GB;
        const int32_t theme = (int32_t) temas;
        if (IsKeyPressed(KEY_LEFT) && theme > minTheme) {
            temas = static_cast<GlTheme>(temas - 1);
        } else if (IsKeyPressed(KEY_RIGHT) && theme < maxTheme) {
            temas = static_cast<GlTheme>(temas + 1);
        }
    }
}

static void updateThemeData() {
    if (internalTheme != temas ) {
        internalTheme = temas;
        cout << (int32_t)internalTheme;
        const int32_t minTheme = (int32_t) THEME_POCKET_GB;
        const int32_t maxTheme = (int32_t) THEME_CRIMSON_GB;

        strcpy(themeData, "");
        if ((int32_t)internalTheme > minTheme) {
            strcat(themeData, LEFT);
        }

        switch (internalTheme) {
            case THEME_POCKET_GB:
                strcat(themeData, PONG_THEME_POCKET_GB);
                cout << &GetCurrentMonitor;
                SetWindowSize(480,360);
                break;
            case THEME_RUSTIC_GB:
                strcat(themeData, PONG_THEME_RUSTIC_GB);
                SetWindowSize(1200,720);
                break;
            case THEME_MIST_GB:
                SetWindowSize(1000,500);
                strcat(themeData, PONG_THEME_MIST_GB);
                break;
            case THEME_CRIMSON_GB:
                SetWindowSize(800,600);

                strcat(themeData, PONG_THEME_CRIMSON_GB);
                break;
        }

        if ((int32_t)internalTheme < maxTheme) {
            strcat(themeData, RIGHT);
        }
    }
}
/*
static void updateMode(const Options *const options) {
    if (options->item == ITEM_GAME_MODE) {
        const int32_t mode = (int32_t)globalData.mode;
        if (IsKeyPressed(KEY_LEFT) && mode == MODE_PVP) {
            PlaySound(globalData.rightSound);
            globalData.mode = MODE_CPU;
        } else if (IsKeyPressed(KEY_RIGHT) && mode == MODE_CPU) {
            PlaySound(globalData.rightSound);
            globalData.mode = MODE_PVP;
        }
    }
}


static void updateModeData(void) {
    if (internalMode != globalData.mode) {
        internalMode = globalData.mode;
        strcpy(modeData, "");
        switch (internalMode) {
            case MODE_CPU:
                strcat(modeData, PONG_OPTION_GAME_MODE_CPU);
                strcat(modeData, RIGHT);
                break;
            case MODE_PVP:
                strcat(modeData, LEFT);
                strcat(modeData, PONG_OPTION_GAME_MODE_PVP);
                break;
        }
    }
}
 */

