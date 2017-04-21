
#include "header.h"

void Informacoes_ao_jogador(int linha,int nrovidas, int cont_ratos_aotodo,int cont_ratos_comidos, int pontuacaoatual,int nivel)
{
        gotoxy(0, linha);
        printf ("Vidas: %d ", nrovidas);
        printf ("Ratos: %d  ", cont_ratos_aotodo);
        printf ("Consumidos:%d", cont_ratos_comidos);
        gotoxy (0, linha+1);
        printf("Pontuação: %d ", pontuacaoatual);
        gotoxy (14, linha+1);
        printf ("Nivel: %d", nivel);
}
void Informacoes_ao_jogador2(int linha,int cont_ratos_comidos, int pontuacaoatual)///PORQUE EXISTE ESSAS INFORMAÇÕES TBM??? AS DE CIMA N BASTAM???
{
            gotoxy(30, linha);
            printf("%d", cont_ratos_comidos);
            gotoxy (11, linha+1);
              printf("%d", pontuacaoatual);
}
