

#include "header.h"

void DeslocaCorpo(int *tamanhocobrinha, int poscobralinha[], int poscobracoluna[], int arrayratolinha[], int arrayratocoluna[],
                  int *cont_ratos_comidos, int *pontuacaoatual, int linha, int coluna, char andacobrinha[linha][coluna])
{
    int i, j, z;


    if (poscobralinha[0]==arrayratolinha[0])
        if (poscobracoluna[0]== arrayratocoluna[0])
        {
            *tamanhocobrinha = *tamanhocobrinha +1;
            arrayratolinha[0] = -1;
            arrayratocoluna[0] = -1;
            *cont_ratos_comidos = *cont_ratos_comidos +1;
            *pontuacaoatual =  *pontuacaoatual +1;

        }

    if (poscobralinha[0]==arrayratolinha[1])
        if (poscobracoluna[0]== arrayratocoluna[1])
        {
            *tamanhocobrinha = *tamanhocobrinha +1;
            arrayratolinha[1] = -1;
            arrayratocoluna[1] = -1;
            *cont_ratos_comidos = *cont_ratos_comidos +1;
            *pontuacaoatual =  *pontuacaoatual +1;
        }

    if (poscobralinha[0]==arrayratolinha[2])
        if (poscobracoluna[0]== arrayratocoluna[2])
        {
            *tamanhocobrinha = *tamanhocobrinha +1;
            arrayratolinha[2] = -1;
            arrayratocoluna[2] = -1;
            *cont_ratos_comidos = *cont_ratos_comidos +1;
            *pontuacaoatual =  *pontuacaoatual +1;
        }


    if (poscobralinha[0]==arrayratolinha[3])
        if (poscobracoluna[0]== arrayratocoluna[3])
        {
            *tamanhocobrinha = *tamanhocobrinha +1;
            arrayratolinha[3] = -1;
            arrayratocoluna[3] = -1;
            *cont_ratos_comidos = *cont_ratos_comidos +1;
            *pontuacaoatual =  *pontuacaoatual +1;
        }

    gotoxy(poscobracoluna[*tamanhocobrinha-1], poscobralinha[*tamanhocobrinha-1]);
    printf(" ");


    i=*tamanhocobrinha;
    z=*tamanhocobrinha;
    j=1;
    while(i>0)
    {

        poscobralinha[i]=poscobralinha[z-j];//aqui щ aquele treco de poscobralinha[4]=poscobralinha[3], e por ai vai
        poscobracoluna[i]=poscobracoluna[z-j];
        i--;
        j++;
        //mudacor++;//esse eu atulaizei para fazer a corzinhas dps hehehe
    }
}
