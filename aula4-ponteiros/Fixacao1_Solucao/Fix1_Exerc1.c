/**
 * Autor: Ednilson Geraldo Rossi
 * E-mail: ednilsonrossi@ifsp.edu.br
 * Data: 24/08/2023
 * 
 * A compilação demanda a inclusão da diretiva -lm, desa forma,
 * o comando para compilar é:
 * 
 *      gcc Fix1_Exerc1.c -lm
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/**
 * Função recebe os valores de a, b e c (passagem de parâmetro
 * por valor, visto que esses dados não serão alterados pela
 * função) e recebe a referência da variável delta (ponteiro) para
 * que o resultado altere o valor desse ponteiro.
*/
void calcular_delta(float a, float b, float c, float* delta);


/**
 * Função recebe por valor os dados de uma equação do 2o grau. 
 * Os argumentos possui_raizes, x1 e x2 são ponteiros que recebem 
 * os resultados da equação.
*/
void calcular_raizes(float a, float b, float c, bool* possui_raizes, float* x1, float* x2);



int main(int argc, char const *argv[]){
    
    float a, b, c;
    bool tem_solucao;
    float raiz1, raiz2;

    printf("Informe os valores de A, B e C: \n");
    scanf("%f%f%f", &a, &b, &c);

    calcular_raizes(a, b, c, &tem_solucao, &raiz1, &raiz2);

    if (tem_solucao == true){
        printf("Raízes: \n\tX' --> %f\n\tX'' -> %f\n\n", raiz1, raiz2);
    }else{
        printf("Problema não possui raízes\n\n");
    }

    return 0;
}


void calcular_raizes(float a, float b, float c, bool* possui_raizes, float* x1, float* x2){
    float dlt;

    calcular_delta(a, b, c, &dlt);
    if(dlt < 0){
        *possui_raizes = false;
    } else if(dlt == 0){
        *possui_raizes = true;
        *x1 = (-b) / (2 * a);
        *x2 = *x1;
    } else{
        *possui_raizes = true;
        *x1 = (-b + sqrt(dlt)) / (2 * a);
        *x2 = (-b - sqrt(dlt)) / (2 * a);
    }
}

void calcular_delta(float a, float b, float c, float* delta){
    *delta = pow(b, 2) - 4 * a * c;
}