#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// a questão 2 segue a mesma lógica da 1, a unica alteração são as variaveis

typedef struct pessoa
{

    char nome[50];
    int doc;
    int idade;

} Pessoa;

void imprime(Pessoa *pessoa, int num_pessoas)
{

    for (int j = 0; j < num_pessoas; j++)
    {
        printf("\n");
        printf("Pessoa [%d] \n", j + 1);
        printf("nome: %s \n", pessoa[j].nome);
        printf("Nº do documento: %d \n", pessoa[j].doc);
        printf("Idade: %d \n", pessoa[j].idade);
        printf("\n");
        printf("========================================================");
        printf("\n");
    }
}

void altera_idade(Pessoa *pessoa)
{

    float nova_idade;

    printf("\n");
    printf("========================================================");
    printf("\n");

    printf("Qual a idade atualizada: ");
    scanf("%f", &nova_idade);

    printf("\n");
    printf("========================================================");
    printf("\n");

    pessoa->idade = nova_idade;
}

void mais_velho_mais_novo(Pessoa *pessoa, int *qnt_pessoas)
{
    int i;
    int velho, novo;
    char m_velho[50], m_novo[50];

    for (i = 0; i < qnt_pessoas; i++)
    {

        if (i == 0)
        {
            strcpy(m_velho, pessoa[i].nome);
            strcpy(m_novo, pessoa[i].nome);
            velho = pessoa[i].idade;
            novo = pessoa[i].idade;
        }

        if (pessoa[i].idade > velho)
        {
            velho = pessoa[i].idade;
            strcpy(m_velho, pessoa[i].nome);
        }
        if (pessoa[i].idade < novo)
            ;
        {
            strcpy(m_novo, pessoa[i].nome);
            novo = pessoa[i].idade;
        }
    }

    printf("A maior idade é %d \n", velho);
    printf("A pessoa mais velha é %s \n", m_velho);
    printf("O menor idade é %d \n", novo);
    printf("A pessoa mais nova é %s \n", m_novo);
}

int main(void)
{

    int num_pessoas, i;

    printf("Quantos funcionários deseja cadastrar: ");
    scanf("%d", &num_pessoas);

    Pessoa *pessoa = (Pessoa *)malloc(num_pessoas * sizeof(Pessoa));

    for (i = 0; i < num_pessoas; i++)
    {
        printf("\n");
        printf("Digite o nome da pessoa %d: ", i + 1);
        scanf(" %[^\n]", &pessoa[i].nome);

        printf("Digite o documento da pessoa %d: ", i + 1);
        scanf("%d", &pessoa[i].doc);

        printf("Digite a idade da pessoa %d: ", i + 1);
        scanf("%d", &pessoa[i].idade);

        printf("\n");
        printf("========================================================");
        printf("\n");
    }

    imprime(pessoa, num_pessoas);

    printf("========================================================");
    printf("\n");

    mais_velho_mais_novo(pessoa, num_pessoas);

    int pess;
    printf("Qual pessoa você deseja alterar a idade: ");
    scanf("%d", &pess);

    altera_idade(&pessoa[pess - 1]);

    imprime(pessoa, num_pessoas);

    mais_velho_mais_novo(pessoa, num_pessoas);

    free(pessoa);

    return 0;
}