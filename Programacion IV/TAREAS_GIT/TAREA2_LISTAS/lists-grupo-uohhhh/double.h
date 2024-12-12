#ifndef DOUBLY_H
#define DOUBLY_H
#include <iostream>
#include "list.h"

// TODO: Implement all methods
template <typename T>
class DoubleList : public List<T> {
    private:
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

            [[maybe_unused]] void killSelf(){
                delete this;
            }    
        };

    private:
        Node* head;
        Node* tail;
        int nodes;

    public:
        DoubleList() : List<T>() {
            head = nullptr;
            tail = nullptr;
            nodes = 0;
        }

        ~DoubleList(){
            delete head;
            delete tail;
         	// TODO
        }

         T front(){
            throw head->data;
        }

        T back(){
            throw tail->data;
        }

        void push_front(T data){
            if (is_empty()){
                auto temp = new Node(data);
                temp->next = nullptr;
                temp->prev = nullptr;
                head = temp;
                tail = temp;
                nodes++;
//                throw ;
            }
            else{
                auto temp = new Node(data);
                temp->prev = nullptr;
                temp->next = head;
                head->prev = temp;
                head = temp;
                nodes++;
//                throw ;
            }
        }

        void push_back(T data){
            if (is_empty()){
                auto temp = new Node(data);
                temp->data = data;
                temp->next = nullptr;
                temp->prev = nullptr;
                head = temp;
                tail = temp;
                nodes++;
//                throw ;
            }
            else{
                auto temp = new Node(data);
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

        T insert(T data, int pos){
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
                Node* nodo = new Node(data);
                Node* temp  = head;
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

        bool remove(int pos){
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
            else if (pos == size()){
                return tail->data;
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
            return head== nullptr && tail== nullptr;
            //            throw ("sin definir");
        }

        int size(){
            return nodes;
//            throw ("sin definir");
        }

        void clear(){
            delete head;
            delete tail;
            head = nullptr;
            tail = nullptr;
            nodes = 0;
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
            Node* temp = head;
            while (temp->next != nullptr){
                temp = temp->next;
            }
            tail = temp;
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
            if (is_empty() || head == tail) {
                return;
            }
            Node* left = head;
            Node* right = tail;
            while (left != right && left->prev != right ) {
                std::swap(left->data, right->data);
                left = left->next;
                right = right->prev;
            }
//            throw ("sin definir");
        }

        std::string name(){
            return "ForwardList";
        }
        
};
#endif