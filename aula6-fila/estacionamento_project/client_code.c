#include "estacionamento.h"

void encher_garagem(Estacionamento garagem){
    printf("%d %s\n", 1234, input(garagem, 1234)?"entrou.":"não entrou.");
    printf("%d %s\n", 2345, input(garagem, 2345)?"entrou.":"não entrou.");
    printf("%d %s\n", 3456, input(garagem, 3456)?"entrou.":"não entrou.");
    printf("%d %s\n", 4567, input(garagem, 4567)?"entrou.":"não entrou.");
    printf("%d %s\n", 5678, input(garagem, 5678)?"entrou.":"não entrou.");
    printf("%d %s\n", 6789, input(garagem, 6789)?"entrou.":"não entrou.");
}

void tirar_da_garagem(Estacionamento garagem, int qtdade){
    for(int i = 0; i < qtdade; i++){
        printf("%d saiu.\n", output(garagem));
    }
}

void relatorio(Estacionamento garagem){
    int placa, i;
    Estacionamento rua;
    init(&rua);

    printf("\n--------------\n");
    printf("Relatório do estacionamento: \n");
    i = 1;
    while(!is_empty(garagem)){
        placa = output(garagem);
        printf("Posição %d - Carro %d\n", i, placa);
        i++;
        input(rua, placa);
    }

    while(!is_empty(rua)){
        input(garagem, output(rua));
    }

    printf("\n--------------\n\n");
}

void busca(Estacionamento garagem, int key){
    int placa;
    printf("Remover veículo específico (%d):\n\n", key);
    do{
        placa = output(garagem);
        if(placa != key){
            input(garagem, placa);
        }
    }while(placa != key);
    printf("Removido: %d\n\n", placa);
}

int main(int argc, char const *argv[])
{
    Estacionamento garagem;

    init(&garagem);
    encher_garagem(garagem);
    tirar_da_garagem(garagem, 3);
    encher_garagem(garagem);
    relatorio(garagem);
    busca(garagem, 2345);
    relatorio(garagem);
    
    return 0;
}
