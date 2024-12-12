//
// Created by Jesus on 16/02/2023.
//

#ifndef EXAMPLES_SCENES_H
#define EXAMPLES_SCENES_H

#include "menu2.h"

#include <raylib.h>

typedef enum ScenesTypes {
    SCENE_MENU = 1,
    SCENE_BOARD,
    SCENE_OPTIONS,
} ScenesTypes;

class SceneHandler {
public:
    void *scene;
    ScenesTypes type;
};

SceneHandler *initSceneHandler(void);

void updateSceneHandler(SceneHandler *const handler);

void drawSceneHandler(const SceneHandler *const handler);

void freeScenehandler(SceneHandler **handler);


bool finishSceneHanlder(void);

#endif //EXAMPLES_SCENES_H
