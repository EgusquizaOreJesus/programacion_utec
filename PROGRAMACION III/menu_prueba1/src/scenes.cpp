#include "scenes.h"
#include "menu2.h"
#include "Options.h"
#include <stdlib.h>
#include "iostream"
#include "maze/maze2.h"

using namespace std;
// declaration static functions.
static bool finished = false;

static void loadScene(SceneHandler *handler, ScenesTypes type);
static Menu *loadMenuScene(void);
static Maze2*loadMazeScene(void);
static Options* loadBoardOptions(void);
static void unloadScene(SceneHandler *handler);
static void updateScene(SceneHandler *handler);
static void drawScene(const SceneHandler *const handler);


// implementation public functions.
SceneHandler *initSceneHandler(void) {
    /// RESERVANDO ESPACIO DE MEMORIA AL HANDLER
    finished = false;
    //SceneHandler *handler = static_cast<SceneHandler *>(malloc(sizeof(SceneHandler)));
    SceneHandler* handler = new SceneHandler;
    if (handler == NULL) {
        return NULL;
    }


    handler->scene = NULL;
    loadScene(handler, SCENE_MENU);
    return handler;
}

void updateSceneHandler(SceneHandler *const handler) {
    updateScene(handler);
}

void drawSceneHandler(const SceneHandler *const handler) {
    drawScene(handler);
}

void freeScenehandler(SceneHandler **handler) {
    if (*handler != NULL) {
        cout << "maze eliminado" << endl;
        unloadScene(*handler);
        free(*handler);
        handler = NULL;
#ifdef PONG_DEBUG
        TraceLog(LOG_INFO, PONG_SCENE_HANDLER_DELETED);
#endif
    }
}

bool finishSceneHanlder(void) {
    return finished;
}


// implementation static functions.
static void loadScene(SceneHandler *handler, ScenesTypes type) {
    unloadScene(handler);
    handler->type = type;
    switch (type) {
        case SCENE_MENU:
            handler->scene = loadMenuScene();
            break;
        case SCENE_BOARD:
            handler->scene = loadMazeScene();
            break;
        case SCENE_OPTIONS:
            handler->scene = loadBoardOptions();
    }
}

static Menu *loadMenuScene(void) {
    return initMenu();
}
static Maze2* loadMazeScene(void) {
    return initBoard();
}

static Options* loadBoardOptions(void) {
    return initOptions();
}

static void unloadScene(SceneHandler *handler) {
    switch (handler->type) {
        case SCENE_MENU:
            freeMenu((Menu **)&handler->scene);
            break;
        case SCENE_BOARD:
            freeMaze((Maze2** )&handler->scene);
            cout << "Maze cerrado";
            break;
        case SCENE_OPTIONS:
            freeOptions((Options **)&handler->scene);
            cout << "cerrar options";
    }
}

static void updateScene(SceneHandler *handler) {
    const OptionEvent event = finishMenu();
    switch (handler->type) {
        case SCENE_MENU:
            updateMenu((Menu *)handler->scene);
            if (event!= OPT_EMPTY) {
                if (event == OPT_START) {
                    loadScene(handler, SCENE_BOARD);
                } else if (event == OPT_OPTIONS) {
                    loadScene(handler, SCENE_OPTIONS);
                } else if (event == OPT_EXIT) {
                    finished = true;
                }
            }
            break;
        case SCENE_BOARD:
            updateMaze2((Maze2 *)handler->scene);
            if (finishMaze()) {
                loadScene(handler, SCENE_MENU);
            }
            break;
        case SCENE_OPTIONS:
            updateOptions((Options *)handler->scene);
            if (finishOptions()) {
                loadScene(handler, SCENE_MENU);
            }
    }
}

static void drawScene(const SceneHandler *const handler) {
    switch (handler->type) {
        case SCENE_MENU:
            drawMenu((Menu *)handler->scene);
            break;
        case SCENE_BOARD:
            drawMaze2((Maze2 *)handler->scene);
            break;
        case SCENE_OPTIONS:
            drawOptions((Options *)handler->scene);
    }
}
