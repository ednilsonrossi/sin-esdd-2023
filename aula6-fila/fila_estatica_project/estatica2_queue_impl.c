/*
#include "queue.h"

struct queue{
    Element items[QUEUE_MAX_SIZE];
    int last, first;
};


void init(Queue* queue){
    Queue q;
    q = malloc(sizeof(struct queue));
    q->last = -1;
    q->first = -1;
    *queue = q;
}

bool is_full(Queue queue){
    return queue->last == QUEUE_MAX_SIZE - 1;
}

bool is_empty(Queue queue){
    return queue->last == queue->first;
}

bool enqueue(Queue queue, Element new_element){
    bool answer = false;
    if(! is_full(queue)){
        queue->last += 1;
        queue->items[queue->last] = new_element;
        answer = true;
    }
    return answer;
}

Element dequeue(Queue queue){
    Element answer = ' ';
    if(!is_empty(queue)){
        queue->first += 1;
        answer = queue->items[queue->first];
    }
    return answer;
}
*/