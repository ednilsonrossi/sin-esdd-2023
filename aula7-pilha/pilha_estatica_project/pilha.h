/*
 * File:   pilha.h
 * Author: Ednilson Rossi
 *
 * Created on 02 de outubro de 2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 20


/**
 * Define o tipo de dado Pilha.
*/
typedef struct stack* Pilha;

/**
 * Define o tipo de informação que será armazenado na pilha.
*/
typedef int Tipo_Informacao;


/**
 * Operação responsável por iniciarlizar uma pilha, recebe como argumento
 * um ponteiro para uma pilha, cria a pilha alterando o argumento ponteiro
 * de entrada/saída.
*/
void init(Pilha* pilha);


/**
 * Operação recebe como argumento uma pilha e retorna true caso a pilha 
 * esteja cheia ou retorna false caso a pilha não esteja cheia.
*/
bool is_full(Pilha pilha);


/**
 * Operação recebe como argumento uma pilha e retorna true caso a pilha
 * esteja vazia, ou seja, sem elementos, ou retorna false caso a pilha
 * não esteja vazia.
*/
bool is_empty(Pilha pilha);


/**
 * Operação recebe como argumento uma pilha e um elemento que será inserido
 * no TOPO da pilha. Caso seja realizada a operação de inserção a operação
 * retorn true, caso ocorra alguma problema a operação retorna false, nesse
 * caso, o elemento não é inserido na pilha.
*/
bool push(Pilha pilha, Tipo_Informacao elemento);


/**
 * Operação remove o elemento que está no topo da pilha. São passados como 
 * argumentos a pilha que terá o elemento removido e um ponteiro para que
 * o elemento removido seja atribuído. Caso seja possível remover o elemento
 * a operaçõa retorna true, caso contrário o retorno será false.
*/
bool pop(Pilha pilha, Tipo_Informacao* elemento);