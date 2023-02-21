#include <stdio.h>
#include <stdlib.h>

int main() {
    int n_questoes, i, j;
    char gabarito[100], **respostas;
    float nota[10], nota_minima = 6.0, porcentagem_aprovados;
    int aprovados = 0, reprovados = 0;

    printf("Digite o número de questões: ");
    scanf("%d", &n_questoes);
    printf("Digite o gabarito da prova: ");
    scanf("%s", gabarito);

    respostas = (char **) malloc(10 * sizeof(char *));
    if (respostas == NULL) {
        printf("Erro ao alocar memória!");
        exit(1);
    }
    for (i = 0; i < 10; i++) {
        respostas[i] = (char *) malloc(n_questoes * sizeof(char));
        if (respostas[i] == NULL) {
            printf("Erro ao alocar memória!");
            exit(1);
        }
    }

    for (i = 0; i < 10; i++) {
        printf("Digite as respostas do aluno %d: ", i+1);
        scanf("%s", respostas[i]);

        nota[i] = 0;
        for (j = 0; j < n_questoes; j++) {
            if (respostas[i][j] == gabarito[j]) {
                nota[i] += 10.0 / n_questoes;
            }
        }
        printf("Nota do aluno %d: %.2f\n", i+1, nota[i]);

        if (nota[i] >= nota_minima) {
            aprovados++;
        } else {
            reprovados++;
        }
    }

    porcentagem_aprovados = 100.0 * aprovados / (aprovados + reprovados);

    printf("Porcentagem de aprovados: %.2f%%\n", porcentagem_aprovados);

    for (i = 0; i < 10; i++) {
        free(respostas[i]);
    }
    free(respostas);

    return 0;
}