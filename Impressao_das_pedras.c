

#include "header.h"


void Impressao_das_Pedras(char andacobrinha[][COLUNA], int linha, int coluna)
{
    int pos1, pos2;//contadores que representam as posi��es na matriz
    for(pos1=0; pos1<linha; pos1++)
    {
        for(pos2=0; pos2<coluna+1; pos2++)
        {
            if (andacobrinha[pos1][pos2] == '*') //Se no mapa tem pedra, a fun��o Imprime as pedras novamente conservando suas posi��es.
            {
                gotoxy(pos2, pos1);
                printf("*");
            }
        }
    }
}

