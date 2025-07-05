#include <stdio.h>

int main(){
    int joao = 170, manoel = 150, i = 0;

    while(joao >= manoel){
        joao += 1;
        manoel += 2;
        i++;
    }

    printf("Manoel ficara maior que joao em %d anos", i);
}