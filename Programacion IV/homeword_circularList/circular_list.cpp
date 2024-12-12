#include "iostream"

using namespace std;

template<typename T>
struct Node{
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(){
        next = nullptr;
        prev = nullptr;
    }

    Node(T value){
        data = value;
    }
};

template<typename T=int>
class CircularList{
public:
    Node<T>* head;
    int sizes;

    CircularList(){
        head = nullptr;
        sizes = 0;
    }
    bool empty(){
        return head== nullptr;
    }
    T front(){
        return head->data;
    }
    T back(){
        return head->prev->data;
    }
    void push_front(int data_) {
//        auto* temp = new Node<T>;
//        Node<T>* tail = head->prev;
//        temp->next = head;
//        temp->prev = tail;
//        tail->next = temp;
//        head->prev = temp;
//        head = temp;
        /// mas corto es si reemplazo ese tail:
        auto temp = new Node<T>(data_);
        if (empty()){
            head = temp;
            head->next = head;
            head->prev = head;
            sizes++;
        }
        else{
            temp->next = head;
            temp->prev = head->prev;
            head->prev->next = temp;
            head->prev = temp;
            head = temp;
            sizes++;

        }

    }
    void push_back(T data_){
        auto temp = new Node<T>(data_);
        if (empty()){
            temp->next = temp;
            temp->prev = temp;
            head = temp;
            sizes++;
        }
        else{
            temp->next = head;
            temp->prev = head->prev;
            head->prev->next = temp;
            head->prev = temp;
            sizes++;

        }

    }
    T pop_front(){
        if (empty()){
            return 0;
        }
        else if (sizes == 1){
            T temp = head->data;
            delete head;
            head = nullptr;
            sizes--;
            return temp;
        }
        else{
            T temp = head->data;
            head->next->prev = head->prev;
            head->prev->next = head->next;
            head = head->next;
            sizes--;
            return temp;
        }
//        Node<T>* tail = head->prev;
//        head->next->prev = tail;
//        tail->next = head->next;
//        head = head->next;
        /// reduciendo aun mas:
//        head->next->prev = head->prev;
//        head->prev->next = head->next;
//        head = head->next;
//            throw ("sin definir");
    }

    T pop_back(){
        if (empty()){
            return 0;
        }
        else if (sizes == 1){
            T temp = head->data;
            delete head;
            head = nullptr;
            sizes--;
            return temp;
        }
        else{
            T temp = head->prev->data;
            head->prev =  head->prev->prev;
            head->prev->next = head;
            sizes--;
            return temp;
        }

//        Node<T>* tail = head->prev;
//        head->prev = tail->prev;
//        tail->prev->next = head;
        /// reduciendo aun mas
//        head->prev = head->prev->prev;
//        head->prev->prev->next = head;
    }
    void insert(T data,int pos){
        if (empty() || pos>=size()){
            push_back(data);
        }
        else if (pos == 1){
            T val = head->data;
            push_front(data);
        }
        else{
            auto new_node = new Node<T>(data);
            Node<T>* temp = head;
            if (pos > sizes/2) {
                for (int i = sizes; i > pos; i--) {
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
            sizes++;
//            auto nodo = new Node<T>(data);
//            Node<T>* temp  = head;
//            int i = 1;
//            while (i++<pos-1){
//                temp = temp->next;
//            }
//            nodo->next = temp->next;
//            nodo->prev = temp;
//            temp->next->prev = nodo;
//            temp->next = nodo;
//            sizes++;
        }
    }
    void remove(int pos){
        if (pos>size()){
            return;
        }
        else if (pos == 1){
            pop_front();
            sizes--;
        }
        else if (pos == size()){
            pop_back();
            sizes--;
        }
        else{
            Node<T>* temp  = head;
            if (pos > sizes/2) {
                for (int i = sizes; i > pos; i--) {
                    temp = temp->prev;
                }
            } else {
                for (int i = 0; i < pos; i++) {
                    temp = temp->next;
                }
            }
            temp = temp->prev->prev;
            temp->next = temp->next->next;
            sizes--;
        }

    }
    T& operator[](int pos){
        if (pos == 1){
            return head->data;
        }
        else if (pos == size()){
            return head->prev->data;
        }
        else{
            Node<T>* temp  = head;
            if (pos > sizes/2) {
                for (int i = sizes; i > pos; i--) {
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
    int size(){
        return sizes;
    }
    void display(){
        Node<T>* temp = head;
        if (temp!= nullptr){
            do {
                cout << temp->data << " ";
                temp = temp->next;
            }
            while (temp != head);
        }
        cout << endl;
    }
    void reverse(){
        if (head == nullptr) {
            return;
        }
        Node<T>* left = head;
        Node<T>* right = head->prev;
        do {
            swap(left->data, right->data);
            left = left->next;
            right = right->prev;
        }
        while (left != right && left->prev != right );
//        Node<T>* current = head;
//        do {
//            std::swap(current->next, current->prev);
//            current = current->prev;
//        } while (current != head);
//        head = head->prev;
    }


};

int main(){
    auto lista = new CircularList;
    lista->push_back(1);
    lista->push_back(2);
    lista->push_back(3);
    lista->push_back(4);
    lista->push_back(5);

    lista->display();
    cout << lista->front() << lista->back() << endl;
    lista->reverse();
    lista->display();
    cout << lista->front() << lista->back();
//    lista->push_back(2);
//    lista->push_back(3);
//    lista->push_back(4);
//    lista->push_back(5);
//    lista->display();
//    cout << lista->size() << endl;
//    lista->insert(6,3);
//    lista->display();
//    lista->remove(6);
//    lista->display();
//    cout << (*lista)[3];


    return 0;
}

