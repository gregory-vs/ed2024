#include "ordind.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

// Função para salvar os dados ordenados no formato especificado
void SalvarOrdenacao(const OrdInd& ord, int chave, const string& nomeArquivo) {
    ofstream outFile(nomeArquivo, ios::app); // Abre o arquivo em modo append
    if (!outFile.is_open()) {
        cerr << "Erro ao abrir o arquivo de saída." << endl;
        return;
    }

    // Escrever cabeçalho
    outFile << ord.NumAtributos() << endl;
    for (int i = 0; i < ord.NumAtributos(); ++i) {
        outFile << ord.NomeAtributo(i) << ",s" << endl;
    }
    outFile << ord.NumLinhas() << endl;

    // Escrever registros ordenados
    for (int i = 0; i < ord.NumLinhas(); ++i) {
        int idx = ord.GetIndiceOrdenado(chave, i);
        for (int j = 0; j < ord.NumAtributos(); ++j) {
            outFile << ord.GetDado(idx, j);
            if (j < ord.NumAtributos() - 1) {
                outFile << ",";
            }
        }
        outFile << endl;
    }

    outFile.close();
}

int main(int argc, char *argv[]) {
    OrdInd ord;

    // Carregar o arquivo xCSV
    if (!CarregarArquivoXCSV(ord, "entrada.xcsv")) {
        return 1;
    }

    // Definir as chaves e algoritmos
    int chaves[] = {0, 1, 2}; // Índices das colunas para ordenação (name, id, address)
    SortAlgorithm algoritmos[] = {QUICK_SORT, MERGE_SORT, BUBBLE_SORT};

    // Ordenar e salvar resultados
    for (int i = 0; i < 3; ++i) {              // Para cada chave
        for (int j = 0; j < 3; ++j) {          // Para cada algoritmo
            ord.CriaIndice(chaves[i], algoritmos[j]);
            SalvarOrdenacao(ord, chaves[i], "saida.xcsv");
        }
    }

    return 0;
}
