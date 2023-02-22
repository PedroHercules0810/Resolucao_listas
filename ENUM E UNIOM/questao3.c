#include <stdio.h>

typedef enum mes
{
    JANEIRO = 1,
    FEVEREIRO,
    MARCO,
    ABRIL,
    MAIO,
    JUNHO,
    JULHO,
    AGOSTO,
    SETEMBRO,
    OUTUBRO,
    NOVEMBRO,
    DEZEMBRO
} Mes;

typedef struct data
{
    int dia;
    int ano;
    Mes mes;
} Data;

int main()
{

    Data data;

    printf("Digite o dia: \n");
    scanf("%d", &data.dia);
    printf("Digite o mes: \n");
    scanf("%d", &data.mes);
    printf("Digite o ano: \n");
    scanf("%d", &data.ano);

    printf("%02d/%02d/%d", data.dia, data.mes, data.ano);

    return 0;
}