//
// Created by Jesus on 25/02/2023.
//

#include "BotBorrador.h"


//
// Created by Jesus on 4/02/2023.
//


using namespace std;
//PARA D
void Bot_DFS::DFS(Maze2 &Maze) {



    vector<Pi> Cardinals{{0, -1},{1,0},{0,1},{-1,0}};
    if (Visited_coords.top() != Target){
        int tem=0;
        for (auto Adder: Cardinals){
            Pi Next = {Visited_coords.top().first + Adder.first, Visited_coords.top().second + Adder.second};
            if (Maze(Next.first, Next.second) != 0 and
                Maze(Next.first, Next.second) != 2 and (Next.first>=0 and Next.first<MAZE_HEIGHT) and ((Next.second>=0 and Next.second<MAZE_WIDTH))){
                Maze(Next.first,Next.second) = 2;
                Visited_coords.push(Next);
                break;
            }tem++;
        }
        if (tem == 4){ Visited_coords.pop();}
    }
}
void Bot_DFS::draw() {
    DrawRectangleRec(bot,PINK);

}
void Bot_DFS::GeneratePath(Pi coord) {


    if(PathAvaliable  and SearchNumber==0)
    {
        if(Path[coord]!=coord  )
        {cout<<"ESTA COORDENADA NO ES ROOT-->  ("<<coord.first<<";"<<coord.second<<")"<<endl;

            Movement.push(coord);
            GeneratePath(Path[coord]);
        }else {
            Movement.push(coord);
            PathReady= true;
            SearchNumber=1;
            cout<<"ENTRO A LA VERDAD"<<endl;
        }
    }
    if(PathReady)
    {
        cout<<"Bot is heading to Target..."<<endl;
    }

}
void Bot_DFS::Botmove(Maze2 &Maze) {
    if(!Movement.empty()) {
        Maze(Movement.top().first,Movement.top().second)=3;
        Movement.pop();
    }
}

void Bot_DFS::GeneralBehaivor() {
    cout<<"USANDO AL DSDSDS"<<endl;
    DFS(maz);
    //GeneratePath(Target);
}
void Bot_DFS::draw_pathSeeking() {
    draw();
}
bool Bot_DFS::StopTurn() {
    return false;
}
void Bot_DFS::BoT_move() {
    Botmove(maz);
}

//PARA B
void Bot_BFS::draw() {
    DrawRectangleRec(bot,PINK);

}
void Bot_BFS::BFS(Maze2& Maze) {
    vector<Pi> Cardinals{{0, 1},{0, -1}, { -1, 0 },{ 1, 0 }}; // East , West , North and South
    if(Visited_coords.top() != Target and Frontier.front()!=Target) {
        Pi cur_coord = Frontier.front();//Current Coordinates
        Maze(cur_coord.first,cur_coord.second)=2;
        Frontier.pop();// Eliminate the first element on qeue that is a visited neighbor
        //cout<<endl;
        for (auto Adder: Cardinals) {

            Pi Next = {cur_coord.first + Adder.first,
                       cur_coord.second + Adder.second}; // Establish next possible coordinate
            if (Maze(Next.first, Next.second) != 0 and
                Maze(Next.first, Next.second) != 2 and (Next.first>=0 and Next.first<MAZE_HEIGHT-1) and ((Next.second>=0 and Next.second<MAZE_WIDTH-1)))//Check if next is an avaliable neighbor
            {

                Frontier.push(Next);// Add the new neighbor
                Maze(Next.first, Next.second) = 2; // Mark
                Visited_coords.push(Next);

                Path[Next]=cur_coord; //Make the next coordinate a ramification of current coordinate
                //cout<<"Se ha hecho "<<Next.first<<";"<<Next.second<<" HIJO DE --> "<< cur_coord.first<<";"<<cur_coord.second<<endl;

            }
        }

    }else {
        PathAvaliable= true;
    }
}
void Bot_BFS::GeneratePath(Pi coord) {


    if(PathAvaliable  and SearchNumber==0)
    {
        if(Path[coord]!=coord  )
        {//cout<<"ESTA COORDENADA NO ES ROOT-->  ("<<coord.first<<";"<<coord.second<<")"<<endl;

            Movement.push(coord);
            GeneratePath(Path[coord]);
        }else {
            Movement.push(coord);
            PathReady= true;
            SearchNumber=1;
            //cout<<"ENTRO A LA VERDAD"<<endl;
        }
    }
    if(PathReady)
    {
        //cout<<"Bot is heading to Target..."<<endl;
    }

}
void Bot_BFS::BotMove(Maze2 &Maze) {
    if(!Movement.empty()) {
        Maze(Movement.top().first,Movement.top().second)=3;
        Movement.pop();
    }
}

void Bot_BFS::GeneralBehaivor(){

    BFS(maze);
    GeneratePath(Target);
}
void Bot_BFS::draw_pathSeeking() {
    draw();
}
void Bot_BFS::BoT_move() {
    BotMove(maze);
}
bool Bot_BFS::StopTurn() {
    return false;
}

Bot_Factory::Bot_Factory(Maze2 MMaze,Type tipo):maze_(MMaze) {
    pair<float,float> Origin;
    if(MAZE_HEIGHT%2==0 and MAZE_WIDTH%2==0)
        Origin= make_pair(0,0);
    if(MAZE_HEIGHT%2!=0  and MAZE_WIDTH%2!=0)  Origin= make_pair(1,1);

    if(tipo==BFS_BOT)
    {
        new_bot_instantiation = new Bot_BFS(Origin.first,Origin.second,maze_);

    }
    if(tipo==DFS_BOT)
    {
        new_bot_instantiation = new Bot_DFS(Origin.first,Origin.second,maze_);
    }
}

GeneralPurpuseBot *Bot_Factory::Instanciar_Bot() {
    if (new_bot_instantiation == NULL){
        cout << "creando instancia";
        return new_bot_instantiation;
    }
    return new_bot_instantiation;

}


