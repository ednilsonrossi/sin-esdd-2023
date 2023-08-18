#include <stdio.h>

int main(int argc, char const *argv[]){
    
    int variavel;   //Declaração de variável
    int *ponteiro;  //Declaração de ponteiro

    ponteiro = &variavel;   //Define para onde o ponteiro aponta

    variavel = 5;
    
    *ponteiro = variavel + 10;  //Executa operação no conteúdo do ponteiro
    
    printf("Variável: %d\n", variavel);
    return 0;
}
