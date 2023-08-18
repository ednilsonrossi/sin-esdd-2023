#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    
    int *array_ptr;

    array_ptr = malloc( sizeof(int) * 10 );

    for(int i = 0; i < 10; i++){
        *(array_ptr + i) = (i+1) * 10;
    }

    for(int i = 0; i < 10; i++){
        printf("Array[%d]: %d\n", i, *(array_ptr + i) );
    }
    
    return 0;
}
