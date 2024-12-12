#include "iostream"
#include "algorithm"
#include "cmath"

class powerInt{
    int exp;
public:
    explicit powerInt(int _exp):exp(_exp){};
    double operator() (int num) const{
        return pow(num,exp);
    }
};



using namespace std;
template<typename T>
class printArray{
    char end_;

public:
    explicit printArray(char c= ' '):end_(c){};
    void operator() (T x){
        cout << x << end_;
    }
};

int main(){
    int A[] = {1,2,3,4,5};
    for_each(A, A + 5, printArray<int>(' ')); // 1 2 3 4 5      // en el parentesis se pone los atributos puestos en el constructor
    cout << endl;

    transform(A, A + 5, A, powerInt(3));        // se pone entre parentesis los atributos puestos en el constructor
    for_each(A, A + 5, printArray<int>(' ')); // 1 8 27 64 125
    // PARA EL CASO DE ESTAS FUNCIONES, TENER EN CUENTA QUE EN CADA PARENTESIS DE LAS CLASES SE PONE
    // SU RESPECTIVO ATRIBUTO
    /// Y DICHAS FUNCIONES for_each and transform funcionan gracias a la sobrecarga del operator ()
    /// debido a que con esta sobrecarga dichos objetos se pueden trabajar como "funciones"


    return 0;
}