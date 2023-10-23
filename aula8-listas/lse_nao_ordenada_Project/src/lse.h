#include "node.h"

typedef struct lista* Lista;

/*
 * Define uma nova lista. A lista definida sempre será vazia.
 */
Lista lista_criar();

/*
 * Em uma lista já existente, inclui-se um novo node contendo uma
 * referência (ponteiro) para um livro. Esse novo node é inserido
 * no final da lista.
 *
 * A operação retorna TRUE(1) se inseriu com sucesso e FALSE(0) se
 * houve algum erro.
 */
bool lista_adiciona(Lista lista, Info data);

/*
 * Verifica se a posição desejada pelo usuário existe na lista passada
 * como argumento para a operação. Caso a posição seja válida e exista
 * na lista, a operação retorna um ponteiro para uma Info. Caso a posição
 * seja inválida ou não exista na lista ou a lista esteja vazia retorna-se
 * o valor NULO.
 */
Info lista_obtemInfo(Lista lista, int posicao);

/*
 * Verifica se uma lista está ou não vazia. Retorna 1 se a lista está vazia
 */
bool lista_estaVazia(Lista lista);

/**
  * Destroi a lista passada como argumento.
  * Operação retorna TRUE se conseguiu destruir a lista e FALSE
  * se não conseguiu destruir a lista.
  **/
bool lista_destroi(Lista lista);