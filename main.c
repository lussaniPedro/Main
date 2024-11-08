#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *NMateria;
    float **nota;
    float med;
} TDisciplinas;

int main(){
    TDisciplinas *materias;
    char strAux[100];
    int i, j, mat, bim;
    float soma;

    system("cls");

    printf("Digite o numero de materias: ");
    scanf("%d", &mat);
    fflush(stdin);

    if(mat > 0){
        materias = (TDisciplinas*)malloc(mat * sizeof(TDisciplinas));
    } else{
        printf("Erro ao alocar memoria!!!");
        exit(1);
    }

    printf("Digite o numero de bimestres: ");
    scanf("%d", &bim);
    fflush(stdin);
    system("cls");

    if(bim > 0){
        for(i = 0; i < mat; i++){
            materias[i].nota = (float**)malloc(bim * sizeof(float*));
            for (j = 0; j < bim; j++) {
                materias[i].nota[j] = (float*)malloc(sizeof(float));
            }
        }
    } else{
        printf("Erro ao alocar memoria!!!");
        exit(1);
    }

    for(i = 0; i < mat; i++){
        printf("Digite o nome da %d materia: ", i+1);
        gets(strAux);
        fflush(stdin);
        materias[i].NMateria = (char*)malloc(strlen(strAux) + 1 * sizeof(char));
        strcpy(materias[i].NMateria, strAux);
    }
    system("cls");

    for(i = 0; i < mat; i++){
        soma = 0;
        for(j = 0; j < bim; j++){
            do{
                printf("Digite a nota do %d bimestre de %s: ", j+1, materias[i].NMateria);
                scanf("%f", &materias[i].nota[j][0]);
                fflush(stdin);
                if(materias[i].nota[j][0] < 0 || materias[i].nota[j][0] > 10){
                    printf("Nota invalida, digite novamente!!!\n\n");
                }
            } while(materias[i].nota[j][0] < 0 || materias[i].nota[j][0] > 10);
            soma += materias[i].nota[j][0];
        }
        materias[i].med = soma / bim;
        system("cls");
    }

    system("cls");
    for(j = 0; j < bim; j++) {
        printf("\t%d Bimestre", j + 1);
    }
    printf("\tMedia");
    printf("\n");

    for(i = 0; i < mat; i++) {
        printf("%-15s", materias[i].NMateria);
        for(j = 0; j < bim; j++) {
            printf("%.2f\t\t", materias[i].nota[j][0]);
        }
        printf("%.2f", materias[i].med);
        printf("\n");
    }

    return 0;
}