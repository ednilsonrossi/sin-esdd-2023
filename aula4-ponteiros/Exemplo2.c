#include <stdio.h>

void ler(int arg);

int main(int argc, char const *argv[]){
    int number = -1;

    ler(number);
    printf("O valor de number é %d.\n", number);

    return 0;
}

void ler(int arg){
    printf("-------------------------\n");
    printf("Valor antigo: %d.\n", arg);
    printf("Digite novo valor: ");
    scanf("%d", &arg);
    printf("Valor novo: %d.\n", arg);
    printf("-------------------------\n");
}