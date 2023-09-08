/**
 * Autor: Ednilson Geraldo Rossi
 * linktr.ee/ednilsonrossi
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Define o tamanho máximo do cadastro, nesse exemplo define-se o cadastro com 
 * um máximo de 10 alunos.
*/
#define MAXSIZE 10

/**
 * Define o tipo Aluno como um PONTEIRO para uma struct aluno.
*/
typedef struct aluno* Aluno;

/**
 * Define o tipo Cadastro como um PONTEIRO para uma struct aluno.
*/
typedef struct cadastro* Cadastro;

//---------------------------------------------------------------------------------
// OPERAÇÃO DE MANIPULAÇÃO DO TAD CADASTRO DE ALUNOS
//---------------------------------------------------------------------------------

/**
 * Inicializa o cadastro. Essa operação é responsável por alocar memória
 * para o cadastro, observando MAXSIZE, e definir a estratégia de implementação
 * do cadastro e seus controles.
*/
void inicializar_cadastro(Cadastro* arquivo);

/**
 * Operação que destroi todo o conteúdo do cadastro e a referência
 * para o cadastro.
*/
void destruir_cadastro(Cadastro arquivo);

/**
 * Operação retorna o tamanho do cadastro, ou seja, a quantidade de alunos
 * existentes no cadastro.
*/
int tamanho_cadastro(Cadastro arquivo);


/**
 * Operação responsável por inserir um novo aluno no cadastro. Caso tenha
 * sucesso o retorno da operação é true. O retorno false indica que o 
 * cadastro está cheio OU o aluno informado é nulo OU o aluno já está
 * cadastrado. Considera-se como chave o prontuário do estudante.
*/
bool entra_cadastro(Cadastro arquivo, Aluno aluno);


/**
 * Retorna verdadeiro se o cadastro atingiu a quantidade máxima, de
 * acordo com MAXSIZE.
*/
bool esta_cheio_cadastro(Cadastro arquivo);


/**
 * Retorna cerdadeiro se nenhum aluno estiver presente no cadastro.
*/
bool esta_vazio_cadastro(Cadastro arquivo);


/**
 * Verifica se um aluno já está presente no cadastro. Considera-se
 * como chave de busca o prontuário do aluno.
*/
bool existe_cadastro(Cadastro arquivo, Aluno aluno);


/**
 * Apaga o aluno do cadastro. Retorna falso caso o cadastro esteja
 * vazio OU o aluno não esteja presente no cadastro.
*/
bool sai_cadastro(Cadastro arquivo, Aluno aluno);


/**
 * Realiza a busca no cadastro considerando como chave (key) o 
 * printuário do aluno. É retornada a referência (ponteiro) para
 * o aluno caso exista, ou NULO caso o prontuário não esteja presente
 * no cadastro.
*/
Aluno busca_cadastro(Cadastro arquivo, int key);


/**
 * Retorna o aluno em uma posição específica do cadastro. O retorno
 * NULO significa que o cadastro está vazio OU a posição é inválida, 
 * ou seja, é um valor negativo ou superior a MAXSIZE-1.
*/
Aluno busca_posicao_cadastro(Cadastro arquivo, int posicao);


//---------------------------------------------------------------------------------
// OPERAÇÃO DE MANIPULAÇÃO DO TAD ALUNO
//---------------------------------------------------------------------------------


/**
 * Aloca espaço em memória para um aluno com os dados necessários
 * do aluno. Retorna-se um PONTEIRO para um aluno.
*/
Aluno criar_aluno(int p, char* n);


/**
 * Apaga os dados do aluno liberando memória
*/
void destroi_aluno(Aluno aluno);


/**
 * Retorna os dados do aluno em uma string formatada com os dados.
*/
char* to_string_aluno(Aluno aluno);