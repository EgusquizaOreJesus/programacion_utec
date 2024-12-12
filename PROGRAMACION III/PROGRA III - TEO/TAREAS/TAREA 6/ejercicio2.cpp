#include "iostream"
#include "stack"

using namespace std;

template<typename T>
stack<T> join_stacks(stack<T>& s1, stack<T>& s2){
    stack<T> result;
    stack<T> result_invert;
    while(!s2.empty()){
        result.push(s2.top());
        s2.pop();
    }
    while(!s1.empty()){
        result.push(s1.top());
        s1.pop();
    }
    while(!result.empty()){
        result_invert.push(result.top());
        result.pop();
    }
    return result_invert;
}



int main(){
    stack<int> stack_a;
    stack<int> stack_b;
    int n {};
    cin >> n;
    while (n-- > 0) {
        int value {};
        cin >> value;
        stack_a.push(value);
    }
    cin >> n;
    while (n-- > 0) {
        int value {};
        cin >> value;
        stack_b.push(value);
    }

    auto stack_result = join_stacks(stack_a, stack_b);

    while (!stack_result.empty()) {
        cout << stack_result.top() << " ";
        stack_result.pop();
    }
    return 0;
}