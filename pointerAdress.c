#include <stdio.h>
#include <stdlib.h>

int main(){
    int *ptr, *auxPtr;
    system("cls");

    ptr = malloc(5 * sizeof(int));
    printf("\nEndereco mallocado: %p\n\n", (void*)ptr);

    auxPtr = ptr;
    printf("Endereco apontado apos malloc: %p\n\n", (void*)auxPtr);

    ptr = realloc(ptr, 10 * sizeof(int));
    printf("Endereco reallocado: %p\n\n", (void*)ptr);

    printf("Endereco apontado apos realloc: %p\n\n", (void*)auxPtr);

    free(ptr);

    return 0;
}