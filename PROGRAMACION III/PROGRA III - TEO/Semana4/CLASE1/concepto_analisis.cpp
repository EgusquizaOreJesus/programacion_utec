/// COMPLEJIDAD ALGORITMICA

/// Los contenedores son como maquinas virtuales
//  que se comportan eficientemente bajo ciertas condiciones
/// El uso eficiente de las condiciones se le llama como: "complejidad algoritmica"

/// El analisis de complejidad algoritmica
/// Nos ayuda a saber el uso eficiente de los recursos, recurso tiempo y recurso espacio
/// Tengo que evaluar el tiempo y el espacio
/// El tiempo se ve reflejado en el uso del procesador
/// El espacio se ve reflejado en el uso de la memoria
/// Y NOSOTROS DEBEMOS SABER CALCULAR, CUAL ES SU COMPLEJIDAD ALGORITMICA DE TIEMPO Y ESPACIO

/// Hay algoritmos que se comportaban con complejidad constante: O(1) Complejidad cste

/// Hay algoritmos que cuando aumento la cantidad de datos aumenta el tiempo de ejecucion de manera lineal: O(n) Complejidad n

/// Hay algoritmos como el bubble_sort, va aumentando y cada vez va aumentando más y más el tiempo: O(n^2) Complejidad n al cuadrado

/// Hay algoritmos como busqueda binaria, que tiene complejidad: O(log(n)) Complejidad logaritmo de n en base 2

/// Entonces ese numero es el que define la complejidad

//// obs: ESA INFORMACION NO SOLAMENTE ESTA EN LOS ALGORITMOS TAMBIEN ESTA EN CONTENEDORES
/// Viendo las operaciones que se puede hacer en cierto contenedor, se puede saber si dicha operacion es eficiente o no
/// Ejm: con el caso del vector
/// Su complejidad para el push_back es constante, en cambio para el insert es lineal
/// DANDO A ENTENDER QUE EL push_Back es mas eficiente que el insert en un vector
/// LO QUE SE COMPRUEBA QUE EL VECTOR ES MUY EFICIENTE PARA INSERTAR ELEMENTOS AL COMIENZO, PERO PARA INSERTAR EN CUALQUIER LUGAR
/// ES MENOS EFICIENTE
