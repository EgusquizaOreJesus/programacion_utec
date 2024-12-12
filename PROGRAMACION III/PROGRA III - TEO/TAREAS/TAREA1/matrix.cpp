#include "matrix.h"
matrix::matrix(SizeType rows, SizeType cols) {
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

void matrix::liberar(){
    for (int i = 0; i < rows_; ++i) {
        delete[] data_[i]; //elimino filas --> porque cada fila es un puntero que apunta a un array
    }
    delete[] data_; //POR ULTIMO ELIMINO EL ARRAY DE PUNTEROS INICIAL
}

matrix::matrix(const matrix &other) {
    rows_ = other.rows();
    cols_ = other.cols_;
    data_ = new Type*[rows_];       // reservo primero el espacio de memoria
    for (int i = 0; i < rows_; ++i) {
        data_[i] = new Type[cols_];
        for (int j = 0; j < cols_; ++j) {
            data_[i][j] = other.data_[i][j];
        }
    }
}

matrix &matrix::operator=(matrix &&other) noexcept {
    using std::swap;
    swap(this->rows_, other.rows_);
    swap(this->cols_, other.cols_);
    swap(this->data_, other.data_);
    return *this;
}

SizeType matrix::rows() const {
    return rows_;
}

SizeType matrix::cols() const {
    return cols_;
}
matrix& matrix::operator=(const matrix& other) {
    if (this!=&other){
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
    }
    return *this;
}



//Matrix::Matrix() = default;

Type &matrix::operator()(int i_row, int i_col) {
    return data_[i_row][i_col];
}
Type matrix::operator()(int i_row, int i_col) const {
    return data_[i_row][i_col];
}

ostream &operator<<(ostream &os, const matrix &m) {
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



matrix matrix::operator*(const matrix &c1) {
    if (this->cols_ == c1.rows_) {
        matrix temp(rows_, c1.cols_);
        for (int i = 0; i < this->rows_; ++i) {
            for (int j = 0; j < c1.cols_; ++j) {
                for (int k = 0; k < c1.rows_; ++k) {
                    temp.data_[i][j] += this->data_[i][k] * c1.data_[k][j];
                }
            }
        }
        return temp;
    }
    return matrix(0, 0);
}
matrix matrix::operator+(const matrix &c1) {
    if (this->rows_ == c1.rows_ && this->cols_ == c1.cols_){
        matrix temp(rows_, cols_);
        for (int i = 0; i < this->rows_; ++i) {
            for (int j = 0; j < this->cols_; ++j) {
                temp.data_[i][j] = this->data_[i][j] + c1.data_[i][j];
            }
        }
        return temp;
    }
    return matrix(0, 0);
}
matrix operator*(const Type &c1, const matrix &m) {
    matrix temp(m.rows_, m.cols_);
    for (int i = 0; i < m.rows_; ++i) {
        for (int j = 0; j < m.cols_; ++j) {
            temp.data_[i][j] = c1*m.data_[i][j];
        }
    }
    return temp;
}
matrix matrix::operator*(const Type &c1) {
    matrix temp(rows_, cols_);
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            temp.data_[i][j] = c1*this->data_[i][j];
        }
    }
    return temp;
}
matrix matrix::operator*=(const Type &c1) {
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            this->data_[i][j] = c1*this->data_[i][j];
        }
    }
    return *this;
}
bool matrix::operator==(const matrix& c1) {
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

matrix::~matrix() {
    liberar();
    std::cout << "eliminado" << std::endl;
}

bool matrix::operator!=(const matrix &c1) {
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




