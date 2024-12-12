#include "function1.h"

using namespace std;

int main(){
    vector<int> primos_2Cifras = vector_primo_dsCrifras();
    print_vector(primos_2Cifras);

    int n;
    cout << "tamano del array:";
    cin >> n;
    cout << endl;

    //creando array dinamico de tamaño n
    int* arr_primos = new int[n];
    for (int i = 0; i < n; ++i) {
        arr_primos[i] = primos_2Cifras[rand()%primos_2Cifras.size()];
    }

    // imprimir
    print_array(arr_primos,n);

    // ordenando los numeros
    insertion_sort(arr_primos,n);
    print_array(arr_primos,n);
    delete[] arr_primos; //siempre eliminar el array dinamico
    return 0;
}
