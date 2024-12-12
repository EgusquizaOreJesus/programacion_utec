#include <iostream>
#include "tester.h"
#include "forward.h"
#include "double.h"
#include "circular.h"

using namespace std;

void test(List<int>* list){   
    cout<<"*** Testing "<<list->name()<<"  *******"<<endl; 
    ASSERT(list->is_empty() == true, "The function is_empty is not working");
    ASSERT(list->size() == 0, "The function size is not working");    
    list->push_front(5);
    list->push_front(10);
    ASSERT(list->pop_front() == 10, "The function push_front/pop_front is not working");
    list->push_back(20);
    list->push_back(15);
    ASSERT(list->pop_back() == 15, "The function push_back/pop_back is not working");
    list->push_back(30);
    list->push_back(8);
    list->insert(12, 2);
    ASSERT((*list)[2] == 12, "The operator [] is not working");    
    list->push_back(10);
    list->push_front(3);
    ASSERT(list->is_sorted() == false, "The function is_sorted is not working");
    list->sort();
    ASSERT(list->is_sorted() == true, "The function sort is not working");
    list->clear();
    ASSERT(list->is_empty() == true, "The function clear is not working");
    delete list;
}

int main()
{    
//    List<int> *forward = new ForwardList<int>();
    //    test(forward);

    List<int> *doble = new DoubleList<int>();
    doble->push_back(2);
    doble->push_back(4);
    doble->push_back(3);
    doble->push_front(10);
    cout << doble->front() << endl;
    doble->printear();
    doble->pop_back();
    doble->pop_back();
    doble->pop_back();
    doble->pop_back();



    doble->printear();

    //    test(doble);

//    List<int> *circular = new CircularList<int>();
//    test(circular);

    return 0;
}