#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
}TData;

typedef struct 
{
    int hora;
    int minuto;
}THora;

typedef struct 
{
    char *nome_curso;
    int ano_curso;
}TCurso;

typedef struct
{
    int minutos_jogados;
    int gols;
    int assistencias;
    int faltas;
    int cartoes_amarelos;
    int cartoes_vermelhos;
}THistorico;

typedef struct
{
    char *nome_jogador;
    TData data_nascimento;
    int numero_camisa;
    int rank;
    TCurso turma;
    THistorico historico;
}TJogador;

typedef struct 
{
    TData data_partida;
    THora hora_partida;
    TJogador *jogadores;
    int qtd_jogadores;
    char *local_partida;
    char *adversario;
}TPartida;

void menu();
void cadastro(TJogador **jogadores, TPartida **partidas, int *qtd_jogadores, int *qtd_partidas);
void relatorios(TJogador *jogadores, TPartida *partidas, int *qtd_jogadores, int *qtd_partidas);
void disparaOpMenu(int opcao, TJogador **jogadores, TPartida **partidas, int *qtd_jogadores, int *qtd_partidas);
void incluirJogadores(TJogador **jogadores, int *qtd_jogadores);
void incluirPartidas(TJogador **jogadores, TPartida **partidas, int *qtd_jogadores, int *qtd_partidas);
void listarJogadores(TJogador *jogadores, int *qtd_jogadores);
void listarPartidas(TPartida *partidas, int *qtd_partidas);

int main()
{
    TJogador *jogadores = NULL;
    TPartida *partidas = NULL;
    int qtd_partidas = 0;
    int qtd_jogadores = 0;
    int opcao;

    do{
        menu();
        scanf("%d", &opcao);
        fflush(stdin);

        disparaOpMenu(opcao, &jogadores, &partidas, &qtd_jogadores, &qtd_partidas);
    } while(opcao != 0);

    return 0;
}

/* Menus e controles de menu */
void menu(){
    system("cls");

    printf("-- Cadastro de Partidas --\n");
    printf("(1) - Cadastrar\n");
    printf("(2) - Relatorios\n");
    printf("(0) - Sair\n\n");

    printf("** Escolha uma opcao: ");
}

void disparaOpMenu(int opcao, TJogador **jogadores, TPartida **partidas, int *qtd_jogadores, int *qtd_partidas){
    system("cls");
    switch(opcao){
        case 1:
            cadastro(jogadores, partidas, qtd_jogadores, qtd_partidas);
            break;
        case 2:
            relatorios(*jogadores, *partidas, qtd_jogadores, qtd_partidas);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("**ERRO! Opcao invalida!!!**\n");
            system("pause");
            break;
    }
}

void cadastro(TJogador **jogadores, TPartida **partidas, int *qtd_jogadores, int *qtd_partidas){
    int opcao;

    do{
        system("cls");
        printf("-- Cadastro de Partidas --\n");
        printf("(1) - Cadastrar Partida\n");
        printf("(2) - Cadastrar Jogador\n");
        printf("(0) - Voltar ao menu anterior\n\n");

        printf("** Escolha uma opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);

        system("cls");
        switch(opcao){
            case 1:
                incluirPartidas(jogadores, partidas, qtd_jogadores, qtd_partidas);
                break;
            case 2:
                incluirJogadores(jogadores, qtd_jogadores);
                break;
            case 0:
                break;
            default:
                printf("**ERRO! Opcao invalida!!!**\n");
                system("pause");
                break;
        }
    } while(opcao != 0);
}

void relatorios(TJogador *jogadores, TPartida *partidas, int *qtd_jogadores, int *qtd_partidas){
    int opcao;

    do{
        system("cls");
        printf("-- Relatorios --\n");
        printf("(1) - Listar Partidas\n");
        printf("(2) - Listar Jogadores\n");
        printf("(0) - Voltar ao menu anterior\n\n");

        printf("** Escolha uma opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);

        system("cls");
        switch(opcao){
            case 1:
                listarPartidas(partidas, qtd_partidas);
                system("pause");
                break;
            case 2:
                listarJogadores(jogadores, qtd_jogadores);
                system("pause");
                break;
            case 0:
                break;
            default:
                printf("**ERRO! Opcao invalida!!!**\n");
                system("pause");
                break;
        }
    } while(opcao != 0);
}

/* Inclusão de dados */
void incluirJogadores(TJogador **jogadores, int *qtd_jogadores){
    while(1){
        if(*qtd_jogadores == 0){
            *jogadores = (TJogador*)malloc(1 * sizeof(TJogador));
        } else{
            *jogadores = (TJogador*)realloc(*jogadores, (*qtd_jogadores + 1) * sizeof(TJogador));
        }

        char strAux[100];

        system("cls");
        printf("Nome do jogador: ");
        gets(strAux);
        (*jogadores)[*qtd_jogadores].nome_jogador = (char*)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy((*jogadores)[*qtd_jogadores].nome_jogador, strAux);

        printf("Data de nascimento (DD MM AAAA): ");
        scanf("%d%d%d", &(*jogadores)[*qtd_jogadores].data_nascimento.dia, &(*jogadores)[*qtd_jogadores].data_nascimento.mes, &(*jogadores)[*qtd_jogadores].data_nascimento.ano);
        fflush(stdin);

        bool check;
        do{
            check = true;

            printf("Numero da camisa: ");
            scanf("%d", &(*jogadores)[*qtd_jogadores].numero_camisa);
            fflush(stdin);

            for(int i = 0; i < *qtd_jogadores; i++){
                if((*jogadores)[i].numero_camisa == (*jogadores)[*qtd_jogadores].numero_camisa){
                    check = false;
                    printf("\n** Erro! Numero ja cadastrado! **\n\n");
                    break;
                }
            }
        } while(!check);

        printf("Rank: ");
        scanf("%d", &(*jogadores)[*qtd_jogadores].rank);
        fflush(stdin);

        printf("\nNome do curso: ");
        gets(strAux);
        (*jogadores)[*qtd_jogadores].turma.nome_curso = (char*)malloc((strlen(strAux) + 1) * sizeof(char));
        strcpy((*jogadores)[*qtd_jogadores].turma.nome_curso, strAux);
    
        printf("Ano do curso: ");
        scanf("%d", &(*jogadores)[*qtd_jogadores].turma.ano_curso);
        fflush(stdin);
    
        printf("\nHistorico do jogador:\n");
    
        printf("- Minutos jogados: ");
        scanf("%d", &(*jogadores)[*qtd_jogadores].historico.minutos_jogados);
        fflush(stdin);
    
        printf("- Gols: ");
        scanf("%d", &(*jogadores)[*qtd_jogadores].historico.gols);
        fflush(stdin);
    
        printf("- Assistencias: ");
        scanf("%d", &(*jogadores)[*qtd_jogadores].historico.assistencias);
        fflush(stdin);
    
        printf("- Faltas: ");
        scanf("%d", &(*jogadores)[*qtd_jogadores].historico.faltas);
        fflush(stdin);
    
        do{
            printf("- Cartoes amarelos: ");
            scanf("%d", &(*jogadores)[*qtd_jogadores].historico.cartoes_amarelos);
            fflush(stdin);

            if((*jogadores)[*qtd_jogadores].historico.cartoes_amarelos < 0 || (*jogadores)[*qtd_jogadores].historico.cartoes_amarelos > 2){
                printf("\n** Erro! Numero invalido! **\n\n");
            }
        } while((*jogadores)[*qtd_jogadores].historico.cartoes_amarelos < 0 || (*jogadores)[*qtd_jogadores].historico.cartoes_amarelos > 2);

        if((*jogadores)[*qtd_jogadores].historico.cartoes_amarelos == 2){
            (*jogadores)[*qtd_jogadores].historico.cartoes_vermelhos = 1;
            printf("** O jogador recebeu 1 cartao vermelho por ter recebido 2 cartoes amarelos! **\n");
            system("pause");
        } else{
            do{
                printf("- Cartoes vermelhos: ");
                scanf("%d", &(*jogadores)[*qtd_jogadores].historico.cartoes_vermelhos);
                fflush(stdin);

                if((*jogadores)[*qtd_jogadores].historico.cartoes_vermelhos < 0 || (*jogadores)[*qtd_jogadores].historico.cartoes_vermelhos > 1){
                    printf("\n** Erro! Numero invalido! **\n\n");
                }
            } while((*jogadores)[*qtd_jogadores].historico.cartoes_vermelhos < 0 || (*jogadores)[*qtd_jogadores].historico.cartoes_vermelhos > 1);
        }

        (*qtd_jogadores)++;

        system("cls");
        printf("Jogador cadastrado com sucesso!!!\n\n");
        system("pause");

        char opSn;
        do{
            system("cls");
            printf("** Deseja cadastrar mais um jogador (S/N)? ");
            scanf("%c", &opSn);
            fflush(stdin);
    
            opSn = tolower(opSn);
            if (opSn != 's' && opSn != 'n'){
                printf("**Erro! Opcao inexistente!**\n\n");
            }
        } while (opSn != 's' && opSn != 'n');

        if(opSn == 'n'){
            break;
        }
    }
}

void incluirPartidas(TJogador **jogadores, TPartida **partidas, int *qtd_jogadores, int *qtd_partidas){
    if(*qtd_partidas == 0){
        *partidas = (TPartida*)malloc(1 * sizeof(TPartida));
    } else{
        *partidas = (TPartida*)realloc(*partidas, (*qtd_partidas + 1) * sizeof(TPartida));
    }

    char strAux[100];

    system("cls");
    printf("Data da partida (DD MM AAAA): ");
    scanf("%d%d%d", &(*partidas)[*qtd_partidas].data_partida.dia, &(*partidas)[*qtd_partidas].data_partida.mes, &(*partidas)[*qtd_partidas].data_partida.ano);
    fflush(stdin);

    printf("Hora da partida (HH MM): ");
    scanf("%d%d", &(*partidas)[*qtd_partidas].hora_partida.hora, &(*partidas)[*qtd_partidas].hora_partida.minuto);
    fflush(stdin);

    printf("Local da partida: ");
    gets(strAux);
    (*partidas)[*qtd_partidas].local_partida = (char*)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy((*partidas)[*qtd_partidas].local_partida, strAux);

    printf("Adversario: ");
    gets(strAux);
    (*partidas)[*qtd_partidas].adversario = (char*)malloc((strlen(strAux) + 1) * sizeof(char));
    strcpy((*partidas)[*qtd_partidas].adversario, strAux);

    (*partidas)[*qtd_partidas].qtd_jogadores = 0;

    if(*qtd_jogadores == 0){
        printf("\nNao ha jogadores cadastrados!\n");
        printf("Voce sera redirecionado para cadastrar um jogador.");
        system("pause");

        incluirJogadores(jogadores, qtd_jogadores);
    }

    if(*qtd_jogadores < 7){
        do{
            printf("\nNao ha jogadores suficientes cadastrados!\n");
            printf("Voce sera redirecionado para cadastrar mais jogadores.");
            system("pause");
    
            incluirJogadores(jogadores, qtd_jogadores);
        } while(*qtd_jogadores < 7);
        
    } else if(*qtd_jogadores > 7){
        (*partidas)[*qtd_partidas].jogadores = (TJogador*)malloc(14 * sizeof(TJogador));

        int numJogador;
        char opSn = 's';

        while((*partidas)[*qtd_partidas].qtd_jogadores < 14 && opSn == 's'){
            bool check;
            do{
                check = true;
                listarJogadores(*jogadores, qtd_jogadores);
    
                printf("Qual jogador deseja selecionar para a partida (1-%d)? ", *qtd_jogadores);
                scanf("%d", &numJogador);
                fflush(stdin);
                numJogador--;
    
                for(int i = 0; i < (*partidas)[*qtd_partidas].qtd_jogadores; i++){
                    if((*partidas)[*qtd_partidas].jogadores[i].numero_camisa == (*jogadores)[numJogador].numero_camisa){
                        check = false;
                        printf("\n** Erro! Jogador ja selecionado! **\n\n");
                        break;
                    }
                }
            } while(!check);

            if(numJogador < 0 || numJogador >= *qtd_jogadores){
                printf("**ERRO! Numero invalido!**\n");
            } else{
                (*partidas)[*qtd_partidas].jogadores[(*partidas)[*qtd_partidas].qtd_jogadores] = (*jogadores)[numJogador];
                (*partidas)[*qtd_partidas].qtd_jogadores++;
            }

            if((*partidas)[*qtd_partidas].qtd_jogadores >= 7){
                printf("** Deseja adicionar mais um jogador (S/N)? ");
                scanf("%c", &opSn);
                fflush(stdin);

                opSn = tolower(opSn);
                if (opSn != 's' && opSn != 'n'){
                    printf("**Erro! Opcao inexistente!**\n\n");
                    opSn = 'n';
                }
            }
        }
    } else{
        (*partidas)[*qtd_partidas].jogadores = (*jogadores);
    }

    (*qtd_partidas)++;

    system("cls");
    printf("Partida cadastrada com sucesso!!!\n\n");
    system("pause");
}

/* Listagem de dados */
void listarJogadores(TJogador *jogadores, int *qtd_jogadores){
    if(*qtd_jogadores == 0){
        printf("Nao ha jogadores cadastrados!\n");
        system("pause");
        return;
    }

    system("cls");
    for(int i = 0; i < *qtd_jogadores; i++){
        printf("\n*** Jogador [%d] ***\n", i + 1);

        printf("Nome: %s\n", jogadores[i].nome_jogador);
        printf("Data de nascimento: %02d/%02d/%04d\n", jogadores[i].data_nascimento.dia, jogadores[i].data_nascimento.mes, jogadores[i].data_nascimento.ano);
        printf("Numero da camisa: %d\n", jogadores[i].numero_camisa);
        printf("Rank: %d\n\n", jogadores[i].rank);

        printf("Curso: %s\n", jogadores[i].turma.nome_curso);
        printf("Ano do curso: %d\n\n", jogadores[i].turma.ano_curso);

        printf("Historico:\n");
        printf("- Minutos jogados: %d\n", jogadores[i].historico.minutos_jogados);
        printf("- Gols: %d\n", jogadores[i].historico.gols);
        printf("- Assistencias: %d\n", jogadores[i].historico.assistencias);
        printf("- Faltas: %d\n", jogadores[i].historico.faltas);
        printf("- Cartoes amarelos: %d\n", jogadores[i].historico.cartoes_amarelos);
        printf("- Cartoes vermelhos: %d\n", jogadores[i].historico.cartoes_vermelhos);
    }
    printf("\n");
}

void listarPartidas(TPartida *partidas, int *qtd_partidas){
    if(*qtd_partidas == 0){
        printf("Nao ha partidas cadastradas!\n");
        system("pause");
        return;
    }

    system("cls");
    for(int i = 0; i < *qtd_partidas; i++){
        printf("\n*** Partida [%d] ***\n", i + 1);

        printf("Data da partida: %02d/%02d/%04d\n", partidas[i].data_partida.dia, partidas[i].data_partida.mes, partidas[i].data_partida.ano);
        printf("Hora da partida: %02d:%02d\n", partidas[i].hora_partida.hora, partidas[i].hora_partida.minuto);
        printf("Local da partida: %s\n", partidas[i].local_partida);
        printf("Adversario: %s\n\n", partidas[i].adversario);

        printf("Jogadores selecionados:\n");
        for(int j = 0; j < partidas[i].qtd_jogadores; j++){
            printf("- %s (Camisa %d)\n", partidas[i].jogadores[j].nome_jogador, partidas[i].jogadores[j].numero_camisa);
        }
    }
    printf("\n");
}