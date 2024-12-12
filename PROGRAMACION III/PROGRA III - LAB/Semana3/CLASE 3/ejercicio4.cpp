#include "iomanip"
#include "iostream"
#include "set"
#include "algorithm"
#include "random"

using namespace std;
template<class T>
class printContainer{
private:
    char _end;
public:
    printContainer(char c = ' '): _end(c) {}
    void operator() (T x){
        cout << setw(3) << x << _end;
    }
};
void bubbleSort(int A[], int n){
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (A[j] > A[j + 1])
                swap(A[j],A[j+1]);
}

int main() {
    int A[300];
    int size = sizeof(A) / sizeof(A[0]);

    /// GENERANDO UN ARRAY ESTATICO CON 100 ELEMENTOS ALEATORIOS CON LA FUNCION generate
    generate(A, A + size, []() { return rand() % 31; });

    /// ITERANDO E IMPRIMIENDO LOS VALORES DE UN CONTENEDOR CON LA FUNCION for_each
    cout << "\nNumeros desordenados:" << endl;
    for_each(A, A + size, [](int x) { cout << setw(3) << x << " "; });
    cout << endl;

    /// Tambien se hubiera podido con:
    //for_each(A,A+size,printContainer<int>());

    bubbleSort(A, size);
    cout << "\nNumeros ordenados repetidos:" << endl;
    // usando la clase template:
    for_each(A, A + size, printContainer<int>());
    cout << endl;

    /// INSERTANDO CADA VALOR EN EL SET, SE USARA UN CONTENEDOR SET
    /// ya que dicho contenedor no CUENTA LOS VALORES REPETIDOS

    /// OTRA FORMA DE INSERTAR LOS VALORES DEFRENTE, SIN TENER QUE USAR UN BUCLE ES ASI:
    set<int> s(A,A+size);
    cout << "\nNumeros ordenados sin repeticiones: " << endl;
    for_each(s.begin(),s.end(), printContainer<int>());





    return 0;
}