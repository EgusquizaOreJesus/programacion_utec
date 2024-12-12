#ifndef NODE_H
#define NODE_H

using namespace std;

template <typename T>
struct NodeBT {
    
    T data;
    NodeBT* left; 
    NodeBT* right;  
    
    NodeBT() : left(nullptr), right(nullptr) {}   
    explicit NodeBT(T value) : data(value), left(nullptr), right(nullptr) {}

    void KillSelf(){
        // TODO
        if(left != nullptr){
            left->KillSelf(); //Killself recursivo para el subarbol izquierdo
        }
        if (right != nullptr)
        {
            right->KillSelf();//Killself recursivo para el subarbol derecho
        }
        delete this; //Eliminamos el nodo actual
    }
};

#endif