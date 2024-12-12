//
// Created by Jesus on 19/02/2023.
//

#include "Bot.h"
#include "iomanip"
Bot1* initBot(float x, float y){
    Bot1* bot = new Bot1(x,y);
    return bot;
}


void Bot1::draw() const {
    DrawRectangleRec(bot,PINK);
}




/*
void Bot::DFS2(Maze2 &Maze) {
    vector<Pi> Cardinals{{0, -1},{1,0},{0,1},{-1,0}};
    if (visited_cordinates_bot.top() != Target){

        int tem=0;
        for (auto Adder: Cardinals){
            Pi Next = {visited_cordinates_bot.top().first + Adder.first, visited_cordinates_bot.top().second + Adder.second};
            if (Maze(Next.first, Next.second) != 0 and
                Maze(Next.first, Next.second) != 2 and (Next.first>=0 and Next.first<MAZE_HEIGHT) and ((Next.second>=0 and Next.second<MAZE_WIDTH))){
                Maze(Next.first,Next.second) = 2;
                visited_cordinates_bot.push(Next);
                break;
            }tem++;
        }
        if (tem == 4){ visited_cordinates_bot.pop();}
    }
}

 void Bot::BFS(Maze2& Maze) {
    vector<Pi> Cardinals{{0, 1},{0, -1}, { -1, 0 },{ 1, 0 }}; // East , West , North and South
    if(Visited_coords_distance.top().first != Target) {
        Pi cur_coord = Frontier.front();//Current Coordinates
        int Distance =0;
        Distance=Visited_coords_distance.top().second;
        Frontier.pop();// Eliminate the first element on qeue that is a visited neighbor
        cout<<cur_coord.first+1<<";"<<cur_coord.second+1<<"   D-->   ("<<Distance<<")  ELIMINADA"<<endl;
        cout<<endl;
        for (auto Adder: Cardinals) {

            Pi Next = {cur_coord.first + Adder.first,
                       cur_coord.second + Adder.second}; // Establish next possible coordinate
            if (Maze(Next.first, Next.second) != 0 and
                Maze(Next.first, Next.second) != 2 and (Next.first>=0 and Next.first<MAZE_HEIGHT-1) and ((Next.second>=0 and Next.second<MAZE_WIDTH-1)))//Check if next is an avaliable neighbor
            {
                cout<<setw(3)<<Next.first+1<<";"<<Next.second+1<<"AHORA EN COLA con distancia --->"<<Distance+1<<endl;
                Frontier.push(Next);// Add the new neighbor
                Maze(Next.first, Next.second) = 2; // Mark
                Visited_coords_distance.push({Next, Distance + 1});
            }
        }
        cout<<"LA DISTANCIA DESPUES DE ESTE PROCESO ES --->"<<Distance<<endl;
    }
    /* int D_F=Visited_coords_distance.top().second;
     while(!Visited_coords_distance.empty())
     { cout<<setw(5)<<Visited_coords_distance.top().first.first+1<<";"<<Visited_coords_distance.top().first.second+1<<"-->"<<Visited_coords_distance.top().second<<endl;
         if(D_F-1==Visited_coords_distance.top().second) {
             Path.push_back(Visited_coords_distance.top().first);
             D_F--;
         }

         Visited_coords_distance.pop();
     }
     cout<<"TARGET REACHED !!!"<<endl;


*/