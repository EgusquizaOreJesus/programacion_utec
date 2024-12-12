#include "algorithm"
#include "iostream"
#include "cmath"
using namespace std;

void printArray2D(int A[][2], int size){
    for (int i = 0; i < size; i++)
        cout << "("<<A[i][0] <<","<< A[i][1]<< ") ";
    cout << endl;
}

class sumComp{
    char op;
public:
    explicit sumComp(char _op=' '):op(_op){};

    double operator() (int num1,int num2) const{
        if (op == '+'){
            return num1+num2;
        }
        else if (op == '*'){
            return num1*num2;
        }
        else if (op == '2'){
            return sqrt(pow(num1,2)+pow(num2,2));
        }
        else{
            return num1;
        }
    }
};



void bubbleSort(int A[][2], int n, sumComp F,bool (*f)(double ,double )) {
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (f(F(A[j][0],A[j][1]),F(A[j+1][0],A[j+1][1]))){
                swap(A[j][0], A[j + 1][0]);
                swap(A[j][1], A[j + 1][1]);
            }
        }
    }
}


bool compDes(double x,double y){return x < y;}
bool compAsc(double x,double y){return x > y;}

int main(){
    int A[4][2] = {{7,3},{2,10},{24,-21},{1,1}};
    int szA = sizeof(A)/sizeof(A[0]);

    printArray2D(A,szA);

    // op igual a +
    bubbleSort(A,szA,sumComp('+'),&compAsc);
    printArray2D(A,szA);

    // op igual a *
    bubbleSort(A,szA,sumComp('*'),&compAsc);
    printArray2D(A,szA);

    // op de norma
    bubbleSort(A,szA,sumComp('2'),&compAsc);
    printArray2D(A,szA);

    // por defecto
    bubbleSort(A,szA,sumComp(),&compAsc);
    printArray2D(A,szA);

    return 0;
}