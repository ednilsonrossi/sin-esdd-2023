/**
 * Autor: Ednilson Geraldo Rossi
 * E-mail: ednilsonrossi@ifsp.edu.br
 * Data: 24/08/2023
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>


struct aluno{
    char nome[50];
    float media;
    int faltas;
};

int main(int argc, char const *argv[]){
    int n;
    struct aluno* dataset;  //Aponta para a variável que mantem os dados
    struct aluno* ptr;      //Será utilizado como variável auxiliar

    //Obter a quandidade de alunos
    do{
        printf("Quantidade de alunos: ");
        scanf("%d", &n);
        __fpurge(stdin);
    }while(n < 1);

    //Aloca um conjunto de dados de forma dinâmica
    dataset = malloc( sizeof(struct aluno) * n );

    //Leitura dos dados
    for(int i = 0; i < n; i++){
        __fpurge(stdin);
        printf("Nome do aluno: ");
        fgets( (*(dataset+i)).nome, 50, stdin );

        /**
         * A função fgets() lê como final da string o '\n', contudo a 
         * biblioteca strings.h considera como final de string o '\0', 
         * dessa forma, o procedimento abaixo apenas troca o '\n' pelo
         * '\o'.
        */
        int j;
        for(j=0; (*(dataset+i)).nome[j] != '\n'; j++);
        (dataset+i)->nome[j] = '\0';
        /*Fim da troca de final de string.*/

        printf("Média: ");
        scanf("%f", &( (dataset+i)->media) );

        printf("Faltas:");
        scanf("%d", &( (dataset+i)->faltas) );
    }

    //imprime lista de alunos conforme cadastro
    /*
    for(int i=0; i < n; i++){
        printf("[Nome: %s | Faltas: %d | Média: %.2f]\n", dataset[i].nome, dataset[i].faltas, dataset[i].media);
    }
    */

    /**
     * Classificação dos dados utilizando o método de classificação bubblesort
    */

    bool trocou = true;
    for(int i = 0; i < n && trocou == true; i++){
        trocou = false;
        for(int j = 0; j < n - (i + 1); j++){
            /*método de classificação analisa uma posição e a posição da frente no arquivo,
            se necessário, realiza a troca.*/
            if( (dataset+j)->media < (dataset+j+1)->media ){
                trocou = true;

                /*Troca usando alocação dinâmica e aritmética de ponteiros.*/
                ptr = malloc(sizeof(struct aluno));     //Alocação de uma variável auxiliar
                *ptr = *(dataset+j);
                *(dataset+j) = *(dataset+j+1);          
                *(dataset+j+1) = *ptr;
                free(ptr);                              //Libera variável auxiliar
            }
        }
    }

    //imprime lista de alunos classificados
    printf("** Relatório **\n");
    for(int i=0; i < n; i++){
        printf("[Nome: %s | Faltas: %d | Média: %.2f]\n", dataset[i].nome, dataset[i].faltas, dataset[i].media);
    }

    //Liberar o dataset
    free(dataset);

    return 0;
}
