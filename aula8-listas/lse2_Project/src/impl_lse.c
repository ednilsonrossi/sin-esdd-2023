#include "lse.h"

struct node{
    //Informação que é armazenada no node.
    Typeinfo info;
    //Ponteiro para o próximo node.
    Node next;
};

struct lse{
    //Ponteiro para o primeiro node da lista.
    Node head;
};

void init_list(List* list){
    *list = malloc(sizeof(struct lse));
    (*list)->head = NULL;
}

List init_list2(){
    List ptr = malloc(sizeof(struct lse));
    ptr->head = NULL;
    return ptr;
}

void destroy_list(List* list){
    if( *list != NULL){
        //Lista existe, precisa ser destruída.
        if( (*list)->head != NULL){
            //Lista não está vazia, primeiro remove todos os nodes.
            Node rip;
            Node walker;
            rip = (*list)->head;
            while(rip->next != NULL){
                walker = rip->next;
                free(rip);
                rip = walker;
            }
            free(rip);
        }           
        //Lista não tem nodes, basta liberar a lista.
        free(*list);
        *list = NULL;
    }
}

bool is_empty_list(List list){
    return list->head == NULL;
}

void insert_end_list(List list, Typeinfo new_info){
    if(list != NULL){
        //Criar um novo nó.
        Node new_node = malloc(sizeof(struct node));

        //Definir os valores do novo nó.
        new_node->next = NULL;
        new_node->info = new_info;

        //Verificar se a lista está vazia
        if(list->head == NULL){
            //Lista é vazia.
            list->head = new_node;
        }else{
            //Lista não está vazia, caminha até o último nó da lista.
            Node walker = list->head;
            while(walker->next != NULL){
                walker = walker->next;
            }
            //Ultimo nó (walker) aponta para o novo nó.
            walker->next = new_node;
        }
    }
}

void insert_begin_list(List list, Typeinfo new_info){
    if(list != NULL){
        //Criar o novo nó.
        Node new_node = malloc(sizeof(struct node));
        new_node->info = new_info;
        new_node->next = list->head;
        list->head = new_node;
    }
}

Typeinfo delete_begin_list(List list){
    Typeinfo answer;
    if(list != NULL){
        if(list->head != NULL){
            Node rip = list->head;
            answer = rip->info;
            list->head = rip->next;
            free(rip);
        }
    }
    return answer;
}

Typeinfo delete_end_list(List list){
    Typeinfo answer;
    if(list != NULL){
        if(list->head != NULL){
            Node rip = list->head;
            Node stalker = NULL;

            while (rip->next != NULL){
                stalker = rip;
                rip = rip->next;
            }

            answer = rip->info;
            free(rip);

            if(stalker == NULL){
                list->head = NULL;
            }else{
                stalker->next = NULL;
            }
            
        }
    }
    return answer;
}

void insert_ascendent_list(List list, Typeinfo new_info){
    if(list != NULL){
        Node new_node = malloc(sizeof(struct node));
        new_node->info = new_info;

        if(list->head == NULL){
            //Lista vazia, insere o nó na lista e altera o next para NULL.
            new_node->next = NULL;
            list->head = new_node;
        }else{
            Node walker = list->head;
            Node stalker = NULL;

            while(walker->info < new_node->info && walker->next != NULL){
                stalker = walker;
                walker = walker->next;
            }

            if(walker->info > new_node->info){
                //Insere o novo antes do walker.
                if(stalker == NULL){
                    //Insere o novo no início da lista
                    new_node->next = walker;
                    list->head = new_node;
                }else{
                    //É no meio da lista.
                    new_node->next = walker;
                    stalker->next = new_node;
                }
            }else{
                //Insere depois do walker;
                new_node->next = walker->next;
                walker->next = new_node;
            }
        }
    }
}

Typeinfo delete_at_list(List list, int position){
    Typeinfo answer;
    if(list != NULL && position >= 0){
        if(list->head != NULL){
            Node walker = list->head;
            Node stalker = NULL;
            int counter = 0;

            while(walker->next != NULL && counter < position){
                stalker = walker;
                walker = walker->next;
                counter += 1;
            }

            if(counter == position){
                //Achou posição;
                answer = walker->info;
                if(stalker == NULL){
                    //Primeiro nó precisa apagar;
                    list->head = walker->next;
                }else{
                    stalker->next = walker->next;
                }
                free(walker);
            }
        }
    }
    return answer;
}