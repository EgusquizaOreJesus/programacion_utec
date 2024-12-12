#include "iostream"

using namespace std;

int suma(int x1, int x2){ return x1 + x2; }
int resta(int x1, int x2){ return x1 + x2; }
int multiplicacion(int x1, int x2){ return x1*x2; }
float division(int x1, int x2){ return float(x1)/float(x2); }
int residuo(int x1, int x2){ return x1%x2; }

template<typename T=int>
void calculadora(T(*f)(int,int),int x1, int x2){
    T resultado = f(x1,x2);
    cout << resultado << endl;
}

int main(){
    int (*var_suma)(int,int)  = &suma;
    int (*var_resta)(int,int) = &resta;
    int (*var_prod)(int,int) = &multiplicacion;
    float (*var_div)(int,int) = &division;
    int (*var_res)(int,int) = &residuo;

    calculadora(var_suma,3,4);
    calculadora(var_res,6,4);
    calculadora(var_prod,3,4);
    calculadora(var_div,3,4);
    calculadora(var_res,5,4);




    return 0;
}