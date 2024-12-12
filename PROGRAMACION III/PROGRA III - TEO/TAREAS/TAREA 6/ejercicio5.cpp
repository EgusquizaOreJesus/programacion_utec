#include "stack"
#include "iostream"

using namespace std;

bool is_equation_balanced(const string& source){
    stack<char> separadores;
    string separador;
    int cont1 = 0;
    int cont2 = 0;

    for(auto& letra:source){
        if (letra == '[' || letra == '(' || letra == '{'){
            separadores.push(letra);
            cont1++;
        }
        if (letra == ']' || letra == ')' || letra == '}'){
            separadores.push(letra);
            cont2++;
        }
        if (letra == '['){
            separador +=  ']';
        }
        if (letra == '('){
            separador += ')';
        }
        if (letra == '{'){
            separador += '}';
        }
        if (letra == ']'){
            separador += '[';
        }
        if (letra == ')'){
            separador += '(';
        }
        if (letra == '}'){
            separador += '{';
        }
    }
    for(auto c: separador){
        cout << c << " ";
    }
    cout << endl;

    if (cont1 != cont2) {
        return false;
    }
    for (int j = 0; j < cont1; ++j) {
        if (separador[j] == '{' || separador[j] == '[' || separador[j] == '('){
            return false;
        }
    }
    for(auto& c: separador){
        if (separadores.top() != c){
            return false;
        }
        separadores.pop();
    }
    return true;
}

int main(){
    string text;
    getline(cin, text);
    cout << boolalpha << is_equation_balanced(text);

    return 0;
}