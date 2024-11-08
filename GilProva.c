#include <stdio.h>
#define MAX 20
int main(){
    char str[MAX];
    int aux[26] = {0}; 
    int i;

    printf("Digite uma string (maximo de 20 caracteres): ");
    gets(str);
    fflush(stdin);

    for(i = 0; str[i] != '\0' && str[i] != '\n'; i++){
        char c = str[i];

        if(c >= 'A' && c <= 'Z'){
            aux[c - 'A']++;
        } else if(c >= 'a' && c <= 'z'){
            aux[c - 'a']++;
        }
    }

    printf("String: %s\n", str);
    printf("Totais: ");
    for(i = 0; i < 26; i++){
        if(aux[i] > 0){
            printf("[%c=%d]", i + 'a', aux[i]);
        }
    }

    return 0;
}