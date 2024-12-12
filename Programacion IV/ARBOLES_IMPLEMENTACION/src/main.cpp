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
    Node() {
        this->leaf = true;
        this->keys = new TK[M-1];
        this->children = new Node*[M];
        count=0;

    }
    Node(initializer_list<TK> elements){
        this->leaf = true;
        this->keys = new TK[M-1];
        this->children = new Node*[M];
        for (int i = 0; i < M; ++i) {
            children[i] = nullptr;
        }
        int i = 0;
        for(auto elem : elements) keys[i++] = elem;
        this->count = i;
    }

    void link_child(int pos, initializer_list<TK> elements){
        Node* newChild = new Node(elements);
        children[pos] = newChild;
        this->leaf = false;
    }



    void hola(){
        cout << count << endl;
        Node* temp2 = this;
        while (!temp2->leaf){
            temp2 = temp2->children[0];
        }
        for (int i = 0; i < count; ++i) {
            while (!temp2->leaf){
                temp2 = temp2->children[i];
            }
            for (int j = 0; j < temp2->count; ++j) {
                cout << temp2->children[j] << endl;
            }
            cout << temp2;
            cout << "tamaño: " <<temp2->count<< endl;
        }
    }
    string displayIn(Node<TK>* ROOT){
        if (ROOT == nullptr){
            return "";
        }
        else{
            for (int i = 0; i < ROOT->count; ++i) {
                cout << ROOT->children[i];
            }
            Node<TK>* TEMP = ROOT;
            return displayIn(ROOT->children);
        }
    }


    string to_string() {
        string result;
        if (leaf) {
            for (int i = 0; i < count; ++i) {
                result += std::to_string(keys[i]);
                if (i != count - 1)
                    result += ",";
            }
        } else {
            for (int i = 0; i < count; ++i) {
                result += children[i]->to_string() + ",";
                result += std::to_string(keys[i]) + ",";
                if (i != count - 1)
                    result += ",";
            }
            result += children[count]->to_string();
        }
        return result;
    }
    bool search(const TK& key) {
        int i = 0;
        while (i < count && key > keys[i])
            ++i;

        if (keys[i] == key)
            return true;

        if (leaf)
            return false;

        return children[i]->search(key);
    }
    void range_search_helper(TK start, TK end, vector<TK>& result) {
        int i = 0;
        while (i < count && start > keys[i])
            ++i;

        if (leaf) {
            while (i < count && keys[i] <= end) {
                result.push_back(keys[i]);
                ++i;
            }
        } else {
            while (i < count && keys[i] <= end) {
                children[i]->range_search_helper(start, end, result);
                result.push_back(keys[i]);
                ++i;
            }
            children[i]->range_search_helper(start, end, result);
        }
    }

    vector<TK> range_search(TK begin, TK end) {
        vector<TK> result;
        range_search_helper(begin, end, result);
        return result;
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
    cout<<"search(5):"<<root->search(5)<<endl;//search(5): 1
    cout<<"search(36):"<<root->search(36)<<endl;//search(36): 1
    cout<<"search(13):"<<root->search(13)<<endl;//search(13): 0
    vector<int> result = root->range_search(16, 21);
    for(auto elem : result) cout<<elem<<", ";//16,17,19,20
    cout<<endl;
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
    cout<<"search(35):"<<root->search(35)<<endl;//search(35): 1
    cout<<"search(22):"<<root->search(22)<<endl;//search(22): 1
    cout<<"search(13):"<<root->search(13)<<endl;//search(13): 0
    vector<int> result = root->range_search(30, 33);
    for(auto elem : result) cout<<elem<<", ";//31,32,33
    cout<<endl;
}

int main(){
    test1();
    test2();
}