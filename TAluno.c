#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N_NOTAS 4

/* Declaração de funções */
void criaAluno(); // Lê os dados do aluno
void imprimir_dados(); // Exibe dados da turma
void verifica_alocacao(void *pAux); // Verifica se a alocação foi bem sucedida
void limpaTurma(); // Limpa os ponteiros alocados

/* Declaração de structs */
typedef struct{
    char *NMateria;
    float notas[N_NOTAS];
} TMateria; // Struct matéria

typedef struct{
    char *nome;
    int num_materias;
    int num_alunos;
    float mediaNotas;
    TMateria *grade;
} TAluno; // Struct aluno

TAluno *info24;
int num_alunos;

int main(){

    system("cls");
    criaAluno();
    imprimir_dados();
    return 0;
}

void criaAluno(){
    char strAux[100];
    float soma = 0;
    int  num_materias, i, j, k;

    do{
        printf("Digite a quantidade de alunos: ");
        scanf("%d", &num_alunos);
        fflush(stdin);
        if(num_alunos < 0){
            printf("Numero invalido!\n\n");
        } else{
            info24 = (TAluno*)malloc(num_alunos * sizeof(TAluno));
            verifica_alocacao(info24);
        }
    } while(num_alunos < 0);

    system("cls");
    for(i = 0; i < num_alunos; i++){
        printf("Digite o nome do aluno [%d]: ", i+1);
        gets(strAux);
        fflush(stdin);
        info24[i].nome = (char*)malloc(strlen(strAux) + 1 * sizeof(char));
        verifica_alocacao(info24[i].nome);
        strcpy(info24[i].nome, strAux);
    }

    system("cls");
    for(i = 0; i < num_alunos; i++){
        do{
            printf("Digite o numero de materias do aluno %s: ", info24[i].nome);
            scanf("%d", &num_materias);
            fflush(stdin);
        } while(num_materias < 0);
        if(num_materias < 0){
            printf("Numero invalido!\n\n");
        } else{
            info24[i].num_materias = num_materias;
            info24[i].grade = (TMateria*)malloc(num_materias * sizeof(TMateria));
            verifica_alocacao(info24[i].grade);
        }
    }

    system("cls");
    for(i = 0; i < num_alunos; i++){
        soma = 0;
        for(j = 0; j < info24[i].num_materias; j++){
            printf("Digite o nome da materia [%d] do aluno %s: ", j+1, info24[i].nome);
            gets(strAux);
            fflush(stdin);
            info24[i].grade[j].NMateria = (char*)malloc(strlen(strAux) + 1 * sizeof(char));
            verifica_alocacao(info24[i].grade[j].NMateria);
            strcpy(info24[i].grade[j].NMateria, strAux);

            for(k = 0; k < N_NOTAS; k++){
                do{
                    printf("Digite a nota [%d] da materia [%d] do aluno [%d]: ", k+1, info24[i].grade->NMateria, info24[i].nome);
                    scanf("%f", &info24[i].grade[j].notas[k]);
                    fflush(stdin);
                    if(info24[i].grade[j].notas[k] > 10 || info24[i].grade[j].notas[k] < 0){
                        printf("Nota invalida, digite novamente!!!\n\n");
                    }
                } while(info24[i].grade[j].notas[k] > 10 || info24[i].grade[j].notas[k] < 0);
                soma += info24[i].grade[j].notas[k];
            }
            info24[i].mediaNotas = soma / (info24[i].num_materias * N_NOTAS);
            system("cls");
        }
    }
}

void imprimir_dados(){
    int i, j, k;

    system("cls");
    printf("Alunos de Info24 (%d):\n\n", num_alunos);
    for(i = 0; i < num_alunos; i++){
        printf("| Aluno [%d]: %s\n", i+1, info24[i].nome);
        for(j = 0; j < info24[i].num_materias; j++){
            printf("|\n");
            printf("| Materia [%d]: %s\n", j+1, info24[i].grade[j].NMateria);
            printf("| [Notas:");
            for(k = 0; k < N_NOTAS; k++){
                printf("  %.2f", info24[i].grade[j].notas[k]);
            }
            printf("]\n");
        }

        printf("| Media: %.2f ", info24[i].mediaNotas);
        if(info24[i].mediaNotas >= 6){
            printf("Aluno aprovado!!!\n\n");
        } else if(info24[i].mediaNotas >= 4){
            printf("Recuperacao!!!\n\n");
        } else{
            printf("Aluno reprovado!!!\n\n");
        }
    }

}

void limpaTurma(){
    for(int i = 0; i < num_alunos; i++){
        for(int j = 0; j < info24[i].num_materias; j++){
            free(info24[i].grade[j].NMateria);
        }
        free(info24[i].grade);
        free(info24[i].nome);
    }

    free(info24);  
}

void verifica_alocacao(void *v){
    if(!v){
        printf("ERRO AO ALOCAR MEMORIA!!!\n\n");
        exit(1);
    }
}