#include <iostream>
#include "queue.h"
#include "tester.h"
using namespace std;

int main() {
    CircularArray<int>* array = new CircularArray<int>(8);
//    ASSERT(array->is_empty() == true, "The function is_empty is not working");
//    array->push_back(6);
//    array->push_back(7);
//    array->push_back(8);
//    array->push_front(0);
//    array->push_front(10);
//    array->push_back(11);
//    cout << array->size();
    cout << array->to_string();
//    ASSERT(array->is_empty() == false, "The function is_empty is not working");
//    ASSERT(array->is_full() == false, "The function is_full is not working");
//    array->push_front(10);
//    array->push_front(2);
//    ASSERT(array->is_full() == true, "The function is_full is not working");
//    ASSERT(array->to_string() == "2 10 6 3 7 8 1 ", "The function push_front is not working");
//    cout << array->to_string(" ") << endl;
//    array->reverse();
//    cout << array->to_string(" ") << endl;
//
//    ASSERT(array->to_string() == "1 8 7 3 6 10 2 ", "The function push_front is not working");
    auto array2 = new QueueArray<int>(10);
//    array->pop_front();
//    array->pop_front();
//    array->pop_front();
//    array->push_back(15);
//    array->push_back(9);
//    array->push_back(4);
//    ASSERT(array[0] == 3 && array[6] == 4, "The operator [] is not working");
    //    ASSERT(array->is_sorted() == false, "The function is_sorted is not working");
//    array->sort();
//    ASSERT(array->to_string() == "1 3 4 7 8 9 15 ", "The function sort is not working");

//    array->reverse();
//    ASSERT(array->to_string() == "15 9 8 7 4 3 1 ", "The function reverse is not working");
//    array->insert(10, 1);
//    array->pop_back();
//    ASSERT(array->size() == 7, "The function size is not working");
    delete array;
    return 0;
}
