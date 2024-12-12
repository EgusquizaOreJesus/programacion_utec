#include <iostream>
#include "set.h"
#include "person.h"

using namespace std;

void test1(){
    Set<int> mset;
    mset.insert(5);
    mset.insert(8);
    mset.insert(2);
    mset.insert(10);
    mset.insert(5);
    mset.insert(12);
    mset.display();//2 5 8 10 12
    cout<<"contains(5)"<<mset.contains(5)<<endl;//1
    cout<<"contains(4)"<<mset.contains(4)<<endl;//0
    mset.remove(10);
    mset.remove(3);
    mset.display();//2 5 8 12
}

void test2(){
    Set<Person> mset;
    mset.insert(Person("juan", 25));
    mset.insert(Person("maria", 18));
    mset.insert(Person("luis", 19));
    mset.insert(Person("bruno", 20));
    mset.insert(Person("maria", 20));
    mset.insert(Person("sara", 21));
    mset.display();//(bruno, 20) (juan, 25) (luis, 19) (maria, 18) (sara, 21)
    cout<<"contains(juan)"<<mset.contains(Person("juan"))<<endl;//1
    cout<<"contains(heider)"<<mset.contains(Person("heider"))<<endl;//0
    mset.remove(Person("juan"));
    mset.remove(Person("heider"));
    mset.display();//(bruno, 20) (luis, 19) (maria, 18) (sara, 21)
}

int main(){
    test1();
    test2();
}

