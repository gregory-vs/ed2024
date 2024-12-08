#include "utils.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstring>

using namespace std;

bool CarregarArquivoXCSV(OrdInd& ord, const string& nomeArquivo) {
    ifstream file;
    file.open(nomeArquivo);
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return false;
    }

    string line;
    int numColunas = 0;

    // Ler número de colunas
    if (!getline(file, line)) return false;
    numColunas = stoi(line);

    // Ler nomes das colunas
    char** colunas = new char*[numColunas];
    for (int i = 0; i < numColunas; ++i) {
        if (!getline(file, line)) return false;
        size_t pos = line.find(',');
        colunas[i] = new char[pos + 1];
        strncpy(colunas[i], line.c_str(), pos);
        colunas[i][pos] = '\0';
    }

    ord.SetAtributos(colunas, numColunas);

    // Ler número de registros
    if (!getline(file, line)) return false;
    int numRegistros = stoi(line);

    // Ler registros
    char*** registros = new char**[numRegistros];
    for (int i = 0; i < numRegistros; ++i) {
        if (!getline(file, line)) return false;
        registros[i] = new char*[numColunas];
        stringstream ss(line);
        string value;
        for (int j = 0; j < numColunas; ++j) {
            getline(ss, value, ',');
            registros[i][j] = new char[value.size() + 1];
            strcpy(registros[i][j], value.c_str());
        }
    }

    ord.SetDados(registros, numRegistros);

    // Limpar colunas temporárias
    for (int i = 0; i < numColunas; ++i) {
        delete[] colunas[i];
    }
    delete[] colunas;

    return true;
}
