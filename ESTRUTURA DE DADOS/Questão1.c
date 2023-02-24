#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// definindo a estrutura funcionario
typedef struct funcionario
{

    char nome[50];
    float salario;
    char cargo[50];
    int id;

} Funcionario;

// função para inprimir os funcionarios
void imprime(Funcionario *funcionario, int num_funcionarios)
{
    setlocale(LC_ALL, NULL);
    for (int j = 0; j < num_funcionarios; j++)
    {
        printf("\n");
        printf("Funcionario [%d] \n", j + 1);
        printf("nome: %s \n", funcionario[j].nome);
        printf("salario: %.2f \n", funcionario[j].salario);
        printf("cargo: %s \n", funcionario[j].cargo);
        printf("Identificador: %d \n", funcionario[j].id);
        printf("\n");
        printf("========================================================");
        printf("\n");
    }
}

// função para alterar o salario de um funcionario especifico
void altera_salario(Funcionario *funcionario)
{
    setlocale(LC_ALL, NULL);
    float novo_salario;

    printf("\n");
    printf("========================================================");
    printf("\n");

    printf("Qual o novo salario: ");
    scanf("%f", &novo_salario);

    printf("\n");
    printf("========================================================");
    printf("\n");

    funcionario->salario = novo_salario;
}

// função para dizer qual o maior e qual o menor salario
void maior_menor_salario(Funcionario *funcionario, int *qnt_funcionarios)
{
    setlocale(LC_ALL, NULL);
    int i;
    float maior, menor;
    char c_maior[50], c_menor[50];

    // usando um for para passar por todos os funcionarios
    for (i = 0; i < qnt_funcionarios; i++)
    {
        // quando i for igual a 0
        if (i == 0)
        {
            // as variaveis de maior e menor salario e cargo vão receber o primeiro funcionario
            strcpy(c_maior, funcionario[i].cargo);
            strcpy(c_menor, funcionario[i].cargo);
            maior = funcionario[i].salario;
            menor = funcionario[i].salario;
        }

        if (funcionario[i].salario > maior)
        {
            // se o proximo funcionario for maior, tanto o salario quanto o cargo são preenchidos com seus dados
            maior = funcionario[i].salario;
            strcpy(c_maior, funcionario[i].cargo);
        }
        if (funcionario[i].salario < menor)
            ;
        {
            // se for menor segue a mesma lógica
            menor = funcionario[i].salario;
            strcpy(c_menor, funcionario[i].cargo);
        }
    }

    // imprimindo o maior e menor salario e seu respectivo cargo
    printf("O maior salário é %f \n", maior);
    printf("O maior cargo é %s \n", c_maior);
    printf("O menor salário é %f \n", menor);
    printf("O menor cargo é %s \n", c_menor);
}

// função principal
int main(void)
{
    setlocale(LC_ALL, NULL);
    int num_funcionarios, i;

    // pedindo para o usuario informar o numero de funcionarios
    printf("Quantos funcionários deseja cadastrar: ");
    scanf("%d", &num_funcionarios);

    // alocando dinamicamente os funcionarios de acordo com o numero de funcionarios
    Funcionario *funcionario = (Funcionario *)malloc(num_funcionarios * sizeof(Funcionario));

    // preenchendo as informações de cada funcionario
    for (i = 0; i < num_funcionarios; i++)
    {
        printf("\n");
        printf("Digite o nome do usuario %d: ", i + 1);
        scanf(" %[^\n]", &funcionario[i].nome);

        printf("Digite o salario do usuario %d: ", i + 1);
        scanf("%f", &funcionario[i].salario);

        printf("Digite o cargo do usuario %d: ", i + 1);
        scanf(" %[^\n]", &funcionario[i].cargo);

        printf("Digite o id do usuario %d: ", i + 1);
        scanf("%d", &funcionario[i].id);

        printf("\n");
        printf("========================================================");
        printf("\n");
    }

    // chamando a função imprime
    imprime(funcionario, num_funcionarios);

    // firula
    printf("========================================================");
    printf("\n");

    // chamando a função maior_menor_funcionario
    maior_menor_salario(funcionario, num_funcionarios);

    // perguntando qual funcionario é desejado alterar o salario
    int funcio;
    printf("Qual funcionario você deseja alterar o salario: ");
    scanf("%d", &funcio);

    // chamando a função altera_salario
    altera_salario(&funcionario[funcio - 1]);

    // chamado a função imprime
    imprime(funcionario, num_funcionarios);

    // exibindo denovo o maior e o menor
    maior_menor_salario(funcionario, num_funcionarios);

    // liberando a memoria
    free(funcionario);

    return 0;
}