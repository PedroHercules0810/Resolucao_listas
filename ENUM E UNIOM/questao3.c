#include <stdio.h>

// definindo um enum de meses
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

// definindo uma estrutura de datas
typedef struct data
{
    int dia;
    int ano;
    Mes mes;
} Data;

// função principal
int main()
{

    // criando uma variavel do tipo Data
    Data data;

    // pedindo para o usuario informar o dia o mes e o ano
    printf("Digite o dia: \n");
    scanf("%d", &data.dia);
    printf("Digite o mes: \n");
    scanf("%d", &data.mes);
    printf("Digite o ano: \n");
    scanf("%d", &data.ano);

    // mostrando a data com formato dd/mm/aaaa
    printf("%02d/%02d/%d", data.dia, data.mes, data.ano);

    return 0;
}