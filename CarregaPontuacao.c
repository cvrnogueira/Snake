


#include "header.h"


void CarregaPontuacao(int pontuacao[15])
{
    FILE *arq;
    int i;//contador para o laço
    arq=fopen("highscores.bin","rb");//abre o arquivo de pontuação para leitura
    if(arq==NULL) {
        arq=fopen("highscores.bin","w+b" );//abre o arquivo de pontuação para escrita e leitura
        i=0;//contador ganha zero
        for(i=0; i<15; i++)
        {
            pontuacao[i]=0;
            fwrite(&pontuacao[i], sizeof(pontuacao[0]), 1, arq);//escreve a pontuação no arquivo
            printf("%d = %d \n", i+1, pontuacao[i]);//imprime a pontuação
        }
    } else
    {
        for(i=0; i<15; i++)
        {
            if(fread(&pontuacao[i], sizeof(int),1, arq)!=1)//le a pontuação
                puts("Error, não foi lido");
            else
                printf("%d = %d \n", i+1, pontuacao[i]);//imprime a pontuação
        }
    }
    fclose(arq);//fecha o arquivo
}
