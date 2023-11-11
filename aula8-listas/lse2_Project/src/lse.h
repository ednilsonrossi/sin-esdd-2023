#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node* Node;

typedef struct lse* List;

typedef int Typeinfo;


void init_list(List* list);

List init_list2();

void destroy_list(List* list);

bool is_empty_list(List list);

void insert_end_list(List list, Typeinfo new_info);

void insert_begin_list(List list, Typeinfo new_info);

void insert_ascendent_list(List list, Typeinfo new_info);

Typeinfo delete_begin_list(List list);

Typeinfo delete_end_list(List list);

Typeinfo delete_at_list(List list, int position);