#include "queue.h"

void mostra_fila(Queue fila);

int main(int argc, char const *argv[])
{
    Queue fila;

    init(&fila);
    printf("Enqueue A: %s.\n", enqueue(fila, 'A') ? "OK" : "ERRO");
    printf("Enqueue B: %s.\n", enqueue(fila, 'B') ? "OK" : "ERRO");
    printf("Enqueue C: %s.\n", enqueue(fila, 'C') ? "OK" : "ERRO");
    printf("Enqueue D: %s.\n", enqueue(fila, 'D') ? "OK" : "ERRO");
    printf("Enqueue E: %s.\n", enqueue(fila, 'E') ? "OK" : "ERRO");
    mostra_fila(fila);
    
    //printf("Dequeue: %c.\n", dequeue(fila));
    //printf("Dequeue: %c.\n", dequeue(fila));
    //mostra_fila(fila);

    printf("Enqueue (fura) F: %s.\n", fura_fila(fila, 'F') ? "FUROU" : "ERRO");
    mostra_fila(fila);
    printf("Enqueue (fura) G: %s.\n", fura_fila(fila, 'G') ? "FUROU" : "ERRO");
    mostra_fila(fila);

    printf("Enqueue A: %s.\n", enqueue(fila, 'A') ? "OK" : "ERRO");
    printf("Enqueue B: %s.\n", enqueue(fila, 'B') ? "OK" : "ERRO");
    printf("Enqueue C: %s.\n", enqueue(fila, 'C') ? "OK" : "ERRO");
    mostra_fila(fila);


    return 0;
}

void mostra_fila(Queue fila){
    Queue temp;
    Element elemento;
    init(&temp);
    while(!is_empty(fila)){
        enqueue(temp, dequeue(fila));
    }

    printf("\n*** Fila ***\n");
    while(!is_empty(temp)){
        elemento = dequeue(temp);
        printf("Elemento: %c.\n", elemento);
        enqueue(fila, elemento);
    }
    printf("************\n");
}
