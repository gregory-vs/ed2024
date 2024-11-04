#include <iostream>
#include "fatorial.h"
#include "fibonacci.h"



int main() {
    int numero;
    std::cout << "Digite um número: ";
    std::cin >> numero;
    int resultado = fatorialIterativo(numero);

    int resultado2 = fatorialRecursivo(numero);
    std::cout << "Fatorial (recursivo) de " << numero << " é: " << resultado << std::endl;

    return 0;
}