#include <stdio.h>

int main(){
    int tam;

    printf("Digite o tamanho do losangulo: ");
    scanf("%d", &tam);

    for(int i = 0; i < tam; i++){
        printf(" ");
        for(int j = 0; j < i; j++){
            printf("@");
        }
        printf("\n");
    }

    for(int i = tam; i > 0; i--){
        
        for(int j = i; j > 0; j--){
            printf("@");
        }
        printf("\n");
    }
}