


#include "header.h"

void Impressao_do_mapa(char andacobrinha[][COLUNA], int linha, int coluna)
{
    int pos1, pos2;//contadores que representam as posições na matriz
    for(pos1=0; pos1<linha; pos1++)
    {
        for(pos2=0; pos2<coluna+1; pos2++)
        {
            printf("%c", andacobrinha[pos1][pos2]);//imprime a matriz lida do arquivo de texto na função Le_arquivo_texto
        }
    }
}

