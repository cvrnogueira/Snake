


#include "header.h"

void gotoxy(int x, int y) //Define a posição do cursor, utilizado pois a bibliote CONIO está com problemas de instalção no computador das integrantes do grupo
{
    static HANDLE h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h,c);

}

char validaInput(char movimentacaocobra, int *contadordemov10)
{

    char possivelmov;
    if(kbhit())
    {
        possivelmov=(getch());//a função pega um movimento digitado pelo usuário


        if(possivelmov== -32)//se for as setas que forem clicadas pelo usuário, é necessário ver se é -32, se sim, quer dizer que são setas
        {
            possivelmov=(getch());//e então pega o segundo char, que é a movimentação dada pelas setas(-32 é o indentificador e o segundo numero é o movimento mesmo)
            switch(possivelmov)
            {
            case 75:
                possivelmov='A';//seta para a direita é A

                break;
            case 77:
                possivelmov='D';//seta para a esquerda D

                break;
            case 80:
                possivelmov='S';//seta para baixo é S

                break;
            case 72:
                possivelmov='W';//seta para cima é W

                break;

            }
        }


        possivelmov=toupper(possivelmov);//coloca-se toupper caso a pessoa cliclou em uma tecla e não seta

        if((possivelmov=='A' && movimentacaocobra!='D') || (possivelmov=='S' && movimentacaocobra!='W') || (possivelmov=='W' && movimentacaocobra!= 'S')|| (possivelmov=='D' && movimentacaocobra!='A')||(possivelmov=='Q')||(possivelmov==27))
        {
            movimentacaocobra=possivelmov;//se o movimento for permitido(cobra não pode se comer), o movimento pega pelo usuário vira o movimento que a cobra irá realizar mesmo
            *contadordemov10 = *contadordemov10 + 1;
        }

        if (possivelmov == 'P')
            {
                getch ();
                //gotoxy (60, 30);
                //system("pause");
          }

        if( possivelmov ==movimentacaocobra)//se for o mesmo movimento limpa-se o buffer e continua no movimento anterior( para garantir que a função não lerá o movimento duas vezes)
            fflush(stdin);
        //if( movimentacaocobra== 'P')///ta diminuinfo UM PEDAÇO DA COOBRA!COMO FAÇO???
        //se a movimentação for P é o pause no jogo
           //movimentacaocobra=consisteFirstMov(contadordemov10);

        if(movimentacaocobra=='Q')//se a movimentação for Q ou esc(27), vai direto para o menu
            menu();
        if(movimentacaocobra==27)
            menu();
    }

    return movimentacaocobra;
}

char consisteFirstMov(int *contadordemov10, int pontuacao[])//a cobra começa parada, logo, o primeiro movimento deve ser consistido para que ela não se coma
{
    char movimentacaocobra, possivelmov;

    do
    {
        possivelmov=getch();
        if(toupper(possivelmov)=='Q')//se a movimentação for Q ou esc(27), vai direto para o menu
           menu();
        if(toupper(possivelmov)==27)
            menu();
        if ((toupper(possivelmov)=='P' )|| (toupper(possivelmov)!='A' && toupper(possivelmov)!='S' && toupper(possivelmov)!='W'))
        {
            movimentacaocobra='D';//p ficar pausada pois a pessoa digitou caracteres não permitidos ou pause
        }
        else  movimentacaocobra = toupper(possivelmov);//se for um caractere permitido, cai no else e dá-se toupper a movimentação da cobra
       if(possivelmov==-32)//se for as setas que forem clicadas pelo usuário, é necessário ver se é -32, se sim, quer dizer que são setas
        {
            possivelmov=(getch());//e então pega o segundo char, que é a movimentação dada pelas setas(-32 é o indentificador e o segundo numero é o movimento mesmo)
            switch(possivelmov)
            {
            case 75:
                movimentacaocobra='A';//seta para a direita é A

                break;
            case 77:
                movimentacaocobra='D';//seta para a esquerda D

                break;
            case 80:
                movimentacaocobra='S';//seta para baixo é S

                break;
            case 72:
                movimentacaocobra='W';//seta para cima é W

                break;

            }
        }

        *contadordemov10 = *contadordemov10 + 1;//a cada detcla diferente o contador de movimentos soma mais um, pois a pessoa fez um movimento
    }
    while(movimentacaocobra=='D');//se foi um caractere não permitido, a cobra ganha D(pois a cobra começa para a esquerda, logo não pode ir para direita tecla 'D')

    return movimentacaocobra;// a função retorna a movimentação da cobra
}

void movimentaCabeca(int *poscobracoluna, int *poscobralinha, int movimentacaocobra)
{

    switch(movimentacaocobra)//dependendo do movimento da cabeça, o corpo segue, logo, o ultimo do corpo é "apagado" e colocado uma posição a frente
    {
    case 'D'://ou seja, a cabeça muda e o 1 do corpo ocupa o lucar da cabeça, o 2 do corpo ocupa o lugar do 1 do corpo e assim sucessivamente

        poscobracoluna[0]++;//o ultimo do corpo é apagado na função "DeslocaCorpo", quando faz-de um gotoxy de espaço para o lugar que ele estava
        break;
    case 'A':

        poscobracoluna[0]--;
        break;
    case 'W':

        poscobralinha[0]--;
        break;
    case 'S':

        poscobralinha[0]++;
        break;
    }
}
