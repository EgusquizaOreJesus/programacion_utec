#include "iostream"

using namespace std;

void printArray(int A[], int n){
    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}

// Funcion bubbleSort normal
// void bubbleSort(int A[], int n){
//   for (int i = 0; i < n - 1; i++)
//       for (int j = 0; j < n - i - 1; j++)
//           if (A[j] > A[j + 1])
//               swap(A[j],A[j+1]);
//}


// Funcion bubbleSort aceptando orden ascendente o descendente
void bubbleSort(int A[], int n, bool (*f)(int,int)) {
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (f(A[j],A[j + 1]))
                swap(A[j], A[j + 1]);
        }
    }
}

bool compDes(int x,int y){return x < y;}
bool compAsc(int x,int y){return x > y;}

int main(){
    int A[] = {10,40,30,50,14,20,90,100};
    int size = sizeof(A)/sizeof(A[0]);
    printArray(A,size);
    bubbleSort(A,size,&compAsc);
    printArray(A,size);
    bubbleSort(A,size,&compDes);
    printArray(A,size);
    return 0;
}