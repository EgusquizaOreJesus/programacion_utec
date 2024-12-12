#include <bits/stdc++.h>
#include "laberinto.h"
#include "Na_No_hA_Stricker.h"
using namespace std;
int main() {

    Laberinto A;
    Player Alfa(1,1,20,20);
    Bot Beta(123, 124,20,20);

    float speed = 1;
    srand(time(nullptr));
    for (int i = 0; i < MAZE_HEIGHT; ++i) {
        for (int j = 0; j < MAZE_WIDTH; ++j) {
           A(i,j) = 0;
      }
       cout<<endl;
    }
    //for (int i = 0; i < MAZE_HEIGHT; ++i) {
    //        for (int j = 0; j < MAZE_WIDTH; ++j) {
    //            A(i,j) = 0;
    //        }
    //        cout<<endl;
    //    }
    //    for (int i = 0; i < MAZE_HEIGHT; ++i) {
    //        for (int j = 0; j < MAZE_WIDTH; ++j) {
    //            cout<< setw(3)<<i << j<<" ";
    //        }
    //        cout<<endl;
    //    }

    backtraking(A);
    InitAudioDevice();  //Inicializo
    InitWindow(MAP_WIDTH, MAP_HEIGHT, "Marisa");
        SetTargetFPS(60);
    float timePlayed = 0.0f;        // Time played normalized [0.0f..1.0f]
    bool pause = false;
    A(62,61) = 1;
    Texture2D block_ = LoadTexture("..\\assets\\block_.png");
    Texture2D finish = LoadTexture("..\\assets\\META1.png");
    Music soundtrack = LoadMusicStream("..\\assets\\BOCCHIGOD.mp3");
    PlayMusicStream(soundtrack);
    while (!WindowShouldClose()) {
        UpdateMusicStream(soundtrack);
        if (IsKeyPressed(KEY_P))
        {
            pause = !pause;
            if (pause) PauseMusicStream(soundtrack);
            else ResumeMusicStream(soundtrack);
        }
        BeginDrawing();
        ClearBackground(BLACK);
        for (int x = 0; x < MAZE_HEIGHT; x++) {
            for (int y = 0; y < MAZE_WIDTH; y++) {
                if (A(y,x) != 1 and A(y,x) != 2 and A(y,x)!=3) {
                    DrawTextureRec(
                            block_,
                            Rectangle{float(x*TILE_SIZE_WIDTH),float(y * TILE_SIZE_HEIGHT),TILE_SIZE_WIDTH, TILE_SIZE_HEIGHT},
                            Vector2{float(x*TILE_SIZE_WIDTH),float(y * TILE_SIZE_HEIGHT)},
                            WHITE
                    );
                }
                if (A(y,x) == 2){
                    DrawRectangle(float(x*TILE_SIZE_WIDTH),float(y * TILE_SIZE_HEIGHT),TILE_SIZE_WIDTH, TILE_SIZE_HEIGHT,PINK);
                }
            }
        }
        //DrawRectangle(15*TILE_SIZE_WIDTH,15*TILE_SIZE_HEIGHT,TILE_SIZE_WIDTH,TILE_SIZE_HEIGHT,GREEN);
        //Alfa.movement(Alfa,A,{1,1});

        DrawTextureRec(
                finish,
                Rectangle{float(62*TILE_SIZE_WIDTH),float(61 * TILE_SIZE_HEIGHT),TILE_SIZE_WIDTH, TILE_SIZE_HEIGHT},
                Vector2{float(62*TILE_SIZE_WIDTH),float(61 * TILE_SIZE_HEIGHT)},
                WHITE
                );
        //DrawRectangle(Beta.getX()*TILE_SIZE_WIDTH,Beta.getY()*TILE_SIZE_HEIGHT,TILE_SIZE_WIDTH,TILE_SIZE_HEIGHT,BLUE);
        //Beta.DFS(A);
        //Beta.DFS2(A);
        Beta.BFS(A);
        if(IsKeyDown(KEY_A) and Alfa.getX() <= MAZE_HEIGHT-1 and Alfa.getX() > 0 and A(Alfa.getY(),Alfa.getX() - 1) != 0)
        {
            Alfa -= (speed);
            cout << "X:" << round(Alfa.getX()) << endl;
        }
        else if(IsKeyDown(KEY_D) and Alfa.getX() < MAZE_HEIGHT-1 and Alfa.getX() >= 0 and A(Alfa.getY(), Alfa.getX() + 1) != 0)
        {
            Alfa += (speed);
            cout << "X:" << round(Alfa.getX()) << endl;
        }
        else if(IsKeyDown(KEY_S) and Alfa.getY() < MAZE_HEIGHT-1 and Alfa.getY() >= 0 and A(Alfa.getY() + 1,Alfa.getX()) != 0)
        {
            Alfa + (speed);
            cout << "Y:" << round(Alfa.getY()) << endl;
        }
        else if(IsKeyDown(KEY_W) and Alfa.getY() <= MAZE_HEIGHT-1 and Alfa.getY() > 0 and A(Alfa.getY() - 1,Alfa.getX()) != 0)
        {
            Alfa - (speed);
            cout << "Y:" << round(Alfa.getY()) << endl;
        }
        DrawRectangle(Alfa.getX()*TILE_SIZE_WIDTH, Alfa.getY()*TILE_SIZE_HEIGHT, TILE_SIZE_WIDTH,TILE_SIZE_HEIGHT, BLUE);
        GetFPS();
        EndDrawing();
    }
    UnloadMusicStream(soundtrack);   // Unload music stream buffers from RAM
    CloseAudioDevice();
    CloseWindow();
}