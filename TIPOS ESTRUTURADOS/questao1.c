#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAGAS 10
#define MAX_TURMAS 3
#define MAX_NOME 81
#define MAX_NOTAS 3

typedef struct aluno
{
    int mat;
    char nome[MAX_NOME];
    float notas[MAX_NOTAS];
    float media;
} Aluno;

typedef struct turma
{
    char id;   
    int vagas; 
    Aluno * alunos[MAX_VAGAS];
} Turma;

Turma * cria_turma(char id)
{
    Turma * t = (Turma*) malloc(sizeof(Turma));
    t->id = id;
    t->vagas = MAX_VAGAS;

    for (int i = 0; i < MAX_VAGAS; i++)
    {
        t->alunos[i] = NULL;
    }
    return t;    
}

void imprime_turma(Turma ** turmas, int n)
{
    for (int i = 0; i < n; i++)
    {
        Turma * turma = turmas[i];
        printf("Turma %c - Vagas disponiveis: %d\n", turma->id, turma->vagas);
    }
}

Turma * procura_turma(Turma ** turma, int n, char id)
{
    int i = 0;
    int v_i = -1;

     for (i = 0; i < n; i++)
    {
        if (turma[i]->id == id)
        {
            v_i = i;
        }
    }
    if (v_i == -1)
    {
        return NULL;
    }
    else
    {
        return turma[v_i];
    }
}

void matricula_aluno(Turma * turma, int mat, char * nome)
{

    if (turma->vagas == 0)
    {
        printf("Nao ha vagas disponiveis na turma %c.\n", turma->id);
        return;
    }

    Aluno * novo_aluno = malloc(sizeof(Aluno));
    novo_aluno->mat = mat;
    strcpy(novo_aluno->nome, nome);
    novo_aluno->notas[0] = 0;
    novo_aluno->notas[1] = 0;
    novo_aluno->notas[2] = 0;
    novo_aluno->media = 0;

    int i;

    for (i = 0; i < MAX_VAGAS; i++)
    {
        if (turma->alunos[i] == NULL)
        {
            turma->alunos[i] = novo_aluno;
            turma->vagas--;
            printf("Aluno matriculado com sucesso!");
            return;
        }
    }
}

void lanca_notas(Turma *turma)
{
    printf("Lancamento de notas para a turma %c:\n", turma->id);

    for (int j = 0; j < MAX_VAGAS; j++)
    {
        if (turma->alunos[j] != NULL)
        {
            printf("Matricula: %d\t - \tAluno: %s\n", turma->alunos[j]->mat, turma->alunos[j]->nome);
            for (int s = 0; s < 3; s++)
            {
                printf("Digite a nota %d: ", s + 1);
                scanf("%f", &turma->alunos[j]->notas[s]);
            }

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

void imprime_alunos(Turma * turma)
{
    printf("Alunos da turma %s: \n\n",turma->id);
    for (int i = 0; i < MAX_VAGAS; i++)
    {
        Aluno *aluno = turma->alunos[i];
        if (aluno != NULL)
        {
            printf("Matricula: %d\n", aluno->mat);
            printf("Nome: %s\n", aluno->nome);
            printf("Notas: %.1f, %.1f, %.1f\n", aluno->notas[0], aluno->notas[1], aluno->notas[2]);
            printf("Media: %.1f\n\n", aluno->media);
        }
    }
}

int main(void)
{

    char id, nome[MAX_NOME];
    Turma ** turma = (Turma **) malloc(MAX_TURMAS * sizeof(Turma *));

    if (turma == NULL)
    {
        printf("ERRO");
        exit(1);
    }
    Turma * m_turma;
    int controle = 0, n = 0, matricula = 0;
    
    printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\nEste programa gerencia as turmas ofertadas, fornecendo as\nfuncionalidades de matricula, lancamento de notas e listagem de alunos.\n\n");
    while (controle != 6)
    {
        printf("\n\nMenu:\n1-Criar turma\n2-Listar turmas\n3-Matricular aluno\n4-Lancar notas\n5-Listar alunos\n6-Sair\n\nDigite sua opcao: ");
        scanf("%d", &controle);
        system("cls");
        switch (controle)
        {
        case 1:
            printf("Criando uma nova turma...");
            printf("\nDigite um id: ");
            scanf(" %c", &id);
            if (n == MAX_TURMAS)
            {
                printf("numero maximo atingido");
            }
            else if (procura_turma(turma, n, id) != NULL)
            {
                printf("A turma Ja existe!");
            }
            else
            {
                turma[n] = (Turma *)malloc(sizeof(Turma));
                turma[n] = cria_turma(id);
                n++; 
                printf("Turma %c criada com sucesso!", id);
            }
            break;
        case 2:
            imprime_turma(turma, n);
            break;
        case 3:
            printf("Matriculando aluno...");
            printf("\nDigite o id da turma: ");
            scanf(" %c", &id);
            m_turma = procura_turma(turma, n, id);
            if (m_turma != NULL)
            {
                printf("Digite a matricula: ");
                scanf("%d", &matricula);
                printf("Digite o nome: ");
                scanf(" %[^\n]s", (char *)&nome);
                matricula_aluno(m_turma, matricula, nome);
            }
            else
            {
                printf("Turma inexistente!");
            }
            break;
        case 4:
            printf("Lancando notas...");
            printf("\nDigite o id da turma: ");
            scanf(" %c", &id);
            m_turma = procura_turma(turma, n, id);
            if (m_turma != NULL)
            {
                lanca_notas(m_turma);
            }
            else
            {
                printf("Turma inexistente!");
            }
            break;
        case 5:
            printf("Listando alunos...");
            printf("\nDigite o id da turma: ");
            scanf(" %c", &id);
            m_turma = procura_turma(turma, n, id);
            if (m_turma != NULL)
            {
                imprime_alunos(m_turma);
            }
            else
            {
                printf("Turma inexistente!");
            }
            break;
        case 6:
            printf("Obrigado por usar meu programa!");
            break;
        default:
            printf("opcao invalida!");
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        free(turma[i]);
    }

    free(turma);

    return 0;
}
