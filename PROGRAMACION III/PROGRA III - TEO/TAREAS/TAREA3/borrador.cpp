#include <iostream>
#include <tuple>
#include "list"
#include "vector"

using namespace std;
void bubblesort(std::vector<std::string> &strings)
{
    typedef std::vector<std::string>::size_type size_type;
    for (size_type i = 1; i < strings.size(); ++i) // for n-1 passes
    {
        // In pass i,compare the first n-i elements
        // with their next elements
        for (size_type j = 0; j < (strings.size() - 1); ++j)
        {
            if(strings[j] > strings[j+1])
            {
                std::string const temp = strings[j];
                strings[j] = strings[j + 1];
                strings[j+1] = temp;
            }
        }
    }
}
template<typename T=string, template<typename ...>typename Container>
void insertion_sort_vector(Container<T> &A){
    int size= distance(A.begin(),A.end());
    for (int j = 1; j < size; ++j) {
        T key = *next(A.begin(),j);
        int i = j-1;
        while ( i>=0 && *next(A.begin(),i) > key){
            *(next(A.begin(),i+1)) = *(next(A.begin(),i));
            i = i-1;
        }
        *(next(A.begin(),i+1)) = key;
    }
}
//void insertion_sort_vector(Container<T> &A){
//    for (int j = 1; j < A.size(); ++j) {
//        string key = A[j];
//        int i = j-1;
//        while (A[i] > key && i>=0){
//            A[i+1] = A[i];
//            i = i-1;
//        }
//        A[i + 1] = key;
//    }
//}

int main()
{
    vector<string> b = {"hola","habc","hbcc","abcs","hbdc"};
    bubblesort(b);
    cout << endl;
    for_each(b.begin(),b.end(),[](string x){cout << x << " ";});
}