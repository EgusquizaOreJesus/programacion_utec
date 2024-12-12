#include <iostream>
#include <vector>
using namespace std;
const int M = 5;

template<typename TK>
struct Node{
    TK* keys;
    Node** children;
    int count;
    bool leaf;

    Node(initializer_list<TK> elements){
        this->leaf = true;
        this->keys = new TK[M-1];
        this->children = new Node*[M];
        int i = 0;
        for(auto elem : elements) keys[i++] = elem;
        this->count = i;
    }

    void link_child(int pos, initializer_list<TK> elements){
        //TODO
    }

    string to_string(){
        string cad = "";
        for(int i=0;i<count;i++)
            cad += std::to_string(keys[i]) + ", ";
        return "";
    }
};


void test1(){
    Node<int>* root = new Node<int>({11, 16, 20, 31});
    root->link_child(0, {3, 5});
    root->link_child(1, {12, 15});
    root->link_child(2, {17, 19});
    root->link_child(3, {22, 25, 27, 28});
    root->link_child(4, {32, 36, 37, 38});
    cout<<root->to_string()<<endl;//3,5,11,12,15,16,17,19,20,22,25,27,28,31,32,36,37,38
}

void test2(){
    Node<int>* root = new Node<int>({20});
    root->link_child(0, {11, 16});
    root->link_child(1, {31, 35});
    root->children[0]->link_child(0, {3, 5});
    root->children[0]->link_child(1, {12, 15});
    root->children[0]->link_child(2, {17, 19});
    root->children[1]->link_child(0, {22, 25, 27, 28});
    root->children[1]->link_child(1, {32, 33});
    root->children[1]->link_child(2, {36, 38});
    cout<<root->to_string()<<endl;//3,5,11,12,15,16,17,19,20,22,25,27,28,31,32,33,35,36,38
}

int main(){
    test1();
    test2();
}