#include <stdio.h>
#include <stdlib.h>

// definindo uma enum com os generos
typedef enum genero
{
    MASCULINO,
    FEMININO
} Genero;

// criando uma estrutura pessoa
typedef struct pessoa
{
    char nome[50];
    int idade;
    Genero genero;
} Pessoa;

// criando a função para imprimir as pessoas
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

// função principal
int main()
{
    int num_pess;

    // pedindo para o usuário informar o numero de pessoas
    printf("Quantas pessoas deseja cadastrar: ");
    scanf("%d", &num_pess);

    // alocando dinamicamente de acordo com o numero de pessoas
    Pessoa *pessoa = (Pessoa *)malloc(num_pess * sizeof(Pessoa));

    // usando um laço de repetição para cadastrar todas as pessoas
    for (int i = 0; i < num_pess; i++)
    {
        printf("Digite o Nome da Pessoa [%d]: \n", i + 1);
        scanf(" %[^\n]", pessoa[i].nome);

        printf("Digite a idade da Pessoa [%d]: \n", i + 1);
        scanf("%d", &pessoa[i].idade);

        printf("Digite o genero da Pessoa [%d]: \n[0] - MASCULINO \n[1] - FEMININO\n \n", i + 1);
        scanf("%d", &pessoa[i].genero);
    }

    // chamando a função imprime, usando o vetor de pessoas e o numero de pessoas como parametro
    imprime(pessoa, num_pess);

    // liberando a memória
    free(pessoa);

    return 0;
}