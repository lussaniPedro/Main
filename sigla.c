#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

char *criarSigla(char *str);
bool validarSigla(char *sigla);

int main(){
    char str[100];

    printf("Digite um nome composto: ");
    gets(str);

    char *sigla = criarSigla(str);
    if(!validarSigla(sigla)){
        printf("ERRO: A sigla deve conter apenas letras!!!\n");
        exit(1);
    }

    printf("Sigla: %s.", sigla);

    return 0;
}

char *criarSigla(char *str){
    char *sigla = (char*)malloc(1 * sizeof(char));
    int i = 0;

    char *token = strtok(str, " ");
    while(token){
        if(strlen(token) > 3){
            sigla = (char*)realloc(sigla, (i + 1) * sizeof(char));
            sigla[i] = toupper(token[0]);
            i++;
        }

        token = strtok(NULL, " ");
    }
    sigla[i] = '\0';

    return sigla;
}

bool validarSigla(char *sigla){
    for(int i = 0; sigla[i] != '\0'; i++){
        if(!isalpha(sigla[i])){
            return false;
        }
    }

    return true;
}