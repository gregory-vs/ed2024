#include <iostream>
#include <string>
#include "ordint.h"

using namespace std;

int main(int argc, char **argv)
{
    char aux[100];
    OrdInd_ptr poi = Cria();
    CarregaArquivo(poi, "entrada.xcsv");
    int numatrib = NumAtributos(poi);
    for (int i = 0; i < numatrib; i++)
    {
        if (NomeAtributo(poi, i, aux) > 0)
        {
            // if (!aux.compare(aux, "Nome") || !string::compare(aux, "CPF") || !string::compare(aux, "End"))
            // {
            //     CriaIndice(poi, i);
            //     OrdenaIndice(poi, i);
            //     ImprimeOrdenadoIndice(poi, i);
            // }
        }
    }
    Destroi(poi);
}