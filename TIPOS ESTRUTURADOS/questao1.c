#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definindo algumas constantes
#define MAX_VAGAS 10
#define MAX_TURMAS 3
#define MAX_NOME 81
#define MAX_NOTAS 3

//Definindo a estrutura do tipo aluno
typedef struct aluno
{
    int mat;
    char nome[MAX_NOME];
    float notas[MAX_NOTAS];
    float media;
} Aluno;

//definindo a estrutura turma
typedef struct turma
{
    char id;   
    int vagas; 
    Aluno * alunos[MAX_VAGAS];
} Turma;

//criando a função que cria turmas
Turma * cria_turma(char id)
{
    //alocando dinamicamente uma turma
    Turma * t = (Turma*) malloc(sizeof(Turma));
    //definindo o id de acordo com o parametro dado pelo usuario
    t->id = id;
    //criando o maximo de vagas
    t->vagas = MAX_VAGAS;

    //criando todas as vagas como NULL
    for (int i = 0; i < MAX_VAGAS; i++)
    {
        t->alunos[i] = NULL;
    }
    return t;    
}

//função para imprimir as turmas
void imprime_turma(Turma ** turmas, int n)
{
    for (int i = 0; i < n; i++)
    {
        Turma * turma = turmas[i];
        printf("Turma %c - Vagas disponiveis: %d\n", turma->id, turma->vagas);
    }
}

//função para procurar a turma pelo id da mesma
Turma * procura_turma(Turma ** turma, int n, char id)
{
    int i = 0;
    int v_i = -1;

    //usando o laço de repetição para passar por todas as turmas
     for (i = 0; i < n; i++)
    {
        //verificando se o id da turma[i] é igual ao id a ser comparado
        if (turma[i]->id == id)
        {
            //igualando a variavel de controle a i
            v_i = i;
        }
    }
    //se a variavel de controle não for alterada a função retorna null
    if (v_i == -1)
    {
        return NULL;
    }
    //se v_i for diferente de -1 a função retorna a turma na posição v_i
    else
    {
        return turma[v_i];
    }
}

//função para matricular os alunos
void matricula_aluno(Turma * turma, int mat, char * nome)
{
    //verificando se há vagas disponiveis
    if (turma->vagas == 0)
    {
        printf("Nao ha vagas disponiveis na turma %c.\n", turma->id);
        return;
    }
    //alocando o aluno
    Aluno * novo_aluno = malloc(sizeof(Aluno));
    //dando a matricula e o nome de acordo com oque o usuário querer
    novo_aluno->mat = mat;
    strcpy(novo_aluno->nome, nome);
    //atribuindo todas as notas e a media do aluno para 0
    novo_aluno->notas[0] = 0;
    novo_aluno->notas[1] = 0;
    novo_aluno->notas[2] = 0;
    novo_aluno->media = 0;

    int i;

    //usando for para colocar o aluno na turma
    for (i = 0; i < MAX_VAGAS; i++)
    {
        //verificando se há vagas
        if (turma->alunos[i] == NULL)
        {
            //caso tenha o aluno é matriculado e é diminuido a quantidade de vagas
            turma->alunos[i] = novo_aluno;
            turma->vagas--;
            printf("Aluno matriculado com sucesso!");
            return;
        }
    }
}

//função para lanças as notas dos alunos
void lanca_notas(Turma * turma)
{
    printf("Lancamento de notas para a turma %c:\n", turma->id);

    //usando for para passar pelas vagas da turma
    for (int j = 0; j < MAX_VAGAS; j++)
    {
        //se a vaga for diferente de NULL significa que existe o aluno
        if (turma->alunos[j] != NULL)
        {
            printf("Matricula: %d\t - \tAluno: %s\n", turma->alunos[j]->mat, turma->alunos[j]->nome);
            //usando outro for para dar as notas de cada aluno
            for (int s = 0; s < 3; s++)
            {
                printf("Digite a nota %d: ", s + 1);
                scanf("%f", &turma->alunos[j]->notas[s]);
            }

            //aqui é feita a média das notas e colocada no campo média do aluno
            float soma = 0.0;
            for (int s = 0; s < 3; s++)
            {
                soma += turma->alunos[j]->notas[s];
            }
            turma->alunos[j]->media = soma / 3.0;
        }
    }
    printf("Notas lancadas com sucesso!\n");
}

//função para imprimir os alunos 
void imprime_alunos(Turma * turma)
{
    printf("Alunos da turma %s: \n\n",turma->id);
    //laço de repetição que passa por todas as vagas
    for (int i = 0; i < MAX_VAGAS; i++)
    {
        Aluno *aluno = turma->alunos[i];
        //se a vaga etiver preenchida é msotrada as informações do aluno
        if (aluno != NULL)
        {
            printf("Matricula: %d\n", aluno->mat);
            printf("Nome: %s\n", aluno->nome);
            printf("Notas: %.1f, %.1f, %.1f\n", aluno->notas[0], aluno->notas[1], aluno->notas[2]);
            printf("Media: %.1f\n\n", aluno->media);
        }
    }
}

//função principal
int main(void)
{

    //criando algumas variaveis e alocando dinamicamente as turmas
    char id, nome[MAX_NOME];
    Turma ** turma = (Turma **) malloc(MAX_TURMAS * sizeof(Turma *));

    /*
        As turmas são alocadas como ponteiro de ponteiro por cada turma ter N alunos que têm N notas
    */

   //verificando se a alocação foi bem sucedida
    if (turma == NULL)
    {
        printf("ERRO");
        exit(1);
    }

    //criando mais uma turma e algumas variaveis de controle
    Turma * m_turma;
    int controle = 0, n = 0, matricula = 0;
    
    //criando o menu
    printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\nEste programa gerencia as turmas ofertadas, fornecendo as\nfuncionalidades de matricula, lancamento de notas e listagem de alunos.\n\n");

    //usando while para manter o programa funcionando até o usuario apertar 6
    while (controle != 6)
    {
        printf("\n\nMenu:\n1-Criar turma\n2-Listar turmas\n3-Matricular aluno\n4-Lancar notas\n5-Listar alunos\n6-Sair\n\nDigite sua opcao: ");
        scanf("%d", &controle);
        system("cls");
        switch (controle)
        {
        case 1:
        //este caso é para criar a turma
            printf("Criando uma nova turma...");
            printf("\nDigite um id: ");
            scanf(" %c", &id);
            //verificando se n atingiu o maximo de turmas
            if (n == MAX_TURMAS)
            {
                printf("numero maximo atingido");
            }
            //verificando se já existe uma turma com aquele id
            else if (procura_turma(turma, n, id) != NULL)
            {
                printf("A turma Ja existe!");
            }
            //caso não caia em nenhuma restrição acimma
            else
            {
                //aloca dinamicamente a turma no indice n
                turma[n] = (Turma *)malloc(sizeof(Turma));
                turma[n] = cria_turma(id);
                //n é incrementado em 1
                n++; 
                printf("Turma %c criada com sucesso!", id);
            }
            break;
        case 2:
        //simplesmente chamando a função imprime turma, usando como parametro a turma criada antes e n
            imprime_turma(turma, n);
            break;
        case 3:
        //nesse caso deve-se matricular um aluno
            printf("Matriculando aluno...");
            printf("\nDigite o id da turma: ");
            scanf(" %c", &id);

            //é feita uma busca pela turma usando a função procura_turma
            m_turma = procura_turma(turma, n, id);

            //verificando se a turma existe
            if (m_turma != NULL)
            {
                //caso a turma exista o usuario digita os dados do aluno
                printf("Digite a matricula: ");
                scanf("%d", &matricula);
                printf("Digite o nome: ");
                scanf(" %[^\n]s", (char *)&nome);
                //a função matricula_aluno é chamada usando os parametros usados pelo usuario
                matricula_aluno(m_turma, matricula, nome);
            }
            else
            {
                //se não houver turmas é avisado ao usuário
                printf("Turma inexistente!");
            }
            break;
        case 4:
            //neste caso é feito o lançamento as notas dos alunos
            printf("Lancando notas...");
            printf("\nDigite o id da turma: ");
            scanf(" %c", &id);
            //é feita a mesma busca pelo id da turma, como foi feito anteriormente
            m_turma = procura_turma(turma, n, id);
            
            //verificando se a turma existe
            if (m_turma != NULL)
            {
                //usando a lanca_notas usando m_turma de parametro
                lanca_notas(m_turma);
            }
            else
            {
                //se a turma não existir é mostrada a mensagem de erro
                printf("Turma inexistente!");
            }
            break;
        case 5:
            //neste caso é listado os alunos 
            printf("Listando alunos...");
            printf("\nDigite o id da turma: ");
            scanf(" %c", &id);
            //mesmo processo já citado
            m_turma = procura_turma(turma, n, id);
            if (m_turma != NULL)
            {
                //se a turma existe é listado os alunos
                imprime_alunos(m_turma);
            }
            else
            {
                //se não é mostrada a mensagem de erro
                printf("Turma inexistente!");
            }
            break;
        case 6:
            //encerra o programa
            printf("Obrigado por usar meu programa!");
            break;
        default:
            //se nenhuma das opções corresponderem é mostrada a imagem de erro.
            printf("opcao invalida!");
            break;
        }
    }

    //desalocando a memória
    for (int i = 0; i < n; i++)
    {
        free(turma[i]);
    }

    free(turma);

    return 0;
}

