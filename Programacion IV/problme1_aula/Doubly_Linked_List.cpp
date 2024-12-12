#include "iostream"

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

class List{
    Node* head;
    Node* tail;
    int nodes;
public:
    List(){
        head = nullptr;
        tail = nullptr;
    }
    bool empty(){
        return head== nullptr && tail== nullptr;
    }
    void push_front(int data_){
        if (empty()){
            auto temp = new Node;
            temp->data = data_;
            temp->next = nullptr;
            temp->prev = nullptr;
            head = temp;
            tail = temp;
        }
        else{
            auto temp = new Node;
            temp->data = data_;
            temp->prev = nullptr;
            temp->next = head;
            head->prev = temp;
            head = temp;
        }

    }
    void push_back(int data_){
        if (empty()){
            auto temp = new Node;
            temp->data = data_;
            temp->next = nullptr;
            temp->prev = nullptr;
            head = temp;
            tail = temp;
        }
        else{
            auto temp = new Node;
            temp->data = data_;
            temp->prev = tail;
            temp->next = nullptr;
            tail->next = temp;
            tail = temp;
        }

    }
    Node* getHead(){
        return head;
    }
    Node* getTail(){
        return tail;
    }
    void setHead(Node* h){
        head = h;
    }
    void setTail(Node* t){
        tail = t;
    }
    int pop_front(){
//        Node* temp = head;
//        head = head->next;
//        head->prev = nullptr;
//        delete temp;
        /// OTRA FORMA DE HACERLO SIN TEMP;
        if (empty()){
            throw ;
        }
        else if (head->next == nullptr && head->prev == nullptr){
            int val = head->data;
            delete head;
            head = nullptr;
            tail = nullptr;
            return val;
        }
        else{
            int val = head->data;
            head=head->next;
            delete head->prev;
            head->prev = nullptr;
            return val;
        }

    }
    int front(){
        return head->data;
    }
    int back(){
        return tail->data;
    }

    void pop_back(){
        if (empty()){
            return;
        }
        else if(tail->next== nullptr && tail->prev == nullptr){
            delete tail;
            head = nullptr;
            tail = nullptr;
        }
        else{
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
    }
    void insert(int data,int pos){
        if (empty() || pos>=size()){
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
            nodo->prev = temp;
            temp->next->prev = nodo;
            temp->next = nodo;
        }

    }
    void display(){
        Node* temp = head;
        while (temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void remove(int pos){

        if (pos == 1){
            pop_front();
        }
        else{
            Node* temp  = head;
            int i = 1;
            while (i++<pos-1){
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }
    }
    int size(){
        Node* temp = head;
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
    int size2(){
        throw nodes;
    }
    void clear(){
        delete head;
        delete tail;
        head = nullptr;
        tail = nullptr;
    }
    int& operator[](int pos){
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
    }
    void reverse() {
        if (empty() || head == tail) {
            return;
        }
        Node* left = head;
        Node* right = tail;
        while (left != right && left->prev != right ) {
            swap(left->data, right->data);
            left = left->next;
            right = right->prev;
        }
    }


};
void push_back(List*& list, int val){
    if (list->empty()){
        Node* temp = new Node;
        temp->data = val;
        temp->next = nullptr;
        temp->prev = nullptr;
        list->setHead(temp);
        list->setTail(temp);
    }
    else{
        auto temp = new Node;
        temp->data = val;
        temp->prev = list->getTail();
        temp->next = nullptr;
        list->getTail()->next = temp;
        list->setTail(temp);
    }

}
bool is_palindrome(List* lista){
    Node* temp1 = lista->getHead();
    Node* temp2 = lista->getTail();
    while(temp1->next != temp2 && temp1 != temp2){
        if (temp1->data != temp2->data){
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->prev;
    }
    return true;
}
int main(){
    List* list1 = new List();
    List* list2 = new List;
    push_back(list1, 1);
    push_back(list1, 2);
    push_back(list1, 3);
    push_back(list1, 2);
    push_back(list1, 1);
    cout<<"List1 is palindrome:"<<is_palindrome(list1)<<endl;//1
    push_back(list2, 1);
    push_back(list2, 2);
    push_back(list2, 3);
    push_back(list2, 3);
    push_back(list2, 2);
    push_back(list2, 1);
    cout<<"List2 is palindrome:"<<is_palindrome(list2)<<endl;//1
    // && left->prev != right
    List* list3 = new List();
    push_back(list3, 1);
    push_back(list3, 2);
    push_back(list3, 3);
    push_back(list3, 3);
    cout<<"List3 is palindrome:"<<is_palindrome(list3)<<endl;//0


    return 0;
}