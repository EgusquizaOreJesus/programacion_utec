#include "iostream"
#include "iomanip"
using namespace std;

using Type = double;

template<typename T>
void sum_matriz(T m1, T m2, size_t row, size_t col){
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << setw(8);
            cout << m1[i][j] + m2[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

template<typename T>
void print_matriz(T m1, size_t row, size_t col){
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << setw(8);
            cout << m1[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

//SOBRECARGA A LA FUNCION, PARA SUMAR UNA MATRIZ Y UN ESCALAR SI SE DA EL CASO
template<typename T>
void sum_matriz(T m1, double k, size_t row, size_t col){
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << setw(8);
            cout << m1[i][j] + k;
        }
        cout << endl;
    }
    cout << endl;
}

template<typename T>
void liberar_memory(T m1,size_t row, size_t col){
    //liberar cada fila
    for (int i = 0; i < row; ++i) {
        delete[] m1[i];
    }
    // liberar el array de punteros
    delete[] m1;
}

int main(){
    size_t row;
    size_t col;
    cout << "Filas:";
    cin >> row;
    cout << "Columnas:";
    cin >> col;

    srand(time(nullptr));
    // Creando primera matriz
    Type** m1 = new Type*[row];
    for (int i = 0; i < row; ++i) {
        m1[i] = new Type[col];
        for (int j = 0; j < col; ++j) {
            Type a = (rand()%499 + 1);
            m1[i][j] = a/10;
        }
    }
    print_matriz(m1,row,col);

    // Creando segunda matriz
    Type** m2 = new Type*[row];
    for (int i = 0; i < row; ++i) {
        m2[i] = new Type[col];
        for (int j = 0; j < col; ++j) {
            Type a = (rand()%499 + 1);
            m2[i][j] = a/10;
        }
    }
    print_matriz(m2,row,col);
    sum_matriz(m1,m2,row,col);

    double k;
    cout << "Valor escalar:";
    cin >> k;
    sum_matriz(m1,k,row,col);
    sum_matriz(m2,k,row,col);

    //LIBERANDO MEMORIA
    liberar_memory(m1,row,col);
    liberar_memory(m2,row,col);

    return 0;
}