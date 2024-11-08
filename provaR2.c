#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L 4
#define C 4
#define C2 100
#define C3 1

int validar_data(int dia, int mes, int ano);
void imprimir_dados();
void coletar_nomes(char nomes[L][C2], const char* info);
void coletar_conceitos(char conceitos[L * C][C3], const char* info);
void coletar_notas(float notas[L], const char* info, float* media);
void coletar_datas(int dia[L], int mes[L], int ano[L], const char* info);

char nome23[L][C2], nome24[L][C2], conceito23[L * C][C3], conceito24[L * C][C3];
int dia23[L], mes23[L], ano23[L], dia24[L], mes24[L], ano24[L];
float notas23[L], notas24[L], med23 = 0, med24 = 0;

int main(){
    coletar_nomes(nome23, "info23");
    coletar_conceitos(conceito23, "info23");
    coletar_notas(notas23, "info23", &med23);
    coletar_datas(dia23, mes23, ano23, "info23");

    coletar_nomes(nome24, "info24");
    coletar_conceitos(conceito24, "info24");
    coletar_notas(notas24, "info24", &med24);
    coletar_datas(dia24, mes24, ano24, "info24");

    imprimir_dados();

    return 0;
}

void coletar_nomes(char nomes[L][C2], const char* info){
    for(int i = 0; i < L; i++){
        do{
            printf("Digite o nome do aluno (%d) de %s: ", i + 1, info);
            fgets(nomes[i], C2, stdin);
            if(nomes[i][0] == ' ' || nomes[i][0] == '\0'){
                printf("Nome Invalido!\n\n");
            }
        } while(nomes[i][0] == ' ' || nomes[i][0] == '\0');
        system("cls");
    }
}

void coletar_conceitos(char conceitos[L * C][C3], const char* info){
    for(int i = 0; i < L; i++){
        for(int j = 0; j < C; j++){
            do{
                printf("Digite o conceito [%d] do aluno (%d) de %s (A, B, C ou D): ", j + 1, i + 1, info);
                gets(conceitos[i * L + j]);
                fflush(stdin);
                if (conceitos[i * L + j][0] != 'A' && conceitos[i * L + j][0] != 'B' && conceitos[i * L + j][0] != 'C' && conceitos[i * L + j][0] != 'D') {
                    printf("Conceito invalido!\n\n");
                }
            } while (conceitos[i * L + j][0] != 'A' && conceitos[i * L + j][0] != 'B' && conceitos[i * L + j][0] != 'C' && conceitos[i * L + j][0] != 'D');
            system("cls");
        }
    }
}

void coletar_notas(float notas[L], const char* info, float* media) {
    for(int i = 0; i < L; i++){
        do{
            printf("Digite a nota do aluno (%d) de %s (0 a 10): ", i + 1, info);
            scanf("%f", &notas[i]);
            *media += notas[i];
            if (notas[i] < 0 || notas[i] > 10) {
                printf("Nota invalida!\n\n");
            }
        } while (notas[i] < 0 || notas[i] > 10);
        system("cls");
    }
    *media /= L;
}

void coletar_datas(int dia[L], int mes[L], int ano[L], const char* info){
    for(int i = 0; i < L; i++){
        int aux;
        do{
            printf("Digite o dia mes e ano em que nasceu o aluno (%d) de %s: ", i + 1, info);
            scanf("%d%d%d", &dia[i], &mes[i], &ano[i]);
            getchar();
            aux = validar_data(dia[i], mes[i], ano[i]);
            if(aux == 0){
                printf("Data invalida, digite novamente\n");
            }
            system("cls");
        } while(aux == 0);
    }
}

int validar_data(int dia, int mes, int ano){
    int x = 1;

    if(ano <= 0){
        x = 0;
    }

    if(mes <= 0 || mes > 12){
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
    } else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
        if(dia > 30){
            x = 0;
        }
    } else if(dia > 31 || dia <= 0){
        x = 0;
    }

    return x;
}

void imprimir_dados(){
    system("pause");
    system("cls");
    printf("INFO 23\n");
    
    for(int i = 0; i < L; i++){
        printf("Aluno %d:\n", i + 1);
        printf("Nome: %s ", nome23[i]);
        printf("[Conceito: ");
        for(int j = 0; j < C; j++){
            printf("%c ", conceito23[i * L + j][0]);
        }
        printf("Nota: %.2f ", notas23[i]);
        printf("Nascimento: %d/%d/%d]", dia23[i], mes23[i], ano23[i]);
        printf("\n");
    }
    printf("Media INFO23: %.2f\n\n", med23);
    
    system("pause");
    printf("------------------------------------------------------\n");
    
    printf("\nINFO 24\n");
    for(int i = 0; i < L; i++){
        printf("Aluno %d:\n", i + 1);
        printf("Nome: %s ", nome24[i]);
        printf("[Conceito: ");
        for(int j = 0; j < C; j++){
            printf("%c ", conceito24[i * L + j][0]);
        }
        printf("Nota: %.2f ", notas24[i]);
        printf("Nascimento: %d/%d/%d]", dia24[i], mes24[i], ano24[i]);
        printf("\n");
    }
    printf("Media INFO24: %.2f\n\n", med24);

    if(med23 > med24){
        printf("Info23 wins!\n");
    } else if(med24 > med23){
        printf("INFO24 WINS!!!\n");
    } else{
        printf("Empate!\n");
    }
    
    printf("[Media final: %.2f]\n", (med23 + med24) / 2);
}