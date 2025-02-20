#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>

bool iswovel = true;

char gerarLetraAleatoria()
{
    char vogais[] = "aeiou";
    char consoantes[] = "bcdfghjklmnpqrstvwxyz";

    if (iswovel)
    {
        iswovel = false;
        return consoantes[rand() % 21];
    }
    else
    {
        iswovel = true;
        return vogais[rand() % 5];
    }
}

void gerarPalavraAleatoria(char *palavra, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        palavra[i] = gerarLetraAleatoria();
    }
    palavra[tamanho] = '\0';
}

int main()
{
    srand((unsigned)time(NULL));

    int numPalavras = 200;
    int tamanhoPalavra;

    system("cls");
    printf("Motivos para odiar java:\n\n");
    sleep(2);
    for (int i = 0; i < numPalavras; i++)
    {
        tamanhoPalavra = 6 + rand() % 12;
        char palavra[tamanhoPalavra + 1];
        gerarPalavraAleatoria(palavra, tamanhoPalavra);
        for(int j = 0, tam2 = strlen(palavra); j < tam2; j++){
            printf("%c", palavra[j]);
            Sleep(05);
        }
        printf(" ");
    }
    
    system("cls");
    printf("Motivos para odiar java:\n\n");
    printf("Todos.\n");
    return 0;
}