#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

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
void pausar();
void opcao_menu(int res);
void mensagem_de_erro(int i);
void salvar_arquivos();

void menu_amigo();
int opcao_menu_amigo();
void menu_alterar_amigo(int i);
void opcao_alterar_Amigo();
int opcao_excluir_amigo();
TAmigo criar_amigo();
void incluir_amigo();
void listar_amigos();
void listar_amigo(TAmigo amig, int i);
void excluir_amigo();
void alterar_amigo(int ind, int op);
void salvar_arquivo_amigo();

void menu_local();
void menu_alterar_local();
void listar_local(TLocal loca);
void listar_locais();
int opcao_local();
void incluir_local();
TLocal criar_local();
void opcao_menu_alterar_local(int ind, int op);
void opcao_alterar_local();
void excluir_local();
int opcao_excluir_local();

void menu_categoria();
int opcao_menu_categoria();
void incluir_categoria();
TCategoria criar_categoria();
void alterar_categoria();
void listar_categorias();
void listar_categoria(TCategoria categ, int i);
void excluir_categoria();
int opcao_excluir_categoria();

void menu_encontro();
int opcao_menu_encontro();
void incluir_encontro();
TEncontro criar_encontro();
void listar_encontro(TEncontro encontro, int i);
void listar_encontros();
void opcao_alterar_encontro();
void menu_alterar_encontro(int ind);
int opcao_menu_alterar_encontro(int ind);
void menu_alterar_amigo_encontro(int ind);
int opcao_menu_alterar_amigo_encontro(int ind);
int opcao_menu_alterar_categoria_encontro(int ind);
void menu_alterar_categoria_encontro(int ind);
void incluir_amigos_encontro(int ind);
void alterar_amigos_encontro(int ind);
void excluir_amigos_encontro(int ind);
void opcao_excluir_amigo_encontro(int ind);
void incluir_categorias_encontro(int ind);
void alterar_categorias_encontro(int ind);
void opcao_excluir_categorias_encontro(int ind);
void excluir_categoria_encontro(int ind, int indice);
void excluir_encontro();
void listar_categorias_encontro(int ind);
void listar_amigos_encontro(int ind);
void listar_amigos_nao_inclusos(TEncontro encontro);
void listar_categorias_nao_inclusas(TEncontro encontro);

void menu_relatorio();
int opcao_menu_relatorio();
void relatorio_amigo();
void relatorio_local();
void relatorio_categoria();
void relatorio_encontro();
void relatorio_por_categoria();
void listar_num_encontro_categoria(int indice);
void listar_num_encontro_categorias();
int opcao_relatorio();

int valida_data(int dia, int mes, int ano);
int valida_email(char *email);
int valida_telefone(char *telefone);
int valida_horario(int hora, int minuto);
int valida_sim_ou_nao(char op);

void salvar_arquivo_local();
void salvar_arquivo_categoria();
void salvar_arquivo_encontro();

void carregar_arquivos();
void carregar_arquivo_amigo();
void carregar_arquivo_local();
void carregar_arquivo_categoria();
void carregar_arquivo_encontro();

void limpar_ponteiros();
void limpar_ponteiros_amigos();
void limpar_ponteiros_locais();
void limpar_ponteiros_categorias();
void limpar_ponteiros_encontros();
void validarAlocacao(void *ptr);

int main()
{
    int res;
    carregar_arquivos();
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
    printf("Menu Principal \n\n");
    printf("1. Manter amigo\n");
    printf("2. Manter local\n");
    printf("3. Manter categoria\n");
    printf("4. Manter encontro\n");
    printf("5. Relatorios\n");
    printf("6. Sair\n\n");
    printf("Digite a opcao:  ");
}

void opcao_menu(int res)
{
    switch (res)
    {
    case 1:
        menu_amigo();
        break;
    case 2:
        menu_local();
        break;
    case 3:
        menu_categoria();
        break;
    case 4:
        menu_encontro();
        break;
    case 5:
        menu_relatorio();
        break;
    case 6:
        system("cls");
        printf("Saindo\n");
        pausar();
        break;
    default:
        mensagem_de_erro(-5);
        pausar();
        break;
    }
}

void menu_amigo()
{
    int op;
    do
    {
        system("cls");
        printf("Manter Amigo\n\n");
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
        break;
    default:
        mensagem_de_erro(-5);
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
    validarAlocacao(amigos);
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
    validarAlocacao(amigos);
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
    validarAlocacao(amigos);
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
        validarAlocacao(amigos);
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
        listar_amigo(amigos[i], i);
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
            mensagem_de_erro(-5);
            pausar();
            return;
        }
        else
        {
            alterar_amigo(i, op);
        }
    } while (op != 6);
}

void alterar_amigo(int ind, int op)
{
    char straux[100];
    system("cls");
    switch (op)
    {
    case 1:
        printf("digite o novo nome do amigo:  ");
        gets(straux);
        amigos[ind].nome = (char *)malloc((strlen(straux) + 1) * sizeof(char));
        validarAlocacao(amigos);
        strcpy(amigos[ind].nome, straux);
        for (int i = 0; i < num_encontro; i++)
        {
            for (int j = 0; j < Encontros[i].num_amigos_encontro; j++)
            {
                if (amigos[ind].id == Encontros[i].amigos[j].id)
                {
                    Encontros[i].amigos[j].nome = amigos[ind].nome;
                }
            }
        }
        break;

    case 2:
        printf("digite a nova data de nascimento:  ");
        scanf("%d %d %d", &amigos[ind].data_nasc.dia, &amigos[ind].data_nasc.mes, &amigos[ind].data_nasc.ano);
        fflush(stdin);
        valida_data(amigos[ind].data_nasc.dia, amigos[ind].data_nasc.mes, amigos[ind].data_nasc.ano);
        for (int i = 0; i < num_encontro; i++)
        {
            for (int j = 0; j < Encontros[i].num_amigos_encontro; j++)
            {
                if (amigos[ind].id == Encontros[i].amigos[j].id)
                {
                    Encontros[i].amigos[j].data_nasc.dia = amigos[ind].data_nasc.dia;
                    Encontros[i].amigos[j].data_nasc.mes = amigos[ind].data_nasc.mes;
                    Encontros[i].amigos[j].data_nasc.ano = amigos[ind].data_nasc.ano;
                }
            }
        }
        break;

    case 3:
        printf("digite o novo apelido:  ");
        gets(straux);
        amigos[ind].apelido = (char *)malloc((strlen(straux) + 1) * sizeof(char));
        validarAlocacao(amigos);
        strcpy(amigos[ind].apelido, straux);
        for (int i = 0; i < num_encontro; i++)
        {
            for (int j = 0; j < Encontros[i].num_amigos_encontro; j++)
            {
                if (amigos[ind].id == Encontros[i].amigos[j].id)
                {
                    Encontros[i].amigos[j].apelido = amigos[ind].apelido;
                }
            }
        }
        break;

    case 4:
        printf("digite o novo e-mail:  ");
        gets(straux);
        valida_email(amigos[ind].email);
        amigos[ind].email = (char *)malloc((strlen(straux) + 1) * sizeof(char));
        validarAlocacao(amigos);
        strcpy(amigos[ind].email, straux);
        for (int i = 0; i < num_encontro; i++)
        {
            for (int j = 0; j < Encontros[i].num_amigos_encontro; j++)
            {
                if (amigos[ind].id == Encontros[i].amigos[j].id)
                {
                    Encontros[i].amigos[j].email = amigos[ind].email;
                }
            }
        }
        break;

    case 5:
        printf("digite o novo telefone");
        gets(straux);
        valida_telefone(amigos[ind].telefone);
        amigos[ind].telefone = (char *)malloc((strlen(straux) + 1) * sizeof(char));
        validarAlocacao(amigos);
        strcpy(amigos[ind].telefone, straux);
        for (int i = 0; i < num_encontro; i++)
        {
            for (int j = 0; j < Encontros[i].num_amigos_encontro; j++)
            {
                if (amigos[ind].id == Encontros[i].amigos[j].id)
                {
                    Encontros[i].amigos[j].telefone = amigos[ind].telefone;
                }
            }
        }
        break;

    case 6:
        break;

    default:
        mensagem_de_erro(-5);
        pausar();
    }
}
void excluir_amigo()
{
    int op = opcao_excluir_amigo();
    if (op != -1)
    {
        for (int i = op; i < num_amigos; i++)
        {
            amigos[i] = amigos[i + 1];
        }
        num_amigos--;
        printf("amigo excluido!!\n\n");
        pausar();
    }
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
        listar_amigo(amigos[i], i + 1);
    }
    pausar();
}

void opcao_alterar_Amigo()
{
    int i;

    if (num_amigos == 0)
    {
        mensagem_de_erro(-1);
        pausar();
        return;
    }

    if (num_amigos > 1)
    {
        do
        {
            listar_amigos();
            printf("qual amigo deseja alterar:  ");
            scanf("%d", &i);
            fflush(stdin);
            if (i < 1 || i > num_amigos)
            {
                mensagem_de_erro(-5);
                pausar();
            }
        } while (i < 0 || i > num_amigos);
    }
    else
    {
        i = 1;
    }
    i--;
    menu_alterar_amigo(i);
}

int opcao_excluir_amigo()
{
    int op;
    char aux;
    if (num_amigos == 0)
    {
        mensagem_de_erro(-1);
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
                mensagem_de_erro(-5);
                pausar();
            }
            system("cls");
        } while (op < 1 || op > num_amigos);
    }
    else
    {
        op = 1;
    }
    op--;
    for (int i = 0; i < num_encontro; i++)
    {
        for (int j = 0; j < Encontros[i].num_amigos_encontro; j++)
        {
            if (amigos[op].id == Encontros[i].amigos[j].id)
            {
                mensagem_de_erro(-12);
                pausar();
                return -1;
            }
        }
    }
    do
    {
        system("cls");
        listar_amigo(amigos[op], op);
        printf("vc tem certeza em apagar esse amigo?(S ou N)");
        scanf("%c", &aux);
        fflush(stdin);
        aux = tolower(aux);
        if (valida_sim_ou_nao(aux))
        {
            mensagem_de_erro(-5);
            pausar();
        }
        else if (aux == 'n')
        {
            return -1;
        }
    } while (valida_sim_ou_nao(aux));
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
        mensagem_de_erro(-5);
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
    validarAlocacao(locais);
    strcpy(local.nome_lugar, straux);

    printf("Logradouro:  ");
    gets(straux);
    local.endereco.logradouro = (char *)malloc((strlen(straux) + 1) * sizeof(char));
    validarAlocacao(locais);
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
    validarAlocacao(locais);
    strcpy(local.endereco.bairro, straux);

    printf("Cidade:  ");
    gets(straux);
    local.endereco.cidade = (char *)malloc((strlen(straux) + 1) * sizeof(char));
    validarAlocacao(locais);
    strcpy(local.endereco.cidade, straux);

    printf("Estado:  ");
    gets(straux);
    local.endereco.estado = (char *)malloc((strlen(straux) + 1) * sizeof(char));
    validarAlocacao(locais);
    strcpy(local.endereco.estado, straux);
    local.id = num_local;

    return local;
}

TCategoria criar_categoria()
{
    TCategoria categoria;
    char straux[100];

    system("cls");
    printf("Categoria: ");
    gets(straux);

    categoria.categoria = (char *)malloc((strlen(straux) + 1) * sizeof(char));
    validarAlocacao(categorias);
    strcpy(categoria.categoria, straux);

    categoria.id = num_categoria;
    categoria.num_encontro_categoria = 0;

    return categoria;
}

void opcao_alterar_local()
{
    if (num_local == 0)
    {
        mensagem_de_erro(-2);
        pausar();
        return;
    }
    int i;

    if (num_local > 1)
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
    else{
        i = 0;
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
    printf("Local [%d]\n", loca.id + 1);
    printf("Nome do Local:  %s\n", loca.nome_lugar);
    printf("Logradouro:  %s\n", loca.endereco.logradouro);
    printf("Numero:  %d\n", loca.endereco.num);
    printf("Bairro:  %s\n", loca.endereco.bairro);
    printf("Cidade:  %s\n", loca.endereco.cidade);
    printf("Estado:  %s\n\n", loca.endereco.estado);
}

void opcao_menu_alterar_local(int ind, int op)
{
    char straux[100];
    system("cls");
    switch (op)
    {
    case 1:
        printf("Digite o novo Nome do Local:  ");
        gets(straux);
        locais[ind].nome_lugar = (char *)malloc(strlen(straux) + 1);
        validarAlocacao(locais);
        strcpy(locais[ind].nome_lugar, straux);
        for (int i = 0; i < num_encontro; i++)
        {
            if (locais[ind].id == Encontros[i].local.id)
            {
                Encontros[i].local.nome_lugar = locais[ind].nome_lugar;
            }
        }
        break;

    case 2:
        printf("Digite o novo Logradouro:  ");
        gets(straux);
        locais[ind].endereco.logradouro = (char *)malloc(strlen(straux) + 1);
        validarAlocacao(locais);
        strcpy(locais[ind].endereco.logradouro, straux);
        for (int i = 0; i < num_encontro; i++)
        {
            if (locais[ind].id == Encontros[i].local.id)
            {
                Encontros[i].local.endereco.logradouro = locais[ind].endereco.logradouro;
            }
        }
        break;

    case 3:
        do
        {
            printf("Digite o novo Numero:  ");
            scanf("%d", &locais[ind].endereco.num);
            fflush(stdin);
            if (locais[ind].endereco.num < 0)
            {
                printf("numero invalido\n");
                pausar();
            }
        } while ((locais[ind].endereco.num < 0));
        for (int i = 0; i < num_encontro; i++)
        {
            if (locais[ind].id == Encontros[i].local.id)
            {
                Encontros[i].local.endereco.num = locais[ind].endereco.num;
            }
        }
        break;

    case 4:
        printf("Digite o novo Bairro:  ");
        gets(straux);
        locais[ind].endereco.bairro = (char *)malloc(strlen(straux) + 1);
        validarAlocacao(locais);
        strcpy(locais[ind].endereco.bairro, straux);
        for (int i = 0; i < num_encontro; i++)
        {
            if (locais[ind].id == Encontros[i].local.id)
            {
                Encontros[i].local.endereco.bairro = locais[ind].endereco.bairro;
            }
        }
        break;

    case 5:
        printf("Digite a nova Cidade:  ");
        gets(straux);
        locais[ind].endereco.cidade = (char *)malloc(strlen(straux) + 1);
        validarAlocacao(locais);
        strcpy(locais[ind].endereco.cidade, straux);
        for (int i = 0; i < num_encontro; i++)
        {
            if (locais[ind].id == Encontros[i].local.id)
            {
                Encontros[i].local.endereco.cidade = locais[ind].endereco.cidade;
            }
        }
        break;

    case 6:
        printf("Digite o novo Estado:  ");
        gets(straux);
        locais[ind].endereco.bairro = (char *)malloc(strlen(straux) + 1);
        validarAlocacao(locais);
        strcpy(locais[ind].endereco.bairro, straux);
        for (int i = 0; i < num_encontro; i++)
        {
            if (locais[ind].id == Encontros[i].local.id)
            {
                Encontros[i].local.endereco.estado = locais[ind].endereco.estado;
            }
        }
        break;

    case 7:
        break;

    default:
        mensagem_de_erro(-5);
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
    for (int i = 0; i < num_encontro; i++)
    {
        if (locais[op].id == Encontros[i].local.id)
        {
            mensagem_de_erro(-13);
            pausar();
            return;
        }
    }
    if (op != -1)
    {
        for (int i = op; i < num_local; i++)
        {
            locais[i] = locais[i + 1];
        }
        num_local--;
        printf("local excluido!!\n\n");
        pausar();
    }
}

int opcao_excluir_local()
{
    int op;
    char aux;
    if (num_local == 0)
    {
        mensagem_de_erro(-2);
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
        mensagem_de_erro(-5);
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
        validarAlocacao(categorias);
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
        listar_categoria(categorias[i], i + 1);
    }
    pausar();
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
    if (num_categoria == 0)
    {
        mensagem_de_erro(-3);
        pausar();
        return;
    }
    do
    {
        listar_categorias();
        printf("Digite qual categoria voce deseja alterar\n");
        scanf("%d", &aux);
        if (aux < 0 || aux > num_categoria)
        {
            mensagem_de_erro(-5);
        }
    } while (aux < 0 || aux > num_categoria);

    printf("digite a nova categoria\n");
    gets(straux);
    categorias[aux].categoria = (char *)malloc((strlen(straux) + 1) * sizeof(char));
    validarAlocacao(categorias);
    strcpy(categorias[aux].categoria, straux);
    for (int i = 0; i < num_encontro; i++)
    {
        for (int j = 0; j < Encontros[i].num_categoria_encontro; j++)
        {
            if (categorias[aux].id == Encontros[i].categoria[j].id)
            {
                Encontros[i].categoria[j].categoria = categorias[aux].categoria;
            }
        }
    }
}

void excluir_categoria()
{
    int op = opcao_excluir_categoria();
    for (int i = 0; i < num_encontro; i++)
    {
        for (int j = 0; j < Encontros[i].num_categoria_encontro; j++)
        {
            if (categorias[op].id == Encontros[i].categoria[j].id)
            {
                mensagem_de_erro(-13);
                pausar();
                return;
            }
        }
    }
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
    system("cls");
    if (num_categoria == 0)
    {
        mensagem_de_erro(-3);
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
                mensagem_de_erro(-5);
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
        system("cls");
        listar_categoria(categorias[op], op + 1);
        printf("vc tem certeza em apagar essa categoria?(S ou N)");
        scanf("%c", &aux);
        fflush(stdin);
        aux = tolower(aux);
        if (aux != 's' && aux != 'n')
        {
            mensagem_de_erro(-5);
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
    arquivo = fopen("Jimmy_amigos.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    for (int i = 0; i < num_amigos; i++)
    {
        fprintf(arquivo, "%s;", amigos[i].nome);
        fprintf(arquivo, "%d;", amigos[i].data_nasc.dia);
        fprintf(arquivo, "%d;", amigos[i].data_nasc.mes);
        fprintf(arquivo, "%d;", amigos[i].data_nasc.ano);
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
    int i = 0, sep = 0;
    char straux[100], c;
    FILE *arquivo;
    arquivo = fopen("Jimmy_amigos.txt", "r");
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
                        if (num_amigos == 0)
                        {
                            amigos = (TAmigo *)malloc(1 * sizeof(TAmigo));
                        }
                        else
                        {
                            amigos = (TAmigo *)realloc(amigos, (num_amigos + 1) * sizeof(TAmigo));
                        }
                        validarAlocacao(amigos);
                        amigos[num_amigos].nome = (char *)malloc((strlen(straux) + 1) * sizeof(char));
                        strcpy(amigos[num_amigos].nome, straux);
                        sep++;
                    }
                    else if (sep == 1)
                    {
                        amigos[num_amigos].data_nasc.dia = atoi(straux);
                        sep++;
                    }
                    else if (sep == 2)
                    {
                        amigos[num_amigos].data_nasc.mes = atoi(straux);
                        sep++;
                    }
                    else if (sep == 3)
                    {
                        amigos[num_amigos].data_nasc.ano = atoi(straux);
                        sep++;
                    }
                    else if (sep == 4)
                    {
                        amigos[num_amigos].apelido = (char *)malloc((strlen(straux) + 1) * sizeof(char));
                        validarAlocacao(amigos);
                        strcpy(amigos[num_amigos].apelido, straux);
                        sep++;
                    }
                    else if (sep == 5)
                    {
                        amigos[num_amigos].email = (char *)malloc((strlen(straux) + 1) * sizeof(char));
                        validarAlocacao(amigos);
                        strcpy(amigos[num_amigos].email, straux);
                        sep++;
                    }
                    else if (sep == 6)
                    {
                        amigos[num_amigos].telefone = (char *)malloc((strlen(straux) + 1) * sizeof(char));
                        validarAlocacao(amigos);
                        strcpy(amigos[num_amigos].telefone, straux);
                        sep++;
                    }
                }
                else if (c == '\n')
                {
                    sep = 0;
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
    arquivo = fopen("Jimmy_locais.txt", "w");
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
    arquivo = fopen("Jimmylocais.txt", "r");
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
                        validarAlocacao(locais);
                        locais[i].nome_lugar = (char *)malloc((strlen(straux) + 1) * sizeof(char));
                        strcpy(locais[i].nome_lugar, straux);
                        sep++;
                    }
                    else if (sep == 1)
                    {
                        locais[i].endereco.logradouro = (char *)malloc((strlen(straux) + 1) * sizeof(char));
                        validarAlocacao(locais);
                        strcpy(locais[i].endereco.logradouro, straux);
                        sep++;
                    }
                    else if (sep == 2)
                    {
                        locais[i].endereco.bairro = (char *)malloc((strlen(straux) + 1) * sizeof(char));
                        validarAlocacao(locais);
                        strcpy(locais[i].endereco.bairro, straux);
                        sep++;
                    }
                    else if (sep == 3)
                    {
                        locais[i].endereco.cidade = (char *)malloc((strlen(straux) + 1) * sizeof(char));
                        validarAlocacao(locais);
                        strcpy(locais[i].endereco.cidade, straux);
                        sep++;
                    }
                    else if (sep == 4)
                    {
                        locais[i].endereco.estado = (char *)malloc((strlen(straux) + 1) * sizeof(char));
                        validarAlocacao(locais);
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
    arquivo = fopen("Jimmy_categorias.txt", "w");
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
    arquivo = fopen("Jimmycategorias.txt", "r");
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
                        validarAlocacao(categorias);
                        categorias[num_categoria].categoria = (char *)malloc((strlen(straux) + 1) * sizeof(char));
                        strcpy(categorias[num_categoria].categoria, straux);
                        sep++;
                    }
                    else if (sep == 1)
                    {
                        categorias[num_categoria].id = atoi(straux);
                        sep++;
                    }
                    else if (sep == 2)
                    {
                        categorias[num_categoria].num_encontro_categoria = atoi(straux);
                        sep++;
                    }
                }
                else if (c == '\n')
                {
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
        break;
    default:
        system("cls");
        mensagem_de_erro(-5);
        pausar();
        break;
    }
    return res;
}

void relatorio_amigo()
{
    int op, i;
    if (num_amigos == 0)
    {
        mensagem_de_erro(-1);
        pausar();
        return;
    }
    else if (num_amigos > 1)
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
                mensagem_de_erro(-5);
                pausar();
            }
            else
            {
                i--;
                listar_amigo(amigos[i], i);
                pausar();
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
    if (num_local == 0)
    {
        mensagem_de_erro(-2);
        pausar();
        return;
    }
    else if (num_local > 1)
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
                mensagem_de_erro(-5);
                pausar();
            }
            else
            {
                i--;
                listar_categoria(categorias[i], i + 1);
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
    if (num_categoria == 0)
    {
        mensagem_de_erro(-3);
        pausar();
        return;
    }
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
                mensagem_de_erro(-5);
                pausar();
            }
            else
            {
                i--;
                listar_categoria(categorias[i], i + 1);
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
    if (num_encontro == 0)
    {
        mensagem_de_erro(-4);
        pausar();
    }
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
                    mensagem_de_erro(-5);
                    pausar();
                }
                else
                {
                    listar_encontro(Encontros[i], i);
                }
            } while (i < 1 || i > num_encontro);
        }
        else
        {
            listar_encontros();
        }
    }
}

void relatorio_por_categoria()
{
    int op, indice;
    if (num_encontro == 0)
    {
        mensagem_de_erro(-4);
        pausar();
        return;
    }
    if (num_categoria > 1)
    {
        op = opcao_relatorio();
        if (op == 1)
        {
            printf("Qual categoria voce deseja listar seus encontros[%d-%d]?:  ", 1, num_categoria);
            scanf("%d", &indice);
            if (indice < 1 || indice > num_categoria)
            {
                mensagem_de_erro(-5);
                pausar();
                return;
            }
            listar_num_encontro_categoria(indice);
        }
        else
        {
            listar_num_encontro_categorias();
        }
    }
}

void listar_num_encontro_categorias()
{
    for (int i = 0; i < num_categoria; i++)
    {
        listar_num_encontro_categoria(i);
    }
}

void listar_num_encontro_categoria(int i)
{
    printf("[%d]Categoria pertence a %d encontros\n", i, categorias[i].num_encontro_categoria);
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
    salvar_arquivo_local();
    salvar_arquivo_categoria();
    salvar_arquivo_encontro();
}

void carregar_arquivos()
{
    carregar_arquivo_amigo();
    carregar_arquivo_categoria();
    carregar_arquivo_local();
    carregar_arquivo_encontro();
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
        opcao_alterar_encontro();
        break;

    case 3:
        excluir_encontro();
        break;

    case 4:
        break;

    default:
        mensagem_de_erro(-5);
        pausar();
        break;
    }

    return op;
}

void incluir_encontro()
{
    if (num_amigos < 1 || num_local < 1 || num_categoria < 1)
    {
        mensagem_de_erro(-15);
        pausar();
        return;
    }
    if (num_encontro == 0)
    {
        Encontros = (TEncontro *)malloc(1 * sizeof(TEncontro));
    }
    else
    {
        Encontros = (TEncontro *)realloc(Encontros, (num_encontro + 1) * sizeof(TEncontro));
    }
    validarAlocacao(Encontros);
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

    system("cls");
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
                mensagem_de_erro(-5);
                pausar();
            }
        } while (ind < 0 || ind >= num_amigos);

        for (int i = 0; i < encontro.num_amigos_encontro; i++)
        {
            if (encontro.amigos[i].id == amigos[ind].id)
            {
                mensagem_de_erro(-7);
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
        validarAlocacao(encontro.amigos);
        encontro.amigos[encontro.num_amigos_encontro] = amigos[ind];
        encontro.num_amigos_encontro++;

        do
        {
            printf("deseja adicionar outro amigo[S ou N]:  ");
            scanf("%c", &aju);
            aju = tolower(aju);
            fflush(stdin);
        } while (valida_sim_ou_nao(aju));

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
                mensagem_de_erro(-5);
                pausar();
            }
        } while (ind < 0 || ind >= num_categoria);

        for (int i = 0; i < encontro.num_categoria_encontro; i++)
        {
            if (encontro.categoria[i].id == categorias[ind].id)
            {
                mensagem_de_erro(-10);
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
        validarAlocacao(encontro.categoria);
        categorias[ind].num_encontro_categoria++;
        encontro.categoria[encontro.num_categoria_encontro] = categorias[ind];
        encontro.num_categoria_encontro++;

        do
        {
            printf("deseja adicionar outra categoria[S ou N]:  ");
            scanf("%c", &aju);
            aju = tolower(aju);
            fflush(stdin);
        } while (aju != 's' && aju != 'n');

        if (aju == 'n')
        {
            break;
        }
    }

    system("cls");
    printf("Digite a descricao do encontro\n\n");
    gets(straux);
    encontro.descricao = (char *)malloc((strlen(straux) + 1) * sizeof(char));
    validarAlocacao(encontro.descricao);
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
    system("cls");
    printf("-- Lista de amigos [%d] --\n\n", (num_amigos - encontro.num_amigos_encontro));
    for (int i = 0; i < num_amigos; i++)
    {
        int check = 1;
        for (int j = 0; j < encontro.num_amigos_encontro; j++)
        {
            if (encontro.amigos[j].id == amigos[i].id)
            {
                check = 0;
                break;
            }
        }
        if (check == 1)
        {
            listar_amigo(amigos[i], i);
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
            if (encontro.categoria[j].id != categorias[i].id)
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
        printf("Todos os amigos registrados estao no encontro\n");
        break;
    case -7:
        printf("Amigo ja adicionado ao encontro\n");
        break;
    case -8:
        printf("Amigos insuficientes\n");
        break;
    case -9:
        printf("Todas as categorias registradas estao no encontro\n");
        break;
    case -10:
        printf("Categoria ja adicionada ao encontro\n");
        break;
    case -11:
        printf("Categorias insuficientes\n");
        break;
    case -12:
        printf("Este amigo esta inserido em um encontro\n");
        printf("Retire-o do encontro antes de poder exclui-lo\n");
        break;
    case -13:
        printf("Este local esta inserido em um encontro\n");
        printf("Retire-o do encontro antes de poder exclui-lo\n");
        break;
    case -14:
        printf("Esta categoria esta inserida em um encontro\n");
        printf("Retire-a do encontro antes de poder exclui-la\n");
        break;
    case -15:
        printf("Dados insuficientes\n");
        break;
    case -16:
        printf("Erro ao alocar memoria\n");
    }
}

void listar_encontro(TEncontro encontro, int ind)
{
    printf("Encontro [%d]\n", ind);
    printf("Local %s\n", encontro.local.nome_lugar);
    printf("Amigos ");
    for (int i = 0; i < encontro.num_amigos_encontro; i++)
    {
        printf("%s ", encontro.amigos[i].nome);
    }
    printf("\nCategorias ");
    for (int i = 0; i < encontro.num_categoria_encontro; i++)
    {
        printf("%s ", encontro.categoria[i].categoria);
    }
    printf("\nHorario %d:%d\n", encontro.horario.hora, encontro.horario.minuto);
    printf("Data %d/%d/%d\n", encontro.data.dia, encontro.data.mes, encontro.data.ano);
    printf("Descricao %s\n\n", encontro.descricao);
}

void listar_encontros()
{
    for (int i; i < num_encontro; i++)
    {
        listar_encontro(Encontros[i], i);
    }
    pausar();
}

int opcao_excluir_encontro()
{
    int op, aju;
    char aux;
    if (num_encontro == 0)
    {
        mensagem_de_erro(-4);
        pausar();
        return -1;
    }
    if (num_encontro > 1)
    {
        do
        {
            listar_encontros();
            printf("qual encontro sera apagado?:  ");
            scanf("%d", &op);
            fflush(stdin);
            if (op < 1 || op >= num_encontro)
            {
                mensagem_de_erro(-5);
                pausar();
            }
            system("cls");
        } while (op < 1 || op > num_encontro);
        op--;
    }
    else
    {
        op = 0;
    }
    do
    {
        system("cls");
        listar_encontro(Encontros[op], op);
        printf("vc tem certeza em apagar esse encontro?(S ou N)");
        scanf("%c", &aux);
        fflush(stdin);
        aux = tolower(aux);
        aju = valida_sim_ou_nao(aux);
        if (aju == 1)
        {
            mensagem_de_erro(-5);
            pausar();
        }
        else if (aux == 'n')
        {
            return -1;
        }
    } while (aju == 1);
    return op;
}

void excluir_encontro()
{
    int op = opcao_excluir_encontro();
    if (op != -1)
    {
        for (int i = op; i < num_encontro; i++)
        {
            Encontros[i] = Encontros[i + 1];
        }
        num_encontro--;
        printf("encontro excluido!!\n\n");
        pausar();
    }
}

void opcao_alterar_encontro()
{
    int ind;
    if (num_encontro == 0)
    {
        mensagem_de_erro(-4);
        pausar();
        return;
    }
    if (num_encontro > 1)
    {
        do
        {
            listar_encontros();
            printf("Qual encontro voce deseja alterar: ");
            scanf("%d", &ind);
            fflush(stdin);
            if (ind < 0 || ind > num_encontro)
            {
                mensagem_de_erro(-5);
                pausar();
            }
            system("cls");
        } while (ind < 0 || ind > num_encontro);
    }
    else
    {
        ind = 0;
    }
    menu_alterar_encontro(ind);
}

void menu_alterar_encontro(int ind)
{
    int op;
    do
    {
        system("cls");
        printf("Menu alterar encontro\n\n");
        printf("1. Alterar data\n");
        printf("2. Alterar horario\n");
        printf("3. Alterar local\n");
        printf("4. Alterar amigos\n");
        printf("5. Alterar categorias\n");
        printf("6. Alterar descricao\n");
        printf("7. Alterar voltar\n\n");
        printf("Digite a opcao:  ");
        op = opcao_menu_alterar_encontro(ind);
    } while (op < 1 || op > 7);
}

int opcao_menu_alterar_encontro(int ind)
{
    int op, i;
    char straux[100];
    scanf("%d", &op);
    fflush(stdin);
    system("cls");
    switch (op)
    {
    case 1:
        printf("Digite a nova data: ");
        scanf("%d%d%d", &Encontros[ind].data.dia, &Encontros[ind].data.mes, &Encontros[ind].data.ano);
        fflush(stdin);
        break;

    case 2:
        printf("Digite o novo horario:  ");
        scanf("%d%d", &Encontros[ind].horario.hora, &Encontros[ind].horario.minuto);
        fflush(stdin);
        break;
    case 3:
        do
        {
            listar_locais();
            printf("Escolha o novo local [%d-%d]:  ", 1, num_local);
            scanf("%d", &i);
            fflush(stdin);
            if (i < 1 || i > num_local)
            {
                mensagem_de_erro(-5);
                pausar();
            }
        } while (i < 1 || i > num_local);
        i--;
        Encontros[ind].local = locais[i];
        locais[i].id = 1;
        break;
    case 4:
        menu_alterar_amigo_encontro(ind);
        break;
    case 5:
        menu_alterar_categoria_encontro(ind);
        break;
    case 6:
        printf("Digite a nova descricao:  ");
        gets(straux);
        Encontros[ind].descricao = (char *)malloc(strlen((straux) + 1) * sizeof(char));
        validarAlocacao(Encontros[ind].descricao);
        strcpy(Encontros[ind].descricao, straux);
        break;
    case 7:
        break;
    default:
        mensagem_de_erro(-5);
        pausar();
        break;
    }
    return op;
}

void menu_alterar_amigo_encontro(int ind)
{
    int op;
    do
    {
        system("cls");
        printf("Menu amigos do encontro\n\n");
        printf("1. incluir amigo ao encontro\n");
        printf("2. alterar amigo do encontro\n");
        printf("3. excluir amigo do encontro\n");
        printf("4. listar amigos do encontro\n");
        printf("5. voltar\n\n");
        printf("Digite a opcao:  ");
        op = opcao_menu_alterar_amigo_encontro(ind);
    } while (op < 1 || op > 5);
}

int opcao_menu_alterar_amigo_encontro(int ind)
{
    int op;
    scanf("%d", &op);
    fflush(stdin);
    system("cls");
    switch (op)
    {
    case 1:
        incluir_amigos_encontro(ind);
        break;
    case 2:
        alterar_amigos_encontro(ind);
        break;
    case 3:
        opcao_excluir_amigo_encontro(ind);
        break;
    case 4:
        listar_amigos_encontro(ind);
        break;
    case 5:
        break;
    default:
        mensagem_de_erro(-5);
        pausar();
        return 0;
        break;
    }
    return op;
}

void incluir_amigos_encontro(int ind)
{
    int index;
    if (Encontros[ind].num_amigos_encontro == num_amigos)
    {
        mensagem_de_erro(-6);
        pausar();
        return;
    }
    if (Encontros[ind].num_amigos_encontro < num_amigos - 1)
    {
        do
        {
            listar_amigos_nao_inclusos(Encontros[ind]);
            printf("Digite qual amigo deseja incluir:  ");
            scanf("%d", &index);
            if (index < 1 || index > num_amigos)
            {
                mensagem_de_erro(-5);
                pausar();
            }
        } while (index < 1 || index > num_amigos);
        for (int i = 0; i < Encontros[ind].num_amigos_encontro; i++)
        {
            if (Encontros[ind].amigos[i].id == amigos[index].id)
            {
                mensagem_de_erro(-7);
                pausar();
                return;
            }
        }
    }
    else
    {
        for (int i = 0; i < Encontros[ind].num_amigos_encontro; i++)
        {
            for (int j = 0; j < num_amigos; j++)
            {
                if (Encontros[ind].amigos[i].id != amigos[j].id)
                {
                    index = amigos[j].id;
                }
            }
        }
    }
    Encontros[ind].amigos = (TAmigo *)realloc(Encontros[ind].amigos, (Encontros[ind].num_amigos_encontro + 1) * sizeof(TAmigo));
    validarAlocacao(Encontros[ind].amigos);
    Encontros[ind].amigos[Encontros[ind].num_amigos_encontro] = amigos[index];
    Encontros[ind].num_amigos_encontro++;
}
void alterar_amigos_encontro(int ind)
{
    int ad, ret;
    system("cls");
    if (Encontros[ind].num_amigos_encontro == num_amigos)
    {
        mensagem_de_erro(-5);
        pausar();
        return;
    }
    if (Encontros[ind].num_amigos_encontro != 1)
    {
        listar_amigos_encontro(ind);
        printf("Qual amigo deseja retirar?:  ");
        scanf("%d", &ret);
        if (ret < 1 || ret > Encontros[ind].num_amigos_encontro)
        {
            mensagem_de_erro(-5);
            pausar();
            return;
        }
        ret--;
    }
    else
    {
        ret = 0;
    }
    if (Encontros[ind].num_amigos_encontro < (num_amigos - 1))
    {
        system("cls");
        listar_amigos_nao_inclusos(Encontros[ind]);
        printf("Qual amigo deseja adicionar no lugar?:  ");
        scanf("%d", &ad);
        if (ad < 1 || ad > num_amigos)
        {
            mensagem_de_erro(-5);
            pausar();
            return;
        }
        ad--;
        for (int i = 0; i < Encontros[ind].num_amigos_encontro; i++)
        {
            if (Encontros[ind].amigos[i].id == amigos[ad].id)
            {
                mensagem_de_erro(-7);
                pausar();
                return;
            }
        }
    }
    else
    {
        for (int i = 0; i < Encontros[ind].num_amigos_encontro; i++)
        {
            if (Encontros[ind].amigos[i].id != i + 1)
            {
                ad = i;
            }
        }
    }
    Encontros[ind].amigos[ret] = amigos[ad];
    system("cls");
    printf("Amigo substituido com sucesso");
    pausar();
}
void opcao_excluir_amigo_encontro(int ind)
{
    int index;
    if (Encontros[ind].num_amigos_encontro < 2)
    {
        mensagem_de_erro(-8);
        pausar();
        return;
    }
    if (Encontros[ind].num_amigos_encontro > 1)
    {
        listar_amigos_encontro(ind);
        printf("Qual amigo deseja excluir do encontro?:  ");
        scanf("%d", &index);
        if (index < 1 || index > Encontros[ind].num_amigos_encontro)
        {
            mensagem_de_erro(-5);
            pausar();
            return;
        }
    }
    else
    {
        index = 0;
    }
    excluir_amigos_encontro(ind);
    system("cls");
    printf("Amigo excluido com sucesso");
    pausar();
}
void excluir_amigos_encontro(int ind)
{
    for (int i; i < Encontros[ind].num_amigos_encontro; i++)
    {
        Encontros[ind].amigos[i] = Encontros[ind].amigos[i + 1];
    }
    Encontros[ind].num_amigos_encontro--;
}
void listar_amigos_encontro(int ind)
{
    for (int i = 0; i < Encontros[ind].num_amigos_encontro; i++)
    {
        printf("[%d]  %s(%s)\n", i + 1, Encontros[ind].amigos[i].nome, Encontros[ind].amigos[i].apelido);
    }
    pausar();
}

void menu_alterar_categoria_encontro(int ind)
{
    int op;
    do
    {
        printf("Menu categorias do encontro\n\n");
        printf("1. incluir categoria ao encontro\n");
        printf("2. alterar categoria do encontro\n");
        printf("3. excluir categoria do encontro\n");
        printf("4. listar categorias do encontro\n");
        printf("5. voltar\n\n");
        printf("Digite a opcao:  ");
        op = opcao_menu_alterar_categoria_encontro(ind);
    } while (op < 1 || op > 5);
}

int opcao_menu_alterar_categoria_encontro(int ind)
{
    int op;
    scanf("%d", &op);
    fflush(stdin);
    system("cls");
    switch (op)
    {
    case 1:
        incluir_categorias_encontro(ind);
        break;
    case 2:
        alterar_categorias_encontro(ind);
        break;
    case 3:
        opcao_excluir_categorias_encontro(ind);
        break;
    case 4:
        listar_categorias_encontro(ind);
        break;
    case 5:
        break;
    default:
        mensagem_de_erro(-5);
        pausar();
        return 0;
        break;
    }
    return op;
}

void incluir_categorias_encontro(int ind)
{
    int index;
    if (Encontros[ind].num_categoria_encontro == num_encontro)
    {
        mensagem_de_erro(-9);
        pausar();
        return;
    }
    if (Encontros[ind].num_categoria_encontro < num_categoria - 1)
    {
        do
        {
            listar_categorias_nao_inclusas(Encontros[ind]);
            printf("Digite qual categoria deseja incluir:  ");
            scanf("%d", &index);
            if (index < 1 || index > num_categoria)
            {
                mensagem_de_erro(-5);
                pausar();
            }
        } while (index < 1 || index > num_categoria);
        for (int i = 0; i < Encontros[ind].num_categoria_encontro; i++)
        {
            if (Encontros[ind].categoria[i].id == categorias[index].id)
            {
                mensagem_de_erro(-10);
                pausar();
                return;
            }
        }
    }
    else
    {
        for (int i = 0; i < Encontros[ind].num_categoria_encontro; i++)
        {
            for (int j = 0; j < num_categoria; j++)
            {
                if (Encontros[ind].categoria[i].id != categorias[j].id)
                {
                    index = categorias[j].id;
                }
            }
        }
    }

    categorias[index].num_encontro_categoria++;
    Encontros[ind].categoria = (TCategoria *)realloc(Encontros[ind].categoria, (Encontros[ind].num_categoria_encontro + 1) * sizeof(TCategoria));
    validarAlocacao(Encontros[ind].categoria);
    Encontros[ind].categoria[Encontros[ind].num_categoria_encontro] = categorias[index];
    Encontros[ind].num_categoria_encontro++;
}

void alterar_categorias_encontro(int ind)
{
    int ad, ret;
    system("cls");
    if (Encontros[ind].num_categoria_encontro == num_categoria)
    {
        mensagem_de_erro(-5);
        pausar();
        return;
    }
    if (Encontros[ind].num_categoria_encontro != 1)
    {
        listar_categorias_encontro(ind);
        printf("Qual categoria deseja retirar?:  ");
        scanf("%d", &ret);
        if (ret < 1 || ret > Encontros[ind].num_categoria_encontro)
        {
            mensagem_de_erro(-5);
            pausar();
            return;
        }
        ret--;
    }
    else
    {
        ret = 0;
    }
    if (Encontros[ind].num_categoria_encontro < (num_categoria - 1))
    {
        system("cls");
        listar_categorias_nao_inclusas(Encontros[ind]);
        printf("Qual categoria deseja adicionar no lugar?:  ");
        scanf("%d", &ad);
        if (ad < 1 || ad > num_categoria)
        {
            mensagem_de_erro(-5);
            pausar();
            return;
        }
        ad--;
        for (int i = 0; i < Encontros[ind].num_categoria_encontro; i++)
        {
            if (Encontros[ind].categoria[i].id == categorias[ad].id)
            {
                mensagem_de_erro(-10);
                pausar();
                return;
            }
        }
    }
    else
    {
        for (int i = 0; i < Encontros[ind].num_categoria_encontro; i++)
        {
            if (Encontros[ind].categoria[i].id != i + 1)
            {
                ad = i;
            }
        }
    }
    categorias[ad].num_encontro_categoria++;
    categorias[ret].num_encontro_categoria--;
    Encontros[ind].categoria[ret] = categorias[ad];
    system("cls");
    printf("Categoria substituida com sucesso");
    pausar();
}

void opcao_excluir_categorias_encontro(int ind)
{
    int index;
    if (Encontros[ind].num_categoria_encontro < 2)
    {
        mensagem_de_erro(-11);
        pausar();
        return;
    }
    if (Encontros[ind].num_categoria_encontro > 1)
    {
        listar_categorias_encontro(ind);
        printf("Qual categoria deseja excluir do encontro?:  ");
        scanf("%d", &index);
        if (index < 1 || index > Encontros[ind].num_categoria_encontro)
        {
            mensagem_de_erro(-5);
            pausar();
            return;
        }
    }
    else
    {
        index = 0;
    }
    excluir_categoria_encontro(ind, index);
    system("cls");
    printf("Categoria excluido com sucesso");
    pausar();
}

void listar_categorias_encontro(int ind)
{
    for (int i = 0; i < Encontros[ind].num_categoria_encontro; i++)
    {
        printf("Categoria [%d] %s\n\n", i + 1, Encontros[ind].categoria[i].categoria);
    }
}

void salvar_arquivo_encontro()
{
    FILE *arquivo;
    arquivo = fopen("Jimmy_encontros.txt", "w");
    for (int i = 0; i < num_encontro; i++)
    {
        fprintf(arquivo, "%d;", Encontros[i].data.dia);
        fprintf(arquivo, "%d;", Encontros[i].data.mes);
        fprintf(arquivo, "%d,", Encontros[i].data.ano);
        fprintf(arquivo, "%d;", Encontros[i].horario.hora);
        fprintf(arquivo, "%d;", Encontros[i].horario.minuto);
        for (int j = 0; j < Encontros[i].num_amigos_encontro; j++)
        {
            fprintf(arquivo, "%d,", Encontros[i].amigos[j].id);
        }
        fprintf(arquivo, "%d;", Encontros[i].local.id);
        for (int j = 0; j < Encontros[i].categoria[j].num_encontro_categoria; j++)
        {
            fprintf(arquivo, "%d:", Encontros[i].categoria[j].id);
        }
        fprintf(arquivo, "%s;", Encontros[i].descricao);
    }
    printf("arquivo salvo com sucesso\n");
    pausar();
    fclose(arquivo);
}

void carregar_arquivo_encontro()
{
    int i, sep = 0, id, aux = 0;
    char straux[100], c;
    FILE *arquivo;
    arquivo = fopen("Jimmyencontros.txt", "r");
    if (arquivo)
    {
        while (!feof(arquivo))
        {
            c = fgetc(arquivo);
            if (c != ';' && c != ',' && c != ':' && c != '\n' && c != EOF)
            {
                straux[i] = c;
                i++;
            }
            else if (c == ';' || c == ',' || c == ':' || c == '\n')
            {
                printf("funcionou");
                straux[i] = '\0';
                i = 0;
                if (c == ';')
                {
                    if (sep == 0)
                    {
                        printf("funcionou");
                        if (num_encontro == 0)
                        {
                            Encontros = (TEncontro *)malloc(1 * sizeof(TEncontro));
                        }
                        else
                        {
                            Encontros = (TEncontro *)realloc(Encontros, (num_encontro + 1) * sizeof(TEncontro));
                        }
                        validarAlocacao(Encontros);
                        Encontros[num_encontro].data.dia = atoi(straux);
                        sep++;
                        Encontros[num_encontro].num_amigos_encontro = 0;
                        Encontros[num_encontro].num_categoria_encontro = 0;
                        printf("funcionou");
                    }
                    else if (sep == 1)
                    {
                        Encontros[num_encontro].data.mes = atoi(straux);
                        sep++;
                        printf("funcionou");
                    }
                    else if (sep == 2)
                    {
                        Encontros[num_encontro].data.ano = atoi(straux);
                        sep++;
                        printf("funcionou");
                    }
                    else if (sep == 3)
                    {
                        Encontros[num_encontro].horario.hora = atoi(straux);
                        sep++;
                        printf("funcionou");
                    }
                    else if (sep == 4)
                    {
                        Encontros[num_encontro].horario.minuto = atoi(straux);
                        sep++;
                        printf("funcionou");
                    }
                    else if (sep == 5)
                    {
                        id = atoi(straux);
                        Encontros[num_encontro].local = locais[id];
                        sep++;
                        printf("funcionou");
                    }
                    else if (sep == 6)
                    {
                        Encontros[num_encontro].descricao = (char *)malloc((strlen(straux) + 1) * sizeof(char));
                        validarAlocacao(Encontros[num_encontro].descricao);
                        strcpy(Encontros[num_encontro].descricao, straux);
                        sep = 0;
                        printf("funcionou");
                    }
                }
            }
            else if (c == ',')
            {
                printf("funcionou");
                if (Encontros[num_encontro].num_amigos_encontro == 0)
                {
                    Encontros[num_encontro].amigos = (TAmigo *)malloc(1 * sizeof(TAmigo));
                }
                else
                {
                    Encontros[num_encontro].amigos = (TAmigo *)realloc(Encontros[num_encontro].amigos, (Encontros[num_encontro].num_amigos_encontro + 1) * sizeof(TAmigo));
                }
                validarAlocacao(Encontros[num_encontro].amigos);
                id = atoi(straux);
                aux = Encontros[num_encontro].num_amigos_encontro;
                printf("funcionou");

                Encontros[num_encontro].amigos[aux] = amigos[id];
                Encontros[num_encontro].num_amigos_encontro++;
            }
            else if (c == ':')
            {
                if (Encontros[num_encontro].num_categoria_encontro == 0)
                {
                    Encontros[num_encontro].categoria = (TCategoria *)malloc(1 * sizeof(TCategoria));
                }
                else
                {
                    Encontros[num_encontro].categoria = (TCategoria *)realloc(Encontros[num_encontro].categoria, (Encontros[num_encontro].num_categoria_encontro + 1) * sizeof(TCategoria));
                }
                validarAlocacao(Encontros[num_encontro].categoria);
                id = atoi(straux);
                aux = Encontros[num_encontro].num_categoria_encontro;

                Encontros[num_encontro].categoria[aux] = categorias[id];
                Encontros[num_encontro].num_categoria_encontro++;
            }
            else if (c == '\n')
            {
                sep = 0;
                num_encontro++;
            }
        }
    }
    fclose(arquivo);
}

void excluir_categoria_encontro(int ind, int indice)
{
    for (int i = indice; i < Encontros[ind].num_categoria_encontro; i++)
    {
        Encontros[ind].categoria[i] = Encontros[ind].categoria[i + 1];
    }
    Encontros[ind].num_categoria_encontro--;
    categorias[indice].num_encontro_categoria--;
}

void limpar_ponteiros()
{
    void limpar_ponteiros_amigos();
    void limpar_ponteiros_locais();
    void limpar_ponteiros_categorias();
    void limpar_ponteiros_encontros();
}
void limpar_ponteiros_amigos()
{
    for (int i = 0; i < num_amigos; i++)
    {
        free(amigos[i].nome);
        free(amigos[i].apelido);
        free(amigos[i].email);
    }
    free(amigos);
}

void limpar_ponteiros_locais()
{
    for (int i = 0; i < num_local; i++)
    {
        free(locais[i].nome_lugar);
        free(locais[i].endereco.bairro);
        free(locais[i].endereco.cidade);
        free(locais[i].endereco.estado);
        free(locais[i].endereco.logradouro);
    }
    free(locais);
}

void limpar_ponteiros_categorias()
{
    for (int i = 0; i < num_amigos; i++)
    {
        free(categorias[i].categoria);
    }
    free(categorias);
}

void limpar_ponteiros_encontros()
{
    for (int i = 0; i < num_amigos; i++)
    {
        free(Encontros[i].amigos);
        free(Encontros[i].categoria);
        free(Encontros[i].descricao);
    }
    free(Encontros);
}

void validarAlocacao(void *ptr){
    if(!ptr){
        mensagem_de_erro(-16);
        exit(1);
    }
}