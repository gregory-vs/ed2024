#include "ordind.h"
#include "ord_alg.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring> // Para manipulação de strings
#include <algorithm> // Para std::sort

using namespace std;

// Construtor
OrdInd::OrdInd() : data(nullptr), indices(nullptr), atributos(nullptr), numLinhas(0), numAtributos(0) {}

// Destrutor
OrdInd::~OrdInd() {
    // Liberar dados
    if (data) {
        for (int i = 0; i < numLinhas; ++i) {
            for (int j = 0; j < numAtributos; ++j) {
                delete[] data[i][j];
            }
            delete[] data[i];
        }
        delete[] data;
    }

    // Liberar atributos
    if (atributos) {
        for (int i = 0; i < numAtributos; ++i) {
            delete[] atributos[i];
        }
        delete[] atributos;
    }

    // Liberar índices
    if (indices) {
        for (int i = 0; i < numAtributos; ++i) {
            delete[] indices[i];
        }
        delete[] indices;
    }
}

// Carregar arquivo xCSV
bool OrdInd::CarregaArquivo(const string& nomeArquivo) {
    ifstream file(nomeArquivo);
    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return false;
    }

    // Contar o número de linhas no arquivo
    string line;
    int linhas = 0;
    while (getline(file, line)) {
        ++linhas;
    }

    if (linhas <= 1) { // Pelo menos uma linha de cabeçalho e uma de dados são necessárias
        cerr << "O arquivo não contém dados suficientes." << endl;
        return false;
    }

    // Voltar ao início do arquivo
    file.clear();
    file.seekg(0, ios::beg);

    // Processar cabeçalho
    getline(file, line);
    stringstream ss(line);
    string value;
    numAtributos = 0;

    while (getline(ss, value, ',')) {
        ++numAtributos;
    }

    atributos = new char*[numAtributos];
    ss.clear();
    ss.str(line);
    int col = 0;

    while (getline(ss, value, ',')) {
        atributos[col] = new char[value.size() + 1];
        strcpy(atributos[col], value.c_str());
        ++col;
    }

    // Alocar espaço para os dados
    numLinhas = linhas - 1; // Descontar a linha do cabeçalho
    data = new char**[numLinhas];

    int linhaAtual = 0;
    while (getline(file, line)) {
        ss.clear();
        ss.str(line);
        data[linhaAtual] = new char*[numAtributos];

        col = 0;
        while (getline(ss, value, ',')) {
            data[linhaAtual][col] = new char[value.size() + 1];
            strcpy(data[linhaAtual][col], value.c_str());
            ++col;
        }
        ++linhaAtual;
    }

    file.close();
    return true;
}

// Número de atributos
int OrdInd::NumAtributos() const {
    return numAtributos;
}

// Obter nome de um atributo
const char* OrdInd::NomeAtributo(int pos) const {
    if (pos < 0 || pos >= numAtributos) {
        return nullptr;
    }
    return atributos[pos];
}

// Criar índice com algoritmo de ordenação escolhido
bool OrdInd::CriaIndice(int atribId, SortAlgorithm algoritmo) {
    if (atribId < 0 || atribId >= numAtributos) {
        cerr << "Atributo inválido para índice: " << atribId << endl;
        return false;
    }

    // Inicializar os índices
    if (!indices) {
        indices = new int*[numAtributos];
        for (int i = 0; i < numAtributos; ++i) {
            indices[i] = nullptr;
        }
    }

    indices[atribId] = new int[numLinhas];
    for (int i = 0; i < numLinhas; ++i) {
        indices[atribId][i] = i;
    }

    // Ordenar os índices com base no atributo escolhido
    if (algoritmo == QUICK_SORT) {
        quickSort(indices[atribId], 0, numLinhas - 1);
    } else if (algoritmo == MERGE_SORT) {
        mergeSort(indices[atribId], 0, numLinhas - 1);
    } else if (algoritmo == BUBBLE_SORT) {
        bubbleSort(indices[atribId], numLinhas);
    } else {
        cerr << "Algoritmo de ordenação inválido." << endl;
        return false;
    }

    return true;
}

// Imprimir dados ordenados pelo índice
void OrdInd::ImprimeOrdenadoIndice(int atribId) const {
    if (atribId < 0 || atribId >= numAtributos || !indices || !indices[atribId]) {
        cerr << "Índice inválido ou não criado para o atributo: " << atribId << endl;
        return;
    }

    for (int i = 0; i < numLinhas; ++i) {
        int idx = indices[atribId][i];
        for (int j = 0; j < numAtributos; ++j) {
            cout << data[idx][j] << " ";
        }
        cout << endl;
    }
}

// Definir atributos (colunas)
void OrdInd::SetAtributos(char** atributosInput, int numAtributosInput) {
    // Liberar memória atual, se existir
    if (atributos) {
        for (int i = 0; i < numAtributos; ++i) {
            delete[] atributos[i];
        }
        delete[] atributos;
    }

    numAtributos = numAtributosInput;
    atributos = new char*[numAtributos];
    for (int i = 0; i < numAtributos; ++i) {
        atributos[i] = new char[strlen(atributosInput[i]) + 1];
        strcpy(atributos[i], atributosInput[i]);
    }
}

// Definir dados (registros)
void OrdInd::SetDados(char*** dadosInput, int numLinhasInput) {
    // Liberar memória atual, se existir
    if (data) {
        for (int i = 0; i < numLinhas; ++i) {
            for (int j = 0; j < numAtributos; ++j) {
                delete[] data[i][j];
            }
            delete[] data[i];
        }
        delete[] data;
    }

    numLinhas = numLinhasInput;
    data = new char**[numLinhas];
    for (int i = 0; i < numLinhas; ++i) {
        data[i] = new char*[numAtributos];
        for (int j = 0; j < numAtributos; ++j) {
            data[i][j] = new char[strlen(dadosInput[i][j]) + 1];
            strcpy(data[i][j], dadosInput[i][j]);
        }
    }
}

int OrdInd::NumLinhas() const {
    return numLinhas;
}

const char* OrdInd::GetDado(int linha, int coluna) const {
    if (linha < 0 || linha >= numLinhas || coluna < 0 || coluna >= numAtributos) {
        return nullptr;
    }
    return data[linha][coluna];
}

int OrdInd::GetIndiceOrdenado(int chave, int pos) const {
    if (chave < 0 || chave >= numAtributos || pos < 0 || pos >= numLinhas) {
        return -1;
    }
    return indices[chave][pos];
}

