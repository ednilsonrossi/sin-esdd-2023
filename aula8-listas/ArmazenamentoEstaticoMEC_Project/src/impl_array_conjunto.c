#include "conjunto.h"

struct conjunto{
    Info* elements;
    int size;
    int max_size;
};

bool init(Conjunto* conjunto){
    Conjunto c = malloc(sizeof(struct conjunto));
    c->max_size = DEFAULT_SIZE;
    c->elements = malloc(sizeof(Info) * c->max_size);
    c->size = 0;

    *conjunto = c;
}

bool insert(Conjunto conjunto, Info item){
    if(conjunto->size == conjunto->max_size){
        Info* new_elements = malloc(sizeof(Info) * conjunto->max_size * 2);
        for(int i = 0; i != conjunto->size; i++){
            new_elements[i] = conjunto->elements[i];
        }
        conjunto->elements = new_elements;
        conjunto->max_size = conjunto->max_size * 2;
    }
    conjunto->elements[conjunto->size] = item;
    conjunto->size = conjunto->size + 1;
    return true;
}

Info getAt(Conjunto conjunto, int position){
    if(position >= 0 && position < conjunto->size){
        return conjunto->elements[position];
    }
    return NULL;
}

int size(Conjunto conjunto){
    return conjunto->size;
}