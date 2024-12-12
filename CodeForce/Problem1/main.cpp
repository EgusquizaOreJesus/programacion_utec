#include <iostream>

using namespace std;

int main() {
    int peso;
    cin >> peso;

    bool encontrado = false;
    for (int i = 2; i <= peso / 2; i += 2) {
        int j = peso - i;
        if (j % 2 == 0) {
            encontrado = true;
            cout << "YES";
            break;
        }
    }
    if (!encontrado) {
        cout << "NO";
    }
    return 0;
}
