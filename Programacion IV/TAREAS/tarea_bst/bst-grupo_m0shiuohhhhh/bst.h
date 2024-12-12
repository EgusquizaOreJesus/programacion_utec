#ifndef BSTREE_H
#define BSTREE_H

//#include <bits/stdc++.h>
#include <type_traits>
#include "node.h"
#include "iterator.h"
using namespace std;
template <typename T>
class BSTree {
public:
    typedef BSTIterator<T> iterator;

private:
    NodeBT<T>* root;

    NodeBT<T>* insert(T value , NodeBT<T>* &raiz)
    {
        if(raiz== nullptr)
        {
            raiz= new NodeBT<T>(value);
            //cout<<"Nodo creado  "<<raiz->data<<endl;

        }
        else if(value<=raiz->data)
        {
            //cout<<"A la izquierda .."<<endl;
            raiz->left= insert(value,raiz->left);
        }
        else if(value>=raiz->data)
        {
            //  cout<<"A la derecha ..."<<endl;
            raiz->right=insert(value,raiz->right);
        }
        return raiz;

    }


public:
    BSTree(): root(nullptr) {}

    void insert(T value){
        insert(value,root);
    }

    [[maybe_unused]]  bool find(T value)
    {
        NodeBT<T>* temp = root;
        while (temp->data!=value)
        {
            if(temp->data==value)
                return true;

            if(value>temp->data)
            {
                temp=temp->right;

            }
            else temp=temp->left;
        }
        return false;
    }


    string displayInOrder()
    {
        return displayInOrder(root);
    }
    string displayInOrder(NodeBT<T>* raiz){

        if(raiz== nullptr)
            return "";
        else{
            if constexpr (!is_same_v<string ,T>)
            {
                return displayInOrder(raiz->left)+to_string(raiz->data)+" "+displayInOrder(raiz->right);
            }else if constexpr (!is_same_v<string,T>) return displayInOrder(raiz->left)+raiz->data+displayInOrder(raiz->right)+" ";
        }

    }

    [[maybe_unused]] string displayPreOrder(){
        return displayPreOrder(root);
    }
    string displayPreOrder(NodeBT<T>* raiz){

        if(raiz== nullptr)
            return "";
        else{

            if constexpr (!is_same_v<string ,T>)
            {
                return to_string(raiz->data)+" "+displayPreOrder(raiz->left)+displayPreOrder(raiz->right);
            }else if constexpr (!is_same_v<string,T>) return raiz->data+displayPreOrder(raiz->left)+" "+displayPreOrder(raiz->right)+" ";
        }

    }

    [[maybe_unused]] string displayPostOrder(){
        return displayPostOrder(root);
    }
    string displayPostOrder(NodeBT<T>* raiz)
    {
        if(raiz== nullptr)
            return "";
        else{

            if constexpr (!is_same_v<string ,T>)
            {
                return displayPostOrder(raiz->left)+displayPostOrder(raiz->right)+to_string(raiz->data)+" ";
            }else if constexpr (!is_same_v<string,T>) return displayPostOrder(raiz->left)+" "+displayPostOrder(raiz->right)+" "+raiz->data;
        }

    }

    int height(){

        return height(root);
    }
    int height(NodeBT<T>* current){


        if(current== nullptr)
            return -1;

        if(current!= nullptr)
            return max((current->left== nullptr)?0:(1+height(current->left)),((current->right== nullptr)?0:(1+height(current->right))));
        else if(current->right== nullptr and current->left== nullptr)
            return 0;

        return 0;
    }

    [[maybe_unused]] int height2(NodeBT<T>* medir){

        return height(medir)-1;
    }

    T minValue(){
        NodeBT<T> * temp = root;
        while (temp!= nullptr)
        {// cout<<"CURRENT -->"<<temp->data<<endl;
            if(temp->left!= nullptr)
            {
                temp=temp->left;
            }
            else return temp->data;
        }
        return temp->data;
    }
    T maxValue(){

        NodeBT<T> * temp = root;
        while (temp!= nullptr)
        {
            if(temp->right!= nullptr)
            {
                temp=temp->right;
            }
            else return temp->data;
        }
        return temp->data;
    }

    [[maybe_unused]]     NodeBT<T> *getRoot() const {
        return root;
    }
    
    void remove(T value){
        remove(root,value);
    }
    void remove(NodeBT<T>*& node, const T& value) {
        if (node == nullptr) {
            return;
        }
        if (value < node->data) {
            remove(node->left, value);
        } else if (value > node->data) {
            remove(node->right, value);
        } else {
            if (node->left == nullptr) {
                NodeBT<T>* temp = node->right;
                delete node;
                node = temp;
            } else if (node->right == nullptr) {
                NodeBT<T>* temp = node->left;
                delete node;
                node = temp;
            } else {
                NodeBT<T>* temp = node->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }
                node->data = temp->data;
                remove(node->right, temp->data);
            }
        }
    }

    bool isBalanced(){
        return isBalanced(root);
    }

    bool isBalanced(NodeBT<T>* current){
        if(current != nullptr)
        {
            bool condition = abs(height(current->left) - height(current->right)) <= 1;
            return (condition && isBalanced(current->left) && isBalanced(current->right));
        }

            return true;

    }


    int size(){
        return size(root);
    }
    int size(NodeBT<T>* current){
        NodeBT<T>* temp = current;

        if (temp == nullptr){
            return 0;
        }

        return 1+size(temp->left)+ size(temp->right);
    };

    [[maybe_unused]]  bool isFull(){
        return isFull(root);
    }; //es aquel en el que todos los nodos tienen 0 o 2 hijos
    bool isFull(NodeBT<T>* current){
        if (current == nullptr) {
            return true;
        }

        if (current->left == nullptr && current->right == nullptr) {
            return true;
        }

        if (current->left == nullptr || current->right == nullptr) {
            return false;
        }

        return isFull(current->left) && isFull(current->right);
    };

    T successor(T value)
    {
        NodeBT<T>* temp = root;
        NodeBT<T>* candidate= root;
        while (temp->data!=value)
        {
            if(temp->data>value)
                candidate=temp;

            if(value>temp->data)
            {
                temp=temp->right;

            }
            else temp=temp->left;
        }

        if(temp->right!= nullptr)
        { temp=temp->right;
            while (temp!= nullptr)
            {
                if(temp->left!= nullptr)
                {
                    temp=temp->left;
                }
                else return temp->data;
            }
        }else return candidate->data;

        return candidate->data;

    }// Retornar el valor siguiente de "value" en el arbol
    T predecessor(T value){

        NodeBT<T>* temp = root;
        NodeBT<T>* candidate= root;
        while (temp->data!=value)
        {
            if(temp->data<value)
                candidate=temp;

            if(value>temp->data)
            {
                temp=temp->right;

            }
            else temp=temp->left;
        }

        if(temp->left!= nullptr)
        { temp=temp->left;
            while (temp!= nullptr)
            {
                if(temp->right!= nullptr)
                {
                    temp=temp->right;
                }
                else return temp->data;
            }
        }else return candidate->data;

        return candidate->data;
    } // Retornar el valor anterior de "value" en el arbol
    void clear(){
        root->KillSelf();
        root = nullptr;
//        clear(root);
    }; // Liberar todos los nodos (usar root->KillSelf)

    void buildFromOrderedArray(T *array, int n){


        buildFromOrderedArray(array , 0 , n-1);


    }; //dado un array ordenado construir un arbol binario balanceado

    void  buildFromOrderedArray(T *array , int l  , int  r)
    {

        int mid = l +(r-l)/2;

        if(l<=r)
        {
            insert(array[mid]);
            buildFromOrderedArray(array, mid+1, r);//right
            buildFromOrderedArray(array, l , mid-1);//left

        }
        else return;


    }

    string displayBFS(){ //must return a string
        queuec<NodeBT<T>*> frontier;
        frontier.push(root);
        string bfs;
        while (!frontier.empty())
        {
            NodeBT<T>* temp=frontier.pop();

            if constexpr (!is_same_v<string ,T>)
            {
                bfs+= to_string(temp->data);
            }else if constexpr (!is_same_v<string,T>)  bfs+= temp->data;
            bfs+=" ";
            if(temp->left!= nullptr)
                frontier.push(temp->left);
            if(temp->right!= nullptr)
                frontier.push(temp->right);


        }

        return bfs;
    }// Recorrido en anchura (BreadthFirstSearch)
    [[maybe_unused]] string displayDFS(){ //must return a string
        stackc<NodeBT<T>*> visited;
        visited.push(root);
        cout << "size: " <<visited.size() << endl;
        string dfs;
        while (!visited.empty())
        {
            cout << "ENTRA BUCLE" << endl;
            NodeBT<T>* temp=visited.pop();
            if constexpr (!is_same_v<string ,T>)
            {
                dfs+= to_string(temp->data);
            }else if constexpr (!is_same_v<string,T>)  dfs+= temp->data;
            dfs+=" ";
            if(temp->right!= nullptr)
                visited.push(temp->right);
            if(temp->left!= nullptr)
                visited.push(temp->left);

        }
        cout << "SALIENDO BUCLE" << endl;

        return dfs;

    }// Recorrido en profundidad (DepthFirstSearch)
    iterator begin(BSTIterator<int>::Type _){
        return iterator(root,_);
    }
//    iterator begin(BSTIterator<int>::Type _);// Retorna el inicio del iterador
//    iterator end();// Retorna el final del iterador
    iterator end(){
        return iterator();
    }
    ~BSTree(){
        if (root != nullptr) {
        root->killSelf();
        root = nullptr;
    }
    } //Destructor del arbol

};

#endif


