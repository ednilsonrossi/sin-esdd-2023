/*
 * File:   impl_pilha_lse.c
 * Author: Ednilson Rossi
 *
 * Created on 17 de novembro de 2023.
 */

#include "pilha.h"

/**
 * Define o tipo de dado para um NODE (nó).
*/
typedef struct node* Node;

struct node{
    Tipo_Informacao info;
    Node next;
};

struct stack{
    Node topo;
};

void init(Pilha* pilha){
    *pilha = malloc(sizeof(struct stack));
    (*pilha)->topo = NULL;
}

bool is_full(Pilha pilha){
    return false;
}

bool is_empty(Pilha pilha){
    return pilha->topo == NULL;
}

bool push(Pilha pilha, Tipo_Informacao elemento){
    if(pilha != NULL){
        Node novo = malloc(sizeof(struct node));
        novo->info = elemento;
        novo->next = pilha->topo;
        pilha->topo = novo;
        return true;
    }
    return false;
}

bool pop(Pilha pilha, Tipo_Informacao* elemento){
    if(pilha != NULL){
        if(!is_empty(pilha)){
            Node rip = pilha->topo;
            *elemento = rip->info;
            pilha->topo = rip->next;
            free(rip);
            return true;
        }
    }
    return false;
}
