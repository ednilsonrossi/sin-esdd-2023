#include "queue.h"
/*
struct queue{
    Element items[QUEUE_MAX_SIZE];
    int last;
};


void init(Queue* queue){
    Queue q;
    q = malloc(sizeof(struct queue));
    q->last = -1;
    *queue = q;
}

bool is_full(Queue queue){
    return queue->last == QUEUE_MAX_SIZE - 1;
}

bool is_empty(Queue queue){
    return queue->last == -1;
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
        answer = queue->items[0];
        for(int i = 0; i < queue->last; i += 1){
            queue->items[i] = queue->items[i+1];
        }
        queue->last -= 1;
    }
    return answer;
}
*/