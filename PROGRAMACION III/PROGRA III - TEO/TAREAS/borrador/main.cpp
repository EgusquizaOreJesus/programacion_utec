#include <iostream>
#include "random"


using std::random_device;
using std::uniform_int_distribution;
using std::cout;
using std::endl;
using std::cin;

#include "matrix.h"
/*OTRA FORMA DE SACAR NUMEROS ALEATORIOS EN UN RANGO ES HACER:
 *     random_device rd;
 *     uniform_int_distribution<int> dis(0,100);
 *     COUT << dis(rd);
 */

int main() {
    // EJERCICIO4
    SizeType rows = 0, cols = 0;
    cin >> rows >> cols;
    Matrix m1(rows,cols);
    for (int i = 0; i < m1.rows(); ++i) {
        for (int j = 0; j < m1.cols(); ++j) {
            cin >> m1(i,j);
        }
    }
    cout << endl;
    cin >> rows >> cols;
    Matrix m2(rows,cols);
    for (int i = 0; i < m2.rows(); ++i) {
        for (int j = 0; j < m2.cols(); ++j) {
            cin >> m2(i, j);
        }
    }
    cout << endl;
    cin >> rows >> cols;
    Matrix m3(rows,cols);
    for (int i = 0; i < m3.rows(); ++i) {
        for (int j = 0; j < m3.cols(); ++j) {
            cin >> m3(i, j);
        }
    }
    cout << endl;
    cout << m1 << endl << m2 << endl << m3 << endl;
    cout << endl;
    cout << "MULTIPLICACION ENTRE MATRICES" << endl;
    cout << m2*m3 << endl;
    cout << "SUMA DE MATRICES" << endl;
    // Suma de matrices
    auto m4 = m1 + m2;
    cout << m4 << endl;
    cout << "AUTOINCREMENTO" << endl;
    // AUTOINCREMENTO
    m1*=5;
    cout << m1 << endl;
    cout << "MULTIPLICACION ESCALAR" << endl;
    auto m5 = 4 * m1 * 2 + m4;
    cout << m5 << endl;
    return 0;

}
/*
ejercicio2
     // EJERCICIO2
    random_device rd;
    Matrix m1(8,9);
    Matrix m2(4,5);
    uniform_int_distribution<int> dis(0,100);
    for (int i = 0; i < m1.rows(); ++i) {
        for (int j = 0; j < m1.cols(); ++j) {
            m1(i, j) = dis(rd);
        }
    }
    cout << m1;
    Matrix m3 = m1;
    for (int i = 0; i < m2.rows(); ++i) {
        for (int j = 0; j < m2.cols(); ++j) {
            m2(i, j) = dis(rd);
        }
    }
    cout << m1.rows() << " " << m1.cols() << endl;
    cout << m2.rows() << " " << m2.cols() << endl;
    cout << m3.rows() << " " << m3.cols() << endl;
    // MOVE
    std::swap(m1,m2);
    m2(0,0) = 100;
    cout << endl;
    cout << m1.rows() << " " << m1.cols() << endl;
    cout << m2.rows() << " " << m2.cols() << endl;
    cout << m1 << endl << m2 << endl << m3 <<endl;
 */

/*
    // EJERCICIO3
        random_device rd;
        Matrix m1(8, 9);
        Matrix m2(4, 5);
        uniform_int_distribution<int> dis(0, 100);
        for (int i = 0; i < m1.rows(); ++i) {
            for (int j = 0; j < m1.cols(); ++j) {
                m1(i, j) = dis(rd);
            }
        }
        //COPIA
        Matrix m3 = m1;
        for (int i = 0; i < m2.rows(); ++i) {
            for (int j = 0; j < m2.cols(); ++j) {
                m2(i, j) = dis(rd);
            }
        }
        // comparando matrices
        cout << m1 << endl << m2 << endl << m3 <<endl;
        cout << std::boolalpha << (m1 == m2) << endl;
        cout << std::boolalpha << (m3 == m1) << endl;
        cout << std::boolalpha << (m2 == m3) << endl;
 */