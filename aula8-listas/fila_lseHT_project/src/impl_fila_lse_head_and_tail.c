#include "queue.h"
 
typedef struct node* Node;

struct node{
    Element info;
    Node next;
};

struct queue{
    Node inicio; //HEAD
    Node fim;    //TAIL
};

void init(Queue* queue){
    *queue = malloc(sizeof(struct queue));
    (*queue)->inicio = NULL;
    (*queue)->fim = NULL;
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

        if(is_empty(queue)){
            queue->inicio = novo;
            queue->fim = novo;
        }else{
            queue->fim->next = novo;
            queue->fim = novo;
        }
        return true;
    }
    return false;
}

Element dequeue(Queue queue){
    Element resposta;
    if(queue != NULL){
        if(!is_empty(queue)){
            Node rip = queue->inicio;
            resposta = rip->info;
            if(rip->next == NULL){
                queue->fim = NULL;
                queue->inicio = NULL;
            }else{
                queue->inicio = rip->next;
            }
            free(rip);
        }
    }
    return resposta;
}