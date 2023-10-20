#include "tad_projeto.h"

struct mec_projeto{
    int numero;
    double valor;
};

Projeto criar(int numero, double valor){
    Projeto pj;

    pj = malloc(sizeof(struct mec_projeto) );
    pj->numero = numero;
    pj->valor = valor;

    return pj;
}

double obtemValor(Projeto projeto){
    return projeto->valor;
}

char* paraImpressao(Projeto projeto){
    char* string;
    string = malloc(sizeof(char) * 90);
    snprintf(string, 90, "Projeto [numero = %d, valor = R$ %.2f]", projeto->numero, projeto->valor);
    return string;
}