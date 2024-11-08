#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *name;
    int num;
    char *email;
    char *note;
    char opSn;
} TContato;

/* Declração de funções */
void menu();
void cadastrar_contato();
void op_menu(int option);
void listar_contatos();

TContato *_contato;
int _numContatos = 0;

int main(){
    int op;
    do{
        system("cls");
        menu();

        printf("Escolha uma opcao: ");
        scanf("%d", &op);
        fflush(stdin);

        op_menu(op);
    } while(op != 0);
    return 0;
}

void menu(){
    printf("| Menu:                |\n");
    printf("|                      |\n");
    printf("| 1. Cadastrar contato |\n");
    printf("| 2. Listar contatos   |\n");
    printf("| 3. Alterar contato   |\n");
    printf("|                      |\n");
    printf("| 4. Excluir contato   |\n");
    printf("| 0. Sair              |\n");
}

void op_menu(int option){
    switch(option){
        case 1:
            if(_numContatos == 0){
                _contato = (TContato *)malloc(1 * sizeof(TContato));
            }
            else{
                _contato = (TContato *)realloc(_contato, (_numContatos + 1) * sizeof(TContato));
            }
            system("cls");
            cadastrar_contato();
            break;
        case 2:
            system("cls");
            listar_contatos();
            system("pause");
            break;
        default:
            break;
    }
}

void cadastrar_contato(){
    char strAux[100];

    printf("Digite o nome do contato: ");
    gets(strAux);
    fflush(stdin);
    _contato[_numContatos].name = (char*)malloc(strlen(strAux) + 1 * sizeof(char));
    strcpy(_contato[_numContatos].name, strAux);

    printf("Digite o numero de telefone do contato: ");
    scanf("%d", &_contato[_numContatos].num);
    fflush(stdin);

    printf("Digite o email do contato: ");
    gets(strAux);
    fflush(stdin);
    _contato[_numContatos].email = (char*)malloc(strlen(strAux) + 1 * sizeof(char));
    strcpy(_contato[_numContatos].email, strAux);

    printf("Deseja adcionar uma anotacao no contato? Digite (S) para sim e qualquer outra tecla para nao: ");
    gets(&_contato[_numContatos].opSn);
    fflush(stdin);
    if(_contato[_numContatos].opSn == 'S' || _contato[_numContatos].opSn == 's'){
        printf("Digite a anotacao: ");
        gets(strAux);
        fflush(stdin);
        _contato[_numContatos].note = (char*)malloc(strlen(strAux) + 1 * sizeof(char));
        strcpy(_contato[_numContatos].note, strAux);
    }

    _numContatos++;
}

void listar_contatos(){
    printf("Contatos [%d]:\n\n", _numContatos);
    
    for(int i = 0; i < _numContatos; i++){
        printf("| Nome: %s\n", _contato[i].name);
        printf("| Numero: %d\n", _contato[i].num);
        printf("| Email: %s\n", _contato[i].email);
        if(_contato[i].opSn == 'S' || _contato[i].opSn == 's'){
            printf("| Nota: %s\n", _contato[i].note);
        }
        printf("\n");
    }
}

void excluir_contato(){
    
}