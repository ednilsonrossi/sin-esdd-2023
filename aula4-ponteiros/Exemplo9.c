#include <stdio.h>

/*
int main(int argc, char const *argv[]){
    int a, b, *ptr;

    a = 2;
    *ptr = 3;
    b = a + (*ptr);
    printf(" %d \n", b);
    return 0;
}
*/

int main(int argc, char const *argv[]){
    int a, b, *ptr = &a;

    a = 2;
    *ptr = 3;
    b = a + (*ptr);
    printf(" %d \n", b);
    return 0;
}