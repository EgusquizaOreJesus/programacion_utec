#include "sp4.h"
#include <iostream>
#include <vector>
#include <random>
#include <queue>
using namespace std;

// n = numero de filas
// m = numero de columnos
// n == m el caso mas desfavorable

using row_t = vector<int>;
using matrix_t = vector<row_t>;

bool ejercicio_1(const matrix_t& matrix) {
  auto sz_row = size(matrix);         // Cantidad de filas            // O(1)
  auto sz_col = size(matrix.front()); // Cantidad de columnas         // O(1)
  auto tab = vector<bool>(sz_row * sz_col, false);                    // O(n*m) // O(n^2)

  for (const auto& row: matrix)                   // O(n)
    for (const auto& value: row)                  // O(m)
      tab[value - 1] = true;

  for (const auto& i: tab)                        // O(n*m)
    if(!tab[i])
      return false;

  return true;                                    // O(1)
}
// O(1) + O(n^2) + O(n)*O(n) + O(n^2) + O(1) 
// = O(1) + O(n^2) + O(n^2) + O(n^2) + O(1)
// = O(1 + n^2 + n^2 + n^2 + 1) = O(2 + 3n^2)
// = O(n^2) considerando una matriz cuadrada

// O(1) + O(n*m) + O(n)O(m) + O(n*m) + O(1)
// O(1) + O(nm) + O(nm) + O(nm) + O(1)
// O(2) + O(3nm)
// O(2 + 3mn)
// O(3nm)
// = O(nm) para un C = 4 y n0 = 1 tal que n >= n0 m >= n0
std::string bigO_1() {
    string result = "O(n^2)";
    return result;
}

void ejercicio_2(int n) {
  for( int i = n;  i > 0;  i /= 2 ) {       // 0(log(n))
    for( int j = 1;  j < n;  j *= 2 ) {     // O(log(n))
      for( int k = 0;  k < n;  k += 2 ) {   // O(n)
        // ... constant number of operations
      }
    }
  }
}
// O(log(n))*O(log(n))*O(n)
// O(log(n)*log(n)*n)
// O(log(n^2)*n)

std::string bigO_2() {
    // log(n)*log(n)*n --> n*log(n^2)
    string result = "O(n*log(n^2))";
    return result;
}

void ejercicio_3(int n) {
  auto sum = 0;                             // O(1)
  for ( int i = 1; i < n; i *= 2 ) {        // O(log(n))
    for ( int j = n; j > 0; j /= 2 ) {      // O(log(n))
      for ( int k = j; k < n; k += 2 ) {    // O(n)
        sum += (i + j * k );                // O(1)
      }
    }
  }
}

// O(1) + O(log(n))*[O(log(n))*[O(n) + O(1)]]
// O(1) + O(log(n))*[O(log(n))*O(n) + 0(log(n))*O(1)]
// O(1) + O(log(n))*[O(log(n)*n) + O(log(n))]
// O(log(n))*O(log(n)*n) + O(log(n))*O(log(n))
// O(n*log(n^2))

std::string bigO_3() {
    // 1 + log(n)*log(n)*n*1 --> n*log(n^2) + 1
    string result = "O(n*log(n^2))";
    return result;
}

void ejercicio_4(int n) {
  for( int i = n;  i > 0;  i-- ) {          // O(n)
    for( int j = 1;  j < n;  j *= 2 ) {
      for( int k = 0;  k < j;  k++ ) {      // O(n)
        // ... constant number C of operations
      }
    }
  }
}

// O(n)*O(n)

std::string bigO_4() {
    // Escribir el resultado del análisis
    string result = "O(n^2)";
    return result;
}

void ejercicio_5(int n) {
  for( int bound = 1; bound <= n; bound *= 2 ) {           // O(log(n))
    for( int i = 0; i < bound; i++ ) {                     // O(n) --> el bound como maximo y peor caso tomara n repeticiones
      for( int j = 0; j < n; j += 2 ) {                    // O(n/2)
        // ... constant number of operations
      }
      for( int j = 1; j < n; j *= 2 ) {                    // O(log(n))
        // ... constant number of operations
      }
    }
  }
}

// O(log(n))*[O(n)*[O(n/2) + O(log(n))]]
// O(log(n))*[O(n)*O(n/2) + O(n)*O(log(n))]
// O(log(n))*[O(n^2/2) + O(n*log(n))] --> elimino cste.
// O(log(n))*O(n^2) + O(log(n))*O(n*log(n))
// O(log(n)*n^2) + O(log(n^2)*n)
// O(n^2*log(n))

std::string bigO_5() {
    // Escribir el resultado del análisis
    string result = "O(n^2*log(n))";
    return result;
}

int randint(int first, int last) {
  random_device rd;
  uniform_int_distribution<int> dis(first, last);
  return dis(rd);
}

int ejercicio_6(int n) {
  if ( n <= 0 ) return 0;                                    // O(1)
  int i = randint( 0, n - 1 );                      // O(1)
  return ejercicio_6( i ) + ejercicio_6( n - 1 - i );  
      // i + n - 1 - i // i + n - 1 - i
      //  ejercicio_6(n - 1) 
}
// El peor caso seria que i valga 0 o n-1
// Si vale i=0 --> seria ejercicio_6(0): O(1) y la otra llamada a la funcion devuelve ejercicio_6(n-1)
// Si vale i= n-1 --> Seria igual ejercicio_6(n-1) y la otra llamada seria ejercicio_6(0): O(1)
// En ambos casos cuando agarra el peor caso el codigo iterara n+1: O(n+1) --> O(n)

// O(n)
std::string bigO_6() {
    // Escribir el resultado del análisis
    string result = "O(n)";
    return result;
}

void ejercicio_7(int n) {
  int k = 1;
  while (k <= n)        // O(log(n+1))  base de 3
    k = 3 * k;
}
// O(log(n)) base 3

std::string bigO_7() {
    // Escribir el resultado del análisis
    string result = "O(log(n))";    // base 3
    return result;
}

void ejercicio_8(int n) {
  for (int i = 0; i < n; ++i) {     // O(n)
    int j = i;                      // O(1)
    while (j < i * i) {             // O(n^2)
      j = j + 1;                    // O(1)
      if (j % i == 0)
        for (int k = 0; k < j; ++k) // O(n^2)
          cout << "utec";
    }
  }
}
// O(n)*[O(1) + O(n^2)*[O(1) + O(n^2)]]
// O(n)*[O(1) + O(n^2)*O(n^2)]
// O(n)*O(n^4)
// O(n^5)
std::string bigO_8() {
    // Escribir el resultado del análisis
    string result = "O(n^5)";
    return result;
}

void ejercicio_9(int n) {
  int count = 0;                       // O(1)
  for (int i = n/2; i < n; ++i) {      // O(n/2)
    int j = 1;                         // O(1)
    while (j + n/2 <= n) {             // O(n/2)
      int k = 1;                       // O(1)
      while (k <= n) {                 // O(log(n))
        ++count;
        k *= 2;
      } // end while
      ++j;
    } // end while
  } // end for
  std::cout << count;
}

// O(1) + O(n/2)*[O(1) + O(n/2)*[O(1) + O(log(n))]]
// O(1) + O(n/2)*[O(1) + O(n/2)*O(log(n))]
// O(1) + O(n/2)*O(n/2)*O(log(n))
// O(1) + O(n^2/4*log(n))           --> Eliminamos cste.
// O(n^2*log(n))

std::string bigO_9() {
    // Escribir el resultado del análisis
    string result = "O(n^2*log(n))";
    return result;
}

void ejercicio_10(int n) {
  int sum = 0;
  for (int i = 0; i < sqrt(n)/2; ++i)       // O(sqrt(n)/2)
    sum++;
  int j = 0;
  for (; j < sqrt(n)/4; ++j)                // O(sqrt(n)/4)
    sum++;
  for (int k = 0; k < 8 + j; ++k)               // O(sqrt(n)/4 + 8)
    sum++;
  cout << sum << endl;
}

// O(sqrt(n)/2) + O(sqrt(n)/4) + O(sqrt(n)/4 + 8) elimino constante
// O(sqrt(n)) + O(sqrt(n)) + O(sqrt(n))
// O(sqrt(n))
std::string bigO_10() {
    // Escribir el resultado del análisis
    string result = "O(sqrt(n))";
    return result;
}

int ejercicio_11 (int n, int x) {
  if (n <= 1) return 1;         // O(1)
  else
    for (int i = 1; i <= n; ++i)    // O(n)
      x = x + 1;                // O(1)
  return ejercicio_11 (n-1, x); 
}
// ejercicio 11: f(n-1) + n + cste.
// Que tiene la forma: T(n) = a*f(n-b) + c*(n^d)
// a = 1, b = 1, c = 1, d = 1
// como a == 1
// tendra la forma: O(n*(n^d))
// Reemplazo:
// O(n^2)


std::string bigO_11() {
    // Escribir el resultado del análisis
    string result = "O(n^2)";
    return result;
}

int ejercicio_12 (vector<int> v) {
  auto n = size(v);     // O(1)
  
  if (n == 0) return 0;                     // O(1)
   if (n == 1) {                            // O(1)
    int value = v.back();                   // O(1)
    v.pop_back();                           // O(1)
    return value;                           // O(1)
  }   

  vector<int> v1;                           // O(1)
  vector<int> v2;                           // O(1)
  auto left = begin(v);       // O(1)
  auto middle = next(left, n/2);    // O(1)
  auto right = end(v);        // O(1)
  
  copy(left, middle, back_inserter(v1));        // O(n/2)       --> n
  copy(middle, right, back_inserter(v2));       // O(n/2)       --> n
    
  return ejercicio_12 (v1) + ejercicio_12 (v2); // f(n) = 2*f(n/2)
}

// f(n) = 2*f(n/2) + 2*n
// se parece a: a*f(n/b) + c*(n^d)
// donde: a = 2, b = 2, c = 2, d = 1
// como: a == b^d --> 2 == 2^1
// tendra la forma de: O((n^d)*log(n))
// Reemplazamos:
// O(n*log(n))

std::string bigO_12() {
    // Escribir el resultado del análisis
    string result = "O(n*log(n))";
    return result;
}

std::string bigO_13() {
    // Escribir el resultado del análisis
    string result = "log(n)";
    return result;
}

