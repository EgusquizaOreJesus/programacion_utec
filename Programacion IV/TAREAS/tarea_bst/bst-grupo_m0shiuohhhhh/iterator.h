#ifndef ITERATOR_Hc
#define ITERATOR_H

#include "node.h"
#include "iostream"
using namespace std;
template<typename T=int>
struct Node {
    T data;
    Node* next;
    Node* prev;

    Node(){
        next = nullptr;
        prev = nullptr;
    }

    explicit Node(T value){
        next = nullptr;
        prev = nullptr;
        data = value;
    }
};

using namespace std;
template <typename T=int>
class DoubleList  {

private:
    Node<T>* head;
    Node<T>* tail;
    int nodes;

public:
    DoubleList() {
        head = nullptr;
        tail = nullptr;
        nodes = 0;
    }

    ~DoubleList(){
        delete head;
        delete tail;
        // TODO
    }

    [[maybe_unused]] T front(){
        throw head->data;
    }

    [[maybe_unused]] T back(){
        throw tail->data;
    }

    void push_front(T data){
        if (is_empty()){
            auto temp = new Node<T>(data);
            temp->next = nullptr;
            temp->prev = nullptr;
            head = temp;
            tail = temp;
            nodes++;
//                throw ;
        }
        else{
            auto temp = new Node<T>(data);
            temp->prev = nullptr;
            temp->next = head;
            head->prev = temp;
            head = temp;
            nodes++;
//                throw ;
        }
    }
    T get_Top(){
        return tail->data;
    }
    void push_back(T data){
        if (is_empty()){
            auto temp = new Node<T>(data);
            head = temp;
            tail= temp;
            nodes++;
//                throw ;
        }
        else{
            auto temp = new Node<T>(data);
            temp->prev = tail;
            temp->next = nullptr;
            tail->next = temp;
            tail = temp;
            nodes++;
//                throw ;
        }
    }

    T pop_front(){
        if (is_empty()){
            throw ;
        }
        else if (head->next == nullptr && head->prev == nullptr){
            T val = head->data;
            delete head;
            head = nullptr;
            tail = nullptr;
            nodes--;
            return val;
        }
        else{
            T val = head->data;
            head=head->next;
            delete head->prev;
            head->prev = nullptr;
            nodes--;
            return val;
        }
    }

    T pop_back(){
        if (is_empty()){
            throw ;
        }
        else if(tail->next== nullptr && tail->prev == nullptr){
            T val = tail->data;
            delete tail;
            head = nullptr;
            tail = nullptr;
            nodes--;
            return val;
        }
        else{
            T val = tail->data;
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
            nodes--;
            return val;
        }
    }

    [[maybe_unused]] T insert(T data, int pos){
        if (is_empty() || pos>=size()){
            push_back(data);
            return data;
        }
        else if (pos == 1){
            T val = head->data;
            push_front(data);
            nodes++;
            return val;
        }
        else{
            auto nodo = new Node<T>(data);
            Node<T>* temp  = head;
            int i = 1;
            while (i++<pos-1){
                temp = temp->next;
            }
            nodo->next = temp->next;
            nodo->prev = temp;
            temp->next->prev = nodo;
            temp->next = nodo;
            nodes++;
            return 0;
        }
        //            throw ("sin definir");
    }

    [[maybe_unused]] bool remove(int pos){
        if (pos>size()){
            return false;
        }
        else if (pos == 1){
            pop_front();
            return true;
        }
        else if (pos == size()){
            pop_back();
            nodes--;
            return true;
        }
        else{
            Node<T>* temp  = head;
            int i = 1;
            while (i++<pos-1){
                temp = temp->next;
            }
            temp->next = temp->next->next;
            nodes--;
            return true;
        }
        //            throw ("sin definir");
    }

    T& operator[](int pos){
        if (pos == 0){
            return head->data;
        }
        else if (pos == size()-1){
            return tail->data;
        }
        else{
            Node<T>* temp  = head;
            int i=0;
            while (i<=pos){
                temp = temp->next;
                i++;
            }
            return temp->data;
        }
        //            throw ("sin definir");
    }

    bool is_empty(){
        return nodes == 0;
        //            throw ("sin definir");
    }

    virtual int size(){
        return nodes;
//            throw ("sin definir");
    }

    [[maybe_unused]] void clear(){
        delete head;
        delete tail;
        head = nullptr;
        tail = nullptr;
        nodes = 0;
//            throw ("sin definir");
    }
    [[maybe_unused]]void display(){
        Node<T>* temp = head;
        while (temp != nullptr){
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << endl;
    }


};

template<typename T=int>
class stackc:private DoubleList<T>
{
public:
    stackc(): DoubleList<T>()
    {}

    void push(T data)
    {
        DoubleList<T>::push_back(data);

    }

    T pop()
    {

        return DoubleList<T>::pop_back();
    }
    bool empty()
    {
        return DoubleList<T>::is_empty();
    }

    int size() override
    {
        return DoubleList<T>::size();
    }
    T top(){
        return DoubleList<T>::get_Top();
    }

};

template<typename T=int>
class queuec:private DoubleList<T>{

public:
    queuec(): DoubleList<T>() {}

    void push(T data)
    {
        DoubleList<T>::push_back(data);
    }

    T pop(){

        return DoubleList<T>::pop_front();

    }

    bool empty(){

        return DoubleList<T>::is_empty();
    }
    int size() override
    {
        return DoubleList<T>::size();
    }

};
template <typename T>
class BSTIterator
{
public:
    enum Type {
        PreOrder, InOrder, PostOrder, BFS
    };

private:
    NodeBT<T>* current;
    Type type;
    stackc<NodeBT<T> * > stack;
    queuec<NodeBT<T> *> queue;
public:
    BSTIterator() : current(nullptr), type(PreOrder) {
    };

    [[maybe_unused]] explicit BSTIterator(NodeBT<T> *current, Type type=PreOrder): type(type) {
        this->type = type;

        if(type==PreOrder)
        {
            this->current = new NodeBT<T>(current->data);
            if(current->right!= nullptr){
                stack.push(current->right);
            }
            if(current->left!= nullptr){
                stack.push(current->left);
            }
        }
        else if (type == InOrder){
            while (current != nullptr){
                this->stack.push(current);
                current = current->left;
            }
            this->current = this->stack.empty() ? nullptr : stack.top();
        }
        else if (type == PostOrder){
//            this->current = current;
            while (current != nullptr){
                this->stack.push(current);
                current = current->left;
            }
            this->current = this->stack.empty() ? nullptr : stack.pop();
        }
        else if (type == BFS){
            this->current = current;
            queue.push(current);
            current = queue.pop();
            if (current->left != nullptr){
                queue.push(current->left);
            }
            if (current->right != nullptr){
                queue.push(current->right);
            }
        }
    }
    BSTIterator<T> &operator=(BSTIterator<T> other);
    bool operator!=(BSTIterator<T> other);
    BSTIterator<T> &operator++();   //++it
    T operator*();
};

template<typename T>
BSTIterator<T> &BSTIterator<T>::operator=(BSTIterator<T> other) {
    current = other.current;
    this->type = other.type;
    stackc<NodeBT<T>*> temp;
    while (stack.size()!=0){
        stack.pop();
    }
    while (other.stack.size()!=0){
        temp.push(other.stack.pop());
    }
    while (temp.size() != 0){
        stack.push(temp.pop());
    }
    //    stack = other.stack;
//    stack.swap(other.stack);
    return *this;
}

template<typename T>
bool BSTIterator<T>::operator!=(BSTIterator<T> other) {
    if (this->current != other.current){
        return true;
    }
    return false;
}

template<typename T>
BSTIterator<T>  &BSTIterator<T>::operator++() {
    if (type == PreOrder){
        if (stack.size() != 0)
        {
            current=stack.pop();

            if(current->right!= nullptr){
                stack.push(current->right);
            }
            if(current->left!= nullptr){
                stack.push(current->left);
            }
            return *this;
        }
        else{
            current = nullptr;
            return *this;
        }

    }
    else if (type == InOrder){
        if (stack.size()!=0) {
            NodeBT<T> *node = this->stack.top();
            this->stack.pop();
            node = node->right;
            while (node != nullptr)
            {
                this->stack.push(node);
                node = node->left;
            }
            if (stack.size()!=0){
                this->current = stack.top();
                return *this;
            }
            current = nullptr;
            return *this;
        }

    }
    else if (type == PostOrder){
        if (stack.size()!=0){
            NodeBT<T>* node = this->stack.top();
            node = node->right;
            while (node != nullptr and node->left == nullptr and node->right != nullptr and current->data != node->data){
                this->stack.push(node);
                node = node->right;
            }
            if (node != nullptr and node->data != current->data) {
                while(node != nullptr){
                    this->stack.push(node);
                    node = node->left;
                }
            }
            this->current = stack.pop();
            return *this;
        }
        else{
            current = nullptr;
            return *this;
        }


    }
    else if (type == BFS){
        if (queue.size() != 0){
            current = queue.pop();
            if (current->left != nullptr){
                queue.push(current->left);
            }
            if (current->right != nullptr){
                queue.push(current->right);
            }
            return *this;
        }
        else{
            current = nullptr;
            return *this;
        }
    }
    return *this;
}

template<typename T>
T BSTIterator<T>::operator*() {
    if (current!= nullptr){
        return current->data;
    }

    return 0;
}


#endif