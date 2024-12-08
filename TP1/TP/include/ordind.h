#ifndef ORDIND_H
#define ORDIND_H

#include <string>

enum SortAlgorithm {
    QUICK_SORT,
    MERGE_SORT,
    BUBBLE_SORT
};

class OrdInd {
private:
    char*** data;        
    int** indices;       
    char** atributos;    
    int numLinhas;       
    int numAtributos;    

public:
    OrdInd();
    ~OrdInd();
    bool CarregaArquivo(const std::string& nomeArquivo);
    int NumAtributos() const;
    const char* NomeAtributo(int pos) const;
    bool CriaIndice(int atribId, SortAlgorithm algoritmo);
    void ImprimeOrdenadoIndice(int atribId) const;
    void SetAtributos(char** atributos, int numAtributos);
    void SetDados(char*** dados, int numLinhas);
    int NumLinhas() const;                          
    const char* GetDado(int linha, int coluna) const; 
    int GetIndiceOrdenado(int chave, int pos) const;

};

#endif // ORDIND_H
