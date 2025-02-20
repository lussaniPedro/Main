#include <stdio.h>

void ler_data();
void imprimir_data(int dia, int mes, int ano);
int validar_data(int dia, int mes, int ano);

int main(){
    ler_data();
    return 0;
}

void ler_data(){
    int ano, mes, dia;

    printf("Digite o dia:\n");
    scanf("%d", &dia);

    printf("Digite o mes:\n");
    scanf("%d", &mes);

    printf("Digite o ano:\n");
    scanf("%d", &ano);

    imprimir_data(dia, mes, ano);
}

void imprimir_data(int dia, int mes, int ano){
    int data;

    data = validar_data(dia, mes, ano);

    printf("Data digitada: %d/%d/%d\n\n", dia, mes, ano);
    
    if(!data){
        printf("Data invalida");
    }
    else{
       printf("Data valida");
    }
}

int validar_data(int dia, int mes, int ano){
    int x = 1;
    if(ano < 0){
        x = 0;
    }
    if((mes < 0) || (mes > 12)){
        x = 0;
    }    
    if((dia > 31) || (dia < 0)){
        x = 0;
    }
    if(mes == 2){
        if (ano % 4 == 0){
            if(dia > 29){
                printf("Ano invalido!\n");
                x = 0;
            }
        }
        else{
            if(dia > 28){
                printf("Ano invalido\n");
                x = 0;
            }
        }
    }
    else if((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11)){
        if(dia > 30){
            printf("Ano invalido\n");
            x = 0;
        }
    }

    return x;
}