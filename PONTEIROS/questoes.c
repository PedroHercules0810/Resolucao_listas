#include <stdio.h>

/*

questão 1)
resposta: *p = 4
           x = 3
           y = 4

implementação

int main()
{

    int x, y, *p;
    y = 0;
    p = &y;
    x = *p;
    x = 4;
    (*p)++;
    --x;
    (*p) += x;

    printf("%d \n",*p);
    printf("%d \n",y);
    printf("%d \n",x);

    return 0;
}

*/

/*
int main(void)
{
    int x, *p;
    x = 100;
    *p = x;
    printf("Valor de p = %d\tValor de *p = %d", p, *p);
}

    Questão 2)
    a) o compilador mostra uma mensagem de advertencia.
    b) por estar adicionando um int a um ponteiro sem fazer a conversão
    e está usando um %p dentro de um printf
    c) o programa executa porem não mostra nada
    d) , e) feito acima
*/

/*
    questão 3)

    a = 11
    b = 20
    c= 10
    d = 30

*/

//questão 4

#include <math.h> //stdio.h está no inico do código

void calcula_hexagono(float l, float * area, float * perimetro)
{

    *area = ((3*pow(l,2))*(sqrt(3)))/2;
    *perimetro = 6*l;
    
}

int main()
{

    float l, area, perimetro;

    printf("Digite o comprimento do lado do hexagono: \n");
    scanf("%f", &l);

    calcula_hexagono(l, &area, &perimetro);

    printf("Area do hexagono: %f\n", area);
    printf("Perimetro do hexagono: %f\n", perimetro);

    return 0;
}