#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N_VAGAS 5

typedef struct estacionamento* Estacionamento;

void init(Estacionamento* park);

bool is_full(Estacionamento park);

bool is_empty(Estacionamento park);

bool input(Estacionamento park, int placa);

int output(Estacionamento park);