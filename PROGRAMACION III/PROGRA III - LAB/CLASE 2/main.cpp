#include <bits/stdc++.h>

using namespace std;

void crear_vector(vector<int> &A, int n);
void print_Vector(vector<int> A){
    for(auto a: A){
        cout << a << " ";
    }
    cout <<endl;
}

int main() {
    srand(time(nullptr));
    vector<int> A;
    crear_vector(A,30);
    print_Vector(A);
    return 0;
}

// MI FORMA DE CREAR VECTOR DE PRIMOS
void crear_vector(vector<int> &A, int n){
    while (A.size() != n){
        int temp = rand()%91 + 10;
        int div = 0;
        for (int i = 1; i <= temp; ++i) {
            if (temp%i == 0){
                div += 1;
            }
            if (div > 2 ){
                break;
            }
        }
        if(div == 2 or temp == 1){
            A.push_back(temp);
        }
    }
}