#include <iostream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include "fatorial.h"
#include "fibonacci.h"

using namespace std;


int main(int argc, char *argv[]) {

    if (argc != 4) {
        cerr << "Uso: " << argv[0] << " -fibonacci|-fatorial -r|-i <numero>\n";
        return 1;
    }

    string operacao = argv[1];
    string modo = argv[2];
    int numero = atoi(argv[3]);

    auto start_wall_clock = chrono::high_resolution_clock::now();
    


    if (operacao == "-fibonacci") {
        if (modo == "-r") {
            cout << "Fibonacci recursivo de " << numero << ": " << fibonacciRecursivo(numero) << endl;
        } else if (modo == "-i") {
            cout << "Fibonacci iterativo de " << numero << ": " << fibonacciIterativo(numero) << endl;
        } else {
            cerr << "Modo inválido! Use -r para recursivo ou -i para iterativo.\n";
            return 1;
        }
    } else if (operacao == "-fatorial") {
        if (modo == "-r") {
            cout << "Fatorial recursivo de " << numero << ": " << fatorialRecursivo(numero) << endl;
        } else if (modo == "-i") {
            cout << "Fatorial iterativo de " << numero << ": " << fatorialIterativo(numero) << endl;
        } else {
            cerr << "Modo inválido! Use -r para recursivo ou -i para iterativo.\n";
            return 1;
        }
    } else {
        cerr << "Operação inválida! Use -fibonacci ou -fatorial.\n";
        return 1;
    }

    auto end_wall_clock = chrono::high_resolution_clock::now();

    chrono::duration<double> wall_clock_duration = end_wall_clock - start_wall_clock;
    cout << "Tempo de relógio (real): " << wall_clock_duration.count() << " segundos\n";
    cout << endl;
    cout << endl;
    cout << endl;


    return 0;
}

