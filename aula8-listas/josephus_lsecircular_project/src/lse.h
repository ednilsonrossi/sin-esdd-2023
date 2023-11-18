/*
 * File:   lse.h
 * Author: Ednilson Rossi
 *
 * Created on 18 de novembro de 2023.
 * 
 * Definição de um TAD que manipula uma Lista Simplesmente Encadeada (LSE).
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct lse* List;

typedef int Infotype;

/**
 * Operação que inicializa a lista
*/
void init_list(List* list);

/**
 * Operação informa se a lista está vazia
*/
bool is_empty_list(List list);

/**
 * Operação insere elemento no final da lista
*/
void insert_end_list(List list, Infotype info);

/**
 * Operação insere no início da lista.
*/
void insert_begin_list(List list, Infotype info);

/**
 * Operação que remove o primeiro elemento da lista
*/
Infotype delete_begin_list(List list);

/**
 * Operação que o último elemento da lista
*/
Infotype delete_end_list(List list);

/**
 * Devolve o valor da info do nó sobrevivente, ou seja, o último nó
 * a ser removido. Ao final a lista estará vazia.
*/
Infotype josephus(List list, int step);