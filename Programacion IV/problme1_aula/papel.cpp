#include "iostream"

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

void sortedInsert(Node*& nodo,int va){
    if(nodo == nullptr){

        Node* temp = new Node(va);
        nodo = temp;

    }
    else if (nodo->next == nullptr){
        Node* temp = new Node(va);
        if (nodo->data <= va){
            nodo->next = temp;
        }
        else{
            temp->next = nodo;
            nodo = temp;
        }
    }
    else{
        Node* temp = nodo;
        Node* valor = new Node(va);
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
void display(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    Node* head = nullptr;
    sortedInsert(head, 12);
    sortedInsert(head, 5);
    sortedInsert(head, 1);
    sortedInsert(head, 10);
    sortedInsert(head, 4);

    //    sortedInsert(head, 10);
//    sortedInsert(head, 4);


    display(head);
    return 0;
}