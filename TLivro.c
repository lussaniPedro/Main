#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// struct Data
typedef struct{
    int dia;
    int mes;
    int ano;
} TData;

// struct Livro
typedef struct{
    char *titulo;
    char *autor;
    char *genero;
    TData publicacao;
} TLivro;

/* Declaração de funções */
void menu();
void op_menu(int opcao);
void listarLivros();
void exibeLivro(int i);
void excluirLivro();
void alteracao();
void alterarLivro(int op, int indice);
void incluirLivro();
TLivro cadastrarLivro();
void limparPonteiros();
int validar_data(int dia, int mes, int ano);
void validarAlocacao(void *ptr);

TLivro *_livros;
int _numLivros = 0;

int main(){
    int op;

    do{
        menu();

        scanf("%d", &op);
        fflush(stdin);

        system("cls");
        op_menu(op);
    } while(op != 0);

    limparPonteiros();
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

    printf("Escolha uma opcao: ");
}

void op_menu(int opcao){
    switch(opcao){
        case 1:
            incluirLivro();
            break;
        case 2:
            listarLivros();
            system("pause");
            break;
        case 3:
            alteracao();
            break;
        case 4:
            excluirLivro();
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
            system("pause");
    }
}

void incluirLivro(){
    if(_numLivros == 0){
        _livros = (TLivro*)malloc(1 * sizeof(TLivro));
    } else{
        _livros = (TLivro*)realloc(_livros, (_numLivros + 1) * sizeof(TLivro));
    }
    validarAlocacao(_livros);
    _livros[_numLivros++] = cadastrarLivro();

    system("Cls");
    printf("Livro cadastrado com sucesso!\n");
    system("pause");
}

// Cadastra um livro
TLivro cadastrarLivro(){
    char strAux[100];
    TLivro livro;

    printf("Digite o titulo do livro: ");
    gets(strAux);
    livro.titulo = (char*)malloc((strlen(strAux) + 1) * sizeof(char));
    validarAlocacao(livro.titulo);
    strcpy(livro.titulo, strAux);

    printf("Digite o genero do livro: ");
    gets(strAux);
    livro.genero = (char*)malloc((strlen(strAux) + 1) * sizeof(char));
    validarAlocacao(livro.genero);
    strcpy(livro.genero, strAux);

    printf("Digite o autor do livro: ");
    gets(strAux);
    livro.autor = (char*)malloc((strlen(strAux) + 1) * sizeof(char));
    validarAlocacao(livro.autor);
    strcpy(livro.autor, strAux);

    int data;
    do{
        printf("Digite o dia, mes e ano em que o livro foi publicado: ");
        scanf("%d%d%d", &livro.publicacao.dia, &livro.publicacao.mes, &livro.publicacao.ano);

        data = validar_data(livro.publicacao.dia, livro.publicacao.mes, livro.publicacao.ano);
        if (data == 0) {
            printf("Data invalida, digite novamente!\n\n");
        }
    } while (data == 0);
    
    printf("Livro cadastrado com sucesso!\n");

    return livro;
}

// Lista os livros
void listarLivros(){
    if(_numLivros == 0){
        printf("A lista de livros esta vazia.\n");
        system("pause");
        return;
    }

    printf("Lista de Livros (%d):\n\n", _numLivros);
    for(int i = 0; i < _numLivros; i++){
        exibeLivro(i);
    }
}

void exibeLivro(int i){
    printf("| Livro (%d):\n", i + 1);
    printf("| Titulo: %s\n", _livros[i].titulo);
    printf("| Genero: %s\n", _livros[i].genero);
    printf("| Autor: %s\n", _livros[i].autor);
    printf("| Data de publicacao %02d/%02d/%d\n\n", _livros[i].publicacao.dia, _livros[i].publicacao.mes, _livros[i].publicacao.ano);
}

// Altera um livro
void alteracao(){
    int indice, op;

    if(_numLivros == 0){
        printf("A lista de livros esta vazia.\n");
        system("pause");
        return;
    }

    listarLivros();
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
    exibeLivro(indice);

    printf("Digite:\n");
    printf("| 1. Para titulo\n");
    printf("| 2. Para genero\n");
    printf("| 3. Para autor\n");
    printf("| 4. Para data\n\n");
    printf("Qual informacao deseja alterar? ");
    scanf("%d", &op);
    fflush(stdin);

    alterarLivro(op, indice);

    system("cls");
    printf("Livro alterado com sucesso!\n");
    system("pause");
}

void alterarLivro(int op, int indice){
    char strAux[100];

    system("cls");
    switch(op){
    case 1:
        printf("Digite o titulo do livro: ");
        gets(strAux);
        _livros[indice].titulo = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        validarAlocacao(_livros[indice].titulo);
        strcpy(_livros[indice].titulo, strAux);
        break;
    case 2:
        printf("Digite o genero do livro: ");
        gets(strAux);
        _livros[indice].genero = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        validarAlocacao(_livros[indice].genero);
        strcpy(_livros[indice].genero, strAux);
        break;
    case 3:
        printf("Digite o autor do livro: ");
        gets(strAux);
        _livros[indice].autor = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        validarAlocacao(_livros[indice].autor);
        strcpy(_livros[indice].autor, strAux);
        break;
    case 4:
        do{
            printf("Digite o dia, mes e ano em que o livro foi publicado: ");
            scanf("%d%d%d", &_livros[indice].publicacao.dia, &_livros[indice].publicacao.mes, &_livros[indice].publicacao.ano);
        } while(validar_data(_livros[indice].publicacao.dia, _livros[indice].publicacao.mes, _livros[indice].publicacao.ano) == 0);
        break;
    default:
        system("cls");
        printf("Opcao invalida!\n");
        system("pause");
        return;
    }
}

// Exclui um livro
void excluirLivro(){
    listarLivros();

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
        _livros[i] = _livros[i + 1]; 
    }
    _numLivros--;

    system("cls");
    printf("Livro excluido com sucesso!\n");
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

    if(x == 0){
        printf("Data invalida!!! Digite novamente!\n\n");
    }

    return x;
}

void limparPonteiros(){
    for(int i = 0; i < _numLivros; i++){
        free(_livros[i].titulo);
        free(_livros[i].autor);
        free(_livros[i].genero);
    }
    free(_livros);
}

void validarAlocacao(void *ptr){
    if(ptr == NULL){
        printf("ERRO AO ALOCAR MEMORIA!\n");
        exit(1);
    }
}