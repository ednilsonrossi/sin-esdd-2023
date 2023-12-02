#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct lista* Lista;

typedef int Infotype;

Lista criar();

bool insere_inicio(Lista lista, Infotype info);

bool insere_final(Lista lista, Infotype info);

bool insere_ordenado(Lista lista, Infotype info);

bool apagar(Lista lista, Infotype info);

void imprime_lista(Lista lista);