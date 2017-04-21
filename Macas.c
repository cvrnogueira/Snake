


#include "header.h"
void apple_generator(int linha, int coluna, int poscobralinha[], int poscobracoluna[], int apple_counter, int *apple_line,
                     int *apple_column, int tamanhocobra, char andacobrinha[linha][coluna], int pontuacao[15],
                     int ratolinha[4], int ratocoluna[4])
{
    int aleatoriocoluna, aleatoriolinha, sair=1, cont=0, contador;
    //if (apple_counter ==0) /// Sу uma maзг por jogo
   // {


        do
        {
            sair=1;
            aleatoriocoluna = 1 + (rand() % (coluna-2) ); //Gera um numero aleatorio para linha e outro para coluna, impedindo que seja nas bordas
            aleatoriolinha = 1 + (rand() % (linha-2) );


            if(andacobrinha[aleatoriolinha][aleatoriocoluna]=='*')///ve se o andacobrinha dos randoms dados й pedra
                sair=0;

            for (cont=0; cont<4; cont++)
                if (aleatoriolinha == ratolinha[cont] && aleatoriocoluna == ratocoluna[cont])
                    sair=0;


            for (contador=tamanhocobra; contador >0; contador --)
                if (poscobralinha[contador] == aleatoriolinha) ///Confere se nгo estб surgindo no corpo da cobra
                    if (poscobracoluna[contador] == aleatoriocoluna)
                        sair=0;



        }
        while (sair ==0);

        gotoxy (aleatoriocoluna, aleatoriolinha);
        printf(".");
        *apple_line = aleatoriolinha;
        *apple_column = aleatoriocoluna;

      //  if(andacobrinha[poscobralinha[0]][poscobracoluna[0]]=='.')
      //  {
      //     *ganhou++;
     //      jogo(pontuacao);
     //  }
    //}

}
