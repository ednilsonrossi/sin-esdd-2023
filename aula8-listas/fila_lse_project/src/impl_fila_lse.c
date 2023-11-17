#include "queue.h"

typedef struct node* Node;

struct node{
    Element info;
    Node next;
};

struct queue{
    Node inicio;
};

void init(Queue* queue){
    *queue = malloc(sizeof(struct queue));
    (*queue)->inicio = NULL;
}

bool is_full(Queue queue){
    return false;
}

bool is_empty(Queue queue){
    return queue->inicio == NULL;
}

bool enqueue(Queue queue, Element new_element){
    if(queue != NULL){
        Node novo = malloc(sizeof(struct node));
        novo->info = new_element;
        novo->next = NULL;

        if(queue->inicio == NULL){
            queue->inicio = novo;
            return true;
        }else{
            Node walker = queue->inicio;
            while(walker->next != NULL){
                walker = walker->next;
            }
            walker->next = novo;
            return true;
        }
    }
    return false;
}

Element dequeue(Queue queue){
    Element answer;
    if(queue != NULL){
        if(!is_empty(queue)){
            Node rip = queue->inicio;
            answer = rip->info;
            queue->inicio = rip->next;
            free(rip);
        }
    } 
    return answer;
}