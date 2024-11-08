#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L 4
#define C 4
#define C2 100
#define C3 1

void pedir_dados();
int validar_data(int dia, int mes, int ano);
void imprimir_dados();

int main(){
    pedir_dados();
    return 0;
}

char nome23[L][C2], nome24[L][C2], conceito23[L * C][C3], conceito24[L * C][C3];
int i  = 0, aux = 0, j = 0, h, ano24[L], ano23[L], mes23[L], mes24[L], dia23[L], dia24[L];
float med23 = 0, med24 = 0, medtotal = 0, notas23[L], notas24[L];

void pedir_dados(){
    for(i = 0; i < L; i++){
        do{
            printf("Digite o nome do aluno (%d) de info23: ", i + 1);
            fgets(nome23[i], C2, stdin);
            if((nome23[i][0] == ' ')||(nome23[i][0] == '\0')){
                printf("Nome Invalido!\n\n");
            }
        } while((nome23[i][0] == ' ')||(nome23[i][0] == '\0'));
        system("cls"); 
    }

    for(i = 0; i < L; i++){
        for(int j = 0; j < C; j++){
            do{
                printf("Digite o conceito [%d] do aluno (%d) de info23 (A, B, C ou D):", j + 1, i + 1);
                gets(conceito23[i * L + j]);
                fflush(stdin);
                if((conceito23[i * L + j][0] != 'A')&&(conceito23[i * L + j][0] != 'B')&&(conceito23[i * L + j][0] != 'C')&&(conceito23[i * L + j][0] != 'D')){
                    printf("Conceito invalido!\n\n");
                }
            } while((conceito23[i * L + j][0] != 'A')&&(conceito23[i * L + j][0] != 'B')&&(conceito23[i * L + j][0] != 'C')&&(conceito23[i * L + j][0] != 'D'));
            system("cls"); 
        }
    }

    for(i = 0; i < L; i++){
        do{
            printf("Digite a nota do aluno (%d) de info23 (0 a 10): ", i + 1);
            scanf("%f", &notas23[i]);
            med23 += notas23[i];
            if((notas23[i] < 0)||(notas23[i] > 10)){
                printf("Nota invalida!\n\n");
            }
        } while((notas23[i] < 0)||(notas23[i] > 10));
        system("cls"); 
    }
    med23 /= 4;

    for(i = 0; i < L; i++){
        do{
            printf("Digite o dia mes e ano em que nasceu o aluno (%d) de info 23: ", i + 1);
            scanf("%d%d%d", &dia23[i], &mes23[i], &ano23[i]);
            getchar();
            aux = validar_data(dia23[i], mes23[i], ano23[i]);
            if(aux == 0){
                printf("Data invalida, digite novamente");
            }
        }while(aux == 0);
        system("cls"); 
    }

    for(i = 0; i < L; i++){
        do{
            printf("Digite o nome do aluno (%d) de info24: ", i + 1);
            fgets(nome24[i], C2, stdin);
            if((nome24[i][0] == ' ')||(nome24[i][0] == '\0')){
                printf("Nome Invalido!\n\n");
            }
        } while((nome24[i][0] == ' ')||(nome24[i][0] == '\0'));
        system("cls"); 
    }

    for(i = 0; i < L; i++){
        for(int j = 0; j < C; j++){
            do{
                printf("Digite o conceito do [%d] aluno (%d) de info24 (A, B, C ou D): ", j + 1, i + 1);
                gets(conceito24[i * L + j]);
                fflush(stdin);
                if((conceito24[i * L + j][0] != 'A')&&(conceito24[i * L + j][0] != 'B')&&(conceito24[i * L + j][0] != 'C')&&(conceito24[i * L + j][0] != 'D')){
                    printf("Conceito invalido!\n\n");
                }
            } while((conceito24[i * L + j][0] != 'A')&&(conceito24[i * L + j][0] != 'B')&&(conceito24[i * L + j][0] != 'C')&&(conceito24[i * L + j][0] != 'D'));
            system("cls"); 
        }
    }

    for(i = 0; i < L; i++){
        do{
            printf("Digite a nota do aluno (%d) de info24 (0 a 10): ", i + 1);
            scanf("%f", &notas24[i]);
            fflush(stdin);
            med24 += notas24[i];
            if((notas24[i] < 0)||(notas24[i] > 10)){
                printf("Nota invalido!\n\n");
            }
        } while((notas24[i] < 0)||(notas24[i] > 10));
        system("cls"); 
    }
    med24 /= 4;

    for(i = 0; i < L; i++){
        do{
            printf("Digite o dia mes e ano em que nasceu o aluno (%d) de info 24: ", i + 1);
            scanf("%d%d%d", &dia24[i], &mes24[i], &ano24[i]);
            aux = validar_data(dia24[i], mes24[i], ano24[i]);
            if(aux == 0){
                printf("Data invalida, digite novamente");
            }
        }while(aux == 0);
        system("cls"); 
    }
    
    imprimir_dados();
}

int validar_data(int dia, int mes, int ano){
    int x = 1;

    if(ano <= 0){
        x = 0;
    }

    if((mes <= 0) || (mes > 12)){
        x = 0;
    }

    if(mes == 2){
        if(ano % 4 == 0){
            if(dia > 29){
                x = 0;
            }
        } else if(dia > 28){
            x = 0;
        }
    } else if((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11)){
        if(dia > 30){
            x = 0;
        }
    } else if((dia > 31) || (dia <= 0)){
        x = 0;
    }

    return x;
}

void imprimir_dados(){   
    system("pause");
    system("cls");
    printf("INFO 23\n");
    
    for(i = 0; i < L; i++){
        printf("Aluno %d:\n", i + 1);
        printf("Nome: %s ", nome23[i]);
        printf("[Conceito: ");
        for(j = 0; j < C; j++){
            printf("%c ", conceito23[i * L + j][0]);
        }
        printf("Nota: %.2f ", notas23[i]);
        printf("Nascimento: %d/%d/%d]", dia23[i], mes23[i], ano23[i]);
        printf("\n");
    }
    printf("Media INFO23: %.2f ", med23);
    printf("\n\n");
    
    system("pause");
    printf("------------------------------------------------------\n");
    
    printf("\n");
    printf("INFO 24\n");
    for(i = 0; i < L; i++){
        printf("Aluno %d:\n", i + 1);
        printf("Nome: %s ", nome24[i]);
        printf("[Conceito: ");
        for(j = 0; j < C; j++){
            printf("%c ", conceito24[i * L + j][0]);
        }
        printf("Nota: %.2f ", notas24[i]);
        printf("Nascimento: %d/%d/%d]", dia24[i], mes24[i], ano24[i]);
        printf("\n");
    }
    printf("Media INFO24: %.2f ", med24);
    printf("\n\n");
 
    printf("[Media final: %.2f]", (med23 + med24) / 2);
}