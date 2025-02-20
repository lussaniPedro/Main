#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>

int main(){
    float peso, doguinho = 0.175, valor = 7.0;

    system("cls");
    printf("Digite seu peso: ");
    scanf("%f", &peso);

    float pesoEmDoguinho = peso / doguinho;
    float valorPessoa = valor * pesoEmDoguinho;

    printf("Calculando");
    for(int i = 0; i < 3; i++){
        printf(".");
        Sleep(700);
    }
    printf("\n");

    printf("\nSeu peso em doguinhos da Gaiosky equivale a %.2f\n", pesoEmDoguinho);
    printf("Voce vale R$%.2f em doguinhos da Gaiosky\n\n", valorPessoa);
}