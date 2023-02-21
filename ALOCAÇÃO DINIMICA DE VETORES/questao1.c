#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, i;
    char *sexo;
    char *opiniao;
    int contF = 0, contMF = 0, contNM = 0;
    float porcF, porcM;

    printf("Informe o numero de pessoas entrevistadas: ");
    scanf("%d", &N);

    sexo = (char *) malloc(N * sizeof(char));
    opiniao = (char *) malloc(N * sizeof(char));

    for (i = 0; i < N; i++) {
        printf("Informe o sexo (M/F) da pessoa %d: ", i+1);
        scanf(" %c", &sexo[i]);

        printf("Informe a opiniao (g = gostou/ n = nao gostou) do produto da pessoa %d: ", i+1);
        scanf(" %s", &opiniao[i]);
    }

    for (i = 0; i < N; i++) {
        if (sexo[i] == 'F' && opiniao[i] == 'g') {
            contF++;
        } else if (sexo[i] == 'F' && opiniao[i] == 'n') {
            contMF++;
        } else if (sexo[i] == 'M' && opiniao[i] == 'n') {
            contNM++;
        }
    }

    porcF = (float) contF / (N / 100.0);
    porcM = (float) contNM / (N / 100.0);

    printf("\nPorcentagem de mulheres que gostaram do produto: %.2f%%\n", porcF);
    printf("Porcentagem de homens que nao gostaram do produto: %.2f%%\n", porcM);

    free(sexo);
    free(opiniao);

    return 0;
}