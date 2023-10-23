#include "lse.h"

int main(int argc, char const *argv[])
{
    Lista lst;
    Info informacao;

    lst = lista_criar();

    lista_adiciona(lst, 5);
    lista_adiciona(lst, 10);
    lista_adiciona(lst, 15);
    lista_adiciona(lst, 20);
    lista_adiciona(lst, 25);
    lista_adiciona(lst, 30);


    for(int i=0; i != 6; i++){
        informacao = lista_obtemInfo(lst, i);
        printf("Lista[%d]: %d\n", i, informacao);
    }

    lista_destroi(lst);

    return 0;
}
