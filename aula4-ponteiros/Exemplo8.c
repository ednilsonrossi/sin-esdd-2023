#include <stdio.h>

void swap(int *, int *);

int main(int argc, char const *argv[]){
    int n1, n2;

    printf("Digite 2 números: ");
    scanf("%d%d", &n1, &n2);
    printf("N1 = %d - N2 = %d\n", n1, n2);
    swap(&n1, &n2);
    printf("N1 = %d - N2 = %d\n", n1, n2);

    return 0;
}

void swap(int *a, int *b){
    int *auxiliar;
    *auxiliar = *a;
    *a = *b;
    *b = auxiliar;
}