// ... op pack = ((((arg1)-arg2)-arg3)-arg4)-arg5
//pack op ... = arg1-(arg2-(arg3-(arg4-(arg5))))

// CONSTRUCORES
//matrix(const matrix& other);                    // CONSTRUCTOR COPIA

/*
//COPY
matrix::matrix(const matrix &other) {
    rows_ = other.rows();
    cols_ = other.cols_;
    data_ = new Type*[rows_];
    for (int i = 0; i < rows_; ++i) {
        data_[i] = new Type[cols_];
        for (int j = 0; j < cols_; ++j) {
            data_[i][j] = other.data_[i][j];
        }
    }
}
 */
//matrix(matrix&& other) noexcept;                // CONSTRUCTOR MOVE

/*
victor::victor(victor &&other)  noexcept {    //Mover el contenido de otro en el actual(this)
    size_ = other.size_;
    data = other.data;   //Copia la referencia de la data en el nuevo victor
    // Pero luego IMPORTANTE
    // TIENES DE QUE HACER LA DESHABILITACION DEL other, porque todo se movio al actual (this)
    // other tiene que quedar vacio, other ya no tiene que acceder a el
    // Para deshabilitarlo haces:
    other.size_ = int {};
    other.data = nullptr;
}

 */
//matrix& operator=(const matrix& other);         // OPERADOR DE ASIGNACION COPIA
/*
victor &victor::operator=(const victor &other) {
    if (this == &other){return *this;}
    // Ya una vez verificado que no son la misma direccion. hago el mismo proceso que el constructor
    size_ = other.size_;
    //OBS: HAY QUE TENER CUIDADO, PORQUE EN ESTE CASO
    // ya EXISTE UNA CLASE ACTUAL VICTOR, Y UN OTHER, AMBOS EXISTEN
    // ENTONCES ANTES DE COPIAR EL CONTENIDO DE OTHER EN EL ACTUAL,
    // PRIMERO TENGO QUE LIBERAR SU MEMORIA DEL ACTUAL, PARA EVITAR ERRORES
    delete[] data;  // LIBERO SU MEMORIA PARA LUEGO PODER RESERVAR MEMORIA PARA COPIAR EL CONTENIDO DE OTHER EN EL ACTUAL
    data = new int[size_];
    copy(other.data,other.data + size_, data);
    return *this;
}
 */

//matrix& operator=(matrix&& other) noexcept;     // OPERADOR DE ASIGNACION MOVE
/*
victor &victor::operator=(victor &&other)  noexcept {
    if (this == &other){return *this;}
    delete[] data;
    size_ = other.size_;
    data = other.data;
    //OBS: HAY QUE TENER CUIDADO, PORQUE EN ESTE CASO
    // ya EXISTE UNA CLASE ACTUAL VICTOR, Y UN OTHER, AMBOS EXISTEN
    // ENTONCES ANTES DE COPIAR EL CONTENIDO DE OTHER EN EL ACTUAL,
    // PRIMERO TENGO QUE LIBERAR SU MEMORIA DEL ACTUAL, PARA EVITAR ERRORES
    other.size_ = int {};
    other.data = nullptr;
    return *this;
}
 */

// SOBRECARGA A OPERADORES
//Type& operator() (int i_row, int i_col);                    // se comporta como un set
//Type operator() (int i_row, int i_col) const;               // se comporta como un get
//friend ostream& operator<<(ostream& os, const matrix& m);
//bool operator==(const matrix& c1);
//bool operator!=(const matrix& c1);
//matrix operator*(const matrix& c1);
//matrix operator*(const Type& c1);
//matrix operator*=(const Type& c1);
//friend matrix operator*(const Type& c1,const matrix& m);
//matrix operator+(const matrix& c1);

/*
TEMPLATE DE TEMPLATE


template<template<typename > typename C,typename T>
void print_poly(C<T> coef){
    int size = distance(coef.begin(), coef.end())-1;
    int exp  = size;
    for(auto elemento: coef){
        if (elemento > 0 and exp!=size)
            cout << " + ";
        if (elemento != 0 && elemento != 1){
            cout<<elemento;
        }
        if (exp == 1){
            cout<<"x";
        }
        if (exp > 0 && exp != 1 && elemento>0)
            cout<<"x^"<<exp;
        exp--;
    }
    cout << endl;
}
int main(){
    vector<int> v1{3,2,7};
    vector<float> v2{0.2,-3.2, 1.1};
    list<float> l1{2.1,-2.2, 4.4, 4.1};

    print_poly(v1); // Resultado: 3x^2+2x^1+7
    print_poly(v2); // Resultado: 0.1x^2-3.2x^1+1.1
    print_poly(l1); // Resultado: 2.1x^3-2.2x^2+4.4x^1+4.1
}
 */