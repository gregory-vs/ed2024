#include <iostream>
#include<cmath>
#include "fatorial.h"

long double fatorialRecursivo(long double n) {
    for (int i = 0; i < 1000000; i++) {
       int x = sin(1);
       ++x;
    }
    if (n <= 1) // Caso base: 0! = 1 e 1! = 1
        return 1;
    return n * fatorialRecursivo(n - 1);
}

long double fatorialIterativo(long double n) {
    long double resultado = 1;
    for (long double i = 2; i <= n; ++i) {
        resultado *= i;
    }
    return resultado;
}
