#include <iostream>
#include <thread>       // Necesesario para trabajar con los threads en la biblioteca estandar de C++

using namespace std;
void foo(){
    std::cout << "funcion 'foo'\n";
}
// Para el thread incial, LA FUNCION ES EL main()
int main(){
    // Para el objeto std::thread llamado t, su funcion inicial seria foo()
    std::thread t(&foo);        /// Cada thread debe tener una funcion inicial, donde comienza la ejecucion
/// Despues de haberse lanzado el nuevo thread (t), el thread inicial sigue ejecutandose
    cout << "funcion main\n";
    t.join();       /// permite que el thread inicial (main())espere al thread asociado con t.


    return 0;
}


