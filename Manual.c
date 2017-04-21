
#include "header.h"



void manual ()
{
    int codigo;///N SEI EXPLICAR ESSA VARIAVEL
    system("cls");
    printf("O jogo NÃO pode iniciar com tecla para direita\n");
    printf ("Comandos:\n");
    printf ("W - a cobrinha move para cima\n");
    printf ("D - a cobrinha move para direita\n");
    printf ("S - a cobrinha move para baixo\n");
    printf ("A - a cobrinha move para esquerda\n");
    printf ("p - Pausa o jogo\n");
    printf ("q - Encerra o jogo\n");
    printf ("Aperte 1 para voltar ao menu\n");
    do
    {


        while (scanf ("%d", &codigo) ==0) ///Se o usuário digitar letras ou outros caracteres
        {
            fflush(stdin);//apaga o buffer para ler o próximo comando do usuário
            printf ("Aperte 1 para voltar ao menu\n");
        }

        if (codigo ==1)
            menu();//se a pessoa digitar 1, volta para o menu
        else
            printf ("Aperte 1 para voltar ao menu\n");

    }
    while (codigo !=1);//sai do laço se a pessoa digitar um para voltar ao menu





}
