#include "iostream"

using namespace std;

class Matrix{
    int** data_ = nullptr;          //definiendo e inicializando el atributo(inicializacion in-class "dentro de la clase")
    int rows_ = int {};   // inicializando los atributos con valores por defecto
    int cols_ = int {};
public:
    explicit Matrix(int rows, int cols){
        rows_ = rows;
        cols_ = cols;
        data_ = new int*[rows_];
        for (int i = 0; i < rows_; ++i) {
            data_[i] = new int[cols_];
            for (int j = 0; j < cols_; ++j) {
                data_[i][j] = 0;
            }
        }
    }
};


int main(){
    Matrix m1(4,2);
    return 0;
}