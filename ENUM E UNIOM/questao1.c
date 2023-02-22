#include <stdio.h>
#include <stdlib.h>

typedef enum genero
{
    MASCULINO,
    FEMININO
} Genero;

typedef struct pessoa
{
    char nome[50];
    int idade;
    Genero genero;
} Pessoa;

void imprime(Pessoa *pessoa, int num_pessoas)
{
    for (int i = 0; i < num_pessoas; i++)
    {
        printf("=======================================\n");
        printf("PESSOA [%d]\n", i + 1);
        printf("Nome: %s \n", pessoa[i].nome);
        printf("Idade: %d \n", pessoa[i].idade);
        pessoa[i].genero == MASCULINO ? printf("Genero: Masculino\n") : printf("Genero: Feminino\n");
    }
}

int main()
{
    int num_pess;

    printf("Quantas pessoas deseja cadastrar: ");
    scanf("%d", &num_pess);

    Pessoa *pessoa = (Pessoa *)malloc(num_pess * sizeof(Pessoa));

    for (int i = 0; i < num_pess; i++)
    {
        printf("Digite o Nome da Pessoa [%d]: \n", i + 1);
        scanf(" %[^\n]", pessoa[i].nome);

        printf("Digite a idade da Pessoa [%d]: \n", i + 1);
        scanf("%d", &pessoa[i].idade);

        printf("Digite o genero da Pessoa [%d]: \n[0] - MASCULINO \n[1] - FEMININO\n \n", i + 1);
        scanf("%d", &pessoa[i].genero);
    }

    imprime(pessoa, num_pess);

    free(pessoa);

    return 0;
}