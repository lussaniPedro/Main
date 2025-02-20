// Exercicio da universidade de Harvard -> 'https://cs50.harvard.edu/x/2022/psets/3/tideman/'
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CANDIDATOS 9

typedef struct {
    char *nome;
} TCandidato;

typedef struct {
    int winner;
    int loser;
} TPares;

void cadastrar_candidatos();
void classificar_candidatos(int votos);
void somar_preferencia(int rank[]);
void criar_pares();
void ordenar_pares();
void trancarPares();
void print_winner();
bool has_cycle(int start, int end);
void valida_alocacao(void *ptr);

TCandidato candidatos[MAX_CANDIDATOS];
int num_candidatos = 0;

TPares pares[MAX_CANDIDATOS * (MAX_CANDIDATOS - 1) / 2];
int num_pares = 0;

int preferencias[MAX_CANDIDATOS][MAX_CANDIDATOS] = {0};
bool locked[MAX_CANDIDATOS][MAX_CANDIDATOS] = {false};

int main() {
    int votos = 0;

    cadastrar_candidatos();

    printf("Digite a quantidade de votos: ");
    scanf("%d", &votos);
    fflush(stdin);

    if (votos < 1) {
        printf("\nQuantidade de votos invalida!\n");
        exit(1);
    }

    classificar_candidatos(votos);
    criar_pares();
    ordenar_pares();
    trancarPares();
    print_winner();

    return 0;
}

void ordenar_pares() {
    for (int i = 0; i < num_pares - 1; i++) {
        for (int j = i + 1; j < num_pares; j++) {
            int margem_i = preferencias[pares[i].winner][pares[i].loser] - preferencias[pares[i].loser][pares[i].winner];
            int margem_j = preferencias[pares[j].winner][pares[j].loser] - preferencias[pares[j].loser][pares[j].winner];
            if (margem_i < margem_j) {
                TPares temp = pares[i];
                pares[i] = pares[j];
                pares[j] = temp;
            }
        }
    }
}

void criar_pares() {
    for (int i = 0; i < num_candidatos; i++) {
        for (int j = 0; j < num_candidatos; j++) {
            if (preferencias[i][j] > preferencias[j][i]) {
                pares[num_pares].winner = i;
                pares[num_pares].loser = j;
                num_pares++;
            }
        }
    }
}

void somar_preferencia(int rank[]) {
    for (int i = 0; i < num_candidatos; i++) {
        for (int j = i + 1; j < num_candidatos; j++) {
            preferencias[rank[i]][rank[j]]++;
        }
    }
}

void classificar_candidatos(int votos) {
    char str[100];
    int rank[MAX_CANDIDATOS];

    for (int i = 0; i < votos; i++) {
        for (int j = 0; j < num_candidatos; j++) {
            bool check = false;
            printf("Rank %d: ", j + 1);
            gets(str);

            for (int k = 0; k < num_candidatos; k++) {
                if (strcmp(candidatos[k].nome, str) == 0) {
                    check = true;
                    rank[j] = k;
                    break;
                }
            }

            if (!check) {
                printf("\nCandidato invalido!\n");
                exit(1);
            }
        }

        somar_preferencia(rank);
        printf("\n");
    }
}

void cadastrar_candidatos() {
    char str[1000];

    printf("Digite os candidatos (separados por espaco): ");
    gets(str);

    char *strAux = strtok(str, " ");
    while (strAux != NULL) {
        candidatos[num_candidatos].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        valida_alocacao(candidatos[num_candidatos].nome);
        strcpy(candidatos[num_candidatos].nome, strAux);

        num_candidatos++;

        strAux = strtok(NULL, " ");
    }

    if (num_candidatos < 2) {
        printf("\nQuantidade de candidatos invalida!\n");
        exit(1);
    }

    if (num_candidatos > (MAX_CANDIDATOS - 1)) {
        printf("\nO limite de candidatos eh de %d!\n", MAX_CANDIDATOS);
        exit(1);
    }
}

void trancarPares() {
    for (int i = 0; i < num_pares; i++) {
        if (!has_cycle(pares[i].loser, pares[i].winner)) {
            locked[pares[i].winner][pares[i].loser] = true;
        }
    }
}

bool has_cycle(int start, int end) {
    if (start == end) {
        return true;
    }

    for (int i = 0; i < num_candidatos; i++) {
        if (locked[start][i]) {
            if (has_cycle(i, end)) {
                return true;
            }
        }
    }

    return false;
}

void print_winner() {
    for (int i = 0; i < num_candidatos; i++) {
        bool is_source = true;
        for (int j = 0; j < num_candidatos; j++) {
            if (locked[j][i]) {
                is_source = false;
                break;
            }
        }
        if (is_source) {
            printf("Vencedor: %s\n", candidatos[i].nome);
            return;
        }
    }
}

void valida_alocacao(void *ptr) {
    if (!ptr) {
        printf("\nErro ao alocar memoria!\n");
        exit(1);
    }
}