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
                // TODO
            }

            Node(T value){
                data = value;
                next = nullptr;
                prev = nullptr;
                // TODO
            }

            void killSelf(){
                // TODO      
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
         	// TODO            
        }

         T front(){
             if (head == nullptr){
                 return 0;
             }
             return head->data;
        }

        T back(){
            if (tail == nullptr){
                return 0;
            }
            return tail->data;
        }

        void push_front(T data){
            if (nodes == 0){
                auto temp = new Node(data);
                head = temp;
                tail = temp;
                nodes++;
            }else{
                Node* temp = new Node(data);
                temp->prev = nullptr;
                temp->next = head;
                head->prev = temp;
                head = temp;
                nodes++;
            }

        }

        void push_back(T data){
            if (nodes == 0){
                auto temp = new Node(data);
                head = temp;
                tail = temp;
                nodes++;
            }else{
                Node* temp = new Node(data);
                temp->prev = tail;
                temp->next = nullptr;
                tail->next = temp;
                tail = temp;
                nodes++;
            }

        }

        T pop_front(){
            if (nodes == 0){
                return 0;
            }
            T val = head->data;
            if (head->next == nullptr){
                nodes--;
                delete head;
                head = nullptr;
                tail = nullptr;
                return val;
            }
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
            nodes--;
            return val;
        }
        void printear(){
            if (head == nullptr){
                return;
            }
            Node* temp = head;
            while (temp != nullptr){
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }
        T pop_back(){
            if (nodes == 0){
                return 0;
            }
            T val = tail->data;
            if (tail->prev == nullptr){
                nodes--;
                delete tail;
                tail = nullptr;
                head = nullptr;
                return val;
            }
            tail = tail->prev;

            delete tail->next;
            tail->next = nullptr;
            nodes--;
        }

        T insert(T data, int pos){
        }

        T remove(int pos){
        }

        T& operator[](int pos){
        }

        bool is_empty(){
        }

        int size(){
        }

        void clear(){
        }
        
        void sort(){
        }

        bool is_sorted(){
        }

        void reverse(){
        }

        std::string name(){
            return "ForwardList";
        }
        
};
#endif