#include <stdio.h>
#include <stdlib.h>
#define N 100

/* Declaração de funções */
void lerPessoa(); // Cadastra pessoas
void imprimirPessoa(); // Exibe pessoas cadastradas

// Struct Data
typedef struct{
    int dia;
    int mes;
    int ano;
} TData;

// Struct Pessoa
typedef struct{
    char nome[N];
    int idade;
    TData nasc;
} TPessoa;

// Variaveis globais 
TPessoa *pessoa;
int i = 0;

int main(){
    lerPessoa();
    imprimirPessoa();
    return 0;
}

// Cadastra pessoas
void lerPessoa(){
    char c;

    pessoa = (TPessoa*)malloc(sizeof(TPessoa));
    while(1){
        system("cls");
        printf("Digite o nome da pessoa: ");
        gets(pessoa[i].nome);
        fflush(stdin);

        printf("Digite a idade da pessoa: ");
        scanf("%d", &pessoa[i].idade);  
        fflush(stdin);

        printf("Digite a data de nascimento da pessoa (DD/MM/AAAA): ");
        scanf("%d%d%d", &pessoa[i].nasc.dia, &pessoa[i].nasc.mes, &pessoa[i].nasc.ano);
        fflush(stdin);
        i++;

        printf("\nDeseja cadastrar mais uma pessoa? Digite (S) para sim e qualquer outra tecla para nao: ");
        scanf("%c", &c);
        fflush(stdin);

        if (c == 's' || c == 'S'){
            pessoa = realloc(pessoa, (i+1)*sizeof(TPessoa));
        } else{
            system("cls");
            break;
        }   
    }
}

// Exibe pessoas cadastradas
void imprimirPessoa(){
    for(int j = 0; j < i; j++){
        printf("Pessoa (%d):\n", j + 1);
        printf("Nome: %s\n", pessoa[j].nome);
        printf("Idade: %d\n", pessoa[j].idade);
        printf("Data de nascimento: %d/%d/%d\n\n", pessoa[j].nasc.dia, pessoa[j].nasc.mes, pessoa[j].nasc.ano);
    }
}