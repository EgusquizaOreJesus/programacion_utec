
/// Mutex
/** Podemos resolver fácilmente el problema de Race Condition utilizando un Mutex (Mutual Exclusion). Esta herramienta nos sirve para proteger un dato compartido entre threads:
///
///Antes de acceder al dato compartido cerramos (lock) el mutex asociado con el dato.
///Una vez que se terminó de procesar el dato abrimos (unlock) el mutex.
 **/

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex candado;

void add(int& s){
    candado.lock();     // Un thread a la vez actualiza el valor de s
    ++s;
    candado.unlock();
}

int main(){
    int s = 0;
    thread t1(&add, ref(s));
    thread t2(&add, ref(s));

    t1.join();
    t2.join();

    cout << s << endl;

    return 0;
}