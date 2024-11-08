#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    int dia;
    int mes;
    int ano;
} TData;

typedef struct{
    char *nome;
    char *curso;
    int ano;
} TTurma;

typedef struct{
    char *nome;
    char *matricula;
    int camisa;
    char **posicao;
    TData nasc;
    TTurma turma;
} TJogador;

typedef struct{
    char *nome;
    char *tecnico;
    TJogador jogador;
    TTurma turma[2];
} TTime;

/* Declaração de funções */
void menu();
void op_menu(int op);
void op_turma();

TTime *_times;
int _numTimes = 0;

int main(){
    int op;

    do{
        menu();
        scanf("%d", &op);

        op_menu(op);
    } while(op != 3);

    return 0;
}

void menu(){
    system("cls");
    printf("-- LIGA CORUJA DE FUTSAL --\n\n");
    printf("1. Turmas\n");
    printf("2. Times\n");
    printf("3. Sair\n\n");
    printf("Digite a opcao: ");
}

void menu_turma(){
    system("cls");
    printf("1. Incluir turma\n");
    printf("2. Listar turmas\n");
    printf("3. Alterar turma\n");
    printf("4. Excluir turma\n");
    printf("5. Voltar\n\n");
    printf("Digite a opcao: ");
}

void op_menu(int op){
    switch(op){
        case 1:
            op_turma();
            break;
        case 2:
            // op_time();
            break;
        case 3:
            printf("Saindo...");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }
}

void op_turma(){
    int op;

    do{
        menu_turma();
        scanf("%d", &op);

        op_menu_turma(op);
    } while(op != 5);    
}

void op_menu_turma(int op){
    switch(op){
        case 1:
            incluirTurma();
            break;
        case 2:
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }
}

void incluirTurma(){
    if(_times);
}