#include "iostream"
#include "set"
#include "map"

using namespace std;

/// CONTENEDOR SET
/// Implementar un contador de palabras sin contar conectores.

// Inicializar un set vacio:
// set<int> s;

// Inicializar un set con elementos:
// set<int> s = {3,4,5,6};


int main(){
    map<string, int> word_count;
    string word;

    set<string> stop_words = {"en","y"};        // Un set con dos elementos

    while (getline(cin,word)){
        if (word.begin()==word.end())
            break;
        // Buscamos la palabra dentro del conjunto
        /// Quiere decir que si no se encuentra la palabra dentro de stop_words, entonces se va contar
        /// Ya que lo unico que no contara es si se encuentra alguna palabra del conjunto de elementos del set "stop_words"
        if (stop_words.find(word) == stop_words.end())
            word_count[word]++;
    }

    for (const auto &w: word_count){
        cout << w.first << ": ";
        cout << w.second;
        cout << (w.second > 1 ? " veces": " vez") << endl;
    }

    return 0;
}