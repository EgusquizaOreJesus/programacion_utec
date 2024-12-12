#include <iostream>
#include "heap.h"
#include "tester.h"

using namespace std;

void testMaxHeap(){
    Heap<int>* heap = new Heap<int>(10, Heap<int>::MAX_HEAP);
    ASSERT(heap->is_empty() == true, "The function is_empty is not working");
    ASSERT(heap->size() == 0, "The function is_full is not working");
    int array[8] = {23, 10, 49, 50, 13, 12, 9, 45};  
    heap->buildFromArray(array, 8);
   ASSERT(heap->top() == 50, "The function top is not working");
    heap->push(8);
    heap->push(55);
   heap->push(18);
    ASSERT(heap->top() == 55, "The function push is not working");
    heap->pop();
    heap->pop();
    ASSERT(heap->top() == 49, "The function pop is not working");
    vector<int> topk = heap->extractTheTopK(2);
    ASSERT(topk[1] == 45, "The function extractTheTopK is not working");
    ASSERT(heap->size() == 7, "The function size is not working");
}

void testMinHeap(){
    Heap<int>* heap = new Heap<int>(10, Heap<int>::MIN_HEAP);
    ASSERT(heap->is_empty() == true, "The function is_empty is not working");
    ASSERT(heap->size() == 0, "The function is_full is not working");
    int array[8] = {23, 10, 49, 50, 13, 12, 9, 45};  
    heap->buildFromArray(array, 8);
    heap->displaya();
    ASSERT(heap->top() == 9, "The function top is not working");
    heap->push(8);
    heap->push(55);
    heap->push(18);
    ASSERT(heap->top() == 8, "The function push is not working");
   heap->pop();
    heap->pop();
    ASSERT(heap->top() == 10, "The function pop is not working");
    vector<int> topk = heap->extractTheTopK(2);
    ASSERT(topk[1] == 12, "The function extractTheTopK is not working");
    ASSERT(heap->size() == 7, "The function size is not working");
}

void testSortAsc(){
    int array[8] = {23, 10, 49, 50, 13, 12, 9, 45};
    Heap<int>::sortAsc(array, 8);

    ASSERT(array[0] == 9, "The function sortAsc is not working");
    ASSERT(array[2] == 12, "The function sortAsc is not working");
}

void testSortDesc(){
    int array[8] = {23, 10, 49, 50, 13, 12, 9, 45};
    Heap<int>::sortDesc(array, 8);
    ASSERT(array[0] == 50, "The function sortAsc is not working");
    ASSERT(array[2] == 45, "The function sortAsc is not working");
}

int main(int argc, char const *argv[])
{
    testMaxHeap();
    testMinHeap();
    testSortAsc();
   testSortDesc();
    return 0;
}
