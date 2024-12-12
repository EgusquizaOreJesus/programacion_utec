#ifndef CIRCULAR_H
#define CIRCULAR_H
#include <iostream>
#include "list.h"
// TODO: Implement all methods
template <typename T>
class CircularList : public List<T> {  
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
                data = value;
                next = nullptr;
                prev = nullptr;
            }

            [[maybe_unused]]void killSelf(){
                delete this;
            }    
        };

    private:
        Node* head;//sentinel
        int nodes; 

    public:
        CircularList() : List<T>() {
            head = nullptr;
            nodes = 0;
        }

        ~CircularList(){
            delete head;
           // TODO
        }       

         T front(){
             return head->data;
//            throw ("sin definir");
        }

        T back(){
            return head->prev->data;
//            throw ("sin definir");
        }

        void push_front(T data){
            auto temp = new Node(data);
            if (is_empty()){
                head = temp;
                head->next = head;
                head->prev = head;
                nodes++;
            }
            else{
                temp->next = head;
                temp->prev = head->prev;
                head->prev->next = temp;
                head->prev = temp;
                head = temp;
                nodes++;
            }
//            throw ("sin definir");
        }

        void push_back(T data){
            auto temp = new Node(data);
            if (is_empty()){
                temp->next = temp;
                temp->prev = temp;
                head = temp;
                nodes++;
            }
            else{
                temp->next = head;
                temp->prev = head->prev;
                head->prev->next = temp;
                head->prev = temp;
                nodes++;

            }
//            throw ("sin definir");
        }

        T pop_front(){
            if (is_empty()){
                return 0;
            }
            else if (nodes == 1){
                T temp = head->data;
                delete head;
                head = nullptr;
                nodes--;
                return temp;
            }
            else{
                T temp = head->data;
                head->next->prev = head->prev;
                head->prev->next = head->next;
                head = head->next;
                nodes--;
                return temp;
            }
//            throw ("sin definir");
        }

        T pop_back(){
            if (is_empty()){
                return 0;
            }
            else if (nodes == 1){
                T temp = head->data;
                delete head;
                head = nullptr;
                nodes--;
                return temp;
            }
            else{
                T temp = head->prev->data;
                head->prev =  head->prev->prev;
                head->prev->next = head;
                nodes--;
                return temp;
            }
//            throw ("sin definir");
        }

        T insert(T data, int pos){
            if (is_empty() || pos>=size()){
                push_back(data);
            }
            else if (pos == 1){
                T val = head->data;
                push_front(data);
            }
            else{
                auto new_node = new Node(data);
                Node* temp = head;
                if (pos > nodes/2) {
                    for (int i = nodes; i > pos; i--) {
                        temp = temp->prev;
                    }
                } else { // Search from front
                    for (int i = 0; i < pos; i++) {
                        temp = temp->next;
                    }
                }
                temp = temp->prev;
                new_node->next = temp;
                new_node->prev = temp->prev;
                temp->prev->next = new_node;
                temp->prev = new_node;
                nodes++;
            }
            return data;
//            throw ("sin definir");
        }

        bool remove(int pos){
            if (pos>size() || is_empty()){
                return false;
            }
            else if (pos == 1){
                pop_front();
                nodes--;
                return true;
            }
            else if (pos == size()){
                pop_back();
                nodes--;
                return true;
            }
            else{
                Node* temp  = head;
                if (pos > nodes/2) {
                    for (int i = nodes; i > pos; i--) {
                        temp = temp->prev;
                    }
                } else {
                    for (int i = 0; i < pos; i++) {
                        temp = temp->next;
                    }
                }
                temp = temp->prev->prev;
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
                return head->prev->data;
            }
            else{
                Node* temp  = head;
                if (pos > nodes/2) {
                    for (int i = nodes; i > pos; i--) {
                        temp = temp->prev;
                    }
                } else {
                    for (int i = 0; i < pos; i++) {
                        temp = temp->next;
                    }
                }
                return temp->prev->data;
            }
        }

        bool is_empty(){
            return head== nullptr;
//            throw ("sin definir");
        }

        int size(){
            return nodes;
//            throw ("sin definir");
        }

        void clear(){
            delete head;
            head = nullptr;
//            throw ("sin definir");
        }
        Node* merge(Node* left, Node* right){
            Node* mergelist;
//            std::cout << "entrando merge";
            if (left->data > right->data){
                mergelist = right;
                right = right->next;

            }
            else{
                mergelist = left;
                left = left->next;
            }
            Node* temp = mergelist;
            do {
                if (left->data >= right->data){

                    temp->next = right;
                    right = right->next;
                }
                else{
                    temp->next = left;
                    left = left->next;
                }
                temp = temp->next;
            } while(left->next != left && right->next != right);
            if (left->next != left){
                temp->next = left;
            }
            if (right->next != right){
                temp->next = right;
            }
            return mergelist;
        }
        Node* mergeSort(Node* head_){
//            std::cout << "entrando al merge" << std::endl;
            if (head_== nullptr || head_->next == head_){
                return head_;
            }
//            std::cout << "condicional princial " << std::endl;
            Node* slow = head_;
            Node* fast =  head_->next;
            while (fast != head_){
                fast = fast->next;
                if (fast != head_){
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            fast = fast->prev;
//            std::cout << "saliendo del bucle" << std::endl;
            Node* left = head_;
            Node* right = slow->next;
            left->prev = slow;
            slow->next = left;
            right->prev = fast;
            fast->next = right;
//            std::cout << "condicionales" << std::endl;
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
//            std::cout << "ORDENADO " << std::endl;
        }

        bool is_sorted(){
//            std::cout << "IS SORTED" << std::endl;
            if (is_empty()){
                return true;
            }
            Node* temp = head;
            if (temp!= nullptr){
                do {
                    if (temp->data > temp->next->data){
                        return false;
                    }
                    temp = temp->next;
                }
                while (temp != head);
            }
            return true;
    //            throw ("sin definir");
        }

        void reverse(){
            if (head == nullptr) {
                return;
            }
            Node* left = head;
            Node* right = head->prev;
            do {
                std::swap(left->data, right->data);
                left = left->next;
                right = right->prev;
            }
            while (left != right && left->prev != right );
//            throw ("sin definir");
        }

        std::string name(){
            return "ForwardList";
        }
};

#endif