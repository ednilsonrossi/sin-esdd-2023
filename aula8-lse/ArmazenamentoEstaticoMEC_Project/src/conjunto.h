#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#include "tad_projeto.h"

typedef struct conjunto* Conjunto;

typedef Projeto Info;

bool init(Conjunto* conjunto);

bool insert(Conjunto conjunto, Info item);

Info getAt(Conjunto conjunto, int position);

int size(Conjunto conjunto);