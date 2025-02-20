#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
#include <stdbool.h>
#include <ctype.h>
#include <conio.h>

#define VITORIA main
#define PINK "\033[38;5;206m"

typedef struct{
    int ano;
    int dia;
    int mes;
} TData;

typedef struct{
    char *str;
    TData data;
} TArquivo;

void menu();

TArquivo *arquivos;

int VITORIA(){
    int op;

    printf(PINK);
    while(true){
        menu();
        scanf("%d", &op);

        // option(op);
    }
}

void menu(){
    printf("Menu\n");
    printf("1. Adicionar arquivo\n");
    printf("2. Listar arquivo\n");
    printf("3. Sair\n\n");
    printf("Digite ");
}

/* void option(int op){
    switch(op){

    }
} */