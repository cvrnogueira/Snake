

#include "header.h"



int main ()
{
    setlocale(LC_ALL, "Portuguese");
    int pontuacao[15];//array de pontua��o com 15 elementos
    system("mode 150, 50");//arruma o tamanho da tela de comando
    int i;//contador para o la�o de colocar todos elementos da pontua��o em zero
    for(i=0; i<15; i++) //todos elementos do array "pontua��o" s�o inciados com zero
    {
        pontuacao[i]=0;
    }

    menu(pontuacao);//chama-se o menu com a pontua��o


    return 0;
}
