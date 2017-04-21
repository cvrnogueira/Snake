#include "header.h"
int jogo(int pontuacao[15])
{
    int nrovidas=3;//numero de vidas que a pessoa tem no jogo(o máximo é três)
    int contadordemov10=0;///N SEI EXPLICAR
    int contadorderatos =0;//comtador de ratos totais
    int contratosmortos=0;//contador de rator comidos pela cobra
    int contadorderatos_apos4=0;///N SEI EXPLICAR
    int arrayrandomlinha[4], arrayrandomcoluna[4];///N SEI EXPLICAR
    int cont_ratos_aotodo=0, cont_ratos_comidos=0;///N SEI EXPLICAR
    int poscobralinha[LINHA*COLUNA];
    int gameover=0;//gameover=1 continua o jogo e gameover=0 sai do jogo e vai para o menu
    int poscobracoluna[COLUNA*LINHA];
    char andacobrinha[LINHA][COLUNA];//andacobrinha é a matriz que contém as posições da cobra
    int tamanhocobrinha=5;//cobra começa o jogo com o tamanha cinco
    char movimentacaocobra; //corresponde ao caracter que a pessoa digitar(seta ou a s w d)
    int apple_line, apple_column, apple_counter=0;///N SEI EXPLICAR
    int pontuacaoatual=0;// pontuação atual da pessoa no jogo
    srand(time (NULL));//semente randômica
    int linha=0, coluna=0;
    int ganhou=0, nivel=1;
    int pos1, pos2;


    Le_arquivo_texto(andacobrinha, &linha, &coluna, ganhou);
    do // Começa a cada vez que o jogador perde(gameover=0, e chama a DesejaContinuar para ver se ele ganha zero(jogar de novo) ou sair(gameover=1)
    {

         ReestartNasVariaveis(&ganhou, &apple_line, &apple_column, &apple_counter, &cont_ratos_aotodo, &tamanhocobrinha,&contadorderatos, arrayrandomcoluna, arrayrandomlinha);
        Impressao_do_mapa(andacobrinha,linha, coluna);

        Informacoes_ao_jogador(linha, nrovidas, cont_ratos_aotodo, cont_ratos_comidos, pontuacaoatual, nivel);
        movimentacaocobra=consisteFirstMov(&contadordemov10, pontuacao);

            for(pos1=0; pos1<linha; pos1++)
        {
            for(pos2=0; pos2<coluna+1; pos2++)
            {
                if (andacobrinha[pos1][pos2] == 'O')
                {
                    poscobracoluna[0]=pos2;  ///Posições iniciais da cobra
                    poscobralinha[0]=pos1;
                    poscobracoluna[1]=pos2+1;
                    poscobralinha[1]=pos1;
                    poscobracoluna[2]=pos2+2;
                    poscobralinha[2]=pos1;
                    poscobracoluna[3]=pos2+3;
                    poscobralinha[3]=pos1;
                    poscobracoluna[4]=pos2+4;
                    poscobralinha[4]=pos1;
                    ImprimeCobra(linha, coluna, tamanhocobrinha-1, &gameover, poscobralinha, poscobracoluna, movimentacaocobra);
                }
            }
        }



        do
        {
            DeslocaCorpo(&tamanhocobrinha, poscobralinha, poscobracoluna, arrayrandomlinha, arrayrandomcoluna,
                         &cont_ratos_comidos, &pontuacaoatual,linha,  coluna,  andacobrinha);
            Informacoes_ao_jogador2(linha,cont_ratos_comidos, pontuacaoatual);
            movimentacaocobra=validaInput(movimentacaocobra, &contadordemov10);
            movimentaCabeca(poscobracoluna,poscobralinha, movimentacaocobra);
            Impressao_das_Pedras( andacobrinha, linha, coluna);



   if(andacobrinha[poscobralinha[0]][poscobracoluna[0]]=='*')
            {
                tamanhocobrinha = tamanhocobrinha - 1;
                gotoxy(poscobracoluna[tamanhocobrinha], poscobralinha[tamanhocobrinha]);
                printf(" ");
            }
            ImprimeCobra(linha, coluna, tamanhocobrinha-1, &gameover, poscobralinha, poscobracoluna, movimentacaocobra);



            if (contadordemov10 ==10)
            {
                contadordemov10 =0;
                if (contadorderatos < 4)
                {
                    Gerador_de_ratos(linha, coluna,  1,  contadorderatos, contratosmortos, arrayrandomlinha, arrayrandomcoluna,
                                     tamanhocobrinha, poscobralinha,poscobracoluna,andacobrinha, &apple_line, &apple_column);
                    //tamanhocobrinha, poscobralinha, poscobracoluna);
                    contadorderatos ++;
                    cont_ratos_aotodo++;
                    gotoxy(16, linha);
                    printf ("%d", cont_ratos_aotodo);
                }
                else //if (contadordemov40 %40 == 0)
                    if (contadorderatos==4) /// depois que já surgiram 4 ratos, alguns vão comecar a desaparecer
                    {
                        if (contadorderatos_apos4 ==4) ///conta quantos ratos surgiram após os 4 ratos iniciais
                            contadorderatos_apos4=0;
                        if (contratosmortos ==4)
                            contratosmortos=0;
                        Gerador_de_ratos(linha, coluna, 0, contadorderatos, contratosmortos, arrayrandomlinha,
                                         arrayrandomcoluna, tamanhocobrinha, poscobralinha,
                                         poscobracoluna,andacobrinha, &apple_line, &apple_column);
                        ///0 é o codigo para matar os ratos, enquanto 1 é para criá-los
                        contratosmortos ++;
                        Gerador_de_ratos(linha, coluna, 1,  contadorderatos_apos4, contratosmortos, arrayrandomlinha,
                                         arrayrandomcoluna,tamanhocobrinha, poscobralinha,
                                         poscobracoluna,andacobrinha, &apple_line, &apple_column);
                        contadorderatos_apos4++;
                        cont_ratos_aotodo++;
                        gotoxy(16, linha);
                        printf ("%d", cont_ratos_aotodo);
                    }
            }
            if (tamanhocobrinha == 7)
            {
                if (apple_counter == 0)
                {
                    apple_generator(linha, coluna, poscobralinha, poscobracoluna, apple_counter,
                                    &apple_line, &apple_column, tamanhocobrinha,
                                    andacobrinha, pontuacao, &apple_line, &apple_column);
                    apple_counter++;
                }
            }
            Sleep(100);
            if (tamanhocobrinha ==3)
                gameover=1;
            if(poscobralinha[0] == apple_line && poscobracoluna[0] == apple_column)
            {
                system("cls");
                nivel++;
                if (nivel==3)
                {
                    printf("Uhuuuu venceu todas!!!");
                    system("pause");
                    gameover=1;
                    ganhou=1;
                    //nrovidas=0
                }
                else
                {
                    printf("Uhuu ganhou. Vamos para o nivel 2!");
                    system("pause");
                    ganhou=1;
                    Le_arquivo_texto(andacobrinha, &linha, &coluna, ganhou);
                }
            }
        }
        while(gameover==0 && ganhou==0);
        //printf("uaaaauu");
        //system("pause");
        if(gameover==1 && ganhou==0)
        {
            nrovidas--;
            gameover = OpcaoContinuar(nrovidas, &tamanhocobrinha, pontuacao);
            ///Ve se o jogador ainda tem vidas para continuar jogando e se deseja continuar
        }
    }
    while (gameover ==0);
    AtualizaPontuacao(pontuacao, pontuacaoatual);
    return pontuacaoatual;
}

