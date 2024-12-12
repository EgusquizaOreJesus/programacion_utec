/*******************************************************************************************
*
*   raylib [textures] example - Load textures from raw data
*
*   NOTE: Images are loaded in CPU memory (RAM); textures are loaded in GPU memory (VRAM)
*
*   Example originally created with raylib 1.3, last time updated with raylib 3.5
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2015-2023 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <raylib.h>
#include <stdlib.h>
#include "src/app.h"
#include "src/maze/laberinto.h"

/*
    App *app = initApp();
    if (app == NULL) {
        return 1;
    }
    runApp(app);
    freeApp(&app);

    return 0;
 */
/*
srand(time(nullptr));
    Laberinto A;
    backtraking(A);
    InitWindow(MAP_WIDTH, MAP_HEIGHT, "Marisa");
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        for (int x = 0; x < MAZE_HEIGHT; x++) {
            for (int y = 0; y < MAZE_WIDTH; y++) {
                if (A(y,x) != 1 and A(y,x) != 2 and A(y,x)!=3) {
                    DrawRectangle(float(x*TILE_SIZE_WIDTH),float(y * TILE_SIZE_HEIGHT),TILE_SIZE_WIDTH, TILE_SIZE_HEIGHT,WHITE);
                }
            }
        }
        EndDrawing();
    }
 */

int main() {
    App *app = initApp();
    if (app == NULL) {
        return 1;
    }
    runApp(app);
    freeApp(&app);

    return 0;
}
