#include "lde.h"

struct node{
    struct node* prev;
    Infotype info;
    struct node* next;
};

typedef struct node* Node;

struct lista{
    Node head;
};

Lista criar(){
    Lista lista = malloc(sizeof(struct lista));
    lista->head = NULL;
    return lista;
}

bool insere_inicio(Lista lista, Infotype info){
    if(lista != NULL){
        Node novo = malloc(sizeof(struct node));
        novo->info = info;
        novo->prev = NULL;
        if(lista->head == NULL){
            //Lista vazia
            novo->next = NULL;
        }else{
            //Lista possui dados
            novo->next = lista->head;
            lista->head->prev = novo;
        }
        lista->head = novo;
        return true;
    }
    return false;
}

bool insere_final(Lista lista, Infotype info){
    if(lista != NULL){
        Node novo = malloc(sizeof(struct node));
        novo->info = info;
        novo->next = NULL;   
        
        if(lista->head == NULL){
            lista->head = novo;
            novo->prev = NULL;
        }else{
            Node walker = lista->head;

            while (walker->next != NULL){
                walker = walker->next;
            }
            
            novo->prev = walker;
            walker->next = novo;
        }
        return true;
    }
    return false;   
}

bool insere_ordenado(Lista lista, Infotype info){
    
}

void imprime_lista(Lista lista){
    if(lista != NULL){
        Node walker = lista->head;
        while (walker != NULL){
            printf("Prev: %p ", walker->prev);
            printf("| Info: %d |", walker->info);
            printf("Next: %p\n", walker->next);
            walker = walker->next;
        }
    }
}
