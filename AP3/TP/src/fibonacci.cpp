#include <iostream>
#include<cmath>
#include "fibonacci.h"

long double fibonacciIterativo(long double n) {
    if (n <= 1) // Caso base
        return n;
    
    long double a = 0, b = 1, resultado;
    for (long double i = 2; i <= n; ++i) {
        resultado = a + b;
        a = b;
        b = resultado;
    }
    return resultado;
}

long double fibonacciRecursivo(long double n) {
    for (int i = 0; i < 10; i++) {
       int x = sin(1);
       ++x;
    }

    if (n <= 1) // Caso base: Fibonacci(0) = 0, Fibonacci(1) = 1
        return n;
    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}