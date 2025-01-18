#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>

typedef struct
{
    int hora;
    int minuto;
} THora;

typedef struct
{
    int dia;
    int mes;
    int ano;
} TData;

typedef struct
{
    char *logradouro;
    int num;
    char *bairro;
    char *cidade;
    char *estado;
} TEndereco;

typedef struct
{
    char *nome;
    TData data_nasc;
    char *apelido;
    char *email;
    char *telefone;
    int id;
} TAmigo;

typedef struct
{
    char *nome_lugar;
    TEndereco endereco;
    int id;
} TLocal;

typedef struct
{
    char *categoria;
    int id;
    int num_encontro_categoria;
} TCategoria;

typedef struct
{
    TData data;
    THora horario;
    TAmigo *amigos;
    int num_amigos_encontro;
    TLocal local;
    TCategoria *categoria;
    int num_categoria_encontro;
    char *descricao;
} TEncontro;

TAmigo *amigos;
TLocal *locais;
TCategoria *categorias;
TEncontro *Encontros;

int num_amigos = 0;
int num_local = 0;
int num_categoria = 0;
int num_encontro = 0;

void menu();
int opcao_menu(int res);
void menu_amigo();
int opcao_menu_amigo();
void menu_alterar_amigo(int i);
void opcao_alterar_Amigo();
void menu_local();
void menu_alterar_local();
void menu_categoria();
void menu_encontro();
void menu_relatorio();
int opcao_menu_relatorio();
int opcao_excluir_amigo();
TAmigo criar_amigo();
void incluir_amigo();
int valida_data(int dia, int mes, int ano);
int valida_email(char *email);
int valida_telefone(char *telefone);
void listar_amigos();
void listar_amigo(TAmigo amig, int i);
void listar_local(TLocal loca);
void listar_locais();
void excluir_amigo();
void alterar_amigo(int i, int op);
int opcao_local();
void incluir_local();
TLocal criar_local();
void opcao_menu_alterar_local(int i, int op);
void pausar();
void opcao_alterar_local();
void excluir_local();
int opcao_excluir_local();
int opcao_menu_categoria();
void incluir_categoria();
TCategoria criar_categoria();
void alterar_categoria();
void listar_categorias();
void listar_categoria(TCategoria categ, int i);
void excluir_categoria();
int opcao_excluir_categoria();
void salvar_arquivo_amigo();
void carregar_arquivo_amigo();
void salvar_arquivo_local();
void carregar_arquivo_local();
void salvar_arquivo_categoria();
void carregar_arquivo_categoria();
void relatorio_amigo();
void relatorio_local();
void relatorio_categoria();
void relatorio_encontro();
void relatorio_por_categoria();
int opcao_relatorio();
void salvar_arquivos();
void carregar_arquivos();
int opcao_menu_encontro();
void incluir_encontro();
TEncontro criar_encontro();
int valida_horario(int hora, int minuto);
void listar_amigos_nao_inclusos(TEncontro encontro);
int valida_sim_ou_nao(char op);
void mensagem_de_erro(int i);
void listar_categorias_nao_inclusas(TEncontro encontro);

int main()
{
    int res;
    carregar_arquivos();
    pausar();
    do
    {
        menu();
        scanf("%d", &res);
        fflush(stdin);
        opcao_menu(res);
    } while (res != 6);
    salvar_arquivos();
}

void menu()
{
    system("cls");
    printf("Menu Principal\n\n");
    printf("1. Manter amigo\n");
    printf("2. Manter local\n");
    printf("3. Manter categoria\n");
    printf("4. Manter encontro\n");
    printf("5. Relatorios\n");
    printf("6. Sair\n\n");
    printf("Digite a opcao:  ");
}

int opcao_menu(int res)
{
    if ((res < 1) || (res > 6))
    {
        printf("Valor invalido\n");
        printf("Por favor faca de novo\n\n");
        pausar();
    }
    else if (res == 1)
    {
        menu_amigo();
    }
    else if (res == 2)
    {
        menu_local();
    }
    else if (res == 3)
    {
        menu_categoria();
    }
    else if (res == 4)
    {
        menu_encontro();
    }
    else if (res == 5)
    {
        menu_relatorio();
    }
    return 0;
}

void menu_amigo()
{
    int op;
    do
    {
        system("cls");
        printf("Menu Amigo\n\n");
        printf("1. Adicionar amigo\n");
        printf("2. Alterar amigo\n");
        printf("3. Excluir amigo\n");
        printf("4. Voltar\n\n");
        printf("Digite a opcao:  ");
        op = opcao_menu_amigo();
    } while (op != 4);
}

int opcao_menu_amigo()
{
    int res;
    scanf("%d", &res);
    fflush(stdin);
    switch (res)
    {
    case 1:
        incluir_amigo();
        break;
    case 2:
        opcao_alterar_Amigo();
        break;
    case 3:
        excluir_amigo();
        break;
    case 4:
        menu();
        break;
    default:
        printf("Valor invalido\n");
        printf("Por favor faca de novo\n\n");
        pausar();
        break;
    }
    return res;
}

void incluir_amigo()
{
    if (num_amigos == 0)
    {
        amigos = (TAmigo *)malloc(1 * sizeof(TAmigo));
    }
    else
    {
        amigos = (TAmigo *)realloc(amigos, (num_amigos + 1) * sizeof(TAmigo));
    }
    amigos[num_amigos] = criar_amigo();
    num_amigos++;
    return;
}

TAmigo criar_amigo()
{
    char straux[100];
    TAmigo amigo;
    system("cls");
    printf("digite o nome do amigo\n");
    gets(straux);
    amigo.nome = (char *)malloc((strlen(straux) + 1) * sizeof(char));
    strcpy(amigo.nome, straux);

    do
    {
        printf("digite sua data de nascimento\n");
        scanf("%d %d %d", &amigo.data_nasc.dia, &amigo.data_nasc.mes, &amigo.data_nasc.ano);
        fflush(stdin);
    } while (valida_data(amigo.data_nasc.dia, amigo.data_nasc.mes, amigo.data_nasc.ano) == 1);

    printf("digite seu apelido\n");
    gets(straux);
    amigo.apelido = (char *)malloc((strlen(straux) + 1) * sizeof(char));
    strcpy(amigo.apelido, straux);

    do
    {
        printf("digite seu e-mail\n");
        gets(straux);
        amigo.email = (char *)malloc((strlen(straux) + 1) * sizeof(char));
        strcpy(amigo.email, straux);

    } while (valida_email(amigo.email) == 0);

    do
    {
        printf("digite seu telefone\n");
        gets(straux);

        amigo.telefone = (char *)malloc((strlen(straux) + 1) * sizeof(char));
        strcpy(amigo.telefone, straux);
    } while (valida_telefone(amigo.telefone) == 0);
    amigo.id = num_amigos + 1;
    return amigo;
}

void menu_alterar_amigo(int i)
{
    int op;
    do
    {
        system("cls");
        printf("Menu alterar amigo\n\n");
        printf("1. Alterar nome\n");
        printf("2. Alterar data de nascimento\n");
        printf("3. Alterar apelido\n");
        printf("4. Alterar e-mail\n");
        printf("5. Alterar numero de telefone\n");
        printf("6. Voltar\n\n");
        printf("Digite a opcao:  ");
        scanf("%d", &op);
        fflush(stdin);
        if (op < 0 || op > 6)
        {
            printf("opcao invalida!!\n\n");
        }
        else
        {
            alterar_amigo(i, op);
        }
    } while (op != 6);
}

void alterar_amigo(int i, int op)
{
    char straux[100];
    system("cls");
    switch (op)
    {
    case 1:
        printf("digite o novo nome do amigo:  ");
        gets(straux);
        amigos[i].nome = (char *)malloc((strlen(straux) + 1) * sizeof(char));
        strcpy(amigos[i].nome, straux);
        break;

    case 2:
        printf("digite a nova data de nascimento:  ");
        scanf("%d %d %d", &amigos[i].data_nasc.dia, &amigos[i].data_nasc.mes, &amigos[i].data_nasc.ano);
        fflush(stdin);
        valida_data(amigos[i].data_nasc.dia, amigos[i].data_nasc.mes, amigos[i].data_nasc.ano);
        break;

    case 3:
        printf("digite o novo apelido:  ");
        gets(straux);
        amigos[i].apelido = (char *)malloc((strlen(straux) + 1) * sizeof(char));
        strcpy(amigos[i].apelido, straux);
        break;

    case 4:
        printf("digite o novo e-mail:  ");
        gets(straux);
        valida_email(amigos[i].email);
        amigos[i].email = (char *)malloc((strlen(straux) + 1) * sizeof(char));
        strcpy(amigos[i].email, straux);
        break;

    case 5:
        printf("digite o novo telefone");
        gets(straux);
        valida_telefone(amigos[i].telefone);
        amigos[i].telefone = (char *)malloc((strlen(straux) + 1) * sizeof(char));
        strcpy(amigos[i].telefone, straux);
        break;

    case 6:
        break;

    default:
        printf("opcao invalida\n\n");
        pausar();
    }
}
void excluir_amigo()
{
    int op = opcao_excluir_amigo();
    for (int i = op; i < num_amigos; i++)
    {
        amigos[i] = amigos[i + 1];
    }
    num_amigos--;
    printf("amigo excluido!!\n\n");
    pausar();
}

void menu_local()
{
    int op;
    do
    {
        system("cls");
        printf("Menu Local\n\n");
        printf("1. Adicionar local\n");
        printf("2. Alterar local\n");
        printf("3. Excluir local\n");
        printf("4. Voltar\n\n");
        printf("Digite a opcao:  ");
        op = opcao_local();
    } while (op != 4);
}

void menu_alterar_local(int i)
{
    system("cls");
    listar_local(locais[i]);
    int op;
    printf("Menu alterar local\n\n");
    printf("1. Alterar nome do local\n");
    printf("2. Alterar logradouro\n");
    printf("3. Alterar numero da casa\n");
    printf("4. Alterar bairro\n");
    printf("5. Alterar cidade\n");
    printf("6. Alterar estado\n");
    printf("7. Voltar\n\n");
    printf("Digite a opcao:  ");
    scanf("%d", &op);
    fflush(stdin);
    opcao_menu_alterar_local(i, op);
}

void menu_categoria()
{
    int op;
    do
    {
        system("cls");
        printf("Menu Categoria\n\n");
        printf("1. Adicionar categoria\n");
        printf("2. Alterar categoria\n");
        printf("3. Excluir categoria\n");
        printf("4. Voltar\n\n");
        printf("Digite a opcao:  ");
        op = opcao_menu_categoria();
    } while (op != 4);
}

void menu_encontro()
{
    int op;
    do
    {
        system("cls");
        printf("Menu Encontro\n\n");
        printf("1. Adicionar Encontro\n");
        printf("2. Alterar Encontro\n");
        printf("3. Excluir Encontro\n");
        printf("4. Voltar\n\n");
        printf("Digite a opcao:  ");
        op = opcao_menu_encontro();

    } while (op != 4);
}

void menu_relatorio()
{
    int op;
    do
    {
        system("cls");
        printf("Relatorios\n\n");
        printf("1. listar amigos\n");
        printf("2. listar locais\n");
        printf("3. listar categorias\n");
        printf("4. listar encontros\n");
        printf("5. Relatorio por categoria\n");
        printf("6. Voltar\n\n");
        printf("Digite a opcao:  ");
        op = opcao_menu_relatorio();
    } while (op != 6);
}

int valida_data(int dia, int mes, int ano)
{
    int x = 0;
    if (ano < 0)
    {
        printf("ano invalido\n\n");
        x = 1;
    }
    else if (mes < 1 || mes > 12)
    {
        printf("mes invalido\n\n");
        x = 1;
    }
    else if (dia < 0 || dia > 31)
    {
        printf("dia invalido\n\n");
        x = 1;
    }
    else if (mes == 2)
    {
        if (ano % 4 == 0)
        {
            if (dia > 29)
            {
                printf("dia invalido\n\n");
                x = 1;
            }
        }
        else
        {
            if (dia > 28)
            {
                printf("dia invalido\n\n");
                x = 1;
            }
        }
    }
    return x;
}

int valida_email(char *email)
{
    int countA = 0, countB = 0, x = 1;

    for (int i = 0; email[i] != '\0'; i++)
    {
        if (email[i] == '@')
        {
            countA++;
        }

        if (email[i] == '.')
        {
            countB++;
        }
    }

    if (countA != 1)
    {
        printf("e-mail invalido\n\n");
        x = 0;
    }

    else if (countB < 1)
    {
        printf("e-mail invalido\n\n");
        x = 0;
    }
    return x;
}

int valida_telefone(char *telefone)
{
    int x = 1, aux;
    aux = strlen(telefone);
    if (aux < 11 || aux > 11)
    {
        printf("numero invalido\n");
        x = 0;
    }
    return x;
}

void listar_amigos()
{
    system("cls");
    for (int i = 0; i < num_amigos; i++)
    {
        listar_amigo(amigos[i], i);
    }
}

void opcao_alterar_Amigo()
{

    if (num_amigos == 0)
    {
        printf("Numero de amigos insuficiente\n\n");
        pausar();
        return;
    }
    int i;
    listar_amigos();
    if (num_amigos > 1)
    {
        do
        {
            printf("qual amigo deseja alterar:  ");
            scanf("%d", &i);
            fflush(stdin);
            if ((i--) < 0 || (i--) > num_amigos)
            {
                printf("opcao invalida\n");
                pausar();
            }
        } while ((i--) < 0 || (i--) > num_amigos);
    }
    menu_alterar_amigo(i);
}

int opcao_excluir_amigo()
{
    int op;
    char aux;
    if (num_amigos == 0)
    {
        printf("Nenhum amigo cadastrado!!\n\n");
        pausar();
        return -1;
    }
    if (num_amigos > 1)
    {
        do
        {
            listar_amigos();
            printf("qual amigo sera apagado?:  ");
            scanf("%d", &op);
            fflush(stdin);
            if (op < 1 || op >= num_amigos)
            {
                printf("\nOpcao invalida!!\n\n");
                pausar();
            }
            system("cls");
        } while (op < 1 || op > num_amigos);
        op--;
    }
    else
    {
        op = 0;
    }
    do
    {
        system("cls");
        listar_amigo(amigos[op], op);
        printf("vc tem certeza em apagar esse amigo?(S ou N)");
        scanf("%c", &aux);
        fflush(stdin);
        aux = tolower(aux);
        if (aux != 's' && aux != 'n')
        {
            printf("Opcao invalida!!\n\n");
            pausar();
        }
        else if (aux == 'n')
        {
            return -1;
        }
    } while (aux != 's' && aux != 'n');
    return op;
}

void listar_amigo(TAmigo amig, int i)
{
    printf("Amigo[%d]\n", (i + 1));
    printf("Nome: %s\n", amig.nome);
    printf("Data de Nascimento: %d/%d/%d\n", amig.data_nasc.dia, amig.data_nasc.mes, amig.data_nasc.ano);
    printf("Apelido: %s\n", amig.apelido);
    printf("E-mail: %s\n", amig.email);
    printf("Telefone: %s\n\n", amig.telefone);
}

int opcao_local()
{
    int op;
    scanf("%d", &op);
    fflush(stdin);
    switch (op)
    {
    case 1:
        incluir_local();
        break;

    case 2:
        opcao_alterar_local();
        break;

    case 3:
        excluir_local();
        break;

    case 4:
        break;

    default:
        printf("opcao invalida!!\n\n");
        pausar();
        break;
    }
    return op;
}

void incluir_local()
{
    if (num_local == 0)
    {
        locais = (TLocal *)malloc(1 * sizeof(TLocal));
    }
    else
    {
        locais = (TLocal *)realloc(locais, (num_local + 1) * sizeof(TLocal));
    }
    locais[num_local] = criar_local();
    num_local++;

    return;
}

TLocal criar_local()
{
    TLocal local;
    char straux[100];

    system("cls");
    printf("Nome:  ");
    gets(straux);
    local.nome_lugar = (char *)malloc((strlen(straux) + 1) * sizeof(char));
    strcpy(local.nome_lugar, straux);

    printf("Logradouro:  ");
    gets(straux);
    local.endereco.logradouro = (char *)malloc((strlen(straux) + 1) * sizeof(char));
    strcpy(local.endereco.logradouro, straux);

    do
    {
        printf("Numero:  ");
        scanf("%d", &local.endereco.num);
        fflush(stdin);
        if (local.endereco.num < 1)
        {
            printf("Numero invalido\n\n");
            pausar();
        }
    } while (local.endereco.num < 1);

    printf("Bairo:  ");
    gets(straux);
    local.endereco.bairro = (char *)malloc((strlen(straux) + 1) * sizeof(char));
    strcpy(local.endereco.bairro, straux);

    printf("Cidade:  ");
    gets(straux);
    local.endereco.cidade = (char *)malloc((strlen(straux) + 1) * sizeof(char));
    strcpy(local.endereco.cidade, straux);

    printf("Estado:  ");
    gets(straux);
    local.endereco.estado = (char *)malloc((strlen(straux) + 1) * sizeof(char));
    strcpy(local.endereco.estado, straux);
    local.id = num_local++;

    return local;
}

TCategoria criar_categoria()
{
    TCategoria categoria;
    char straux[100];

    system("cls");
    printf("Categoria: ");
    gets(straux);
    fflush(stdin);
    categoria.categoria = (char *)malloc((strlen(straux) + 1) * sizeof(char));
    strcpy(categoria.categoria, straux);
    categoria.id = num_categoria;
    categoria.num_encontro_categoria = 0;

    return categoria;
}

void opcao_alterar_local()
{
    if (num_local == 0)
    {
        printf("Numero de locais insuficiente\n\n");
        pausar();
        return;
    }
    int i;
    if (num_local >= 1)
    {
        do
        {
            listar_locais();
            printf("qual local deseja alterar:  ");
            scanf("%d", &i);
            fflush(stdin);
            if ((i - 1) < 0 || (i - 1) > num_amigos)
            {
                printf("opcao invalida\n");
                pausar();
            }
        } while ((i - 1) < 0 || (i - 1) > num_amigos);
    }
    menu_alterar_local(i);
}

void listar_locais()
{
    system("cls");
    for (int i = 0; i < num_local; i++)
    {
        listar_local(locais[i]);
    }
}

void listar_local(TLocal loca)
{
    printf("Nome do Local:  %s\n", loca.nome_lugar);
    printf("Logradouro:  %s\n", loca.endereco.logradouro);
    printf("Numero:  %d\n", loca.endereco.num);
    printf("Bairro:  %s\n", loca.endereco.bairro);
    printf("Cidade:  %s\n", loca.endereco.cidade);
    printf("Estado:  %s\n\n", loca.endereco.estado);
}

void opcao_menu_alterar_local(int i, int op)
{
    char straux[100];
    system("cls");
    switch (op)
    {
    case 1:
        printf("Digite o novo Nome do Local:  ");
        gets(straux);
        locais->nome_lugar = (char *)malloc(strlen(straux) + 1);
        strcpy(locais[i].nome_lugar, straux);
        break;

    case 2:
        printf("Digite o novo Logradouro:  ");
        gets(straux);
        locais->endereco.logradouro = (char *)malloc(strlen(straux) + 1);
        strcpy(locais[i].endereco.logradouro, straux);
        break;

    case 3:
        do
        {
            printf("Digite o novo Numero:  ");
            scanf("%d", &locais[i].endereco.num);
            fflush(stdin);
            if (locais[i].endereco.num < 0)
            {
                printf("numero invalido\n");
                pausar();
            }
        } while ((locais[i].endereco.num < 0));
        break;

    case 4:
        printf("Digite o novo Bairro:  ");
        gets(straux);
        locais->endereco.bairro = (char *)malloc(strlen(straux) + 1);
        strcpy(locais[i].endereco.bairro, straux);
        break;

    case 5:
        printf("Digite o novo Cidade:  ");
        gets(straux);
        locais->endereco.cidade = (char *)malloc(strlen(straux) + 1);
        strcpy(locais[i].endereco.cidade, straux);
        break;

    case 6:
        printf("Digite o novo Estado:  ");
        gets(straux);
        locais->endereco.bairro = (char *)malloc(strlen(straux) + 1);
        strcpy(locais[i].endereco.bairro, straux);
        break;

    case 7:
        break;

    default:
        printf("opcao invalida!!\n\n");
        pausar();
        break;
    }
}
void pausar()
{
    printf("pressione qualquer tecla para continuar...");
    getch();
}

void excluir_local()
{
    int op = opcao_excluir_local();
    for (int i = op; i < num_local; i++)
    {
        locais[i] = locais[i + 1];
    }
    num_local--;
    printf("local excluido!!\n\n");
    pausar();
}

int opcao_excluir_local()
{
    int op;
    char aux;
    if (num_local == 0)
    {
        printf("Nenhum local cadastrado!!\n\n");
        pausar();
        return -1;
    }
    if (num_local > 1)
    {
        do
        {
            listar_locais();
            printf("qual local sera apagado?:  ");
            scanf("%d", &op);
            fflush(stdin);
            op--;
            if (op < 1 || op >= num_local)
            {
                printf("\nOpcao invalida!!\n\n");
                pausar();
            }
            system("cls");
        } while (op < 1 || op > num_local);
    }
    else
    {
        op = 0;
    }
    do
    {
        listar_local(locais[op]);
        printf("vc tem certeza em apagar esse local?(S ou N)");
        scanf("%c", &aux);
        fflush(stdin);
        aux = tolower(aux);
        if (aux != 's' && aux != 'n')
        {
            printf("Opcao invalida!!\n\n");
            pausar();
        }
        else if (aux == 'n')
        {
            return -1;
        }
    } while (aux != 's' && aux != 'n');
    return op;
}

int opcao_menu_categoria()
{
    int res;
    scanf("%d", &res);
    fflush(stdin);
    switch (res)
    {
    case 1:
        incluir_categoria();
        break;
    case 2:
        alterar_categoria();
        break;
    case 3:
        excluir_categoria();
        break;
    case 4:
        menu();
        break;
    default:
        printf("Valor invalido\n");
        printf("Por favor faca de novo\n\n");
        pausar();
        break;
    }
    return res;
}

void incluir_categoria()
{
    char aux;
    do
    {
        if (num_categoria == 0)
        {
            categorias = (TCategoria *)malloc(1 * sizeof(TCategoria));
        }
        else
        {
            categorias = (TCategoria *)realloc(categorias, (num_categoria + 1) * sizeof(TCategoria));
        }
        categorias[num_categoria] = criar_categoria();
        num_categoria++;

        printf("voce deseja adicionar mais uma categoria(s/n)\n");
        scanf("%c", &aux);
        aux = tolower(aux);
        fflush(stdin);
    } while (aux == 's');
}

void listar_categorias()
{
    for (int i = 0; i < num_categoria; i++)
    {
        listar_categoria(categorias[i], i);
    }
}

void listar_categoria(TCategoria categ, int i)
{
    printf("Categoria[%d]", i);
    printf("%s\n", categ.categoria);
}

void alterar_categoria()
{
    int aux;
    char straux[100];
    do
    {
        listar_categorias();
        printf("Digite qual categoria voce deseja alterar\n");
        scanf("%d", &aux);
        if (aux < 0 || aux > num_categoria)
        {
            printf("opcao invalida!!\n\n");
        }
    } while (aux < 0 || aux > num_categoria);

    printf("digite a nova categoria\n");
    gets(straux);
    categorias[aux].categoria = (char *)malloc((strlen(straux) + 1) * sizeof(char));
    strcpy(categorias[aux].categoria, straux);
}

void excluir_categoria()
{
    int op = opcao_excluir_categoria();
    for (int i = op; i < num_categoria; i++)
    {
        categorias[i] = categorias[i + 1];
    }
    num_categoria--;
    printf("categoria excluida!!\n\n");
    pausar();
}

int opcao_excluir_categoria()
{
    int op;
    char aux;
    system("clear");
    if (num_categoria == 0)
    {
        printf("Nenhuma categoria cadastrada!!\n\n");
        pausar();
        return -1;
    }
    if (num_categoria > 1)
    {
        do
        {
            listar_categorias();
            printf("qual categoria sera apagada?:  ");
            scanf("%d", &op);
            fflush(stdin);
            op--;
            if (op < 1 || op >= num_local)
            {
                printf("\nOpcao invalida!!\n\n");
                pausar();
            }
            system("cls");
        } while (op < 1 || op > num_local);
    }
    else
    {
        op = 0;
    }
    do
    {
        listar_categoria(categorias[op], op);
        printf("vc tem certeza em apagar essa categoria?(S ou N)");
        scanf("%c", &aux);
        fflush(stdin);
        aux = tolower(aux);
        if (aux != 's' && aux != 'n')
        {
            printf("Opcao invalida!!\n\n");
            pausar();
        }
        else if (aux == 'n')
        {
            return -1;
        }
    } while (aux != 's' && aux != 'n');
    return op;
}

void salvar_arquivo_amigo()
{
    FILE *arquivo;
    arquivo = fopen("amigos.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    for (int i = 0; i < num_amigos; i++)
    {
        fprintf(arquivo, "%s;", amigos[i].nome);
        fprintf(arquivo, "%d,", amigos[i].data_nasc.dia);
        fprintf(arquivo, "%d,", amigos[i].data_nasc.mes);
        fprintf(arquivo, "%d,", amigos[i].data_nasc.ano);
        fprintf(arquivo, "%s;", amigos[i].apelido);
        fprintf(arquivo, "%s;", amigos[i].email);
        fprintf(arquivo, "%s;", amigos[i].telefone);
        fprintf(arquivo, "%c", '\n');
    }
    printf("dados salvos com sucesso!!\n");
    pausar();
    fclose(arquivo);
}
void carregar_arquivo_amigo()
{
    int i, sepp = 0, sepv = 0;
    char straux[100], c;
    FILE *arquivo;
    arquivo = fopen("amigos.txt", "r");

    if (arquivo)
    {
        while (!feof(arquivo))
        {
            c = fgetc(arquivo);
            if (c != ';' && c != ',' && c != '\n' && c != EOF)
            {
                straux[i] = c;
                i++;
            }
            else if (c == ';' || c == ',' || c == '\n')
            {
                straux[i] = '\0';
                i = 0;
                if (c == ';')
                {
                    if (sepp == 0)
                    {
                        if (num_amigos == 0)
                        {
                            amigos = (TAmigo *)malloc(1 * sizeof(TAmigo));
                        }
                        else
                        {
                            amigos = (TAmigo *)realloc(amigos, (num_amigos + 1) * sizeof(TAmigo));
                        }
                        amigos[num_amigos].nome = (char *)malloc(strlen(straux) + 1);
                        strcpy(amigos[num_amigos].nome, straux);
                        sepp++;
                    }
                    else if (sepp == 1)
                    {
                        amigos[num_amigos].apelido = (char *)malloc(strlen(straux) + 1);
                        strcpy(amigos[num_amigos].apelido, straux);
                    }
                    else if (sepp == 2)
                    {
                        amigos[num_amigos].email = (char *)malloc(strlen(straux) + 1);
                        strcpy(amigos[num_amigos].email, straux);
                    }
                    else if (sepp == 3)
                    {
                        amigos[num_amigos].telefone = (char *)malloc(strlen(straux) + 1);
                        strcpy(amigos[num_amigos].telefone, straux);
                    }
                }
                else if (c == ',')
                {
                    if (sepv == 0)
                    {
                        amigos[num_amigos].data_nasc.dia = atoi(straux);
                        sepv++;
                    }
                    else if (sepv == 1)
                    {
                        amigos[num_amigos].data_nasc.mes = atoi(straux);
                        sepv++;
                    }
                    else if (sepv == 2)
                    {
                        amigos[num_amigos].data_nasc.ano = atoi(straux);
                    }
                }
                else if (c == '\n')
                {
                    sepp = 0;
                    sepv = 0;
                    num_amigos++;
                }
            }
        }
    }
    fclose(arquivo);
}

void salvar_arquivo_local()
{
    FILE *arquivo;
    arquivo = fopen("locais.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }
    for (int i = 0; i < num_local; i++)
    {
        fprintf(arquivo, "%s;", locais[i].nome_lugar);
        fprintf(arquivo, "%s;", locais[i].endereco.logradouro);
        fprintf(arquivo, "%d,", locais[i].endereco.num);
        fprintf(arquivo, "%s;", locais[i].endereco.bairro);
        fprintf(arquivo, "%s;", locais[i].endereco.cidade);
        fprintf(arquivo, "%s;", locais[i].endereco.estado);
    }
    printf("arquivo salvo com sucesso\n");
    pausar();
    fclose(arquivo);
}

void carregar_arquivo_local()
{
    int i, sep = 0;
    char straux[100], c;
    FILE *arquivo;
    arquivo = fopen("locais.txt", "r");

    if (arquivo)
    {
        while (!feof(arquivo))
        {
            c = fgetc(arquivo);
            if (c != ';' && c != ',' && c != '\n' && c != EOF)
            {
                straux[i] = c;
                i++;
            }
            else if (c == ';' || c == ',' || c == '\n')
            {
                straux[i] = '\0';
                i = 0;
                if (c == ';')
                {
                    if (sep == 0)
                    {
                        if (num_local == 0)
                        {
                            locais = (TLocal *)malloc(1 * sizeof(TLocal));
                        }
                        else
                        {
                            locais = (TLocal *)realloc(locais, (num_local + 1) * sizeof(TLocal));
                        }
                        locais[i].nome_lugar = (char *)malloc(strlen(straux) * sizeof(char));
                        strcpy(locais[i].nome_lugar, straux);
                        sep++;
                    }
                    else if (sep == 1)
                    {
                        locais[i].endereco.logradouro = (char *)malloc(strlen(straux) * sizeof(char));
                        strcpy(locais[i].endereco.logradouro, straux);
                        sep++;
                    }
                    else if (sep == 2)
                    {
                        locais[i].endereco.bairro = (char *)malloc(strlen(straux) * sizeof(char));
                        strcpy(locais[i].endereco.bairro, straux);
                        sep++;
                    }
                    else if (sep == 3)
                    {
                        locais[i].endereco.cidade = (char *)malloc(strlen(straux) * sizeof(char));
                        strcpy(locais[i].endereco.cidade, straux);
                        sep++;
                    }
                    else if (sep == 4)
                    {
                        locais[i].endereco.estado = (char *)malloc(strlen(straux) * sizeof(char));
                        strcpy(locais[i].endereco.estado, straux);
                    }
                }
                else if (c == ',')
                {
                    locais[i].endereco.num = atoi(straux);
                }
                else if (c == '\n')
                {
                    sep = 0;
                    num_local++;
                }
            }
        }
    }
    fclose(arquivo);
}

void salvar_arquivo_categoria()
{
    FILE *arquivo;
    arquivo = fopen("categorias.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo\n");
    }
    for (int i = 0; i < num_categoria; i++)
    {
        fprintf(arquivo, "%s;", categorias[i].categoria);
        fprintf(arquivo, "%d%d;", categorias[i].id, categorias[i].num_encontro_categoria);
        fprintf(arquivo, "\n");
    }
    printf("arquivo salvo com sucesso\n");
    pausar();
    fclose(arquivo);
}

void carregar_arquivo_categoria()
{
    FILE *arquivo;
    char straux[100], c;
    int i, sep = 0;
    arquivo = fopen("categorias.txt", "r");

    if (arquivo)
    {
        while (!feof(arquivo))
        {
            c = fgetc(arquivo);
            if (c != ';' && c != '\n' && c != EOF)
            {
                straux[i] = c;
                i++;
            }
            else if (c == ';' || c == '\n')
            {
                straux[i] = '\0';
                i = 0;
                if (c == ';')
                {
                    if (sep == 0)
                    {
                        if (num_categoria == 0)
                        {
                            categorias = (TCategoria *)malloc(1 * sizeof(TCategoria));
                        }
                        else
                        {
                            categorias = (TCategoria *)realloc(categorias, (num_categoria + 1) * sizeof(TCategoria));
                        }
                        categorias[num_categoria].categoria = (char *)malloc((i + 1) * sizeof(char));
                        strcpy(categorias[num_categoria].categoria, straux);
                        sep++;
                    }
                    else if(sep == 1){
                        categorias[num_categoria].id = atoi(straux);
                        sep++;
                    }
                    else if(sep == 2){
                        categorias[num_categoria].num_encontro_categoria = atoi(straux);
                        sep++;
                    }
                }
                else if(c == '\n'){
                    sep = 0;
                    num_categoria++;
                }
            }
        }
    }
    fclose(arquivo);
}

int opcao_menu_relatorio()
{
    int res;
    scanf("%d", &res);
    fflush(stdin);
    switch (res)
    {
    case 1:
        relatorio_amigo();
        break;
    case 2:
        relatorio_local();
        break;
    case 3:
        relatorio_categoria();
        break;
    case 4:
        relatorio_encontro();
        break;
    case 5:
        relatorio_por_categoria();
        break;
    case 6:
        menu();
        break;
    default:
        system("cls");
        printf("opcao invalida\n");
        printf("por favor digite de novo\n\n");
        pausar();
        break;
    }
    pausar();
    return res;
}

void relatorio_amigo()
{
    int op, i;
    if (num_amigos > 1)
    {
        op = opcao_relatorio();
    }
    if (op == 1)
    {
        do
        {
            printf("Qual amigo voce deseja listar?\n");
            printf("[1-%d]", num_amigos);
            scanf("%d", &i);
            fflush(stdin);
            if (i < 1 || i > num_amigos)
            {
                printf("numero invalido\n\n");
            }
            else
            {
                i--;
                listar_categoria(categorias[i], i);
            }
        } while (i < 1 || i > num_amigos);
    }
    else
    {
        listar_amigos();
        pausar();
    }
}

void relatorio_local()
{
    int op, i;
    if (num_local > 1)
    {
        op = opcao_relatorio();
    }
    if (op == 1)
    {
        do
        {
            printf("Qual local voce deseja listar?\n");
            printf("[1-%d]", num_local);
            scanf("%d", &i);
            fflush(stdin);
            if (i < 1 || i > num_local)
            {
                printf("numero invalido\n\n");
            }
            else
            {
                i--;
                listar_categoria(categorias[i], i);
            }
        } while (i < 1 || i > num_local);
    }
    else
    {
        listar_locais();
    }
}

void relatorio_categoria()
{
    int op, i;
    if (num_categoria > 1)
    {
        op = opcao_relatorio();
    }
    if (op == 1)
    {
        do
        {
            printf("Qual categoria voce deseja listar?\n");
            printf("[1-%d]", num_categoria);
            scanf("%d", &i);
            fflush(stdin);
            if (i < 1 || i > num_categoria)
            {
                printf("numero invalido\n\n");
            }
            else
            {
                i--;
                listar_categoria(categorias[i], i);
            }
        } while (i < 1 || i > num_categoria);
    }
    else
    {
        listar_categorias();
    }
}
void relatorio_encontro()
{
    int op, i;
    if (num_encontro > 1)
    {
        op = opcao_relatorio();
        if (op == 1)
        {
            do
            {
                printf("Qual encontro voce deseja listar?\n");
                printf("[1-%d]", num_encontro);
                scanf("%d", &i);
                fflush(stdin);
                if (i < 1 || i > num_encontro)
                {
                    printf("numero invalido\n\n");
                }
                else
                {
                    // listar_encontro(i-1);
                }
            } while (i < 1 || i > num_encontro);
        }
    }
}

void relatorio_por_categoria()
{
    if (num_categoria > 1)
    {
    }
}

int opcao_relatorio()
{
    int op;
    do
    {
        system("cls");
        printf("1: mostrar apenas um\n");
        printf("2: mostrar todos\n\n");
        printf("digite a opcao:  ");
        scanf("%d", &op);
        fflush(stdin);
    } while (op < 1 || op > 2);
    return op;
}

void salvar_arquivos()
{
    salvar_arquivo_amigo();
    salvar_arquivo_categoria();
    salvar_arquivo_local();
}

void carregar_arquivos()
{
    carregar_arquivo_amigo();
    carregar_arquivo_local();
    carregar_arquivo_categoria();
}

int opcao_menu_encontro()
{
    int op;
    scanf("%d", &op);
    fflush(stdin);
    switch (op)
    {
    case 1:
        incluir_encontro();
        break;

    case 2:
        // alterar_encontro();
        break;

    case 3:
        // excluir_encontro();
        break;

    case 4:
        break;

    default:
        printf("numero, invalido\n\n");
        pausar();
        break;
    }

    return op;
}

void incluir_encontro()
{
    if (num_amigos < 1 || num_local < 1 || num_categoria < 1)
    {
        printf("dados insuficientes");
    }
    if (num_encontro == 0)
    {
        Encontros = (TEncontro *)malloc(1 * sizeof(TEncontro));
    }
    else
    {
        Encontros = (TEncontro *)realloc(Encontros, (num_encontro + 1) * sizeof(TEncontro));
    }
    Encontros[num_encontro] = criar_encontro();
    num_encontro++;
}

TEncontro criar_encontro()
{
    int op, ind;
    char aju;
    char straux[100];
    TEncontro encontro;
    encontro.num_amigos_encontro = 0;
    encontro.num_categoria_encontro = 0;

    do
    {
        printf("Digite a data do encontro:  ");
        scanf("%d%d%d", &encontro.data.dia, &encontro.data.mes, &encontro.data.ano);
        fflush(stdin);
        op = valida_data(encontro.data.dia, encontro.data.mes, encontro.data.ano);
    } while (op == 1);

    do
    {
        printf("Digite o horario do encontro:  ");
        scanf("%d%d", &encontro.horario.hora, &encontro.horario.minuto);
        fflush(stdin);
        op = valida_horario(encontro.horario.hora, encontro.horario.minuto);
    } while (op == 1);

    while (encontro.num_amigos_encontro < num_amigos)
    {
        int aux = 0;

        do
        {
            listar_amigos_nao_inclusos(encontro);
            printf("Qual amigo voce deseja adicionar ao encontro:  ");
            scanf("%d", &ind);
            fflush(stdin);
            ind--;
            if (ind < 0 || ind >= num_amigos)
            {
                printf("invalido");
                pausar();
            }
        } while (ind < 0 || ind >= num_amigos);

        for (int i = 0; i < encontro.num_amigos_encontro; i++)
        {
            if (encontro.amigos[i].id == amigos[ind].id)
            {
                printf("amigo ja inserido");
                pausar();
                aux = 1;
                break;
            }
        }

        if (aux == 1)
        {
            continue;
        }

        if (encontro.num_amigos_encontro == 0)
        {
            encontro.amigos = (TAmigo *)malloc(1 * sizeof(TAmigo));
        }
        else
        {
            encontro.amigos = (TAmigo *)realloc(encontro.amigos, (encontro.num_amigos_encontro + 1) * sizeof(TAmigo));
        }

        encontro.amigos[encontro.num_amigos_encontro] = amigos[ind];
        encontro.num_amigos_encontro++;

        do
        {
            printf("deseja adicionar outro amigo[S ou N]:  ");
            scanf("%c", &aju);
            aju = tolower(aju);
            fflush(stdin);
        } while (aju != 's' || aju != 'n');

        if (aju == 'n')
        {
            break;
        }
    }

    do
    {
        listar_locais();
        printf("Qual local voce deseja adicionar ao encontro:  ");
        scanf("%d", &ind);
        fflush(stdin);
        ind--;
        if (ind < 0 || ind >= num_local)
        {
            pausar();
        }
    } while (ind < 0 || ind >= num_local);
    encontro.local = locais[ind];

    while (encontro.num_categoria_encontro < num_categoria)
    {
        int aux = 0;

        do
        {
            listar_categorias_nao_inclusas(encontro);
            printf("Qual categoria voce deseja adicionar ao encontro:  ");
            scanf("%d", &ind);
            fflush(stdin);
            ind--;
            if (ind < 0 || ind >= num_categoria)
            {
                printf("invalido");
                pausar();
            }
        } while (ind < 0 || ind >= num_categoria);

        for (int i = 0; i < encontro.num_categoria_encontro; i++)
        {
            if (encontro.categoria[i].id == categorias[ind].id)
            {
                printf("categoria ja inserida");
                pausar();
                aux = 1;
                break;
            }
        }

        if (aux == 1)
        {
            continue;
        }

        if (encontro.num_categoria_encontro == 0)
        {
            encontro.categoria = (TCategoria *)malloc(1 * sizeof(TCategoria));
        }
        else
        {
            encontro.categoria = (TCategoria *)realloc(encontro.categoria, (encontro.num_categoria_encontro + 1) * sizeof(TCategoria));
        }

        encontro.categoria[encontro.num_categoria_encontro] = categorias[ind];
        encontro.num_categoria_encontro++;

        do
        {
            printf("deseja adicionar outra categoria[S ou N]:  ");
            scanf("%c", &aju);
            aju = tolower(aju);
            fflush(stdin);
        } while (aju != 's' || aju != 'n');

        if (aju == 'n')
        {
            break;
        }
    }

    system("cls");
    printf("Digite a descricao do encontro\n\n");
    gets(straux);
    encontro.descricao = (char *)malloc((strlen(straux) + 1) * sizeof(char));
    strcpy(encontro.descricao, straux);

    return encontro;
}

int valida_horario(int hora, int minuto)
{
    int x = 0;
    if (hora > 23 || hora < 0)
    {
        x = 1;
    }
    else if (minuto > 59 || minuto < 0)
    {
        x = 1;
    }
    return x;
}

void listar_amigos_nao_inclusos(TEncontro encontro)
{
    int aux = 0;
    system("cls");
    printf("-- Lista de amigos [%d] --\n\n", (num_amigos - encontro.num_amigos_encontro));
    for (int i = 0; i < num_amigos; i++)
    {
        int check = 1;
        for (int j = 0; j < encontro.num_amigos_encontro; j++)
        {
            if (encontro.amigos[j].id == amigos[i].id)
            {
                aux = i;
                check = 0;
                break;
            }
        }
        if (check == 0)
        {
            listar_amigo(amigos[i], aux);
            aux++;
        }
    }
}

void listar_categorias_nao_inclusas(TEncontro encontro)
{
    int aux = 0;
    system("cls");
    printf("-- Lista de categorias [%d] --\n\n", (num_categoria - encontro.num_categoria_encontro));
    for (int i = 0; i < num_categoria; i++)
    {
        int check = 1;
        for (int j = 0; j < encontro.num_categoria_encontro; j++)
        {
            if (encontro.categoria[j].id == categorias[i].id)
            {
                aux = i;
                check = 0;
                break;
            }
        }
        if (check == 0)
        {
            listar_categoria(categorias[i], aux);
            aux++;
        }
    }
}

int valida_sim_ou_nao(char op)
{
    int x = 0;
    if (op != 's' && op != 'n')
    {
        x = 1;
    }
    return x;
}

void mensagem_de_erro(int i)
{
    system("cls");
    switch (i)
    {
    case -1:
        printf("Nenhum amigo cadastrado ainda\n");
        break;
    case -2:
        printf("Nenhum local cadastrado ainda\n");
        break;
    case -3:
        printf("Nenhuma categoria cadastrada ainda\n");
        break;
    case -4:
        printf("Nenhum encontro cadastrado ainda\n");
        break;
    case -5:
        printf("Opcao invalida\n");
        break;
    case -6:
        break;
    }
}