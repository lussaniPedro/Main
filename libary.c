#include <stdio.h>  
#include <stdlib.h>
#include <string.h>

void *invertstr(char *str)  
{  
    char *strAux;
    int i, j;

    strAux = malloc(strlen(str) + 1 * sizeof(char));
    for(i = strlen(str), j = 0; i > 0; i--, j++){
        strAux = realloc(strAux, (j + 1) * sizeof(char));
        strAux[j] = str[i];
    }
    strAux[j] = '\0';

    return strAux;
}

void appendC(char **str, char c){
    int tam = strlen(*str);
    if(tam > 0){
        *str = realloc(*str, (tam + 1) * sizeof(char));
        if(!str) exit(1);

        (*str)[tam] = c;
        (*str)[tam + 1] = '\0';
    } else{
        *str = malloc(2 * sizeof(char));
        if(!str) exit(1);

        (*str)[tam] = c;
        (*str)[tam + 1] = '\0';
    }
}

void appendS(char **str, char *s){
    int tam = strlen(*str);
    int tamS = strlen(s);
    if(tam > 0){
        *str = realloc(*str, (tam + tamS + 1) * sizeof(char));
        if(!str) exit(1);

        for(int i = 0; i < tamS; i++){
            (*str)[tam + i] = s[i];
        }
        (*str)[tam + tamS] = '\0';
    } else{
        *str = malloc((tam + tamS + 1) * sizeof(char));
        if(!str) exit(1);

        for(int i = 0; i < tamS; i++){
            (*str)[i] = s[i];
        }
        (*str)[tamS] = '\0';
    }
}

void appendI(int **vet, int tam, int num){
    if(tam > 0){
        *vet = realloc(*vet, (tam + 1) * sizeof(int));
        if(!*vet) exit(1);

        (*vet)[tam] = num;
    } else{
        *vet = malloc(2 * sizeof(int));
        if(!*vet) exit(1);

        (*vet)[0] = num;
    }
}

int main(){
    int *vet = malloc(1 * sizeof(int));

    appendI(&vet, 0, 1);
    appendI(&vet, 1, 2);
    appendI(&vet, 2, 3);
    appendI(&vet, 3, 4);
    appendI(&vet, 4, 5);
    appendI(&vet, 5, 6);

    for(int i = 0; i < 6; i++){
        printf("%d\n", vet[i]);
    }

    return 0;
}