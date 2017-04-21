
#include <locale.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<windows.h>
#include <conio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#define LINHA 100
#define COLUNA 100

void gotoxy(int x, int y);
void ReestartNasVariaveis(int *ganhou, int *apple_line, int *apple_column, int *apple_counter, int *cont_ratos_aotodo, int *tamanhocobrinha, int *contadorderatos, int arrayrandomcoluna[], int arrayrandomlinha[]);
void Impressao_do_mapa(char andacobrinha[][COLUNA], int linha, int coluna);
void Impressao_das_Pedras(char andacobrinha[][COLUNA], int linha, int coluna);
void Informacoes_ao_jogador(int linha,int nrovidas, int cont_ratos_aotodo,int cont_ratos_comidos, int pontuacaoatual,int nivel);
void DeslocaCorpo(int *tamanhocobrinha, int poscobralinha[], int poscobracoluna[], int arrayratolinha[], int arrayratocoluna[], int *cont_ratos_comidos, int *pontuacaoatual,int linha, int coluna, char andacobrinha[linha][coluna]);
void AtualizaPontuacao(int pontuacao[], int pontuacaoatual);
char validaInput(char movimentacaocobra, int *contadordemov10);
char consisteFirstMov(int *contadordemov10, int pontuacao[]);
void movimentaCabeca(int *poscobracoluna, int *poscobralinha, int movimentacaocobra);
void ImprimeCobra(int linha, int coluna, int tamanhocobrinha, int *gameover, int *poscobralinha, int *poscobracoluna, int movimentacaocobra);
int OpcaoContinuar(int nrovidas, int *tamanhocobrinha, int pontuacao[15]);
void Gerador_de_ratos( int linha, int coluna, int codigo, int contadorderatos, int contratosmortos,
                       int arrayrandomlinha[4], int arrayrandomcoluna[4], int tamanhocobra, int poscobralinha[],
                       int poscobracoluna[], char andacobrinha[linha][coluna], int *appleline, int *applecolumn);
void manual ();
void Apaga_ratos (int arrayrandomlinha[4], int arrayrandomcoluna[4], int contratosmortos);
void apple_generator(int linha, int coluna, int poscobralinha[], int poscobracoluna[], int apple_counter,
                     int *apple_line, int *apple_column, int tamanhocobra, char andacobrinha[linha][coluna],
                     int pontuacao[15], int ratolinha[4], int ratocoluna[4]);
int jogo(int pontuacao[15]);
void menu ();
void CarregaPontuacao(int pontuacao[15]);
void Le_arquivo_texto(char andacobrinha[LINHA][COLUNA], int *linha, int *coluna, int ganhou);


