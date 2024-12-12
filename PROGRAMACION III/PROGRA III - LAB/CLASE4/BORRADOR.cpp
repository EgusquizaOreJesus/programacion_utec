#include "iostream"
#include "vector"

using  namespace std;
int suma_digitos(int number){
    if (number < 10){
        return number;
    }else{
        return number%10 + suma_digitos(number/10);

    }
}

int max_element(vector<int> v){

}


int main(){
    cout << suma_digitos(943);
    return 0;
}