#include <iostream>
#include <stack>

void transfer(std::stack<int>& a, std::stack<int>& b) {
    while (!a.empty()) {
        b.push(a.top());
        a.pop();
    }
}

void print_stack(std::stack<int*> st) { // pass a copy so we don't destoy the original
    while (!st.empty()) {
        std::cout << st.top() << ' ';
        st.pop();
    }
    std::cout << '\n';
}

int main() {
    int x = 3;
    int* t1 = nullptr;
    t1 = &x;
    int* x1 = new int(3);
    int* x2 = new int(4);
    t1 = x1;
    t1 = x2;


    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
//    for (int i = 0; a[i] > 0; i++)
//        x.push(&a[i]);
    delete t1;
    return 0;
}