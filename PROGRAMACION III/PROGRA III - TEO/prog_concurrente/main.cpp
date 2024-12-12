#include <iostream>
#include "thread"

using namespace std;

/// PROGRAMACION CONCURRENTE
// Para implementar hilos, primero tengo que añadir una cabecera #include "thread"

// voy a crear tres funciones
void f1(){
    cout << "Hola F1" << endl;
}

void f2(){
    cout << "Hola F2" << endl;
}

void f3(){
    cout << "Hola F3" << endl;
}




void ejemplo_secuencial(){
    /// Si yo llamo a estas funciones de esta manera
// Se estaran llamando de manera secuencial:
    f1();
    f2();
    f3();
}
void ejemplo_hilo_simple(){
    /// Si yo lo quiesiera hacer en paralelo, necesitaria crear 3 hilos
    //El hilo se crea asi:
    thread t1;
    // Ahora a ese hilo vamos a asignarle una funcion, y para eso existen dos formas
    /// 1.  es crearlo asi
    t1 = thread(f1);
    /// 2. es crearlo defrente
    // thread t1(f1)

    /// OBS: ES URGENTE QUE UNA VEZ ASIGNADO AL HILO UNA FUNCION O CLASE, CUANDO TERMINE DE REALIZA SU TAREA
    /// URGENTE TENEMOS QUE NOTIFICARLE AL SISTEMA OPERTATIVO DOS POSIBILIDADES
    /// 1. La primera es que al finalizar la tarea me voy a unir al hilo principal y eso se hace poniendo la funcion join()
    /// 2. O otra posibilidad es que le digo que no me junto para ello uso la funcion detach().
    /// Pero una clara diferencia es que si hago detach(), el resultado no se va mostrar en el main, porque como no se junta
    /// con el hilo principal no lo muestra, pero puede que a veces si muestre o no.
    t1.join();
}
int sumar(int a, int b){
    return a+b;
}
void ejemplo_hilo_con_parametros(){
    /// Si a una funcion con parametros le quieres asignar un hilo, se realiza de la siguiente manera:
    // NO SE PUEDE COLOCAR ASI: thread t1(sumar(10,20))
    /// Se tiene que colocar la funcion y sus parametros con comas:
    thread t1(sumar,10,20);
    t1.join();
    /// PERO DICHO EJEMPLO NO ME MUESTRA NADA, NO ME SIRVE MUCHO
}
void sumar_ref(int a,int b, int& resultado){
    resultado = a+b;
}
/// OBS: Un problema que ocurre con los hilos es que no pueden trabajar con funciones sobrecargadas
/// una solucion: seria cambiarle el nombre para no tener problemas
/// otra solucion, si quisiera mantener el nombre, es usando lambda
void ejemplo_hilo_con_parametros_por_referencia(){
    int total = 0;
    /// OBS: cuando tengas parametros con referencia en tu funcion, indicar en el hilo que es por referencia,
    /// ya que ellos no lo reconocen.
    thread t1(sumar_ref,10,20, ref(total));
    t1.join();
    cout << total << endl;
}
void sumar(int a,int b, int& resultado){
    resultado = a+b;
}
/// Para solucionar el problema de utilizar la funcion y actualizar un valor, aqui viene otro tipo de llamada
/// utilizando lambda si me permite hacerlo
void ejemplo_hilo_con_parametros_lambda(){
    int total=0;
    /// como quiero actualizar el valor del total, coloco el total en los corchetes por referencia [&]
    /// y para este caso no tendra parametros, y en los {} pongo la funcion sumar asignado al total, y
    /// ya con eso actualizo el valor del total
    thread t1([&total](){
        total = sumar(10,20);
    });
    t1.join();
    cout  << total << endl;
}

/// Como hariamos con clases o struct
/// que dentro tengo un metodo, en este caso sumar
/// Y quiero ejecutar ese metodo en forma paralela
struct A{
    int sumar(int a,int b) const {
        return a+b;
    }
    void sumar_ref(int a,int b, int& resultado){
        resultado = a+b;
    }
};

/// Hay dos formas de hacerlo
/// La mas sencilla es usando lambda
void ejemplo_hilo_metodo_de_clase_lambda(){
    /// 1. Tengo que crear un objeto
    A a;
    int resultado = 0;
    /// Lyego creo un hilo y con lambda en el captcher [] pongo el objeto declarado constante o por referencia
    /// (dependiendo si es que modificaras el objeto o no), y tambien donde se guardara el resultado declarado por referencia
    /// [a, &resultado]  --> esto permite que dentro del cuerpo de lambda pueda acceder a estos dos valores, que son externos a lambda
    /// uno declarado para solo lectura y otro para lectura y escritura "&", si no le pongo "&", al objeto o funcion o elemento lo va definir como "constante"
    thread t1([a,&resultado](){
        resultado = a.sumar(10,20);
    });
    t1.join();
    cout  << resultado << endl;
}

/// Otra forma y más compleja sin utilizar lambda es:
/// Como puedo llamar a metodo sumar_ref sin usar lambda??
/// La sintaxis es:
// 1. llamar a la direccion del metodo (&A::method), y la direccion del objeto (&a)
// y luego los parametros, y si hay algun parametro por referencia colocar (ref) para que no lo lea constante
void ejemplo_hilo_metodo_de_clase(){
    A a;
    int result=0;
    thread t1(&A::sumar_ref,            // Direccion del metodo
              &a,                          // Direccion del objeto
              10,20, ref(result));      // PARAMETROS QUE DISPONE EL METODO
    t1.join();
    cout  << result << endl;
}

/// COMO HACER HILOS CON TEMPLATE??
/// En templates hay que tener cuidado porque tenemos que poner EXPLICITAMENTE EL TIPO

template<typename T>
auto restar(T a, T b){
    return a-b;
}

template<typename T>
void restar_ref(T a, T b, T& result){
    result = a-b;
}

/// ES NECESARIO ESPECIFICAR EXPLICITAMENTE EL TIPO DE VARIABLE CUANDO SE TRABAJA CON TEMPLATES
void ejemplos_hilos_template(){
    int total = 0;
    /// ESPECIFICAR TIPO, NO DEDUCE
    thread t1(restar_ref<int>,20,10, ref(total));
    t1.join();
    cout  << total << endl;

}
/// EN EL CASO QUE HAGA POR LAMBDA, NO ES NECESARIO ESPECIFICAR EXPLICITAMENTE SU TIPO DE VARIABLE A TRATAR
/// Porque el lambda si lo deduce
void ejemplos_hilos_template_lambda(){
    int total = 0;
    /// En lambda si deduce
    thread t1([&total](){
        total = restar(20,10);
    });
    t1.join();
    cout  << total << endl;

}

/// Y ESTO MISMO SE APLICA PARA CASOS DE CLASES O STRUCT DE TEMPLATE
/// Si yo quiero utilizar template de clases si lo quieres hacer sin lambda TENDRAS QUE ESPECIFICAR EXPLICITAMENTE SU TIPO
/// Si la clase tiene template especificar su tipo y para el metodo de dicha clase tambien

int main() {
    ejemplo_hilo_simple();
    ejemplo_hilo_con_parametros();
    ejemplo_hilo_con_parametros_por_referencia();
    ejemplo_hilo_con_parametros_lambda();
    ejemplo_hilo_metodo_de_clase_lambda();
    ejemplo_hilo_metodo_de_clase();
    ejemplos_hilos_template();
    ejemplos_hilos_template_lambda();
    return 0;
}
