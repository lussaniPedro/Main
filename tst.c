#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N_NT 4

typedef struct
{
    char *nm_materias;
    float notas[N_NT];
} tMaterias;

typedef struct
{
    char *nome;
    tMaterias *grade;
    int numDiscpl;
    int num_aluno;
} tAluno;

tAluno* criaaluno()
{
    tAluno *info24;
    int numAluno, i, j, k;
    char straux[200];
    printf("quantos alunos você deseja?: ");
    scanf("%d", &numAluno);
    
    if(numAluno > 0)
    {
        info24 = (tAluno *)malloc(numAluno * sizeof(tAluno));
        info24[0].num_aluno = numAluno;
    }    
                            

    for(i=0; i<numAluno; i++)
    {
            
        printf("qual o nome do %d aluno?: ", i+1);
        fflush(stdin);
        gets(straux);
        fflush(stdin);
        info24[i].nome = (char *)malloc((strlen(straux)+1)*sizeof(char));
        strcpy(info24[i].nome, straux);
        info24[i].numDiscpl = 0;
        while(info24[i].numDiscpl <=0)
        {
            printf("quantas matérias deseja para %s?: ", info24[i].nome);
            scanf("%d", &info24[i].numDiscpl);
        }
        
        info24[i].grade = (tMaterias *)malloc(info24[i].numDiscpl * sizeof(tMaterias));
            
        for(j=0; j<info24[i].numDiscpl; j++)
        {
            printf("Digite o nome da %d disciplina: ", j+1);
            fflush(stdin);
            gets(straux);
            fflush(stdin);
            info24[i].grade[j].nm_materias = (char*) malloc ((strlen(straux)+1) * sizeof(char));
            strcpy(info24[i].grade[j].nm_materias, straux);
                
            for(k=0; k<N_NT; k++)
            {
                info24[i].grade[j].notas[k] = -1;
                while(info24[i].grade[j].notas[k] > 10 || info24[i].grade[j].notas[k] < 0)
                {
                    printf("Digite Nota (%d) de %s: ", k+1, info24[i].nome);
                    scanf("%f", &info24[i].grade[j].notas[k]);
                    if(info24[i].grade[j].notas[k] > 10 || info24[i].grade[j].notas[k] < 0)
                    {
                        printf("Nota inválida, verme.\n");
                    }
                }
            }
        }
    }
    
    return info24;
}

int main()
{
    int numAluno;
    tAluno *info24 = criaaluno();
   
    return 0;
}