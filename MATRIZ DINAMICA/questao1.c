#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    // criando as variaveis
    setlocale(LC_ALL, NULL);
    int i, j, M, N, costa = 0;

    // pedindo para o usuario indicar o numero de linhas e de colunas
    printf("Digite o numero de linhas: \n");
    scanf("%d", &M);
    printf("Digite o numero de colunas: \n");
    scanf("%d", &N);
    printf("\n");

    // verificando se M não é menor ou igual a 1 ou se N é maior ou igual a 1000
    if (M <= 1 || N >= 1000)
    {
        // se for o caso, é mostrada a mensagem de erro e encerrado o programa
        printf("Numero de linhas ou colunas invcalido!");
        exit(1);
    }

    // alocando dinamicamente o mapa, começando pelas linhas
    char **mapa = (char **)malloc(M * sizeof(char *));
    // verificando se a alocação foi bem sucedida
    if (mapa == NULL)
    {
        printf("Alocação falhou!");
        exit(1);
    }
    // alocando as colunas do mapa
    for (i = 0; i < M; i++)
    {
        mapa[i] = (char *)malloc(N * sizeof(char));
        if (mapa[i] == NULL)
        {
            printf("Alocação falhou!");
            exit(1);
        }
    }

    // usando um for para o usuário preencher as linhas do mapa
    for (i = 0; i < M; i++)
    {
        printf("\nDigite o mapa da linha %d: \n Exemplo: ..##. \n cada . eh um ponto de agua, enqunato cada # eh um ponto de terra.\n", i);
        scanf("%s", mapa[i]);
    }

    // usando dois for para passar por cada linha e coluna do mapa
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (mapa[i][j] == '#' && ((i == 0 || mapa[i - 1][j] == '.') || (i == M - 1 || mapa[i + 1][j] == '.') || (j == 0 || mapa[i][j - 1] == '.') || (j == N - 1 || mapa[i][j + 1] == '.')))
            {
                // se o # atender a condição, significa que aquele ponto de terra é uma costa
                costa++;
            }
        }
    }

    // imprimindo o mapa
    printf("\n");
    printf("O mapa da região é: ");
    printf("\n");

    for (i = 0; i < M; i++)
    {
        printf("%s", mapa[i]);
        printf("\n");
    }

    // mostrando quantas costas tem o mapa
    printf("\n");
    printf("A região tem %d costas.", costa);
    printf("\n");

    // liberando a memoria
    for (i = 0; i < M; i++)
    {
        free(mapa[i]);
    }
    free(mapa);

    return 0;
}