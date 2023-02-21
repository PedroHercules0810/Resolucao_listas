#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
        setlocale(LC_ALL,NULL);
        int i, j, M, N, costa = 0;

    printf("Digite o numero de linhas: \n");
    scanf("%d", &M);
    printf("Digite o numero de colunas: \n");
    scanf("%d", &N);
    printf("\n");

    if (M <= 1 || N >= 1000)
    {
        printf("Numero de linhas ou colunas invcalido!");
        exit(1);
    }
    

    char **mapa = (char **)malloc(M * sizeof(char *));
    if (mapa == NULL)
    {
        printf("Alocação falhou!");
        exit(1);
    }
    for (i = 0; i < M; i++)
    {
        mapa[i] = (char *)malloc(N * sizeof(char));
        if (mapa[i] == NULL)
        {
            printf("Alocação falhou!");
            exit(1);
        }
    }

    for (i = 0; i < M; i++)
    {
        printf("\nDigite o mapa da linha %d: \n Exemplo: ..##. \n cada . eh um ponto de agua, enqunato cada # eh um ponto de terra.\n",i);
        scanf("%s",mapa[i]);
    }
    
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (mapa[i][j] == '#' && ((i == 0 || mapa[i - 1][j] == '.') || (i == M - 1 || mapa[i + 1][j] == '.') || (j == 0 || mapa[i][j - 1] == '.') || (j == N - 1 || mapa[i][j + 1] == '.')))
            {
                costa++;
            }
        }
    }

    printf("\n");
    printf("O mapa da região é: ");
    printf("\n");

    for (i = 0; i < M; i++)
    {
        printf("%s",mapa[i]);
        printf("\n");
    }
    
    printf("\n");
    printf("A região tem %d costas.",costa);
    printf("\n");

    for (i = 0; i < M; i++)
    {
        free(mapa[i]);
    }
    free(mapa);

    return 0;
}