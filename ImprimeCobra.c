
#include "header.h"


void ImprimeCobra(int linha, int coluna, int tamanhocobrinha, int *gameover, int *poscobralinha, int *poscobracoluna, int movimentacaocobra)
{
    int conttamanhocobrinha; //contador do tamanho da cobra, ele recebe o tamanho da cobra e vai decrementando ao longo da função
    int i;//contador para o laço
    for(conttamanhocobrinha=tamanhocobrinha; conttamanhocobrinha>=0; conttamanhocobrinha--)

    {
        gotoxy(poscobracoluna[conttamanhocobrinha], poscobralinha[conttamanhocobrinha]);

        if(conttamanhocobrinha==0)//se o conttamanhocobrinha for zero significa que é a cabeça, então consiste para ver se bateu nas paredes
        {
             if((poscobralinha[0]==linha-1|| poscobralinha[0]==0)|| (poscobracoluna[0]==coluna-1 || poscobracoluna[0]==0))
                *gameover=1;
                ///aqui posso deixar assim pq só tem parede nas bordas
                    for(i=tamanhocobrinha; i>0; i--) //ve se a cobra comeu o prório corpo, ou seja, se a cabeça passou por cima de alguma parte do corpo
                    if(poscobralinha[0]==poscobralinha[i] && poscobracoluna[0]==poscobracoluna[i])
                     *gameover=1;//se isso acontecer gameover=0 e vai para Desejacontinuar
            switch(movimentacaocobra)//faz o switch da movimentação da cabeça dependendo da movimentação da cabeça
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
        else if(poscobralinha[conttamanhocobrinha]==poscobralinha[conttamanhocobrinha-1])//muda o símbolo do corpo dependendo da movimentação da cabeça
            printf("-");

        else
            printf("|");
    }
}
