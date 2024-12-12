//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct StackNode {
    int data;
    StackNode *next;
    StackNode(int a) {
        data = a;
        next = NULL;
    }
};

class MyStack {
private:
    StackNode *top;

public:
    void push(int);
    int pop();
    MyStack() { top = NULL; }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        MyStack *sq = new MyStack();

        int Q;
        cin >> Q;
        while (Q--) {
            int QueryType = 0;
            cin >> QueryType;
            if (QueryType == 1) {
                int a;
                cin >> a;
                sq->push(a);
            } else if (QueryType == 2) {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
    }
}

// } Driver Code Ends


//Function to push an integer into the stack.
void MyStack ::push(int x)
{
    auto nodo = new StackNode(x);

    if (top == nullptr){
        top=nodo;
        return;
    }
    StackNode* temp = top;
    while (temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = nodo;
    // Your Code
}

//Function to remove an item from top of the stack.
int MyStack ::pop()
{
    if (top == nullptr){
        return 0;
    }
    else if (top->next == nullptr){
        StackNode* temp = top;
        int data_ = top->data;
        delete top;
        top = nullptr;
        return data_;
    }
    else{
        StackNode* temp = top;
        while (temp->next->next != nullptr){
            temp = temp->next;
        }
        int data_ = temp->next->data;
        delete temp->next;
        temp->next = nullptr;
        return data_;
    }
}