


#include "header.h"

  void Impressao_do_mapa(char andacobrinha[][COLUNA], int linha, int coluna)
  {
int pos1, pos2;
 for(pos1=0; pos1<linha; pos1++)
        {
            for(pos2=0; pos2<coluna+1; pos2++)
            {
                printf("%c", andacobrinha[pos1][pos2]);//dai aqui to so imprimindo tudo(detalhe: a matriz de duas dimens�es que � a andacobrinha, � de char, pq as matrizes de uma dimes�o que correnspondem a linha e coluna dela recebem char( *, #, @, )
            }
        }
  }

