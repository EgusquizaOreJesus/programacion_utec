#ifndef FORWARD_H
#define FORWARD_H
#include <iostream>
#include "list.h"

// TODO: Implement all methods
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
         	// TODO            
        }

        T front(){
            return head->data;
        }

        T back(){
            if (head == nullptr){
                return 0;
            }
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            return temp->data;
        }

        void push_front(T data){
            Node* temp = new Node(data);
            temp->next = head;
            head = temp;
            nodes++;

        }

        void push_back(T data){
            if (nodes == 0){
                auto temp = new Node(data);
                head = temp;
            }
            else{
                Node* valor = new Node(data);
                Node* temp = head;
                while (temp->next != nullptr)
                    temp = temp->next;
                temp->next = valor;
            }
            nodes++;

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
        }

        T pop_back(){
            if (head == nullptr){
                return 0;
            }
            else if (head->next == nullptr) {
                std::cout << "caso 1" << std::endl;
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
                Node* temp2 = temp->next;
                T val = temp2->data;
                delete temp2;
                temp->next = nullptr;
                nodes--;
                return val;
            }
        }

        T insert(T data, int pos){
            Node* valor = new Node(data);
            if (pos < 1){
                this->push_front(data);
            }
            else if (pos > nodes){
                this->push_back(data);
            }
            else{
                Node* temp = head;
                for (int i = 1; i < pos; ++i) {
                    temp = temp->next;
                }
                valor->next = temp->next;
                temp->next = valor;
            }
            nodes++;

            return valor->data;

        }

        T remove(int pos){
            if (head == nullptr){
                return 0;
            }
            if (pos < 1){
                nodes--;
                return this->pop_front();
            }
            else if (pos > nodes){
                nodes--;
                return this->pop_back();
            }
            else{
                Node* temp = head;
                for (int i = 1; i < pos; ++i) {
                    temp = temp->next;
                }
                T val = temp->next->data;
                Node* temp2 = temp->next;
                temp->next = temp->next->next;
                delete temp2;
                nodes--;
                return val;
            }
        }

        T& operator[](int pos){
            Node* temp = head;
            for (int i = 0; i < pos; ++i) {
                temp = temp->next;
            }
            return temp->data;
        }

        bool is_empty(){
            return nodes == 0;
        }

        int size(){
            return nodes;
        }

        void clear(){
            while (head != nullptr){
                Node* temp = head;
                head = head->next;
                nodes--;
                delete temp;
            }
        }
        
        void sort(){
        }

        bool is_sorted(){
            Node* temp = head;
            // ASCENDENTE
            while (temp->next != nullptr){
                if (temp->data > temp->next->data){
                    return false;
                }
                temp = temp->next;
            }
            return true;
        }

        void reverse(){
            Node* prev = nullptr;
            Node* next;
            Node* temp = head;
            while (temp != nullptr) {
                next = temp->next;      // le pasamos la cadena de punteros del temp->next
                temp->next = prev;      // descolgamos el temp->next para que apunte al previo
                prev = temp;            // asignamos al previo el temp ya descolgado
                temp = next;            // reseteamos el temp para que ahora sea la siguiente cadena del next
            }
            head = prev;        // cambiamos la direccion donde apunte head
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
        std::string name(){
            return "ForwardList";
        }
        
};

#endif