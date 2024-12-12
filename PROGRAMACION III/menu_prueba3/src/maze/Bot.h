//
// Created by Jesus on 19/02/2023.
//

#ifndef EXAMPLES_BOT_H
#define EXAMPLES_BOT_H
#include "iostream"
#include "queue"
#include "stack"
#include "vector"
#include "../global.h"
#include "raylib.h"
using namespace std;
//using I = int;
using Pi = std::pair<int,int>;

/*
class Bot {
public:
    float x_{};
    float y_{};
    std::stack<std::pair<pair<int,int>,int>>distance;
    std::queue<std::pair<int , int>> Frontier;
    std::stack<Pi> visited_cordinates_bot;
    std::vector<Pi> cordinates_bot_walks;
    std::vector<Pi> Path;
    Rectangle bot;
    Bot(float x , float y):x_(x),y_(y){
        visited_cordinates_bot.push({x,y}); // Stablishing first coordinate
        Visited_coords_distance.push({{x,y},0});
        bot = {x*TILE_SIZE_WIDTH,y*TILE_SIZE_HEIGHT,TILE_SIZE_WIDTH,TILE_SIZE_HEIGHT};
        Frontier.push({x,y});
    }
    [[nodiscard]] auto get_visited_coord_distance() const;

    static void DFS2(Maze2& Maze);
    static void BFS(Maze2& Maze);
    void draw();
};
 */
using I = int;
using Pi = std::pair<int,int>;
class Bot1{
public:

    float x_{};
    float y_{};
    std::stack<Pi>Visited_coords_distance;
    std::queue<std::pair<int , int>> Frontier;
    std::stack<Pi> visited_cordinates_bot;
    std::vector<Pi> cordinates_bot_walks;
    Pi Target;      //META
    std::vector<Pi> Path;
    Rectangle bot{};
    bool turno = true;
    Bot1(float x , float y):x_(x),y_(y){
        visited_cordinates_bot.push({x,y}); // Stablishing first coordinate
        Visited_coords_distance.push({x,y});
        bot = {x*TILE_SIZE_WIDTH,y*TILE_SIZE_HEIGHT,TILE_SIZE_WIDTH,TILE_SIZE_HEIGHT};
        Frontier.push({x,y});
    }
    void draw() const;
};

Bot1* initBot(float x, float y);

#endif //EXAMPLES_BOT_H
