
#include "header.h"



void manual ()
{
    int codigo;//Op��o escolhida pelo usu�rio
    system("cls");
    printf("O jogo N�O pode iniciar com comando para direita\n");
    printf ("Ao comer uma ma��(representada por um ponto), voce troca de n�vel e ganha dez pontos!\n");
    printf ("A cabe�a da cobra incial ao abrir o jogo � representada pelo s�mbolo O!\n");
    printf ("Ao comer um rato(representado por um e comercial), voce ganha um ponto, e ao comer cinco ratos surge uma ma�a!!\n");
    printf ("Comandos:\n");
    printf ("W - a cobrinha move para cima\n");
    printf ("D - a cobrinha move para direita\n");
    printf ("S - a cobrinha move para baixo\n");
    printf ("A - a cobrinha move para esquerda\n");
    printf ("p - Pausa o jogo\n");
    printf ("q ou esq- Encerra o jogo\n");
    printf ("Aperte 1 para voltar ao menu\n");
    do
    {


        while (scanf ("%d", &codigo) ==0) //Se o usu�rio digitar letras ou outros caracteres
        {
            fflush(stdin);//apaga o buffer para ler o pr�ximo comando do usu�rio
            printf ("Aperte 1 para voltar ao menu\n");
        }

        if (codigo ==1)
            menu();//se a pessoa digitar 1, volta para o menu
        else
            printf ("Aperte 1 para voltar ao menu\n");

    }
    while (codigo !=1);//sai do la�o se a pessoa digitar um para voltar ao menu





}
