#include "carro.h"

#ifndef _H_PARQUE3
#define _H_PARQUE

typedef struct _parque * parque;


parque criaParque();

void destroiParque(parque p);

void destroiParqueECarros(parque p);

int novoCarroParque(parque p, char * entrada, char * matricula);

int tamanhoParque(parque p);

carro removeCarroParque(parque p, char * matricula);

carro carroPosParque(parque p, int i);

#endif
