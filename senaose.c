#include <stdio.h>
int main(){
    int n1, n2, i, soma;

    printf("Entre com os 2 valores: ");
    scanf("%d %d", &n1, &n2);

    printf("\n\nREPETICAO COM WHILE:\n");
    i = n1;
    soma = 0;
    while(i <= n2){
        printf("%d\n", i);
        soma += i;
        i++;
    }
    printf("Soma de todos os numeros: %d\n", soma);

    printf("\n\nREPETICAO COM DO..WHILE:\n");
    i = n1;
    soma = 0;
    do{
        printf("%d\n", i);
        if (i % 2 == 0) {
            soma += i;
        }
        i++;
    } while (i <= n2);
    printf("Soma dos numeros pares: %d\n", soma);

    printf("\n\nREPETICAO COM FOR:\n");
    for (i = n1; i <= n2; i++) {
        if (i % 2 != 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}
