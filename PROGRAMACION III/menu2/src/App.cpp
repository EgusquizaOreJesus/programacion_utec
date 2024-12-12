//
// Created by Jesus on 16/02/2023.
//

#include "App.h"
#include <stdlib.h>
#include "iostream"
static bool finished = false;
static bool showFPS = false;

static void settingApp(void);
static void updateFullScreen(void);
static void updateApp(App *const app);
static void drawApp(const App *const app);
static void freeInternalApp(App *app);
static void drawFPS(void);

Global globalData;

// FUNCIONES PUBLICAS
App *initApp(void) {
    finished = false;
    App* app = new App;
    if (app == NULL) {
        return NULL;
    }
    InitAudioDevice();
    initGlobal(&globalData);
    settingApp();
    SetWindowPosition(640,360);
    //app->sounds.push_back(sond2);
    app->sceneHandler = initSceneHandler();
    return app;
}

void runApp(App *const app) {
    std::cout << globalData.widht_window;
    std::cout << globalData.height_window;

    PlayMusicStream(globalData.music[globalData.theme]);
    while (!WindowShouldClose() && !finished) {
        UpdateMusicStream(globalData.music[globalData.theme]);
        updateApp(app);
        drawApp(app);
    }
    std::cout << "cerrado app" << std::endl;
}

void freeApp(App **app) {
    if (*app != NULL) {
        freeGlobal(&globalData);
        freeInternalApp(*app);
        free(*app);
        *app = NULL;
#ifdef PONG_DEBUG
        TraceLog(LOG_INFO, PONG_APP_DELETED);
#endif
    }
}


static void settingApp() {
    InitWindow(globalData.map_widht, globalData.map_height , "MAZE");
    HideCursor();
    Image iconKAWAI = LoadImage("../textures/icon_windowscompress.png");
    SetWindowIcon(iconKAWAI);
    SetExitKey(KEY_F8);
    SetTargetFPS(60);
}

static void updateApp(App *const app) {
    //updateFullScreen();
    updateSceneHandler(app->sceneHandler);
    finished = finishSceneHanlder();
}

static void drawApp(const App *const app) {
    BeginDrawing();
    ClearBackground(BLACK);
    drawSceneHandler(app->sceneHandler);
    //drawFPS();
    EndDrawing();
}

static void freeInternalApp(App *const app) {
    freeScenehandler(&app->sceneHandler);
    CloseAudioDevice();
    CloseWindow();
}

static void updateFullScreen(void) {
    if (globalData.fullScreen && !IsWindowFullscreen()) {
        ToggleFullscreen();
    } else if (!globalData.fullScreen && IsWindowFullscreen()) {
        ToggleFullscreen();
    }
}

static void drawFPS(void) {
    if (showFPS) {
        const char *strFPS = TextFormat("FPS: %d", GetFPS());
        RLAPI::DrawText(strFPS, 10, 10, 24, GREEN);
    }
}

