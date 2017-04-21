
#include "header.h"





void menu (int pontuacao[])
{
    setlocale(LC_ALL, "portuguese");//colocar a linguagem português(aceita acentos, por exemplo)
    int option;///N SEI EXPLICAR ESSA AI


    do
    {
        system("cls");
        printf ("   ---      -        ---    ----   --     ---     --------      \n");
        printf ("  /  /     /  \\    /  /   /    |  |  |  /  /     /  _____/     \n");
        printf (" /  /__   /    \\  /  /   /  /| |  |  | /  /     /  /___        \n");
        printf ("/_    /  /  /\\  \\/  /   /  / | |  |   /  /     /  _____/      \n");
        printf ("  /  /  /  /  \\ /  /   /   --  |  |  |\\  \\    /  /____       \n");
        printf (" /  /  /  /    \\  /   /  /   | |  |  | \\  \\  /       /       \n");
        printf ("---    --       ---   ---    ---   ----  --- --------           \n");

        printf("\n");
        printf("               Obrigado por jogar!\n");
        printf("\n");
        printf("               Escolha uma opção:\n");
        printf("\n");
        printf("               0- Jogar novamente\n");
        printf("               1- Ranking\n");
        printf("               2- Regras do jogo\n");
        printf("               3- Encerrar\n");
        printf("               Dica: Caso voc}e não leu as regras, lembre-se que o primeiro movimento NÃO pode ser para direita!\n");
        printf("\n");
        while (scanf ("%d", &option) ==0)
        {
            fflush(stdin);//apaga o buffer para ler o próximo comando do usuário
            printf("Opção Inválida. Opções válidas somente 0, 1, 2 e 3\n");
        }

        fflush(stdin);
        switch (option)
        {
        case 0://zero é para a pessoa ir jogar, se for, chama o arquivo_texto para ler o mapa

            jogo (pontuacao);
            break;
        case 1://Um é para ver o ranking, logo chama a LoadPontuação que mostra o ranking
            CarregaPontuacao(pontuacao);
            system("pause");
            break;
        case 2://2 é para acessar o manual, logo chama-se a função que tem o manual
            manual ();
            break;
            fflush(stdin);
        case 3://3 é para sair, logo imprime-se tchau e sai
           {
            printf("Tchau :D\n");///ACHO Q N TA APAREDENDO ESSE TCHAU
            system("pause");
            exit(EXIT_SUCCESS);
           }
            break;
        default:
            printf("Opção Inválida. Opções válidas somente 0, 1, 2 e 3\n");
            break;
            fflush(stdin);
        }
    }
    while (option != 3);  // && sim_nao != 1 && sim_nao != 2 && sim_nao != 3 && sair!=1);
}
