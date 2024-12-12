#include <iostream>
#include "heap.h"
#include "tester.h"

using namespace std;



int main(int argc, char const *argv[])
{
    Heap<int>* heap = new Heap<int>(10, Heap<int>::MIN_HEAP);
    int array[8] = {23, 10, 49, 50, 13, 12, 9, 45};
    heap->buildFromArray(array, 8);
    cout << heap->top() << endl;
    cout << heap->top() << endl;
    heap->display();
    heap->remove(3);
    heap->display();

    //    testMaxHeap();
//    testMinHeap();
//    testSortAsc();
//    testSortDesc();

    return 0;
}
