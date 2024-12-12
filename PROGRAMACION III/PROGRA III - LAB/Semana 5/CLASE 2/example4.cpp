#include <iostream>
#include <thread>

using namespace std;

void foo(){
    cout << "Funcion 'foo()'\n";
}

int main(){
    std::thread t(&foo);
    cout << "Funcion 'main()'\n";

    t.detach(); ///Podemos hacer que el nuevo thread se ejecute libremente (daemon) con detach()
    /// Estos threads se ejecutan en segundo plano y no más se puede unir

    return 0;
}