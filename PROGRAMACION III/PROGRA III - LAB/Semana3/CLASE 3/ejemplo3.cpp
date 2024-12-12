#include "iostream"
#include "vector"
#include "set"

using namespace std;

int main() {
    vector<int> v;

    for (int i = 0; i < 4; i++) {
        v.push_back(i);
        v.push_back(i);
    }

    /// Para insertar valores en un set, se utiliza el insert, no cuenta con push_back
    /// OBS: si te das cuenta el set no cuenta elementos repetidos, DATAZO
    set<int> s;
    for (const int& e: v)
        s.insert(e);

    cout << v.size() << endl; // Salida: 8
    cout << s.size() << endl; // Salida: 4  // NO CUENTA REPETIDOS

    /// obs: PUEDO CREAR LOS ELEMENTOS DIRECTAMENTE ASI Y SIN NECESIDAD DE UN BUCLE FOR:
    // Puedo crear los elementos directamente con los elementos del vector
    set<int> s2(v.begin(),v.end());
    cout << s2.size() << endl; // Salida: 4

    return 0;
}
