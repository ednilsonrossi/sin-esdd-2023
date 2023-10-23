#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Info;

typedef struct node* Node;

/*
 * Aloca (instancia) um espaço na memória para armazenar um novo node. 
 */
Node node_criar();

void node_apagar(Node no);

void node_alteraInfo(Node no, Info data);

void node_alteraNext(Node no, Node next);

Info node_obtemInfo(Node no);

Node node_obtemNext(Node no);