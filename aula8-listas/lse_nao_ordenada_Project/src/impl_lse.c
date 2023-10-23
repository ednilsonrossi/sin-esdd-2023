#include "lse.h"

struct lista{
    Node ptr;
};

Lista lista_criar(){
    Lista lista;
    lista = malloc(sizeof(struct lista));
    lista->ptr = NULL;
    return lista;
}

bool lista_estaVazia(Lista lista){
    bool answer = true;
    if(lista != NULL){
        if(lista->ptr != NULL){
            answer = false;
        }
    }
    return answer;
}

bool lista_adiciona(Lista lista, Info data){
    Node novo_node;
    Node caminhante;
    bool deu_certo = false;

    if(lista != NULL){
        novo_node = node_criar();
        node_alteraInfo(novo_node, data);
        node_alteraNext(novo_node, NULL);

        if(lista->ptr == NULL){
            /**
             * Lista está vazia, insere-se o novo_node como
             * primeiro elemento da lista.
            */
            lista->ptr = novo_node;
            deu_certo = true;
        }else{
            /**
             * Lista não está vazia, é necessário localizar a última
             * posição da lista e inserir o novo_node no final da lista.
            */
            caminhante = lista->ptr;
            while(node_obtemNext(caminhante) != NULL){
                caminhante = node_obtemNext(caminhante);
            }
            node_alteraNext(caminhante, novo_node);
            deu_certo = true;
        }
    }
    return deu_certo;
}

Info lista_obtemInfo(Lista lista, int posicao){
    Info resultado;
    Node caminhante;
    int contador;

    if(lista != NULL){
        if(posicao >= 0 && !lista_estaVazia(lista)){
            caminhante = lista->ptr;
            contador = 0;
            while(contador < posicao && node_obtemNext(caminhante) != NULL){
                caminhante = node_obtemNext(caminhante);
                contador += 1;
            }

            if(contador == posicao){
                resultado = node_obtemInfo(caminhante);
            }
        }
    }

    return resultado;
}

bool lista_destroi(Lista lista){
    Node caminhante;
    Node finado;
    if(lista != NULL){
        caminhante = lista->ptr;
        while(caminhante != NULL){
            finado = caminhante;
            caminhante = node_obtemNext(caminhante);
            node_apagar(finado);
        }
        lista->ptr = NULL;
        return true;
    }
    return false;
}

