#include <stdio.h>
#include <stdlib.h>
float calcular_azul(int dias){
    if(dias > 15){
        return dias * 10 * 0.90; 
    } else if(dias > 5){
        return dias * 10 * 0.95; 
    } else{
        return dias * 10;
    }
}

float calcular_verde(int dias){
    if(dias > 10){
        printf("O limite para a cor verde eh de 10 dias!!!\n");
        return -1; 
    } else{
        return dias * 15;
    }
}

float calcular_laranja(int dias){
    if(dias > 10){
        return 10 * 20 + (dias - 10) * 20 * 0.10;
    } else{
        return dias * 20;
    }
}

float calcular_vermelho(int dias){
    if(dias > 10){
        return 10 * 25 + (dias - 10) * 25 * 0.30;
    } else{
        return dias * 25;
    }
}

void calcular_preco(){
    int cor, dias, cd = 0;
    float preco = 0, preco_total = 0;

    while (1){
        printf("| Considere:           |\n");
        printf("|                      |\n");
        printf("| CD Azul = 1          |\n");
        printf("| CD Verde = 2         |\n");
        printf("| CD Laranja = 3       |\n");
        printf("| CD Vermelho = 4      |\n");
        printf("|                      |\n");
        printf("| Resetar carrinho = 5 |\n");
        printf("| Finalizar compra = 0 |\n\n");
        printf("Digite o numero: ");
        scanf("%d", &cor);

        if(cor == 5){
            preco_total = 0;
            cd = 0;
            system("cls");
            continue;
        }

        if(cor == 0){
            printf("[O cliente esta levando %d CDs por: R$%.2f]\n", cd, preco_total);
            break;
        }


        printf("Digite a quantidade de dias de locacao: ");
        scanf("%d", &dias);

        switch(cor){
            case 1:
                preco = calcular_azul(dias);
                cd++;
                break;

            case 2:
                preco = calcular_verde(dias);
                cd++;
                break;

            case 3:
                preco = calcular_laranja(dias);
                cd++;
                break;

            case 4:
                preco = calcular_vermelho(dias);
                cd++;
                break;

            default:
                printf("Cor invalida.\n");
                preco = -1;
                break;
        }

        if(preco >= 0){
            printf("O valor total da locacao eh: R$%.2f\n", preco);
            system("pause");
            system("cls");
            preco_total += preco;
        }
    }
}

int main(){
    calcular_preco();
    return 0;
}