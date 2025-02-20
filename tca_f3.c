#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <stdbool.h>
#define M 50
#define PAUSE                                                \
    printf("Presione qualquer tecla para continuar. . .\n"); \
    getchar();

typedef struct
{
    int dia;
    int mes;
    int ano;
} Tdata;

typedef struct
{
    char *nome;
    Tdata dt_nasc;
    char *apelido;
    char *email;
    char *telefone;
} Tamigo;

typedef struct
{
    char *logradouro;
    int num_end;
    char *bairro;
    char *cidade;
    char *estado;
} Tendereco;

typedef struct
{
    char *nm_lcl;
    Tendereco endereco;
} Tlocal;

typedef struct
{
    char *nome;
    int num_n;
} Tcategoria;

typedef struct
{
    int hora;
    int min;
} Thorario;

typedef struct
{
    Tdata data;
    Thorario horario;
    Tlocal local;
    Tamigo *amigo;
    int num_e_amigos;
    Tcategoria *categoria;
    int num_e_cat;

} Tencontro;
Tamigo *amigos;
int num_amigos = -1;
Tlocal *locais;
int num_locais = -1;
Tcategoria *categorias;
int num_cat = -1;
Tencontro *encontros;
int num_enc = -1;

// funcoes principais
void menu_princ();
void op_menu(int op);
void amigo();
void local();
void categoria();
void encontro();
void relatorio();
void instrucoes();

// menus
void menu_amigo();
void op_menu_amigo(int op);
void menu_local();
void op_menu_local(int op);
void menu_categoria();
void op_menu_cat(int op);
void menu_enc();
void op_menu_enc(int op);
void menu_relatorio();
void op_menu_relat(int op);

// sub_funcoes de amigo
void incluir_amigo();
void excluir_amigo();
void alterar_amigo();

// sub_funcoes de local
void incluir_local();
void excluir_local();
void alterar_local();

// sub_funcoes de categoria
void incluir_cat();
void excluir_cat();
void alterar_cat();

// sub_funcoes de encontro
void incluir_enc();
void excluir_enc();
void alterar_enc();

// sub_funcoes de relatorio
void listar_amigos();
void listar_locais();
void listar_categorias();
void listar_encontros();
void listar_p_cat();

// sub_funcoes criar
Tamigo cria_amigo();
Tlocal cria_local();
Tcategoria cria_categoria();
Tencontro cria_enc();

// sub funcoes criar_enc
Tdata pega_data(Tencontro e);
Thorario pega_hora(Tencontro e);
Tlocal pega_local(Tencontro e);
Tamigo pega_amigo();
Tcategoria pega_cat();

// sub funcoes verifica
void verifica_amigo_enc(Tamigo amigo);
void verifica_local_enc(Tlocal local);
bool compara_local(Tlocal local, Tlocal encontro);
void verifica_cat_enc(Tcategoria cat);
//  sub-funcoes listar_enc
void listar_e_amigos();
void listar_e_locais();
void listar_e_cat();

// sub-funcoes excluir amigo
void imprime_amigo(Tamigo a);
void reorganizar_amigo(int faixa);
void excluir_amigo_enc(Tamigo amigo);
void reorganizar_amigo_enc(int faixa);

// sub-funcoes excluir local
void imprime_local(Tlocal l);
void reorganizar_local(int faixa);

// sub-funcoes excluir cat
void imprime_cat(Tcategoria c);
void reorganizar_cat(int faixa);

// sub-funcoes excluir enc
void imprime_enc(Tencontro e);
void reorganizar_enc(int faixa);
void imprime_hora(Thorario hora);
void imprime_data(Tdata data);

// sub funcoes alterar amigo
int alterar_Faixa_a(int faixa);
int menuAlterarAtributoa();

// sub funcoes alterar local
int alterar_faixa_l(int faixa);
int menuAlterarAtributol();

// sub funcoes alterar cat
void alterar_faixa_c(int faixa);

// sub funcoes alterar enc
int alterar_faixa_e(int faixa);
int menuAlterarAtributoe();
void alterar_faixa_e_a(int faixa, int faixa2);
void alterar_faixa_e_l(int faixa);
void alterar_faixa_e_c(int faixa, int faixa2);

// funçoes de arquivos
void salva_arq_amigo();
void pega_arq_amigo();
void salva_arq_local();
void pega_arq_local();
void salva_arq_cat();
void pega_arq_cat();
void salva_arq_amigoenc();
void pega_arq_amigoenc();
void salva_arq_localenc();
void pega_arq_localenc();

// funcoes extras

bool verificadata(int dia, int mes, int ano);
bool verifica_hora(int hora, int min);
bool verifica_tel(char *telefone);
bool verifica_email(char *email);
bool verifica_num_end(int num_end);
bool validasimnao(char op);
int ano_bissexto(int ano);
void libera_memoria();
void erro_Mens(int erro);
void limpa_buffer(); // 82 funcoes

// a fazer

/*verificar se os dados (amigo, local, categoria, encontro) sao iguais
  verificar se os dados de cada um deles e igual
  fazer os arquivos
  encurtar a alocacao do encontro
  validacao do encontro se forem 2 dados iguais
  */

int main()
{
    int op = 0;
    setlocale(LC_ALL, "Portuguese");

    pega_arq_amigo();
    pega_arq_local();
    pega_arq_cat();
    pega_arq_amigoenc();
    pega_arq_localenc();

    while (op != 6)
    {
        system("cls");
        menu_princ();
        scanf("%d", &op);
        op_menu(op);
    }

    salva_arq_amigo();
    salva_arq_local();
    salva_arq_cat();
    salva_arq_amigoenc();
    salva_arq_localenc();

    libera_memoria();
    return 0;
}

void amigo()
{
    int op;
    menu_amigo();
    scanf("%d", &op);
    op_menu_amigo(op);
}

void local()
{
    int op;
    menu_local();
    scanf("%d", &op);
    op_menu_local(op);
}

void categoria()
{
    int op;
    menu_categoria();
    scanf("%d", &op);
    op_menu_cat(op);
}

void encontro()
{
    int op;
    menu_enc();
    scanf("%d", &op);
    op_menu_enc(op);
}

void relatorio()
{
    int op;
    menu_relatorio();
    scanf(" %d", &op);
    limpa_buffer();
    op_menu_relat(op);
}

// menus e ops
//[
void menu_princ()
{
    int cont = 0;
    if (cont == 1)
    {
        PAUSE
    }
    system("cls");
    printf("1 - amigo\n");
    printf("2 - local\n");
    printf("3 - categoria\n");
    printf("4 - encontro\n");
    printf("5 - relatorio\n");
    printf("6 - sair\n\n");
    printf("escolha uma opcao:\n");
    cont = 1;
}

void op_menu(int op)
{
    if (op < 1 || op > 6)
    {
        erro_Mens(0);
        return;
    }
    switch (op)
    {
    case 1:
        amigo();
        break;

    case 2:
        local();
        break;

    case 3:
        categoria();
        break;

    case 4:
        encontro();
        break;

    case 5:
        relatorio();
        break;

    case 6:
        printf("saindo");
        for (int i = 0; i < 3; i++)
        {

            printf(".");
            // Sleep(600);
        }

        break;
    }
}

void menu_amigo()
{
    system("cls");
    printf("\tMenu de Amigos:\n");
    printf("1 - incluir amigo:\n");
    printf("2 - excluir amigo:\n");
    printf("3 - alterar amigo:\n");
    printf("4 - voltar");
    printf("\nescolha uma opcao:\n");
}

void op_menu_amigo(int op)
{
    if (op < 1 || op > 4)
    {
        erro_Mens(0);
        return;
    }
    switch (op)
    {
    case 1:
        incluir_amigo();
        break;

    case 2:
        excluir_amigo();
        break;

    case 3:
        alterar_amigo();
        break;

    case 4:
        return;
        break;
    }
}

void menu_local()
{
    system("cls");
    printf("Menu de Locais:\n\n");
    printf("1 - incluir local:\n");
    printf("2 - excluir local:\n");
    printf("3 - alterar local:\n");
    printf("4 - voltar:\n");
    printf("\nescolha uma opcao:\n");
}
void op_menu_local(int op)
{
    if (op < 1 || op > 4)
    {
        erro_Mens(0);
        return;
    }
    switch (op)
    {
    case 1:
        incluir_local();
        break;

    case 2:
        excluir_local();
        break;

    case 3:
        alterar_local();
        break;

    case 4:
        return;
        break;
    }
}

void menu_categoria()
{
    system("cls");
    printf("Menu de categorias:\n\n");
    printf("1 - incluir categoria:\n");
    printf("2 - excluir categoria:\n");
    printf("3 - alterar categoria:\n");
    printf("4 - voltar:\n");
    printf("\nescolha uma opcao:\n");
}
void op_menu_cat(int op)
{
    if (op < 1 || op > 4)
    {
        erro_Mens(0);
        return;
    }
    switch (op)
    {
    case 1:
        incluir_cat();
        break;

    case 2:
        excluir_cat();
        break;

    case 3:
        alterar_cat();
        break;

    case 4:
        return;
        break;
    }
}

void menu_enc()
{
    system("cls");
    printf("Menu de encontros:\n\n");
    printf("1 - incluir encontro:\n");
    printf("2 - excluir encontro:\n");
    printf("3 - alterar encontro:\n");
    printf("4 - voltar:\n");
    printf("\nescolha uma opcao:\n");
}
void op_menu_enc(int op)
{
    if (op < 1 || op > 4)
    {
        erro_Mens(0);
        return;
    }
    switch (op)
    {
    case 1:
        incluir_enc();
        break;

    case 2:
        excluir_enc();
        break;

    case 3:
        alterar_enc();
        break;

    case 4:
        return;
        break;
    }
}

void menu_relatorio()
{
    system("cls");
    printf("Menu de relatorios:\n\n");
    printf("1 - listar amigos:\n");
    printf("2 - listar locais:\n");
    printf("3 - listar categorias:\n");
    printf("4 - listar encontros.\n");
    printf("5 - listar por categoria:\n");
    printf("6 - voltar:\n");
    printf("\nescolha uma opcao:\n");
}
void op_menu_relat(int op)
{
    if (op < 1 || op > 6)
    {
        erro_Mens(0);
        return;
    }
    switch (op)
    {
    case 1:
        listar_amigos();
        break;

    case 2:
        listar_locais();
        break;

    case 3:
        listar_categorias();
        break;

    case 4:
        listar_encontros();
        break;

    case 5:
        listar_p_cat();
        break;

    case 6:
        return;
        break;
    }
}
//] menus e ops

// funcoes amigo
//[
void incluir_amigo()
{
    Tamigo a;
    system("cls");
    printf("\tincluir amigo:\n");

    a = cria_amigo();

    if (num_amigos == -1)
    {
        num_amigos++;
    }
    if (num_amigos == 0)
    {
        amigos = malloc(1 * sizeof(Tamigo));
        amigos[0] = a;
    }
    else if (num_amigos > 0)
    {
        amigos = realloc(amigos, (num_amigos + 1) * sizeof(Tamigo));
        amigos[num_amigos] = a;
    }
    else
    {
        erro_Mens(-1);
    }
    num_amigos++;
}

void excluir_amigo()
{
    int faixa = -1, exc = 0;
    char op;
    system("cls");
    printf("\texcluir amigo\n");
    if (num_amigos <= 0)
    {
        erro_Mens(-18);
        return;
    }
    while (faixa < 0 || faixa >= num_amigos)
    {
        if (num_amigos == 1)
        {
            faixa = 0;
            op = 'b';
            while (op != 's' && op != 'n')
            {
                listar_amigos();
                printf("deseja excluir este amigo? (s/n): ");
                scanf(" %c", &op);

                limpa_buffer();
                op = tolower(op);
                if (!validasimnao(op))
                {
                    erro_Mens(-17);
                }
            }
            if (op == 's')
            {
                printf("entrou\n");
                verifica_amigo_enc(amigos[faixa]);

                reorganizar_amigo(faixa);
                exc = 1;
            }

            break;
        }
        else
        {
            listar_amigos();
            printf("digite a faixa que deseja excluir [%d - %d].\n", 1, num_amigos);
            scanf("%d", &faixa);
            limpa_buffer();
            printf("\n");
            faixa--;
            if ((faixa < 0) || (faixa >= num_amigos))
            {
                erro_Mens(-19);
            }
            else
            {
                op = 'b';
                while (!validasimnao(op))
                {
                    system("cls");
                    imprime_amigo(amigos[faixa]);
                    printf("\ndeseja excluir o amigo [%d]: (s/n): ", faixa + 1);
                    scanf("%c", &op);
                    limpa_buffer();
                    op = tolower(op);

                    if (!validasimnao(op))
                    {
                        erro_Mens(-17);
                    }
                }
                if (op == 's')
                {
                    // excluir_amigo_enc(amigos[faixa]);
                    verifica_amigo_enc(amigos[faixa]);
                    reorganizar_amigo(faixa);
                    break;
                }
                break;
            }
        }
    }

    if (exc)
    {
        system("cls");
        printf("exclusao bem sucedida!!!\n");

        PAUSE
    }
}

void alterar_amigo()
{
    printf("\taltera amigo\n");
    int faixa = -1, resp;

    if (num_amigos <= 0)
    {
        printf("Erro: nao tem amigos para alterar.\n");
        return;
    }

    while (faixa < 0 || faixa >= num_amigos)
    {
        listar_amigos();
        if (num_amigos > 1)
        {
            printf("digite o amigo que deseja alterar [1 - %d]", num_amigos);
            scanf("%d", &faixa);
            limpa_buffer();
            printf("\n");
        }
        else
        {
            faixa = 1;
        }

        faixa--;
        if (faixa < 0 || faixa >= num_amigos)
        {
            erro_Mens(-27);
        }
        else
        {
            resp = alterar_Faixa_a(faixa);
        }
    }
    system("cls");
    if (resp > 0)
    {
        imprime_amigo(amigos[faixa]);
    }

    PAUSE
}
int alterar_Faixa_a(int faixa)
{
    int atributo = 1;
    char op, straux[100];
    while (atributo > 0)
    {
        atributo = menuAlterarAtributoa();
        switch (atributo)
        {
        case 1:
            system("cls");
            printf("\tdados do amigo\n");
            imprime_amigo(amigos[faixa]);
            printf("\n Novo nome do Amigo: ");
            scanf(" %s", straux);
            amigos[faixa].nome = malloc((strlen(straux) + 1) * sizeof(char));
            strcpy(amigos[faixa].nome, straux);
            limpa_buffer();
            break;
        case 2:
            system("cls");
            printf("\tdados do amigo\n");
            imprime_amigo(amigos[faixa]);
            printf("\n Novo apelido do Amigo: ");
            scanf(" %s", straux);
            amigos[faixa].apelido = malloc((strlen(straux) + 1) * sizeof(char));
            strcpy(amigos[faixa].apelido, straux);
            limpa_buffer();
            break;
        case 3:
            system("cls");
            printf("\tdados do amigo\n");
            imprime_amigo(amigos[faixa]);
            printf("\n Novo email do Amigo: ");
            scanf(" %s", straux);
            amigos[faixa].email = malloc((strlen(straux) + 1) * sizeof(char));
            strcpy(amigos[faixa].email, straux);
            limpa_buffer();
            break;
        case 4:
            system("cls");
            printf("\tdados do amigo\n");
            imprime_amigo(amigos[faixa]);
            do
            {
                printf("\n Nova data de nascimento do Amigo: [DD/MM/AAAA]");
                scanf(" %d%d%d", &amigos[faixa].dt_nasc.dia, &amigos[faixa].dt_nasc.mes, &amigos[faixa].dt_nasc.ano);
            } while (!verificadata(amigos[faixa].dt_nasc.dia, amigos[faixa].dt_nasc.mes, amigos[faixa].dt_nasc.ano));
            limpa_buffer();
            break;
        case 5:
            system("cls");
            printf("\tdados do amigo\n");
            imprime_amigo(amigos[faixa]);
            printf("\n Novo telefone do Amigo: [ex: 41912345678]");
            scanf(" %s", amigos[faixa].telefone);
            verifica_tel(amigos[faixa].telefone);
            limpa_buffer();
            break;
        default:
            erro_Mens(-20);
            break;
        }
        op = 'b';
        while (!validasimnao(op))
        {
            printf("\nDeseja alterar outro atributo (s/n): ");
            scanf("%c", &op);
            limpa_buffer();
            op = tolower(op);
            if (!validasimnao(op))
            {
                erro_Mens(-17);
            }
        }
        if (op == 'n')
        {
            atributo = -1;
        }
        else
        {
            // return 1;
        }
    }
    return 0;
}

int menuAlterarAtributoa()
{
    int op = -1;

    while (op < 1 || op > 6)
    {
        system("cls");
        printf("alteracao do atributo do amigo.\n");
        printf("*** Digite o Codigo do Atributo a Alterar\n");
        printf(" - (1) Nome do amigo \n");
        printf(" - (2) apelido\n");
        printf(" - (3) email\n");
        printf(" - (4) data de nascimento\n");
        printf(" - (5) telefone\n");
        printf(" - (6) Voltar para Menu Anterior\n\n");
        printf(" ** Digite a Opcao: ");
        scanf("%d", &op);
        fflush(stdin);
        if (op < 1 || op > 6)
        {
            erro_Mens(-17);
        }
    }
    return op;
}
//]funcoes amigo

// funcoes local
//[
void incluir_local()
{

    Tlocal l;
    system("cls");
    printf("\tincluir local\n");

    l = cria_local();

    if (num_locais == -1)
    {
        num_locais++;
    }

    if (num_locais == 0)
    {
        locais = malloc(1 * sizeof(Tlocal));
        locais[0] = l;
    }
    else if (num_locais > 0)
    {
        locais = realloc(locais, (num_locais + 1) * sizeof(Tlocal));
        locais[num_locais] = l;
    }
    else
    {
        erro_Mens(-1);
    }
    num_locais++;
}

void excluir_local()
{

    int faixa = -1, exc = 0;
    char op;
    bool sn;
    system("cls");
    printf("\texcluir local\n");
    if (num_locais <= 0)
    {
        erro_Mens(-20);
        return;
    }
    while (faixa < 0 || faixa >= num_locais)
    {
        if (num_locais == 1)
        {
            faixa = 0;
            op = 'b';
            while (!validasimnao(op))
            {
                imprime_local(locais[faixa]);
                printf("deseja excluir este local? (s/n): ");
                scanf("%c", &op);
                limpa_buffer();
                op = tolower(op);
                sn = validasimnao(op);
                if (!sn)
                {
                    erro_Mens(-17);
                }
            }
            if (op == 's')
            {
                verifica_local_enc(locais[faixa]);
                reorganizar_local(faixa);
                exc = 1;
            }

            break;
        }
        else
        {
            listar_locais();
            printf("digite a faixa que deseja excluir [%d - %d].\n", 1, num_locais);
            scanf("%d", &faixa);
            limpa_buffer();
            printf("\n");
            faixa--;
            if ((faixa < 0) || (faixa >= num_locais))
            {
                erro_Mens(-19);
            }
            else
            {
                op = 'b';
                while (!validasimnao(op))
                {
                    system("cls");
                    imprime_local(locais[faixa]);
                    printf("\ndeseja excluir a faixa [%d]: (s/n)", faixa + 1);
                    scanf("%c", &op);
                    limpa_buffer();
                    op = tolower(op);
                    sn = validasimnao(op);
                    if (!sn)
                    {
                        erro_Mens(-17);
                    }
                }
                if (op == 's')
                {
                    verifica_local_enc(locais[faixa]);
                    reorganizar_local(faixa);
                    break;
                }
                break;
            }
        }
    }
    if (exc)
    {
        system("cls");
        printf("exclusao bem sucedida!!!\n");

        PAUSE
    }
}

void alterar_local()
{
    printf("\talterar local\n");
    int faixa = -1, resp;

    if (num_locais <= 0)
    {
        erro_Mens(-30);
        return;
    }

    while (faixa < 0 || faixa >= num_locais)
    {
        listar_locais();
        if (num_locais > 1)
        {
            printf("digite o numero do local que deseja alterar [1 - %d]", num_locais);
            scanf("%d", &faixa);
            limpa_buffer();
            printf("\n");
        }
        else
        {
            faixa = 1;
        }

        faixa--;
        if (faixa < 0 || faixa >= num_locais)
        {
            erro_Mens(-28);
        }
        else
        {
            resp = alterar_faixa_l(faixa);
        }
    }
    system("cls");
    if (resp > 0 && resp < 7)
    {
        imprime_local(locais[faixa]);
    }

    PAUSE
}
int alterar_faixa_l(int faixa)
{
    int atributo = 1, aux;
    char op, straux[100];
    bool sn = false;
    while (atributo > 0)
    {
        atributo = menuAlterarAtributol();
        switch (atributo)
        {
        case 1:
            system("cls");
            printf("\tdados do local");
            imprime_local(locais[faixa]);
            printf("\n Novo nome do local: ");
            scanf("%s", straux);
            locais[faixa].nm_lcl = malloc((strlen(straux) + 1) * sizeof(char));
            strcpy(locais[faixa].nm_lcl, straux);
            limpa_buffer();
            break;
        case 2:
            system("cls");
            printf("\tdados do local\n");
            imprime_local(locais[faixa]);
            printf("\n Novo logradouro do Local: ");
            scanf("%s", straux);
            locais[faixa].endereco.logradouro = malloc((strlen(straux) + 1) * sizeof(char));
            strcpy(locais[faixa].endereco.logradouro, straux);
            limpa_buffer();
            break;
        case 3:
            system("cls");
            printf("\tdados do local.\n");
            imprime_local(locais[faixa]);
            while (!sn)
            {
                printf("Novo numero de endereco do local: ");
                scanf("%d", &aux);
                sn = verifica_num_end(aux);
            }
            locais[faixa].endereco.num_end = aux;
            limpa_buffer();
            break;
        case 4:
            system("cls");
            printf("\t dados do local\n");
            imprime_local(locais[faixa]);
            printf("\n novo bairro do local ");
            scanf("%s", straux);
            locais[faixa].endereco.bairro = malloc((strlen(straux) + 1) * sizeof(char));
            strcpy(locais[faixa].endereco.bairro, straux);
            break;
        case 5:
            system("cls");
            printf("\t dados do local\n");
            imprime_local(locais[faixa]);
            printf("\n nova cidade do local ");
            scanf("%s", straux);
            locais[faixa].endereco.cidade = malloc((strlen(straux) + 1) * sizeof(char));
            strcpy(locais[faixa].endereco.cidade, straux);
            break;
        case 6:
            system("cls");
            printf("\t dados do local\n");
            imprime_local(locais[faixa]);
            printf("\n novo estado do local ");
            scanf("%s", straux);
            locais[faixa].endereco.estado = malloc((strlen(straux) + 1) * sizeof(char));
            strcpy(locais[faixa].endereco.estado, straux);
            break;

        case 7:
            return 0;
        default:
            erro_Mens(-20);
            break;
        }
        op = 'b';
        while (op != 's' && op != 'n')
        {
            printf("\ndeseja alterar outro atributo (s/n): ");
            scanf("%c", &op);
            limpa_buffer();
            op = tolower(op);
            sn = validasimnao(op);
            if (!sn)
            {
                erro_Mens(-17);
            }
        }
        if (op == 'n')
        {
            atributo = -1;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}
int menuAlterarAtributol()
{
    int op = -1;

    while (op < 1 || op > 7)
    {
        system("cls");
        printf("alteracao do atributo do local.\n");
        printf("*** digite o codigo do atributo que deseja alterar\n");
        printf("(1) Nome do local\n");
        printf("(2) Logradouro\n");
        printf("(3) numero de endereco\n");
        printf("(4) bairro\n");
        printf("(5) cidade\n");
        printf("(6) estado\n");
        printf("(7) valtar ao menu anterior\n");
        printf("\tdigite a opcao desejada:\n");
        scanf("%d", &op);
        limpa_buffer();
        if (op < 0 || op > 7)
        {
            erro_Mens(0);

            PAUSE
        }
    }
    return op;
}

//] funcoes local

// funcoes categoria
//[
void incluir_cat()
{
    char op;
    system("cls");
    printf("\tincluir categoria\n");

    if (num_cat == -1)
    {
        num_cat++;
    }
    if (num_cat == 0)
    {
        categorias = malloc(sizeof(Tcategoria));
    }
    else
    {
        categorias = realloc(categorias, (num_cat + 1) * sizeof(Tcategoria));
    }

    if (!categorias)
    {
        printf("Erro ao alocar memC3ria para categorias!\n");
        exit(1);
    }

    categorias[num_cat] = cria_categoria();

    printf("deseja incluir mais uma categoria (s/n).\n");
    scanf("%c", &op);
    limpa_buffer();
    op = tolower(op);
    bool sn = validasimnao(op);

    if (!sn)
    {
        erro_Mens(-17);
    }
    op = tolower(op);
    if (op == 's')
    {
        incluir_cat();
    }
}

void excluir_cat()
{
    int faixa = -1, exc = 0;
    char op = 'b';
    system("cls");
    printf("\texcluir categoria\n");
    if (num_cat <= 0)
    {
        erro_Mens(-20);
        return;
    }
    while (faixa <= 0 || faixa >= num_cat)
    {
        if (num_cat == 1)
        {
            while (!validasimnao(op))
            {
                listar_categorias();
                printf("\ndeseja excluir essa categoria? (s/n):\n");
                scanf("%c", &op);
                limpa_buffer();
                if (!validasimnao(op))
                {
                    erro_Mens(-17);
                }
            }
            if (op == 's')
            {
                verifica_cat_enc(categorias[faixa]);
                reorganizar_cat(faixa);
                exc = 1;
            }
            break;
        }

        else
        {
            listar_categorias();
            printf("digite a faixa que deseja excluir [%d - %d].\n", 1, num_cat);
            scanf("%d", &faixa);
            limpa_buffer();
            printf("\n");
            faixa--;
            if ((faixa < 0) || (faixa >= num_cat))
            {
                erro_Mens(-19);
            }
            else
            {
                op = 'b';
                while (!validasimnao(op))
                {
                    system("cls");
                    imprime_cat(categorias[faixa]);
                    printf("\ndeseja excluir a faixa [%d]: (s/n)\n", faixa + 1);
                    scanf("%c", &op);
                    limpa_buffer();
                    op = tolower(op);
                    if (!validasimnao(op))
                    {
                        erro_Mens(-17);
                    }
                }
                if (op == 's')
                {
                    verifica_cat_enc(categorias[faixa]);
                    reorganizar_cat(faixa);
                    break;
                }
                break;
            }
        }
    }
    if (exc)
    {
        system("cls");
        printf("exclusao bem sucedida!!!\n");

        PAUSE
    }
}

void alterar_cat()
{
    printf("\talterar categoria\n");
    int faixa = -1;
    bool sn;
    char op;
    if (num_cat <= 0)
    {
        erro_Mens(-31);
        return;
    }

    while (faixa < 0 || faixa >= num_cat)
    {
        while (1)
        {
            listar_categorias();
            if (num_cat > 1)
            {
                printf("digite o numero da categoria que deseja alterar [1 - %d]", num_cat);
                scanf("%d", &faixa);
                limpa_buffer();
                printf("\n");
            }
            else
            {
                faixa = 1;
            }
            faixa--;
            if (faixa < 0 || faixa >= num_cat)
            {
                erro_Mens(-32);
            }
            else
            {
                alterar_faixa_c(faixa);
            }
            system("cls");
            imprime_cat(categorias[faixa]);

            PAUSE

            while (op != 's' && op != 'n')
            {
                printf("\ndeseja alterar outra categoria (s/n)\n");
                scanf("%c", &op);
                limpa_buffer();
                op = tolower(op);
                sn = validasimnao(op);
                if (!sn)
                {
                    erro_Mens(-17);
                }
            }
            if (op == 'n')
            {
                break;
            }
        }
    }
}

void alterar_faixa_c(int faixa)
{
    char straux[100];
    int atributo = 1;

    while (atributo > 0)
    {
        system("cls");
        printf("alteracao do atributo do categoria.\n");
        printf("\t dados da categoria.\n");
        imprime_cat(categorias[faixa]);
        printf("\n Novo nome da categoria: ");
        scanf("%s", straux);
        categorias[faixa].nome = malloc((strlen(straux) + 1) * sizeof(char));
        strcpy(categorias[faixa].nome, straux);
        limpa_buffer();
        break;
    }
}
void incluir_enc()
{
    Tencontro e;
    system("cls");
    printf("\tincluir encontro\n");
    e = cria_enc();

    if (num_enc == -1)
    {
        num_enc++;
    }
    if (num_enc == 0)
    {
        encontros = malloc(1 * sizeof(Tencontro));
        encontros[0] = e;
    }
    else if (num_enc > 0)
    {
        encontros = realloc(encontros, (num_enc + 1) * sizeof(Tencontro));
        encontros[num_enc] = e;
    }
    else
    {
        erro_Mens(-1);
    }
    num_enc++;
}

void excluir_enc()
{
    int faixa = -1, exc = 0;
    char op = 'b';
    bool sn;
    system("cls");
    printf("\texcluir encontro\n");
    if (num_cat < 0)
    {
        erro_Mens(-37);

        PAUSE

        return;
    }
    while (faixa <= 0 || faixa >= num_enc)
    {
        if (num_enc == 1)
        {
            while (op != 's' && op != 'n')
            {
                listar_encontros();
                limpa_buffer();
                printf("\ndeseja excluir esse encontro? (s/n):\n");
                scanf(" %c", &op);
                limpa_buffer();
                op = tolower(op);
                sn = validasimnao(op);
                printf("%c", op);
                PAUSE
                if (!sn)
                {
                    erro_Mens(-17);
                }
            }
            if (op == 's')
            {
                reorganizar_enc(faixa);
                exc = 1;
            }
            break;
        }
        else
        {
            listar_encontros();
            printf("digite a faixa do encontro que deseja  excluir [%d - %d].\n", 1, num_enc);
            scanf("%d", &faixa);
            limpa_buffer();
            printf("\n");
            faixa--;
            if ((faixa < 0) || (faixa >= num_enc))
            {
                erro_Mens(-19);
            }
            else
            {
                op = 'b';
                while (!sn)
                {
                    system("cls");
                    imprime_enc(encontros[faixa]);
                    printf("\ndeseja excluir a faixa [%d]: (s/n)\n", faixa + 1);
                    scanf("%c", &op);
                    limpa_buffer();
                    op = tolower(op);
                    sn = validasimnao(op);
                    if (!sn)
                    {
                        erro_Mens(-17);
                    }
                }
                if (op == 's')
                {
                    reorganizar_enc(faixa);
                    exc = 1;
                    break;
                }
                break;
            }
        }
    }

    PAUSE

    if (exc)
    {
        system("cls");
        printf("exclusao bem sucedida!!!\n");

        PAUSE
    }
}

void alterar_enc()
{
    printf("\talterar encontro\n");
    int faixa = -1, resp;

    if (num_enc <= 0)
    {
        erro_Mens(-38);
        return;
    }
    else
    {
        while (faixa < 0 || faixa >= num_enc)
        {
            listar_encontros();
            if (num_enc > 2)
            {
                printf("digite o numero do encontro que deseja alterar [1 - %d].\n", num_enc);
                scanf(" %d", &faixa);
                limpa_buffer();
                printf("\n");
            }
            else
            {
                faixa = 1;
            }

            faixa--;
            if (faixa < 0 || faixa >= num_enc)
            {
                erro_Mens(-39);
            }
            else
            {
                resp = alterar_faixa_e(faixa);
            }
        }
        system("cls");
        if (resp > 0)
        {
            imprime_enc(encontros[faixa]);
        }

        PAUSE
    }
}

int alterar_faixa_e(int faixa)
{
    int atributo = 1, faixa2;
    char op;
    bool sn = false;
    while (atributo > 0)
    {
        atributo = menuAlterarAtributoe();
        switch (atributo)
        {
        case 1:
            if (encontros[faixa].num_e_amigos != 0)
            {
                printf("digite a faixa do amigo que deseja alterar de [1 - %d]", encontros[faixa].num_e_amigos);
                scanf("%d", &faixa2);
            }
            else
            {
                printf("voce so tem um amigo nesse encontro.\n");
                faixa2 = 0;

                PAUSE
            }

            alterar_faixa_e_a(faixa, faixa2);
            break;
        case 2:
            alterar_faixa_e_l(faixa); // fazer
            break;
        case 3:
            if (encontros[faixa].num_e_cat != 0)
            {
                printf("digite a faixa da categoria que deseja alterar de [1 - %d]", encontros[faixa].num_e_cat);
                scanf("%d", &faixa2);
            }
            else
            {
                printf("voce so tem uma categoria no encontro.\n");
                faixa2 = 0;

                PAUSE
            }

            alterar_faixa_e_c(faixa, faixa2);
            break;

        default:
            printf("erro!! faixa invalida, digite uma faixa entre 1 e 3");
            break;
        }
        op = 'b';
        while (op != 's' && op != 'n')
        {
            printf("\ndeseja alterar outro atributo (s/n): ");
            scanf("%c", &op);
            limpa_buffer();
            op = tolower(op);
            sn = validasimnao(op);
            if (!sn)
            {
                erro_Mens(-17);
            }
        }
        if (op == 'n')
        {
            atributo = -1;
        }
    }
    return 0;
}

int menuAlterarAtributoe()
{
    int op = -1;

    while (op < 1 || op > 3)
    {
        system("cls");
        printf("\tdigite o codigo do atributo que deseja alterar\n");
        printf("(1) Amigo\n");
        printf("(2) local\n");
        printf("(3) categoria\n");
        printf("\tdigite a opcao desejada\n");
        scanf("%d", &op);
        limpa_buffer();
        if (op < 0 || op > 3)
        {
            erro_Mens(0);
        }
    }
    return op;
}
void alterar_faixa_e_a(int faixa, int faixa2)
{
    int atributo;
    char straux[100], op;
    bool sn;
    while (!sn)
    {
        printf("voce esta tentando trocar o atributo de um amigo,\ndeseja trocar o atributo desse amigo lembrando que ira troca-lo na sua lista de amigos tambem? (s/n)\n");
        scanf(" %c", &op);
        limpa_buffer();
        op = tolower(op);
        sn = validasimnao(op);
    }
    while (atributo > 0)
    {
        atributo = menuAlterarAtributoa();

        switch (atributo)
        {
        case 1:
            system("cls");
            printf("\tdados do amigo\n");
            printf("(%d e %d)", faixa, faixa2);

            PAUSE

            imprime_amigo(encontros[faixa].amigo[faixa2]);
            printf("\n Novo nome do Amigo: ");
            scanf(" %s", straux);
            limpa_buffer();
            encontros[faixa].amigo[faixa2].nome = malloc((strlen(straux) + 1) * sizeof(char));
            strcpy(encontros[faixa].amigo[faixa2].nome, straux);
            limpa_buffer();
            break;
        case 2:
            system("cls");
            printf("\tdados do amigo\n");
            imprime_amigo(encontros[faixa].amigo[faixa2]);
            printf("\n Novo apelido do Amigo: ");
            scanf(" %s", straux);
            encontros[faixa].amigo[faixa2].apelido = malloc((strlen(straux) + 1) * sizeof(char));
            strcpy(encontros[faixa].amigo[faixa2].apelido, straux);
            limpa_buffer();
            break;
        case 3:
            system("cls");
            printf("\tdados do amigo\n");
            imprime_amigo(encontros[faixa].amigo[faixa2]);
            printf("\n Novo email do Amigo: ");
            scanf(" %s", straux);
            encontros[faixa].amigo[faixa2].email = malloc((strlen(straux) + 1) * sizeof(char));
            strcpy(encontros[faixa].amigo[faixa2].email, straux);
            limpa_buffer();
            break;
        case 4:
            system("cls");
            printf("\tdados do amigo\n");
            imprime_amigo(encontros[faixa].amigo[faixa2]);
            do
            {
                printf("\n Nova data de nascimento do Amigo: [DD/MM/AAAA]");
                scanf(" %d%d%d", &encontros[faixa].amigo[faixa2].dt_nasc.dia, &encontros[faixa].amigo[faixa2].dt_nasc.mes, &encontros[faixa].amigo[faixa2].dt_nasc.ano);
            } while (!verificadata(encontros[faixa].amigo[faixa2].dt_nasc.dia, encontros[faixa].amigo[faixa2].dt_nasc.mes, encontros[faixa].amigo[faixa2].dt_nasc.ano));
            limpa_buffer();
            break;
        case 5:
            system("cls");
            printf("\tdados do amigo\n");
            imprime_amigo(encontros[faixa].amigo[faixa2]);
            printf("\n Novo telefone do Amigo: [ex: 999999999]");
            scanf(" %s", encontros[faixa].amigo[faixa2].telefone);
            // verifica_tel(amigos[faixa].telefone);
            limpa_buffer();
            break;

        case 6:
            return;
        default:
            erro_Mens(-20);
            break;
        }
    }
}

void alterar_faixa_e_l(int faixa)
{
    int atributo, aux, i;
    char straux[100], op;
    bool sn;
    while (!sn)
    {
        printf("voce esta tentando trocar o atributo de um local,\ndeseja trocar o atributo desse local lembrando que ira troca-lo na sua lista de locais tambem? (s/n)\n");
        scanf(" %c", &op);
        limpa_buffer();
        op = tolower(op);
        sn = validasimnao(op);
    }
    while (atributo > 0)
    {
        atributo = menuAlterarAtributol();

        PAUSE

        switch (atributo)
        {
        case 1:
            system("cls");
            printf("\tdados do local");
            imprime_local(encontros[faixa].local);
            printf("\n Novo nome do local: ");
            scanf("%s", straux);
            encontros[faixa].local.nm_lcl = malloc((strlen(straux) + 1) * sizeof(char));
            strcpy(encontros[faixa].local.nm_lcl, straux);
            for (i = 0; i < num_locais; i++)
            {
                while (strcmp(encontros[faixa].local.nm_lcl, locais[i].nm_lcl) != 0)
                {
                    aux = i;
                    break;
                }
            }

            locais[aux].nm_lcl = malloc((strlen(straux) + 1) * sizeof(char));
            strcpy(locais[aux].nm_lcl, encontros[faixa].local.nm_lcl);
            limpa_buffer();
            break;
        case 2:
            system("cls");
            printf("\tdados do local\n");
            imprime_local(encontros[faixa].local);
            printf("\n Novo logradouro do Local: ");
            scanf("%s", straux);
            encontros[faixa].local.endereco.logradouro = malloc((strlen(straux) + 1) * sizeof(char));
            strcpy(encontros[faixa].local.endereco.logradouro, straux);
            for (i = 0; i < num_locais; i++)
            {
                while (strcmp(encontros[faixa].local.endereco.logradouro, locais[i].endereco.logradouro) != 0)
                {
                    aux = i;
                    break;
                }
            }

            locais[aux].endereco.logradouro = malloc((strlen(straux) + 1) * sizeof(char));
            strcpy(locais[aux].endereco.logradouro, encontros[faixa].local.endereco.logradouro);
            limpa_buffer();
            break;
        case 3:
            system("cls");
            printf("\tdados do local.\n");
            imprime_local(encontros[faixa].local);
            while (!sn)
            {
                printf("Novo numero de endereco do local: ");
                scanf("%d", &aux);
                sn = verifica_num_end(aux);
            }
            encontros[faixa].local.endereco.num_end = aux;
            for (i = 0; i < num_locais; i++)
            {
                while (encontros[faixa].local.endereco.num_end != locais[i].endereco.num_end)
                {
                    aux = i;
                    break;
                }
            }

            locais[aux].endereco.num_end = encontros[faixa].local.endereco.num_end;
            limpa_buffer();
            break;
        case 4:
            system("cls");
            printf("\t dados do local\n");
            imprime_local(encontros[faixa].local);
            printf("\n novo bairro do local ");
            scanf("%s", straux);
            encontros[faixa].local.endereco.bairro = malloc((strlen(straux) + 1) * sizeof(char));
            strcpy(encontros[faixa].local.endereco.bairro, straux);
            for (i = 0; i <= num_locais; i++)
            {
                while (strcmp(encontros[faixa].local.endereco.bairro, locais[i].endereco.bairro) != 0)
                {
                    aux = i;
                    break;
                }
            }
            locais[aux].endereco.bairro = malloc((strlen(straux) + 1) * sizeof(char));
            strcpy(locais[aux].endereco.bairro, encontros[faixa].local.endereco.bairro);
            break;
        case 5:
            system("cls");
            printf("\t dados do local\n");
            imprime_local(encontros[faixa].local);
            printf("\n nova cidade do local ");
            scanf("%s", straux);
            encontros[faixa].local.endereco.cidade = malloc((strlen(straux) + 1) * sizeof(char));
            strcpy(encontros[faixa].local.endereco.cidade, straux);
            for (i = 0; i < num_locais; i++)
            {
                while (strcmp(encontros[faixa].local.endereco.cidade, locais[i].endereco.cidade) != 0)
                {
                    aux = i;
                    break;
                }
            }
            locais[aux].endereco.cidade = malloc((strlen(straux) + 1) * sizeof(char));
            strcpy(locais[aux].endereco.cidade, encontros[faixa].local.endereco.cidade);
            break;
        case 6:
            system("cls");
            printf("\t dados do local\n");
            imprime_local(encontros[faixa].local);
            printf("\n novo estado do local ");
            scanf("%s", straux);
            encontros[faixa].local.endereco.estado = malloc((strlen(straux) + 1) * sizeof(char));
            strcpy(encontros[faixa].local.endereco.estado, straux);
            for (i = 0; i <= num_locais; i++)
            {
                while (strcmp(encontros[faixa].local.endereco.estado, locais[i].endereco.estado) != 0)
                {
                    aux = i;
                    break;
                }
            }
            locais[aux].endereco.estado = malloc((strlen(straux) + 1) * sizeof(char));
            strcpy(locais[aux].endereco.estado, encontros[faixa].local.endereco.estado);
            break;

        case 7:
            return;

        default:
            erro_Mens(-20);
            break;
        }
    }
}

void alterar_faixa_e_c(int faixa, int faixa2)
{
    char straux[100], op;
    bool sn;
    int i, aux;

    while (!sn)
    {
        printf("voce esta tentando trocar o nome de uma categoria,\ndeseja trocar o nome dessa categoria lembrando que ira troca-lo na sua lista de categorias tambem? (s/n)\n");
        scanf(" %c", &op);
        limpa_buffer();
        op = tolower(op);
        sn = validasimnao(op);
    }
    if (op == 's')
    {
        system("cls");
        printf("alteracao do atributo da categoria.\n");
        printf("\t dados da categoria.\n");
        imprime_cat(encontros[faixa].categoria[faixa2]);
        printf("\n Novo nome da categoria: ");
        scanf(" %s", straux);
        limpa_buffer();
        encontros[faixa].categoria[faixa2].nome = malloc((strlen(straux) + 1) * sizeof(char));
        strcpy(encontros[faixa].categoria[faixa2].nome, straux);
        for (i = 0; i <= num_cat; i++)
        {
            while (strcmp(encontros[faixa].categoria[faixa2].nome, categorias[i].nome) != 0)
            {
                aux = i;
                break;
            }
        }
        categorias[aux].nome = malloc((strlen(straux) + 1) * sizeof(char));
        strcpy(categorias[aux].nome, encontros[faixa].categoria[faixa2].nome);
        limpa_buffer();
    }
}

//] funcoes encontro

// funcoes relatorio
//[
void listar_amigos()
{
    system("cls");
    int i;
    if (num_amigos < 0)
    {
        erro_Mens(-34);

        PAUSE

        return;
    }

    printf("\tlistar amigos\n");

    for (i = 0; i < num_amigos; i++)
    {
        printf("nome do amigo.\n");
        puts(amigos[i].nome);

        printf("apelido do amigo.\n");
        puts(amigos[i].apelido);

        printf("email do amigo.\n");
        puts(amigos[i].email);

        printf("data de nascimento do amigo.\n");

        printf("%d/", amigos[i].dt_nasc.dia);
        printf("%d/", amigos[i].dt_nasc.mes);
        printf("%d\n", amigos[i].dt_nasc.ano);
        printf("numero de telefone do amigo.\n");
        puts(amigos[i].telefone);
        printf("pressione qualquer tecla para continuar. . .\n");
        getchar();
    }
}
void listar_locais()
{
    int i;
    system("cls");
    if (num_locais < 0)
    {
        erro_Mens(-35);

        PAUSE

        return;
    }
    printf("\tlistar locais\n");

    for (i = 0; i < num_locais; i++)
    {
        printf("nomes dos encontros:\n");
        puts(locais[i].nm_lcl);

        printf("nomes dos logradouro:\n");
        puts(locais[i].endereco.logradouro);

        printf("numeros de endereco:\n");
        printf("%d\n", locais[i].endereco.num_end);

        printf("nomes dos bairros:\n");

        puts(locais[i].endereco.bairro);

        printf("nomes das cidades:\n");
        puts(locais[i].endereco.cidade);

        printf("nomes dos estados:\n");
        puts(locais[i].endereco.estado);
    }

    PAUSE
}

void listar_categorias()
{
    int i;
    limpa_buffer();
    if (num_cat < 0)
    {
        erro_Mens(-16);

        PAUSE

        limpa_buffer();
        return;
    }

    printf("nomes.\n");
    for (i = 0; i < num_cat; i++)
    {
        puts(categorias[i].nome);
    }

    PAUSE
}
void listar_encontros()
{
    int i;
    system("cls");
    if (num_enc == 0)
    {
        erro_Mens(-36);

        PAUSE

        return;
    }

    printf("\nlistar encontros\n");

    for (i = 0; i < num_enc; i++)
    {
        printf("amigos:\n\n");
        listar_e_amigos();
        printf("saiu");
        PAUSE

        printf("locais:\n");
        listar_e_locais();

        PAUSE

        printf("categorias:");
        listar_e_cat();

        PAUSE
    }
}
void listar_p_cat()
{
    int i, j, k;

    printf("\tlistar por categoria\n");

    for (i = 0; i < num_enc; i++)
    {
        for (j = 0; j < num_enc - 1; j++)
        {
            for (k = 0; k < num_cat - j - 1; k++)
            {
                encontros[i].categoria[j].num_n = 0;
                if (strcmp(encontros[i].categoria[j].nome, encontros[i].categoria[k].nome) == 0)
                {
                    encontros[i].categoria[j].num_n++;
                }
            }
            printf("existem %d ", encontros[i].categoria[j].num_n);
            puts(encontros[i].categoria[j].nome);

            PAUSE
        }
    }

    PAUSE
}
Tamigo cria_amigo()
{
    Tamigo a;
    char straux[1000];
    bool sn = false;
    printf("digite o nome do amigo.\n");
    scanf("%s", straux);
    limpa_buffer();
    a.nome = malloc((strlen(straux)) + 1 * sizeof(char));
    strcpy(a.nome, straux);

    printf("digite o apelido do amigo.\n");
    scanf("%s", straux);
    limpa_buffer();
    a.apelido = malloc((strlen(straux)) + 1 * sizeof(char));
    strcpy(a.apelido, straux);

    while (!sn)
    {
        printf("digite o email do amigo.\n");
        scanf("%s", straux);
        limpa_buffer();

        sn = verifica_email(straux);
    }

    a.email = malloc((strlen(straux)) + 1 * sizeof(char));
    strcpy(a.email, straux);

    do
    {

        printf("digite a data de nascimento do amigo (formato DD MM AAAA).\n");
        scanf("%d%d%d", &a.dt_nasc.dia, &a.dt_nasc.mes, &a.dt_nasc.ano);
        limpa_buffer();

    } while (!verificadata(a.dt_nasc.dia, a.dt_nasc.mes, a.dt_nasc.ano));

    sn = false;
    while (!sn)
    {
        printf("digite o telefone do amigo. (ex 41912345678)\n");
        scanf("%s", straux);
        limpa_buffer();

        sn = verifica_tel(straux);
    }
    a.telefone = malloc((strlen(straux) + 1) * sizeof(char));
    strcpy(a.telefone, straux);

    return a;
}

Tlocal cria_local()
{
    Tlocal l;
    int aux = 0;
    char straux[1000];
    bool sn;

    printf("digite o nome do local.\n");
    scanf("%s", straux);
    limpa_buffer();
    l.nm_lcl = malloc((strlen(straux)) + 1 * sizeof(char));
    strcpy(l.nm_lcl, straux);

    printf("digite o logradouro do local.\n");
    scanf("%s", straux);
    limpa_buffer();
    l.endereco.logradouro = malloc((strlen(straux)) + 1 * sizeof(char));
    strcpy(l.endereco.logradouro, straux);

    while (!sn)
    {
        printf("digite o numero do endereco do local.\n");
        scanf("%d", &aux);
        limpa_buffer();
        sn = verifica_num_end(aux);
    }
    l.endereco.num_end = aux;

    printf("digite o bairro do local.\n");
    scanf("%s", straux);
    limpa_buffer();
    l.endereco.bairro = malloc((strlen(straux)) + 1 * sizeof(char));
    strcpy(l.endereco.bairro, straux);

    printf("digite a cidade do local.\n");
    scanf("%s", straux);
    limpa_buffer();
    l.endereco.cidade = malloc((strlen(straux)) + 1 * sizeof(char));
    strcpy(l.endereco.cidade, straux);

    printf("digite o estado do local.\n");
    scanf("%s", straux);
    limpa_buffer();
    l.endereco.estado = malloc((strlen(straux)) + 1 * sizeof(char));
    strcpy(l.endereco.estado, straux);

    return l;
}
Tcategoria cria_categoria()
{
    Tcategoria c;
    char straux[1000];
    c.nome = NULL;

    printf("Digite o nome da categoria:\n");
    scanf(" %s", straux);
    limpa_buffer();
    c.nome = malloc((strlen(straux) + 1) * sizeof(char));
    strcpy(c.nome, straux);
    num_cat++;
    return c;
}

Tencontro cria_enc()
{
    Tencontro e;
    char op;
    bool sn;
    e.num_e_amigos = 0;
    e.num_e_cat = 0;
    /*if(Nuamigo == 0){
    incuiamigo();
    CLS
    encontro.amigos[0] = Listaamigo[Numamigo];
    }*/
    if (num_amigos < 0 || num_locais < 0 || num_cat < 0)
    {
        printf("nao tem dados suficientes para concluir a inclusao do encontro. \n");

        if (num_amigos < 0)
        {
            printf("nao tem amigos para por no encontro. \n");
        }
        else if (num_locais < 0)
        {
            printf("nao tem locais para por no encontro. \n");
        }
        else if (num_cat < 0)
        {
            printf("nao tem categorias para por no encontro. \n");
        }
        PAUSE
    }
    else
    {
        e.data = pega_data(e);

        e.horario = pega_hora(e);

        e.local = pega_local(e);

        PAUSE

        while (1)
        {
            if (e.num_e_amigos == 0)
            {
                e.amigo = malloc(1 * sizeof(Tamigo));
            }
            else
            {
                e.amigo = realloc(e.amigo, (e.num_e_amigos + 1) * sizeof(Tamigo));
            }

            e.amigo[e.num_e_amigos] = pega_amigo();
            op = 'b';
            printf("inclusao de amigo bem sucedida!!.\n");

            while (op != 's' && op != 'n')
            {
                printf("deseja incluir mais um amigo no encontro? (s/n)");
                scanf(" %c", &op);
                limpa_buffer();
                printf("%c", op);
                op = tolower(op);
                sn = validasimnao(op);
                if (!sn)
                {
                    erro_Mens(-17);
                }
            }
            e.num_e_amigos++;
            if (op == 'n')
            {
                break;
            }
        }
        op = 'b';
        while (op != 'n')
        {
            if (e.num_e_cat == 0)
            {
                e.categoria = malloc(1 * sizeof(Tcategoria));
            }
            else
            {
                e.categoria = realloc(e.categoria, e.num_e_cat * sizeof(Tcategoria));
            }

            e.categoria[e.num_e_cat] = pega_cat();
            op = 'b';
            while (op != 's' && op != 'n')
            {
                printf("deseja incluir mais uma categoria no encontro? (s/n)");
                scanf("%c", &op);
                limpa_buffer();
                op = tolower(op);
                sn = validasimnao(op);
                if (!sn)
                {
                    erro_Mens(-17);
                }
            }
            if (op == 'n')
            {
                break;
            }
            e.num_e_cat++;

            PAUSE
        }

        return e;
    }
}

Tdata pega_data(Tencontro e)
{

    printf("digite a data do encontro.\nformato(DD MM AAAA)\n");
    scanf("%d%d%d", &e.data.dia, &e.data.mes, &e.data.ano);
    limpa_buffer();
    verificadata(e.data.dia, e.data.mes, e.data.ano);

    return e.data;
}

Thorario pega_hora(Tencontro e)
{
    bool sn;
    while (!sn)
    {
        printf("digite o horario do encontro.\n(formato Hr Min)\n");
        scanf("%d%d", &e.horario.hora, &e.horario.min);
        limpa_buffer();
        sn = verifica_hora(e.horario.hora, e.horario.min);
    }

    return e.horario;
}

Tlocal pega_local(Tencontro e)
{
    int i, aux = -1;
    char straux[1000];
    listar_locais();

    while (aux == -1)
    {
        printf("Digite o nome do local.\n");
        scanf(" %s", straux);
        limpa_buffer();
        for (i = 0; i < num_locais; i++)
        {

            if (strcmp(straux, locais[i].nm_lcl) == 0)
            {
                aux = i;
                break;
            }
        }
        if (aux == -1)
        {
            erro_Mens(-5);
        }
    }

    e.local.nm_lcl = malloc((strlen(straux) + 1) * sizeof(char));
    strcpy(e.local.nm_lcl, straux);

    aux = -1;

    while (aux == -1)
    {
        printf("Digite o logradouro do local do encontro.\n");
        scanf("%s", straux);
        limpa_buffer();
        for (i = 0; i < num_locais; i++)
        {

            if (strcmp(straux, locais[i].endereco.logradouro) == 0)
            {
                aux = i;
                break;
            }
        }
        if (aux == -1)
        {
            erro_Mens(-6);
        }
    }

    e.local.endereco.logradouro = malloc((strlen(straux) + 1) * sizeof(char));
    strcpy(e.local.endereco.logradouro, straux);

    aux = -1;

    while (aux == -1)
    {
        printf("Digite o nC:mero do endereco do local do encontro.\n");
        scanf("%d", &e.local.endereco.num_end);
        limpa_buffer();
        for (i = 0; i < num_locais; i++)
        {
            if (e.local.endereco.num_end == locais[i].endereco.num_end)
            {
                aux = i;
                break;
            }
        }
    }
    if (aux == -1)
    {
        erro_Mens(-7);
    }

    aux = -1;

    while (aux == -1)
    {
        printf("Digite o bairro do local.\n");
        scanf("%s", straux);
        limpa_buffer();
        for (i = 0; i < num_locais; i++)
        {

            if (strcmp(straux, locais[i].endereco.bairro) == 0)
            {
                aux = i;
                break;
            }
        }
        if (aux == -1)
        {
            erro_Mens(-8);
        }
    }

    e.local.endereco.bairro = malloc((strlen(straux) + 1) * sizeof(char));
    strcpy(e.local.endereco.bairro, straux);

    aux = -1;

    while (aux == -1)
    {
        printf("Digite a cidade do encontro.\n");
        scanf("%s", straux);
        limpa_buffer();

        for (i = 0; i < num_locais; i++)
        {

            if (strcmp(straux, locais[i].endereco.cidade) == 0)
            {
                aux = i;
                break;
            }
        }
        if (aux == -1)
        {
            erro_Mens(-9);
        }
    }

    e.local.endereco.cidade = malloc((strlen(straux) + 1) * sizeof(char));
    strcpy(e.local.endereco.cidade, straux);

    aux = -1;

    while (aux == -1)
    {
        printf("Digite o estado do local.\n");
        scanf("%s", straux);
        limpa_buffer();
        for (i = 0; i < num_locais; i++)
        {

            if (strcmp(straux, locais[i].endereco.estado) == 0)
            {
                aux = i;
                break;
            }
        }
        if (aux == -1)
        {
            erro_Mens(-10);
        }
    }

    e.local.endereco.estado = malloc((strlen(straux) + 1) * sizeof(char));
    strcpy(e.local.endereco.estado, straux);

    return e.local;
}

Tamigo pega_amigo()
{
    int i, aux = -1;
    char straux[1000];
    Tamigo amigo;
    system("cls");
    listar_amigos();

    while (aux == -1)
    {
        printf("Digite o nome do amigo.\n");
        scanf("%s", straux);
        limpa_buffer();
        for (i = 0; i < num_amigos; i++)
        {
            if (strcmp(straux, amigos[i].nome) == 0)
            {
                aux = i;
                break;
            }
        }
        if (aux == -1)
        {
            erro_Mens(-11);
        }
    }

    amigo.nome = malloc((strlen(straux) + 1) * sizeof(char));
    if (!amigo.nome)
    {
        printf("erro na criacao do nome do amigo!!");
        exit(1);
    }
    strcpy(amigo.nome, straux);

    aux = -1;

    while (aux == -1)
    {
        printf("Digite o apelido do amigo.\n");
        scanf("%s", straux);
        limpa_buffer();
        for (i = 0; i < num_amigos; i++)
        {
            if (strcmp(straux, amigos[i].apelido) == 0)
            {
                aux = i;
                break;
            }
        }
        if (aux == -1)
        {
            erro_Mens(-12);
        }
    }

    amigo.apelido = malloc((strlen(straux) + 1) * sizeof(char));
    strcpy(amigo.apelido, straux);

    if (!amigo.apelido)
    {
        printf("erro ao criar o encontro.\n");
        exit(1);
    }

    aux = -1;
    while (aux == -1)
    {
        printf("Digite o email do amigo.\n");
        scanf("%s", straux);
        limpa_buffer();
        aux = -1;
        for (i = 0; i < num_amigos; i++)
        {
            if (strcmp(straux, amigos[i].email) == 0)
            {
                aux = i;
                break;
            }
        }
        if (aux == -1)
        {
            erro_Mens(-13);
        }
    }

    amigo.email = malloc((strlen(straux) + 1) * sizeof(char));
    strcpy(amigo.email, straux);

    aux = -1;

    while (aux == -1)
    {
        printf("Digite a data de nascimento do amigo (formato DD MM AAAA).\n");
        scanf("%d%d%d", &amigo.dt_nasc.dia, &amigo.dt_nasc.mes, &amigo.dt_nasc.ano);
        limpa_buffer();

        if (!verificadata(amigo.dt_nasc.dia, amigo.dt_nasc.mes, amigo.dt_nasc.ano))
        {
            continue;
        }
        for (i = 0; i < num_amigos; i++)
        {
            if (amigo.dt_nasc.dia == amigos[i].dt_nasc.dia && amigo.dt_nasc.mes == amigos[i].dt_nasc.mes && amigo.dt_nasc.ano == amigos[i].dt_nasc.ano)
            {
                aux = i;
                break;
            }
        }
        if (aux == -1)
        {
            erro_Mens(-14);
        }
    }

    aux = -1;
    while (aux == -1)
    {
        printf("Digite o telefone do amigo.\n");
        scanf("%s", straux);
        limpa_buffer();
        aux = -1;
        for (i = 0; i < num_amigos; i++)
        {
            if (strcmp(straux, amigos[i].telefone) == 0)
            {
                aux = i;
                break;
            }
        }
        if (aux == -1)
        {
            erro_Mens(-15);
        }
    }
    amigo.telefone = (char *)malloc((strlen(straux) + 1) * sizeof(char));
    strcpy(amigo.telefone, straux);
    return amigo;
}

Tcategoria pega_cat()
{
    int i, aux = -1;
    char straux[1000];
    Tcategoria categoria;
    listar_categorias();

    while (aux == -1)
    {
        printf("Digite o nome da categoria.\n");
        scanf("%s", straux);
        limpa_buffer();

        for (i = 0; i < num_cat; i++)
        {

            if (strcmp(straux, categorias[i].nome) == 0)
            {

                aux = i;
                break;
            }
        }

        if (aux == -1)
        {
            erro_Mens(-16);
        }
    }
    categoria.nome = malloc((strlen(straux) + 1) * sizeof(char));
    strcpy(categoria.nome, straux);
    return categoria;
}

void listar_e_amigos()
{
    int i, j;

    if (num_enc < 0)
    {
        printf("Numero de encontros invalido.\n");
        return;
    }

    for (i = 0; i < num_enc; i++)
    {
        for (j = 0; j < encontros[i].num_e_amigos; j++)
        {
            printf("amigo %d:\n\n", j + 1);
            printf("------------------------------------\n");
            puts(encontros[i].amigo[j].nome);
            puts(encontros[i].amigo[j].apelido);
            puts(encontros[i].amigo[j].email);
            printf("%d/%d/%d.\n", encontros[i].amigo[j].dt_nasc.dia, encontros[i].amigo[j].dt_nasc.mes, encontros[i].amigo[j].dt_nasc.ano);
            puts(encontros[i].amigo[j].telefone);
            printf("------------------------------------\n");
        }
    }
}

void listar_e_locais()
{
    int i;
    for (i = 0; i < num_enc; i++)
    {
        puts(encontros[i].local.nm_lcl);
        puts(encontros[i].local.endereco.logradouro);
        printf("%d.\n", encontros[i].local.endereco.num_end);
        puts(encontros[i].local.endereco.bairro);
        puts(encontros[i].local.endereco.cidade);
        puts(encontros[i].local.endereco.estado);
    }
}

void listar_e_cat()
{
    int i;
    printf("\n");
    for (i = 0; i < num_enc; i++)
    {
        for (int j = 0; j <= encontros[i].num_e_cat; j++)
        {
            puts(encontros[i].categoria[j].nome);
        }
    }
}

// funcoes excluir amigo
//[
void reorganizar_amigo(int faixa)
{
    int i;
    for (i = faixa; i < (num_amigos - 1); i++)
    {
        amigos[i] = amigos[i + 1];
    }
    num_amigos--;
}
void imprime_amigo(Tamigo a)
{
    printf("nome:\n");
    puts(a.nome);
    printf("apelido:\n");
    puts(a.apelido);
    printf("email:\n");
    puts(a.email);
    printf("data de nascimento:\n");
    printf("%2d%2d%4d", a.dt_nasc.dia, a.dt_nasc.mes, a.dt_nasc.ano);
    printf("telefone:\n");
    puts(a.telefone);
}

void reorganizar_amigo_enc(int faixa)
{
    int i, j;
    for (i = 0; i < num_enc; i++)
    {
        for (j = faixa; j < (encontros[i].num_e_amigos - 1); j++)
        {
            encontros[i].amigo[j] = encontros[i].amigo[j + 1];
        }
    }
    encontros[i].num_e_amigos--;
}

// funcoes excluir local
//[
void reorganizar_local(int faixa)
{
    int i;
    for (i = faixa; i < (num_locais - 1); i++)
    {
        locais[i] = locais[i + 1];
    }
    num_locais--;
}
void imprime_local(Tlocal l)
{
    printf("nome do encontro:\n");
    puts(l.nm_lcl);
    printf("logradouro:\n");
    puts(l.endereco.logradouro);
    printf("numero do endereco:\n");
    printf("%d", l.endereco.num_end);
    printf("bairro:\n");
    puts(l.endereco.bairro);
    printf("cidade:\n");
    puts(l.endereco.cidade);
    printf("estado:\n");
    puts(l.endereco.estado);
}
//]
// funcoes excluir cat
//[

void reorganizar_cat(int faixa)
{
    int i;
    for (i = faixa; i < (num_cat - 1); i++)
    {
        categorias[i] = categorias[i + 1];
    }
    num_cat--;
}
void imprime_cat(Tcategoria c)
{
    printf("categoria do encontro:\n");
    puts(c.nome);
}

void imprime_hora(Thorario hora)
{
    printf("horas:\n%d\n", hora.hora);
    printf("minutos:\n%d\n", hora.min);
}
void imprime_data(Tdata data)
{
    printf("data:\n");
    printf("%d/%d/%d", data.dia, data.mes, data.ano);
}
void imprime_enc(Tencontro e)
{

    imprime_hora(e.horario);
    imprime_data(e.data);
    imprime_amigo(e.amigo[e.num_e_amigos]);
    imprime_local(e.local);
    imprime_cat(e.categoria[e.num_e_cat]);
}
void reorganizar_enc(int faixa)
{
    int i;
    for (i = faixa; i < (num_enc - 1); i++)
    {
        encontros[i] = encontros[i + 1];
    }
    num_enc--;
}

void pega_arq_amigo()
{
    FILE *file;
    char straux[500];
    char *nome, *apelido, *email, *dndia, *dnmes, *dnano, *tel;

    file = fopen("amigo.txt", "r");
    if (!file)
    {
        printf("Erro ao abrir o arquivo.\n");
        getchar();
        return;
    }

    printf("Arquivo aberto com sucesso!\n");
    if (num_amigos < 0)
    {
        num_amigos++;
    }
    while (fgets(straux, sizeof(straux), file) != NULL)
    {
        if (num_amigos == 0)
        {
            amigos = malloc(1 * sizeof(Tamigo));
        }
        else
        {
            amigos = realloc(amigos, (num_amigos + 1) * sizeof(Tamigo));
        }

        if (!amigos)
        {
            printf("Erro ao alocar memória para amigos.\n");
            fclose(file);
            getchar();
            return;
        }
        nome = strtok(straux, "#");
        apelido = strtok(NULL, "#");
        email = strtok(NULL, "#");
        dndia = strtok(NULL, "#");
        dnmes = strtok(NULL, "#");
        dnano = strtok(NULL, "#");
        tel = strtok(NULL, "#");

        printf("%s", nome);
        printf("%s", apelido);
        printf("%s", email);
        printf("%s", dndia);
        printf("%s", dnmes);
        printf("%s", dnano);
        printf("%s", tel);
        getchar();
        if (nome && apelido && email && dndia && dnmes && dnano && tel)
        {

            amigos[num_amigos].nome = strdup(nome);
            amigos[num_amigos].apelido = strdup(apelido);
            amigos[num_amigos].email = strdup(email);
            amigos[num_amigos].telefone = strdup(tel);
            amigos[num_amigos].dt_nasc.dia = atoi(dndia);
            amigos[num_amigos].dt_nasc.mes = atoi(dnmes);
            amigos[num_amigos].dt_nasc.ano = atoi(dnano);

            num_amigos++;
        }
        else
        {
            printf("Erro: Dados insuficientes para um amigo.\n");
            getchar();
            break;
        }
    }

    fclose(file);
}

void salva_arq_amigo()
{
    FILE *file;
    file = fopen("amigo.txt", "w");

    if (!file)
    {
        erro_Mens(-40);
        exit(1);
    }
    printf("entrou %d(num_amigos)\n", num_amigos);

    for (int i = 0; i < num_amigos; i++)
    {
        fprintf(file, "%s#", amigos[i].nome);
        fprintf(file, "%s#", amigos[i].apelido);
        fprintf(file, "%s#", amigos[i].email);
        fprintf(file, "%d#", amigos[i].dt_nasc.dia);
        fprintf(file, "%d#", amigos[i].dt_nasc.mes);
        fprintf(file, "%d#", amigos[i].dt_nasc.ano);
        fprintf(file, "%s#", amigos[i].telefone);

        fprintf(file, "\n");
    }

    fclose(file);
}

void pega_arq_local()
{
    FILE *file;
    char straux[500];
    char *nmlcl, *logradouro, *num_end, *bairro, *cidade, *estado;

    file = fopen("local.txt", "r");
    if (!file)
    {
        printf("erro ao abrir o arquivo.\n");
        getchar();
        return;
    }

    printf("Arquivo aberto com sucesso!\n");
    if (num_locais < 0)
    {
        num_locais++;
    }
    while (fgets(straux, sizeof(straux), file) != NULL)
    {
        if (num_locais == 0)
        {
            locais = malloc(1 * sizeof(Tlocal));
        }
        else
        {
            locais = realloc(locais, (num_locais + 1) * sizeof(Tlocal));
        }

        if (!locais)
        {
            printf("Erro ao alocar memoria para locais.\n");
            fclose(file);
            getchar();
            return;
        }
        nmlcl = strtok(straux, "#");
        logradouro = strtok(NULL, "#");
        num_end = strtok(NULL, "#");
        bairro = strtok(NULL, "#");
        cidade = strtok(NULL, "#");
        estado = strtok(NULL, "#");

        printf("%s", nmlcl);
        printf("%s", logradouro);
        printf("%s", num_end);
        printf("%s", bairro);
        printf("%s", cidade);
        printf("%s", estado);
        getchar();
        if (nmlcl && logradouro && num_end && bairro && cidade && estado)
        {
            locais[num_locais].nm_lcl = strdup(nmlcl);
            locais[num_locais].endereco.logradouro = strdup(logradouro);
            locais[num_locais].endereco.num_end = atoi(num_end);
            locais[num_locais].endereco.bairro = strdup(bairro);
            locais[num_locais].endereco.cidade = strdup(cidade);
            locais[num_locais].endereco.estado = strdup(estado);

            num_locais++;
        }
        else
        {
            printf("Erro: dados insuficientes para um local.\n");
            getchar();
            break;
        }
    }
    fclose(file);
}

void salva_arq_local()
{
    FILE *file;
    file = fopen("local.txt", "w");

    if (!file)
    {
        erro_Mens(-41);
        exit(1);
    }
    printf("entrou %d(num_locais)\n", num_locais);

    for (int i = 0; i < num_locais; i++)
    {
        fprintf(file, "%s#", locais[i].nm_lcl);
        fprintf(file, "%s#", locais[i].endereco.logradouro);
        fprintf(file, "%d#", locais[i].endereco.num_end);
        fprintf(file, "%s#", locais[i].endereco.bairro);
        fprintf(file, "%s#", locais[i].endereco.cidade);
        fprintf(file, "%s#", locais[i].endereco.estado);

        fprintf(file, "\n");
    }

    fclose(file);
}

void salva_arq_cat()
{
    FILE *file;
    file = fopen("categoria.txt", "w");

    if (!file)
    {
        erro_Mens(-42);
        exit(1);
    }
    printf("entrou %d(num_cat)\n", num_cat);

    for (int i = 0; i < num_cat; i++)
    {
        fprintf(file, "%s#", categorias[i].nome);

        fprintf(file, "\n");
    }
    fclose(file);
}

void pega_arq_cat()
{
    FILE *file;
    char straux[500];
    char *nome;
    file = fopen("categoria.txt", "r");
    if (!file)
    {
        printf("erro ao abrir o arquivo.\n");
        getchar();
        return;
    }
    printf("arquivo aberto com sucesso!\n");
    if (num_cat < 0)
    {
        num_cat++;
    }
    while (fgets(straux, sizeof(straux), file) != NULL)
    {
        if (num_cat == 0)
        {
            categorias = malloc(1 * sizeof(Tcategoria));
        }
        else
        {
            categorias = realloc(categorias, (num_cat + 1) * sizeof(Tcategoria));
        }

        if (!categorias)
        {
            printf("Erro ao alocar memoria para categorias.\n");
            fclose(file);
            getchar();
            return;
        }
        nome = strtok(straux, "#");

        printf("%s", nome);
        getchar();
        if (nome)
        {
            categorias[num_cat].nome = strdup(nome);

            num_cat++;
        }
        else
        {
            printf("erro: dados insuficientes para uma categoria.\n");
            getchar();
            break;
        }
    }
    fclose(file);
}

void salva_arq_amigoenc()
{
    FILE *file;
    file = fopen("encontro_amigo.txt", "w");

    if (!file)
    {
        erro_Mens(-43);
        exit(1);
    }
    printf("entrou %d(num_enc).\n", num_enc);
    getchar();
    for (int i = 0; i < num_enc; i++)
    {

        for (int j = 0; j < encontros[i].num_e_amigos; j++)
        {

            fprintf(file, "%s#", encontros[i].amigo[j].nome);
            fprintf(file, "%s#", encontros[i].amigo[j].apelido);
            fprintf(file, "%s#", encontros[i].amigo[j].email);
            fprintf(file, "%d#", encontros[i].amigo[j].dt_nasc.dia);
            fprintf(file, "%d#", encontros[i].amigo[j].dt_nasc.mes);
            fprintf(file, "%d#", encontros[i].amigo[j].dt_nasc.ano);
            fprintf(file, "%s#", encontros[i].amigo[j].telefone);

            fprintf(file, "\n");
        }
    }

    fclose(file);
}

void pega_arq_amigoenc()
{
    FILE *file;
    char straux[500];
    char *nome, *apelido, *email, *dndia, *dnmes, *dnano, *tel;

    file = fopen("encontro_amigo.txt", "r");

    if (!file)
    {
        printf("Erro ao abrir o arquivo.\n");
        getchar();
        return;
    }
    printf("Arquivo aberto com sucesso!\n");

    printf("entrou");
    getchar();
    if (num_enc < 0)
    {
        num_enc++;
    }
    while (fgets(straux, sizeof(straux), file) != NULL)
    {

        if (num_enc == 0)
        {
            encontros = malloc(1 * sizeof(Tencontro));
        }
        else
        {
            encontros = realloc(encontros, (num_enc + 1) * sizeof(Tencontro));
        }

        if (!encontros)
        {
            printf("erro ao alocar memoria para encontros");
            fclose(file);
            getchar();
            return;
        }
        printf("entrou");
        getchar();
        for (int i = 0; i <= num_enc; i++)
        {
            if (encontros[i].num_e_amigos < 0)
            {
                encontros[i].num_e_amigos++;
            }

            if (encontros[i].num_e_amigos == 0)
            {
                encontros[i].amigo = malloc(1 * sizeof(Tamigo));
            }
            else
            {
                encontros[i].amigo = realloc(encontros[i].amigo, (num_enc + 1) * sizeof(Tamigo));
            }
            nome = strtok(straux, "#");
            apelido = strtok(NULL, "#");
            email = strtok(NULL, "#");
            dndia = strtok(NULL, "#");
            dnmes = strtok(NULL, "#");
            dnano = strtok(NULL, "#");
            tel = strtok(NULL, "#");

            printf("%s", nome);
            printf("%s", apelido);
            printf("%s", email);
            printf("%s", dndia);
            printf("%s", dnmes);
            printf("%s", dnano);
            printf("%s", tel);
            getchar();

            if (nome && apelido && email && dndia && dnmes && dnano && tel)
            {
                printf("entrou.\n");
                encontros[i].amigo[encontros[i].num_e_amigos].nome = nome;
                printf("entrou.\n");
                encontros[i].amigo[encontros[i].num_e_amigos].apelido = apelido;
                printf("entrou.\n");
                encontros[i].amigo[encontros[i].num_e_amigos].email = email;
                printf("entrou.\n");
                encontros[i].amigo[encontros[i].num_e_amigos].telefone = tel;
                printf("entrou.\n");
                encontros[i].amigo[encontros[i].num_e_amigos].dt_nasc.dia = atoi(dndia);
                printf("entrou.\n");
                encontros[i].amigo[encontros[i].num_e_amigos].dt_nasc.mes = atoi(dnmes);
                printf("entrou.\n");
                encontros[i].amigo[encontros[i].num_e_amigos].dt_nasc.ano = atoi(dnano);
                printf("entrou.\n");
                printf("%d", encontros[i].num_e_amigos);
                encontros[num_enc].num_e_amigos++;
                printf("%d", encontros[i].num_e_amigos);
                getchar();
            }
            else
            {
                printf("Erro: Dados insuficientes para um encontro.amigo.\n");
                fclose(file);
                getchar();
                return;
            }
        }
        if (nome && apelido && email && dndia && dnmes && dnano && tel)
        {
            num_enc++; // temporario
        }
    }
    fclose(file);
}

void salva_arq_localenc()
{
    FILE *file;
    file = fopen("encontros_local.txt", "w");

    if (!file)
    {
        erro_Mens(-41); // Tratar erro de abertura de arquivo
        exit(1);
    }

    printf("entrou %d(num_enc).\n", num_enc); // Mensagem de depuração

    for (int i = 0; i < num_enc; i++)
    {
        // Verifica se os dados do local estão inicializados corretamente antes de escrever
        if (encontros[i].local.nm_lcl && encontros[i].local.endereco.logradouro && encontros[i].local.endereco.num_end &&
            encontros[i].local.endereco.bairro && encontros[i].local.endereco.cidade && encontros[i].local.endereco.estado)
        {
            // Escreve no arquivo com segurança (verificando se cada campo existe)
            fprintf(file, "%s#", (encontros[i].local.nm_lcl[0] != '\0') ? encontros[i].local.nm_lcl : "N/A");
            fprintf(file, "%s#", (encontros[i].local.endereco.logradouro[0] != '\0') ? encontros[i].local.endereco.logradouro : "N/A");
            fprintf(file, "%d#", encontros[i].local.endereco.num_end);
            fprintf(file, "%s#", (encontros[i].local.endereco.bairro[0] != '\0') ? encontros[i].local.endereco.bairro : "N/A");
            fprintf(file, "%s#", (encontros[i].local.endereco.cidade[0] != '\0') ? encontros[i].local.endereco.cidade : "N/A");
            fprintf(file, "%s#", (encontros[i].local.endereco.estado[0] != '\0') ? encontros[i].local.endereco.estado : "N/A");

            fprintf(file, "\n"); // Nova linha após cada entrada
        }
        else
        {
            // Se algum campo necessário não estiver inicializado, avisa
            printf("Erro: Dados do encontro %d incompletos!\n", i);
        }
    }

    printf("Arquivo 'encontros_local.txt' salvo com sucesso.\n"); // Mensagem de depuração
    fclose(file);
}

void pega_arq_localenc()
{
    FILE *file;
    char straux[500];
    char *nmlcl, *logradouro, *num_end, *bairro, *cidade, *estado;

    file = fopen("encontro_local.txt", "r");

    if (!file)
    {
        printf("erro ao abrir o arquivo.\n");
        getchar();
        return;
    }

    printf("Arquivo aberto com sucesso!\n");
    if (num_locais < 0)
    {
        num_locais++;
    }
    while (fgets(straux, sizeof(straux), file) != NULL)
    {
        if (num_locais == 0)
        {
            locais = malloc(1 * sizeof(Tlocal));
        }
        else
        {
            locais = realloc(locais, (num_locais + 1) * sizeof(Tlocal));
        }

        if (!locais)
        {
            printf("Erro ao alocar memoria para locais.\n");
            fclose(file);
            getchar();
            return;
        }

        nmlcl = strtok(straux, "#");
        logradouro = strtok(NULL, "#");
        num_end = strtok(NULL, "#");
        bairro = strtok(NULL, "#");
        cidade = strtok(NULL, "#");
        estado = strtok(NULL, "#");

        if (nmlcl && logradouro && num_end && bairro && cidade && estado)
        {
            strcpy(encontros[num_enc].local.nm_lcl, nmlcl);
            strcpy(encontros[num_enc].local.endereco.logradouro, logradouro);
            encontros[num_enc].local.endereco.num_end = atoi(num_end);
            strcpy(encontros[num_enc].local.endereco.bairro, bairro);
            strcpy(encontros[num_enc].local.endereco.cidade, cidade);
            strcpy(encontros[num_enc].local.endereco.estado, estado);
            num_locais++;
        }
        else
        {
            printf("Erro: Dados insuficientes para um local.\n");
            fclose(file);
            getchar();
            return;
        }
    }
    fclose(file);
}

/*
void pega_arq_local()
{
    FILE *file;
    char straux[500];
    char *nmlcl, *logradouro, *num_end, *bairro, *cidade, *estado;

    file = fopen("local.txt", "r");
    if (!file)
    {
        printf("erro ao abrir o arquivo.\n");
        getchar();
        return;
    }

    printf("Arquivo aberto com sucesso!\n");
    if (num_locais < 0)
    {
        num_locais++;
    }
    while (fgets(straux, sizeof(straux), file) != NULL)
    {
        if (num_locais == 0)
        {
            locais = malloc(1 * sizeof(Tlocal));
        }
        else
        {
            locais = realloc(locais, (num_locais + 1) * sizeof(Tlocal));
        }

        if (!locais)
        {
            printf("Erro ao alocar memoria para locais.\n");
            fclose(file);
            getchar();
            return;
        }
        nmlcl = strtok(straux, "#");
        logradouro = strtok(NULL, "#");
        num_end = strtok(NULL, "#");
        bairro = strtok(NULL, "#");
        cidade = strtok(NULL, "#");
        estado = strtok(NULL, "#");

        printf("%s", nmlcl);
        printf("%s", logradouro);
        printf("%s", num_end);
        printf("%s", bairro);
        printf("%s", cidade);
        printf("%s", estado);
        getchar();
        if (nmlcl && logradouro && num_end && bairro && cidade && estado)
        {
            locais[num_locais].nm_lcl = strdup(nmlcl);
            locais[num_locais].endereco.logradouro = strdup(logradouro);
            locais[num_locais].endereco.num_end = atoi(num_end);
            locais[num_locais].endereco.bairro = strdup(bairro);
            locais[num_locais].endereco.cidade = strdup(cidade);
            locais[num_locais].endereco.estado = strdup(estado);

            num_locais++;
        }
        else
        {
            printf("Erro: dados insuficientes para um local.\n");
            getchar();
            break;
        }
    }
    fclose(file);
}*/
void verifica_amigo_enc(Tamigo amigo)
{
    int i, j, cont, sn = 0;
    char op;

    if (num_enc < 0)
    {
        printf("Não há encontros registrados.\n");
        PAUSE
        return;
    }

    for (i = 0; i < num_enc; i++)
    {
        printf("Verificando encontro %d...\n", i + 1);

        for (j = 0; j < encontros[i].num_e_amigos; j++)
        {
            cont = 0;

            if (strcmp(amigo.nome, encontros[i].amigo[j].nome) == 0)
            {
                cont++;
            }
            if (strcmp(amigo.apelido, encontros[i].amigo[j].apelido) == 0)
            {
                cont++;
            }
            if (strcmp(amigo.email, encontros[i].amigo[j].email) == 0)
            {
                cont++;
            }
            if (amigo.dt_nasc.dia == encontros[i].amigo[j].dt_nasc.dia)
            {
                cont++;
            }
            if (amigo.dt_nasc.mes == encontros[i].amigo[j].dt_nasc.mes)
            {
                cont++;
            }
            if (amigo.dt_nasc.ano == encontros[i].amigo[j].dt_nasc.ano)
            {
                cont++;
            }
            if (strcmp(amigo.telefone, encontros[i].amigo[j].telefone) == 0)
            {
                cont++;
            }

            if (cont == 7)
            {
                sn++;
                printf("Amigo encontrado no encontro %d.\n", i + 1);
                break;
            }
        }
    }

    if (sn > 0)
    {
        printf("O amigo foi encontrado em %d encontro(s).\n", sn);
        printf("Deseja excluir o amigo desses encontros? (s/n): ");
        scanf(" %c", &op);

        if (op == 's')
        {
            for (i = 0; i < num_enc; i++)
            {
                for (j = 0; j < encontros[i].num_e_amigos; j++)
                {
                    if (strcmp(amigo.nome, encontros[i].amigo[j].nome) == 0 &&
                        strcmp(amigo.apelido, encontros[i].amigo[j].apelido) == 0 &&
                        strcmp(amigo.email, encontros[i].amigo[j].email) == 0 &&
                        amigo.dt_nasc.dia == encontros[i].amigo[j].dt_nasc.dia &&
                        amigo.dt_nasc.mes == encontros[i].amigo[j].dt_nasc.mes &&
                        amigo.dt_nasc.ano == encontros[i].amigo[j].dt_nasc.ano &&
                        strcmp(amigo.telefone, encontros[i].amigo[j].telefone) == 0)
                    {

                        printf("Amigo excluído do encontro %d.\n", i + 1);

                        if (encontros[i].num_e_amigos == 1)
                        {
                            printf("Este é o único amigo do encontro. O encontro será excluído.\n");
                            PAUSE
                            for (int k = i; k < num_enc - 1; k++)
                            {
                                encontros[k] = encontros[k + 1];
                            }
                            num_enc--;
                            i--;
                        }
                        else
                        {
                            for (int k = j; k < encontros[i].num_e_amigos - 1; k++)
                            {
                                encontros[i].amigo[k] = encontros[i].amigo[k + 1];
                            }
                            encontros[i].num_e_amigos--;
                        }
                        break;
                    }
                }
            }
        }
        else if (op == 'n')
        {
            printf("Exclusão cancelada.\n");
        }
        else
        {
            erro_Mens(-17);
        }
    }
    else
    {
        printf("Amigo não encontrado em nenhum encontro.\n");
    }
}

void verifica_cat_enc(Tcategoria cat)
{
    int i, j, cont = 0, sn = 0;
    char op;

    if (num_enc < 0)
    {
        printf("nao ha encontros registrados.\n");
        PAUSE
        return;
    }

    for (i = 0; i < num_enc; i++)
    {
        printf("verificando encontro %d...\n", i + 1);

        for (j = 0; j < encontros[i].num_e_cat; j++)
        {
            cont = 0;

            if (strcmp(cat.nome, encontros[i].categoria[j].nome) == 0)
            {
                cont = 1;
            }

            if (cont == 1)
            {
                sn++;
                printf("categoria encontrada no encontro %d.\n", i + 1);
                break;
            }
        }
    }

    if (sn > 0)
    {
        printf("a categoria foi encontrado em %d encontro(s).\n", sn);
        printf("deseja excluir o amigo desses encontros? (s/n): ");
        scanf("%c", &op);

        if (op == 's')
        {
            for (i = 0; i < num_enc; i++)
            {
                for (j = 0; j < encontros[i].num_e_cat; j++)
                {
                    if (strcmp(cat.nome, encontros[i].categoria[j].nome) == 0)
                    {
                        printf("categoria excluida do encontro %d.\n", i + 1);
                        if (encontros[i].num_e_cat == 1)
                        {
                            printf("este eh o unico amigo do encontro. O encontro sera excluido.\n");
                            PAUSE
                            for (int k = 0; k < num_enc - 1; k++)
                            {
                                encontros[k] = encontros[k + 1];
                            }
                            num_enc--;
                            i--;
                        }
                        else
                        {
                            for (int k = j; k < encontros[i].num_e_cat - 1; i++)
                            {
                                encontros[i].categoria[k] = encontros[i].categoria[k + 1];
                            }
                            encontros[i].num_e_cat--;
                        }
                        break;
                    }
                }
            }
        }
        else if (op == 'n')
        {
            printf("exclusao cancelada.\n");
        }
        else
        {
            erro_Mens(-17);
        }
    }
    else
    {
        printf("categoria nao encontrada em nenhum encontro.\n");
    }
}

bool compara_local(Tlocal local, Tlocal encontro)
{

    return (strcmp(local.nm_lcl, encontro.nm_lcl) == 0) &&
           (strcmp(local.endereco.logradouro, encontro.endereco.logradouro) == 0) &&
           (local.endereco.num_end == encontro.endereco.num_end) &&
           (strcmp(local.endereco.bairro, encontro.endereco.bairro) == 0) &&
           (strcmp(local.endereco.cidade, encontro.endereco.cidade) == 0) &&
           (strcmp(local.endereco.estado, encontro.endereco.estado) == 0);
}

void verifica_local_enc(Tlocal local)
{
    int i, sn = 0;
    char op;
    bool sina = false;

    if (num_enc <= 0)
    {
        printf("Nao ha encontros registrados.\n");
        return;
    }
    for (i = 0; i < num_enc; i++)
    {
        printf("Verificando encontro %d...\n", i + 1);

        if (compara_local(local, encontros[i].local))
        {
            printf("Local encontrado no encontro %d.\n", i + 1);
            sn++;
        }
    }

    if (sn == 0)
    {
        printf("Local nao encontrado em nenhum encontro.\n");
        return;
    }

    while (!sina)
    {
        printf("O local foi encontrado em %d encontro(s).\n", sn);
        printf("Deseja excluir esses encontros? (s/n): ");
        scanf(" %c", &op);
        op = tolower(op);
        sina = validasimnao(op);
        if (!sina)
        {
            erro_Mens(-17);
        }
    }

    if (op == 's')
    {
        for (i = 0; i < num_enc; i++)
        {
            if (compara_local(local, encontros[i].local))
            {
                printf("Encontro %d excluido.\n", i + 1);

                for (int k = i; k < num_enc - 1; k++)
                {
                    encontros[k] = encontros[k + 1];
                }

                num_enc--;
                i--;
            }
        }
    }
    else if (op == 'n')
    {
        printf("Exclusao cancelada.\n");
    }
    else
    {
        erro_Mens(-17);
    }
}

bool verifica_num_end(int num_end)
{
    if (num_end <= 0)
    {
        erro_Mens(-29);
        return false;
    }
    return true;
}

bool verifica_tel(char *telefone)
{
    int i, auxn;
    if (strlen(telefone) != 11)
    {
        erro_Mens(-20);
        return false;
    }
    if (telefone[2] != '9')
    {
        erro_Mens(-21);
        return false;
    }
    auxn = strlen(telefone);
    for (i = 0; i < auxn; i++)
    {
        if (!isdigit(telefone[i]))
        {
            erro_Mens(-22);
            return false;
        }
    }

    return true;
}

bool verifica_email(char *email)
{
    int cont = 0, auxe;
    if (strlen(email) < 8)
    {
        erro_Mens(-23);
        return false;
    }
    auxe = strlen(email);
    for (int i = 0; i < auxe; i++)
    {
        if (email[i] == '.')
        {
            cont++;
        }
    }
    if (cont == 0)
    {
        erro_Mens(-24);
        return false;
    }
    cont = 0;

    for (int i = 0; i < auxe; i++)
    {
        if (email[i] == '@')
        {
            cont++;
        }
    }
    if (cont == 0)
    {
        erro_Mens(-25);
        return false;
    }
    return true;
}

bool verificadata(int dia, int mes, int ano)
{
    if (ano < 1)
    {
        erro_Mens(-1);
        return false;
    }

    if (mes < 1 || mes > 12)
    {
        erro_Mens(-2);
        return false;
    }

    int dias_por_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (ano_bissexto(ano))
    {
        dias_por_mes[1] = 29;
    }

    if (dia < 1 || dia > dias_por_mes[mes - 1])
    {
        erro_Mens(-3);
        return false;
    }

    if (ano < 1850)
    {
        erro_Mens(-26);
        return false;
    }
    printf("Data %d/%d/%d e valida.\n", dia, mes, ano);

    return true;
}

bool verifica_hora(int hora, int min)
{
    int horaInicio = 0;
    int horaFim = 24;

    if (hora >= horaInicio && hora < horaFim && min >= 0 && min <= 59)
    {
        return true;
    }
    else
    {
        erro_Mens(-4);
        return false;
    }
}

void libera_memoria()
{
    for (int i = 0; i < num_amigos; i++)
    {
        free(amigos[i].nome);
        free(amigos[i].apelido);
        free(amigos[i].email);
        free(amigos[i].telefone);
    }
    free(amigos);

    for (int i = 0; i < num_locais; i++)
    {
        free(locais[i].nm_lcl);
        free(locais[i].endereco.logradouro);
        free(locais[i].endereco.bairro);
        free(locais[i].endereco.cidade);
        free(locais[i].endereco.estado);
    }
    free(locais);

    for (int i = 0; i < num_cat; i++)
    {
        free(categorias[i].nome);
    }
    free(categorias);

    for (int i = 0; i < num_enc; i++)
    {
        for (int j = 0; j < encontros[i].num_e_amigos; j++)
        {
            free(encontros[i].amigo[j].nome);
            free(encontros[i].amigo[j].apelido);
            free(encontros[i].amigo[j].email);
            free(encontros[i].amigo[j].telefone);
        }
        for (int j = 0; j < encontros[i].num_e_cat; j++)
        {
            free(encontros[i].categoria[j].nome);
        }

        free(encontros[i].local.nm_lcl);
        free(encontros[i].local.endereco.logradouro);
        free(encontros[i].local.endereco.bairro);
        free(encontros[i].local.endereco.cidade);
        free(encontros[i].local.endereco.estado);
    }
    free(encontros);
}

bool validasimnao(char op)
{
    if (op != 's' && op != 'n')
    {
        return false;
    }
    return true;
}

int ano_bissexto(int ano)
{
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
    {
        return 1;
    }
    return 0;
}

void erro_Mens(int erro)
{

    switch (erro)
    {
    case 0:
        printf("Erro: Opcao invalida\n");
        break;

    case -1:
        printf("Erro: Ano invlido\n");
        break;

    case -2:
        printf("Erro: Mes invalido\n");
        break;

    case -3:
        printf("Erro: Dia invalido para o mes especificado\n");
        break;

    case -4:
        printf("Erro: horario invalido\n");
        break;

    case -5:
        printf("Erro: nome do local nao esta entre os alocados na funcao local.\n");
        break;

    case -6:
        printf("Erro: logradouro nao esta entre os alocados na funcao local.\n");
        break;

    case -7:
        printf("Erro: numero do endereco nao esta entre os alocados na funcao local.\n");
        break;

    case -8:
        printf("Erro: bairro nao esta entre os alocados na funcao local.\n");
        break;

    case -9:
        printf("Erro: cidade nao esta entre os alocados na funcao local.\n");
        break;

    case -10:
        printf("Erro: estado nao esta entre os alocados na funcao local.\n");
        break;

    case -11:
        printf("Erro: nome de amigo nao esta entre os alocados na funcao amigo.\n");
        break;

    case -12:
        printf("Erro: apelido de amigo nao esta entre os alocados na funcao amigo.\n");
        break;

    case -13:
        printf("Erro: email de amigo nao esta entre os alocados na funcao amigo.\n");
        break;

    case -14:
        printf("Erro: data de nascimento de amigo nao esta entre os alocados na funcao amigo.\n");
        break;

    case -15:
        printf("Erro: telefone de amigo nao esta entre os alocados na funcao amigo.\n");
        break;

    case -16:
        printf("Erro: nome da categoria nao esta entre os alocados na funcao categoria.\n");
        break;

    case -17:
        printf("Erro: resposta invalida, digite ou (s) ou (n).\n");
        break;

    case -18:
        printf("Erro: nao tem amigos para excluir.\n");
        break;

    case -19:
        printf("Erro: amigo invalido digite um numero maior que 0 e menor que %d ", num_amigos);
        break;

    case -20:
        printf("Erro: numero de caracteres eh invalido digite 11 numeros.\n");
        break;

    case -21:
        printf("Erro: o primeiro numero depois do DDD tem que ser 9.\n");
        break;

    case -22:
        printf("Erro: o numero do telefone tem que ser feito de numeros, nC) seu VERME!!\n");
        break;

    case -23:
        printf("Erro: o email tem menos de 8 caracteres.\n");
        break;

    case -24:
        printf("Erro: o email tem que ter no minimo 1 ponto final (.).\n");
        break;

    case -25:
        printf("Erro: o email tem que ter no minimo 1 arroba (@).\n");
        break;

    case -26:
        printf("Erro: o seu amigo nao tem mais de 150 anos.\n");
        break;

    case -27:
        printf("Erro: faixa de alteracao invalida, digite um amigo existente.\n");
        break;

    case -28:
        printf("Erro: faixa de alteracao invalida, digite um local existente.\n");
        break;

    case -29:
        printf("Erro: numero de endereco invalido digite um numero positivo.\n");
        break;

    case -30:
        printf("Erro nao tem locais para alterar.\n");
        break;

    case -31:
        printf("nao tem locais para alterar.\n");
        break;

    case -32:
        printf("Erro: faixa de alteracao invalida digite uma categoria existente.\n");
        break;

    case -33:
        printf("Erro: categoria invalda.\n");
        break;

    case -34:
        printf("nao tem nada sobre amigos para listar.\n");
        break;

    case -35:
        printf("nao tem nada sobre locais para listar.\n");
        break;

    case -36:
        printf("nao tem nada sobre encontros para listar.\n");
        break;

    case -37:
        printf("nao existem encontros para excluir.\n");
        break;

    case -38:
        printf("nao existem locais para alterar.\n");
        break;

    case -39:
        printf("encontro inexistente, digite um encontro valido.\n");
        break;
    default:
        printf("Erro!!!");
        exit(1);
    }
}

void limpa_buffer()
{
    while (getchar() != '\n')
        ;
}
//]funções extras