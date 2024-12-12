#include "iostream"
#include "thread"
#include "vector"
#include "mutex"
#include "atomic"



using namespace std;
/// funcion, que haga una operacion repetitiva 100 veces:
/// Este calculo es serial, sin programacion concurrente
void ejemplo1(){
    int x = 0;
    int n = 100;
    for (int i = 0; i < n; ++i) {
        x++;
    }
    cout << x << endl;
}
void incrementar(int& x){
    x++;
}

/// PERO VAMOS A HACER LO SIGUIENTE, ESTO MISMO LO VAMOS A HACER CON HILOS
/// CON PROGRAMACION CONCURRENTE
/// PRIMER MODELO: MEMORIA COMPARTIDA (uso de los lock / unlock)

/// cada incremento lo vamos a hacer en un hilo, cada hilo va autoincrementar el valor de x
/// entonces tendriamos n hilos
void ejemplo_varios_hilos(){
    int n_rep = 200;
    int n_hilos = 100;
    /// Para poder hacer 100 hilos vamos a crear un vector que contenga hilos
    vector<thread> v_hilos(n_hilos);
    /// OBS: los hilos no se puede copiar, siempre que quieras iterar por hilos hazlo por referencia
    /// OBS: Inicialmente los hilos aparecen vacios
    for (int i = 0; i < n_rep; ++i) {
        int x = 0;
        for (auto& h: v_hilos){     // Asignamos las funciones a los hilos
            /// ya inicializamos los hilos, ahora a cada hilo vamos a asignarle una funcion o tambien una clase o simplemente con lambda
            h = thread(incrementar, ref(x));
        }
        /// AHORA FALTARIA HACERLE SU join() a CADA HILO, ojo: SI TODOS LOS HILOS LES ASIGNAS UNA FUNCION EN UN BUCLE FOR
        /// LOS join LOS ASIGNAS EN OTRO BUCLE FOR, NO PONGAS JUNTO LA FUNCION Y EL JOIN EN UN UNICO FOR
        for (auto& h: v_hilos){     // Ejecucion de los joins
            h.join();
        }
        /// PERO EN ESTE EJEMPLO, VA SER MUY DIFICIL QUE FALLE PORQUE SOLAMENTE ESTAMOS HACIENDO UN CALCULO
        /// VAMOS A REPETIR ESTE PROCESO MULTIPLES VECES, PARA VER SI EN ALGUNO FALLA, LA RESPUESTA CORRECTA SERIA
        /// 100 SI NO ES ASI QUE IMPRIMA LOS VALORES ERRONEOS
        if (x==n_hilos){
            cout << x << " ";
        }
        else{
            cout << "ERROR" << " ";
        }
    }
    cout << endl;
}

/// PERO VA VER CASOS DONDE FALLE, Y PARA EVITAR QUE ESO PASE, SE SOLUCIONA CON LOS "MUTEX"

/// 1. Creamos un mutex de forma global
mutex mtx;
/// Y a la funcion que le estoy asignando un hilo, la bloqueo - protejo
/// Bloquea la operacion, para que todas las operaciones realizadas en dicha funcion se ejecuten como una sola
/// Y terminado de realizar todas sus operaciones de la funcion, desbloqueo la funcion

void incrementar_protegido1(int& x){
    mtx.lock();
    x++;
    mtx.unlock();
}

/// PERO DICHA FUNCION PUEDE LLEGAR A FALLAR, PUEDE VER EL CASO EN EL QUE EL ARCHIVO SE BLOQUEE INDEFINIDAMENTE


/// PRIMERA SOLUCION
/// Para evitar aquello: hacemos que el bloqueo y desbloqueo sea automatico a la hora de iniciar la funcion y terminarla
/// Para ello hacemos uso de la operacion: "lock_guard (nombre) (mutex)"

void incrementar_protegido_automatico(int& x){
    lock_guard lg(mtx);
    x++;
}
/// Pero lo malo del lock_guard es que no me permite desbloquearlo, osea si yo quisiera que lock_guard se debloquee automaticamente
/// Si es que me olvido de desbloquearlo, pero que me permita tambien desbloquearlo o bloquearlo  yo mismo
/// Osea si yo tuviera en mi funcion otras instrucciones, y yo quiero que se desbloquee una cierta linea
/// Para que las otras instrucciones no queden bloqueadas, YO NO PUEDO DESBLOQUEARLO con el lock_guard() PARA ELLO UTILIZO OTRA ESTRUCTURA


/// SEGUNDA SOLUCION

/// USAREMOS el "unique_lock", que su ventaja es que me permite desbloquear si es que quiero
/// a diferencia del otro, este me permite desbloquearlo en  cualquier linea que quiera, o tambien me permite
/// que al iniciar dicha operacion, no lo bloquie todavia y lo bloquie desde cierta linea eso se logra poniendo en el unique_lock --> "defer_lock"
/// Y tambien tiene la ventaja, que si me olvido desbloquearlo, lo desbloquea automaticamente, ES MUCHO MAS FLEXIBLE
/// sintaxis unique_lock (nombre)(mutex, ...)

void incrementar_protegido_uniquelock(int& x){
    unique_lock ul(mtx, std::defer_lock);
    /// con defer_lock
    /// ME PERMITE ASIGNAR OPERACIONES QUE NO QUIERO QUE ESTEN BLOQUEADAS
    // instrucciones (libres)
    /// Y ya recien desde una linea bloquearlas
    ul.lock();
    x++;
    // SI ME OLVIDO DESBLOQUEARLO, SE DESBLOQUEA AUTOMATICAMENTE
}

void ejemplo_protegido_mutex(){
    int n_rep = 200;
    int n_hilos = 100;
    vector<thread> v_hilos(n_hilos);
    for (int i = 0; i < n_rep; ++i) {
        int x = 0;
        for (auto& h: v_hilos){     // Asignamos las funciones a los hilos
            h = thread(incrementar_protegido_uniquelock, ref(x));
        }
        for (auto& h: v_hilos){     // Ejecucion de los joins
            h.join();
        }
        if (x==n_hilos){
            cout << x << " ";
        }
        else{
            cout << "ERROR" << " ";
        }
    }
    cout << endl;
}

/// OBS: cuando estoy realizando operaciones sencillas como en estos ejemplos, se sugiere usar "atomic"
/// PERO SI SON COMPLEJAS SE RECOMIENDA USAR lock, unique lock, etc. que son estructuras de bloqueo GENERICO

void ejemplo_atomic(){
    int n_rep = 200;
    int n_hilos = 100;
    vector<thread> v_hilos(n_hilos);
    for (int i = 0; i < n_rep; ++i) {
        atomic<int> x = 0;          // Lo que hago es reemplazar la variable que se va actualizando por "atomic"
        /// y declarando atomic, dicha variable NO NECESITA SER BLOQUEADA
        for (auto& h: v_hilos){     // Asignamos las funciones a los hilos
            /// Entonces si yo quisiera actualizar su valor de dicha variable atomica
            /// Lo hago con un lambda
            h = thread([&x](){x++;});
        }
        for (auto& h: v_hilos){     // Ejecucion de los joins
            h.join();
        }
        if (x==n_hilos){
            cout << x << " ";
        }
        else{
            cout << "ERROR" << " ";
        }
    }
    cout << endl;
}



int main(){
    /// AL CREAR VARIOS HILOS REALIZANDO OPERACIONES, PUEDE OCURRIR ERRORES
    ejemplo_varios_hilos();
    cout << endl;
    /// PARA SOLUCIONARLO USAMOS mutex, Y BLOQUEAMOS Y DESBLOQUEAMOS OPERACIONES
    ejemplo_protegido_mutex();
    cout << endl;
    /// SI SON OPERACIONES SENCILLAS USAR NOMA EL atomic
    ejemplo_atomic();
    cout << endl;


    return 0;

}