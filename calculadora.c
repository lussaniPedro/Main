#include <stdio.h>
#include <stdlib.h>
float calcular();

int main(){
    calcular();
    return 0;
}

float calcular(){
    int op;
    float n1, n2, res;

    system("cls");
    printf("| Considere que:     |\n");
    printf("|                    |\n");
    printf("| 1 = Adicao         |\n");
    printf("| 2 = Subtracao      |\n");
    printf("| 3 = Multiplicacao  |\n");
    printf("| 4 = Divisao        |\n\n");

    do{
        printf("Agora digite um operador: ");
        scanf("%d", &op);
        if((op > 4) || (op < 1)){
            printf("Numero invalido\n\n");
        }
    } while((op > 4) || (op < 1));
    system("cls");
    
    printf("Digite o primeiro numero: ");
    scanf("%f", &n1);
    system("cls");
    
    printf("Digite o segundo numero: ");
    scanf("%f", &n2);
    system("cls");
      
    if (op == 1){
        res = n1 + n2;
        printf("O resultado da adicao de %.2f e %.2f eh %.2f", n1, n2, res);
    } else if(op == 2){
        res = n1 - n2;
        printf("O resultado da subtracao de %.2f e %.2f eh %.2f", n1, n2, res);
    } else if(op == 3){
        res = n1 * n2;
        printf("O resultado da multiplicacao de %.2f e %.2f eh %f", n1, n2, res);
    } else if(op == 4){
        if((n1 == 0) || (n2 == 0)){
            printf("numero invalido");
        } else{
            res = n1 / n2;
            printf("O resultado da divisao de %.2f e %.2f eh %.2f", n1, n2, res);
        }
    }

    return res;
}