#include <stdio.h>
#define TRUE 1
#define FALSE 0

int conta_digitos(int input, int digit);

int main(int argc, char const *argv[])
{
    int number_1, number_2, index;
    int is_permutation = TRUE;

    printf("Informe dois números inteiros: \n");
    scanf("%d%d", &number_1, &number_2);

    index = 1;
    while (index <= 9 && is_permutation){
        if(conta_digitos(number_1, index) != conta_digitos(number_2, index)){
            is_permutation = FALSE;
        }
        index += 1;
    }
    
    if(is_permutation == TRUE){
        printf("%d e %d são permutação.\n", number_1, number_2);
    }else{
        printf("%d e %d não são permutação.\n", number_1, number_2);
    }

    return 0;
}


int conta_digitos(int input, int digit){
    int counter, bit;

    counter = 0;
    while (input > 0){
        bit = input % 10;
        if(bit == digit){
            counter += 1;
        }
        input = input / 10;
    }
    
    return counter;
}