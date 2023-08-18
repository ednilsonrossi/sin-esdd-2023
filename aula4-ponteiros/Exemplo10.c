#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    
    int *ptr;

    ptr = malloc( sizeof(int) );

    *ptr = 10;
    *ptr = (*ptr) * 2;

    printf(" %d \n\n", *ptr);
    return 0;
}
