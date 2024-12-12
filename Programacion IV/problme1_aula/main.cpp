#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node();
    Node(int val){
        data = val;
        next = nullptr;
    }

};

Node::Node() {
    data = int{};
    next = nullptr;
}

class Lista{
    Node* head;
public:
    Lista(){
        head = nullptr;
    }
    void push_front(int data_){
        Node* nodo = new Node;
        nodo->data = data_;
        nodo->next = head;
        head = nodo;
    }
    void push_back(int data_){
        Node* nodo = new Node;
        nodo->data = data_;
        if (head == nullptr){
            head = nodo;
        }
        else{
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = nodo;
        }
        nodo->next = nullptr;
    }
    void pop_front(){
        if (head == nullptr){
            cout << "LIST VACIA" << endl;
        }
        else{
            Node* temp = head;
            head = head->next;
            delete temp;
        }

    }
    int& operator[](int pos){
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
    }
    void pop_back(){
        if (head == nullptr){
            cout << "LIST VACIA" << endl;
        }
        else if (head->next == nullptr){
            delete head;
            head = nullptr;
        }
        else{
            Node* temp = head;
            while (temp->next->next != nullptr){
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
    }
    void clear(){
        while (head != nullptr){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void reverse(){
        Node* prev = nullptr;
        Node* temp = head;
        Node* next_ = nullptr;
        while (temp != nullptr){
            next_ = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next_;
        }
        head = prev;

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
    // function to perform insertion sort on a linked list
    void insertionSort() {
        if (head == nullptr || head->next == nullptr)
            return;

        Node* sortedList = nullptr; // initialize the sorted list

        while (head != nullptr) {
            Node* currNode = head;
            head = head->next; // advance head

            if (sortedList == nullptr || currNode->data < sortedList->data) {
                currNode->next = sortedList;
                sortedList = currNode;
            }
            else {
                Node* tempNode = sortedList;
                while (tempNode->next != nullptr && currNode->data > tempNode->next->data) {
                    tempNode = tempNode->next;
                }
                currNode->next = tempNode->next;
                tempNode->next = currNode;
            }
        }

        head = sortedList; // update the head pointer to point to the sorted list
    }
    friend Lista* Mezclar(Lista* list1, Lista* list2);
    friend Lista* Mezclar2(Lista* list1, Lista* list2);
    friend Lista* interseccion(Lista* list1, Lista* list2);
    void display(){
        Node* temp = head;
        while (temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
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
    bool empty(){
        return head== nullptr;
    }
    void insert(int data,int pos){
        if (empty() || pos>size()){
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
        }

    }

};

Node* merge(Node* left, Node* right){
    Node* mergelist = nullptr;
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

Node* mergeSort(Node*& head){
    if (head== nullptr || head->next == nullptr){
        return head;
    }
    Node* slow = head;
    Node* fast =  head->next;
    while (fast != nullptr){
        fast = fast->next;
        if (fast != nullptr){
            slow = slow->next;
            fast = fast->next;
        }
    }
    Node* left = head;
    Node* right = slow->next;
    slow->next = nullptr;

    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left,right);

}


Lista* Mezclar(Lista* list1, Lista* list2) {
    auto list = new Lista;
    Node* temp1 = list1->head;
    Node* temp2 = list2->head;
    Node* init = new Node();
    Node* tail = init;
    Node* final;
    while(temp1!= nullptr && temp2 != nullptr){
        if (temp1->data <= temp2->data){
            list->push_front(temp1->data);
            temp1 = temp1->next;
        }
        else{
            list->push_front(temp2->data);
            temp2 = temp2->next;
        }
    }
    while (temp1 != nullptr){
        list->push_front(temp1->data);
        temp1 = temp1->next;
    }
    while (temp2 != nullptr){
        list->push_front(temp2->data);
        temp2 = temp2->next;
    }
    return list;
}
Lista* Mezclar2(Lista* list1, Lista* list2) {
    Node* temp1 = list1->head;
    Node* temp2 = list2->head;
    Node* init = new Node();
    Node* tail = init;
    Node* final;
    while(temp1!= nullptr && temp2 != nullptr){
        if (temp1->data <= temp2->data){
            tail->next = temp1;
            tail = tail->next;
            temp1 = temp1->next;
        }
        else{
            tail->next = temp2;
            tail = tail->next;
            temp2 = temp2->next;
        }
    }
    if (temp1!= nullptr){
        tail->next = temp1;
        tail = tail->next;
    }
    if (temp2!= nullptr){
        tail->next = temp2;
        tail = tail->next;
    }
//    while (temp1 != nullptr){
//        list->push_front(temp1->data);
//        temp1 = temp1->next;
//    }
//    while (temp2 != nullptr){
//        list->push_front(temp2->data);
//        temp2 = temp2->next;
//    }
    auto list = new Lista;
    list->head = init->next;
    return list;
}

Lista* interseccion(Lista* list1, Lista* list2){

    Node* temp1 = list1->head;
    Node* temp2 = list2->head;
    Node* init = new Node();
    Node* nodo = init;
    while(temp1!= nullptr && temp2 != nullptr){

        if (temp1->data < temp2->data){
            temp1 = temp1->next;
        }
        else if (temp2->data < temp1->data){
            temp2 = temp2->next;
        }
        else{
            nodo->next = temp1;
            nodo = nodo->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    nodo->next = nullptr;
    auto list = new Lista;
    list->head = init->next;
    return list;
}
void sortedInsert(Node* nodo,int va){
    if(nodo == nullptr){
        Node* temp = new Node(va);
        nodo = temp;
    }
    else{
        Node* temp = nodo;
        while(temp->data < nodo->data){
            temp = temp->next;
        }

    }
}
void display(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " " << endl;
        temp = temp->next;
    }
    cout << endl;
}
void push_back(Node*& head,int val){
    Node* nodo = new Node(val);
    if (head == nullptr){
        head = nodo;
    }
    else{

        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = nodo;
    }
}
int main() {
//    sortedInsert(head,2);
//    display(head);

    //    auto list2 = new Lista;
//    list2->push_back(3);
//    list2->push_back(6);
//    list2->push_back(7);
//    list2->display();
//    Lista* lista = Mezclar2(list1, list2);
//    lista->display();
    Node* head = nullptr;
    Node* head2 = nullptr;

    push_back(head,3);
    push_back(head,5);

    push_back(head,2);
    display(head);

    push_back(head,1);
    push_back(head2,4);
    push_back(head2,5);
    Node* result = merge(head,head2);
    display(result);
    result = mergeSort(result);
    display(result);
//    temp->next->data = 4;
//    temp->next->next->data = 1;


    return 0;
}
