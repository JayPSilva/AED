#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "carro.h"



struct _carro
{
    char matricula[9];
    char entrada[6];
    char saida[6];
};



carro criaCarro(char * entrada, char * matricula)
{
    carro c;
    c = (carro)malloc(sizeof(struct _carro));
    if (c == NULL)
        return NULL;
    strcpy((*c).entrada, entrada);
    strcpy((*c).matricula, matricula);
    (*c).saida[0] = '!';
    return c;
}



void destroiCarro(carro c)
{
    free(c);
}



void atribuiSaida(carro c, char * saida)
{
    strcpy((*c).saida, saida);;
}



int conversorhoras(carro c)
{
    int i, horas, minutos, auxh, auxm;
    if ((*c).saida[0] == '!')
        return 0;
    for (i = 0; i < strlen((*c).entrada); i++)
    {
        if ((*c).entrada[i] == ':')
        {
            if (i == 2)
                auxh = (((int)(*c).entrada[0] - '0') * 10) + ((int)(*c).entrada[1] - '0');
            else
                auxh = (int)(*c).entrada[0] - '0';
            auxm = (((int)(*c).entrada[i+1] - '0') * 10) + ((int)(*c).entrada[i+2] - '0');
            break;
        }
    }
    for (i = 0; i < strlen((*c).saida); i++)
    {
        if ((*c).saida[i] == ':')
        {
            if (i == 2)
                horas = ((((int)(*c).saida[0] - '0') * 10) + ((int)(*c).saida[1] - '0')) - auxh;
            else
                horas = ((int)(*c).saida[0] - '0') - auxh;
            minutos = ((((int)(*c).saida[i+1] - '0') * 10) + ((int)(*c).saida[i+2] - '0')) - auxm;
            break;
        }
    }
    if (minutos < 0)
        horas -= 1;
    if (horas < 0)
        horas += 24;
    if (minutos != 0)
        horas += 1;
    return horas;
}



float preco(int horas)
{
    int i;
    float resultado = 4.25;
    if (horas < 4)
    {
        switch (horas)
        {
            case 1: return 1.50;
            case 2: return 2.50;
            case 3: return 3.50;
        }
    }
    else
    {
        horas -= 4;
        for (i = 1; i < 21; i++)
        {
            if (horas == 0)
                return resultado;
            else
            {
                resultado += 0.75;
                horas--;
            }
        }
    }
}



char * carroMatricula(carro c)
{
    return (*c).matricula;
}
