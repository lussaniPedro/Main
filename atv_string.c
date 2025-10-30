#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main(){
    char *str[3];
    char strAux[MAX];

    printf("Digite tres palavras:\n");
    for(int i = 0; i < 3; i++){
        gets(strAux);
        str[i] = (char*)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(str[i], strAux);
    }

    for(int i = 0; i < 2; i++){
        for(int j = i + 1; j < 3; j++){
            if(strlen(str[i]) > strlen(str[j])){
                char *tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
        }
    }

    for(int i = 0; i < 3; i++){
        if(i < 2){
            printf("%s - ", str[i]);
        } else{
            printf("%s", str[i]);
        }
    }
}