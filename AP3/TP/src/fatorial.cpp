#include <iostream>
#include "fatorial.h"

int fatorialRecursivo(int n) {
    if (n <= 1) // Caso base: 0! = 1 e 1! = 1
        return 1;
    return n * fatorialRecursivo(n - 1);
}

int fatorialIterativo(int n) {
    int resultado = 1;
    for (int i = 2; i <= n; ++i) {
        resultado *= i;
    }
    return resultado;
}
