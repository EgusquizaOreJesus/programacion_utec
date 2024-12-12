#include "iostream"
#include "thread"
#include "vector"
#include "mutex"
#include "atomic"
#include "algorithm"
#include "numeric"
#include "cmath"
#include "future"

using namespace std;
/// TERCER MODELO: POR MENSAJERIA
/// Se hace a traves de señales, yo le comunico al otro hilo que termine
/// y luego que le toque a el, algo asi
/// entre los hilos tengo que habilitar un canal de comunicacion


// PROMISE & FUTURE
/// Para implementar el promise and future necesitar incluir la libreria "future"

/// Ya creado el promise y future, para poder utilizarlo vamos a crear un metodo
/// que va recibir como parametro un promise

void producer(promise<string> prm){
    /// PARA QUE EL PROMISE PUEDA ENVIAR UN MENSAJE, EL PROMISE TENDRA QUE UTILIZAR UN METODO QUE SE LLAMA: "set_value"
    /// Y el future recibe el mensaje a traves de un metodo que se llama: "get_value"
    prm.set_value("Hola !!!");      // ENVIA EL MENSAJE
    cout << "FIN DEL PRODUCTOR" << endl;
}

void consumer(future<string> ftr){
    cout << ftr.get() << endl;
}


void ejemplo_mensajeria(){
    /// PRIMER PASO: crear el promise y su correspondiente future
    /// El promise tiene que tener la informacion que va a enviar y recibir el future
    /// en los parametros tipo template: defines el tipo de dato que vas a enviar
    promise<string> prm_1;  // Lo que va hacer es enviar informacion de tipo string

    /// Luego creo un future a partir de ese promise que va recibir un valor de tipo string
    /// Y dicho future tengo que juntarlo al promise
    future<string> fut_1 = prm_1.get_future();

    /// Una vez enviado el mensaje por el promise, este future lo va a recibir
    /// El promise debe enviar el mensaje al hilo principal

    /// Para ello, primero creo un hilo, donde use la funcion producer, y pongo el promise de donde envie el mensaje
    /// Como dicho promise no lo voy a necesitar más, entonces lo muevo
    thread T2(producer, std::move(prm_1));           // entra en los hilos
    /// ya con eso ahora imprimo el valor del future
    cout << fut_1.get();        // El future lee el mensaje

    T2.join();

    /// entonces los pasos serian
    // 1. ENVIO EL MENSAJE
    // 2. ENTRA EN LOS HILOS EL MENSAJE
    // 3. LEO EL MENSAJE
    // 4. PONGO JOIN A LOS HILOS
}

/// ahora podriamos tener dos funciones una que produzca y otra que consuma. En este caso necesitaria dos hilos:
/// Los creo en el hilo principal
/// Pero luego se los transfiero a dos hilos, uno que va recibir el "promise" con su producer
/// Y el otro que va recbir con su consumer o client el "future"
void hilos_mensajeria2(){
    promise<string> prm_1;
    future<string> ftr_1 = prm_1.get_future();

    thread t1(producer, std::move(prm_1));
    thread t2(consumer, std::move(ftr_1));
    t1.join();
    t2.join();
}

/// Una desventaja de usar hilos de esta manera de forma basica:
// ES EL PROBLEMA DE QUE LOS HILOS NUNCA RETORNAN VALORES, pero ESO NO PASA CON LOS async

/// QUE UTILIDAD TIENE AQUELLO:
// Es una estructura adicional que se llama "async", que me permite devolver valores a diferencia de un hilo
// osea
/// EN UN HILO NO ES POSIBLE PONER FUNCIONES QUE RETORNEN VALORES
int sumar(int a, int b){
    return a+b;
}
/// SI LO IMPLEMENTO EN UN HILO NO FUNCIONARIA
/// PARA ELLO UTILIZO EL "async", porque puedo recibir el resultado en un future
/// Su sintaxis es muy similar al thread, pero aqui si puedo retornar valores
/// Y TAMPOCO NECESITO JOIN COMO EN EL CASO DEL HILO, SOLAMENTE DEFINO EL RESULTADO
/// Y LO QUE DEVUELVE EL RESULTADO ES UN FUTURE

void ejemplo_async(){
    /// SI ME PERMITE ASIGNAR A UNA VARIABLE EL VALOR QUE RETORNA ASYNC, A DIFERENCIA DEL THREAD
    auto resultado = async(sumar,10,20);        // Resultado es un future.
    /// Y ACUERDATE QUE EL FUTURE PARA QUE PUEDA RECIBIR LA INFORMACION NECESITA UN get
    cout << resultado.get() << endl;

    /// Y FUNCIONA MUCHO MAS SENCILLO QUE EL USO DE HILOS THREAD

}

int main(){
    hilos_mensajeria2();
    //ejemplo_async();

    return 0;
}