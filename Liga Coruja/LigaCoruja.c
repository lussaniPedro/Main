#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <unistd.h>
#include <conio.h>

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
void switchOp(int op);
void opTurma();

TTime *_times = NULL;
int _numTimes = 0;

TTurma *_turmas = NULL;
int _numTurmas = 0;

int main(){
    int op;

    do{
        menu();
        scanf("%d", &op);

        switchOp(op);
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

void switchOp(int op){
    switch(op){
        case 1:
            opTurma();
            break;
        case 2:
            // opTime();
            break;
        case 3:
            printf("Saindo...");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }
}

void opTurma(){
    int op;

    do{
        menuTurma();
        scanf("%d", &op);

        switchOpTurma(op);
    } while(op != 5);    
}

void menuTurma(){
    printf("-- TURMA --\n");
    printf("1. Incluir turma\n");
    printf("2. Alterar turma\n");
    printf("3. Excluir turma\n");
    printf("4. Listar turmas\n");
    printf("5. Voltar\n\n");
    printf("Digite sua opcao: ");
}

void switchOpTurma(int op){
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
    if(_turmas == 0){
        _turmas = (TTurma*)malloc(1 * sizeof(TTurma));
    } else{
        _turmas = (TTurma*)realloc(_turmas, (_numTurmas + 1) * sizeof(TTurma));
    }

    _turmas[_numTimes++] = criarTurma();

    printf("Turma adicionada com sucesso!");
    Sleep(800);
}

TTurma criarTurma(){

}