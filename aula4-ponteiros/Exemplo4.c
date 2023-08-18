#include <stdio.h>

int main(int argc, char const *argv[]){
    
    int contador;
    int *contadorPtr;

    contador = 7;
    contadorPtr = &contador;

    printf("Valor de contador...: %d - endereço de memória %p\n", contador, &contador);
    printf("Valor de contadorPtr: %p - conteúdo da variável apontada: %d\n", contadorPtr, *contadorPtr);

    return 0;
}
