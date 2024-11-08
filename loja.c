#include <stdio.h>
#include <stdlib.h>

/* Declaração de funções */
void menu(); // Exibe o menu de opções para o usuario
void op_menu(int op); // Executa a escolha do usuario
void adcionar_produto(); // Adciona um produto ao estoque
void listar_produtos(); // Exibe os produtos em estoque
void alterar_produto(); // Altera os dados de um produto adcionado
void excluir_produto(); // Tira um produto do estoque

/* Declaração de estruturas */
typedef struct{
    char *nome;
    int quantidade;
    int code;
    float preço;
} TLoja; // Struct loja

TLoja *_estoque;
int _numProdutos = 0;

int main(){
    int op;
    
    do{

        system("cls");
        menu();
        printf("Digite a opção desejada: ");
        scanf("%d", &op);
        op_menu(op);
    } while(op != 0);
    return 0;
}

void menu(){
    system("cls");
    printf("| Menu:                |\n");
    printf("|                      |\n");
    printf("| 1. Adcionar produto  |\n");
    printf("| 2. Listar produtos   |\n");
    printf("| 3. Alterar produto   |\n");
    printf("|                      |\n");
    printf("| 4. Excluir produto   |\n");
    printf("| 0. Sair              |\n\n");
}

void op_menu(int op){
    switch(op){
        case 1:
            system("cls");
            adcionar_produto();
            break;
        case 2:
            system("cls");
            listar_produtos();
            break;
        case 3:
            system("cls");
            alterar_produto();
            break;
        case 4:
            system("cls");
            excluir_produto();
            break;
        case 0:
            system("cls");
            printf("Saindo...");
            break;
        default:
            printf("Opcao inexistente!\n\n");
            system("pause");
            break;
    }
}

void adcionar_produto(){
    char strAux[100];

    _estoque = realloc(_estoque, (_numProdutos+1)*sizeof(TLoja));

    printf("Digite o nome do produto: ");
    gets(strAux);
    _estoque[_numProdutos].nome = (char*)malloc(strlen(strAux) + 1 * sizeof(char));
    strcpy(_estoque[_numProdutos].nome, strAux);

    printf("Digite a quantidade de produtos em estoque: ");
    scanf("%d", &_estoque[_numProdutos].quantidade);

    printf("Digite o preço do produto: ");
    scanf("%f", &_estoque[_numProdutos].preço);

    printf("Digite o codigo do produto: ");
    scanf("%d", &_estoque[_numProdutos].code);
    _numProdutos++;
}

void listar_produtos(){
    printf("Produtos (%d):\n\n", _numProdutos+1);
    for(int i = 0; i < _numProdutos; i++){
        printf("| Produto [%d]: %s\n", i+1, _estoque[i].nome);
        printf("| Codigo do produto: %d\n", _estoque[i].code);
        printf("| Valor: %.2f\n", _estoque[i].preço);
        printf("| Produtos em estoque: %d\n\n", _estoque[i].quantidade);
    }
}

void alterar_produto(){
    listar_produtos();
}

void excluir_produto(){
    listar_produtos();
    
    if(_numProdutos){
        return;
    }

    int op;
    printf("Qual produto deseja exluir? [%d-%d]: ", 1, _numProdutos+1);
    scanf("%d", &op);

    for(int i = op - 1; i < _numProdutos; i++){
        _estoque[i] = _estoque[i + 1];
    }
    _numProdutos--;

    system("cls");
    printf("Produto excluido com sucesso!\n\n");
    system("pause");
}