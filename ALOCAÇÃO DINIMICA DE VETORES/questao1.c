#include <stdio.h>
#include <stdlib.h>

int main()
{
    // criando as variáveis
    int N, i;
    char *sexo;
    char *opiniao;
    int contF = 0, contMF = 0, contNM = 0;
    float porcF, porcM;

    // pedindo para o usuário informar o numero de pessoas
    printf("Informe o numero de pessoas entrevistadas: ");
    scanf("%d", &N);

    // alocando dinamicamente o sexo e a opinão de acordo com N
    sexo = (char *)malloc(N * sizeof(char));
    opiniao = (char *)malloc(N * sizeof(char));

    // usando laço de repetição for para informar o sexo das pessoas e a opinião
    for (i = 0; i < N; i++)
    {
        printf("Informe o sexo (M/F) da pessoa %d: ", i + 1);
        scanf(" %c", &sexo[i]);

        printf("Informe a opiniao (g = gostou/ n = nao gostou) do produto da pessoa %d: ", i + 1);
        scanf(" %s", &opiniao[i]);
    }

    // usando for para fazer a contagem
    for (i = 0; i < N; i++)
    {
        if (sexo[i] == 'F' && opiniao[i] == 'g')
        {
            // se for do sexo Feminino e a opção for que gostou, incrementa a variavel
            contF++;
        }
        else if (sexo[i] == 'F' && opiniao[i] == 'n')
        {
            // se for do sexo feminino e a opção for que não gostou, incrementa outra variavel
            contMF++;
        }
        else if (sexo[i] == 'M' && opiniao[i] == 'n')
        {
            // se o sexxo for masculino e a opção for que não gostou, incrementa outra variavel
            contNM++;
        }
    }

    // canculando as porcentagens
    porcF = (float)contF / (N / 100.0);
    porcM = (float)contNM / (N / 100.0);

    // mostrando as porcentagens
    printf("\nPorcentagem de mulheres que gostaram do produto: %.2f%%\n", porcF);
    printf("Porcentagem de homens que nao gostaram do produto: %.2f%%\n", porcM);

    //liberando a memória
    free(sexo);
    free(opiniao);

    return 0;
}