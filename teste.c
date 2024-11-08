#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} TData;

typedef struct
{
    char *nome;
    char *nomMat;
    char *conteudo;
    TData data;
    char *atv;
} TProfessor;

typedef struct 
{
    char *nome;
    char *turma;
    TData data;
} TAluno;

typedef struct 
{
    char *nome;
    char *local;
    char *periodo;
    int vagas;
    char *numero;
    TData data;
} TCarona;

int lerOpcao();
int lerProf();
int lerConteudo();
int lerAluno();
void justificaFalta();
void printarConteudo(int auxAluno);
void printarFaltas();
void lerCarona();
void cadastrarCarona();
void printarCarona();
void salvarAluno();
void salvarProf();
void salvarCarona();
int valide_data(int dias, int mes, int ano);
void liberarPonteiros();

TProfessor *cont;
TAluno *faltas;
TCarona *motorista;
int numProf = -1, numAluno = -1, numCar = -1;

int main()
{
    SetConsoleOutputCP(65001);
    int op1 = 1, opProf = 1, opAluno = 1;

    while (op1 != 0)
    {
        op1 = lerOpcao();
        switch (op1)
        {
        case 1:
            opProf = 1;
            while (opProf != 0)
            {
                opProf = lerProf();
                switch (opProf)
                {
                case 1:
                    lerConteudo();
                    break;
                case 2:
                    printarFaltas();
                    break;
                }
            }
            break;
        case 2:
            opAluno = 1;
            while (opAluno != 0)
            {
                opAluno = lerAluno();
                switch(opAluno)
                {
                    case 1:
                        justificaFalta();
                        break;
                    case 2:
                        lerCarona();
                        break;
                }
            }
            break;
        }
    }
    salvarAluno();
    salvarProf();
    salvarCarona();
    liberarPonteiros();
}

int lerOpcao()
{
    int aux;
    printf("Bem vindo!!\n");
    printf("Selecione a opção desejada: \n");
    printf("1) Sou professor\n");
    printf("2) Sou aluno\n");
    printf("0) Encerrar o programa\n");
    scanf("%d", &aux);
    system("cls");
    return aux;
}

int lerProf()
{
    int aux;
    printf("1) Cadastrar aula\n");
    printf("2) Ver faltas\n"); 
    printf("0) Voltar\n");
    scanf("%d", &aux);
    system("cls");
    return aux;
}

int lerConteudo()
{
    int auxDat = 0;
    char strAux[1000];
    numProf++;
    cont = (TProfessor *)realloc(cont, numProf + 1 * sizeof(TProfessor));

    printf("Digite o seu nome: \n"); // leitura do nome do professor
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    cont[numProf].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(cont[numProf].nome, strAux);

    printf("Digite o nome da sua matéria :\n"); // leitura do nome da materia
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    cont[numProf].nomMat = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(cont[numProf].nomMat, strAux);

    printf("Digite a data da sua aula(DD MM AAAA, sem barras): \n");
    while (auxDat == 0)
    {
        scanf("%d%d%d", &cont[numProf].data.dia, &cont[numProf].data.mes, &cont[numProf].data.ano);
        auxDat = valide_data(cont[numProf].data.dia, cont[numProf].data.mes, cont[numProf].data.ano);
        if (auxDat == 0)
        {
            printf("Valor invalido!\n");
        }
    }
    printf("Digite resumidamente o conteudo que foi lecionado: \n"); // leitura do conteudo
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    cont[numProf].conteudo = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(cont[numProf].conteudo, strAux);

    printf("Digite a atividade pra suprir a falta: \n"); // leitura da atividade
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    cont[numProf].atv = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(cont[numProf].atv, strAux);

    system("cls");
}

int lerAluno()
{
    int aux;
    printf("1) Justificar falta\n");
    printf("2) Caronas\n");
    printf("0) Voltar\n");
    scanf("%d", &aux);
    system("cls");
    return aux;
}

void justificaFalta()
{
    char strAux[100];
    int auxDat = 0;
    numAluno++;
    faltas = (TAluno *)realloc(faltas, numAluno + 1 * sizeof(TAluno));
    
    printf("Qual seu nome?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    faltas[numAluno].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(faltas[numAluno].nome, strAux);

    
    printf("Qual sua turma?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    faltas[numAluno].turma = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(faltas[numAluno].turma, strAux);
    

    while (auxDat == 0)
    {
        printf("Qual dia você que justificar? (DD MM AAAA, sem barras)\n");
        fflush(stdin);
        scanf("%d %d %d", &faltas[numAluno].data.dia, &faltas[numAluno].data.mes, &faltas[numAluno].data.ano);
        fflush(stdin);
        auxDat = valide_data(faltas[numAluno].data.dia, faltas[numAluno].data.mes, faltas[numAluno].data.ano);
        if (auxDat == 0)
        {
            printf("Valor invalido!\n");
        }
    }
    system("cls");
    printarConteudo(numAluno);
}

void printarConteudo(int auxAluno)
{
    int i = 0, j = 0;
    for (i = 0; i < numProf + 1; i++)
    {
        if(faltas[auxAluno].data.dia == cont[i].data.dia && faltas[auxAluno].data.mes == cont[i].data.mes && faltas[auxAluno].data.ano == cont[i].data.ano)
        {
            printf("Nome do professor: ");
            puts(cont[i].nome);
            printf("Nome da matéria: ");
            puts(cont[i].nomMat);
            printf("Data: %d/%d/%d\n", cont[i].data.dia, cont[i].data.mes, cont[i].data.ano);
            printf("Conteudo lecionado: ");
            puts(cont[i].conteudo);
            printf("Atividade de reposição: ");
            puts(cont[i].atv);
            printf("\n");
            j++;   
        }
    }
    if(j == 0)
    {
        printf("Nenhum conteudo no dia selecionado!\n");
    }
}

void printarFaltas()
{
    int i;
    for (i = 0; i < numAluno + 1; i++)
    {
        printf("Nome do aluno: ");
        puts(faltas[i].nome);
        printf("Nome da turma: ");
        puts(faltas[i].turma);
        printf("Data: %d/%d/%d\n\n", faltas[i].data.dia, faltas[i].data.mes, faltas[i].data.ano);
    }
}

void lerCarona()
{
    int opCarona;
    opCarona = 3;
    printf("1) Cadastrar carona\n");
    printf("2) Ver caronas disponiveis\n");
    scanf("%d", &opCarona);
    system("cls");
    switch(opCarona)
    {
        case 1:
            cadastrarCarona();
            break;
        case 2:
            printarCarona();
            break;
    }
}

void cadastrarCarona()
{
    int auxDat = 0;
    char strAux[100];
    numCar++;
    motorista = (TCarona *)realloc(cont, numCar + 1 * sizeof(TCarona));

    printf("Qual seu nome?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    motorista[numCar].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(motorista[numCar].nome, strAux);

    printf("Qual o local?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    motorista[numCar].local = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(motorista[numCar].local, strAux);

    printf("Qual o periodo/horario da carona?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    motorista[numCar].periodo = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(motorista[numCar].periodo, strAux);

    printf("Tem quantas vagas no carro?\n");
    scanf("%d", &motorista[numCar].vagas);

    while (auxDat == 0)
    {
        printf("Qual a data da carona? (DD MM AAAA, sem barras)\n");
        scanf("%d%d%d", &motorista[numCar].data.dia, &motorista[numCar].data.mes, &motorista[numCar].data.ano);
        auxDat = valide_data(motorista[numCar].data.dia, motorista[numCar].data.mes, motorista[numCar].data.ano);
        if (auxDat == 0)
        {
            printf("Valor invalido!\n");
        }
    }

    printf("Qual seu numero pra contato?\n");
    fflush(stdin);
    gets(strAux);
    fflush(stdin);
    motorista[numCar].numero = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(motorista[numCar].numero, strAux);

    system("cls");
}

void printarCarona()
{
    int i;
    for(i = 0; i < numCar + 1; i++)
    {
        printf("Nome do motorista: ");
        puts(motorista[i].nome);
        printf("Local da carona: ");
        puts(motorista[i].local);
        printf("Periodo/horario da carona: ");
        puts(motorista[i].periodo);
        printf("Numero de vagas: %d\n", motorista[i].vagas);
        printf("Data: %d/%d/%d\n", motorista[numCar].data.dia, motorista[numCar].data.mes, motorista[numCar].data.ano);
        printf("Numero pra contato: ");
        puts(motorista[numCar].numero);
        printf("\n");
    }
}

void salvarAluno()
{
    int i, j;
    FILE *pArq;

    pArq = fopen("alunosBD.txt", "w");
    for (i = 0; i < numAluno + 1; i++)
    {
        printf("%s", faltas[0].nome);
        fprintf(pArq, "%s;", faltas[i].nome);
        fprintf(pArq, "%s;", faltas[i].turma);
        fprintf(pArq, "%d;", faltas[i].data.dia);
        fprintf(pArq, "%d;", faltas[i].data.mes);
        fprintf(pArq, "%d;", faltas[i].data.ano);
        fprintf(pArq, "%c", '\n');
    }
    fclose(pArq);

}

void salvarProf()
{
    int i, j;
    FILE *pArq1;

    pArq1 = fopen("profBD.txt", "w");
    for (i = 0; i < numProf + 1; i++)
    {
        fprintf(pArq1, "%s;", cont[i].nome);
        fprintf(pArq1, "%s;", cont[i].nomMat);
        fprintf(pArq1, "%d;", cont[i].data.dia);
        fprintf(pArq1, "%d;", cont[i].data.mes);
        fprintf(pArq1, "%d;", cont[i].data.ano);
        fprintf(pArq1, "%s;", cont[i].conteudo);
        fprintf(pArq1, "%s;", cont[i].atv);
        fprintf(pArq1, "%c", '\n');
    }
    fclose(pArq1);
}

void salvarCarona()
{
    int i, j;
    FILE *pArq2;

    pArq2 = fopen("caronasBD.txt", "w");
    for (i = 0; i < numCar + 1; i++)
    {
        fprintf(pArq2, "%s;", motorista[i].nome);
        fprintf(pArq2, "%s;", motorista[i].local);
        fprintf(pArq2, "%s;", motorista[i].periodo);
        fprintf(pArq2, "%d;", motorista[i].vagas);
        fprintf(pArq2, "%d;", motorista[i].data.dia);
        fprintf(pArq2, "%d;", motorista[i].data.mes);
        fprintf(pArq2, "%d;", motorista[i].data.ano);
        fprintf(pArq2, "%s;", motorista[i].numero);
        fprintf(pArq2, "%c", '\n');
    }
    fclose(pArq2);
}

void liberarPonteiros()
{
    int i;
    for(i = 0; i < numAluno + 1; i++)
    {
        free(faltas[i].nome);
        free(faltas[i].turma);
    }
    for(i = 0; i < numProf + 1; i++)
    {
        free(cont[i].nome);
        free(cont[i].nomMat);
        free(cont[i].conteudo);
        free(cont[i].atv);
    }
    for(i = 0; i < numCar + 1; i++)
    {
        free(motorista[i].nome);
        free(motorista[i].periodo);
        free(motorista[i].local);
        free(motorista[i].numero);
    }
    free(faltas);
    free(cont);
    free(motorista);
}
int valide_data(int dias, int mes, int ano)
{
    if (mes > 12 || mes <= 0)
    {
        return 0;
    }
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    {
        if (dias <= 0 || dias > 31)
        {
            return 0;
        }
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        if (dias <= 0 || dias > 30)
        {
            return 0;
        }
    }
    if (ano % 4 == 0 && mes == 2)
    {
        if (dias <= 0 || dias > 29)
        {
            return 0;
        }
    }
    else if (mes == 2)
    {
        if (dias <= 0 || dias > 28)
        {
            return 0;
        }
    }
    return 1;
}