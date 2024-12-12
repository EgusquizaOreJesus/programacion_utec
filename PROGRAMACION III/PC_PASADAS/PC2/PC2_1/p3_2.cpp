#include "iostream"
#include "thread"
#include "iomanip"
#include "vector"
#include "algorithm"

/// PRIMERA FORMA HACERLO CON PURAS MATRICES DINAMICAS
using namespace std;
using matrix_t = vector<vector<double>>;
matrix_t crear_matriz(size_t row, size_t col){
    matrix_t m1(row);
    generate(m1.begin(),m1.end(),[col](){
        vector<double> v(col);
        generate(v.begin(),v.end(),[](){return rand()%100;});
        return v;
    });
    return m1;
}


ostream& operator<<(ostream& os, const matrix_t& m ){
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[0].size(); ++j) {
            os << setw(8) << m[i][j];
        }
        os << endl;
    }
    os << endl;
    return os;
}

matrix_t operator+(const matrix_t& m1,const matrix_t& m2){
    matrix_t a = crear_matriz(m1.size(),m1[0].size());
    for (int i = 0; i < m1.size(); ++i) {
        for (int j = 0; j < m1[0].size(); ++j) {
            a[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return a;
}
matrix_t operator+(const matrix_t& m1, double a){
    matrix_t temp = crear_matriz(m1.size(),m1[0].size());
    for (int i = 0; i < m1.size(); ++i) {
        for (int j = 0; j < m1[0].size(); ++j) {
            temp[i][j] = m1[i][j] + a;
        }
    }
    return temp;
}
matrix_t operator+(double a ,const matrix_t& m1){
    matrix_t temp = crear_matriz(m1.size(),m1[0].size());
    for (int i = 0; i < m1.size(); ++i) {
        for (int j = 0; j < m1[0].size(); ++j) {
            temp[i][j] = m1[i][j] + a;
        }
    }
    return temp;
}
matrix_t operator*(const matrix_t& m1,const matrix_t& m2){
    matrix_t temp = crear_matriz(m1.size(),m2[0].size());
    for (int i = 0; i < m1.size(); ++i) {
        for (int j = 0; j < m2[0].size(); ++j) {
            temp[i][j] = 0;
            for (int k = 0; k < m2.size(); ++k) {
                temp[i][j] += m1[i][k]*m2[k][j];
            }
        }
    }
    return temp;
}
matrix_t transpuesta(const matrix_t& m1){
    matrix_t temp = crear_matriz(m1[0].size(), m1.size());
    for (int i = 0; i < temp.size(); ++i) {
        for (int j = 0; j < temp[0].size(); ++j) {
            temp[i][j] = m1[j][i];
        }
    }
    return temp;
}

double mean(const matrix_t& m){
    double prom = 0;
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[0].size() ; ++j) {
            prom += m[i][j];
        }
    }
    prom = prom/double(m.size()*m[0].size());
    return prom;
}
int main(){
    srand(time(nullptr));
    matrix_t A = crear_matriz(2,3);
    matrix_t B = transpuesta(A);
    cout << A;
    cout << B;
    cout << A*B;
    cout << mean(A) << endl;
    cout << mean(B) << endl;

    cout << A*B + mean(A);

    return 0;
}