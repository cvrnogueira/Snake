

#include "header.h"



int main ()
{
    setlocale(LC_ALL, "Portuguese");
    int pontuacao[15];//array de pontuação com 15 elementos
    system("mode 150, 50");//arruma o tamanho da tela de comando
    int i;//contador para o laço de colocar todos elementos da pontuação em zero
    for(i=0; i<15; i++) //todos elementos do array "pontuação" são inciados com zero
    {
        pontuacao[i]=0;
    }

    menu(pontuacao);//chama-se o menu com a pontuação


    return 0;
}
