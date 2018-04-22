#ifndef _H_CARRO
#define _H_CARRO

typedef struct _carro * carro;



carro criaCarro(char * entrada, char * matricula);

void destroiCarro(carro c);

void atribuiSaida(carro c, char * saida);

int conversorhoras(carro c);

float preco(int horas);

char * carroMatricula(carro c);


#endif
