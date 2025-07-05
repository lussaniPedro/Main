#include <stdio.h>

int main(){
    int i = 0, n, soma;

    printf("Digite n");
    scanf("%d", &n);

    while(i < n){
        soma = soma - (i+1);
        i++;
        soma = soma + (i+1);
        i++;
    }

    printf("%d", soma);
}