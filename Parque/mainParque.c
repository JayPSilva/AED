#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "parque.h"
#include "carro.h"


void adicionaCarro(parque p, char * linha)
{
    char c;
    char matricula[9];
    char entrada[6];
    int i;
    if (sscanf(linha,"%c %s %s", &c, matricula, entrada) != 3)
        printf("Dados invalidos.\n");
    else
    {
        for (i = 0; i < strlen(matricula); i++)
            matricula[i] = tolower(matricula[i]);
        if (novoCarroParque(p, entrada, matricula) != 1)
            printf("Carro ja no parque.\n");
        else
            printf("Entrada autorizada.\n");
    }
}



float saidaCarro(parque p, char * linha)
{
    int i;
    char ch;
    char matricula[9];
    char saida[6];
    carro c;
    float precocarro;
    if (sscanf(linha,"%c %s %s", &ch, matricula, saida) != 3)
        printf("Dados invalidos.\n");
    else
    {
        for (i = 0; i < strlen(matricula); i++)
            matricula[i] = tolower(matricula[i]);
        c = removeCarroParque(p, matricula);
        if (c == NULL)
        {
            printf("Carro nao existe no parque.\n");
            return 0.0;
        }
        else
            atribuiSaida(c, saida);
            precocarro = preco(conversorhoras(c));
            destroiCarro(c);
            printf("Carro com matricula %s deve pagar %.2f euros.\n", matricula, precocarro);
            return precocarro;
    }
}



void estatisticasParque(parque p)
{
    int i;
    int lim = tamanhoParque(p);
    carro c;
    if (lim == 0)
        printf("Parque sem carros.\n");
    else
    {
        for (i = 1; i <= lim; i++)
        {
            c = carroPosParque(p, i);
            printf("Matricula: %s\n", carroMatricula(c));
        }
    }
}



float interpretador(parque p)
{
    char linha[25], cmd;
    float caixa = 0.0;
    fgets(linha,25,stdin);
    cmd = toupper(linha[0]);
    while (cmd != 'X')
    {
        switch(cmd)
        {
            case 'E': adicionaCarro(p, linha);
                    break;
            case 'S': caixa += saidaCarro(p, linha);
                    break;
            case 'L': estatisticasParque(p);
                    break;
            case 'C': printf("Dinheiro em caixa : %.2f euros.\n", caixa);
                    break;
            default: printf("Comando invalido.\n");
                    break;
        }
        fgets(linha,25,stdin);
        cmd = toupper(linha[0]);
    }
    return caixa;
}





int main()
{
    parque mainP = criaParque();
    float caixa = interpretador(mainP);
    printf("Dinheiro em caixa : %.2f euros.\n%d carros no parque.\n", caixa, tamanhoParque(mainP));
    destroiParqueECarros(mainP);
    return 1;

}
