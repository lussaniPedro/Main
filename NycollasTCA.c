#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    int hora;
    int minuto;
} Horario;

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    char *nome;
} Categoria;

typedef struct
{
    char *logradouro;
    char *num;
    char *bairro;
    char *cidade;
    char *estado;
} Endereco;

typedef struct
{
    char *nome;
    char *apelido;
    char *email;
    char telefone[11];
    Data nascimento;
} Amigo;

typedef struct
{
    Data data;
    Horario horario;
    Amigo **amigos;
    Categoria categoria;
    char *descricao;
} Encontro;

Amigo *conjuntoAmigos = NULL;
int num_Amigos = 0;

void menu_opcoes();
void opcao_menu(int op);
void subMenu();
void subMenu_opcao1();
void incluirAmigo();
void alterarAmigo();
void excluirAmigo();
void exibirAmigos();
bool validarData(int d, int m, int a);

int main()
{
    int op = 1;
    while(op != 6)
    {
        menu_opcoes();
        __fpurge(stdin);  
        scanf("%d", &op);
        __fpurge(stdin);  
        system("clear");
        opcao_menu(op);
    }

    return 0;
}

void menu_opcoes()
{
    printf("/Menu principal/\n");
    printf("-------------------------\n");
    printf("(1) - Manter Amigo\n");
    printf("(2) - Manter Local\n");
    printf("(3) - Manter Categoria\n");
    printf("(4) - Manter Encontro\n");
    printf("(5) - Relatórios\n");
    printf("(6) - Sair\n");
    printf("-------------------------\n");
    
    printf("Digite a opção:\n");
}

void opcao_menu(int op)
{
    switch (op)
    {
    case 1:
        subMenu_opcao1();
        break;
    case 2:
        printf("Opção 2 ainda não implementada\n");
        break;
    case 3:
        printf("Opção 3 ainda não implementada\n");
        break;
    case 4:
        printf("Opção 4 ainda não implementada\n");
        break;
    case 5:
        printf("Opção 5 ainda não implementada\n");
        break;
    case 6:
        printf("Saindo...\n");
        break;
    default:
        printf("Opção inválida!\n");
        break;
    }
}

void subMenu_opcao1()
{
    int opSubMenu;
    subMenu();
    scanf("%d", &opSubMenu);
    printf("\n");

    switch (opSubMenu)
    {
    case 1:
        incluirAmigo();
        break;
    case 2:
        printf("Alterar amigo - opção ainda não implementada\n");
        break;
    case 3:
        excluirAmigo();
        break;
    default:
        printf("Opção inválida!\n");
        break;
    }
}

void incluirAmigo()
{
    char strAux[200];
    
    num_Amigos++;                                                               // Adiciona um amigo
    conjuntoAmigos = realloc(conjuntoAmigos, num_Amigos * sizeof(Amigo));       // Realoca memória para o novo amigo
    
    printf("Nome do amigo:\n");                                                 
    __fpurge(stdin);
    gets(strAux);  
    __fpurge(stdin);
    conjuntoAmigos[num_Amigos - 1].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(conjuntoAmigos[num_Amigos - 1].nome, strAux);
    printf("\n");
    
    printf("Apelido do amigo:\n");
    __fpurge(stdin);
    gets(strAux);
    __fpurge(stdin);
    conjuntoAmigos[num_Amigos - 1].apelido = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(conjuntoAmigos[num_Amigos - 1].apelido, strAux);
    printf("\n");
    
    printf("Email do amigo:\n");
    __fpurge(stdin);
    gets(strAux);
    __fpurge(stdin);
    conjuntoAmigos[num_Amigos - 1].email = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(conjuntoAmigos[num_Amigos - 1].email, strAux);
    printf("\n");
    
    printf("Telefone:\n");
    __fpurge(stdin);
    gets(conjuntoAmigos[num_Amigos - 1].telefone);
    __fpurge(stdin);
    while(strlen(conjuntoAmigos[num_Amigos - 1].telefone) < 11)
    {
        printf("Número inválido!!!Digite novamente\n");
        __fpurge(stdin);
        gets(conjuntoAmigos[num_Amigos - 1].telefone);
        __fpurge(stdin);
    }
    
    printf("Digite dia, mês e ano de nascimento do amigo:\n");
    scanf("%d %d %d", &conjuntoAmigos[num_Amigos - 1].nascimento.dia, 
    &conjuntoAmigos[num_Amigos - 1].nascimento.mes, &conjuntoAmigos[num_Amigos - 1].nascimento.ano);
    
    while(validarData(conjuntoAmigos[num_Amigos - 1].nascimento.dia,conjuntoAmigos[num_Amigos - 1].nascimento.mes,
    conjuntoAmigos[num_Amigos - 1].nascimento.ano) == false)
    {
        printf("Data inválida!!!Digite novamente:\n");
        scanf("%d %d %d", &conjuntoAmigos[num_Amigos - 1].nascimento.dia, 
        &conjuntoAmigos[num_Amigos - 1].nascimento.mes, &conjuntoAmigos[num_Amigos - 1].nascimento.ano);
    }
    
    exibirAmigos();
}


void excluirAmigo()
{
    if(num_Amigos == 0)
    {
        printf("Não há amigos para excluir!!!\n");
        return 0;
    }
    int amigo;
    
    printf("Qual o número do amigo que você deseja excluir?\n");
    scanf("%d", &amigo);
    system("clear");
    
    
    while(amigo < 1 || amigo > num_Amigos) {
        printf("Não existe amigo com número correspondente!!!\n");
        scanf("%d", &amigo);
    }

    amigo--;  

    free(conjuntoAmigos[amigo].nome);                                           
    free(conjuntoAmigos[amigo].apelido);
    free(conjuntoAmigos[amigo].email);

    
    for (int i = amigo; i < num_Amigos - 1; i++)                                
    {
        conjuntoAmigos[i] = conjuntoAmigos[i + 1];
    }

    
    num_Amigos--;                                                               //-1 amigo

    
    conjuntoAmigos = realloc(conjuntoAmigos, num_Amigos * sizeof(Amigo));       //realoca a mémoria após a remoção do amigo

    
    exibirAmigos();
}

bool validarData(int d, int m, int a) 
{
    bool valido = false;  
    
    if(d < 1 || d > 31)
    {
        valido = false;
    } else if(m < 1 || m > 12)
    {
        valido = false;
    } else if(a < 0)
    {
        valido = false;
    } else if((m == 2) && (d > 29))
    {
        valido = false;
    } else if((m == 4 || m == 6 || m == 9 || m == 11) && (d > 30))
    {
        valido = false;
    } else {
        valido = true;
    }
    
    if(m == 2 && d == 29)
    {
        if(((a % 4 == 0) && (a % 100 != 0)) || (a % 400 == 0))
        {
            valido = true;
        }
        else
        {
            valido = false;
        }
    }

    return valido;
}

void subMenu()
{
    printf("(1) - Incluir\n");
    printf("(2) - Alterar\n");
    printf("(3) - Excluir \n");
    printf("Digite a opção:\n");
}

void exibirAmigos()
{
    if (num_Amigos == 0) {
        printf("Nenhum amigo registrado.\n");
        return;
    }

    printf("Lista de Amigos:\n");
    for (int i = 0; i < num_Amigos; i++) {
        printf("Amigo %d:\n", i + 1);
        printf("Nome: %s\n", conjuntoAmigos[i].nome);
        printf("Apelido: %s\n", conjuntoAmigos[i].apelido);
        printf("Email: %s\n", conjuntoAmigos[i].email);
        printf("Telefone: %s\n", conjuntoAmigos[i].telefone);
        printf("Data de Nascimento: %02d/%02d/%d\n\n", 
               conjuntoAmigos[i].nascimento.dia,
               conjuntoAmigos[i].nascimento.mes,
               conjuntoAmigos[i].nascimento.ano);
    }
}