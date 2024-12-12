#include "iostream"

using namespace std;


struct Node{
    int data;
    Node* next;
    Node* prev;
};

/// CIRCULAR DOUBLY LINKED LIST:
//
class List{
    Node* head;
    Node* tail;
public:
    List(){
        head = nullptr;
        tail = nullptr;
    }

    void push_front(int data){
        auto temp = new Node;
        temp->data = data;
        Node* tail_ = head->prev;
        temp->next = head;
        temp->prev = tail_;
    }
    void push_back(int data){
        auto temp = new Node;
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
    void pop_front(){
//        Node* temp = head;
//        head = head->next;
//        head->prev = nullptr;
//        delete temp;
        /// OTRA FORMA DE HACERLO SIN TEMP;
        head=head->next;
        delete head->prev;
        head->prev = nullptr;
    }
    void pop_back(){
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }
    void insert(int data,int pos){

    }



};

int main(){


    return 0;
}