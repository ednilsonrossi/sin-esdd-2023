#include "lse.h"

int main(int argc, char const *argv[]){
    
    List meus_dados;

    init_list(&meus_dados);

    insert_end_list(meus_dados, 10);
    insert_end_list(meus_dados, 20);
    insert_end_list(meus_dados, 30);
    insert_begin_list(meus_dados, 40); 



    while(!is_empty_list(meus_dados)){
        printf("%d, ", delete_begin_list(meus_dados));
        //printf("%d, ", delete_end_list(meus_dados));
    }

    return 0;
}