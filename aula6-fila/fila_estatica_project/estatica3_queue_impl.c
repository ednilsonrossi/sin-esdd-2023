#include "queue.h"

struct queue{
    Element items[QUEUE_MAX_SIZE];
    int last, first, size;
};


void init(Queue* queue){
    Queue q;
    q = malloc(sizeof(struct queue));
    q->last = -1;
    q->first = -1;
    q->size = 0;
    *queue = q;
}

bool is_full(Queue queue){
    return queue->size == QUEUE_MAX_SIZE;
}

bool is_empty(Queue queue){
    return queue->size == 0;
}

bool enqueue(Queue queue, Element new_element){
    bool answer = false;
    if(! is_full(queue)){
        if(queue->last == QUEUE_MAX_SIZE - 1){
            queue->last = 0;
        }else{
            queue->last += 1;
        }
        queue->items[queue->last] = new_element;
        queue->size += 1;
        answer = true;
    }
    return answer;
}

Element dequeue(Queue queue){
    Element answer = ' ';
    if(!is_empty(queue)){
        if(queue->first == QUEUE_MAX_SIZE - 1){
            queue->first = 0;
        }else{
            queue->first += 1;
        }
        queue->size -= 1;
        answer = queue->items[queue->first];
    }
    return answer;
}