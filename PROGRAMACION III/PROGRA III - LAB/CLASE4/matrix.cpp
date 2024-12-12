//
// Created by Jesus on 21/01/2023.
//

#include "matrix.h"

matrix2::matrix2(int rows, int cols) {
    rows_ = rows;
    cols_ = cols;
    data_ = new int*[rows];
    random_device rd;
    uniform_int_distribution<int> dis(0,100);
    for (int i = 0; i < rows; ++i) {
        data_[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            data_[i][j] = dis(rd);
        }
    }
}

int matrix2::operator()(int row, int cols) const {
    return data_[row][cols];
}

matrix2::~matrix2() {
    liberar();
}

int matrix2::rows() const {
    return rows_;
}

int matrix2::cols() const {
    return cols_;
}

void matrix2::liberar() {
    for (int i = 0; i < rows_; ++i) {
        delete[] data_[i]; //elimino filas --> porque cada fila es un puntero que apunta a un array
    }
    delete[] data_; //POR ULTIMO ELIMINO EL ARRAY DE PUNTEROS INICIAL
}

ostream& operator<<(ostream &os, const matrix2 &m) {
    for (int i = 0; i < m.rows(); ++i) {
        for (int j = 0; j < m.cols(); ++j) {
            os << std::setw(3) <<m(i,j) << " ";
        }
        os << std::endl;
    }
    return os;
}

matrix2 matrix2::operator+(const matrix2 &m) const {
    if (rows_ == m.rows_ && cols_ == m.cols_){
        matrix2 temp(rows_,cols_);
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                temp.data_[i][j] = data_[i][j] + m.data_[i][j];
            }
        }
        return temp;
    }
    return matrix2(0, 0);
}

matrix2::matrix2(const matrix2 &other) {
    rows_ = other.rows();
    cols_ = other.cols_;
    data_ = new int*[rows_];
    for (int i = 0; i < rows_; ++i) {
        data_[i] = new int[cols_];
        for (int j = 0; j < cols_; ++j) {
            data_[i][j] = other.data_[i][j];
        }
    }
}

matrix2 &matrix2::operator=(const matrix2 &other) {
    if (this!=&other){
        this -> rows_ = other.rows();
        this -> cols_ = other.cols();
        liberar();
        this->data_ = new int*[rows_];
        for (int i = 0; i < other.rows_; ++i) {
            data_[i] = new int[cols_];
            for (int j = 0; j < other.cols_; ++j) {
                data_[i][j] = other.data_[i][j];
            }
        }
    }
    return *this;
}
