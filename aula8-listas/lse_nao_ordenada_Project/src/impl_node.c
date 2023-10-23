#include "node.h"


struct node{
    Info data;
    Node next;
};

Node node_criar(){
    Node novo;
    novo = malloc(sizeof(struct node));
    return novo;
}

void node_apagar(Node no){
    free(no);
}

void node_alteraInfo(Node no, Info data){
    if(no != NULL){
        no->data = data;
    }
}

void node_alteraNext(Node no, Node next){
    if(no != NULL){
        no->next = next;
    }
}

Info node_obtemInfo(Node no){
    if(no != NULL){
        return no->data;
    }
    return NULL;
}

Node node_obtemNext(Node no){
    if(no != NULL){
        return no->next;
    }
    return NULL;
}