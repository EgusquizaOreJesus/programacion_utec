#include <iostream>
#include "funciones_1.h"
#include "funciones_2.h"

using namespace std;

// Si quiero usar las funciones creadas, incluyo sus .h en el main

int main() {
    // En los .cpp --> se definen
    // En los .h   --> se declaran

    int total_1 = sumar(10,20);
    int total_2 = restar(40, 20);
    cout << total_1 << endl;
    cout << total_2 << endl;

    // Si ejecuto este proceso de compilacion
    // Lo que va a ocurrir es que va a hacer una serie de procesos que no los veo
    // pero lo esta ejecutando, pero al final va generar un archivo en "cmake"
    // que se llama el mismo nombre del proyecto pero .exe "CLASE_I.exe"
    // Este archivo de aqui es el que resume todo lo que hallas compilados
    // El resultado final
    // Este archivo lo puedes pasar a cualquier lugar y se podra ejecutar normalmente,
    // a nivel de consola se podra ejecutar

    return 0;
}
