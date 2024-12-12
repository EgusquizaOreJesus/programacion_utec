#include "function2.h"

using namespace std;

int main(){
    srand(time(nullptr));
    int n, m;
    cout << "n:";
    cin >> n;
    cout << "m:";
    cin >> m;
    int** matriz = crear_matriz(n,m);
    print_matriz(matriz,n,m);
    cout << "EJERCICIO1" << endl;
    float promedio = promedio_matriz(matriz,n,m);
    cout << "Promedio de la matriz: " << promedio << endl;
    cout << endl;
    // EJERCICIO2
    cout << "EJERCICIO2" << endl;
    int** matriz1 = crear_matriz(n,m);
    int** matriz2 = crear_matriz(n,m);
    print_matriz(matriz1,n,m);
    print_matriz(matriz2,n,m);
    cout << "LA SUMA DE AMBAS MATRICES ES: " << endl;
    print_suma(matriz1,matriz2,n,m);

    liberar(matriz,n);
    liberar(matriz1,n);
    liberar(matriz2,n);
    return 0;
}