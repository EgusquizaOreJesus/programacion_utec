#include "queue"
#include "iostream"

using namespace std;
string process_text_by_queue(const string& source) {
    string result;
    queue<char> key;
    for (auto &letra: source) {
        if (letra != '*') {
            key.push(letra);
        }
        else{
            result += key.front();
            key.pop();
        }
    }
    return result;
}
int main(){
    string text;
    getline(cin, text);
    cout << process_text_by_queue(text);
    return 0;
}