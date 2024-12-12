//
// Created by Jesus on 24/01/2023.
//

#include "p1.h"

template<typename T>
T input(const string &com) {
    cout << com;
    T val;
    cin >> val;
    return val;
}

template<typename T>
T input() {
    T val;
    cin >> val;
    return val;
}