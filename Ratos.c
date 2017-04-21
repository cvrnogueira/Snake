
#include "header.h"


void Apaga_ratos (int arrayrandomlinha[4], int arrayrandomcoluna[4], int contratosmortos)
{
    gotoxy (arrayrandomcoluna[contratosmortos], arrayrandomlinha[contratosmortos]);
    printf(" "); // Por exemplo, caso não haja ratos mortos, o primeiro a ser morto será o de numero 0, o qual surgiu primeiro.
    //Caso um rato já tenha sido morto, o que será apagado será o segundo que surgiu, o que tem seus endereços na posição 1 do vetor.
    //matrizrandomcoluna[contratosmortos] =0;
}



void Gerador_de_ratos( int linha, int coluna, int codigo, int contadorderatos, int contratosmortos,
                       int arrayrandomlinha[4], int arrayrandomcoluna[4], int tamanhocobra, int poscobralinha[],
                       int poscobracoluna[], char andacobrinha[linha][coluna], int *appleline, int *applecolumn)
{
    int aleatoriocoluna, aleatoriolinha, sair=0, cont;
    //As duas primeiras são números aleatórios candidatos a serem coordenadas dos ratos. A terceira é uma flag utilizada para
    //saber se foi encontrado coordenadas válidas para os ratos. A última é um contados para os laços.
    if (codigo ==1)
    {

        do
        {
            sair=1;
            aleatoriocoluna = 1 + (rand() % (coluna-2) ); //Gera um numero aleatorio para linha e outro para coluna, impedindo que seja nas bordas
            aleatoriolinha = 1 + (rand() % (linha-2) );

            if (aleatoriolinha == *appleline && aleatoriocoluna == *applecolumn)
                sair=0;

            if(andacobrinha[aleatoriolinha][aleatoriocoluna]=='*')//ve se o andacobrinha dos randoms dados é pedra
                sair=0;

            for (cont=tamanhocobra; cont >0; cont --)
                if (poscobralinha[cont] == aleatoriolinha) //confere se n é no corpo
                    if (poscobracoluna[cont] == aleatoriocoluna)
                        sair=0;

        } while (sair == 0);

        arrayrandomlinha[contadorderatos] = aleatoriolinha; //Se os números gerados são coordenadas válidas, serão armazenados em dois vetores
        arrayrandomcoluna[contadorderatos] = aleatoriocoluna;
        gotoxy (arrayrandomcoluna[contadorderatos], arrayrandomlinha[contadorderatos]);
        printf ("&");

    }

    if (codigo ==0)
        Apaga_ratos(arrayrandomlinha, arrayrandomcoluna, contratosmortos);

}
