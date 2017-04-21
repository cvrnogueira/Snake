
#include "header.h"


void AtualizaPontuacao(int pontuacao[], int pontuacaoatual)
{
    int i, j; //contadores para os laços
    int achou=0;//flag, zero é falso e 1 é verdadeiro
    FILE *arq;
    for(i=0; i<15; i++)
    {
        if(!achou)//se não achou uma pontuação menor que a atual do jogador continua procurando
        {
            if(pontuacaoatual>pontuacao[i])//se achou se atualiza a pontuação com essa nova
            {
                for(j=15; j>i; j--)
                {

                    {
                        pontuacao[j]=pontuacao[j-1];

                    }
                }
                pontuacao[i]=pontuacaoatual;
                achou=1;//flag vira verdadeiro para sair do if

            }

        }
    }

    arq=fopen("highscores.bin", "r+b");//abre o arquivo de pontuação para leitura
    if(arq==NULL)
    {
        arq=fopen("highscores.bin","w+b" );//abre o arquivo de pontuação para escrita
        for(i=0; i<15; i++)
        {
            fwrite(&pontuacao[i], sizeof(pontuacao[0]), 1, arq);//escreve-se a pontuação atualizada no arquivo
        }
    }
    else
    {
        if(fwrite(pontuacao, sizeof(pontuacao[0]), 15, arq)!= 15)//consiste para ver se foi escrito corretamente
            puts("Error");
    }
    fclose(arq);//fecha arquivo
    printf("Sua pontuacao %d \n", pontuacaoatual);//imprime a pontuação
    printf("\n\n");
    puts("Ranking atualizado: ");//imprime o ranking atualizado
    CarregaPontuacao(pontuacao);
    system("pause");

}
