/**
 * Autor: Ednilson Geraldo Rossi
 * linktr.ee/ednilsonrossi
*/

#include "student.h"

int main(int argc, char const *argv[])
{
    
    Cadastro meus_dados;
    Aluno aluno;

    inicializar_cadastro(&meus_dados);

    aluno = criar_aluno(123, "Daniel\0");
    entra_cadastro(meus_dados, aluno);
    aluno = criar_aluno(456, "Eduardo\0");
    entra_cadastro(meus_dados, aluno);
    aluno = criar_aluno(678, "Maria\0");
    entra_cadastro(meus_dados, aluno);
    aluno = criar_aluno(901, "Zuleica\0");
    entra_cadastro(meus_dados, aluno);

    printf("Busca aluno pelo prontuário: \n");
    aluno = busca_cadastro(meus_dados, 678);
    if(aluno != NULL)
        printf("%s \n\n", to_string_aluno(aluno));


    printf("Relatório de alunos: \n");
    for(int i = 0; i < tamanho_cadastro(meus_dados); i++){
        aluno = busca_posicao_cadastro(meus_dados, i);
        if(aluno != NULL){
            printf("%s ", to_string_aluno(aluno));
            printf("\n");
        }
    }

    printf("\n\nApagar aluno do cadastro:\n");
    aluno = busca_cadastro(meus_dados, 456);
    if(sai_cadastro(meus_dados, aluno)){
        printf("Aluno excluído.");
    }else{
        printf("Erro ao excluir aluno.");
    }
    printf("\n\nRelatório de alunos: \n");
    for(int i = 0; i < tamanho_cadastro(meus_dados); i++){
        aluno = busca_posicao_cadastro(meus_dados, i);
        if(aluno != NULL){
            printf("%s ", to_string_aluno(aluno));
            printf("\n");
        }
    }


    destruir_cadastro(meus_dados);

    return 0;
}
