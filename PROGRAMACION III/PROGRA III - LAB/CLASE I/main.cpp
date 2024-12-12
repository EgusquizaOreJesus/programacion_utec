#include <iostream>

using namespace std;

void insertionSort(int size);
int main() {
    srand(time(nullptr));
    insertionSort(30);
}

void insertionSort(int size){
    int array[size];
    for (int i = 0; i < size; ++i) {
        array[i] = 1+rand()%99;
    }
    for (int step = 1; step < size; step++) {
        int key = array[step];
        int j = step - 1;
        while (key < array[j] && j >= 0) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
    //PRINTEAR
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}