/**
 * Autor: Ednilson Geraldo Rossi
 * linktr.ee/ednilsonrossi
*/

#include "student.h"


//---------------------------------------------------------------------------------
// DEFINIÇÃO DAS ESTRUTURAS DE DADOS QUE SERÃO UTILIZADAS
//---------------------------------------------------------------------------------

struct aluno{
    int prontuario;
    char nome[40];
};


struct cadastro{
    Aluno dataset[MAXSIZE];     //Array de ponteiro para struct aluno.
    int cadastrados;            //Quantidade de alunos cadastrados.
};



//---------------------------------------------------------------------------------
// OPERAÇÃO DE MANIPULAÇÃO DO TAD ALUNO
//---------------------------------------------------------------------------------


Aluno criar_aluno(int p, char* n){
    Aluno aluno;
    aluno = malloc(sizeof(struct aluno));

    aluno->prontuario = p;
    strcpy(aluno->nome, n);

    return aluno;
}


void destroi_aluno(Aluno aluno){
    free(aluno);
}


char* to_string_aluno(Aluno aluno){
    char* string;
    string = malloc(sizeof(char) * 90);
    snprintf(string, 90, "Aluno [prontuario = %d, nome = %s]", aluno->prontuario, aluno->nome);
    return string;
}


//---------------------------------------------------------------------------------
// OPERAÇÃO DE MANIPULAÇÃO DO TAD CADASTRO
//---------------------------------------------------------------------------------


void inicializar_cadastro(Cadastro* arquivo){
    *arquivo = malloc(sizeof(struct cadastro));
    (*arquivo)->cadastrados = 0;
}

void destruir_cadastro(Cadastro arquivo){
    Aluno aluno;
    while(!esta_vazio_cadastro(arquivo)){
        aluno = busca_posicao_cadastro(arquivo, tamanho_cadastro(arquivo) - 1);
        sai_cadastro(arquivo, aluno);
    }
    free(arquivo);
}

int tamanho_cadastro(Cadastro arquivo){
    return arquivo->cadastrados;
}

bool esta_cheio_cadastro(Cadastro arquivo){
    if(arquivo->cadastrados == MAXSIZE-1){
        return true;
    }else{
        return false;
    }
}

bool esta_vazio_cadastro(Cadastro arquivo){
    return arquivo->cadastrados == 0;
}

bool entra_cadastro(Cadastro arquivo, Aluno aluno){
    if(esta_cheio_cadastro(arquivo) || aluno == NULL || existe_cadastro(arquivo, aluno) == true){
        return false;
    }
    arquivo->dataset[arquivo->cadastrados] = aluno;
    arquivo->cadastrados += 1;
    return true;
}

bool sai_cadastro(Cadastro arquivo, Aluno aluno){
    if(esta_vazio_cadastro(arquivo) || !existe_cadastro(arquivo, aluno)){
        return false;
    }

    int index = 0;
    while(arquivo->dataset[index]->prontuario != aluno->prontuario){
        index += 1;
    }

    destroi_aluno(aluno);

    while(index < arquivo->cadastrados - 1){
        arquivo->dataset[index] = arquivo->dataset[index+1];
        index += 1;
    }
    arquivo->cadastrados -= 1;
    return true;
}


bool existe_cadastro(Cadastro arquivo, Aluno aluno){
    bool existe = false;
    if(esta_vazio_cadastro(arquivo) == false){
        for(int i = 0; i < arquivo->cadastrados && existe == false; i += 1){
            if(arquivo->dataset[i]->prontuario == aluno->prontuario){
                existe = true;
            }
        }
    }
    return existe;
}

Aluno busca_cadastro(Cadastro arquivo, int key){
    Aluno aluno = NULL;

    if(!esta_vazio_cadastro(arquivo)){
        for(int i = 0; i < arquivo->cadastrados && aluno == NULL; i += 1){
            if(arquivo->dataset[i]->prontuario == key){
                aluno = arquivo->dataset[i];
            }
        }
    }

    return aluno;
}

Aluno busca_posicao_cadastro(Cadastro arquivo, int posicao){
    Aluno aluno = NULL;
    if(!esta_vazio_cadastro(arquivo) && posicao >= 0 && posicao < arquivo->cadastrados){
        aluno = arquivo->dataset[posicao];
    }
    return aluno;
}