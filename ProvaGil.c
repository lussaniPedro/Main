#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
int main(){
    int vetA[N], vetB[N], vetM[N], i;
    srand((unsigned)time(NULL));

    for(i = 0; i < N; i++){
        vetA[i] = rand()%9 + 1;
        vetB[i] = rand()%9 + 1;
    }

    printf("Vetor A:  ");
    for(i = 0; i < N; i++){
        printf("%d\t", vetA[i]);
    }

    printf("\nVetor B:  ");
    for(i = 0; i < N; i++){
        printf("%d\t", vetB[i]);
    }

    for(i = 0; i < N; i++){
        vetM[i] = vetA[i] * vetB[N - i - 1];
    }
    
    printf("\nVetor M:  ");
    for(i = 0; i < N; i++){
        printf("%d\t", vetM[i]);
    }
}