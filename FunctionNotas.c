#include <stdio.h>
#define L 5
#define C 4
#define C2 100

void ler_nome(char matNome[L][C2]);
void ler_nota(float nota[L][C]);
void calcular_media(float nota[L][C], float med[L]);
void mostrar_nota(float nota[L][C], float med[L], char matNome[L][C2]);

char matNome[L][C2];
float nota[L][C];
float med[L];

int main(){
    ler_nome(matNome);
    ler_nota(nota);
    calcular_media(nota, med);
    mostrar_nota(nota, med, matNome);

    return 0;
}

void ler_nome(char matNome[L][C2]){
    for(int i = 0; i < L; i++) {
        printf("Digite o nome do aluno (%d): ", i + 1);
        gets(matNome[i]);
    }
}

void ler_nota(float nota[L][C]){
    for(int i = 0; i < L; i++){
        float soma = 0;
        for(int j = 0; j < C; j++){
            do {
                printf("Digite a nota [%d] do aluno (%d): ", j + 1, i + 1);
                scanf("%f", &nota[i][j]);
                if(nota[i][j] < 0 || nota[i][j] > 10){
                    printf("Valor inválido, digite novamente!!!\n\n");
                }
            } while (nota[i][j] < 0 || nota[i][j] > 10);
            soma += nota[i][j];
        }
        for(int k = 0; k < C - 1; k++){
            for(int l = 0; l < C - k - 1; l++){
                if(nota[i][l] > nota[i][l + 1]){
                    float temp = nota[i][l];
                    nota[i][l] = nota[i][l + 1];
                    nota[i][l + 1] = temp;
                }
            } 
        }
    }
}

void calcular_media(float nota[L][C], float med[L]){
    for(int i = 0; i < L; i++){
        float soma = 0;
        for(int j = 0; j < C; j++){
            soma += nota[i][j];
        }
        med[i] = soma / C;
    }
}

void mostrar_nota(float nota[L][C], float med[L], char matNome[L][C2]){
    for(int i = 0; i < L; i++){
        printf("Nome: %s\n", matNome[i]);
        printf("[");
        for(int j = 0; j < C; j++){
            printf("nota [%d]: %.2f\t", j + 1, nota[i][j]);
        }
        printf("A media eh: %.2f]\n", med[i]);

        if(med[i] >= 7){
            printf("Aluno Aprovado!!!\n");
        } else if(med[i] >= 4){
            printf("Recuperacao!\n");
        } else{
            printf("Reprovado!\n");
        }
    }
}