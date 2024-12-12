#include "iostream"
#include "random"


using namespace std;



int main(){
    string digitos;
    random_device rd;
    uniform_int_distribution<int> dis(0,9);

    for (int i = 0; i < 7; ++i) {
        digitos += std::to_string(dis(rd));
    }


    cout << digitos;
    return 0;
}