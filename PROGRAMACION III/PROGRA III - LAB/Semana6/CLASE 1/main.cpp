#include <iostream>
/// FUTURE
/**
 * Si un thread necesita esperar por un evento, podemos hacerlo a través de un objeto future. Este mecanismo sirve para trabajar con tareas asíncronas.

 * @return
 */
// Internamente al crear un objeto future:
//
//Almacena un valor que será asignado en el futuro.
//Este provee el método get() para poder acceder al valor.

/// PROMISE
/**
 * Un objeto de tipo promise asegura establecer un valor en el futuro. Es por ello que, cada objeto promise tiene asociado un objeto future.

 * @return
 */
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
