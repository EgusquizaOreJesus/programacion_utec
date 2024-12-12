#include <iostream>
#include <thread>

/// RACE CONDITION
// se da cuando dos hilos van a competir para acceder a la variable y podrian acceder al mismo tiempo

using namespace std;

void add(int& s){
    ++s;
}

int main(){
    int s = 0;
    /// Podrian acceder a la variable s al mismo tiempo
    thread t1(&add, ref(s));
    thread t2(&add, ref(s));

    t1.join();
    t2.join();

    cout << s << endl;

    return 0;
}