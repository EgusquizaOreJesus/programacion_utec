//
// Created by Jesus on 16/01/2023.
//

#include "matrix.h"



Matrix::Matrix(SizeType rows, SizeType cols) {
    rows_ = rows;
    cols_ = cols;
    data_ = new Type*[rows];
    for (int i = 0; i < rows; ++i) {
        data_[i] = new Type[cols];
        for (int j = 0; j < cols; ++j) {
            data_[i][j] = 0;
        }
    }
}

void Matrix::liberar(){
    for (int i = 0; i < rows_; ++i) {
        delete[] data_[i]; //elimino filas --> porque cada fila es un puntero que apunta a un array
    }
    delete[] data_; //POR ULTIMO ELIMINO EL ARRAY DE PUNTEROS INICIAL
}


/*
Matrix::Matrix(const Matrix &other) {
    std::cout << "hola" << std::endl;

    rows_ = other.rows();
    //this -> cols_ = other.cols_;
    //this -> data_ = other.data_;
}
 */
Matrix::Matrix(const Matrix &other) {

    rows_ = other.rows();
    this -> cols_ = other.cols_;

    data_ = new Type*[rows_];
    for (int i = 0; i < rows_; ++i) {
        data_[i] = new Type[cols_];
        for (int j = 0; j < cols_; ++j) {
            data_[i][j] = other.data_[i][j];
        }
    }
}

SizeType Matrix::rows() const {
    return rows_;
}

SizeType Matrix::cols() const {
    return cols_;
}

/*
 * Type &Matrix::operator()(int i_row, int i_col) {
    return <#initializer#>;
}

Matrix &Matrix::operator=(Matrix &&other) noexcept {
    return <#initializer#>;
}

 */

Matrix& Matrix::operator=(const Matrix& other) {
    this -> rows_ = other.rows();
    this -> cols_ = other.cols();
    liberar();
    this->data_ = new Type*[rows_];
    for (int i = 0; i < other.rows_; ++i) {
        data_[i] = new Type[cols_];
        for (int j = 0; j < other.cols_; ++j) {
            data_[i][j] = other.data_[i][j];
        }
    }
    return *this;
}
Matrix &Matrix::operator=(Matrix &&other) noexcept {
    using std::swap;
    swap(this->rows_, other.rows_);
    swap(this->cols_, other.cols_);
    swap(this->data_, other.data_);
    return *this;
}


//Matrix::Matrix() = default;

Type &Matrix::operator()(int i_row, int i_col) {
    return data_[i_row][i_col];
}
Type Matrix::operator()(int i_row, int i_col) const {
    return data_[i_row][i_col];
}

ostream &operator<<(ostream &os, const Matrix &m) {
    std::string txt;
    for (int i = 0; i < m.rows_; ++i) {
        for (int j = 0; j < m.cols_; ++j) {
            os << m.data_[i][j];
            os << "\t";
        }
        os << "\n";
    }
    os << "\n";
    return os;
}



Matrix Matrix::operator*(const Matrix &c1) {
    if (this->cols_ == c1.rows_) {
        Matrix temp(rows_, c1.cols_);
        for (int i = 0; i < this->rows_; ++i) {
            for (int j = 0; j < c1.cols_; ++j) {
                for (int k = 0; k < c1.rows_; ++k) {
                    temp.data_[i][j] += this->data_[i][k] * c1.data_[k][j];
                }
            }
        }
        return temp;
    }
    return Matrix(0, 0);
}
Matrix Matrix::operator+(const Matrix &c1) {
    if (this->rows_ == c1.rows_ && this->cols_ == c1.cols_){
        Matrix temp(rows_, cols_);
        for (int i = 0; i < this->rows_; ++i) {
            for (int j = 0; j < this->cols_; ++j) {
                temp.data_[i][j] = this->data_[i][j] + c1.data_[i][j];
            }
        }
        return temp;
    }
    return Matrix(0, 0);
}
Matrix operator*(const Type &c1, const Matrix &m) {
    Matrix temp(m.rows_, m.cols_);
    for (int i = 0; i < m.rows_; ++i) {
        for (int j = 0; j < m.cols_; ++j) {
            temp.data_[i][j] = c1*m.data_[i][j];
        }
    }
    return temp;
}
Matrix Matrix::operator*(const Type &c1) {
    Matrix temp(rows_, cols_);
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            temp.data_[i][j] = c1*this->data_[i][j];
        }
    }
    return temp;
}
Matrix Matrix::operator*=(const Type &c1) {
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            this->data_[i][j] = c1*this->data_[i][j];
        }
    }
    return *this;
}
bool Matrix::operator==(const Matrix& c1) {
    if (c1.rows_ == this->rows_ and c1.cols_ == this->cols_){
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                if (this->data_[i][j] != c1.data_[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    else{
        return false;
    }
}

Matrix::~Matrix() {
    liberar();
}

bool Matrix::operator!=(const Matrix &c1) {
    if (c1.rows_ == this->rows_ and c1.cols_ == this->cols_){
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                if (this->data_[i][j] != c1.data_[i][j]){
                    return true;
                }
            }
        }
        return false;
    }
    else{
        return true;
    }
}




