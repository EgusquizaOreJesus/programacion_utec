//
// Created by Jesus on 25/02/2023.
//
static bool finished = false;

#include "Game.h"
Game* initGame(){
    cout << "INICIALIZO GAME";
    resetValues();
    Game* juego = new Game;
    juego->maze2 = initBoard();
    auto Robot = Bot_Factory(*juego->maze2,DFS_BOT);
    juego->bot = Robot.Instanciar_Bot();
    juego->maze2->show = false;

    return juego;
}

void drawGame(Game *const game) {

    drawMaze2(game->maze2);
    if (game->maze2->show){
        game->bot->GeneralBehaivor();
        game->bot->BoT_move();
    }
}
static void resetValues(void) {
    finished = false;
}

void updateGAME(Game*const game){
    if (IsKeyPressed(KEY_ESCAPE)) {
        cout << "finalizo GAME";
        finished = true;
    }
}

bool finishGAME(void) {
    return finished;
}

void freeGame(Game **game){
    if (*game != NULL) {
        free(*game);
    }
}