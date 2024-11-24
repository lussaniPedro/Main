#include <stdio.h>
#include <ctype.h>

int pedirDados();
void imprimirResultados(int vitorias);

int main() {
    int vitorias;

    vitorias = pedirDados();
    imprimirResultados(vitorias);

    return 0;
}

int pedirDados(){
    int vitorias = 0;
    char res;

    for (int i = 0; i < 6; i++) {
        do{
            printf("Digite o resultado do %d jogo (V para vitoria e P para derrota): ", i + 1);
            scanf("%c", &res);
            fflush(stdin);
            res = tolower(res);

            if(res != 'v' && res != 'p'){
                printf("Opcao invalida! Digite novamente!!!\n\n");
            }
        } while(res != 'v' && res != 'p');

        if (res == 'v') {
            vitorias++;
        }
    }

    return vitorias;
}

void imprimirResultados(int vitorias){
    printf("\nResultado: ");
    if (vitorias >= 5) {
        printf("1\n");
    } else if (vitorias >= 3) {
        printf("2\n");
    } else if (vitorias >= 1) {
        printf("3\n");
    } else {
        printf("-1\n");
    }
}