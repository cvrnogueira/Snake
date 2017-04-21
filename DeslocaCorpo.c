

#include "header.h"

void DeslocaCorpo(int *tamanhocobrinha, int poscobralinha[], int poscobracoluna[], int arrayratolinha[], int arrayratocoluna[],
                  int *cont_ratos_comidos, int *pontuacaoatual, int linha, int coluna, char andacobrinha[linha][coluna])
{
    int i, j, z;


    if (poscobralinha[0]==arrayratolinha[0]) //Verifica se a cobra passa por cima de um rato
        if (poscobracoluna[0]== arrayratocoluna[0])
        {
            *tamanhocobrinha = *tamanhocobrinha +1; //Seu tamanho aumenta
            arrayratolinha[0] = -1; //As posições do rato pelo qual ela passou recebem um número que não existe no mapa,
            arrayratocoluna[0] = -1; //evitando com que ela, passando pela mesma posição, aumente novamente de tamanho.
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

    gotoxy(poscobracoluna[*tamanhocobrinha-1], poscobralinha[*tamanhocobrinha-1]);//é colocado um epaõ em brando para "apagar" o ultimo pedaço da cauda da cobra
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
