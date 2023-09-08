#include "queue.h"

int main(int argc, char const *argv[])
{
    Queue fila;

    init(&fila);
    printf("Enqueue A: %s.\n", enqueue(fila, 'A') ? "OK" : "ERRO");
    printf("Enqueue B: %s.\n", enqueue(fila, 'B') ? "OK" : "ERRO");
    printf("Enqueue C: %s.\n", enqueue(fila, 'C') ? "OK" : "ERRO");
    printf("Enqueue D: %s.\n", enqueue(fila, 'D') ? "OK" : "ERRO");
    printf("Enqueue E: %s.\n", enqueue(fila, 'E') ? "OK" : "ERRO");
    printf("Enqueue F: %s.\n", enqueue(fila, 'F') ? "OK" : "ERRO");
    printf("Enqueue G: %s.\n", enqueue(fila, 'G') ? "OK" : "ERRO");
    printf("Enqueue H: %s.\n", enqueue(fila, 'H') ? "OK" : "ERRO");
    printf("Enqueue I: %s.\n", enqueue(fila, 'I') ? "OK" : "ERRO");
    printf("Enqueue J: %s.\n", enqueue(fila, 'J') ? "OK" : "ERRO");
    printf("Enqueue K: %s.\n", enqueue(fila, 'K') ? "OK" : "ERRO");
    printf("Enqueue L: %s.\n", enqueue(fila, 'L') ? "OK" : "ERRO");

    printf("\n\nDequeue All:\n");
    while(!is_empty(fila)){
        printf("Dequeued: %c.\n", dequeue(fila));
    }

    printf("Enqueue A: %s.\n", enqueue(fila, 'A') ? "OK" : "ERRO");
    printf("Enqueue B: %s.\n", enqueue(fila, 'B') ? "OK" : "ERRO");
    return 0;
}
