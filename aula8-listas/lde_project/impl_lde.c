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
    if(lista != NULL){
        Node novo = malloc(sizeof(struct node));
        novo->info = info;
        if(lista->head == NULL){
            //lista vazia
            novo->next = NULL;
            novo->prev = NULL;
            lista->head = novo;
        }else{
            if(novo->info < lista->head->info){
                //insere no início
                novo->next = lista->head;
                novo->prev = NULL;
                lista->head->prev = novo;
                lista->head = novo;
            }else{
                //procurar posicao na lista
                Node walker = lista->head;
                while(novo->info > walker->info && walker->next != NULL){
                    walker = walker->next;
                }

                if(novo->info > walker->info){
                    //insere depois do walker
                    novo->next = walker->next;
                    walker->next = novo;
                    novo->prev = walker;
                }else{
                    //insere antes do walker
                    novo->prev = walker->prev;
                    novo->next = walker;
                    walker->prev->next = novo;
                    walker->prev = novo;
                }
            }
        }

        return true;
    }
    return false;
}

bool apagar(Lista lista, Infotype info){
    if(lista != NULL){
        if(lista->head != NULL){
            Node walker = lista->head;
            while (walker->info != info && walker->next != NULL){
                walker = walker->next;
            }

            //verificar se encontrou a info ou se a info não existe
            if(walker->info == info){
                //info encontrada, apagar o nó
                if(walker == lista->head){
                    //primeiro nó que deve ser excluído

                    //organiza a cabeça da lista e o novo nó cabeça que tem o prev nulo
                    lista->head = walker->next;
                    lista->head->prev = NULL;
                }else{
                    if(walker->next == NULL){
                        //último nó deve ser excluído

                        //ajusta o penultimo no para ser o ultimo
                        walker->prev->next = NULL;
                    }else{
                        //apagar nó do meio da lista

                        walker->prev->next = walker->next;
                        walker->next->prev = walker->prev;
                    }
                }
                //apagar o walker
                free(walker);
                return true;
            }
            //caso não encontre a algoritmo segue para retorno false
        }
    }
    return false;
}

void imprime_lista(Lista lista){
    if(lista != NULL){
        printf("HEAD: %p\n", lista->head);
        Node walker = lista->head;
        while (walker != NULL){
            printf("Prev: %p ", walker->prev);
            printf("| Info: %d |", walker->info);
            printf("Next: %p\n", walker->next);
            walker = walker->next;
        }
    }
}
