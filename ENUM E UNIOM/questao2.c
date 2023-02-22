#include <stdio.h>
#include <stdlib.h>

typedef enum tipo
{
    ALIMENTO,
    BEBIDA,
    ELETRONICA
} Tipo;

typedef struct produto
{
    char nome[50];
    float preco;
    Tipo tipo;
} Produto;

void imprime(Produto * produto, int num_produtos)
{
    for (int i = 0; i < num_produtos; i++)
    {
        printf("=======================================\n");
        printf("PRODUTO [%d]\n", i + 1);
        printf("Nome: %s \n", produto[i].nome);
        printf("Idade: %f \n", produto[i].preco);
        if (produto[i].tipo == ALIMENTO)
        {
            printf("TIPO: ALIMENTO \n");
        }
        else if (produto[i].tipo == BEBIDA)
        {
            printf("TIPO: BEBIDA \n");
        }
        else
        {
            printf("TIPO: ELETRONICA \n");
        }
    }
}

int main()
{
    int num_prods;

    printf("Quantos produtos deseja cadastrar: ");
    scanf("%d", &num_prods);

    Produto * produto = (Produto *) malloc(num_prods * sizeof(Produto));

    for (int i = 0; i < num_prods; i++)
    {
        printf("Digite o Nome do Produto [%d]: \n", i + 1);
        scanf(" %[^\n]", produto[i].nome);

        printf("Digite o Preço do Produto [%d]: \n", i + 1);
        scanf("%f", &produto[i].preco);

        printf("Digite o tipo do Produto [%d]: \n[0] - ALIMENTO \n[1] - BEBIDA\n[2] - ELETRONICA \n", i + 1);
        scanf("%d", &produto[i].tipo);
    }

    imprime(produto, num_prods);

    free(produto);

    return 0;
}