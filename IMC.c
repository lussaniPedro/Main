#include <stdio.h>
#include <stdlib.h>

/* Declaração de funções */
float calcularTMB(float peso, float altura, int idade, char sexo); // Função que calcula a taxa metabólica basal (Mifflin-St Jeor)
float calcularCalorias(float tmb, int nivel_atividade); // Função que calcula as calorias 
float calcularIMC(float peso, float altura); // Função que calcula o índice de massa corporal
void classificarIMC(float imc); // Função que classifica o IMC
void pedir_dados(); // Função que pega os dados do usuário

typedef struct{
    float peso;
    float altura;
    int idade;
    int nivel_atividade;
    char sexo;
} TPessoa;

int main(){
    pedir_dados();
    return 0;
}

void pedir_dados(){
    TPessoa pessoa;
    char op;

    system("cls");
    printf("Digite seu peso em kg: ");
    scanf("%f", &pessoa.peso);
    fflush(stdin);
    system("cls");

    printf("Digite sua altura em metros: ");
    scanf("%f", &pessoa.altura);
    fflush(stdin);
    system("cls");

    printf("Digite sua idade em anos: ");
    scanf("%d", &pessoa.idade);
    fflush(stdin);
    system("cls");

    printf("Digite seu sexo (M para masculino, F para feminino): ");
    scanf(" %c", &pessoa.sexo);
    fflush(stdin);
    system("cls");

    printf("Nivel de atividade fisica (1-Sedentario, 2-Levemente ativo, 3-Moderadamente ativo, 4-Muito ativo, 5-Extremamente ativo): ");
    scanf("%d", &pessoa.nivel_atividade);
    fflush(stdin);
    system("cls");

    printf("Deseja manter suas informacoes em sigilo? Digite (S) para sim e qualquer outra tecla para nao: ");
    scanf("%c", &op);
    fflush(stdin);
    system("cls");

    if(op != 's' && op != 'S'){
        printf("[Peso(KG): %.2f, Altura(M): %.2f, Idade: %d, Sexo: ", pessoa.peso, pessoa.altura, pessoa.idade);
        if(pessoa.sexo == 'M' || pessoa.sexo == 'm'){
            printf("Masculino]\n\n");
        } else{
            printf("Feminino]\n\n");
        }
    }

    float imc = calcularIMC(pessoa.peso, pessoa.altura);
    printf("Seu IMC eh: %.2f\n", imc);
    classificarIMC(imc);

    float tmb = calcularTMB(pessoa.peso, pessoa.altura * 100, pessoa.idade, pessoa.sexo);
    printf("Sua TMB eh: %.2f calorias/dia\n\n", tmb);

    float calorias_diarias = calcularCalorias(tmb, pessoa.nivel_atividade);
    printf("| [Voce deve consumir aproximadamente %.2f calorias/dia para manter seu peso.]\n", calorias_diarias);

    float calorias_emagrecer = calorias_diarias - 500;
    float calorias_ganhar = calorias_diarias + 500;

    printf("| [Para emagrecer, voce deve consumir cerca de %.2f calorias/dia.]\n", calorias_emagrecer);
    printf("| [Para ganhar massa, voce deve consumir cerca de %.2f calorias/dia.]\n", calorias_ganhar);
}

float calcularIMC(float peso, float altura){
    return peso / (altura * altura);
}
 
float calcularTMB(float peso, float altura, int idade, char sexo){
    if (sexo == 'M' || sexo == 'm'){
        return 10 * peso + 6.25 * altura - 5 * idade + 5;
    } else{
        return 10 * peso + 6.25 * altura - 5 * idade - 161;
    }
}

float calcularCalorias(float tmb, int nivel_atividade){
    float fator;

    switch(nivel_atividade){
        case 1: 
            fator = 1.2;
            break;
        case 2:
            fator = 1.375;
            break;
        case 3: 
            fator = 1.55;
            break;
        case 4: 
            fator = 1.725;
            break;
        case 5: 
            fator = 1.9;
            break;
        default:
            printf("Nivel de atividade invalido.\n");
            return 0;
    }
    
    return tmb * fator;
}

void classificarIMC(float imc){
    if(imc < 18.5){
        printf("Voce esta abaixo do peso.\n\n");
    } else if(imc >= 18.5 && imc < 24.9){
        printf("Voce esta no peso ideal.\n\n");
    } else if(imc >= 25 && imc < 29.9){
        printf("Voce esta com sobrepeso.\n\n");
    } else if(imc >= 30 && imc < 34.9){
        printf("Voce esta com obesidade classe I.\n\n");
    } else if(imc >= 35 && imc < 39.9){
        printf("Voce esta com obesidade classe II.\n\n");
    } else{
        printf("Voce esta com obesidade classe III.\n\n");
    }
}