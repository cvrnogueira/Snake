

#include "header.h"


int OpcaoContinuar(int nrovidas, int *tamanhocobrinha, int pontuacao[15])
{
    system ("cls");
    int codigo;///NAO SEI ESSA VARIÁVEL(SEPA PODERÍAMOS MUDAR O GAMEOVER PARA CONTINUAR A JOGAR COMO 0, PQ DAI GAMEOVER SERIA FALSE)
    int gameover;//Se gameover é zero a pessoa volta para o menu inial, se gameover é um, a pessoa ainda pode jogar novamente
    if(nrovidas==0)//caso a pessoa perca, deve-se ver se o numero de vidas dela é maior do que zero, se não é a pessoa volta para o menu pois deu game over
    {
        fflush(stdin);
        printf ("Putss.. Suas vidas acabaram..\n");
        system("pause"); //Uma pausa para ler a mensagem a cima.
        gameover=1;
    }

    else
    {

        do
        {

            printf("Deseja continuar seu jogo? Aperte 4 caso sim e 3 caso nao.\n");//caso a pessoa ainda tenha vidas ela escolhe continuar o jogo ou não
            while (scanf ("%d", &codigo) == 0) //Caso o usuário digite letras ou outros caracteres
            {
                fflush(stdin);
                printf("Deseja continuar seu jogo? Aperte 4 caso sim e 3 caso nao.\n");

            }
            fflush(stdin);
            if (codigo ==4)//se a pessoa digita 4, ela escolhe jogar novamente, ou seja, o gameover ganha 1 e o jogo continua
                gameover =0;
            else if (codigo ==3)
            {
                fflush(stdin);
                gameover =1; //caso a pessoa perca, deve-se ver se o numero de vidas dela é maior do que zero, se não é a pessoa volta para o menu pois deu game over
                //no caso, ele ja era 0 antes, mas foi colocad novamente pra reforcar
            }

        }
        while (codigo != 3 && codigo !=4);// enquanto a pessoa não digitar 3 ou 4 contia no laço de saber se ela quer sair ou continuar

        fflush(stdin);
    }

    return gameover;//a função retorna o que o gameover der(1 para continuar, zero para sair)
}

