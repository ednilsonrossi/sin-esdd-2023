#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct conta{
    int numero;
    double saldo;
};

/*
int main(int argc, char const *argv[]){
    struct conta contaJose;

    contaJose.numero = 123;
    contaJose.saldo = 100.0;

    printf("Número conta: %d \t Saldo: R$ %.2lf\n", contaJose.numero, contaJose.saldo);

    return 0;
}
*/

/*
int main(int argc, char const *argv[]){
    
    struct conta *ponteiro;

    ponteiro = malloc( sizeof(struct conta) );

    ponteiro->numero = 123;
    ponteiro->saldo = 100.0;

    printf("Número conta: %d \t Saldo: R$ %.2lf\n", ponteiro->numero, ponteiro->saldo);

    return 0;
}
*/

int main(int argc, char const *argv[]){
    
    struct conta *ponteiro;
    struct conta variavel;

    ponteiro = malloc( sizeof(struct conta) );

    ponteiro->numero = 123;
    ponteiro->saldo = 100.0;

    variavel.numero = 456;
    variavel.saldo = 500.0;

    printf("Número conta: %d \t Saldo: R$ %.2lf\n", ponteiro->numero, ponteiro->saldo);
    printf("Número conta: %d \t Saldo: R$ %.2lf\n", variavel.numero, variavel.saldo);

    free(ponteiro);
    return 0;
}

