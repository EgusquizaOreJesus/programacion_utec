//
// Created by Jesus on 25/02/2023.
//
static bool finished = false;
using namespace std;
#include "Game.h"
Game* initGame(){
    cout << "INICIALIZO GAME";
    resetValues();
    Game* juego = new Game;
    juego->maze2 = initBoard();
    cout << globalData.dificultad << endl;
    auto Robot = Bot_Factory(*juego->maze2,globalData);
    juego->bot = Robot.Instanciar_Bot();
    juego->maze2->show = false;

    return juego;
}

void Game::DRAWGAME() {
    drawMaze2(maze2);
    if (maze2->show){
        bot->GeneralBehaivor();
        bot->BoT_move();
    }
}

static void resetValues() {
    finished = false;
}


void Game::updateGAMES() {
    if (IsKeyPressed(KEY_ESCAPE)) {
        cout << "finalizo GAME";
        finished = true;
    }
}

bool finishGAME(void) {
    return finished;
}

void freeGame2(Game *game){
    if (game != NULL) {
        free(game->bot);
        free(game);
    }
}

