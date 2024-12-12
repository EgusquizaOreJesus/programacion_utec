#include <iostream>
#include <future>
#include <thread>
#include <chrono>

using namespace std;
/// PARA QUE EL PROMISE PUEDA ENVIAR UN MENSAJE, EL PROMISE TENDRA QUE UTILIZAR UN METODO QUE SE LLAMA: "set_value"
/// Y el future recibe el mensaje a traves de un metodo que se llama: "get_value"
int f1(){
    int s = 0;
    for (int i=0; i<200000000; i++)
        s += 1;
    return s;
}

void foo(promise<int>* obj){
    int sum = 0;
    for (int i=0; i<100000000; i++)
        sum += 1;
    obj->set_value(sum);
}

int main(){
    promise<int> promise_obj;       /// Creamos un objeto "promise"
    future<int> fugure_obj = promise_obj.get_future();      /// Creamos un objeto "future" desde el objeto "promise"

    thread t1(foo, &promise_obj);

    cout << "Respuesta f1  = " << f1() << endl;
    cout << "Respuesta foo = " <<fugure_obj.get() << endl;
    t1.join();
    return 0;
}


