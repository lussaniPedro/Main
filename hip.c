#include <stdio.h>
#include <math.h>
void pedir_catetos();
float calcular_hipotenusa(float cat1, float cat2);

int main(){
    pedir_catetos();
    return 0;    
}

void pedir_catetos(){
    float cateto, cateto2, result;
    printf("Digite cateto 1: ");
    scanf("%f", &cateto);

    printf("Digite cateto 2: ");
    scanf("%f", &cateto2);

    result = calcular_hipotenusa(cateto, cateto2);

    printf("O resultado eh: %.2f", result);
}

float calcular_hipotenusa(float cat1, float cat2){
    float hip;
    cat1 = pow(cat1, 2);
    cat2 = pow(cat2, 2);

    hip = cat1 + cat2;

    return sqrt(hip);
}