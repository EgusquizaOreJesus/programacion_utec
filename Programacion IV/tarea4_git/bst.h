#ifndef BSTREE_H
#define BSTREE_H

#include "iterator.h"

using namespace std;

template <typename T>
class BSTree {
    public:
        typedef BSTIterator<T> iterator;  

    private:
        NodeBT<T>* root;    
        string displayPreOrder(NodeBT<T> nodo){
            string result;

        }
    public:
        BSTree(): root(nullptr) {}

		void insert(T value);	
		bool find(T value);		
        string displayInOrder();
        string displayPreOrder();
        string displayPostOrder();
        int height();
        T minValue();
        T maxValue();
        void remove(T value);        
        bool isBalanced();
        int size();
        bool isFull(); //es aquel en el que todos los nodos tienen 0 o 2 hijos        
        T successor(T value); // Retornar el valor siguiente de "value" en el arbol
        T predecessor(T value); // Retornar el valor anterior de "value" en el arbol
        void clear(); // Liberar todos los nodos (usar root->KillSelf)
        void buildFromOrderedArray(T *array, int n); //dado un array ordenado construir un arbol binario balanceado
        string displayBFS();// Recorrido en anchura (BreadthFirstSearch)
        string displayDFS();// Recorrido en profundidad (DepthFirstSearch)
        iterator begin(BSTIterator<int>::Type _);// Retorna el inicio del iterador             
        iterator end();// Retorna el final del iterador
        ~BSTree(); //Destructor del arbol

}; 


#endif


