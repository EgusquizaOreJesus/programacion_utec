#include "iostream"
#include "thread"
#include "iomanip"
#include "vector"

/// PRIMERA FORMA HACERLO CON PURAS MATRICES DINAMICAS
using matrix_t = int**;
using namespace std;
matrix_t transpuesta(const matrix_t& m1, int row, int col){
    matrix_t m2 = nullptr;
    m2 = new int*[col];

    for (int i = 0; i < col; ++i) {
        m2[i] = new int[row];
        for (int j = 0; j < row; ++j) {
            m2[i][j] = m1[j][i];
        }
    }
    return m2;
}
double mean(matrix_t A, int row, int col){
    double prom = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j <col ; ++j) {
            prom += A[i][j];
        }
    }
    prom = prom/(row*col);
    return prom;

}


matrix_t crear_matriz(int row, int col){
    matrix_t m1 = nullptr;
    m1 = new int*[row];
    for (int i = 0; i < row; ++i) {
        m1[i] = new int[col];
        for (int j = 0; j < col; ++j) {
            m1[i][j] = rand()%100;
        }
    }
    return m1;
}

void printMatrix(matrix_t m, int row, int col){
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << setw(8) << m[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

matrix_t product(matrix_t m1 , matrix_t m2 , int row, int col){
    matrix_t m_prod = nullptr;
    m_prod = new int*[row];
    for (int i = 0; i < row; ++i) {
        m_prod[i] = new int[row];
        for (int j = 0; j < row; ++j) {
            m_prod[i][j] = 0;
            for (int k = 0; k < col; ++k) {
                m_prod[i][j] += m1[i][k]*m2[k][j];
            }
        }
    }
    return m_prod;
}
void liberar(matrix_t m,int row){
    for (int i = 0; i < row; ++i) {
        delete[] m[i];
    }
    delete[] m;
}

void split_matrix(matrix_t m, int blocks, int row, int col, vector<matrix_t>& v_matrix){
    int parte1 = row / blocks;
    int parte2 = row - parte1;
    matrix_t temp1 = crear_matriz(parte1, col);
    for (int j = 0; j < parte1; ++j) {
        for (int k = 0; k < col; ++k) {
            temp1[j][k] = m[j][k];
        }
    }
    matrix_t temp2 = crear_matriz(parte2, col);
    for (int i = 0; i < parte2; ++i) {
        for (int j = 0; j < col; ++j) {
            temp2[i][j] = m[parte1 + i][j];
        }
    }
    v_matrix.push_back(temp1);
    v_matrix.push_back(temp2);
}


int main(){
    srand(time(nullptr));
    int row_ = 11;
    int col_ = 4;
    int parte1 = row_ / 2;
    int parte2 = row_ - parte1;
    matrix_t m1 = crear_matriz(row_,col_);
    printMatrix(m1,row_,col_);
    matrix_t  m2 = transpuesta(m1,row_,col_);
    printMatrix(m2,col_,row_);

    matrix_t m3 = product(m1,m2,row_, col_);
    printMatrix(m3,row_,row_);
    vector<matrix_t> v_matrix;
    split_matrix(m1,2,row_,col_,v_matrix);
    printMatrix(v_matrix[0],parte1,col_);
    printMatrix(v_matrix[1],parte2,col_);


    return 0;
}




