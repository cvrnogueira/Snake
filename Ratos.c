
#include "header.h"


void Apaga_ratos (int arrayrandomlinha[4], int arrayrandomcoluna[4], int contratosmortos)
{
    gotoxy (arrayrandomcoluna[contratosmortos], arrayrandomlinha[contratosmortos]);
    printf(" "); // Por exemplo, caso n�o haja ratos mortos, o primeiro a ser morto ser� o de numero 0, o qual surgiu primeiro.
    //Caso um rato j� tenha sido morto, o que ser� apagado ser� o segundo que surgiu, o que tem seus endere�os na posi��o 1 do vetor.
    //matrizrandomcoluna[contratosmortos] =0;
}



void Gerador_de_ratos( int linha, int coluna, int codigo, int contadorderatos, int contratosmortos,
                       int arrayrandomlinha[4], int arrayrandomcoluna[4], int tamanhocobra, int poscobralinha[],
                       int poscobracoluna[], char andacobrinha[linha][coluna], int *appleline, int *applecolumn)
{
    int aleatoriocoluna, aleatoriolinha, sair=0, cont;
    //As duas primeiras s�o n�meros aleat�rios candidatos a serem coordenadas dos ratos. A terceira � uma flag utilizada para
    //saber se foi encontrado coordenadas v�lidas para os ratos. A �ltima � um contados para os la�os.
    if (codigo ==1)
    {

        do
        {
            sair=1;
            aleatoriocoluna = 1 + (rand() % (coluna-2) ); //Gera um numero aleatorio para linha e outro para coluna, impedindo que seja nas bordas
            aleatoriolinha = 1 + (rand() % (linha-2) );

            if (aleatoriolinha == *appleline && aleatoriocoluna == *applecolumn)
                sair=0;

            if(andacobrinha[aleatoriolinha][aleatoriocoluna]=='*')//ve se o andacobrinha dos randoms dados � pedra
                sair=0;

            for (cont=tamanhocobra; cont >0; cont --)
                if (poscobralinha[cont] == aleatoriolinha) //confere se n � no corpo
                    if (poscobracoluna[cont] == aleatoriocoluna)
                        sair=0;

        } while (sair == 0);

        arrayrandomlinha[contadorderatos] = aleatoriolinha; //Se os n�meros gerados s�o coordenadas v�lidas, ser�o armazenados em dois vetores
        arrayrandomcoluna[contadorderatos] = aleatoriocoluna;
        gotoxy (arrayrandomcoluna[contadorderatos], arrayrandomlinha[contadorderatos]);
        printf ("&");

    }

    if (codigo ==0)
        Apaga_ratos(arrayrandomlinha, arrayrandomcoluna, contratosmortos);

}
