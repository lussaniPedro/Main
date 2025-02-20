#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 30000

void interpretBrainfuck(const char* code); 

int main()
{
    char code[1024];

    printf("Digite o codigo Brainfuck: ");
    if (fgets(code, sizeof(code), stdin) == NULL) {
        fprintf(stderr, "Erro na leitura do codigo.\n");
        return 1;
    }

    interpretBrainfuck(code);

    return 0;
}

void interpretBrainfuck(const char* code) 
{
    unsigned char memory[MEMORY_SIZE] = {0};  
    unsigned char *ptr = memory;

    for (const char *pc = code; *pc != '\0'; pc++) 
    {  
        switch (*pc) 
        {
            case '>':
                ptr++; 
                if (ptr >= memory + MEMORY_SIZE) {
                    fprintf(stderr, "Erro: ponteiro excedeu o limite da memoria.\n");
                    return;
                }
                break;
            case '<':
                ptr--;  
                if (ptr < memory) {
                    fprintf(stderr, "Erro: ponteiro saiu da memoria.\n");
                    return;
                }
                break;
            case '+':
                (*ptr)++;  
                break;
            case '-':
                (*ptr)--;  
                break;
            case '.':
                putchar(*ptr); 
                fflush(stdout); 
                break;
            case ',':
                *ptr = getchar();  
                break;
            case '[':
                if (*ptr == 0) {
                    int open_brackets = 1;
                    while (open_brackets > 0) {
                        pc++;
                        if (*pc == '[') open_brackets++;
                        if (*pc == ']') open_brackets--;
                    }
                }
                break;
            case ']':
                if (*ptr != 0) {
                    int open_brackets = 1;
                    while (open_brackets > 0) {
                        pc--;
                        if (*pc == ']') open_brackets++;
                        if (*pc == '[') open_brackets--;
                    }
                }
                break;
            default:
                break;
        }
    }
}

