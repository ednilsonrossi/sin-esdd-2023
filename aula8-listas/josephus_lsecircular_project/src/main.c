#include "lse.h"

int main(int argc, char const *argv[]){
    
    List soldados;

    init_list(&soldados);

    int id_soldado = 1;
    while(id_soldado <= 40){
        insert_end_list(soldados, id_soldado);
        id_soldado += 1;
    }

    printf("Sobrevivente: %d\n\n", josephus(soldados, 3));

    return 0;
}