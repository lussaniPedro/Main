#include <stdio.h>
#include <stdlib.h>
#define N 100

void mostrar_cadastros();
void excluir_cadastro();
void menu();
int validar_data(int dia, int mes, int ano);

// Struct Data
typedef struct
{
    int dia;
    int mes;
    int ano;
} TData;

// Struct Banco
typedef struct
{
    char nome_cliente[N];
    double saldo;
    TData nascimento;
} TBanco;

void cadastrar_cliente(TBanco *cliente);
void depositar(TBanco *cliente);
void sacar(TBanco *cliente);

TBanco clientes[N];
int num_clientes = 0;

int main()
{
    menu();
    return 0;
}

// Exibe o menu
void menu()
{
    int opcao;

    do
    {
        system("cls");
        printf("| Menu:               |\n");
        printf("|                     |\n");
        printf("| 1. Cadastrar        |\n");
        printf("| 2. Ver Cadastro     |\n");
        printf("| 3. Depositar        |\n");
        printf("| 4. Sacar            |\n");
        printf("|                     |\n");
        printf("| 5. excluir cadastro |\n");
        printf("| 0. Sair             |\n\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            system("cls");
            cadastrar_cliente(&clientes[num_clientes]);
            num_clientes++;
            break;
        case 2:
            system("cls");
            if(num_clientes >= 1)
            {
                mostrar_cadastros();
            }
            else
            {
                printf("Nenhum cliente cadastrado!\n");
            }
            system("pause");
            break;
        case 3:
            system("cls");
            if(num_clientes > 0)
            {
                int cliente_index;
                mostrar_cadastros();
                printf("Escolha o cliente [%d-%d]: ", 1, num_clientes);
                scanf("%d", &cliente_index);
                if(cliente_index >= 1 && cliente_index <= num_clientes)
                {
                    depositar(&clientes[cliente_index - 1]);
                }
                else
                {
                    printf("Cliente invalido!\n");
                }
            }
            else
            {
                printf("Nenhum cliente cadastrado!\n");
            }
            system("pause");
            break;
        case 4:
            system("cls");
            if(num_clientes > 0)
            {
                int cliente_index;
                mostrar_cadastros();
                printf("Escolha o cliente [%d-%d]: ", 1, num_clientes);
                scanf("%d", &cliente_index);
                if(cliente_index >= 1 && cliente_index <= num_clientes)
                {
                    sacar(&clientes[cliente_index - 1]);
                }
                else
                {
                    printf("Cliente invalido!\n");
                }
                system("pause");
                break;
            }
            else
            {
                printf("Nenhum cliente cadastrado!\n");
            }
            system("pause");
            break;
        case 5:
            system("cls");
            if(num_clientes >= 1)
            {
                excluir_cadastro();
            }
            else
            {
                printf("Nenhum cliente cadastrado!\n");
            }
            system("pause");
            break;
        case 0:
            system("cls");
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

// Cadastra um cliente
void cadastrar_cliente(TBanco *cliente)
{
    int data_valida;

    printf("Digite seu nome: ");
    fgets(cliente->nome_cliente, N, stdin);

    do
    {
        printf("Digite sua Data de nascimento (DD/MM/AAAA): ");
        scanf("%d%d%d", &cliente->nascimento.dia, &cliente->nascimento.mes, &cliente->nascimento.ano);

        data_valida = validar_data(cliente->nascimento.dia, cliente->nascimento.mes, cliente->nascimento.ano);
        if(data_valida == 0)
        {
            printf("Data invalida, digite novamente!\n\n");
        }
    } while (data_valida == 0);

    printf("Digite seu saldo inicial: ");
    scanf("%lf", &cliente->saldo);

    printf("\nCadastro concluido\n");
    system("pause");
}

// Exclui um cadastro
void excluir_cadastro()
{
    mostrar_cadastros();
    if(num_clientes == 0)
    {
        return;
    }

    int indice;
    printf("Digite o numero de cadastro a ser excluido [%d-%d]: ", 1, num_clientes);
    scanf("%d", &indice);
    getchar();

    if(indice < 1 || indice > num_clientes)
    {
        printf("Numero invalido!\n");
        system("pause");
        return;
    }

    for (int i = indice - 1; i < num_clientes - 1; i++)
    {
        clientes[i] = clientes[i + 1];
    }

    num_clientes--;
    printf("\nCadastro excluido com sucesso!\n");
}

// Exibe os cadastros
void mostrar_cadastros()
{
    for (int i = 0; i < num_clientes; i++)
    {
        printf("| Cliente (%d):\n", i + 1);
        printf("| Nome: %s", clientes[i].nome_cliente);
        printf("| Data de nascimento: %d/%d/%d\n", clientes[i].nascimento.dia, clientes[i].nascimento.mes, clientes[i].nascimento.ano);
        printf("| Saldo: R$%.2f\n\n", clientes[i].saldo);
    }
}

// Deposita dinheiro
void depositar(TBanco *cliente)
{
    double valor;
    system("cls");
    printf("Saldo: R$%.2f\n", cliente->saldo);
    printf("Digite o valor a ser depositado: ");
    scanf("%lf", &valor);
    if(valor > 0)
    {
        cliente->saldo += valor;
        printf("\nDeposito de R$%.2f realizado com sucesso!\n Saldo atual: R$%.2f\n\n", valor, cliente->saldo);
    }
    else
    {
        printf("\nValor de deposito invalido!\n");
    }
}

// Saca dinheiro
void sacar(TBanco *cliente)
{
    double valor;

    system("cls");
    printf("Saldo: R$%.2f\n", cliente->saldo);
    printf("Digite o valor a ser sacado: ");
    scanf("%lf", &valor);
    if(valor > 0 && valor <= cliente->saldo)
    {
        cliente->saldo -= valor;
        printf("\nSaque de R$%.2f realizado com sucesso!\n Saldo atual: R$%.2f\n\n", valor, cliente->saldo);
    }
    else
    {
        printf("\nValor de saque invalido ou saldo insuficiente!\n");
    }
}

// Valida a data
int validar_data(int dia, int mes, int ano)
{
    int x = 1;

    if(ano <= 0)
    {
        x = 0;
    }

    if((mes <= 0) || (mes > 12))
    {
        x = 0;
    }

    if(mes == 2)
    {
        if(ano % 4 == 0)
        {
            if(dia > 29)
            {
                x = 0;
            }
        }
        else if(dia > 28)
        {
            x = 0;
        }
    }
    else if((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11))
    {
        if(dia > 30)
        {
            x = 0;
        }
    }
    else if((dia > 31) || (dia <= 0))
    {
        x = 0;
    }

    return x;
}