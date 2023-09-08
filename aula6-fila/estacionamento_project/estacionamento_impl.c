#include "estacionamento.h"

struct estacionamento{
    int array[N_VAGAS];
    int contador;
};

void init(Estacionamento* park){
    Estacionamento e;
    e = malloc(sizeof(struct estacionamento));
    e->contador = 0;
    *park = e;
}

bool is_full(Estacionamento park){
    return park->contador == N_VAGAS;
}

bool is_empty(Estacionamento park){
    return park->contador == 0;
}

bool input(Estacionamento park, int placa){
    if(!is_full(park)){
        park->array[park->contador] = placa;
        park->contador += 1;
        return true;
    }
    return false;
}

int output(Estacionamento park){
    int saida;
    if(!is_empty(park)){
        saida = park->array[0];
        for(int i=0; i < park->contador - 1; i++){
            park->array[i] = park->array[i+1];
        }
        park->contador -= 1;
        return saida;
    }
    return -1;
}