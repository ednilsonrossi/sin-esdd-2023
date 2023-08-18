#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    
    double *ptr1;
    int *ptr2;

    ptr1 = malloc( sizeof(double) );
    ptr2 = malloc( sizeof(int) );

    *ptr1 = 10.567;
    *ptr2 = 2;

    printf(" %lf \n\n", *ptr1 + *ptr2);
    return 0;
}