#include <stdio.h>
#include <stdlib.h>

int main()
{
    // criando as variaveis
    int n_questoes, i, j;
    char gabarito[100], **respostas;
    float nota[10], nota_minima = 6.0, porcentagem_aprovados;
    int aprovados = 0, reprovados = 0;

    // pedindo para o usuario informar o numero de questões e o gabarito
    printf("Digite o número de questões: ");
    scanf("%d", &n_questoes);
    printf("Digite o gabarito da prova: ");
    scanf("%s", gabarito);

    // alocando dinamicamente as respostas como ponteiro de ponteiro
    respostas = (char **)malloc(10 * sizeof(char *));
    if (respostas == NULL)
    {
        // se a alocação falhar emite a mensagem de erro e fecha o programa
        printf("Erro ao alocar memória!");
        exit(1);
    }

    // usando laço de repetição para alocar dinamicamente as respostas de acordo com o numero de questões
    for (i = 0; i < 10; i++)
    {
        respostas[i] = (char *)malloc(n_questoes * sizeof(char));
        if (respostas[i] == NULL)
        {
            printf("Erro ao alocar memória!");
            exit(1);
        }
    }

    // usando um for para passar o gabarito dos alunos
    for (i = 0; i < 10; i++)
    {
        printf("Digite as respostas do aluno %d: ", i + 1);
        scanf("%s", respostas[i]);

        nota[i] = 0;
        // usando outro for para comparar as respostas do aluno com o gabarito e calculando a média do aluno
        for (j = 0; j < n_questoes; j++)
        {
            if (respostas[i][j] == gabarito[j])
            {
                nota[i] += 10.0 / n_questoes;
            }
        }
        printf("Nota do aluno %d: %.2f\n", i + 1, nota[i]);

        // se a nota for maior do que a nota minima, a variavel aprovados é incrementada
        if (nota[i] >= nota_minima)
        {
            aprovados++;
        }
        else
        {
            // se não a quantidade de reprovados é incrementada
            reprovados++;
        }
    }

    // calculando a porcentagem de aprovação e printando ela
    porcentagem_aprovados = 100.0 * aprovados / (aprovados + reprovados);

    printf("Porcentagem de aprovados: %.2f%%\n", porcentagem_aprovados);

    // liberando a memória
    for (i = 0; i < 10; i++)
    {
        free(respostas[i]);
    }
    free(respostas);

    return 0;
}