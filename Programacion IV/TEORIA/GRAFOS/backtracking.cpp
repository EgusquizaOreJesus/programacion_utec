#include <iostream>
#include "solucion.h"

using namespace std;
void generar(vector<int>& val, int nivel){
    val[nivel] = val[nivel] + 1;

}


void displayAllSubsets(vector<int> val, int sum) {
    vector<int> s(int(val.size()), -1);
    int nivel = 0;
    int subsetSum = 0;

    while (nivel >= 0) {
        s[nivel] = s[nivel] + 1;
        if (s[nivel] == 1) {
            subsetSum += val[nivel];
        }

        if (nivel == val.size() - 1 && subsetSum == sum) {
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == 1) {
                    cout << val[i] << " ";
                }
            }
            cout << endl;
        }

        if (nivel < val.size() - 1 && subsetSum <= sum) {
            nivel++;
        } else {
            while (s[nivel] >= 1 && nivel >= 0) {
                subsetSum -= val[nivel];
                s[nivel] = -1;
                nivel--;
            }
        }
    }
}




int main(){

    vector<int> conjunto = {1,2,3,4,5,6,7,8,9,10};
    int P = 5;
    displayAllSubsets(conjunto, P);
    //{5}
    //{2 3}
    //{1 4}
//    displayAllSubsets_pruning(conjunto, P);
    //{5}
    //{2 3}
    //{1 4}
}