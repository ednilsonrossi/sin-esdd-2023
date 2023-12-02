#include "lde.h"

int main(int argc, char const *argv[])
{
    Lista l;

    l = criar();
    insere_ordenado(l, 7);
    insere_ordenado(l, 12);
    insere_ordenado(l, 5);
    insere_ordenado(l, 13);
    imprime_lista(l);

    apagar(l, 5);
    imprime_lista(l);

    return 0;
}
