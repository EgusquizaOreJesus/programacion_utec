#include "map"
#include "iostream"

using namespace std;

/// OBS:
/// Cuando escribes:
///   char selection{};
//    cin >> selection;
//    return toupper(selection);
/// El compilador realiza una conversion implicita del tipo int al tipo char
/// Para evitar la advertencia, haga una conversion explicita:
//  char get_selection() {
//    char selection{};
//    cin >> selection;
//    return char( ::toupper( ( unsigned char )selection) );
//
// }
// o tambien:
// return toupper(selection, std::locale());

int main(){
    map<string,int> word_count;
    string word;



    while(getline(cin,word)){
        if (word.end() == word.begin()){ break;}

        /// Para hacer que las palabras escritas en mayusculas se vuelvan minusculas
        /// Hacemos uso de tolower, pero dicha funcion, solamente funciona para "char"
        /// Un string es una cadena de char, asi que vamos a recorrer cada palabra con un bucle for
        /// Pasando por referencia cada palabra para se cambien a minusculas cada una
        for(char& c: word){
            c = tolower(c,std::locale());
            // este tolower devuelve el mismo tipo que la entrada
        }
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