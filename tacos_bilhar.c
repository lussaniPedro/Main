#include <stdio.h>
#include <stdlib.h>

/* Dupla: Pedro Henrique e Nathan */

int main(){
    int c, *vet, cont = 0;
    scanf("%d", &c);
    if(c < 1 || c > 100000){
        return 0;
    }
    
    vet = (int *)malloc(c * sizeof(int));

    for(int i = 0; i < c-1;i++){
        scanf("%d ", &vet[i]);
        if(vet[i] < 1 || vet[i] > 10000){
            return 0;
        }
    }
    
    for(int i = 0; i < c;i++){       
        for(int j = i+1; j < c;j++){
            if(vet[i] == vet[j]){
                vet[j] = -1;
                break;
            }
        }
        if(vet[i] != -1){
            cont += 2;
        }
    }
    printf("%d", cont);
}