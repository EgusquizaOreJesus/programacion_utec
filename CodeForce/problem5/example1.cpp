#include <iostream>
#include "deque"
#include "algorithm"
using namespace std;

int main() {
    deque<int> a = {1,2,3,4,5,6};

//    std::cout << "Ingrese la altura del triangulo:";
//    std::cin >> n;
//
//    for(int i = 1; i <= n; i++) {
//        std::cout << std::string(n-i, ' ') << std::string(2*i-1, '*') << std::endl;
//    }
    for_each(a.begin(),a.end(),[](int x){cout << x << " " ;});
    a.pop_front();
    cout << endl;
    for_each(a.begin(),a.end(),[](int x){cout << x << " " ;});
    cout << endl;
    a.pop_back();
    for_each(a.begin(),a.end(),[](int x){cout << x << " " ;});
    cout << endl;
//    int t;
//    cin >> t;
//    while(t--){
//        int n, s;
//        cin >> n >> s;
//
//        deque<int> a(n);
//        for (int i = 0; i < n; i++) {
//            cin >> a[i];
//        }
//
//        int ans = 0;
//        int sum = accumulate(a.begin(), a.end(), 0);
//        if (sum < s) {
//            ans = -1;
//        }
//        else{
//            while (!isSum(a,s)){
//                int l = 0, r = a.size() - 1,temp1 = 0,temp2 = 0;
//                while (a[l] == 0) {
//                    l++;
//                    temp1++;
//                }
//                while (a[r] == 0) {
//                    r--;
//                    temp2++;
//                }
//                if (temp1>temp2){
//                    for (int i = 0; i <= temp2; ++i) {
//                        a.pop_back();
//                        ans++;
//                    }
//                }
//                else{
//                    for (int i = 0; i <= temp1; ++i) {
//                        a.pop_front();
//                        ans++;
//                    }
//                }
//            }
//        }
//        cout << ans << endl;
//        a.clear();
//    }
}
bool a(){
//    int n, s;
//    cin >> n >> s;
//
//    deque<int> a(n);
//    for (int i = 0; i < n; i++) {
//        cin >> a[i];
//    }
//
//    int ans = 0;
//    int sum = accumulate(a.begin(), a.end(), 0);
//    if (sum < s) {
//        ans = -1;
//    }
//    else{
//        while (!isSum(a,s)){
//            int l = 0, r = a.size() - 1,temp1 = 0,temp2 = 0;
//            while (a[l] == 0) {
//                l++;
//                temp1++;
//            }
//            while (a[r] == 0) {
//                r--;
//                temp2++;
//            }
//            if (temp1>temp2){
//                for (int i = 0; i <= temp2; ++i) {
//                    a.pop_back();
//                    ans++;
//                }
//            }
//            else{
//                for (int i = 0; i <= temp1; ++i) {
//                    a.pop_front();
//                    ans++;
//                }
//            }
//        }
//    }
//    cout << ans << endl;
}

//#include <iostream>
//#include "deque"
//#include "algorithm"
//#include "numeric"
//#include "vector"
//using namespace std;
//
//bool isSum(deque<int> a,int x){
//    int sum = 0;
//    for_each(a.begin(),a.end(),[&sum](int x){sum+=x;});
//    if (sum == x){
//        return true;
//    }
//    return false;
//}
//
//int main() {
//    int t;
//    cin >> t;
//    while(t--){
//        int n, s;
//        cin >> n >> s;
//        deque<int> a;
//        for (int i = 0; i < n; i++) {
//            int x;
//            cin >> x;
//            a.push_back(x);
//        }
//        int ans = 0;
//        int sum = accumulate(a.begin(), a.end(), 0);
//        if (sum < s) {
//            ans = -1;
//        }
//        else{
//            while (!isSum(a,s)){
//                int l = 0, r = a.size() - 1,temp1 = 0,temp2 = 0;
//                while (a[l] == 0) {
//                    l++;
//                    temp1++;
//                }
//                while (a[r] == 0) {
//                    r--;
//                    temp2++;
//                }
//                if (temp1>temp2){
//                    for (int i = 0; i <= temp2; ++i) {
//                        a.pop_back();
//                        ans++;
//                    }
//                }
//
//                else if (temp1 < temp2){
//                    for (int i = 0; i <= temp1; ++i) {
//                        a.pop_front();
//                        ans++;
//                    }
//                }
//                else{
//                    ans = ans + 2;
//                    a.pop_front();
//                    a.pop_back();
//                }
//            }
//        }
//        cout << ans << endl;
//        a.clear();
//    }
//    return 0;
//}