#include "global.h"

Colors getPocketGB(void) {
    Colors colors = {0};
    colors.color0 = (Color){ 43, 43, 38, 255 };
    colors.color1 = (Color){ 112, 107, 102, 255 };
    colors.color2 = (Color){ 168, 159, 148, 255 };
    colors.color3 = (Color){ 224, 219, 205, 255 };
    return colors;
}

Colors getRusticGB(void) {
    Colors colors = {0};
    colors.color0 = (Color){ 44, 33, 55, 255 };
    colors.color1 = (Color){ 118, 68, 98, 255 };
    colors.color2 = (Color){ 169, 104, 104, 255 };
    colors.color3 = (Color){ 237, 180, 161, 255 };
    return colors;
}

Colors getMistGB(void) {
    Colors colors = {0};
    colors.color0 = (Color){ 45, 27, 0, 255 };
    colors.color1 = (Color){ 30, 96, 110, 255 };
    colors.color2 = (Color){ 90, 185, 168, 255 };
    colors.color3 = (Color){ 196, 240, 194, 255 };
    return colors;
}

Colors getCrimsonGB(void) {
    Colors colors = {0};
    colors.color0 = (Color){ 27, 3, 38, 255 };
    colors.color1 = (Color){ 122, 28, 75, 255 };
    colors.color2 = (Color){ 186, 80, 68, 255 };
    colors.color3 = (Color){ 239, 249, 214, 255 };
    return colors;
}

void initGlobal(Global *const globalData) {
    globalData->theme = THEME_POCKET_GB;
    globalData->mode = MODE_CPU;
    globalData->ptos = 5;
    globalData->fullScreen = false;
    globalData->leftSound = LoadSound("../assets/sound/left.wav");
    globalData->rightSound = LoadSound("../assets/sound/right.wav");
    globalData->resetMusic();
    globalData->map_height = 500;
    globalData->map_widht=420;
    globalData->height_window = GetMonitorPhysicalHeight(0);
    globalData->widht_window = GetMonitorPhysicalWidth(0);
    SetSoundVolume(globalData->leftSound, 1.0);
    SetSoundVolume(globalData->rightSound, 1.0);
}

void freeGlobal(Global *const globalData) {
    UnloadSound(globalData->leftSound);
    UnloadSound(globalData->rightSound);
}


void Global::resetMusic() {
    std::vector<Music> temp;
    Music sond1 = LoadMusicStream("../sounds/sound1.mp3");
    Music sond2 = LoadMusicStream("../sounds/sound2.mp3");
    Music sond3 = LoadMusicStream("../sounds/sound3.mp3");
    Music sond4 = LoadMusicStream("../sounds/sound4.mp3");
    temp.push_back(sond1);
    temp.push_back(sond2);
    temp.push_back(sond3);
    temp.push_back(sond4);
    music = temp;
}