
#include "header.h"

void ReestartNasVariaveis(int *ganhou, int *apple_line, int *apple_column, int *apple_counter, int *cont_ratos_aotodo, int *tamanhocobrinha, int *contadorderatos, int arrayrandomcoluna[], int arrayrandomlinha[] )
{
    int i;

    system ("cls");
        *ganhou=0;
        *apple_line=-1;
        *apple_column=-1;
        *apple_counter=0;
        *cont_ratos_aotodo=0;
        *tamanhocobrinha=5;
        *contadorderatos = 0;
         for(i=0; i<3; i++)
        {
            arrayrandomcoluna[i]=-1;
            arrayrandomlinha[i]=-1;

        }

}

