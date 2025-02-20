//ESSE QUE VOCÊ ESTÁ MEXENDO NO MOMENTO!!! 8=D
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

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
    int num_Enc;
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
    Endereco endereco;
    int id;
} Local;

typedef struct
{
    char *nome;
    char *apelido;
    char *email;
    char telefone[14];
    Data nascimento;
} Amigo;

typedef struct
{
    Data data;
    Horario horario;
    Amigo **amigos;
    int num_AmigIncl;
    Categoria categoria;
    Local local;
    char *descricao;
} Encontro;

Amigo *conjuntoAmigos = NULL;
Local *conjuntoLocais = NULL;
Categoria *conjuntoCategorias = NULL;
Encontro *mEncontros = NULL;

int num_Amigos = 0;
int num_Locais = 0;
int num_Categorias = 0;
int num_Encontros = 0;

//Funções de menu
void menu_opcoes();
void opcao_menu(int op);
void subMenu();
void subMenu_opcao1();
void subMenu_opcao2();
void subMenu_opcao3();
void subMenu_opcao4();
void subMenu_opcao5();
void menuOpcoesManterAmigos();
void menuOpcoesManterLocais();
void menuOpcoesManterCategorias();
void menuOpcoesManterEncontros();
void opcoes_AlterarAmigo();
void opcoes_AlterarLocal();
void opcoes_AlterarEncontro();
void opcoes_Relatorio();

//Funções de inclusão
void incluirAmigo();
void incluirLocal();
void incluirCategoria();
void incluirEncontro();

//Funções de alteração
void alterarAmigo();
void alterarLocal();
void alterarCategoria();
void alterarEncontro();

//Funções de exclusão
void excluirAmigo();
void excluirLocal();
void excluirCategoria();
void excluirEncontro();

//Funções de alterar amigo
void alterarNome(int amigo);
void alterarApelido(int amigo);
void alterarEmail(int amigo);
void alterarAniversario(int amigo);
void alterarTelefone(int amigo);

//Funções de alterar local
void alterarNomeLocal(int local);
void alterarLogradouro(int local);
void alterarNumero(int local);
void alterarBairro(int local);
void alterarCidade(int local);
void alterarEstado(int local);

//Funções de alterar encontro
void alterarData(int encont);
void alterarHorario(int encont);
void alterarDescricao(int encont);

//Funções auxiliares(Exibição)
void sair();
void exibirAmigos();
void exibirLocais();
void exibirCategorias();
void exibirTodosEncontros();
void relatorioCategoria();
void error(int e);

//Funções referentes a arquivos
void salvarAmigos();
void salvarLocais();
void salvarCategorias();
void salvarEncontros();
void salvarDados();

//Funções de recuperação de dados
void recuperarAmigos();
void recuperarLocais();
void recuperarCategorias();
void recuperarEncontros();
void recuperarDados();

//Funções de liberação de memória
void liberarAmigos();
void liberarLocais();
void liberarCategorias();
void liberarEncontros();
void liberarMemoria();

//Funções de validação de dados
int validarData(int d, int m, int a);
int validarHorario(int h, int m);
int validarTel(char tel[]);
int validarEmail(char email[]);
void validarAlocacao(void *ptr);

int main()
{
    int op = 1;
    SetConsoleOutputCP(65001);

    recuperarDados();
    while(op != 6)
    {
        menu_opcoes();
        fflush(stdin);
        scanf("%d", &op);
        fflush(stdin);  
        system("cls");
        opcao_menu(op);
    }

    salvarDados();
    liberarMemoria();
}

void menu_opcoes()
{
    system("cls");
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
        subMenu_opcao2();
        break;
    case 3:
        subMenu_opcao3();
        break;
    case 4:
        subMenu_opcao4();
        break;
    case 5:
        subMenu_opcao5();
        break;
    case 6:
        sair();
        break;
    default:
        error(-1);
        break;
    }
}

void subMenu_opcao1()
{
    int opSubMenu;
    
    menuOpcoesManterAmigos();
    scanf("%d", &opSubMenu);
    system("cls");
    printf("\n");

    switch (opSubMenu)
    {
    case 1:
        incluirAmigo();
        break;
    case 2:
        alterarAmigo();
        break;
    case 3:
        excluirAmigo();
        break;
    default:
        error(-1);
        break;
    }
}

void incluirAmigo()
{
    char strAux[200];

    conjuntoAmigos = realloc(conjuntoAmigos, (num_Amigos + 1) * sizeof(Amigo));

    validarAlocacao(conjuntoAmigos);

    printf("Nome do amigo:\n");                                                 
    fflush(stdin);
    gets(strAux);  
    fflush(stdin);
    conjuntoAmigos[num_Amigos].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    validarAlocacao(conjuntoAmigos[num_Amigos].nome);
    strcpy(conjuntoAmigos[num_Amigos].nome, strAux);
    printf("\n");

    printf("Apelido do amigo:\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    conjuntoAmigos[num_Amigos].apelido = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    validarAlocacao(conjuntoAmigos[num_Amigos].apelido);
    strcpy(conjuntoAmigos[num_Amigos].apelido, strAux);
    printf("\n");

    printf("Email do amigo:\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    while(!validarEmail(strAux))
    {
        error(-10);
        fflush(stdin);
        gets(strAux);
        fflush(stdin);
    }
    conjuntoAmigos[num_Amigos].email = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    validarAlocacao(conjuntoAmigos[num_Amigos].email);
    strcpy(conjuntoAmigos[num_Amigos].email, strAux);
    printf("\n");

    printf("Telefone:\n");
    fflush(stdin);
    gets(conjuntoAmigos[num_Amigos].telefone);
    fflush(stdin);

    while(!validarTel(conjuntoAmigos[num_Amigos].telefone))
    {
        error(-7);
        fflush(stdin);
        gets(conjuntoAmigos[num_Amigos].telefone);
        fflush(stdin);
    }

    printf("Digite dia, mês e ano de nascimento do amigo:\n");
    scanf("%d %d %d", &conjuntoAmigos[num_Amigos].nascimento.dia, 
    &conjuntoAmigos[num_Amigos].nascimento.mes, &conjuntoAmigos[num_Amigos].nascimento.ano);

    while(!validarData(conjuntoAmigos[num_Amigos].nascimento.dia,conjuntoAmigos[num_Amigos].nascimento.mes,
    conjuntoAmigos[num_Amigos].nascimento.ano))
    {
        error(-8);
        scanf("%d %d %d", &conjuntoAmigos[num_Amigos].nascimento.dia, 
        &conjuntoAmigos[num_Amigos].nascimento.mes, &conjuntoAmigos[num_Amigos].nascimento.ano);
    }                                                               

    num_Amigos++;

    system("cls");
    printf("Amigo incluído com sucesso!!!\n");
}


void excluirAmigo()
{
    if(num_Amigos == 0)
    {
        error(-3);
        return;
    }

    int amigo;

    printf("Qual o número do amigo que você deseja excluir(1 - %d)?\n", num_Amigos);
    scanf("%d", &amigo);
    system("cls");

    while(amigo < 1 || amigo > num_Amigos) {
        printf("Não existe amigo com número correspondente!!!\n");
        scanf("%d", &amigo);
    }

    amigo--;  

    if(num_Encontros != 0) {
        for(int i = 0; i < num_Encontros;i++)
        {
            for(int j = 0;j < num_Amigos;j++)
            {
                if(mEncontros[i].amigos[j] == &conjuntoAmigos[amigo]) {
                    printf("Você deve excluir o encontro com as informações:\n");
                    printf("Local: %s-%s,%s\n", mEncontros[i].local.nome,
                    mEncontros[i].local.endereco.num, mEncontros[i].local.endereco.estado);
                    printf("Data:%d/%d/%d\n", mEncontros[i].data.dia, mEncontros[i].data.mes,
                    mEncontros[i].data.ano);
                    printf("Horario: %d:%d\n", mEncontros[i].horario.hora, mEncontros[i].horario.minuto);
                    printf("para poder excluir esse amigo");
                    return;
                }
            }
        }
    }

    free(conjuntoAmigos[amigo].nome);                                           
    free(conjuntoAmigos[amigo].apelido);
    free(conjuntoAmigos[amigo].email);

    for (int i = amigo; i < num_Amigos - 1; i++)                                
    {
        conjuntoAmigos[i] = conjuntoAmigos[i + 1];
    }

    num_Amigos--;                                                              

    conjuntoAmigos = realloc(conjuntoAmigos, num_Amigos * sizeof(Amigo));

    printf("Amigo excluído com sucesso!!!\n");
}

void opcoes_AlterarAmigo()
{
    printf("-------------------------\n");
    printf("(1) - Nome\n");
    printf("(2) - Apelido\n");
    printf("(3) - Email\n");
    printf("(4) - Telefone\n");
    printf("(5) - Aniversario\n");
    printf("-------------------------\n");
    printf("Digite a opção:\n");
}

void alterarNome(int amigo)
{
    char strAux[200];

    printf("Insira o novo nome:\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);

    amigo--;

    conjuntoAmigos[amigo].nome = realloc(conjuntoAmigos[amigo].nome, (strlen(strAux) + 1) * sizeof(char));
    validarAlocacao(conjuntoAmigos[amigo].nome);
    strcpy(conjuntoAmigos[amigo].nome, strAux);
    printf("\n");

    system("cls");

    printf("Nome alterado com sucesso!!!\n");
}

void alterarApelido(int amigo)
{
    char strAux[200];

    printf("Insira o novo apelido:\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);

    amigo--;

    conjuntoAmigos[amigo].apelido = realloc(conjuntoAmigos[amigo].apelido, (strlen(strAux) + 1) * sizeof(char));
    validarAlocacao(conjuntoAmigos[amigo].apelido);
    strcpy(conjuntoAmigos[amigo].apelido, strAux);
    printf("\n");

    system("cls");

    printf("Apelido alterado com sucesso!!!\n");
}

void alterarEmail(int amigo)
{
    char strAux[200];

    printf("Insira o novo email:\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);

    amigo--;

    conjuntoAmigos[amigo].email = realloc(conjuntoAmigos[amigo].email, (strlen(strAux) + 1) * sizeof(char));
    validarAlocacao(conjuntoAmigos[amigo].email);
    strcpy(conjuntoAmigos[amigo].email, strAux);
    printf("\n");

    system("cls");

    printf("Email alterado com sucesso!!!\n");
}

void alterarTelefone(int amigo)
{
    char strAux[200];

    printf("Insira o novo telefone:\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    
    while(!validarTel(strAux))
    {
        error(-7);
        fflush(stdin);
        gets(strAux);
        fflush(stdin);
    }

    amigo--;

    strcpy(conjuntoAmigos[amigo].telefone, strAux);
    printf("\n");

    system("cls");

    printf("Telefone alterado com sucesso!!!\n");
}

void alterarAniversario(int amigo)
{
    int d,m,a;

    printf("Digite o novo dia, mes e ano de nascimento do amigo:\n");
    scanf("%d %d %d", &d,&m,&a);
    while(!validarData(d,m,a))
    {
        printf("Data inválida!!!\n");
        scanf("%d %d %d", &d,&m,&a);
    }

    amigo--;

    conjuntoAmigos[amigo].nascimento.dia = d;
    conjuntoAmigos[amigo].nascimento.mes = m;
    conjuntoAmigos[amigo].nascimento.ano = a;

    system("cls");

    printf("Aniversário alterado com sucesso!!!\n");
}

void alterarAmigo()
{
    if(num_Amigos == 0)
    {
        error(-4);
        return;
    }

    int amigo;
    int op;

    printf("Amigos disponíveis:\n");
    for (int g = 0; g < num_Amigos; g++) {
        printf("-%s (%d)\n", conjuntoAmigos[g].nome, g + 1);
    }

    printf("Qual o número do amigo que deseja alterar(1-%d):\n", num_Amigos);
    scanf("%d", &amigo);
    while(amigo < 1 || amigo > num_Amigos)
    {
        printf("Amigo inexistente!!!\n");
        scanf("%d", &amigo);
    }

    system("cls");

    opcoes_AlterarAmigo();
    scanf("%d", &op);
    system("cls");

    switch(op){
    case 1:
        alterarNome(amigo);
        break;
    case 2:
        alterarApelido(amigo);
        break;  
    case 3:
        alterarEmail(amigo);
        break;
    case 4:
        alterarTelefone(amigo);
        break;
    case 5:
        alterarAniversario(amigo);
        break;
    default:
        error(-1);    
        break;
    }
}

void subMenu_opcao2()
{
    int opSubMenu;

    menuOpcoesManterLocais();
    scanf("%d", &opSubMenu);
    system("cls");
    printf("\n");

    switch (opSubMenu)
    {
    case 1:
        incluirLocal();
        break;
    case 2:
        alterarLocal();
        break;
    case 3:
        excluirLocal();
        break;
    default:
        error(-1);
        break;
    }
}

void incluirLocal()
{
    char strAux[200];

    conjuntoLocais = realloc(conjuntoLocais, (num_Locais + 1) * sizeof(Local));
    validarAlocacao(conjuntoLocais);

    printf("Nome do local:\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    conjuntoLocais[num_Locais].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    validarAlocacao(conjuntoLocais[num_Locais].nome);
    strcpy(conjuntoLocais[num_Locais].nome, strAux);
    printf("\n");

    printf("Logradouro:\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    conjuntoLocais[num_Locais].endereco.logradouro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    validarAlocacao(conjuntoLocais[num_Locais].endereco.logradouro);
    strcpy(conjuntoLocais[num_Locais].endereco.logradouro, strAux);
    printf("\n");

    printf("Número:\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    conjuntoLocais[num_Locais].endereco.num = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    validarAlocacao(conjuntoLocais[num_Locais].endereco.num);
    strcpy(conjuntoLocais[num_Locais].endereco.num, strAux);
    printf("\n");

    printf("Bairro:\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    conjuntoLocais[num_Locais].endereco.bairro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    validarAlocacao(conjuntoLocais[num_Locais].endereco.bairro);
    strcpy(conjuntoLocais[num_Locais].endereco.bairro, strAux);
    printf("\n");

    printf("Cidade:\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    conjuntoLocais[num_Locais].endereco.cidade = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    validarAlocacao(conjuntoLocais[num_Locais].endereco.cidade);
    strcpy(conjuntoLocais[num_Locais].endereco.cidade, strAux);
    printf("\n");

    printf("Estado:\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    conjuntoLocais[num_Locais].endereco.estado = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    validarAlocacao(conjuntoLocais[num_Locais].endereco.estado);
    strcpy(conjuntoLocais[num_Locais].endereco.estado, strAux);
    printf("\n");

    conjuntoLocais[num_Locais].id = num_Locais;

    num_Locais++;

    system("cls");

    printf("Local incluído com sucesso!!!\n");
}

void opcoes_AlterarLocal()
{
    printf("-------------------------\n");
    printf("(1) - Nome\n");
    printf("(2) - Logradouro\n");
    printf("(3) - Número\n");
    printf("(4) - Bairro\n");
    printf("(5) - Cidade\n");
    printf("(6) - Estado\n");
    printf("-------------------------\n");
    printf("Digite a opção:\n");
}

void alterarLocal()
{
    if(num_Locais == 0){
        error(-4);
        return;
    }

    int local;
    int opAlterarLocal;

    printf("Locais disponíveis:\n\n");
    for (int g = 0; g < num_Locais; g++) {
        printf("%s (%d)\n", conjuntoLocais[g].nome, g + 1);
    }

    printf("Qual o número do local que deseja alterar(1 - %d)?\n", num_Locais);
    scanf("%d", &local);
    while(local < 1 || local > num_Locais){
        printf("Local inexistente!!!\n");
        scanf("%d", &local);
    }

    system("cls");

    opcoes_AlterarLocal();
    scanf("%d", &opAlterarLocal);
    switch(opAlterarLocal){
    case 1:
        alterarNomeLocal(local);
        break;
    case 2:
        alterarLogradouro(local);
        break;
    case 3:
        alterarNumero(local);
        break;
    case 4:
        alterarBairro(local);
        break;
    case 5:
        alterarCidade(local);
        break;
    case 6:
        alterarEstado(local);
        break;
    default:
        error(-1);
        break;
    }
}

void alterarNomeLocal(int local)
{
    char strAux[200];

    printf("Insira o novo nome:\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);

    local--;

    conjuntoLocais[local].nome = realloc(conjuntoLocais[local].nome, (strlen(strAux) + 1) * sizeof(char));
    
    validarAlocacao(conjuntoLocais[local].nome);
    strcpy(conjuntoLocais[local].nome, strAux);
    system("cls");
    
    printf("Nome alterado com sucesso!!!\n");
}

void alterarLogradouro(int local)
{
    char strAux[200];

    printf("Insira o novo logradouro:\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);

    local--;

    conjuntoLocais[local].endereco.logradouro = realloc(conjuntoLocais[local].endereco.logradouro,
    (strlen(strAux) + 1) * sizeof(char));

    validarAlocacao(conjuntoLocais[local].endereco.logradouro);
    strcpy(conjuntoLocais[local].endereco.logradouro, strAux);
    system("cls");

    printf("Logradouro alterado com sucesso!!!\n");
}

void alterarNumero(int local)
{
    char strAux[200];

    printf("Insira o novo número:\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);

    local--;

    conjuntoLocais[local].endereco.num = realloc(conjuntoLocais[local].endereco.num,
    (strlen(strAux) + 1) * sizeof(char));

    validarAlocacao(conjuntoLocais[local].endereco.num);
    strcpy(conjuntoLocais[local].endereco.num, strAux);
    system("cls");

    printf("Número alterado com sucesso!!!\n");
}

void alterarBairro(int local)
{
    char strAux[200];

    printf("Insira o novo bairro:\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);

    local--;

    conjuntoLocais[local].endereco.bairro = realloc(conjuntoLocais[local].endereco.bairro,
    (strlen(strAux) + 1) * sizeof(char));

    validarAlocacao(conjuntoLocais[local].endereco.bairro);

    strcpy(conjuntoLocais[local].endereco.bairro, strAux);
    printf("\n");

    system("cls");

    printf("Bairro alterado com sucesso!!!\n");
}

void alterarCidade(int local)
{
    char strAux[200];

    printf("Insira o novo cidade:\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);

    local--;

    conjuntoLocais[local].endereco.cidade = realloc(conjuntoLocais[local].endereco.cidade, 
    (strlen(strAux) + 1) * sizeof(char));

    validarAlocacao(conjuntoLocais[local].endereco.cidade);

    strcpy(conjuntoLocais[local].endereco.cidade, strAux);
    printf("\n");
    system("cls");

    printf("Cidade alterada com sucesso!!!\n");
}

void alterarEstado(int local)
{
    char strAux[200];

    printf("Insira o novo estado:\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);

    local--;

    conjuntoLocais[local].endereco.estado = realloc(conjuntoLocais[local].endereco.estado, 
    (strlen(strAux) + 1) * sizeof(char));

    validarAlocacao(conjuntoLocais[local].endereco.estado);

    strcpy(conjuntoLocais[local].endereco.estado, strAux);
    printf("\n");

    system("cls");

    printf("Estado alterado com sucesso!!!\n");
}

void excluirLocal()
{
    if(num_Locais == 0)
    {
        error(-3);
        return;
    }

    int local;

    printf("Digite o número do local que você quer excluir(1 - %d)?\n", num_Locais);
    scanf("%d", &local);
    while(local < 1 || local > num_Locais){
        printf("Local inexistente!!!\n");
        scanf("%d", &local);
    }

    local--;

    if(num_Encontros != 0){
        for(int i = 0; i < num_Encontros; i++) {
            for(int j = 0; j < num_Locais;j++) {
                if(mEncontros[i].local.id == conjuntoLocais[local].id){
                    printf("Você deve excluir o encontro com as informações:\n");
                    printf("Local: %s-%s,%s\n", mEncontros[i].local.nome,
                    mEncontros[i].local.endereco.num, mEncontros[i].local.endereco.estado);
                    printf("Data:%d/%d/%d\n", mEncontros[i].data.dia, mEncontros[i].data.mes,
                    mEncontros[i].data.ano);
                    printf("Horario: %d:%d\n", mEncontros[i].horario.hora, mEncontros[i].horario.minuto);
                    printf("para poder excluir o local.\n\n");
                    return;                
                }
            }
        }
    }

    free(conjuntoLocais[local].nome);
    free(conjuntoLocais[local].endereco.logradouro);
    free(conjuntoLocais[local].endereco.num);
    free(conjuntoLocais[local].endereco.bairro);
    free(conjuntoLocais[local].endereco.cidade);
    free(conjuntoLocais[local].endereco.estado);

    for (int i = local; i < num_Locais - 1; i++){
            conjuntoLocais[i] = conjuntoLocais[i + 1];
    }

    num_Locais--;

    conjuntoLocais = realloc(conjuntoLocais, num_Locais * sizeof(Local));

    printf("Local excluído com sucesso!!!\n");
}

void subMenu_opcao3()
{
    int opSubMenu;

    menuOpcoesManterCategorias();
    scanf("%d", &opSubMenu);
    system("cls");
    printf("\n");
    switch (opSubMenu){
    case 1:
        incluirCategoria();
        break;
    case 2:
        alterarCategoria();
        break;
    case 3:
        excluirCategoria();
        break;
    default:
        printf("Opção inválida!\n");
        break;
    }
}

void incluirCategoria()
{
    char strAux[200];

    conjuntoCategorias = realloc(conjuntoCategorias, (num_Categorias + 1) * sizeof(Categoria));

    validarAlocacao(conjuntoCategorias);

    printf("Nome da categoria:\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    conjuntoCategorias[num_Categorias].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));

    validarAlocacao(conjuntoCategorias[num_Categorias].nome);
    strcpy(conjuntoCategorias[num_Categorias].nome, strAux);

    num_Categorias++;

    system("cls");

    printf("Categoria incluída com sucesso!!!\n");
}

void alterarCategoria()
{
    if(num_Categorias == 0){
        error(-4);
        return;
    }

    int categoria;
    char strAux[200];

    printf("Qual o número da categoria que deseja alterar(1 - %d)?\n", num_Categorias);
    scanf("%d", &categoria);
    while(categoria < 1 || categoria > num_Categorias){
        printf("Categoria inexistente!!!\n");
        scanf("%d", &categoria);
    }

    system("cls");

    printf("Digite a nova categoria:\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);

    categoria--;

    conjuntoCategorias[categoria].nome = realloc(conjuntoCategorias[categoria].nome, 
    (strlen(strAux) + 1) * sizeof(char));

    validarAlocacao(conjuntoCategorias[categoria].nome);

    strcpy(conjuntoCategorias[categoria].nome, strAux);

    printf("Categoria alterada com sucesso!!!\n");
}

void excluirCategoria()
{
    if(num_Categorias == 0){
        error(-3);
        return;
    }

    int categoria;
    printf("Digite o número da categoria que você quer excluir(1 - %d)?\n", num_Categorias);
    scanf("%d", &categoria);
    while(categoria < 1 || categoria > num_Categorias){
        printf("Categoria inexistente!!!\n");
        scanf("%d", &categoria);
    }

    categoria--;

    if(num_Encontros != 0){
        for(int i = 0; i < num_Encontros;i++){
            for(int j = 0; j < num_Categorias; j++){
                if(&mEncontros[i].categoria == &conjuntoCategorias[j]){
                    printf("Você deve excluir o encontro com informações:\n");
                    printf("Data: %d/%d/%d\n",mEncontros[i].data.dia,
                    mEncontros[i].data.mes, mEncontros[i].data.ano);
                    printf("Horário: %d:%d\n",mEncontros[i].horario.hora,
                    mEncontros[i].horario.minuto);
                    printf("Local: Local: %s - %s, %s, %s, %s\n",mEncontros[i].local.nome,
                    mEncontros[i].local.endereco.num,mEncontros[i].local.endereco.bairro,
                    mEncontros[i].local.endereco.cidade,mEncontros[i].local.endereco.estado);
                    printf("para poder excluir a categoria.\n");
                }
            }
        }
    }

    free(conjuntoCategorias[categoria].nome);

    for (int i = categoria; i < num_Categorias - 1; i++){
        conjuntoCategorias[i] = conjuntoCategorias[i + 1];
    }

    num_Categorias--;

    conjuntoCategorias = realloc(conjuntoCategorias, (num_Categorias) * sizeof(Categoria));

    if(conjuntoCategorias == NULL){
        error(-2);
    }

    system("cls");

    printf("Categoria excluída com sucesso!!!\n");
}

void subMenu_opcao4()
{
    int opSubMenu;

    menuOpcoesManterEncontros();
    scanf("%d", &opSubMenu);
    system("cls");
    printf("\n");
    switch(opSubMenu){
    case 1:
        incluirEncontro();
        break;
    case 2:
        alterarEncontro();
        break;
    case 3:
        excluirEncontro();
        break;
    default:
        error(-1);
        break;
    }
}

void incluirEncontro() 
{
    if (num_Amigos == 0) {
        printf("Não é possível criar um encontro sem amigos cadastrados.\n");
        return;
    } else if (num_Locais == 0) {
        printf("Não é possível criar um encontro sem locais cadastrados.\n");
        return;
    } else if (num_Categorias == 0) {
        printf("Não é possível criar um encontro sem categorias cadastradas.\n");
        return;
    }

    char strAux[200];
    int contAmigos = 0;

    mEncontros = realloc(mEncontros, (num_Encontros + 1) * sizeof(Encontro));
    validarAlocacao(mEncontros);

    printf("Defina a data:\n");
    scanf("%d %d %d", &mEncontros[num_Encontros].data.dia, &mEncontros[num_Encontros].data.mes, 
    &mEncontros[num_Encontros].data.ano);

    while (validarData(mEncontros[num_Encontros].data.dia, 
    mEncontros[num_Encontros].data.mes, 
    mEncontros[num_Encontros].data.ano) == 0) {
        printf("Data inválida!!!\n");
        scanf("%d %d %d", &mEncontros[num_Encontros].data.dia, 
                          &mEncontros[num_Encontros].data.mes,
                          &mEncontros[num_Encontros].data.ano);
    }

    printf("Defina o horário:\n");
    scanf("%d %d", &mEncontros[num_Encontros].horario.hora, 
    &mEncontros[num_Encontros].horario.minuto);

    while (validarHorario(mEncontros[num_Encontros].horario.hora, 
    mEncontros[num_Encontros].horario.minuto) == 0) {
        printf("Horário inválido!!!\n");
        scanf("%d %d", &mEncontros[num_Encontros].horario.hora, 
                          &mEncontros[num_Encontros].horario.minuto);
    }

    printf("Amigos disponíveis:\n");
    for (int g = 0; g < num_Amigos; g++) {
        printf("%s (%d)\n", conjuntoAmigos[g].nome, g + 1);
    }

    printf("Insira o número do amigo que deseja incluir (0 para parar):\n");

    mEncontros[num_Encontros].amigos = malloc(sizeof(Amigo*) * num_Amigos);
    validarAlocacao(mEncontros[num_Encontros].amigos);

    while (1) 
    {
        int amigoSelec;
        scanf("%d", &amigoSelec);

        if (amigoSelec == 0) {
            break;
        } else if (amigoSelec < 1 || amigoSelec > num_Amigos) {
            printf("Amigo inexistente!!!\n");
        } else {
            mEncontros[num_Encontros].amigos[contAmigos] = &conjuntoAmigos[amigoSelec - 1];
            contAmigos++;

            if (contAmigos == num_Amigos) {
                break;
            }
        }
    }

    if (contAmigos == 0) {
        printf("Nenhum amigo foi selecionado!!!\n");
        return;
    }

    mEncontros[num_Encontros].amigos = realloc(mEncontros[num_Encontros].amigos, contAmigos * sizeof(Amigo));
    validarAlocacao(mEncontros[num_Encontros].amigos);

    system("cls");

    mEncontros[num_Encontros].num_AmigIncl = contAmigos;

    printf("Categorias disponíveis:\n");
    for (int i = 0; i < num_Categorias; i++) {
        printf("%s (%d)\n", conjuntoCategorias[i].nome, i + 1);
    }

    printf("Insira o número da categoria que deseja incluir:\n");

    int categoriaSelec;
    scanf("%d", &categoriaSelec);

    while(categoriaSelec < 0 || categoriaSelec > num_Categorias){
        printf("Categoria inexistente!!!\n");
        scanf("%d", &categoriaSelec);
    }

    mEncontros[num_Encontros].categoria = conjuntoCategorias[categoriaSelec - 1];

    system("cls");

    printf("Locais disponíveis:\n");
    for (int i = 0; i < num_Locais; i++) {
        printf("%s - %s, %s, %s, %s (%d)\n", 
            conjuntoLocais[i].endereco.logradouro,
            conjuntoLocais[i].endereco.num, 
            conjuntoLocais[i].endereco.bairro, 
            conjuntoLocais[i].endereco.cidade, 
            conjuntoLocais[i].endereco.estado, i + 1);
    }

    printf("Insira o número do local que deseja incluir:\n");
    int localSelec;
    scanf("%d", &localSelec);

    while((localSelec - 1) < 0 || (localSelec - 1) > num_Locais){
        printf("Local inexistente!!!\n");
        scanf("%d", &localSelec);
    }
    conjuntoLocais[localSelec - 1].id = localSelec - 1;

    mEncontros[num_Encontros].local = conjuntoLocais[localSelec - 1];

    printf("Digite uma descrição para o encontro:\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);

    mEncontros[num_Encontros].descricao = malloc((strlen(strAux) + 1) * sizeof(char));
    validarAlocacao(mEncontros[num_Encontros].descricao);
    strcpy(mEncontros[num_Encontros].descricao, strAux);

    system("cls");

    num_Encontros++;

    printf("Encontro criado com sucesso!\n");
}

int validarData(int d, int m, int a) 
{
    int valido = 1;  

    if (a <= 0) {
        valido = 0;  
    }
    else if (m < 1 || m > 12) {
        valido = 0; 
    }
    else if (d < 1 || d > 31) {
        valido = 0;  
    }
    else {
        if (m == 2) {
            if ((a % 400 == 0) || ((a % 4 == 0) && (a % 100 != 0))) {
                if (d > 29) {
                    valido = 0; 
                }
            } else {
                if (d > 28) {
                    valido = 0;  
                }
            }
        }
        else if (m == 4 || m == 6 || m == 9 || m == 11) {
            if (d > 30) {
                valido = 0;  
            }
        }
        else if (d > 31) {
            valido = 0;
        }
    }

    return valido;
}


void opcoes_AlterarEncontro()
{
    printf("-------------------------\n");
    printf("(1) - Data\n");
    printf("(2) - Horário\n");
    printf("(3) - Amigos\n");
    printf("(4) - Local\n");
    printf("(5) - Categoria\n");
    printf("(6) - Descrição\n");
    printf("-------------------------\n");
    printf("Digite a opção:\n");
}

void alterarData(int encont)
{
    int dia, mes, ano;

    printf("Digite a nova data:\n");
    scanf("%d %d %d", &dia, &mes, &ano);
    while (!validarData(dia, mes, ano))
    {
        error(-8);
        scanf("%d %d %d", &dia, &mes, &ano);
    }

    encont--;

    mEncontros[encont].data.dia = dia;
    mEncontros[encont].data.mes = mes;
    mEncontros[encont].data.ano = ano;

    system("cls");

    printf("Data alterada com sucesso!!!\n");
}

void alterarHorario(int encont)
{
    int hora, minuto;
    printf("Digite o novo horário:\n");
    scanf("%d %d", &hora, &minuto);
    while (!validarHorario(hora, minuto))
    {
        error(-9);
        scanf("%d %d", &hora, &minuto);
    }

    encont--;

    mEncontros[encont].horario.hora = hora;
    mEncontros[encont].horario.minuto = minuto;

    system("cls");

    printf("Horário alterado com sucesso!!!\n");
}

void alterarDescricao(int encont)
{
    char strAux[200];
    printf("Digite a nova descrição:\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);

    encont--;

    mEncontros[encont].descricao = realloc(mEncontros[encont].descricao, (strlen(strAux) + 1) * sizeof(char));
    validarAlocacao(mEncontros[encont].descricao);
    strcpy(mEncontros[encont].descricao, strAux);

    system("cls");

    printf("Descrição alterada com sucesso!!!\n");
}

void alterarEncontro()
{
    if(num_Encontros == 0){
        printf("Não há encontros disponíveis.\n");
        return;
    }

    int encont;
    int op;

    printf("Encontros disponíveis:\n\n");
    for(int g = 0; g < num_Encontros;g++)
    {
        printf("Encontro (%d):\n\n",g + 1);
        printf("Data: %d/%d/%d\n", mEncontros[g].data.dia,
        mEncontros[g].data.mes,mEncontros[g].data.ano);
        printf("Horário: %d:%d\n",mEncontros[g].horario.hora,
        mEncontros[g].horario.minuto);
        printf("Local: %s - %s, %s, %s, %s\n", mEncontros[g].local.nome,
        mEncontros[g].local.endereco.num,mEncontros[g].local.endereco.bairro,
        mEncontros[g].local.endereco.cidade, mEncontros[g].local.endereco.estado);
    }

    printf("Digite o número do encontro que deseja alterar(1-%d):\n", num_Encontros);
    scanf("%d", &encont);
    while(encont < 1 || encont > num_Encontros){
        printf("Encontro inexistente!!!\n");
        scanf("%d", &encont);
    }

    system("cls");

    opcoes_AlterarEncontro();
    scanf("%d", &op);
    system("cls");

    switch(op){
    case 1:
        alterarData(encont);
        break;
    case 2:
        alterarHorario(encont);
        break;
    case 3:
        alterarAmigo();
        break;
    case 4:
        alterarLocal();
        break;
    case 5:
        alterarCategoria();
        break;
    case 6:
        alterarDescricao(encont);
        break;
    default:
        error(-1);
        break;
    }

}

void excluirEncontro() 
{
    if (num_Encontros == 0) 
    {
        error(-3);
        return;
    }

    int encontroSelec;
    printf("Encontros disponíveis:\n");
    for (int i = 0; i < num_Encontros; i++) 
    {
        printf("Encontro %d:\nData:%d/%d/%d - %d:%d\n", i + 1, 
               mEncontros[i].data.dia, mEncontros[i].data.mes, mEncontros[i].data.ano,
               mEncontros[i].horario.hora, mEncontros[i].horario.minuto);
        printf("Local: %s - %s, %s, %s, %s\n", mEncontros[i].local.nome,mEncontros[i].local.endereco.num,
               mEncontros[i].local.endereco.bairro, mEncontros[i].local.endereco.cidade,
               mEncontros[i].local.endereco.estado);
    }

    printf("Insira o número do encontro que deseja excluir:\n");
    scanf("%d", &encontroSelec);

    while((encontroSelec - 1) < 0 || (encontroSelec - 1) > num_Encontros){
        printf("Encontro inexistente!!!\n");
        scanf("%d", &encontroSelec);
    }

    int indiceExclusao = encontroSelec - 1;

    free(mEncontros[indiceExclusao].amigos); 
    free(mEncontros[indiceExclusao].descricao); 
    free(mEncontros[indiceExclusao].local.nome);
    free(mEncontros[indiceExclusao].local.endereco.logradouro);
    free(mEncontros[indiceExclusao].local.endereco.num);
    free(mEncontros[indiceExclusao].local.endereco.bairro);
    free(mEncontros[indiceExclusao].local.endereco.cidade);
    free(mEncontros[indiceExclusao].local.endereco.estado);

    for (int i = indiceExclusao; i < num_Encontros - 1; i++) {
        mEncontros[i] = mEncontros[i + 1];
    }

    num_Encontros--;

    mEncontros = realloc(mEncontros, num_Encontros * sizeof(Encontro));
    if (mEncontros == NULL && num_Encontros > 0) {
        error(-2);
        exit(0);
    }

    system("cls");
    printf("Encontro excluído com sucesso!\n");
}

void opcoes_Relatorio()
{
    printf("-------------------------\n");
    printf("(1) - Listar Amigos\n");
    printf("(2) - Listar Locais\n");
    printf("(3) - Listar Categorias\n");
    printf("(4) - Listar Encontros\n");
    printf("(5) - Relátorio por categoria\n");
    printf("-------------------------\n");
    printf("Digite a opção:\n");
}

void subMenu_opcao5()
{
    int opSubMenu;
    opcoes_Relatorio();
    scanf("%d", &opSubMenu);

    system("cls");

    switch(opSubMenu){
    case 1:
        exibirAmigos();
        break;
    case 2:
        exibirLocais();
        break;
    case 3:
        exibirCategorias();
        break;
    case 4:
        exibirTodosEncontros();
        break;
    case 5:
        relatorioCategoria();
        break;
    default:
        error(-1);
        return;
    }

    printf("\n");
    system("pause");
}

void salvarAmigos()
{
    FILE *arqAmigos = fopen("amigos.txt", "w");

    if(arqAmigos == NULL){
        error(-5);
        exit(0);
    }

    fprintf(arqAmigos, "%d\n", num_Amigos);

    for(int i = 0; i < num_Amigos;i++)
    {
        fprintf(arqAmigos, "%s\n", conjuntoAmigos[i].nome);
        fprintf(arqAmigos, "%s\n",conjuntoAmigos[i].apelido);
        fprintf(arqAmigos, "%s\n", conjuntoAmigos[i].email);
        fprintf(arqAmigos, "%s\n", conjuntoAmigos[i].telefone);
        fprintf(arqAmigos, "%d/%d/%d\n",conjuntoAmigos[i].nascimento.dia,
        conjuntoAmigos[i].nascimento.mes,conjuntoAmigos[i].nascimento.ano);
        fprintf(arqAmigos, "\n");           
    } 

    fclose(arqAmigos);
}

void salvarLocais()
{
    FILE *arqLocais = fopen("locais.txt", "w");

    if(arqLocais == NULL){
        error(-5);
        exit(0);
    }

    fprintf(arqLocais, "%d\n", num_Locais);

    for(int i = 0; i < num_Locais;i++)
    {
        fprintf(arqLocais, "%s\n", conjuntoLocais[i].nome);
        fprintf(arqLocais, "%s\n", conjuntoLocais[i].endereco.logradouro);
        fprintf(arqLocais, "%s\n", conjuntoLocais[i].endereco.num);
        fprintf(arqLocais, "%s\n", conjuntoLocais[i].endereco.bairro);
        fprintf(arqLocais, "%s\n", conjuntoLocais[i].endereco.cidade);
        fprintf(arqLocais, "%s\n", conjuntoLocais[i].endereco.estado);
        fprintf(arqLocais, "%d\n", conjuntoLocais[i].id);
        fprintf(arqLocais, "\n");
    }

    fclose(arqLocais);
}

void salvarCategorias()
{
    FILE *arqCategorias = fopen("categorias.txt", "w");

    if(arqCategorias == NULL){
        error(-5);
        exit(0);
    }

    fprintf(arqCategorias, "%d\n", num_Categorias);

    for(int i = 0; i < num_Categorias;i++)
    {
        fprintf(arqCategorias, "%s\n", conjuntoCategorias[i].nome);
        fprintf(arqCategorias, "\n");
    }

    fclose(arqCategorias);
}

void salvarEncontros()
{
    FILE *arqEncontros = fopen("encontros.txt", "w");

    if(arqEncontros == NULL){
        error(-5);
        exit(0);
    }

    fprintf(arqEncontros, "%d\n", num_Encontros);

    for(int i = 0; i < num_Encontros;i++)
    {
        fprintf(arqEncontros, "%d:%d\n", mEncontros[i].horario.hora,mEncontros[i].horario.minuto);
        fprintf(arqEncontros, "%d/%d/%d\n", mEncontros[i].data.dia,mEncontros[i].data.mes,mEncontros[i].data.ano);
        fprintf(arqEncontros, "%s\n", mEncontros[i].categoria.nome);
        fprintf(arqEncontros, "%s\n", mEncontros[i].local.nome);
        fprintf(arqEncontros, "%s\n", mEncontros[i].local.endereco.logradouro);
        fprintf(arqEncontros, "%s\n", mEncontros[i].local.endereco.num);
        fprintf(arqEncontros, "%s\n", mEncontros[i].local.endereco.bairro);
        fprintf(arqEncontros, "%s\n", mEncontros[i].local.endereco.cidade);
        fprintf(arqEncontros, "%s\n", mEncontros[i].local.endereco.estado);
        fprintf(arqEncontros, "%d\n", mEncontros[i].num_AmigIncl);

        for(int j = 0; j < mEncontros[i].num_AmigIncl;j++){
            fprintf(arqEncontros, "%s\n", mEncontros[i].amigos[j]->nome);
            fprintf(arqEncontros, "%s\n", mEncontros[i].amigos[j]->apelido);
        }

        fprintf(arqEncontros, "%s\n", mEncontros[i].descricao);

        fprintf(arqEncontros, "\n");
    }

    fclose(arqEncontros);
}

void recuperarAmigos()
{
    FILE *arqAmigos = fopen("amigos.txt", "r");

    if(arqAmigos == NULL)
    {
        return;
    }

    fscanf(arqAmigos, "%d\n", &num_Amigos);
    conjuntoAmigos = (Amigo *)malloc(num_Amigos * sizeof(Amigo));

    char strAux[256];

    for(int i = 0; i < num_Amigos;i++)
    {
        fscanf(arqAmigos, " %[^\n]", strAux);
        conjuntoAmigos[i].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(conjuntoAmigos[i].nome, strAux);

        fscanf(arqAmigos, " %[^\n]", strAux);
        conjuntoAmigos[i].apelido = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(conjuntoAmigos[i].apelido, strAux);

        fscanf(arqAmigos, " %[^\n]", strAux);
        conjuntoAmigos[i].email = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(conjuntoAmigos[i].email, strAux);

        fscanf(arqAmigos, " %[^\n]", conjuntoAmigos[i].telefone);

        fscanf(arqAmigos, "%d/%d/%d\n", &conjuntoAmigos[i].nascimento.dia,
        &conjuntoAmigos[i].nascimento.mes,&conjuntoAmigos[i].nascimento.ano);
    }
    fclose(arqAmigos);
}

void recuperarLocais()
{
    FILE *arqLocais = fopen("locais.txt", "r");

    if(arqLocais == NULL){
        return;
    }

    fscanf(arqLocais, "%d\n", &num_Locais);
    conjuntoLocais = (Local *)malloc(num_Locais * sizeof(Local));

    char strAux[256];

    for(int i = 0; i < num_Locais;i++)
    {
        fscanf(arqLocais, " %[^\n]", strAux);   
        conjuntoLocais[i].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(conjuntoLocais[i].nome, strAux);

        fscanf(arqLocais, " %[^\n]", strAux);
        conjuntoLocais[i].endereco.logradouro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(conjuntoLocais[i].endereco.logradouro, strAux);

        fscanf(arqLocais, "  %[^\n]", strAux);
        conjuntoLocais[i].endereco.num = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(conjuntoLocais[i].endereco.num, strAux);

        fscanf(arqLocais, " %[^\n]", strAux);
        conjuntoLocais[i].endereco.bairro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(conjuntoLocais[i].endereco.bairro, strAux);

        fscanf(arqLocais, " %[^\n]", strAux);
        conjuntoLocais[i].endereco.cidade = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(conjuntoLocais[i].endereco.cidade, strAux);

        fscanf(arqLocais, " %[^\n]", strAux);
        conjuntoLocais[i].endereco.estado = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(conjuntoLocais[i].endereco.estado, strAux);

        fscanf(arqLocais, "%d\n", &conjuntoLocais[i].id);
    }
    fclose(arqLocais);
}

void recuperarCategorias()
{
    FILE *arqCategorias = fopen("categorias.txt", "r");

    if(arqCategorias == NULL){
        return;
    }

    fscanf(arqCategorias, "%d\n", &num_Categorias);
    conjuntoCategorias = (Categoria *)malloc(num_Categorias * sizeof(Categoria));

    char strAux[256];

    for(int i = 0; i < num_Categorias;i++)
    {
        fscanf(arqCategorias, " %[^\n]", strAux);
        conjuntoCategorias[i].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(conjuntoCategorias[i].nome, strAux);
    }
    fclose(arqCategorias);
}

void recuperarEncontros()
{
    FILE *arqEncontros = fopen("encontros.txt", "r");

    if(arqEncontros == NULL){
        return;
    }

    fscanf(arqEncontros, "%d\n", &num_Encontros);
    mEncontros = (Encontro *)malloc(num_Encontros * sizeof(Encontro));

    char strAux[256];

    for(int i = 0; i < num_Encontros;i++)
    {
        fscanf(arqEncontros, "%d:%d\n", &mEncontros[i].horario.hora, &mEncontros[i].horario.minuto);
        fscanf(arqEncontros, "%d/%d/%d\n", &mEncontros[i].data.dia, &mEncontros[i].data.mes, 
        &mEncontros[i].data.ano);

        fscanf(arqEncontros, " %[^\n]", strAux);
        mEncontros[i].categoria.nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(mEncontros[i].categoria.nome, strAux);

        fscanf(arqEncontros, " %[^\n]", strAux);
        mEncontros[i].local.nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(mEncontros[i].local.nome, strAux);

        fscanf(arqEncontros, " %[^\n]", strAux);
        mEncontros[i].local.endereco.logradouro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(mEncontros[i].local.endereco.logradouro, strAux);

        fscanf(arqEncontros, " %[^\n]", strAux);
        mEncontros[i].local.endereco.num = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(mEncontros[i].local.endereco.num, strAux);

        fscanf(arqEncontros, " %[^\n]", strAux);
        mEncontros[i].local.endereco.bairro = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(mEncontros[i].local.endereco.bairro, strAux);

        fscanf(arqEncontros, " %[^\n]", strAux);
        mEncontros[i].local.endereco.cidade = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(mEncontros[i].local.endereco.cidade, strAux);

        fscanf(arqEncontros, " %[^\n]", strAux);
        mEncontros[i].local.endereco.estado = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(mEncontros[i].local.endereco.estado, strAux);

        fscanf(arqEncontros, "%d\n", &mEncontros[i].num_AmigIncl);
        mEncontros[i].amigos = (Amigo **)malloc(mEncontros[i].num_AmigIncl * sizeof(Amigo *));

        for(int j = 0; j < mEncontros[i].num_AmigIncl;j++)
        {
            mEncontros[i].amigos[j] = (Amigo *)malloc(sizeof(Amigo));

            fscanf(arqEncontros, " %[^\n]", strAux);  
            mEncontros[i].amigos[j]->nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
            strcpy(mEncontros[i].amigos[j]->nome, strAux);

            fscanf(arqEncontros, " %[^\n]", strAux);
            mEncontros[i].amigos[j]->apelido = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
            strcpy(mEncontros[i].amigos[j]->apelido, strAux);
        }

        fscanf(arqEncontros, " %[^\n]", strAux);
        mEncontros[i].descricao = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy(mEncontros[i].descricao, strAux);
    }
    fclose(arqEncontros);
}

void liberarAmigos()
{
    for(int i = 0; i < num_Amigos;i++)
    {
        free(conjuntoAmigos[i].nome);
        conjuntoAmigos[i].nome = NULL;
        free(conjuntoAmigos[i].apelido);
        conjuntoAmigos[i].apelido = NULL;
        free(conjuntoAmigos[i].email);
        conjuntoAmigos[i].email = NULL;
    }
    free(conjuntoAmigos);
    conjuntoAmigos = NULL;
}

void liberarLocais()
{
    for(int i = 0; i < num_Locais;i++)
    {
        free(conjuntoLocais[i].nome);
        conjuntoLocais[i].nome = NULL;
        free(conjuntoLocais[i].endereco.logradouro);
        conjuntoLocais[i].endereco.logradouro = NULL;
        free(conjuntoLocais[i].endereco.num);
        conjuntoLocais[i].endereco.num = NULL;
        free(conjuntoLocais[i].endereco.bairro);
        conjuntoLocais[i].endereco.bairro = NULL;
        free(conjuntoLocais[i].endereco.cidade);
        conjuntoLocais[i].endereco.cidade = NULL;
        free(conjuntoLocais[i].endereco.estado);
        conjuntoLocais[i].endereco.estado = NULL;
    }
    free(conjuntoLocais);
    conjuntoLocais = NULL;
}

void liberarCategorias()
{
    for(int i = 0; i < num_Categorias;i++)
    {
        free(conjuntoCategorias[i].nome);
        conjuntoCategorias[i].nome = NULL;
    }
    free(conjuntoCategorias);
    conjuntoCategorias = NULL;
}

void liberarEncontros()
{
    for(int i = 0; i < num_Encontros;i++)
    {
        free(mEncontros[i].amigos);
        mEncontros[i].amigos = NULL;
        free(mEncontros[i].descricao);
        mEncontros[i].descricao = NULL;
        free(mEncontros[i].local.nome);
        mEncontros[i].local.nome = NULL;
        free(mEncontros[i].local.endereco.logradouro);
        mEncontros[i].local.endereco.logradouro = NULL;
        free(mEncontros[i].local.endereco.num);
        mEncontros[i].local.endereco.num = NULL;
        free(mEncontros[i].local.endereco.bairro);
        mEncontros[i].local.endereco.bairro = NULL;
        free(mEncontros[i].local.endereco.cidade);
        mEncontros[i].local.endereco.cidade = NULL;
        free(mEncontros[i].local.endereco.estado);
        mEncontros[i].local.endereco.estado = NULL;
        free(mEncontros[i].categoria.nome);
        mEncontros[i].categoria.nome = NULL;
    }
    free(mEncontros);
    mEncontros = NULL;
}

void salvarDados()
{   
    salvarAmigos();
    salvarLocais();
    salvarCategorias();
    salvarEncontros();

    printf("Dados salvos com sucesso!!!\n");
}

void recuperarDados()
{
    recuperarAmigos();
    recuperarLocais();
    recuperarCategorias();
    recuperarEncontros();
}

void liberarMemoria()
{
    liberarAmigos();
    liberarLocais();
    liberarCategorias();
    liberarEncontros();

    printf("Memória liberada com sucesso!!!\n");
}

int validarHorario(int h, int m)
{
    int valido = 0;
    if(h < 0 || h > 23) {
        valido = 0;
    } else if(m < 0 || m > 59) {
        valido = 0;
    } else {
        valido = 1;
    }

    return valido;
}

int validarTel(char tel[])
{
    int valido = 1;
    int tam = strlen(tel);

    if(tam != 13){
        valido = 0;
    }

    return valido;
}

void validarAlocacao(void *ptr)
{
    if (ptr == NULL) 
    {
        error(-2);
        exit(1);  
    }
}

void sair()
{
    system("cls");
    printf("Saindo");
    
    for(int i = 0; i < 3; i++){
        printf(".");
        sleep(1);
    }
    printf("\n");
}

void exibirAmigos()
{
    if (num_Amigos == 0) {
        error(-6);
        return;
    }

    printf("Lista de Amigos:\n\n");
    for (int i = 0; i < num_Amigos; i++) {
        printf("Amigo [%d]:\n", i + 1);
        printf("Nome: %s\n", conjuntoAmigos[i].nome);
        printf("Apelido: %s\n", conjuntoAmigos[i].apelido);
        printf("Email: %s\n", conjuntoAmigos[i].email);
        printf("Telefone: %s\n", conjuntoAmigos[i].telefone);
        printf("Data de Nascimento: %.2d/%.2d/%.2d\n\n", 
        conjuntoAmigos[i].nascimento.dia,
        conjuntoAmigos[i].nascimento.mes,
        conjuntoAmigos[i].nascimento.ano);
    }
}

void exibirLocais()
{
    if(num_Locais == 0){
        error(-6);
        return;
    }

    printf("LIsta de Locais:\n\n");
    for(int j = 0; j < num_Locais;j++){
        printf("Local [%d]:\n", j + 1);
        printf("Nome: %s\n", conjuntoLocais[j].nome);
        printf("Logradouro: %s\n", conjuntoLocais[j].endereco.logradouro);
        printf("Número: %s\n", conjuntoLocais[j].endereco.num);
        printf("Bairro: %s\n", conjuntoLocais[j].endereco.bairro);
        printf("Cidade: %s\n", conjuntoLocais[j].endereco.cidade);
        printf("Estado: %s\n\n", conjuntoLocais[j].endereco.estado);
    }
}

void exibirCategorias()
{
    if(num_Categorias == 0){
        error(-6);
        return;
    }

    printf("Lista de Categorias:\n\n");
    for(int k = 0; k < num_Categorias; k++){
        printf("Categoria [%d]:\n", k + 1);
        printf("Nome: %s\n", conjuntoCategorias[k].nome);
        printf("\n");
    }
}

void exibirTodosEncontros()
{
    if (num_Encontros == 0) {
        error(-6);
        return;
    }

    for (int i = 0; i < num_Encontros; i++) 
    {
        printf("\nDetalhes do Encontro [%d]:\n\n", i + 1);
        printf("Data do Encontro: %.2d/%.2d/%.2d\n", mEncontros[i].data.dia, mEncontros[i].data.mes, mEncontros[i].data.ano);
        printf("Horario: %.2d:%.2d\n", mEncontros[i].horario.hora, mEncontros[i].horario.minuto);
        printf("Categoria: %s\n", mEncontros[i].categoria.nome);
        printf("Local: %s\n", mEncontros[i].local.nome);
        printf("Endereço: %s, %s, %s - %s\n", 
        mEncontros[i].local.endereco.logradouro, 
        mEncontros[i].local.endereco.num,
        mEncontros[i].local.endereco.bairro,
        mEncontros[i].local.endereco.cidade);
        printf("Estado: %s\n", mEncontros[i].local.endereco.estado);
        printf("Descricao: %s\n", mEncontros[i].descricao);
        printf("Amigos presentes:\n");
        for (int j = 0; j < mEncontros[i].num_AmigIncl; j++) {
            printf("- %s (%s)\n", mEncontros[i].amigos[j]->nome, mEncontros[i].amigos[j]->apelido);
        }

        printf("\n");
    }
}

void relatorioCategoria()
{
    if(num_Categorias == 0){
        error(-6);
        return;
    }

    for(int g = 0; g < num_Categorias;g++)
    {
        conjuntoCategorias[g].num_Enc = 0;
    }

    for(int i = 0; i < num_Encontros; i++)
    {
        for(int j = 0; j < num_Categorias; j++)
        {
            if(strcmp(mEncontros[i].categoria.nome, conjuntoCategorias[j].nome) == 0)
            {
                conjuntoCategorias[j].num_Enc++;
            }
        }
    }

    printf("Relátorio em relação às categorias existentes:\n");
    for(int k = 0; k < num_Categorias; k++){
        printf("(%d) - %s [%d]\n", k + 1, conjuntoCategorias[k].nome,conjuntoCategorias[k].num_Enc);
    }
}

void subMenu()
{
    printf("-------------------------\n");
    printf("(1) - Incluir\n");
    printf("(2) - Alterar\n");
    printf("(3) - Excluir \n");
    printf("-------------------------\n");
    printf("Digite a opção:\n");
}

int validarEmail(char email[])
{
    int contAt = 0;
    int contDot = 0;
    int valido = 0;

    for(int i = 0; email[i] != '\0'; i++)
    {
        if(email[i] == '@'){
            contAt++;
        } else if(email[i] == '.'){
            contDot++;
        }
    }

    if(contAt != 1 || contDot < 1)
    {
        valido = 0;
    }else{
        valido = 1;
    }

    return valido;
}

void error(int e)
{
    switch(e)
    {
    case -1:
        printf("Opção inválida!!!");
        break;
    case -2:
        printf("Error ao alocar memória!!!");
        break;
    case -3:
        printf("Não há registro para excluir.");
        break;
    case -4:
        printf("Não há registro para alterar.");
        break;
    case -5:
        printf("Erro ao abrir o arquivo!!!");
        break;
    case -6:
        printf("Não há registro para exibir.");
        break;
    case -7:
        printf("Telefone inválido!!!\n");
        break;
    case -8:
        printf("Data inválida!!!\n");
        break;
    case -9:
        printf("Horário inválido!!!\n");
        break;
    case -10:
        printf("Email inválido!!!\n");
        break;
    }

    printf("\n");
    system("pause");
}

void menuOpcoesManterAmigos()
{
    printf("-------------------------\n");
    printf("(1) - Incluir Amigo\n");
    printf("(2) - Alterar Amigo\n");
    printf("(3) - Excluir Amigo\n");
    printf("-------------------------\n");
    printf("Digite a opção:\n");
}

void menuOpcoesManterLocais()
{
    printf("-------------------------\n");
    printf("(1) - Incluir Local\n");
    printf("(2) - Alterar Local\n");
    printf("(3) - Excluir Local\n");
    printf("-------------------------\n");
    printf("Digite a opção:\n");
}

void menuOpcoesManterCategorias()
{
    printf("-------------------------\n");
    printf("(1) - Incluir Categoria\n");
    printf("(2) - Alterar Categoria\n");
    printf("(3) - Excluir Categoria\n");
    printf("-------------------------\n");
    printf("Digite a opção:\n");
}

void menuOpcoesManterEncontros()
{
    printf("-------------------------\n");
    printf("(1) - Incluir Encontro\n");
    printf("(2) - Alterar Encontro\n");
    printf("(3) - Excluir Encontro\n");
    printf("-------------------------\n");
    printf("Digite a opção:\n");
}