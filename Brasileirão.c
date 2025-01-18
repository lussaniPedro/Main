#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define BLUE printf("\033[0;34m");
#define ORANGE printf("\033[38;5;214m");
#define RED printf("\033[0;31m");
#define GREEN printf("\033[0;32m");
#define WHITE printf("\033[0;37m");
#define BLACK printf("\033[0;30m");

typedef struct{
    char *nome;
    int pontos;
    int vitorias;
    int cartoes;
    int gols;
} TTime;

/* Declaração de funções */
void menu();
void op_menu(int opcao);
void incluirTime();
TTime criarTime();
void listarTime();
void op_listar(int op);
void menu_listar();
void exibirTabela();
void exibirTime(int index);
void mostrarQualificacao();
void excluirTime();
void ordernarTimes();
void limparMemoria();
void salvarDados();
void carregarDados();
void valida_alocacao(void *ptr);

TTime *times;
int numTimes = 0;

int main(){
    int op;

    SetConsoleOutputCP(65001);
    carregarDados();

    do{
        menu();

        scanf("%d", &op);
        fflush(stdin);

        system("cls");
        op_menu(op);
    } while(op != 0);

    salvarDados();
    limparMemoria();
    return 0;
}

void menu(){
    system("cls");
    printf("\n---- MENU ----\n");
    printf("1. Incluir time\n");
    printf("2. Listar times\n");
    printf("3. Mostrar qualificações\n");
    printf("4. Alterar time\n");
    printf("5. Excluir time\n");
    printf("0. Sair\n\n");
    printf("** Escolha uma opcao: ");
}

void op_menu(int opcao){
    switch(opcao){
        case 1:
            incluirTime();
            system("pause");
            break;
        case 2:
            listarTime();
            system("pause");
            break;
        case 3:
            mostrarQualificacao();
            system("pause");
            break;
        case 5:
            excluirTime();
            system("pause");
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }
}

void incluirTime(){
    if(numTimes == 0){
        times = (TTime *)malloc(1 * sizeof(TTime));
    } else{
        times = (TTime *)realloc(times, (numTimes + 1) * sizeof(TTime));
    }
    valida_alocacao(times);
    times[numTimes] = criarTime();
    numTimes++;

    printf("\n** Time adicionado com sucesso! **\n");
}

TTime criarTime(){
    TTime time;
    char strAux[100];

    printf("Nome do time: ");
    gets(strAux);
    time.nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy(time.nome, strAux);
    valida_alocacao(time.nome);

    printf("Pontos: ");
    scanf("%d", &time.pontos);
    fflush(stdin);

    printf("Vitorias: ");
    scanf("%d", &time.vitorias);
    fflush(stdin);

    printf("Saldo de gols: ");
    scanf("%d", &time.gols);
    fflush(stdin);

    printf("Cartoes: ");
    scanf("%d", &time.cartoes);
    fflush(stdin);

    return time;
}

void listarTime(){
    int op;

    if(numTimes == 0){
        printf("Nenhum time cadastrado!\n");
        return;
    }

    if(numTimes == 1){
        exibirTabela();
    } else{
        menu_listar();
        scanf("%d", &op);
        op_listar(op);
    }
}

void op_listar(int op){
    int indice;
    system("cls");
    switch (op){
        case 1:
            exibirTabela();
            break;
        case 2:
            printf("** Qual time deseja exibir [%d-%d]? ", 1, numTimes);
            scanf("%d", &indice);
            system("cls");
            BLACK printf("\n%-4s | %-15s | %-6s | %-4s | %-6s | %-7s\n", "Pos", "Nome", "Pts", "SG", "Vit", "Cart");
            exibirTime(indice - 1);
            printf("\n");
            break;
        case 3:
            return;
        default:
            printf("Numero invalido!!!");
            break;
    }
    mostrarQualificacao();
}

void menu_listar(){
    system("cls");
    printf("1. Exibir tabela\n");
    printf("2. Exibir um time\n");
    printf("3. Voltar ao menu inicial\n\n");
    printf("** Digite a opcao desejada: ");
}

void exibirTabela(){
    BLACK printf("\n%-4s | %-15s | %-6s | %-4s | %-6s | %-7s\n", "Pos", "Nome", "Pts", "SG", "Vit", "Cart");
    for(int i = 0; i < numTimes; i++){
        exibirTime(i);
    }
    printf("\n");
}

void exibirTime(int index){
    ordernarTimes();
    if(index >= 0 && index <= 3){
        WHITE printf("%-4d ", index + 1);
        BLUE printf("| ");
        WHITE printf("%-15s | %-6d | %-4d | %-6d | %-7d\n", times[index].nome, times[index].pontos, times[index].gols, times[index].vitorias, times[index].cartoes);
    } else if(index == 4 || index == 5){
        WHITE printf("%-4d ", index + 1);
        ORANGE printf("| ");
        WHITE printf("%-15s | %-6d | %-4d | %-6d | %-7d\n", times[index].nome, times[index].pontos, times[index].gols, times[index].vitorias, times[index].cartoes);
    } else if(index >= 6 && index <= 11){
        WHITE printf("%-4d ", index + 1);
        GREEN printf("| ");
        WHITE printf("%-15s | %-6d | %-4d | %-6d | %-7d\n", times[index].nome, times[index].pontos, times[index].gols, times[index].vitorias, times[index].cartoes);
    } else if(index >= numTimes - 4 && index <= numTimes && index != 18){
        WHITE printf("%-4d ", index + 1);
        RED printf("| ");
        WHITE printf("%-15s | %-6d | %-4d | %-6d | %-7d\n", times[index].nome, times[index].pontos, times[index].gols, times[index].vitorias, times[index].cartoes);
    } else if(index == 18){
        WHITE printf("%-4d ", index + 1);
        RED printf("| ");
        WHITE printf("%-15s | %-6d | %-4d | %-6d | %-7d\n", times[index].nome, times[index].pontos, times[index].gols, times[index].vitorias, times[index].cartoes);
    } else{
        WHITE printf("%-4d ", index + 1);
        WHITE printf("| ");
        WHITE printf("%-15s | %-6d | %-4d | %-6d | %-7d\n", times[index].nome, times[index].pontos, times[index].gols, times[index].vitorias, times[index].cartoes);
    }
    WHITE
}

void mostrarQualificacao(){
    printf("Qualificacao/Rebaixamento\n\n");
    printf("🟦  Fase de grupos da Copa Libertadores\n");
    printf("🟧  Qualificatorias da Copa Libertadores\n");
    printf("🟩  Fase de grupos da Copa Sul-Americana\n");
    printf("🟥  Rebaixamento\n\n");
}

void excluirTime() {
    int index;
    if (numTimes == 0) {
        printf("Nenhum time cadastrado para excluir!\n");
        return;
    }

    exibirTabela();
    printf("Digite o numero do time que deseja excluir [1-%d]: ", numTimes);
    scanf("%d", &index);

    if(index > 0 && index <= numTimes){
        free(times[index - 1].nome);
        for(int i = index - 1; i < numTimes - 1; i++){
            times[i] = times[i + 1];
        }
        times = (TTime *)realloc(times, (numTimes - 1) * sizeof(TTime));
        numTimes--;
        printf("\nTime excluido com sucesso!\n");
    } else{
        printf("Numero invalido!\n");
    }
}

void ordernarTimes(){
    int i, j;
    int troca;
    TTime temp;

    for(i = 0; i < numTimes - 1; i++){
        troca = 0; 
        for(j = 0; j < numTimes - i - 1; j++){
            if(times[j].pontos < times[j + 1].pontos){
                temp = times[j];
                times[j] = times[j + 1];
                times[j + 1] = temp;
                troca = 1;  
            } else if(times[j].pontos == times[j + 1].pontos && times[j].vitorias < times[j + 1].vitorias){
                temp = times[j];
                times[j] = times[j + 1];
                times[j + 1] = temp;
                troca = 1;
            } else if(times[j].pontos == times[j + 1].pontos && times[j].vitorias == times[j + 1].vitorias && times[j].gols < times[j + 1].gols){
                temp = times[j];
                times[j] = times[j + 1];
                times[j + 1] = temp;
                troca = 1;
            } else if(times[j].pontos == times[j + 1].pontos && times[j].vitorias == times[j + 1].vitorias && times[j].gols == times[j + 1].gols && times[j].cartoes > times[j + 1].cartoes){
                temp = times[j];
                times[j] = times[j + 1];
                times[j + 1] = temp;
                troca = 1;
            }
        }

        if(troca == 0){
            break;
        }
    }
}

void limparMemoria() {
    for (int i = 0; i < numTimes; i++) {
        free(times[i].nome);
    }
    free(times);
}

void valida_alocacao(void *ptr) {
    if (!ptr) {
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }
}

/* Funções de salvar e carregar os dados */
void salvarDados(){
    FILE *arquivo = fopen("times.txt", "w");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo para salvar!\n");
        return;
    }

    fprintf(arquivo, "%d\n", numTimes);
    for(int i = 0; i < numTimes; i++){
        fprintf(arquivo, "%s\n", times[i].nome);
        fprintf(arquivo, "%d %d %d %d\n", times[i].pontos, times[i].vitorias, times[i].gols, times[i].cartoes);
    }

    fclose(arquivo);
    printf("** Dados salvos com sucesso!\n");
}

void carregarDados(){
    FILE *arquivo = fopen("times.txt", "r");
    if(arquivo == NULL){
        printf("Nenhum arquivo de dados encontrado. Iniciando sem dados preexistentes.\n");
        return;
    }

    fscanf(arquivo, "%d\n", &numTimes);
    times = (TTime *)malloc(numTimes * sizeof(TTime));
    valida_alocacao(times);

    for(int i = 0; i < numTimes; i++){
        char strAux[100];
        fgets(strAux, 100, arquivo);
        strAux[strcspn(strAux, "\n")] = 0;
        times[i].nome = (char *)malloc((strlen(strAux) + 1) * sizeof(char));
        valida_alocacao(times[i].nome);
        strcpy(times[i].nome, strAux);

        fscanf(arquivo, "%d %d %d %d\n", &times[i].pontos, &times[i].vitorias, &times[i].gols, &times[i].cartoes);
    }

    fclose(arquivo);
}