#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#define DEFAULT_SIZE 5

typedef struct mec_projeto *Projeto;

Projeto criar(int numero, double valor);

double obtemValor(Projeto projeto);

char* paraImpressao(Projeto projeto);