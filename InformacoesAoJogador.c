
#include "header.h"

void Informacoes_ao_jogador(int linha,int nrovidas, int cont_ratos_aotodo,int cont_ratos_comidos, int pontuacaoatual,int nivel)
{

    gotoxy(0, linha); //Todos os gotoxy certificam que as informa��es n�o ser�o impressas no mapa.
    printf ("Vidas: %d ", nrovidas);//impress�o do nro de vidas atual
    printf ("Ratos: %d  ", cont_ratos_aotodo);//impressao da quantidade do numero de ratos presentes no momento na tela
    printf ("Consumidos:%d", cont_ratos_comidos);//ipress�o da quanitdade numeros de ratos comidos(se mant�m e vai aumentando ao longo de todo jogo)
    gotoxy (0, linha+1);
    printf("Pontua��o: %d ", pontuacaoatual);//ipress�o da pontuacao comidos(se mant�m e vai aumentando ao longo de todo jogo)
    gotoxy (14, linha+1);
    printf ("Nivel: %d", nivel);//impress�o do nivel atual
}


