#include <stdio.h>
#define SIZE 6
void gerar_vetor(int array[]);

int main(int argc, char const *argv[]){
    int dados[6];
    gerar_vetor(dados);
    for(int index = 0; index != SIZE; index += 1){
        printf("Valor do dado: %d\n", dados[index]);
    }
    return 0;
}

void gerar_vetor(int array[]){
    for(int i = 1; i != 7; i++){
        array[i-1] = i;
    }
}