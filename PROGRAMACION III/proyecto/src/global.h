#ifndef PONG_GLOBAL_H
#define PONG_GLOBAL_H

#include <raylib.h>
#include <stdint.h>
#include "vector"
#include "iostream"

#define MAP_WIDTH  1125
#define MAP_HEIGHT 1000
#define TILE_SIZE_WIDTH  9     //tamaño de cuadrado
#define TILE_SIZE_HEIGHT  8
#define MAZE_WIDTH 125
#define MAZE_HEIGHT 125


const static int32_t GL_MIN_PTO = 2;
const static int32_t GL_MAX_PTO = 10;



typedef enum GlMode {
    MODE_CPU = 0,
    MODE_PVP
} GlMode;

typedef enum GLMusic {
    MUSIC_1 = 0,
    MUSIC_2,
    MUSIC_3,
    MUSIC_4,
} GLMusic;

static GLMusic temas = MUSIC_1;



typedef enum OptionEvent {
    OPT_EMPTY = -1,
    OPT_START,
    OPT_OPTIONS,
    OPT_EXIT
} OptionEvent;

typedef struct GameObject {
    Vector2 position;
    Vector2 size;
    Vector2 velocity;
} GameObject;

typedef struct Colors {
    Color color0;
    Color color1;
    Color color2;
    Color color3;
} Colors;

typedef struct Global {
    GlMode mode;
    GLMusic theme;
    Colors colors;
    bool fullScreen;
    int32_t ptos;
    Sound leftSound;
    Sound rightSound;
    std::vector<Music> music;
    int map_widht;
    int map_height;
    int widht_window;
    int height_window;
    void resetMusic();
} Global;

Colors getPocketGB(void);
Colors getRusticGB(void);
Colors getMistGB(void);
Colors getCrimsonGB(void);

void initGlobal(Global *const globalData);
void freeGlobal(Global *const globalData);

#endif /* PONG_GLOBAL_H */
