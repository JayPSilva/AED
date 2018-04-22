#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "carro.h"
#include "parque.h"

#define CAP 150

struct _parque
{
    carro * carros;
    int numCarros;
    int capacidade;
};



parque criaParque()
{
    parque p;
    p = (parque)(malloc(sizeof(struct _parque)));
    if (p == NULL)
        return NULL;
    p->carros = (carro *)(malloc(sizeof(carro) * CAP));
    if ((*p).carros == NULL)
    {
        free(p);
        return NULL;
    }
    (*p).numCarros = 0;
    (*p).capacidade = CAP;
    return p;
}



void destroiParque(parque p)
{
    free((*p).carros);
    free(p);
}



void destroiParqueECarros(parque p)
{
    int i;
    for (i = 0; i < (*p).numCarros; i++)
        destroiCarro((*p).carros[i]);
    free((*p).carros);
    free(p);
}



int novoCarroParque(parque p, char * entrada, char * matricula)
{
    int i;
    int verificador = 0;
    carro c;
    for (i = 0; i < strlen(matricula); i++)
        matricula[i] = tolower(matricula[i]);
    for (i = 1; i <= tamanhoParque(p); i++)
    {
        c = carroPosParque(p, i);
        if (strcmp(matricula,carroMatricula(c)) == 0)
        {
            verificador = 1;
            break;
        }
    }
    if ((*p).numCarros > CAP || verificador == 1)
        return 0;
    (*p).carros[(*p).numCarros] = criaCarro(entrada, matricula);
    (*p).numCarros++;
    return 1;
}



int tamanhoParque(parque p)
{
    return (*p).numCarros;
}

carro removeCarroParque(parque p, char * matricula)
{
    carro c;
    int i, pos = -1;
    for (i = 0; i < (*p).numCarros; i++)
    {
        if (strcmp(carroMatricula((*p).carros[i]),matricula) == 0)
            pos = i;
    }
    if (pos == -1)
        return NULL;
    c = (*p).carros[pos];
    for (i = pos; i < (*p).numCarros - 1; i++)
    (*p).carros[i] = (*p).carros[i+1];
    (*p).numCarros--;
    return c;
}



carro carroPosParque(parque p, int i)
{
    return (*p).carros[i-1];
}
