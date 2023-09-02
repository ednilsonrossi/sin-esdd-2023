#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>


/**
 * A constante BITS_SIZE define do tamanho de bits compartado pelo TAD, caso
 * necessário é possível aumentar ou diminuir a quandidade de bits do TAD.
*/
#define BITS_SIZE 16

/**
 * Definição do tipo Binario (ponteiro para uma struct meu_binario).
*/
typedef struct meu_binario* Binario;


/**
 * Operação recebe uma string com até 17 caracteres, lembrando que a
 * string pode possuir o caractere '\0' indicando o final da mesma.
*/
Binario criar_binario(char string[BITS_SIZE+1]);

/**
 * Liberar a memória alocada para armazenar o número binário.
*/
void destruir_binario(Binario numero);

/**
 * Verifica se um número realmente é binário, ou seja, se é comporto
 * apenas pelos dígitos 0 e 1. Caso exista algum digito diferente de
 * 0 ou 1 a validação retorna o resultado FALSO.
*/
bool validar_binario(Binario numero);

/**
 * Operação atribui o valor zero para o binário. Deve-se utilizar essa 
 * operação para executar umn reset no valor armazenado antes de reutilizar 
 * o valor binário.
*/
void zerar_binario(Binario numero);


/**
 * Operação responsável por apresentar o valor binário, observa-se
 * que a operação apresenta todos os bits, mesmos os zeros existentes
 * a esquerda do primeiro bit significativo.
*/
void imprime_binario(Binario numero);


/**
 * Operação realiza a leitura de um valor binário pelo terminal. O argumento
 * é a mensagem que apresentada ao usuário para que o valor seja digitado.
*/
Binario leitura_binario(char* mensagem);


/**
 * Operação converte o número binário em decimal, ou seja, em um tipo inteiro.
*/
int binario_to_int(Binario numero);


/**
 * Operação realiza a soma de dois binários (n1 e n2), passados como argumento.
 * A operação retorna um terceiro binário.
*/
Binario soma_binario(Binario n1, Binario n2);



