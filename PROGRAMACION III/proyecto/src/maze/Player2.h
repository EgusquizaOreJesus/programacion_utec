//
// Created by Jesus on 21/02/2023.
//

#ifndef EXAMPLES_PLAYER2_H
#define EXAMPLES_PLAYER2_H
#include "../global.h"
#include "maze2.h"

using Pi = std::pair<int,int>;

class Player{
private:
    int x_{};
    int y_{};
    Color color_;
public:
    Player(int x , int y, Color color):x_(x),y_(y), color_(color){
    }
    ~Player()= default;
    [[nodiscard]] int getX() const {
        return x_;
    }
    [[nodiscard]] int getY() const {
        return y_;
    }
    void DrawPlayer(){
        DrawRectangle(x_ * TILE_SIZE_WIDTH, y_ * TILE_SIZE_HEIGHT, TILE_SIZE_WIDTH, TILE_SIZE_HEIGHT, color_);
    }

    bool no_salga(){
        if (IsKeyDown(KEY_A)) {
            if (x_ <= MAZE_HEIGHT and x_ > 0)
                return true;
        }
        else if (IsKeyDown(KEY_D)) {
            if (x_ < MAZE_HEIGHT and x_ >= 0)
                return true;
        }
        else if (IsKeyDown(KEY_W)) {
            if (y_ <= MAZE_WIDTH and y_ > 0)
                return true;
        }
        else if (IsKeyDown(KEY_S)) {
            if (y_ < MAZE_WIDTH and y_ >= 0)
                return true;
        }
        return false;
    }

    bool sig_cuadro(Maze2 y){
        if (IsKeyDown(KEY_A)) {
            if (y(y_, x_ - 1) != 0)
                return true;
        }
        else if (IsKeyDown(KEY_D)) {
            if (y(y_, x_ + 1) != 0)
                return true;
        }
        else if (IsKeyDown(KEY_W)) {
            if (y(y_ - 1, x_) != 0)
                return true;
        }
        else if (IsKeyDown(KEY_S)) {
            if (y(y_ + 1, x_) != 0)
                return true;
        }
        return false;
    }

    bool col_play(Player y){
        if (IsKeyDown(KEY_A)) {
            if ((y_ != y.getY() or x_ - 1 != y.getX()) and (x_ - 1 != MAZE_HEIGHT / 2 or y_ != MAZE_WIDTH / 2))
                return true;
        }
        else if (IsKeyDown(KEY_D)) {
            if ((y_ != y.getY() or x_ + 1 != y.getX()) and (x_ + 1 != MAZE_HEIGHT / 2 or y_ != MAZE_WIDTH / 2))
                return true;
        }
        else if (IsKeyDown(KEY_W)) {
            if ((y_ - 1 != y.getY() or x_ != y.getX()) and (y_ - 1 != MAZE_WIDTH / 2 or x_ !=  MAZE_HEIGHT / 2))
                return true;
        }
        else if (IsKeyDown(KEY_S)) {
            if ((y_ + 1 != y.getY() or x_ != y.getX()) and (y_ + 1 != MAZE_WIDTH / 2 or x_ != MAZE_HEIGHT / 2))
                return true;
        }
        return false;
    }

    bool tecla_val(pthread_key_t a){
        if (a == KEY_A or a == KEY_W or a == KEY_D or a == KEY_S){
            return true;
        }
        return false;
    }

    void avanz_play(pthread_key_t y){
        if (y == KEY_A){
            x_ -= 1;
        }
        else if (y == KEY_D){
            x_ += 1;
        }
        else if (y == KEY_W){
            y_ -= 1;
        }
        else if (y == KEY_S){
            y_ += 1;
        }
    }

    int vecinos(Player z, Maze2& y){
        int total_vec = 0;
        if (y(y_, x_ + 1) != 0 and (z.getX() != x_ + 1 or z.getY() != y_) and (x_ + 1 != MAZE_HEIGHT / 2 or y_ != MAZE_WIDTH / 2)){
            total_vec++;
        }
        if (y(y_, x_ - 1) != 0 and (z.getX() != x_ - 1 or z.getY() != y_) and (x_ - 1 != MAZE_HEIGHT / 2 or y_ != MAZE_WIDTH / 2)){
            total_vec++;
        }
        if (y(y_ + 1, x_) != 0 and (z.getY() != y_ + 1 or z.getX() != x_) and (y_ + 1 != MAZE_WIDTH / 2 or x_ != MAZE_HEIGHT / 2)){
            total_vec++;
        }
        if (y(y_ - 1, x_) != 0 and (z.getY() != y_ - 1 or z.getX() != x_) and (y_ - 1 != MAZE_WIDTH / 2 or x_ != MAZE_HEIGHT / 2)){
            total_vec++;
        }
        return total_vec;
    }

    void movement(Player& t, Maze2& y, Pi coords, int& trn){
        while (vecinos(t, y) == 2){
            if (y(y_ - 1, x_) != 0 and coords.first != y_ - 1 and col_play(t) and vecinos(t, y) < 3){
                coords.first = y_;
                coords.second = x_;
                y_ -= 1;
                this->DrawPlayer();
            }
            else if (y(y_, x_ + 1) != 0 and coords.second != x_ + 1 and col_play(t) and vecinos(t, y) < 3){
                coords.second = x_;
                coords.first = y_;
                x_ += 1;
                this->DrawPlayer();
            }
            else if (y(y_ + 1, x_) != 0 and coords.first != y_ + 1 and col_play(t) and vecinos(t, y) < 3){
                coords.first = y_;
                coords.second = x_;
                y_ += 1;
                this->DrawPlayer();
            }
            else if (y(y_, x_ - 1) != 0 and coords.second != x_ - 1 and col_play(t) and vecinos(t, y) < 3){
                coords.second = x_;
                coords.first = y_;
                x_ -= 1;
                this->DrawPlayer();
            }
            this->DrawPlayer();
        }
        if (trn == 1){
            trn = 2;
        }
        else if (trn == 2) {
            trn = 1;
        }
    }

    bool verf_gan(Maze2& ga){
        if ((x_ ==  ga.target.first -1 and y_ ==  ga.target.second) or (x_ ==  ga.target.first +1  and y_ ==  ga.target.second)
            or (x_ ==  ga.target.first and y_ ==  ga.target.second-1) or (x_ ==  ga.target.first and y_ == ga.target.second+1))
            return true;
        return false;
    }
    /*
        bool verf_gan(){
        if ((x_ == MAZE_HEIGHT / 2 - 1 and y_ == MAZE_WIDTH / 2) or (x_ == MAZE_HEIGHT / 2 + 1 and y_ == MAZE_WIDTH / 2)
            or (x_ == MAZE_HEIGHT / 2 and y_ == MAZE_WIDTH / 2 - 1) or (x_ == MAZE_HEIGHT / 2 and y_ == MAZE_WIDTH / 2 + 1))
            return true;
        return false;
    }
     */
};


#endif //EXAMPLES_PLAYER2_H
