
#include "iomanip"
#include "iostream"
#include "stack"
#include "vector"

#define MAP_WIDTH  1125
#define MAP_HEIGHT 1000
#define TILE_SIZE_WIDTH  9     //tamaño de cuadrado
#define TILE_SIZE_HEIGHT  8
#define MAZE_WIDTH 20
#define MAZE_HEIGHT 20
using namespace std;


using I = int;

class Maze2 {
    inline static int * tam;
// La instancia unica
    inline static Maze2* _inst;
    Maze2(int x,int y) {
        this->tam = new int[x*y];
    }
public:
    static Maze2* getInstance(int x,int y);
    std::stack<std::pair<I,I> >  Visited_Coordinates;

    pair<int,int> target = {MAZE_HEIGHT/2,MAZE_WIDTH/2};
    I &operator()(int i_row, int i_col) ;
    I operator()(int i_row, int i_col) const;

    //    Rectangle recRight;
};

Maze2* Maze2::getInstance(int H,int W){
    if (_inst == nullptr){
        _inst = new Maze2(H,W);
        for (int x = 0; x < H; ++x) {
            for (int y = 0; y < W; ++y) {
                (*_inst)(x,y) = 0;
            }
        }
        _inst->Visited_Coordinates.push({1,1});
    }
    return _inst;
}
I &Maze2::operator()(int i_row, int i_col) {
    return tam[MAZE_WIDTH*i_row+(MAZE_WIDTH-(MAZE_WIDTH-i_col))];
}

I Maze2::operator()(int i_row, int i_col) const {
    return tam[MAZE_WIDTH*i_row+(MAZE_WIDTH-(MAZE_WIDTH-i_col))];
}
Maze2* initBoard() {
    cout << "INICIALIZO MAZE" << endl;
    std::cout << "gola";
    Maze2* maze = Maze2::getInstance(MAP_HEIGHT,MAZE_WIDTH);

    for (int x = 0; x < MAZE_HEIGHT; ++x) {
        for (int y = 0; y < MAZE_WIDTH; ++y) {
            cout << setw(3) << (*maze)(x,y);
        }
    }

    //*maze = a;
    //maze->IA = initBot(1,1);
    //    for (int x = 0; x < MAZE_HEIGHT; ++x) {
    //        for (int y = 0; y < MAZE_WIDTH; ++y) {
    //            std::cout << setw(3)<<(*maze)(x,y) ;
    //        }
    //        cout << endl;
    //    }
    //    cout << endl;


    (*maze)(MAZE_HEIGHT/2, MAZE_WIDTH/2) = 1;
    for (int x = 0; x < MAZE_HEIGHT; ++x) {
        for (int y = 0; y < MAZE_WIDTH; ++y) {
            cout << setw(3) << (*maze)(x,y);
        }
    }
    cout << endl;
    return maze;
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
int main(){
    Maze2* maze = Maze2::getInstance(MAP_HEIGHT,MAZE_WIDTH);
    for (int x = 0; x < MAZE_HEIGHT; ++x) {
        for (int y = 0; y < MAZE_WIDTH; ++y) {
            cout << setw(3) << (*maze)(x,y);
        }
        cout << endl;
    }
    backtraking(*maze);
    for (int x = 0; x < MAZE_HEIGHT; ++x) {
        for (int y = 0; y < MAZE_WIDTH; ++y) {
            cout << setw(3) << (*maze)(x,y);
        }
        cout << endl;
    }

    return 0;
}

