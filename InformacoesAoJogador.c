
#include "header.h"

void Informacoes_ao_jogador(int linha,int nrovidas, int cont_ratos_aotodo,int cont_ratos_comidos, int pontuacaoatual,int nivel)
{

    gotoxy(0, linha); //Todos os gotoxy certificam que as informações não serão impressas no mapa.
    printf ("Vidas: %d ", nrovidas);//impressão do nro de vidas atual
    printf ("Ratos: %d  ", cont_ratos_aotodo);//impressao da quantidade do numero de ratos presentes no momento na tela
    printf ("Consumidos:%d", cont_ratos_comidos);//ipressão da quanitdade numeros de ratos comidos(se mantém e vai aumentando ao longo de todo jogo)
    gotoxy (0, linha+1);
    printf("Pontuação: %d ", pontuacaoatual);//ipressão da pontuacao comidos(se mantém e vai aumentando ao longo de todo jogo)
    gotoxy (14, linha+1);
    printf ("Nivel: %d", nivel);//impressão do nivel atual
}


