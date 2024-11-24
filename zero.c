#include <stdio.h>
#include <stdlib.h>

/* Dupla: Pedro Henrique e Nathan */

int pedirDados(int n, int *num);

int main() {
    int n, soma, *num;

    system("cls");
    printf("Digite o numero de valores a serem digitados: ");
    scanf("%d", &n);
    fflush(stdin);

    num = (int*)malloc(n * sizeof(int));
    soma = pedirDados(n, num);

    printf("\nSaida: %d\n", soma);

    return 0;
}

int pedirDados(int n, int *num){
    int x;

    int index = 0;
    for (int i = 0; i < n; i++) {
        printf("Digite o primeiro valor: ");
        scanf("%d", &x);
        fflush(stdin);

        if (x == 0) {
            if (index > 0) {
                index--;
            }
        } else {
            num[index++] = x;
        }
    }

    int soma = 0;
    for (int i = 0; i < index; i++) {
        soma += num[i];
    }

    return soma;
}