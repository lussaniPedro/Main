#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char **materias;
    float **notas, *medias, *mediaBim, soma, soma2 = 0;
    char strAux[100];
    int i, j, mat, bim;

    system("cls");
    printf("Digite o numero de materias: ");
    scanf("%d", &mat);
    fflush(stdin);

    printf("Digite o numero de bimestres: ");
    scanf("%d", &bim);
    fflush(stdin);
    system("cls");

    if(mat > 0){
        materias = (char**)malloc(mat * sizeof(char *));
        notas = (float**)malloc(mat * sizeof(float *));
        medias = (float*)malloc(mat * sizeof(float));
        mediaBim = (float*)malloc(bim * sizeof(float));
    } else{
        printf("Erro ao alocar memoria!!!");
        exit(1);
    }
    
    if(bim > 0){
        for(i = 0; i < mat; i++){
            notas[i] = (float *)malloc(bim * sizeof(float));
        }
    } else{
        printf("Erro ao alocar memoria!!!");
        exit(1);
    }

    for(i = 0; i < mat; i++){
        printf("Digite o nome da %d materia: ", i + 1);
        gets(strAux);
        fflush(stdin);
        materias[i] = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(materias[i], strAux);
    }
    system("cls");

    for(i = 0; i < mat; i++){
        soma = 0;
        for(j = 0; j < bim; j++){
            do{
                printf("Digite a nota do %d bimestre de %s: ", j + 1, materias[i]);
                scanf("%f", &notas[i][j]);
                fflush(stdin);
                if(notas[i][j] < 0 || notas[i][j] > 10){
                    printf("Nota invalida, digite novamente!!!\n\n");
                }
            } while(notas[i][j] < 0 || notas[i][j] > 10);
            soma += notas[i][j];
            soma2 += notas[i][j];
        }
        medias[i] = soma / bim;
        system("cls");
    }

    for(j = 0; j < bim; j++){
        soma = 0;  
        for(i = 0; i < mat; i++){
            soma += notas[i][j];
        }
        mediaBim[j] = soma / mat;
    }

    system("cls");
    for(j = 0; j < bim; j++){
        printf("\t\t%d Bim", j + 1);
    }
    printf("\t\tMedia");
    printf("\n");

    for(i = 0; i < mat; i++){
        printf("%-16s", materias[i]);
        for(j = 0; j < bim; j++){
            printf("%.2f\t\t", notas[i][j]);
        }
        printf("%.2f", medias[i]);
        printf("\n");
    }

    printf("Media\t\t");
    for(i = 0; i < bim; i++){
        printf("%.2f\t\t", mediaBim[i]);
    }
    printf("%.2f\n\n", soma2 / (mat * bim));

    return 0;
}
