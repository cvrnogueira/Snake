
#include "header.h"


void ImprimeCobra(int linha, int coluna, int tamanhocobrinha, int *gameover, int *poscobralinha, int *poscobracoluna, int movimentacaocobra)
{
    int conttamanhocobrinha; //contador do tamanho da cobra, ele recebe o tamanho da cobra e vai decrementando ao longo da fun��o
    int i;//contador para o la�o
    for(conttamanhocobrinha=tamanhocobrinha; conttamanhocobrinha>=0; conttamanhocobrinha--)

    {
        gotoxy(poscobracoluna[conttamanhocobrinha], poscobralinha[conttamanhocobrinha]);

        if(conttamanhocobrinha==0)//se o conttamanhocobrinha for zero significa que � a cabe�a, ent�o consiste para ver se bateu nas paredes
        {
             if((poscobralinha[0]==linha-1|| poscobralinha[0]==0)|| (poscobracoluna[0]==coluna-1 || poscobracoluna[0]==0))
                *gameover=1;
                ///aqui posso deixar assim pq s� tem parede nas bordas
                    for(i=tamanhocobrinha; i>0; i--) //ve se a cobra comeu o pr�rio corpo, ou seja, se a cabe�a passou por cima de alguma parte do corpo
                    if(poscobralinha[0]==poscobralinha[i] && poscobracoluna[0]==poscobracoluna[i])
                     *gameover=1;//se isso acontecer gameover=0 e vai para Desejacontinuar
            switch(movimentacaocobra)//faz o switch da movimenta��o da cabe�a dependendo da movimenta��o da cabe�a
            {
            case 'D':
                printf("<");
                break;

            case 'S':
                printf("^");

                break;

            case 'W':
                printf("V");

                break;

            case 'A':
                printf(">");

                break;


            }


        }
        else if(poscobralinha[conttamanhocobrinha]==poscobralinha[conttamanhocobrinha-1])//muda o s�mbolo do corpo dependendo da movimenta��o da cabe�a
            printf("-");

        else
            printf("|");
    }
}
