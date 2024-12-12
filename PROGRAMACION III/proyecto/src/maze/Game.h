//
// Created by Jesus on 25/02/2023.
//

#ifndef EXAMPLES_GAME_H
#define EXAMPLES_GAME_H
#include "maze2.h"
#include "BotBorrador.h"

class Game {

public:
    Maze2* maze2;
    GeneralPurpuseBot* bot;
};
Game* initGame();
void drawGame(Game *const game);
static void resetValues(void);
bool finishGAME(void);
void updateGAME(Game*const game);
void freeGame(Game **game);
#endif //EXAMPLES_GAME_H
