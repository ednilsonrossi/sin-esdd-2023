#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Define o tamanho máximo da fila.
*/
#define QUEUE_MAX_SIZE 10

/**
 * Define o tipo de dado que será manipulado pela fila.
*/
typedef char Element;

/**
 * Define que a fila (Queue) é um PONTEIRO para uma
 * struct queue. Independente da definição da struct
 * o TAD deve atender as especificações apontadas.
*/
typedef struct queue* Queue;


/**
 * Inicializa o queue
*/
void init(Queue* queue);


/**
 * Retorna se a queue está cheia em função da 
 * constante QUEUE_MAX_SIZE.
*/
bool is_full(Queue queue);

/**
 * Retorna se a queue está vazia ou não.
*/
bool is_empty(Queue queue);

/**
 * Insere um novo elemento no final da fila.
*/
bool enqueue(Queue queue, Element new_element);

/**
 * Remove o primeiro elemento da fila.
*/
Element dequeue(Queue queue);
