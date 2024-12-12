#include <iostream>

using namespace std;
struct comparador{

    bool operator()(int a, int b){
        return a < b;
    }
};

void sumar(double a, double b){

}
int main() {
    int a = 3;
    sumar(a,3);
    return 0;
}
