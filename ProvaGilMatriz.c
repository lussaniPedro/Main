#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define L 5
#define C 5
int main(){
    int matrizA[L][C], matrizB[L][C], matrizM[L][C], i, j;
    srand((unsigned)time(NULL));
    
    for(i = 0; i < L; i++){
        for(j = 0; j < C; j++){
            matrizA[i][j] = rand()%9 + 1;
            matrizB[i][j] = rand()%9 + 1;
        }
    }

    for(i = 0; i < L; i++){
        for(j = 0; j < C; j++){
            matrizM[i][j] = matrizA[i][j] * matrizB[L - i - 1][C - j -1];
        }
    }    

    system("cls");
    printf("---------------INICIO---------------\n");
    printf("Matriz A:\n");
    printf("-------------------------------------\n");
    for(i = 0; i < L; i++){
        for(j = 0; j < C; j++){
            printf("| %d |\t", matrizA[i][j]);    
        }
        printf("\n");
    }    
    
    
    printf("-------------------------------------\n");
    printf("Matriz B:\n");
    printf("-------------------------------------\n");
    for(i = 0; i < L; i++){
        for(j = 0; j < C; j++){
            printf("| %d |\t", matrizB[i][j]);    
        }
        printf("\n");
    }    
    
    
    printf("-------------------------------------\n");
    printf("Matriz M:\n");
    printf("-------------------------------------\n");
    for(i = 0; i < L; i++){
        for(j = 0; j < C; j++){
            printf(" %d\t", matrizM[i][j]);    
        }
        printf("\n");
    }    
    
    printf("-----------------FIM-----------------\n");

    return 0;
}