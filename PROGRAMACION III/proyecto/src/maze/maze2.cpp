//
// Created by Jesus on 16/02/2023.
//

#include "maze2.h"
#include "iostream"
#include "Player2.h"
#include "BotBorrador.h"
#include "iomanip"

using namespace std;

using Pi = std::pair<int,int>;
static void BFS(Maze2& maze);
static void DFS(Maze2& maze);
static bool finished = false;
static const int32_t MAX_COUNTER = 5;
static int32_t counter = MAX_COUNTER;
static int32_t prevCounter = 0;
static void drawCounterScreen(void);
static void UpdateCounter (void);
static bool showCounter = true;
static void resetValues(void);
bool bot_creado = false;
static int turno = 0;
Player* zeta = new Player(1,1,GREEN);
Player* Beta = new Player(MAZE_HEIGHT-1,MAZE_WIDTH-1,PURPLE);

GeneralPurpuseBot* crear_Bot(Maze2 *const maze){
    auto Robot = Bot_Factory(*maze,BFS_BOT);
    auto UseRobot= Robot.Instanciar_Bot();
    return UseRobot;
}


Maze2* initBoard() {
    cout << "INICIALIZO MAZE" << endl;
    std::cout << "gola";
    resetValues();
    Maze2* maze = Maze2::getInstance(MAP_HEIGHT,MAZE_WIDTH);
    backtraking(*maze);

    (*maze)(MAZE_HEIGHT/2, MAZE_WIDTH/2) = 1;
    (*maze)((MAZE_HEIGHT/2)-1, MAZE_WIDTH/2) = 1;
    (*maze)((MAZE_HEIGHT/2)+1, MAZE_WIDTH/2) = 1;
    (*maze)(MAZE_HEIGHT/2, (MAZE_WIDTH/2)-1) = 1;
    (*maze)(MAZE_HEIGHT/2, (MAZE_WIDTH/2)+1) = 1;
    cout << endl;
    return maze;
}


static void resetValues(void) {
    finished = false;
    showCounter = true;
    counter = MAX_COUNTER;
    prevCounter = 0;
}
I &Maze2::operator()(int i_row, int i_col) {
    return tam[MAZE_WIDTH*i_row+(MAZE_WIDTH-(MAZE_WIDTH-i_col))];
}

I Maze2::operator()(int i_row, int i_col) const {
    return tam[MAZE_WIDTH*i_row+(MAZE_WIDTH-(MAZE_WIDTH-i_col))];
}

void drawMaze2(Maze2 *const maze) {
    if (showCounter){
        UpdateCounter();
        drawCounterScreen();
    }
    else{
        maze->show = true;
//        bot->GeneralBehaivor();
//        bot->BoT_move();
        //DFS(*maze);
        //BFS(*maze);
        //        for (int x = 0; x < MAZE_HEIGHT; ++x) {
        //            for (int y = 0; y < MAZE_WIDTH; ++y) {
        //                std::cout << setw(3)<<(*maze)(x,y) ;
        //            }
        //            cout << endl;
        //        }
        //        cout << endl;

        DrawRectangle(maze->target.first * TILE_SIZE_WIDTH, maze->target.first*TILE_SIZE_HEIGHT, TILE_SIZE_WIDTH, TILE_SIZE_HEIGHT, RED);
        for (int x = 0; x < MAZE_HEIGHT; x++) {
            for (int y = 0; y < MAZE_WIDTH; y++) {
                if ((*maze)(y,x)==0) {
                    DrawRectangle(float(x * TILE_SIZE_WIDTH), float(y * TILE_SIZE_HEIGHT), TILE_SIZE_WIDTH,
                                  TILE_SIZE_HEIGHT, WHITE);
                }
                if ((*maze)(y,x)==2){
                    DrawRectangle(float(x * TILE_SIZE_WIDTH), float(y * TILE_SIZE_HEIGHT), TILE_SIZE_WIDTH,
                                  TILE_SIZE_HEIGHT, PINK);
                }
                if ((*maze)(y,x) == 3){
                    DrawRectangle(float(x*TILE_SIZE_WIDTH),float(y * TILE_SIZE_HEIGHT),TILE_SIZE_WIDTH, TILE_SIZE_HEIGHT,RED);
                }
            }
        }
//        pthread_key_t z;
//        z = GetKeyPressed();
//        pair<int,int> coords_ac {Alfa->getY(),Alfa->getX()};
//        if (Alfa->tecla_val(z) and Alfa->no_salga() and Alfa->sig_cuadro(*maze) and Alfa->col_play(*Beta))
//        {
//            Alfa->avanz_play(z);
//            Alfa->DrawPlayer();
//            Alfa->movement(*Beta, *maze, coords_ac, turno);
//            Alfa->DrawPlayer();
//        }
//        Alfa->DrawPlayer();
    }

}
void backtraking(Maze2& Alfa) {
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
    }
}

//Maze2::Maze2(const Maze2& other){
//    int size = MAZE_WIDTH*MAZE_HEIGHT;
//    tam =new int[MAZE_WIDTH*MAZE_HEIGHT];
//    copy(other.tam,other.tam + size, tam);
//}
//
//Maze2 &Maze2::operator=(const Maze2 &other) {
//    if (this == &other){return *this;}
//    int size = MAZE_WIDTH*MAZE_HEIGHT;
//    delete[] tam;
//    tam = new int[size];
//    copy(other.tam,other.tam + size, tam);
//    return *this;
//}
static void drawCounterScreen(void) {
    DrawRectangle(
            0,
            0,
            GetScreenWidth(),
            GetScreenHeight(),
            Fade((Color){ 43, 43, 38, 255 }, 0.6)
    );
    vector<const char* > v = {"","START","1","2","3","4"};
    const int32_t fontSize = 120;
    const char* value = TextFormat("%s",v[counter]);
    const int32_t posX = GetScreenWidth() / 2 - MeasureText(value, fontSize) / 2;
    const int32_t posY = GetScreenHeight() / 2 - (fontSize / 2);
    DrawText(value, posX, posY, fontSize, (Color){ 224, 219, 205, 255 });

}
static void UpdateCounter (void) {
    if (counter > 0) {
        const int32_t time = (int32_t) GetTime();
        if (time != prevCounter) {
            prevCounter = time;
            counter--;
        }
    } else {
        showCounter = false;
        counter = MAX_COUNTER;
        prevCounter = 0;
    }
}
//static void DFS(Maze2& maze){
//    vector<Pi> Cardinals{{0, -1},{1,0},{0,1},{-1,0}};
//    if (maze.IA->Frontier.front() != maze.target){
//        Pi cur_coord = maze.IA->Frontier.front();//Current Coordinates
//
//        maze.IA->Frontier.pop();// Eliminate the first element on qeue that is a visited neighbor
//        int tem=0;
//        for (auto Adder: Cardinals){
//            Pi Next = {maze.IA->visited_cordinates_bot.top().first + Adder.first, maze.IA->visited_cordinates_bot.top().second + Adder.second};
//            if (maze(Next.first, Next.second) != 0 and
//                    maze(Next.first, Next.second) != 2 and (Next.first>=0 and Next.first<MAZE_HEIGHT) and ((Next.second>=0 and Next.second<MAZE_WIDTH))){
//                maze(Next.first,Next.second) = 2;
//                maze.IA->visited_cordinates_bot.push(Next);
//                maze.IA->Frontier.push(Next);// Add the new neighbor
//                break;
//            }tem++;
//        }
//        if (tem == 4){ maze.IA->visited_cordinates_bot.pop();}
//    }
//}
static void DFS(Maze2& maze){
    vector<Pi> Cardinals{{0, -1},{1,0},{0,1},{-1,0}};
    if (maze.IA->Visited_coords_distance.top() != maze.target){
        int tem=0;
        for (auto Adder: Cardinals){
            Pi Next = {maze.IA->Visited_coords_distance.top().first + Adder.first, maze.IA->Visited_coords_distance.top().second + Adder.second};
            if (maze(Next.first, Next.second) != 0 and
                maze(Next.first, Next.second) != 2 and (Next.first>=0 and Next.first<MAZE_HEIGHT) and ((Next.second>=0 and Next.second<MAZE_WIDTH))){
                maze(Next.first,Next.second) = 2;
                maze.IA->Visited_coords_distance.push(Next);
                break;
            }tem++;
        }
        if (tem == 4){ maze.IA->Visited_coords_distance.pop();}
    }
}
static void BFS(Maze2& maze){
    vector<Pi> Cardinals{{0, 1},{0, -1}, { -1, 0 },{ 1, 0 }}; // East , West , North and South

    if(maze.IA->Frontier.front() != maze.target) {
        Pi cur_coord = maze.IA->Frontier.front();//Current Coordinates

        maze.IA->Frontier.pop();// Eliminate the first element on qeue that is a visited neighbor
        for (auto Adder: Cardinals) {

            Pi Next = {cur_coord.first + Adder.first,
                       cur_coord.second + Adder.second}; // Establish next possible coordinate
            if (maze(Next.first, Next.second) != 0 and
                    maze(Next.first, Next.second) != 2 and (Next.first>=0 and Next.first<MAZE_HEIGHT) and ((Next.second>=0 and Next.second<MAZE_WIDTH)))//Check if next is an avaliable neighbor
            {
                maze.IA->Frontier.push(Next);// Add the new neighbor
                maze(Next.first, Next.second) = 2; // Mark
                maze.IA->Visited_coords_distance.push(Next);
            }
        }
    }
}
Maze2* Maze2::getInstance(int H,int W){
    if (_inst == nullptr){
        cout << "creando" << endl;
        _inst = new Maze2(H,W);
        for (int x = 0; x < H; ++x) {
            for (int y = 0; y < W; ++y) {
                (*_inst)(x,y) = 0;
            }
        }
        _inst->Visited_Coordinates.push({1,1});
        cout << _inst->Visited_Coordinates.size() << endl;
    }
    else{
        cout << "RESET" << endl;
        for (int x = 0; x < H; ++x) {
            for (int y = 0; y < W; ++y) {
                (*_inst)(x,y) = 0;
            }
        }
        cout << _inst->Visited_Coordinates.size() << endl;
        _inst->Visited_Coordinates.push({1,1});
    }
    return _inst;

}