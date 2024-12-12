#include "stack"
#include "iostream"

using namespace std;

string process_text_by_stack(const string& source) {
    string result;
    stack<char> key;
    for (auto &letra: source) {
        if (letra != '*') {
            key.push(letra);
        }
        else{
            result += key.top();
            key.pop();
        }
    }
    return result;
}

int main(){
    string text;
    getline(cin, text);
    cout << process_text_by_stack(text);
    return 0;
}