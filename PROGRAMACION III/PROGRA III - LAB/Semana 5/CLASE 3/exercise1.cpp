#include "iostream"
#include "iomanip"
#include "algorithm"
#include "assert.h"
#include "thread"
#include "vector"
#include "list"
#include "deque"

using namespace std;

template<typename T, template<class ...>typename Container>
void sumar_containers(Container<T> v1, Container<T> v2,Container<T>& result){
    for (int i = 0; i < v1.size(); ++i) {
        *(next(result.begin(),i))  = *(next(v1.begin(),i)) + *(next(v2.begin(),i));
    }
}


template<typename T, template<class ...>typename Container>
void sumar_containers_PARTES(Container<T> v1, Container<T> v2,Container<T>& result,  int parte, int range){
    int start = (parte) * (v1.size()/range);
    int fin = (parte + 1) * (v1.size()/range);
    for (int i = start; i < fin; ++i) {
        *(next(result.begin(),i))  = *(next(v1.begin(),i)) + *(next(v2.begin(),i));
    }
}
template<typename T, template<class ...>typename Container>
void verificarSuma(Container<T> C){
    for (const auto& e: C)
        assert(e == 3);
}
using t = int;
void ejercicio1_con2HILOS_MIMETODO(){
/// inicializo un cronometro para ver cuanto demora de ejecutar:
    chrono::time_point<std::chrono::system_clock> t_inicio, t_final;

    vector<t> A(100000000, 1);
    vector<t> B(100000000, 2);
    vector<t> C(100000000);

    t_inicio = chrono::high_resolution_clock::now();    // start
    int range = 2;
    vector<thread> hilos(range);
    int i = 0;
    for(auto& hilo: hilos){
        hilo = thread(sumar_containers_PARTES<t,vector>,A,B, ref(C),i,range);
        i++;
    }
    for(auto& hilo:  hilos){
        hilo.join();
    }
    t_final  = chrono::high_resolution_clock::now();    // finish
    std::chrono::duration<double, std::milli> t = t_final - t_inicio;
    cout << "Tiempo = " << t.count() << "ms" << endl;       // visualizo el tiempo

    verificarSuma(C);
}
void ejercicio2_con2HILOSMETODOPROFE(){
    chrono::time_point<std::chrono::system_clock> t_inicio, t_final;

    vector<int> A(100000000, 1);
    vector<int> B(100000000, 2);
    vector<int> C(100000000);

    t_inicio = chrono::high_resolution_clock::now();

    thread t1(&sumar_containers_PARTES<t,vector>, A, B, ref(C), 0,2);
    thread t2(&sumar_containers_PARTES<t,vector>, A, B, ref(C), 1,2);

    t1.join();
    t2.join();

    t_final  = chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> t = t_final - t_inicio;
    cout << "Tiempo = " << t.count() << "ms" << endl;

    verificarSuma(C);
}
void ejercicio1_sinHILOS(){
    chrono::time_point<std::chrono::system_clock> t_inicio, t_final;

    vector<int> A(100000000, 1);
    vector<int> B(100000000, 2);
    vector<int> C(100000000);


    t_inicio = chrono::high_resolution_clock::now();

    sumar_containers(A,B,C);

    t_final  = chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> t = t_final - t_inicio;
    cout << "Tiempo = " << t.count() << "ms" << endl;

    verificarSuma(C);
}

int main(){
    //ejercicio1_con2HILOS_MIMETODO();
    //ejercicio2_con2HILOSMETODOPROFE();
    //ejercicio1_sinHILOS();
    return 0;
}