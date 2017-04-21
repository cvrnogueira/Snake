#include "header.h"
int jogo(int pontuacao[15])
{
    int nrovidas=3;//numero de vidas que a pessoa tem no jogo(o m�ximo � tr�s)
    int contadordemov10=0;//Incrementado a cada movimento, quando chega a 10 � zerado na fun��o
    int contadorderatos =0;//comtador de ratos que foram impressos na tela
    int contratosmortos=0;//contador de rator comidos pela cobra
    int contadorderatos_apos4=0;//Conta os ratos surigidos ap�s o quarto rato surgido na tela
    int arrayrandomlinha[4], arrayrandomcoluna[4];//armazena as coordenadas X e Y dos ratos
    int cont_ratos_aotodo=0, cont_ratos_comidos=0;
    //conta todos os ratos que foram impressos e os que formam comidos, respectivamente
    int poscobralinha[LINHA*COLUNA];//Armazena as linhas nas quais o corpo da cobra est� incerido
    int gameover=0;//gameover=1 continua o jogo e gameover=0 sai do jogo e vai para o menu
    int poscobracoluna[COLUNA*LINHA]; //Armazena as colunas nas quais o corpo da cobra est� incerido
    char andacobrinha[LINHA][COLUNA];//andacobrinha � a matriz que cont�m as posi��es da cobra
    int tamanhocobrinha=5;//cobra come�a o jogo com o tamanha cinco
    char movimentacaocobra; //corresponde ao caracter que a pessoa digitar(seta ou a s w d)
    int apple_line, apple_column, apple_counter=0;//Armazenam a linha, a coluna e a quantidade de ma��s geradas, respectivamente.
    int pontuacaoatual=0;// pontua��o atual da pessoa no jogo
    srand(time (NULL));//semente rand�mica
    int linha=0, coluna=0; //Armazenar� o n�mero de linhas e colunas lidos do arquivo
    int ganhou=0, nivel=1; //Verifica se o jogador j� comeu uma ma�� e mostra o n�vel, respectivamente
    int pos1, pos2; //contadores para o laco

    Le_arquivo_texto(andacobrinha, &linha, &coluna, ganhou);
    do // Come�a a cada vez que o jogador perde(gameover=0, e chama a DesejaContinuar para ver se ele ganha zero(jogar de novo) ou sair(gameover=1)
    {
        system("color 3");//da cor azul ao jogo
        ReestartNasVariaveis(&ganhou, &apple_line, &apple_column, &apple_counter, &cont_ratos_aotodo, &tamanhocobrinha,&contadorderatos, arrayrandomcoluna, arrayrandomlinha);
        Impressao_do_mapa(andacobrinha,linha, coluna);
        Informacoes_ao_jogador(linha, nrovidas, cont_ratos_aotodo, cont_ratos_comidos, pontuacaoatual, nivel);
        movimentacaocobra=consisteFirstMov(&contadordemov10, pontuacao);
        for(pos1=0; pos1<linha; pos1++)
        {
            for(pos2=0; pos2<coluna+1; pos2++)
            {
                if (andacobrinha[pos1][pos2] == 'O') //A partir da letra O do arquivo, marca s posi��es iniciais da cobra, que inicia com tamanho 5
                {
                    poscobracoluna[0]=pos2;
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
        do //La�o menor, s� acaba quando o usu�rio perder ou mudar de n�vel
        {
            DeslocaCorpo(&tamanhocobrinha, poscobralinha, poscobracoluna, arrayrandomlinha, arrayrandomcoluna,
                         &cont_ratos_comidos, &pontuacaoatual,linha,  coluna,  andacobrinha);
            Informacoes_ao_jogador(linha, nrovidas, cont_ratos_aotodo, cont_ratos_comidos, pontuacaoatual, nivel);
            movimentacaocobra=validaInput(movimentacaocobra, &contadordemov10);
            movimentaCabeca(poscobracoluna,poscobralinha, movimentacaocobra);
            Impressao_das_Pedras( andacobrinha, linha, coluna);
            if(andacobrinha[poscobralinha[0]][poscobracoluna[0]]=='*') //Verifica se o jogador passou por uma pedra
            {
                pontuacaoatual= pontuacaoatual -1;
                if (pontuacaoatual < 0) // Certifica que na� h� pontua��o negativa
                    pontuacaoatual = 0;
                tamanhocobrinha = tamanhocobrinha - 1;
                gotoxy(poscobracoluna[tamanhocobrinha], poscobralinha[tamanhocobrinha]);
                printf(" ");
            }
            ImprimeCobra(linha, coluna, tamanhocobrinha-1, &gameover, poscobralinha, poscobracoluna, movimentacaocobra);

            //A cada 10 movimentos do jogador, um rato surge ou desaparece. Se houver menos de quatro ratos na tela, um novo
            //� impresso. Se quatro j� houverem sido impressos, o primeiro que surgiu � apagado e um novo
            //rato surge na tela. Depois de mais dez movimentos, o mesmo ocorre com o segundo, depois, com o terceiro e
            //e, finalmente, com o quarto. Depois que os quatro ratos iniciais desapareceram, nenhuma de suas coordenadas est�
            //armazenada no array de n�meros aleat�rios, j� que cada rato novo que surge na tela assume as coordenadas do �ltimo
            //rato que foi apagado.

            if (contadordemov10 ==10)
            {
                contadordemov10 =0;
                if (contadorderatos < 4) //Cria-se primeiramente quarto ratos
                {
                    Gerador_de_ratos(linha, coluna,  1,  contadorderatos, contratosmortos, arrayrandomlinha, arrayrandomcoluna,
                                     tamanhocobrinha, poscobralinha,poscobracoluna,andacobrinha, &apple_line, &apple_column);
                    contadorderatos ++;
                    cont_ratos_aotodo++;
                }
                else if (contadorderatos==4) // depois que j� surgiram 4 ratos, alguns v�o comecar a desaparecer
                {
                    if (contadorderatos_apos4 ==4) //conta quantos ratos surgiram ap�s os 4 ratos iniciais
                        contadorderatos_apos4=0; //� zerado a cadda 4 ratos surgidos ap�s o quarto rato
                    if (contratosmortos ==4) //Conta quantos ratos o jogador consumiu
                        contratosmortos=0;// � zerado a cada 4 ratos consumidos
                    Gerador_de_ratos(linha, coluna, 0, contadorderatos, contratosmortos, arrayrandomlinha,
                                     arrayrandomcoluna, tamanhocobrinha, poscobralinha,
                                     poscobracoluna,andacobrinha, &apple_line, &apple_column);
                    //0 � o codigo para matar os ratos, enquanto 1 � para cri�-los
                    contratosmortos ++;
                    Gerador_de_ratos(linha, coluna, 1,  contadorderatos_apos4, contratosmortos, arrayrandomlinha,
                                     arrayrandomcoluna,tamanhocobrinha, poscobralinha,
                                     poscobracoluna,andacobrinha, &apple_line, &apple_column);
                    contadorderatos_apos4++;
                    cont_ratos_aotodo++;
                }
            }
            if (tamanhocobrinha == 10) // Verifica se o tamanho da cobra for grande o suficiente para gerar uma ma��
            {
                if (apple_counter == 0) // Verifica se nenhuma surgiu antes
                {
                    apple_generator(linha, coluna, poscobralinha, poscobracoluna, apple_counter,
                                    &apple_line, &apple_column, tamanhocobrinha,
                                    andacobrinha, pontuacao, &apple_line, &apple_column);
                    apple_counter++;
                }
            }
            Sleep(100); //Velocidade da cobrinha
            if (tamanhocobrinha ==3) //Se a cobrinha for pequena demais, o jogador perde.
                gameover=1;
            if(poscobralinha[0] == apple_line && poscobracoluna[0] == apple_column) //Isso significa que a cobra passou pela maca
            {
                pontuacaoatual= pontuacaoatual+10;
                system("cls");
                nivel++;
                if (nivel==3) //Se o jogador j� est� no segundo n�vel, ele vence!
                {
                    printf("Uhuuuu venceu todas!!!");
                    system("pause");
                    gameover=1; //For�a a sa�da do la�o
                    ganhou=1;
                    //nrovidas=0
                }
                else
                {
                    printf("Uhuu ganhou. Vamos para o nivel 2!"); //Caso ele esteja no n�vel um, o jogo vai para o dois
                    system("pause"); //Pausa para ler a mensagem
                    ganhou=1; //flag para saber qual o n�vel
                    Le_arquivo_texto(andacobrinha, &linha, &coluna, ganhou); //L� o arquivo do segundo n�vel
                }
            }
        }
        while(gameover==0 && ganhou==0);
        if(gameover==1 && ganhou==0) //Verifica se o motivo pelo qual programa saiu do la�o
            // � o fato do jogador ter batido em parede, no seu corpo ou ter um tamanho pequeno demais.
        {
            nrovidas--;
            gameover = OpcaoContinuar(nrovidas, &tamanhocobrinha, pontuacao);
            ///V� se o jogador ainda tem vidas para continuar jogando e se deseja continuar.
        }
    }
    while (gameover ==0);
    AtualizaPontuacao(pontuacao, pontuacaoatual); //atualiza o ranking de acordo recebendo a nova pontua��o do jogador
    return pontuacaoatual;
}

