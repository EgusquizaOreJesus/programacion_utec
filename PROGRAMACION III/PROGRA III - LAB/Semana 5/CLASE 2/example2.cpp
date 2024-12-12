#include <iostream>
#include <thread>

using namespace std;

void foo(int a, int& b){
    b = b + a;
}

int main(){
    int a=1, b=2;
    /// PODEMOS PASAR ARGUMENTOS A LA FUNCION, (el primero por valor y el segundo por referencia)
    std::thread t(foo, a, ref(b));
    cout << "b = " << b << endl;

    t.join();

    return 0;
}