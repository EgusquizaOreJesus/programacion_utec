#include "iostream"

using namespace std;
struct NodeF{
    int data;
    NodeF* next;
    NodeF();
    NodeF(int val){
        data = val;
        next = nullptr;
    }

};
struct Node{
    int data;
    Node* next;
    Node* prev;
    Node();
    Node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
class DoubleList{
    Node* head;
    Node* tail;
public:
    DoubleList(){
        head = nullptr;
        tail = nullptr;
    }
    bool empty(){
        return head== nullptr && tail== nullptr;
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


};
void push_back(DoubleList*& list, int val){
    if (list->empty()){
        Node* temp = new Node(val);
        list->setHead(temp);
        list->setTail(temp);
    }
    else{
        Node* temp = new Node(val);
        temp->prev = list->getTail();
        temp->next = nullptr;
        list->getTail()->next = temp;
        list->setTail(temp);
    }

}
bool is_palindrome(DoubleList* lista){
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
void sortedInsert(NodeF*& nodo,int va){
    if(nodo == nullptr){

        NodeF* temp = new NodeF(va);
        nodo = temp;

    }
    else if (nodo->next == nullptr){
        NodeF* temp = new NodeF(va);
        if (nodo->data <= va){
            nodo->next = temp;
        }
        else{
            temp->next = nodo;
            nodo = temp;
        }
    }
    else{
        NodeF* temp = nodo;
        NodeF* valor = new NodeF(va);
        if (va < temp->data){
            valor->next = nodo;
            nodo = valor;
        }
        else{
            while(temp->next != nullptr){

                if (temp->data < va && temp->next->data > va){
                    valor->next = temp->next;
                    temp->next = valor;
                    break;
                }
                temp = temp->next;
            }
        }

        if (temp->next == nullptr){
            temp->next = valor;
        }
    }
}
void display(NodeF* head){
    NodeF* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


//#include <iostream>
#include <iostream>
using namespace std;

void test_sortedinsert(){
    NodeF* head = nullptr;
    sortedInsert(head, 2);
    sortedInsert(head, 5);
    sortedInsert(head, 1);
    sortedInsert(head, 10);
    sortedInsert(head, 4);
    display(head);//1->2->4->5->10->
}

void test_palindrome()
{
    DoubleList* list1 = new DoubleList();
    push_back(list1, 1);
    push_back(list1, 2);
    push_back(list1, 3);
    push_back(list1, 2);
    push_back(list1, 1);
    cout<<"List1 is palindrome:"<<is_palindrome(list1)<<endl;//1

    DoubleList* list2 = new DoubleList();
    push_back(list2, 1);
    push_back(list2, 2);
    push_back(list2, 3);
    push_back(list2, 3);
    push_back(list2, 2);
    push_back(list2, 1);
    cout<<"List2 is palindrome:"<<is_palindrome(list2)<<endl;//1

    DoubleList* list3 = new DoubleList();
    push_back(list3, 1);
    push_back(list3, 2);
    push_back(list3, 3);
    push_back(list3, 3);
    cout<<"List3 is palindrome:"<<is_palindrome(list3)<<endl;//0
}


int main() {
    cout<<"test_sortedinsert:"<<endl;
    test_sortedinsert();

    cout<<"test_palindrome:"<<endl;
    test_palindrome();
    return 0;
}