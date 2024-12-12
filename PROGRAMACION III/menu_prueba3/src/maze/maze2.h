//
// Created by Jesus on 16/02/2023.
//

#ifndef EXAMPLES_MAZE2_H
#define EXAMPLES_MAZE2_H
#include <iostream>
#include <stack>
#include <raylib.h>
#include "algorithm"
#include <vector>
#include "Bot.h"
#include <raylib.h>
#include "../global.h"

//using Pi = std::pair<int,int>;
using I = int;

class Maze2 {
private:
    inline static int * tam;
// La instancia unica
    inline static Maze2* _inst;
    Maze2(int x,int y) {
        Maze2::tam = new int[x*y];
    }

public:
    Bot1* IA{};
    static Maze2* getInstance(int H,int W);
    std::stack<std::pair<I,I> >  Visited_Coordinates;

    pair<int,int> target = {MAZE_HEIGHT/2,MAZE_WIDTH/2};
    I &operator()(int i_row, int i_col) ;
    I operator()(int i_row, int i_col) const;
    //    Rectangle recRight;
};



/*
class Maze2 {
public:
    int * tam;
    Bot1* IA;
    std::stack<std::pair<I,I> >  Visited_Coordinates;
    Maze2() = default;
    Maze2(const Maze2& other);
    Maze2& operator=(const Maze2& other);
    pair<int,int> target = {MAZE_HEIGHT/2,MAZE_WIDTH/2};
    I &operator()(int i_row, int i_col) ;
    I operator()(int i_row, int i_col) const;

    //    Rectangle recRight;
};
 */
void backtraking(Maze2& Alfa);
Maze2 *initBoard(void);
void updateMaze2(Maze2 *const maze);
void drawMaze2(Maze2 *const maze);
bool finishMaze(void);
void freeMaze(Maze2 **board);

#endif //EXAMPLES_MAZE2_H
