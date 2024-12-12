#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void add(vector<int>& A, int e){
    for (int i=0; i < 10; i++)
        A.push_back(e);
}

int main(){
    vector<int> A;
    /// PODRIAN HACER EL PUSH AL MISMO TIEMPO
    thread t1(&add, ref(A), 1);
    thread t2(&add, ref(A), 2);

    t1.join();
    t2.join();

    cout << A.size() << endl;

    for (const int e: A)
        cout << e << " ";
    cout << endl;

    return 0;
}
