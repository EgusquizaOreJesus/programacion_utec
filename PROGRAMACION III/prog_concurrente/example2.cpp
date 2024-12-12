#include "iostream"
#include "thread"
#include "vector"
#include "mutex"
#include "atomic"
#include "algorithm"
#include "numeric"
#include "cmath"

using namespace std;

/// Si quiero sumar los valores del 1 al 100 haria lo siguiente:
/// typename T = typename Iterator::value_type : Lo que hace es que cada iterador tiene un tipo de valor y ya con el template
/// LO GENERALIZO
template<typename Iterator, typename T = typename Iterator::value_type>
T sumar(Iterator start, Iterator stop){
    T total = 0;
    while (start!= stop){
        total += *start++;      // esto va copiar el valor al total, y va incrementar el start
    }
    return total;

}
template<typename Iterator, typename T = typename Iterator::value_type>
T sumar_ref(Iterator start, Iterator stop, T& result){
    result = 0;
    while (start!= stop){
        result += *start++;      // esto va copiar el valor al total, y va incrementar el start
    }
}
/// pero aqui ESTAMOS HACIENDOLO DE FORMA SERIAL
/// Es como si una sola persona lo estuviera haciendo todo
void ejemplo(){
    vector<int> v(100);
    /// Con la funcion "iota", le estoy diciendo al vector que agregue valores del 1 al 100
    iota(v.begin(),v.end(),1);
//    for(auto & i : v){
//        cout << i << " ";
//    }
//    cout << endl;
    cout << sumar(v.begin(),v.end());
}

/// SEGUNDO MODEL: PROGRAMACION PARALELA
/// Es mas eficiente que modelo de memoria compartida

/// SI QUISIERA HACERLO DE MANERA PARALELA
/// Osea dividir el trabajo en 10 personas
/// Tendria que a cada grupo asignarle un HILO
/// Y para no tener problemas de Race condition, voy a crear un casillero con 10 valores, para que
/// El resultado de cada hilo se coloque en cada casillero
/// Y este casillero va ser asignado a otro hilo y lo coloque al hilo principal
/// EN TOTAL HABRA 11 HILOS, pero el ultimo hilo que coloque es el COORDINADOR

///  ENTONCES HAREMOS ESTA FUNCION CON MULTIPLES HILOS
void ejemplo_multiples_hilos(){
    /// DATOS DE ENTRADA
    vector<int> v(103);
    // 1. Creare una variable con el numero de hilos que considerare:
    iota(v.begin(),v.end(),1);      // Autocompletar el contenedor a partir de 1 consecutivamente: 1, 2, 3, 4, ...


    /// REFERENCIAS O VARIABLES DE LOS HILOS
    int n_hilos = 10;
    int n_valores = v.size();
    // Luego pondre el rango de valores por cada hilo
    //int rango = n_valores/n_hilos;
    /// El rango me sirve para definir la carga que le tengo que dar a cada hilo,
    /// y le tengo que decir desde que valor hasta que valor tiene que tener
    /// Este rango es muy ambiguo, porque los datos tienen que ser exactos
    /// Si quisiera un rango para datos que puedan dar decimales
    /// Lo que hago primero es implementar un "ceil" para que basta que haya un minimo decimal lo redondee al siguiente
    /// Luego le pongo un static_cast en double al n_hilos, para que al hacerle la division me retorne un valor decimal
    /// Si implemento el rango de esta manera tendira un mejor control:
    int rango = ceil(n_valores / static_cast<double>(n_hilos));
    /// Ahora falta controlar el rango en el bucle for.


    // Vectores
    /// Creamos un vector de hilos
    vector<thread> v_hilos(n_hilos);           // Hilos
    /// Creamos un vector de resultado
    vector<int> v_resultado_hilos(n_hilos);    // Casillero donde cada hilo va almacenar su resultado - SUBTOTAL


    /// AQUI ESTAMOS CREANDO LOS 10 HILOS, Y CADA HILO LE ASIGNO UN RESULTADO
    auto it = v.begin();
    for (int i = 0; i < n_hilos; ++i) {
        /// Para controlar el rango, usaremos la distancia y diremos que si es menor al rango. El rango sera igual a dicha distancia
        /// Ya con eso estaria controlado el rango
        if (distance(it,end(v)) < rango){rango = distance(it, end(v));}


        /// Asignando a cada hilo su respectivo resultado de la funcion
        /// OBS: acuerdate que en caso de funciones template debo colocar explicitamente los parametros
        v_hilos[i] = thread(sumar_ref<vector<int>::iterator>,it, next(it,rango), ref(v_resultado_hilos[i]));
        // El it para estos casos es necesario pasarlo por copia y NO POR REFERENCIA
        // porque lo que esta pasando si fuera por referencia es UN RACE CONDITION
        // Ejm: Cuando tu estas en el aeropuerto, y hay una pantalla para ubicarte en que terminal te toca ir
        // Tenemos un solo recurso que es una pantalla pero tenemos muchas personas accediendo a ese recurso
        // Y no va a  haber ningun problema que todas esas personas vayan a ese recurso, PORQUE SOLO VAN A IR A VERLO
        // NO VAN A TOCARLO, NO PUEDEN HACERLO. ESE TIPO ES UN RACE CONDITION PORQUE TODOS COMPITEN EN QUERER IR A VERLO
        // PERO ES UN RACE CONDITION VENIGNO
        /// PERO EN ESTE CASO SI HAY UN RACE CONDITION CLARO, PORQUE ESTOY CAMBIANDO EL VALOR EN LA SIGUIENTE LINEA
        /// Y PARA EVITARLO HAY QUE PASARLO LOS VALORES POR COPIA Y NO POR REFERENCIA
        /// PORQUE SI LO PASARA POR REFERENCIA TENDRIA QUE CONTROLARLO CON lock / unlock
        it = next(it,rango);
    }

    /// Poniendo los join a cada hilo
    for (int i = 0; i < n_hilos; ++i) {
        v_hilos[i].join();
    }
    /// Ahora el coordinador, realizara la suma total cuando se halla asignado a cada hilo su respectivo valor
    // Suma total
    auto total = sumar(begin(v_resultado_hilos), end(v_resultado_hilos));

    /// MOSTRAR EL RESULTADO
    cout << total << endl;

    /// OBS: SI TE DAS CUENTA EN ESTOS CASOS SE ESTA EVITANDO LA SINCRONIZACION
    /// SI SE DA EL CASO ES SUGERIBLE EVITAR LA SINCRONIZACION EVITAR LOS MUTEX
}

/// AHORA DICHO EJEMPLO ES MUY AMBIGUO
// Porque el rango de valores tiene que ser igual para todo, y no lo controlo
// Si quisiera controlarlo
/// Una solucion simple, seria ponerle la funcion "ceil" al rango
/// ceil: lo que hace es que basta que haya un decimal en un numero, este lo redondea al siguiente, ejem: ceil(1.1) --> 2
/// ceil se implementa con la libreria cmath, y un static_cast en el n_hilos para que al dividirse me salga un valor decimal
/// Luego para controlar el rango, usaremos la distance que si es menor al rango, el rango sea igual a la distance
/// YA CON ESO DICHA FUNCION ESTA MEJOR GENERALIZADA PARA CUALQUIER RANGO DE VALORES


/// ACORDAR
/// El uso de hilos con clases y objetos
/// Es necesario llamar por referencia "&" cuando hagas thread
/// En terminos de eficiencia: En caso de funcion accedes directamente
/// Pero en el caso de un metodo requiere dos operaciones:
/// Primero identifica al objeto que va acceder
/// Luego accede a la direccion de su metodo




int main(){
    //ejemplo();
    ejemplo_multiples_hilos();

    return 0;
}