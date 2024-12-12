#include <iostream>

using namespace std;

template<typename T>
struct Node{
    T data;
    Node* next;
};

template<typename T=int>
class Lista{
    Node<T>* head;
public:
    Lista(){
        head = nullptr;
    }
    T front(){
        return head->data;
    }

    T back(){
        Node<T>* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        return temp->data;
    }
    void push_front(int data_){
        Node<T>* nodo = new Node<T>;
        nodo->data = data_;
        nodo->next = head;
        head = nodo;
    }
    void push_back(int data_){
        Node<T>* nodo = new Node<T>;
        nodo->data = data_;
        if (empty()){
            head = nodo;
        }
        else{
            Node<T>* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = nodo;
        }
        nodo->next = nullptr;
    }
    T pop_front(){
        if (empty()){
            return 0;
        }
        else{
            Node<T>* temp = head;
            T data_ = head->data;
            head = head->next;
            delete temp;
            return data_;
        }


    }
    T pop_back(){
        if (head == nullptr){
            return 0;
        }
        else if (head->next == nullptr){
            Node<T>* temp = head;
            T data_ = head->data;
            delete head;
            head = nullptr;
            return data_;
        }
        else{
            Node<T>* temp = head;
            while (temp->next->next != nullptr){
                temp = temp->next;
            }
            T data_ = temp->next->data;
            delete temp->next;
            temp->next = nullptr;
            return data_;
        }
    }
    T& operator[](int x){
        int recorr=0;
        Node<T>* temp = head;
        while (temp != nullptr){
            recorr++;
            if (recorr == x){
                return temp->data;
            }
            temp = temp->next;
        }
    }
    bool empty(){
        if (head== nullptr){
            return true;
        }
        return false;
    }
    int size(){
        if (head == nullptr){
            return 0;
        }
        else if(head->next == nullptr){
            return head->data;
        }
        else{
            Node<T>* temp = head;
            int size_ = 1;
            while (temp->next != nullptr){
                temp = temp->next;
                size_++;
            }
            return size_;
        }


    }
    void clear(){
        while (head != nullptr){
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void reverse(){
        Node<T>* prev = nullptr;
        Node<T>* temp = head;
        Node<T>* next_ = nullptr;
        while (temp != nullptr){
            if (next_!= nullptr){
                cout << next_->data;
            }
            next_ = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next_;
        }
        head = prev;

    }
    // function to perform insertion sort on a linked list
    void insertionSort() {
        if (head == nullptr || head->next == nullptr)
            return;

        Node<T>* sortedList = nullptr; // initialize the sorted list

        while (head != nullptr) {
            Node<T>* currNode = head;
            head = head->next; // advance head

            if (sortedList == nullptr || currNode->data < sortedList->data) {
                currNode->next = sortedList;
                sortedList = currNode;
            }
            else {
                Node<T>* tempNode = sortedList;
                while (tempNode->next != nullptr && currNode->data > tempNode->next->data) {
                    tempNode = tempNode->next;
                }
                currNode->next = tempNode->next;
                tempNode->next = currNode;
            }
        }

        head = sortedList; // update the head pointer to point to the sorted list
    }
    void display(){
        Node<T>* temp = head;
        while (temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    auto list1 = new Lista;
    list1->push_back(1);
    list1->push_back(2);
    list1->push_back(3);
    list1->push_back(4);
    list1->push_back(5);
    list1->push_back(6);
    list1->display();
    list1->clear();
    list1->pop_front();
    list1->display();

    return 0;
}