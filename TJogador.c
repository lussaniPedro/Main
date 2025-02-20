#include <stdio.h>
#include <stdlib.h>
#define N 50

// struct de data
typedef struct Data{
    int dia;
    int mes;
    int ano;
} TData;

// struct de jogador
typedef struct Jogador{
    char nome[N];
    char time[N];
    int gols;
    int camisa;
    TData nasc;
} TJogador;

int validar_data(int dia, int mes, int ano);
void pedir_dados(TJogador *jogador);
void imprimir_dados(TJogador jogador);

int main(){
    TJogador jogador;
    pedir_dados(&jogador);
    imprimir_dados(jogador);
    return 0;
}

// pede os dados do jogador
void pedir_dados(TJogador *jogador){
    int aux;

    printf("Digite o nome do jogador: ");
    gets(jogador->nome);

    printf("Digite a camisa do jogador: ");
    scanf("%d", &jogador->camisa); 
    getchar();

    printf("Digite o time do jogador: ");
    gets(jogador->time);

    printf("Digite o saldo de gols do jogador: ");
    scanf("%d", &jogador->gols);

    do{
        printf("Digite a data de nascimento do jogador: ");
        scanf("%d%d%d", &jogador->nasc.dia, &jogador->nasc.mes, &jogador->nasc.ano);

        aux = validar_data(jogador->nasc.dia, jogador->nasc.mes, jogador->nasc.ano);
        if(aux == 0){
            printf("Data invalida, digite novamente!\n\n");
        }
    } while(aux == 0);

}

// mostra os dados do jogador
void imprimir_dados(TJogador jogador){
    system("cls");
    printf("| Nome: %s\n", jogador.nome);
    printf("| Camisa: %d\n", jogador.camisa);
    printf("| Time: %s\n", jogador.time);
    printf("| Saldo de gols: %d\n", jogador.gols);
    printf("| Nascimento: %d/%d/%d\n", jogador.nasc.dia, jogador.nasc.mes, jogador.nasc.ano);
}

// valida data
int validar_data(int dia, int mes, int ano){
    int x = 1;

    if(ano <= 0){
        x = 0;
    }

    if((mes <= 0) || (mes > 12)){
        x = 0;
    }

    if(mes == 2){
        if(ano % 4 == 0){
            if(dia > 29){
                x = 0;
            }
        } else if(dia > 28){
            x = 0;
        }
    } else if((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11)){
        if(dia > 30){
            x = 0;
        }
    } else if((dia > 31) || (dia <= 0)){
        x = 0;
    }

    return x;
}