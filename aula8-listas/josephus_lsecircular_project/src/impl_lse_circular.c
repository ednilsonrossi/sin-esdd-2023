/*
 * File:   impl_lse_circular.h
 * Author: Ednilson Rossi
 *
 * Created on 18 de novembro de 2023.
 * 
 * Considerando as definições do TAD de Lista Simplesmente Encadeada,
 * essa implementação utiliza a tecnologia de LSE Circular.
 */

#include "lse.h"

struct node{
    Infotype info;
    struct node* next;
};

typedef struct node* Node;

struct lse{
    Node head;
};

void init_list(List* list){
    List nova = malloc(sizeof(struct lse));
    nova->head = NULL;
    *list = nova;
}

bool is_empty_list(List list){
    if(list != NULL){
        return list->head == NULL;
    }
    return false;
}

void insert_end_list(List list, Infotype info){
    if(list != NULL){
        Node novo = malloc(sizeof(struct node));
        novo->info = info;
        novo->next = NULL;

        if(list->head == NULL){
            list->head = novo;
            novo->next = novo;
        }else{
            Node walker = list->head;
            while (walker->next != list->head){
                walker = walker->next;
            }
            novo->next = walker->next;
            walker->next = novo;
        }
    }
}

void insert_begin_list(List list, Infotype info){
    if(list != NULL){
        Node novo = malloc(sizeof(struct node));
        novo->info = info;
        novo->next = NULL;

        if(list->head == NULL){
            list->head = novo;
            novo->next = novo;
        }else{
            Node walker = list->head;
            while (walker->next != list->head){
                walker = walker->next;
            }
            novo->next = list->head;
            walker->next = novo;
            list->head = novo;
        }
    }
}

Infotype delete_begin_list(List list){
    if(list != NULL){
        Infotype info = list->head->info;
        Node rip = list->head;

        Node walker = list->head;
        while (walker->next != list->head){
            walker = walker->next;
        }
        if(walker == list->head){
            list->head = NULL;
        }else{
            walker->next = rip->next;
            list->head = rip->next;
        }
        free(rip);
        return info;
    }
}


Infotype delete_end_list(List list){
    if(list != NULL){
        Node walker = list->head;
        Node stalker = NULL;
        while (walker->next != list->head){
            stalker = walker;
            walker = walker->next;
        }

        Infotype info = walker->info;

        if(stalker == NULL){
            list->head = NULL;
        }else{
            stalker->next = list->head;
        }
        free(walker);
        return info;
    }
}


Infotype josephus(List list, int step){
    if(list != NULL && step > 0){
        Node walker = list->head;
        Node stalker = NULL;

        while(walker->next != walker){
            for(int i = 1; i != step; i++){
                stalker = walker;
                walker = walker->next;
            }

            /*Verifica e o nó a ser removido é o primeiro nó, ou seja, o head.*/
            if(walker == list->head){
                /*Remove o primeiro nó da lista*/
                list->head = walker->next;
                stalker = walker->next;
                while (stalker->next != walker){
                    stalker = stalker->next;
                }
                stalker->next = list->head;
            }else{
                stalker->next = walker->next;
            }
            free(walker);
            walker = stalker->next;
            
        }
        Infotype survivor = list->head->info;
        free(list->head);
        list->head = NULL;
        return survivor;
    }
}