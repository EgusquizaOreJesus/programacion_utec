//
// Created by Jesus on 16/02/2023.
//

#ifndef EXAMPLES_APP_H
#define EXAMPLES_APP_H

#include "scenes.h"
#include "vector"
class App {
public:
    SceneHandler *sceneHandler;
    std::vector<Music> sounds;
};

App *initApp(void);

void runApp(App *const app);
void soundtrack();
void initSoundtrack(std::vector<Music>& v);
void freeApp(App **app);

#endif //EXAMPLES_APP_H
