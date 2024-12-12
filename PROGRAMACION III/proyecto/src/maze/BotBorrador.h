//
// Created by Jesus on 25/02/2023.
//

#ifndef EXAMPLES_BOTBORRADOR_H
#define EXAMPLES_BOTBORRADOR_H
#include "stack"
#include "maze2.h"
#include <queue>
#include <iomanip>
#include <map>
using I = int;
using Pi = std::pair<int,int>;
class GeneralPurpuseBot{

public:
    virtual void GeneralBehaivor()=0; // Target Search and Path making
    virtual void draw_pathSeeking()=0; // Draw the bot
    virtual void BoT_move() =0;// Once a path has being made the bot will start heding to its target
    virtual bool StopTurn()=0; // Gives inormation about the movement status to other players //to be implemented

};



class Bot_BFS:public GeneralPurpuseBot{


private:
    float x_{};
    float y_{};
    std::stack<Pi>Visited_coords; //needed in DFS and BFS
    std::queue<std::pair<int , int>> Frontier; // needed in BFS
    Pi Target;      //META -->//needed in DFS and BFS
    std::map<Pi,Pi> Path;//needed in DFS(to be included) and BFS
    bool PathAvaliable= false; //needed in DFS(to be included) and BFS
    bool PathReady = false;//needed in DFS(to be included) and BFS
    Rectangle bot;//General bot atribute
    std::stack<Pi> Movement;//needed in DFS(to be included) and BFS
    size_t SearchNumber=0;//needed in DFS(to be included) and BFS
    Maze2 maze;
public:

    Bot_BFS(float x , float y, Maze2& Mmaze):x_(x),y_(y),maze(Mmaze){
        Visited_coords.push({x, y});
        bot = {x*TILE_SIZE_WIDTH,y*TILE_SIZE_HEIGHT,TILE_SIZE_WIDTH,TILE_SIZE_HEIGHT};
        Frontier.push({x,y});//set irst possition as visited
        Target={MAZE_HEIGHT/2,MAZE_WIDTH/2};
        Path[{x,y}]={x,y};//Mark first position as its own root

    }

    void draw();
    void BFS(Maze2& Maze);
    void GeneratePath(Pi coord);
    void BotMove(Maze2 & Maze);
    //overriding unctions
    void GeneralBehaivor()override;
    void draw_pathSeeking()override;
    void BoT_move() override;
    bool StopTurn() override;
};
class Bot_DFS:public GeneralPurpuseBot{


private:
    float x_{};
    float y_{};

    std::stack<Pi> visited_cordinates_bot;
    std::stack<Pi>Visited_coords; //needed in DFS and BFS
    Pi Target;      //META -->//needed in DFS and BFS
    std::map<Pi,Pi> Path;//needed in DFS(to be included) and BFS
    bool PathAvaliable= false; //needed in DFS(to be included) and BFS
    bool PathReady = false;//needed in DFS(to be included) and BFS
    Rectangle bot;//General bot atribute
    std::stack<Pi> Movement;//needed in DFS(to be included) and BFS
    size_t SearchNumber=0;//needed in DFS(to be included) and BFS
    Maze2 maz;
public:

    Bot_DFS(float x , float y, Maze2 Mmaze):x_(x),y_(y),maz(Mmaze){
        Visited_coords.push({x, y});
        //   visited_cordinates_bot.push({1,1}); // Stablishing first coordinate
        bot = {x*TILE_SIZE_WIDTH,y*TILE_SIZE_HEIGHT,TILE_SIZE_WIDTH,TILE_SIZE_HEIGHT};
        Target={MAZE_HEIGHT/2,MAZE_WIDTH/2};
        Path[{x_,y_}]={x_,y_};//Mark first position as its own root

    }

    void draw();
    void DFS(Maze2& Maze);
    void GeneratePath(Pi coord);
    void Botmove(Maze2 & Maze);
    //overriding unctions
    void GeneralBehaivor()override;
    void draw_pathSeeking()override;
    void BoT_move() override;
    bool StopTurn() override;
};
enum Type{ BFS_BOT,DFS_BOT};
class Bot_Factory{
public:
    Bot_Factory(Maze2 Mmaze ,Type tipo);
    GeneralPurpuseBot* Instanciar_Bot();


private:
    Maze2 maze_;
    GeneralPurpuseBot* new_bot_instantiation;


};


#endif //EXAMPLES_BOTBORRADOR_H
