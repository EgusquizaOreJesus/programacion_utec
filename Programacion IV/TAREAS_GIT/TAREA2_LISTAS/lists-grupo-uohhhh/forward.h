#ifndef FORWARD_H
#define FORWARD_H
#include <iostream>
#include "list.h"

// TODO: Implement all methods
using namespace std;
template <typename T>
class ForwardList : public List<T> {
    private:
        struct Node {
            T data;
            Node* next;

            Node(){
                next = nullptr;
                // TODO
            }

            explicit Node(T value){
                data = value;
                next = nullptr;
                // TODO
            }

            [[maybe_unused]]void killSelf(){
                delete this;
            }
        };

    private:
        Node* head;
        int nodes;

    public:
        ForwardList() : List<T>() {
            head = nullptr;
            nodes = 0;
        }

        ~ForwardList(){
            delete head;
         	// TODO            
        }

        T front(){
            return head->data;
//            throw ("sin definir");
        }

        T back(){
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            return temp->data;
//            throw ("sin definir");
        }

        void push_front(T data){
            Node* nodo = new Node(data);
            if (is_empty()){
                head = nodo;
                head->next = nullptr;
            }
            else{
                nodo->next = head;
                head = nodo;
            }
            nodes++;
//            throw ("sin definir");
        }

        void push_back(T data){
            Node* nodo = new Node(data);
            if (head == nullptr){
                head = nodo;
                head->next = nullptr;
            }
            else{
                Node* temp = head;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = nodo;
            }
            nodo->next = nullptr;
            nodes++;
//            throw ("sin definir");
        }

        T pop_front(){
            if (head == nullptr){
                return 0;
            }
            else{
                T val = head->data;
                Node* temp = head;
                head = head->next;
                delete temp;
                nodes--;
                return val;
            }
//            throw ("sin definir");
        }

        T pop_back(){
            if (head == nullptr){
                return 0;
            }
            else if (head->next == nullptr){
                T val = head->data;
                delete head;
                head = nullptr;
                nodes--;
                return val;
            }
            else{
                Node* temp = head;
                while (temp->next->next != nullptr){
                    temp = temp->next;
                }
                T val = temp->next->data;
                delete temp->next;
                temp->next = nullptr;
                nodes--;
                return val;
            }
//            throw ("sin definir");
        }

        T insert(T data, int pos){
            if (is_empty() || pos>size()){
                push_back(data);
            }
            else if (pos == 1){
                push_front(data);
            }
            else{
                Node* nodo = new Node();
                nodo->data = data;
                Node* temp  = head;
                int i = 1;
                while (i++<pos-1){
                    temp = temp->next;
                }
                nodo->next = temp->next;
                temp->next = nodo;
                nodes++;
            }
            return data;
//            throw ("sin definir");
        }

        bool remove(int pos){
            if (pos>nodes){
                return false;
            }
            else if (pos == 1){
                pop_front();
                nodes--;
                return true;
            }
            else{
                Node* temp  = head;
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
            if (pos == 1){
                return head->data;
            }
            else{
                Node* temp  = head;
                int i = 1;
                while (i++<pos-1){
                    temp = temp->next;
                }
                return temp->next->data;
            }
//            throw ("sin definir");
        }

        bool is_empty(){
            return head == nullptr;
//            throw ("sin definir");
        }

        int size(){
            return nodes;
//            throw ("sin definir");
        }

        void clear(){
            while (head != nullptr){
                Node* temp = head;
                head = head->next;
                delete temp;
            }
//            throw ("sin definir");
        }
        Node* merge(Node* left, Node* right){
            Node* mergelist;
            if (left->data > right->data){
                mergelist = right;
                right = right->next;

            }
            else{
                mergelist = left;
                left = left->next;
            }
            Node* temp = mergelist;
            while(left != nullptr && right != nullptr){
                if (left->data >= right->data){

                    temp->next = right;
                    right = right->next;
                }
                else{
                    temp->next = left;
                    left = left->next;
                }
                temp = temp->next;
            }
            if (left != nullptr){
                temp->next = left;
            }
            if (right != nullptr){
                temp->next = right;
            }
            return mergelist;
        }
        Node* mergeSort(Node* head_){
            if (head_== nullptr || head_->next == nullptr){
                return head_;
            }
            Node* slow = head_;
            Node* fast =  head_->next;
            while (fast != nullptr){
                fast = fast->next;
                if (fast != nullptr){
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            Node* left = head_;
            Node* right = slow->next;
            slow->next = nullptr;

            left = mergeSort(left);
            right = mergeSort(right);
            return merge(left,right);
        }
        void sort(){

            if (is_sorted()){
                return;
            }
            else{
                head = mergeSort(head);
            }
//            throw ("sin definir");
        }

        bool is_sorted(){
            if (is_empty()){
                return true;
            }
            Node* temp = head;
            while (temp->next != nullptr){
                if (temp->data > temp->next->data){
                    return false;
                }
                temp = temp->next;
            }
            return true;
//            throw ("sin definir");
        }

        void reverse(){
            Node* prev = nullptr;
            Node* temp = head;
            Node* next_;
            while (temp != nullptr){
                next_ = temp->next;
                temp->next = prev;
                prev = temp;
                temp = next_;
            }
            head = prev;
//            throw ("sin definir");
        }

        void display(){
            Node* temp = head;
            while (temp != nullptr){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        std::string name(){
            return "ForwardList";
        }
        
};

#endif