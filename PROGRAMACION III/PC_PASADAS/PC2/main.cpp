#include <iostream>
#include "random"
#include "iomanip"
using namespace std;
template<typename T>
using matrix_t = T**;

template<typename T>
matrix_t<T> crear_matriz(int row, int col){
    int min = 0;
    int max = 99;
    matrix_t<T> m1 = nullptr;
    if (typeid(T).name() == typeid(double).name() || typeid(T).name() == typeid(float).name()){
        random_device rd;
        uniform_real_distribution<double> dis(min,max);
        m1 = new T*[row];
        for (int i = 0; i < row; ++i) {
            m1[i] = new T[col];
            for (int j = 0; j < col; ++j) {
                m1[i][j] = dis(rd);
            }
        }
        return m1;
    }
    else{
        random_device rd;
        uniform_int_distribution<int> dis(min,max);
        m1 = new T*[row];
        for (int i = 0; i < row; ++i) {
            m1[i] = new T[col];
            for (int j = 0; j < col; ++j) {
                m1[i][j] = dis(rd);
            }
        }
        return m1;
    }

}

template<typename T>
void liberar(matrix_t<T> m,int row){
    for (int i = 0; i < row; ++i) {
        delete[] m[i];
    }
    delete[] m;
}
template<typename T1,typename T2>
matrix_t<double> product(matrix_t<T1> m1 , matrix_t<T2> m2 , int row_m1, int col_m1, int row_m2, int col_m2){
    matrix_t<double> m_prod = nullptr;
    m_prod = new double*[row_m1];
    for (int i = 0; i < row_m1; ++i) {
        m_prod[i] = new double[col_m2];
        for (int j = 0; j < col_m2; ++j) {
            m_prod[i][j] = 0;
            for (int k = 0; k < row_m2; ++k) {
                m_prod[i][j] += m1[i][k]*m2[k][j];
            }
        }
    }
    return m_prod;
}
template<typename T>
void printMatrix(matrix_t<T> m, int row, int col){
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout  <<setw(10) << m[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
template<typename T>
double mean(matrix_t<T> A, int row, int col){
    double prom = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j <col ; ++j) {
            prom += A[i][j];
        }
    }
    prom = prom/(row*col);
    return prom;
}
template<typename T, typename K>
matrix_t<double> sum_escalar(matrix_t<T> m,int row,int col, K c){
    matrix_t<double> m_sum = nullptr;
    m_sum = new double*[row];
    for (int i = 0; i < row; ++i) {
        m_sum[i] = new double[col];
        for (int j = 0; j < col; ++j) {
            m_sum[i][j] = m[i][j] + c;
        }
    }
    return m_sum;
}
int main() {
    matrix_t<double> m1 = crear_matriz<double>(2,3);
    matrix_t<int> m2 = crear_matriz<int>(3,1);
    printMatrix(m1,2,3);
    printMatrix(m2,3,1);
    matrix_t<double> m = product(m1,m2,2,3,3,1);
    printMatrix(m,2,1);
    cout << mean(m1,2,3);
    matrix_t<double> m4 = sum_escalar(m2,3,1,2);
    printMatrix(m4,3,1);
    return 0;
}
