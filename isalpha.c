#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define GREEN "\033[32m"
#define RESET "\033[0m"
#define INPUTGREEN printf(GREEN); gets(str); printf(RESET);

int main(){
    char str[100];
    int countA = 0, countB = 0, countC = 0;

    system("cls");
    printf("Digite uma string: ");
    INPUTGREEN

    printf("\n");
    for(int i = 0; str[i] != '\0'; i++){
        if(isalpha(str[i])){
            printf("%s'%c'%s eh uma letra!\n", GREEN, str[i], RESET);
            countA++;
        } else if(isdigit(str[i])){
            printf("%s'%c'%s eh um numero!\n", GREEN, str[i], RESET);
            countB++;
        } else{
            printf("%s'%c'%s eh um caracter especial!\n", GREEN, str[i], RESET);
            countC++;
        }
    }

    printf("\n");
    printf("Letras: %d\n", countA);
    printf("Numeros: %d\n", countB);
    printf("Especiais: %d\n\n", countC);

    return 0;
}