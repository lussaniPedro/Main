#include <stdio.h>
#include <stdlib.h>
#define N 100

int validar_data(int dia, int mes, int ano);

// struct Data
typedef struct{
    int dia;
    int mes;
    int ano;
} TData;

// struct Livro
typedef struct{
    char titulo[N];
    char autor[N];
    char genero[N];
    TData publicacao;
} TLivro;

/* Declaração de funções */
void menu();
void listar_livros();
void excluir_livro();
void alterar_livro();
void option(int opcao);
void cadastrar_livro(TLivro *cadastro_livro);

TLivro _cadastro_livro[N];
int _numLivros = 0;

int main(){
    int op;
    do{
        menu();

        printf("Escolha uma opcao: ");
        scanf("%d", &op);
        fflush(stdin);

        option(op);
    } while(op != 0);
    return 0;
}

// Menu
void menu(){
    system("cls");
    printf("| Menu:              |\n");
    printf("|                    |\n");
    printf("| 1. Adicionar livro |\n");
    printf("| 2. Listar livros   |\n");
    printf("| 3. Alterar livro   |\n");
    printf("|                    |\n");
    printf("| 4. Excluir livro   |\n");
    printf("| 0. Sair            |\n\n");
}

void option(int opcao){
    switch(opcao){
        case 1:
            system("cls");
            cadastrar_livro(&_cadastro_livro[_numLivros]);
            _numLivros++;
            break;
        case 2:
            system("cls");
            listar_livros();
            system("pause");
            break;
        case 3:
            system("cls");
            alterar_livro();
            break;
        case 4:
            system("cls");
            excluir_livro();
            break;
        case 0:
            system("cls");
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
    }
}

// Cadastra um livro
void cadastrar_livro(TLivro *cadastro_livro){
    
    printf("Digite o titulo do livro: ");
    fgets(cadastro_livro->titulo, N, stdin);

    printf("Digite o genero do livro: ");
    fgets(cadastro_livro->genero, N, stdin);

    printf("Digite o autor do livro: ");
    fgets(cadastro_livro->autor, N, stdin);

    int data;
    do{
        printf("Digite o dia, mes e ano em que o livro foi publicado: ");
        scanf("%d%d%d", &cadastro_livro->publicacao.dia, &cadastro_livro->publicacao.mes, &cadastro_livro->publicacao.ano);

        data = validar_data(cadastro_livro->publicacao.dia, cadastro_livro->publicacao.mes, cadastro_livro->publicacao.ano);
        if (data == 0) {
            printf("Data invalida, digite novamente!\n\n");
        }
    } while (data == 0);
    
    printf("Livro cadastrado com sucesso!\n");
}

// Lista os livros
void listar_livros(){
    if(_numLivros == 0){
        printf("A lista de livros esta vazia.\n");
        return;
    }

    printf("Lista de Livros (%d):\n\n", _numLivros);
    for(int i = 0; i < _numLivros; i++){
        printf("| Livro (%d):\n", i + 1);
        printf("| Titulo do livro: %s", _cadastro_livro[i].titulo);
        printf("| Genero do livro: %s", _cadastro_livro[i].genero);
        printf("| Autor do livro: %s", _cadastro_livro[i].autor);
        printf("| Data de publicacao %d/%d/%d\n\n", _cadastro_livro[i].publicacao.dia, _cadastro_livro[i].publicacao.mes, _cadastro_livro[i].publicacao.ano);
    }
}

// Altera um livro
void alterar_livro(){
    listar_livros();

    if(_numLivros == 0){
        system("pause");
        return;
    } 

    int indice, option, data;
    printf("Digite o numero do livro a ser alterado [%d-%d]: ", 1, _numLivros);
    scanf("%d", &indice);
    fflush(stdin); 

    system("cls");
    if(indice < 1 || indice > _numLivros){
        printf("Numero invalido!\n");
        system("pause");
        return;
    }

    indice--;
    printf("| Livro (%d):\n", indice);
    printf("| Titulo do livro: %s", _cadastro_livro[indice].titulo);
    printf("| Genero do livro: %s", _cadastro_livro[indice].genero);
    printf("| Autor do livro: %s", _cadastro_livro[indice].autor);
    printf("| Data de publicacao %d/%d/%d\n\n", _cadastro_livro[indice].publicacao.dia, _cadastro_livro[indice].publicacao.mes, _cadastro_livro[indice].publicacao.ano);

    printf("Digite:\n");
    printf("| 1. Para titulo\n");
    printf("| 2. Para genero\n");
    printf("| 3. Para autor\n");
    printf("| 4. Para data\n\n");
    printf("Qual informacao deseja alterar? ");
    scanf("%d", &option);
    fflush(stdin); 

    system("cls");
    switch(option){
    case 1:
        printf("Digite o titulo do livro: ");
        fgets(_cadastro_livro[indice].titulo, N, stdin);
        break;
    case 2:
        printf("Digite o genero do livro: ");
        fgets(_cadastro_livro[indice].genero, N, stdin);
        break;
    case 3:
        printf("Digite o autor do livro: ");
        fgets(_cadastro_livro[indice].autor, N, stdin);
        break;
    case 4:
        do{
            printf("Digite o dia, mes e ano em que o livro foi publicado: ");
            scanf("%d%d%d", &_cadastro_livro[indice].publicacao.dia, &_cadastro_livro[indice].publicacao.mes, &_cadastro_livro[indice].publicacao.ano);

            data = validar_data(_cadastro_livro[indice].publicacao.dia, _cadastro_livro[indice].publicacao.mes, _cadastro_livro[indice].publicacao.ano);
            if(data == 0){
                printf("Data invalida, digite novamente!\n\n");
            }
        } while(data == 0);
        break;
    default:
        printf("Opcao invalida!\n");
        system("cls");
        return;
    }
    system("cls");

    printf("\nLivro alterado com sucesso!\n");
    system("pause");
}

// Exclui um livro
void excluir_livro(){
    listar_livros();

    if(_numLivros == 0){
        return;
    } 

    int indice;
    printf("Digite o numero do livro a ser excluido [%d-%d]: ", 1, _numLivros);
    scanf("%d", &indice);
    getchar(); 

    if(indice < 1 || indice > _numLivros){
        printf("Numero invalido!\n");
        system("pause");
        return;
    }

    for(int i = indice - 1; i < _numLivros - 1; i++){
        _cadastro_livro[i] = _cadastro_livro[i + 1]; 
    }
    _numLivros--;

    printf("\nLivro excluido com sucesso!\n");
    system("pause");
}

// Valida data
int validar_data(int dia, int mes, int ano){
    int x = 1;

    if(ano <= 0){
        x = 0;
    }

    if((mes <= 0) || (mes > 12)){
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
    } else if((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11)){
        if(dia > 30){
            x = 0;
        }
    } else if((dia > 31) || (dia <= 0)){
        x = 0;
    }

    return x;
}