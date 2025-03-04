//
// Created by Jesus on 16/02/2023.
//

#include "maze2.h"
#include "iostream"
#include "iomanip"
using namespace std;
static bool finished = false;
static void resetValues(void);
Maze2* initBoard(void) {
    std::cout << "gola";
    resetValues();
    //Maze2 *maze = static_cast<Maze2 *>(malloc(sizeof(Maze2)));
    Maze2* maze = new Maze2;
    Maze2 a;
    maze->tam = new int[MAZE_WIDTH*MAZE_WIDTH];
    a.tam = new int[MAZE_WIDTH*MAZE_WIDTH];
    a.Visited_Coordinates.push({1,1});
    for (int x = 0; x < MAZE_WIDTH; ++x) {
        for (int y = 0; y < MAZE_WIDTH; ++y) {
            a(x,y) = 0;
        }
    }
    backtraking(a);
    for (int x = 0; x < MAZE_WIDTH; ++x) {
        for (int y = 0; y < MAZE_WIDTH; ++y) {
            cout << setw(3) << a(x,y) ;
        }
        cout << endl;
    }
    cout << endl;

    *maze = a;
    cout << endl;

    for (int x = 0; x < MAZE_WIDTH; ++x) {
        for (int y = 0; y < MAZE_WIDTH; ++y) {
            cout << setw(3) << (*maze)(x,y) ;
        }
        cout << endl;
    }
    cout << endl;

    return maze;
}

static void resetValues(void) {
    finished = false;
}
I &Maze2::operator()(int i_row, int i_col) {
    return tam[MAZE_WIDTH*i_row+(MAZE_WIDTH-(MAZE_WIDTH-i_col))];
}

I Maze2::operator()(int i_row, int i_col) const {
    return tam[MAZE_WIDTH*i_row+(MAZE_WIDTH-(MAZE_WIDTH-i_col))];
}

void drawMaze2(Maze2 *const maze) {
    for (int x = 0; x < MAZE_HEIGHT; x++) {
        for (int y = 0; y < MAZE_WIDTH; y++) {
            if (maze->tam[MAZE_WIDTH * x + (MAZE_WIDTH - (MAZE_WIDTH - y))] != 1) {
                DrawRectangle(float(x * TILE_SIZE_WIDTH), float(y * TILE_SIZE_HEIGHT), TILE_SIZE_WIDTH,
                              TILE_SIZE_HEIGHT, WHITE);
            }
        }
    }
}
void backtraking(Maze2& Alfa) {  // Implementation of Recursive Backtraking
    if(!Alfa.Visited_Coordinates.empty())
    {
        I current_x=Alfa.Visited_Coordinates.top().first;
        I current_y=Alfa.Visited_Coordinates.top().second;
        std::vector<std::pair<std::pair<I,I>, I>> Neighbors;  // 1 represents a vertical and 2 represents an horizontal movement
        // The second pair indicates if movement is vertical or horizontal
        if(Alfa(current_x+2,current_y)!=1 and current_x+2<MAZE_HEIGHT) // Check South
        {
            Neighbors.push_back({{current_x+2,current_y},1});
        }
        if(Alfa(current_x,current_y+2)!=1 and current_y+2<MAZE_WIDTH) // Check East
        {
            Neighbors.push_back({{current_x,current_y+2},2});
        }
        if(Alfa(current_x,current_y-2)!=1 and current_y-2>=1 )       //Check West
        {
            Neighbors.push_back({{current_x,current_y-2},-2});

        }
        if(Alfa(current_x-2,current_y)!=1 and current_x-2>=1 )   //Check North
        {
            Neighbors.push_back({{current_x-2,current_y},-1});


        }

        if(!Neighbors.empty())
        {
            auto Next_coordinate=Neighbors[rand()%Neighbors.size()];// Choose an avaliable neighbor randomdly
            Alfa.Visited_Coordinates.push(Next_coordinate.first); // Push new coordinate in the stack
            Alfa(Next_coordinate.first.first,Next_coordinate.first.second)=1; // marked the new coordinate as visited
            if(abs(Next_coordinate.second)==1) // check if the movement was vertical or not
            {
                Alfa(current_x+Next_coordinate.second,current_y)=1;//marked middle as visited

            }else{
                auto add=(Next_coordinate.second>0)?1:-1;
                Alfa(current_x,current_y+add)=1;//marked middle as visited
            }
            backtraking(Alfa);

        }else {

            Alfa.Visited_Coordinates.pop();
            backtraking(Alfa);
        }


    }else{

        std::cout<<"MAZE SUCCESFULLY GENERATED !!!"<<std::endl;
    }

}
void updateMaze2(Maze2 *const maze){
    if (IsKeyPressed(KEY_ESCAPE)) {
        finished = true;
    }

}

bool finishMaze(void) {
    return finished;
}
void freeMaze(Maze2 **maze){
    if (*maze != NULL) {
        free(*maze);
        *maze = NULL;
#ifdef PONG_DEBUG
        TraceLog(LOG_INFO, PONG_BOARD_DELETED);
#endif
    }
}

Maze2::Maze2(const Maze2& other){
    int size = MAZE_WIDTH*MAZE_WIDTH;
    tam =new int[MAZE_WIDTH*MAZE_WIDTH];
    copy(other.tam,other.tam + size, tam);
}

Maze2 &Maze2::operator=(const Maze2 &other) {
    if (this == &other){return *this;}
    int size = MAZE_WIDTH*MAZE_WIDTH;
    delete[] tam;
    tam = new int[size];
    copy(other.tam,other.tam + size, tam);
    return *this;
}
