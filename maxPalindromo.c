#include <stdio.h>
#include <string.h>

int isPalindrome(const char str[]);

int main(){
    char *str = "socorram me em marrocos";
    char straux[100], palindromo[100] = "";
    int len = strlen(str);

    for(int i = 0; i < len; i++){
        for(int j = i; j < len; j++){
            int k = 0;
            for(int x = i; x <= j; x++){
                straux[k++] = str[x];
            }
            straux[k] = '\0';

            if(isPalindrome(straux)){
                if(strlen(straux) > strlen(palindromo)){
                    strcpy(palindromo, straux);
                }
            }
        }
    }
    
    printf("O maior palindromo dentro de %s eh %s\n", str, palindromo);
}

int isPalindrome(const char str[]){
    int tamanho = strlen(str);
    
    for(int i = 0; i < tamanho / 2; i++){
        if (str[i] != str[tamanho - 1 - i]){
            return 0;
        }
    }

    return 1;
}