#include <stdio.h>
void bubble_sort(int arr[], int n);
int main(){
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    if(n <= 0){
        printf("O tamanho do vetor deve ser um número positivo.\n");
        return 1;
    }

    int arr[n];

    for(int i = 0; i < n; i++){
        printf("Digite a posicao (%d) do vetor: ", i);
        scanf("%d", &arr[i]);
    }

    bubble_sort(arr, n);

    printf("Vetor apos a ordenacao:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void bubble_sort(int arr[], int n){
    int i, j, temp;
    int troca;

    for(i = 0; i < n - 1; i++){
        troca = 0; 

        for(j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                troca = 1;  
            }
        }

        if(troca == 0){
            break;
        }
    }
}