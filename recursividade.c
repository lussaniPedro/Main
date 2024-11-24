#include <stdio.h>
#include <stdlib.h>

/* Declaração de funções */
void pedirVetor(int *vet, int n, int i);
void menu(int *vet, int n);
void somaVetor(int *vet, int n, int i, int soma);
void OpcaoBuscar(int *vet, int n);
void buscarElemento(int *vet, int n, int i, int op);

int main(){
    int *vet, n;

    system("cls");
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    vet = (int*)malloc(n * sizeof(int));

    system("cls");
    pedirVetor(vet, n, 0);

    menu(vet, n);
}

void pedirVetor(int *vet, int n, int i){
    if(i < n){
        printf("Digite o valor: ");
        scanf("%d", &vet[i++]);
        pedirVetor(vet, n, i);
    }
    return;
}

void menu(int *vet, int n){
    int op;
    do{
        system("cls");
        printf("- (1) Somar\n");
        printf("- (2) Buscar\n");
        printf("- (3) Sair\n\n");
        printf("Digite a opcao: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                somaVetor(vet, n, 0, 0);
                break;
            case 2:
                OpcaoBuscar(vet, n);
                break;
            case 3:
                system("cls");
                printf("Saindo...");
                break;
            default:
                printf("Erro! Opcao invalida!\n");
                break;
        }
    } while(op != 3);
}

void somaVetor(int *vet, int n, int i, int soma){
    system("cls");
    if(i < n){
        soma += vet[i++];
        somaVetor(vet, n, i, soma);
    } else{
        printf("Soma: %d\n", soma);
        system("pause");
        return;
    }
}

void OpcaoBuscar(int *vet, int n){
    int op;

    system("cls");
    printf("Digite o numero a ser procurado: ");
    scanf("%d", &op);

    buscarElemento(vet, n, 0, op);
}

void buscarElemento(int *vet, int n, int i, int op){
    system("cls");
    if(i < n){
        if(vet[i] == op){
            printf("Numero encontrado na posicao [%d]\n", i);
            system("pause");
        } else{
            i++;
            buscarElemento(vet, n, i, op);
        }
    }
    return;
}