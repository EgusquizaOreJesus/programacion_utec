#include "iostream"
#include "map"

using namespace std;

/// CONTENEDORES MAP
/// Implementar un contador de palabras utilizando el contenedor map.

// Inicializar un mapa vacio
// map<string, int> word_count;

// Inicializar un mapa con elementos
// map<string, int> word_count = {{“Hola”,1},{“Mundo”,1}};

int main(){
    /// Un contenedor "map" con "keys" de tipo string y con "values" de tipo int
    map<string, int> word_count;
    // string: aqui almacenaremos una palabra
    // int: aqui el contador
    string word;

    while (getline(cin,word)){      //aqui lo que hacemos es obtener una palabra por linea
        if (word.begin()==word.end())      // SI NO INGRESA NINGUN SIMBOLO/PALABRA, SALIMOS DEL BUCLE
            break;
        // Si la palabra no se encuentra en el contenedor se creara un nuevo elemento con "key"
        // igual a "word" y un "value" igual a 0. Luego este valor se incrementa en 1 en 1 por cada vez que se encuentra la misma palabra

        // Si la palabra ya existe en el contenedor, su valor se incrementa en 1. Esto me indica las veces que se repite la palabra
        word_count[word]++;
    }

    /// Iteramos a traves del contenedor map
    for (const auto &w: word_count){
        cout << w.first << ": ";        // Imprimimos el key
        cout << w.second;               // Imprimimos el value
        cout << (w.second > 1 ? " veces": " vez") << endl;
    }

    return 0;
}