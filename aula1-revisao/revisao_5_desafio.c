#include <stdio.h>
#define MAX 10

struct data{
    int k;
    int Lin;
    int Col;
};

void imprime_matriz(int m[MAX][MAX], int n);
void carrega_matriz(int m[MAX][MAX], int n);
struct data sou_o_maximo(int m[MAX][MAX], int n);

int main(int argc, char const *argv[])
{
    srand( (unsigned) time(NULL) );

    int matriz[MAX][MAX];
    int n;
    struct data relatorio[MAX];

    printf("Informe tamanho da matriz: ");
    scanf("%d", &n);

    carrega_matriz(matriz, n);
    imprime_matriz(matriz, n);

    for(int index = 0; index < n*n; index += 1){
        relatorio[index] = sou_o_maximo(matriz, n);
        matriz[relatorio[index].Lin][relatorio[index].Col] = -1;
    }

    printf("\nElemento\tLinha\tColuna\n");
    for(int index = 0; index < n*n; index += 1){
        printf("%6d   \t%2d\t%2d\n", relatorio[index].k, relatorio[index].Lin, relatorio[index].Col);
    }

    return 0;
}


void imprime_matriz(int m[MAX][MAX], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%4d", m[i][j]);
        }
        printf("\n");
    }
}

void carrega_matriz(int m[MAX][MAX], int n){
    for(int i = 0; i < n; i += 1){
        for(int j = 0; j < n; j += 1){
            m[i][j] = rand() % 100;
        }
    }
}

struct data sou_o_maximo(int m[MAX][MAX], int n){
    struct data maximo;
    maximo.k = m[0][0];
    maximo.Col = 0;
    maximo.Lin = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(m[i][j] > maximo.k){
                maximo.k = m[i][j];
                maximo.Lin = i;
                maximo.Col = j;
            }
        }
    }

    return maximo;
}