#include "iostream"

using namespace std;

template<typename T>
struct Node{
    T data;
    Node<T>* next;
    Node<T>* prev;
};

template<typename T=int>
class List{
    Node<T>* head;
    Node<T>* tail;
public:
    List(){
        head = nullptr;
        tail = nullptr;
    }
    bool empty(){
        return head== nullptr && tail== nullptr;
    }
    T front(){
        if (empty()){
            return 0;
        }
        return head->data;
    }
    T back(){
        if (empty()){
            return 0;
        }
        return tail->data;
    }
    void push_front(T data_){
        if (empty()){
            auto temp = new Node<T>;
            temp->data = data_;
            temp->next = nullptr;
            temp->prev = nullptr;
            head = temp;
            tail = temp;
        }
        else{
            auto temp = new Node<T>;
            temp->data = data_;
            temp->prev = nullptr;
            temp->next = head;
            head->prev = temp;
            head = temp;
        }

    }
    void push_back(T data_){
        if (empty()){
            auto temp = new Node<T>;
            temp->data = data_;
            temp->next = nullptr;
            temp->prev = nullptr;
            head = temp;
            tail = temp;
        }
        else{
            auto temp = new Node<T>;
            temp->data = data_;
            temp->prev = tail;
            temp->next = nullptr;
            tail->next = temp;
            tail = temp;
        }

    }
    T pop_front(){
//        Node* temp = head;
//        head = head->next;
//        head->prev = nullptr;
//        delete temp;
        /// OTRA FORMA DE HACERLO SIN TEMP;
        if (empty()){
            return 0;
        }
        else if (head->next == nullptr && head->prev == nullptr){
            T data_ = head->data;
            delete head;
            head = nullptr;
            tail = nullptr;
            return data_;
        }
        else{
            T data_ = head->data;
            head=head->next;
            delete head->prev;
            head->prev = nullptr;
            return data_;
        }

    }
    T pop_back(){
        if (empty()){
            return 0;
        }
        else if(tail->next== nullptr && tail->prev == nullptr){
            T data_ = tail->data;
            delete tail;
            head = nullptr;
            tail = nullptr;
            return data_;
        }
        else{
            T data_ = tail->data;
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
            return data_;
        }
    }
    void insert(T data,int pos){
        auto nodo = new Node<T>();
        nodo->data = data;
        Node<T>* temp  = head;
        int i = 0;
        while (i++<pos-1){
            temp = temp->next;
        }
        nodo->next = temp->next;
        nodo->prev = temp;
        temp->next->prev = nodo;
        temp->next = nodo;
    }
    void remove(int pos){
        auto nodo = new Node<T>();
        Node<T>* temp  = head;
        int i = 1;
        if (pos == 1){
            pop_front();
        }
        else{
            while (i++<pos-1){
                temp = temp->next;
            }
            nodo = temp->next->next;
            temp->next = nodo;
        }

    }
    T& operator[](int pos){
        Node<T>* temp = head;
        int i = 0;
        if (!empty()){
            while (i++<pos-1){
                temp = temp->next;
            }
            return temp->data;
        }
    }
    int size(){
        Node<T>* temp = head;
        if (empty()){
            return 0;
        }
        int size_=1;
        while (temp->next!= nullptr){
            temp = temp->next;
            size_++;
        }
        return size_;
    }
    void display(){
        Node<T>* temp = head;
        while (temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void reverse(){
        auto nodo = new Node<T>;
        nodo = tail->prev;
    }


};

int main(){
    auto lista = new List;
    lista->push_back(1);
    lista->push_back(2);
    lista->push_back(3);
    lista->push_back(4);
    lista->push_back(5);
    lista->display();
    cout << lista->size() << endl;
    lista->insert(6,3);
    lista->display();
    lista->remove(6);
    lista->display();
    cout << (*lista)[3];


    return 0;
}