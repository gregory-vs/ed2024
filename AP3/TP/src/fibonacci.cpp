#include <iostream>
#include "fibonacci.h"

int fibonacciIterativo(int n) {
    if (n <= 1) // Caso base
        return n;
    
    int a = 0, b = 1, resultado;
    for (int i = 2; i <= n; ++i) {
        resultado = a + b;
        a = b;
        b = resultado;
    }
    return resultado;
}

int fibonacciRecursivo(int n) {
    if (n <= 1) // Caso base: Fibonacci(0) = 0, Fibonacci(1) = 1
        return n;
    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}