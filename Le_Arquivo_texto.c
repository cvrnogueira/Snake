
#include "header.h"
void Le_arquivo_texto(char andacobrinha[LINHA][COLUNA], int *linha, int *coluna, int ganhou)
{
    int i=0,j;
    char c[3],d[3];
    char linhatexto[LINHA][COLUNA];
    FILE *arq;

if (ganhou==1)
    arq=fopen("nivel2.3.txt", "r");
else
    arq = fopen("nivel1.3.txt", "r");

    if (arq == NULL)
        puts("Erro na abertura do mapa, desculpe pelo incoveniente");
    else
    {
        fgets(c, 3, arq);//pega valor da linha
        *linha = atoi(c);
        fgetc(arq);//pega o espa�o entre eles

        fgets(d, 4, arq);//pega valor da coluna
        *coluna = atoi(d);

        while(!feof(arq))
        {
            fgets(linhatexto[i], *coluna+2, arq);
            //printf("|%s|%d\n", linhatexto[i], strlen(linhatexto[i]));
            //int comp=strlen(linhatexto[i]);
            //linhatexto[comp-1]='\0';
            i++;
        }
    }

    for(i=0; i<*linha; i++)
    {
        for(j=0; j<*coluna+2;j++)
        {
            andacobrinha[i][j] = linhatexto[i][j];
        }
    }

    fclose(arq);

}
