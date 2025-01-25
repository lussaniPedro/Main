// Exercicio da universidade de Harvard -> 'https://cs50.harvard.edu/x/2022/psets/3/tideman/'
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CANDIDATOS 9 // Número máximo de candidatos

/* Declaração de structs */
typedef struct{
    char *nome;
} TCandidato;

typedef struct{
    int winner;
    int loser;
} TPares;

/* Declaração de funções */
void cadastrar_candidatos(); // Cadastra os candidatos
void classificar_candidatos(int votos); // Classifica o rank dos candidatos por votação
void somar_preferencia(int rank[]); // Soma as preferências dos candidatos por rank
void criar_pares(); // Cria os pares de vencedores e perdedores
void ordenar_pares(); // Ordena os pares de vencedores e perdedores
void valida_alocacao(void *ptr); // Valida a alocação de memória

/* Variáveis globais */
TCandidato candidatos[MAX_CANDIDATOS];
int num_candidatos = 0;

TPares pares[MAX_CANDIDATOS] = {0};
int num_pares = 0;

int preferencias[MAX_CANDIDATOS][MAX_CANDIDATOS] = {0};


int main(){
    int votos = 0;

    cadastrar_candidatos();

    printf("Digite a quantidade de votos: ");
    scanf("%d", &votos);
    fflush(stdin);

    if(votos < 1){
        printf("\nQuantidade de votos invalida!\n");
        exit(1);
    }

    classificar_candidatos(votos);

    return 0;
}

void ordenar_pares(){
    for(int i = 0; i < num_candidatos; i++){
        
    }
}

void criar_pares(){
    for(int i = 0; i < num_candidatos; i++){
        for(int j = 0; j < num_candidatos; j++){
            if(preferencias[i][j] > preferencias[j][i]){
                pares[num_pares].winner = i;
                pares[num_pares].loser = j;
                num_pares++;    
            }
        }
    }
}

void somar_preferencia(int rank[]){
    for(int i = 0; i < num_candidatos - 1; i++){
        for(int j = 0; j < num_candidatos; j++){
            preferencias[rank[i]][rank[j]] = j;
        }
    }
}

void classificar_candidatos(int votos){
    char str[100];
    int rank[MAX_CANDIDATOS];

    for(int i = 0; i < votos; i++){    
        for(int j = 0; j < num_candidatos; j++){
            bool check = false;
            printf("Rank %d: ", j + 1);
            gets(str);

            for(int k = 0; k < num_candidatos; k++){
                if(strcmp(candidatos[k].nome, str) == 0){
                    check = true;
                    rank[j] = k;
                    break;
                }
            }


            if(!check){
                printf("\nCandidato invalido!\n");
                exit(1);
            }
        }

        somar_preferencia(rank);
        printf("\n");
    }
}

void cadastrar_candidatos(){
    char str[1000];

    printf("Digite os candidatos (separados por espaco): ");
    gets(str);

    char *strAux = strtok(str, " ");
    while(strAux != NULL){
        candidatos[num_candidatos].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        valida_alocacao(candidatos[num_candidatos].nome);
        strcpy(candidatos[num_candidatos].nome, strAux);

        num_candidatos++;

        strAux = strtok(NULL, " ");
    }

    if(num_candidatos < 2){
        printf("\nQuantidade de candidatos invalida!\n");
        exit(1);
    }

    if(num_candidatos > (MAX_CANDIDATOS - 1)){
        printf("\nO limite de candidatos eh de %d!\n", MAX_CANDIDATOS);
        exit(1);
    }
}

void valida_alocacao(void *ptr){
    if(!ptr){
        printf("\nErro ao alocar memoria!\n");
        exit(1);
    }
}