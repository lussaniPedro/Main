#include <stdio.h>
#include <stdlib.h>

/* Dupla: Pedro Henrique e Nathan */

int main(){
    int N, K, *vetrot, *vetbala, menor;
    scanf("%d %d", &N, &K);

    vetrot = (int *)malloc(N * sizeof(int));
    vetbala = (int *)calloc(K, sizeof(int));

    for(int i = 0; i < N; i++){
        scanf("%d", &vetrot[i]);
    }

    for(int j = 0; j < N; j++){
        for (int i = 1; i <= K; i++){
            if(vetrot[j] == i){
                vetbala[i-1]++;
            }
        }
    }
    
    menor = vetbala[0];

    for (int i = 1; i < K; i++)
    {
        if (vetbala[i] < menor)
        {
            menor = vetbala[i];
        }
    }

    printf("%d", menor);
}