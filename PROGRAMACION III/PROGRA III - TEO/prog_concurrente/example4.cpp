#include "thread"
#include "iostream"
#include "vector"
#include "algorithm"
#include "numeric"
using namespace std;

void f1(){
    cout << "Mi primer hilo\n";
}

int f2(int a, int b){
    return a+b;
}
void f3(int a, int b, int &result){
    result = a+b;
}
void ejemplo_hilos_simples(){
    /// Los thread puedo crealos asi:
    thread t1;      // HILO VACIO

    /// o puedo crear una coleccion de ellos
    vector<thread> vh;      // COLECCION DE HILOS VACIOS

    /// COMO PUEDO ASIGNARLE??
    /// Primero tienes que tener una FUNCION
    // Puedo hacer ambas cosas simultaneamente
    // Puedo tan pronto crear el hilo asignarle una funcion (collabor) --> funcion, lambda, functor

    /// OBS: LAS FUNCIONES EN CASOS DE HILOS NO TIENEN QUE RETORNAR VALORES TIENEN QUE SER VOID
    /// Podria crear una funcion que retorne valores pero SERIA ABSURDO, porque el valor de retorno
    /// NO LO VOY A PODER CALCULAR, LOS HILOS NO PUEDEN CALCULAR EL VALOR DE RETORNO

    /// Asignando la funcion al hilo
    thread t2(f1);       // HILO CON SU FUNCION DETERMINADA
    thread t3(f1);
    // ----- podria poner codigo aqui etc
    // podria poner entre el hilo y su join codigo, NO HABRA PROBLEMA
    cout << "Esperando fin de hilo 2\n";


    /// pero NO OLVIDARSE DEFINIR SU PUNTO DE CONTACTO CUANDO ASIGNAS UNA FUNCION A UN HILO
    t2.join();  // OBLIGATORIO
    /// AL EJECUTARSE EL PROGRAMA, EL ORDEN EN EL QUE SE EJECUTEN PUEDE VARIAR
    /// NO HAY UN ORDEN DE SINCRONIZACION.
    /// OBS: Y como el hilo 3 tiene un detach(), esto provoca que el hilo 3 quiza se muestre o quiza NO
    /// NADA ME ASEGURA QUE SE MOSTRARA
    /// Tambien puedo crearlo de la siguiente forma:
    // .... mas codigo
    t3.detach();            // NO ESPERES EL HILO
}

void ejemplo_hilos_con_parametros(){
    thread t1(f2,10,20);
    t1.join();
    // Pero de esta manera NO TENGO FORMA DE OBTENER LA OPERACION,
    /// LA FORMA PARA HACERLO ES REFERENCIA UN VALOR QUE SERA LA RESPUESTA DE LA SUMA
    int resultado = 0;
    /// OBS: cuando trabajamos con hilos, y quieres modificar un valor,
    /// Asignale explicitamente que dicho valor es por referencia
    thread t2(f3,10,20, ref(resultado));
    // ... codigo
    /// ya con esto puedo visualizar la suma
    t2.join();
    /// obs: ES IMPORTANTE QUE EL VALOR MODIFICADO OSEA EL RESULTADO DE UN HILO DEBE EVALUARSE LUEGO DEL JOIN
    /// Porque como no hay un orden, si lo inserto arriba del join, puede que primero se ejecute el resultado y luego la funcion
    /// Y si es asi, me ejecutaria el valor inicial que era 0
    /// POR ESO ES MEJOR SACAR EL VALOR UNA VEZ QUE TERMINA EL HILO
    cout << resultado;
}
/// SUGERENCIA
/// No intenten que inmediatamente despues que han creado el hilo, inmediatamente hacer el join del hilo
/// porque eso hace que llame directamente a la funcion y es casi como si no tuvieramos un hilo
/// el join tiene que ejecutarse de forma no conjunta osea separada de la creacion  y asignacion de una funcion en un hilo



/// OTRA FORMA DE OBTENER EL VALOR, CON UNA FUNCION QUE RETORNE SERIA USANDO LAMBDA
void ejemplo_hilos_con_parametros_lambda(){
    /// USANDO FUNCION QUE RETORNA:
    int resultado1 = 0;
    thread t1([&resultado1](){
        resultado1 = f2(10,20);
    });
    t1.join();
    cout << resultado1;

    /// USANDO FUNCION VOID QUE MODIFICA VALOR:
    int resultado2 = 0;
    thread t2([&resultado2](){
        f3(10,20,resultado2);
    });
    t2.join();
    cout << resultado2;
}
class A{
public:
    int m1(int a, int b){
        return a+b;
    }
    void m2(int a, int b, int& result){
        result = a+b;
    }
};

void ejemplo_hilo_asignado_metodo(){
    A obj_a;
    int total=0;
    /// habilito el hilo
    thread t1(&A::m2,                   // DIRECCION DEL METODO
              &obj_a,                      // DIRECCION DEL OBJETO
              10,20, ref(total));       // PARAMETROS QUE DISPONE EL METODO
    t1.join();
    cout << total;
}

/// ESTA SOLUCION ES UTIL CUANDO QUIERO  CREAR UNA COLECCION DE HILOS
void ejemplo_hilo_vacio() {
    thread t1;

    /// ... PASA UN TIEMPO

    t1 = thread(f1);        // Asignamos funcion - Comienza ejecutar
    t1.join();
}
/// Que pasa cuando los hilos se crean pero no se le asignan una funcion?
/// - Primero dichos hilos no van a ejecutarse inmediatamente
/// - Van a crearse pero la ejecucion se realiza al momento que se le asigna una funcion
/// - ENTONCES YO PUEDO CREAR HILOS QUE ESTEN A LA ESPERA QUE SE LES ASIGNE UNA FUNCION

void sumar_rango(int start, int stop,vector<int>& datos, int& result){
    for (int i = start; i < stop; ++i) {
        result += datos[i];
    }
}

void ejemplo_multples_hilos(){
    vector<int> v1(100);    // vector de valores con 100 values
    generate(v1.begin(),v1.end(),[](){return rand()%20;});
    //for_each(v1.begin(),v1.end(),[](int x){cout << x << " ";});
    //cout << endl;

    /// En programacion regular
    /// Para sumar todo esos valores, uno lo haria asi:
    /// PERO LO QUE PASA AQUI ES QUE ESTAMOS RECORRIENDO TODO EL VECTOR DE FORMA SECUENCIAL
    int total = 0;
    for(auto& item: v1){
        total += item;
    }
    cout << total << endl;
    /// SI LO QUISIERA HACER DE FORMA PARALELA SE NECESITARIA IMPLEMENTAR UN VECTOR DE  HILOS
    /// DE TAL FORMA QUE TODA LA INFORMACION DEL VECTOR LO VAMOS A SUBDIVIDIR EN 4 HILOS
    /// El primer hilo va verificar del 0 al 24
    /// El segundo del 25 al 49
    /// El tercero del 50 al 74
    /// Y el ultimo del 75 al 99
    /// CON DICHO PROCESO LO QUE HACEMOS ES QUE EN VEZ DE PROCESARLO CON UN SOLO HILO DE FORMA SECUENCIAL
    /// LO HAREMOS CON 4

    /// Ahora podria crear los hilos manualmente:
    /// donde cada hilo trabaja con una parte del proceso
    vector<int> subtotal(4);
    thread t1(sumar_rango,0,25,ref(v1),ref(subtotal[0]));
    thread t2(sumar_rango,25,50,ref(v1),ref(subtotal[1]));
    thread t3(sumar_rango,50,75,ref(v1),ref(subtotal[2]));
    thread t4(sumar_rango,75,100,ref(v1),ref(subtotal[3]));
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    /// y luego los subtotales los sumamos
    /// accumulate lo que me permite es sumar los valores de un contenedor
    auto total_final = accumulate(subtotal.begin(),subtotal.end(),0);
    cout << total_final << endl;

}


/// OBS: RECUERDA
/// PARA UNA FUNCION: los parametros del hilo son:
/// 1. Nombre de la funcion
/// 2. Lista de parametros de funcoion

/// PARA UNA CLASE CON METODOS: los parametros del hilo son:
/// 1. La direccion del metodo
/// 2. La direccion del objeto
/// 3. La lista de parametros del metodo
int main(){
    srand(time(nullptr));
    ejemplo_vector_hilos();

    return 0;
}