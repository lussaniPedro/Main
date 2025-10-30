#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define A 3

void imprimir_datas();
void gerar_data(TData *p);

// Struct Data
typedef struct TData{
    int dia;
    int mes;
    int ano;
} TData;

// main
int main(){
    imprimir_datas();
    return 0;
}

// Imprime as datas
void imprimir_datas(){
    srand((unsigned)time(NULL));    
    TData nasc[A];
    int i;

    for(i = 0; i < A; i++){
        gerar_data(&nasc[i]);
        printf("TData: %d/%d/%d\n", nasc[i].dia, nasc[i].mes, nasc[i].ano);
    }
}

// Preenchendo com data aleatória
void gerar_data(TData *p){
    do{
        p->dia = (rand()%31) + 1;
        p->mes = (rand()%12) + 1;
        p->ano = (rand()%100) + 1924;
    } while((p->mes == 2)&&(p->dia >28));
}