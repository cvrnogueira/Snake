


#include "header.h"

void gotoxy(int x, int y) //Define a posi��o do cursor, utilizado pois a bibliote CONIO est� com problemas de instal��o no computador das integrantes do grupo
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
        possivelmov=(getch());//a fun��o pega um movimento digitado pelo usu�rio


        if(possivelmov== -32)//se for as setas que forem clicadas pelo usu�rio, � necess�rio ver se � -32, se sim, quer dizer que s�o setas
        {
            possivelmov=(getch());//e ent�o pega o segundo char, que � a movimenta��o dada pelas setas(-32 � o indentificador e o segundo numero � o movimento mesmo)
            switch(possivelmov)
            {
            case 75:
                possivelmov='A';//seta para a direita � A

                break;
            case 77:
                possivelmov='D';//seta para a esquerda D

                break;
            case 80:
                possivelmov='S';//seta para baixo � S

                break;
            case 72:
                possivelmov='W';//seta para cima � W

                break;

            }
        }


        possivelmov=toupper(possivelmov);//coloca-se toupper caso a pessoa cliclou em uma tecla e n�o seta

        if((possivelmov=='A' && movimentacaocobra!='D') || (possivelmov=='S' && movimentacaocobra!='W') || (possivelmov=='W' && movimentacaocobra!= 'S')|| (possivelmov=='D' && movimentacaocobra!='A')||(possivelmov=='Q')||(possivelmov==27))
        {
            movimentacaocobra=possivelmov;//se o movimento for permitido(cobra n�o pode se comer), o movimento pega pelo usu�rio vira o movimento que a cobra ir� realizar mesmo
            *contadordemov10 = *contadordemov10 + 1;
        }

        if (possivelmov == 'P')
            {
                getch ();
                //gotoxy (60, 30);
                //system("pause");
          }

        if( possivelmov ==movimentacaocobra)//se for o mesmo movimento limpa-se o buffer e continua no movimento anterior( para garantir que a fun��o n�o ler� o movimento duas vezes)
            fflush(stdin);
        //if( movimentacaocobra== 'P')///ta diminuinfo UM PEDA�O DA COOBRA!COMO FA�O???
        //se a movimenta��o for P � o pause no jogo
           //movimentacaocobra=consisteFirstMov(contadordemov10);

        if(movimentacaocobra=='Q')//se a movimenta��o for Q ou esc(27), vai direto para o menu
            menu();
        if(movimentacaocobra==27)
            menu();
    }

    return movimentacaocobra;
}

char consisteFirstMov(int *contadordemov10, int pontuacao[])//a cobra come�a parada, logo, o primeiro movimento deve ser consistido para que ela n�o se coma
{
    char movimentacaocobra, possivelmov;

    do
    {
        possivelmov=getch();
        if(toupper(possivelmov)=='Q')//se a movimenta��o for Q ou esc(27), vai direto para o menu
           menu();
        if(toupper(possivelmov)==27)
            menu();
        if ((toupper(possivelmov)=='P' )|| (toupper(possivelmov)!='A' && toupper(possivelmov)!='S' && toupper(possivelmov)!='W'))
        {
            movimentacaocobra='D';//p ficar pausada pois a pessoa digitou caracteres n�o permitidos ou pause
        }
        else  movimentacaocobra = toupper(possivelmov);//se for um caractere permitido, cai no else e d�-se toupper a movimenta��o da cobra
       if(possivelmov==-32)//se for as setas que forem clicadas pelo usu�rio, � necess�rio ver se � -32, se sim, quer dizer que s�o setas
        {
            possivelmov=(getch());//e ent�o pega o segundo char, que � a movimenta��o dada pelas setas(-32 � o indentificador e o segundo numero � o movimento mesmo)
            switch(possivelmov)
            {
            case 75:
                movimentacaocobra='A';//seta para a direita � A

                break;
            case 77:
                movimentacaocobra='D';//seta para a esquerda D

                break;
            case 80:
                movimentacaocobra='S';//seta para baixo � S

                break;
            case 72:
                movimentacaocobra='W';//seta para cima � W

                break;

            }
        }

        *contadordemov10 = *contadordemov10 + 1;//a cada detcla diferente o contador de movimentos soma mais um, pois a pessoa fez um movimento
    }
    while(movimentacaocobra=='D');//se foi um caractere n�o permitido, a cobra ganha D(pois a cobra come�a para a esquerda, logo n�o pode ir para direita tecla 'D')

    return movimentacaocobra;// a fun��o retorna a movimenta��o da cobra
}

void movimentaCabeca(int *poscobracoluna, int *poscobralinha, int movimentacaocobra)
{

    switch(movimentacaocobra)//dependendo do movimento da cabe�a, o corpo segue, logo, o ultimo do corpo � "apagado" e colocado uma posi��o a frente
    {
    case 'D'://ou seja, a cabe�a muda e o 1 do corpo ocupa o lucar da cabe�a, o 2 do corpo ocupa o lugar do 1 do corpo e assim sucessivamente

        poscobracoluna[0]++;//o ultimo do corpo � apagado na fun��o "DeslocaCorpo", quando faz-de um gotoxy de espa�o para o lugar que ele estava
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
