//
// Created by Jesus Egusquiza on 5/4/2023.
//

#ifndef CODEROOM3_SET_H
#define CODEROOM3_SET_H

using namespace std;
template<typename T>
class Set
{
private:
    struct Node
    {
        T data;
        Node* left;
        Node* right;
        explicit Node(T _data){
            data = _data;
            left = nullptr;
            right = nullptr;
        }
    };
    Node* root;
    //TODO

    void insert(Node* &node, T value){
        if(node == nullptr){
            node = new Node(value);
        }
        else if(value < node->data)
            insert(node->left, value);
        else if(value > node->data)
            insert(node->right, value);
    }
    void display(Node* raiz){
        if(raiz== nullptr)
            return;
        display(raiz->left);
        cout << raiz->data << " ";
        display(raiz->right);
    }
    bool contains(Node* raiz, T value){
        if (raiz == nullptr){
            return false;
        }
        else if (raiz->data == value){
            return true;
        }
        else if (value < raiz->data){
            contains(raiz->left,value);
        }
        else if (value > raiz->data){
            contains(raiz->right,value);
        }
    }
public:
    Set(){
        root = nullptr;
        //TODO
    }
    void display(){
        display(root);
        cout << endl;
    }

    void insert(T value){
        insert(root,value);
        //TODO
    }

    void remove(T value){
        remove(root,value);
    }
    void remove(Node*& node, const T& value) {
        if (node == nullptr) {
            return;
        }
        if (value < node->data) {
            remove(node->left, value);
        } else if (value > node->data) {
            remove(node->right, value);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                node = temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                node = temp;
            } else {
                Node* temp = node->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }
                node->data = temp->data;
                remove(node->right, temp->data);
            }
        }
    }
    bool contains(T value){
        return contains(root,value);
        //TODO
    }
};
#endif //CODEROOM3_SET_H
