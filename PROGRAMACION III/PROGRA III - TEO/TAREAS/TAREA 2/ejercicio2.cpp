#include <fstream>
#include "iostream"
#include "vector"
#include "list"
#include "iomanip"
#include "typeindex"

#include <typeinfo>

using namespace std;

template<typename ForwardIterator>
void print(ForwardIterator primero, ForwardIterator ultimo, ostream &outs, const string &T) {
    for (; primero != ultimo; ++primero) {
        if (*primero == *prev(ultimo,1)){cout << *primero;}
        else{
            cout <<  *primero << T;
        }
    }
    cout << endl;
}

template<typename ForwardIterator>
void print(ForwardIterator primero, ForwardIterator ultimo, ofstream &os, string T) {
    if (os.is_open()){
        for (; primero != ultimo; ++primero) {
            if (*primero == *prev(ultimo,1)){os << *primero;}
            else{
                os <<  *primero << T;
            }
        }
        os.close();
    }
}

int main(){
    // Vector
    std::vector<int> vec = {10, 20, 30, 40, 50, 60};
// Imprimir en consola
    print(begin(vec), end(vec), std::cout, "-");
// Grabarlos en un archivo
    std::ofstream file("out.txt");
    print(begin(vec), end(vec), file, "|");
// Imprimir la mitad de valores
    auto last_it = next(begin(vec), vec.size() / 2);
    print(begin(vec), last_it, std::cout, "-");
    return 0;
}