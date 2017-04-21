# Snake
This was my first College Project




Primeiramente, para rodar o jogo é só abrilo no codeblocks e apertar f9 ou o botão de rodar o projeto, não ha necessidade de nenhuma biblioteca adiconal, somente o computador ser windows
pois usamos funções da biblioteca windows.h;
Para não haver a necessidade beiaxa a biblioteca conio, as integrantes do grupo decidiram incluir a função void gotoxy(int x, int y) no próprio header.
-------------------------------------------------------------------------------------------------------------------------------------------------------------
void DeslocaCorpo(int *tamanhocobrinha, int poscobralinha[], int poscobracoluna[], int arrayratolinha[], int arrayratocoluna[], int *cont_ratos_comidos, 
		  int *pontuacaoatual,int linha, int coluna, char andacobrinha[linha][coluna]);
	Essa função, atualiza as posições da cobra: a partir da movimentação da cabeça, faz as outras partes do corpo seguirem as anteriores. Ou seja, 
a primeira parte do corpo da cobra vai receber as coordenadas que pertennciam a cabeça ateriormente. Depois que a última parte do corpo for atualizada,
imprime-se um espaço em branco nas coordenadas que pertenciam à última parte do corpo da cobra. Além disso, a função verifica se as coordenadas da cabeça da
cobrinha são as mesmas de um rato ou de uma pedra. Caso seja um rato, a pontuação e o tamanho da cobra são incrementados. Caso seja uma pedra, o tamanho da cobra é
decrementado. 
--------------------------------------------------------------------------------------------------------------------------------------------------
void AtualizaPontuacao(int pontuacao[], int pontuacaoatual);
	Essa função procura no arranjo pontuacao(que tem 15 elementos), no qual estão armazenados os melhores escores, uma pontuação que seja menor que a total obtida pelo jogador.
Caso não encontrado, a pontuação do usuário não é salva. Caso o oposto ocorra, a pontuação é salva no arranjo e as outras posições desse são atualizadas, de forma
de o arranjo sempre armazene as pontuações em ordem descrescente. Ao final, a função escreve no arquivo o ranking atualizado e depois chama a função
"CarregaPontuacao", a qual o imprime na tela do jogo.
----------------------------------------------------------------------------------------------------------------------------------------------------
char validaInput(char movimentacaocobra, int *contadordemov10);
Essa função valida o movimento posto pelo usuário. Os válidos são somente as flechas e as letras "a", "s", "w" e "d", o "p" para pausar, o "q" e o esq para sair do jogo e ir
direto ao menu, sem salvar a pontuação. Além disso, se o jogador quiser movimentar a cobra para o sentido oposto de sua movimentação no momento, a cobra não obedece o desejo do usuário e assim continua na mesma direção. Por exemplo, se
um jogador pressiona a tecla "d" enquanto a cobra se move para esquerda, a cobra ignora o comando do usuário e continua sua movimentação para a direita. Além disso,
a auxiliar conta os movimentos do usuário. Ao final, retorna o movimento que a cobra deve seguir.

-----------------------------------------------------------------------------------------------------------------------------------
char consisteFirstMov(int *contadordemov10, int pontuacao[]);
	Essa auxiliar funciona da mesma forma que a validaInput, porém especificamente para o primeiro movimento, o qual não pode ser para a direita(essa especificação está
tanto no manual quanto no menu do jogo).

---------------------------------------------------------------------------------------------------------------------------------------------
void movimentaCabeca(int *poscobracoluna, int *poscobralinha, int movimentacaocobra);
	Essa função vai receber o comando validado pelas funções anteriores e movimentar a cabeça de acordo com esse. Por exemplo, se "movimentacaocobra" 
for igual a 'A', o programa irá mover a cabeça da cobra uma posição para cima. 
------------------------------------------------------------------------------------------------------------------------------------------------
void imprimeCobra(int linha, int coluna, int tamanhocobrinha, int *gameover, int *poscobralinha, int *poscobracoluna, int movimentacaocobra);
	Essa função imprime a cabeça e o corpo da cobra, sendo que os caracteres mudam dependendo a direção do comando. Além disso, a função confere se a cobra bateu em parede
ou se comeu o próprio corpo.
------------------------------------------------------------------------------------------------------------------------------------------------------
int OpcaoContinuar(int nrovidas, int *tamanhocobrinha, int pontuacao[15]);
	Essa função primeiramente vê se o usuário tem vidas suficientes para continuar jogando. Se possuir, questiona-o se deseja continuar jogando, e, de acordo
com sua resposta, chama o menu ou retorna ao jogo novamente. Porém, caso o jogador tenha perdido todas suas vidas, ela mostra uma mensagem dizendo que o usuário
nao possui mais vidas para jogar e volta ao menu.
----------------------------------------------------------------------------------------------------------------------------------------------------------
void Gerador_de_ratos( int linha, int coluna, int codigo, int contadorderatos, int contratosmortos,int arrayrandomlinha[4], int arrayrandomcoluna[4], 
		       int tamanhocobra, int poscobralinha[], int poscobracoluna[], char andacobrinha[linha][coluna], int *appleline, int *applecolumn);
	Essa função gera dois números aleatórios que servirão como as coordenadas x e y dos ratos gerados. Antes de usar o comando "gotoxy" para imprimir
o camundongo na tela, a função confere se nas coordenadas geradas há alguma parte do corpo da cobra, uma pedra, uma maçã ou uma parede. Os números aleatórios, 
depois de validados, são armazenados em dois arranjos, um para as coordenadas x geradas e outro para as y.
A variável código utilizada é para saber se a auxiliar, quando chamada, deve criar um rato ou chamar outra que mate o rato. Ou seja, se o código for igual a zero,
a função chama a "Apaga_ratos".
------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Apaga_ratos (int arrayrandomlinha[4], int arrayrandomcoluna[4], int contratosmortos);
	Essa função gera um espaço sobre um rato. A auxiliar apaga os ratos na ordem que foram gerados, ou seja, primeiramente o primeiro rato gerado, o qual está
tem suas coordenadas armazenadas nas posições zero dos arranjos. Para que isso aconteça, é fornecido um contador, que avisa qual a posição que armazena o rato
que deve ser morto. 
-----------------------------------------------------------------------------------------------------------------------------------------------------------------
void manual ();
	A função mostra as regras do jogo e faz o usuário voltar para o menu inicial apertando a tecla 1.
---------------------------------------------------------------------------------------------------------------------------------------------------------------
void apple_generator(int linha, int coluna, int poscobralinha[], int poscobracoluna[], int apple_counter,
                     int *apple_line, int *apple_column, int tamanhocobra, char andacobrinha[linha][coluna],
                     int pontuacao[15], int ratolinha[4], int ratocoluna[4]);
	A função funciona da mesma forma que a "gerador_de_ratos", gera duas coordenadas aleatórias e confere se nessas há uma parte da cobra ou da parede, um rato
ou uma pedra. O "apple_counter" confere se já foi gerada uma maça antes.   
--------------------------------------------------------------------------------------------------------------------------------------------------------------	

int jogo(int pontuacao[15]);
	Essa função tem um laço que chama, enquanto o usuário não bater em seu corpo ou nas paredes e ainda tiver um tamanho suficientemente grande,
 as auxiliares de movimento "deslocacorpo","movimentaCabeca", "imprimeCobra". Também chama a "apple_generator", de acordo com o tamanho da cobrinha e 
a "gerador_de_ratos" a cada dez movimentos. Cada vez que o usuário bate em uma parte de seu corpo ou na parede, ele perde uma vida e assim sai do laço.
Se ele ainda tiver vidas, é questionado se deseja jogar novamente. Caso essa seja a vontade dele, o laço maior, no qual está inserido o mencionado acima, 
volta ao seu início. Assim, jogo começa novamente, com todas as coordenadas dos ratos do último jogo zeradas e o tamanho da cobra de volta ao inicial. 
Se o usuário não tiver mais vidas, ou ainda as tiver e não desejar mais jogar, o programa volta ao menu. Porém, antes de voltar ao menu, chama a "atualizaPontuacao" 
para ver se o total de pontos obtido pelo jogador é suficiente para tê-los salvos no aquivo de texto. Ao final, retorna a pontuação total do jogo, 
a qual só é zerada quando o usuário perde todas suas vidas ou quando esse não deseja jogar novamente.
----------------------------------------------------------------------------------------------------------------------------------------------------
void menu ();
	O menu chama as auxiliares "manual", "loadPontuacao", ou a "jogo" de acordo com a vontade do jogador.
---------------------------------------------------------------------------------------------------------------------------------------------------
void CarregaPontuacao(int pontuacao[15]);
	Seu objetivo é abrir o arquivo binário, escrever o arranjo de highscores no arquivo, imprimi-los na tela 
e, ao final, fechá-lo.
-----------------------------------------------------------------------------------------------------------------------------	
void ReestartNasVariaveis(int *ganhou, int *apple_line, int *apple_column, int *apple_counter, int *cont_ratos_aotodo, int *tamanhocobrinha, int *contadorderatos, int arrayrandomcoluna[], int arrayrandomlinha[]);
	Essa função é chamada a cada início de jogo. Cada vez que o usuário perde, o tamanho da cobrinha volta a ser o inicial e os arranjos de números aleatórios
recebem -1, evitando com que a cobra passe por uma coordenada na qual havia um rato na execução anterior e ganhe pontos injustamente. Além disso, os contadores de
ratos e maçãs que foram gerados são zerados.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Impressao_do_mapa(char andacobrinha[][COLUNA], int linha, int coluna);
	Essa função basicamente imprime o mapa na tela, baseando-se na matriz atualizada na função "Le_arquivo_texto" e os números de linhas e colunas
lá lidos da mesma forma.
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Impressao_das_Pedras(char andacobrinha[][COLUNA], int linha, int coluna);
	Essa função imprime as pedras na tela, é chamada continuamente durante o jogo, para evitar com que as mesmas desaparçam após o jogador passar por cima
delas.
---------------------------------------------------------------------------------------------------------------------------------------------------------------
void Informacoes_ao_jogador(int linha,int nrovidas, int cont_ratos_aotodo,int cont_ratos_comidos, int pontuacaoatual,int nivel);
	Essa função imprime na tela o número de ratos consumidos pelo jogador e sua pontuação. Ela é chamada continuamnete durante o jogo, já que cada vez
que o jogador consome um rato, seus parâmetros são atualizados e necessita-se que os valores mostrados na tela também sejam atualizados enquanto o usuário joga.
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Le_arquivo_texto(char andacobrinha[LINHA][COLUNA], int *linha, int *coluna, int ganhou);
	Essa auxiliar abre o arquivo, o lê, armazena o número de linhas e colunas nas respectivas variáveis e o mapa inteiro presente no arquivo na matriz 
"andacobrinha" e finalmente o fecha. O parâmetro "ganhou" é uma flag para saber qual o arquivo a ser lido. Se o jogador já comeu uma maçã, ganhou recebeu 1 na 
função "jogo". Assim, se ganhou tiver o valor de 1, a função abre o arquivo que armazena o segundo nível. Caso contrário, a auxiliar abre o nível inicial.




