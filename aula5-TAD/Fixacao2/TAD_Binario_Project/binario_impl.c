/**
 * Autor: Ednilson Geraldo Rossi
 * linktr.ee/ednilsonrossi
*/

#include "binario.h"

struct meu_binario{
    char bits[BITS_SIZE];
};


Binario criar_binario(char string[BITS_SIZE]){
    Binario numero;
    numero = malloc(sizeof(struct meu_binario));
    zerar_binario(numero);

    for(int i = strlen(string) - 1, j = BITS_SIZE - 1; i >= 0; i--, j--){
        numero->bits[j] = string[i];
    }

    if(validar_binario(numero) == false){
        zerar_binario(numero);
    }
    return numero;
}

bool validar_binario(Binario numero){
    bool valido = true;
    for(int i = 0; i < BITS_SIZE && valido == true; i++){
        if(numero->bits[i] != '0' && numero->bits[i] > '1'){
            valido = false;
        }
    }
    return valido;
}

void imprime_binario(Binario numero){
    for(int i = 0; i < BITS_SIZE; i++){
        printf("%c", numero->bits[i]);
    }
}

void zerar_binario(Binario numero){
    for(int i=0; i < BITS_SIZE; i++){
        numero->bits[i] = '0';
    }
}

int binario_to_int(Binario numero){
    int potencia = 0;
    int inteiro = 0;
    for(int i = BITS_SIZE-1; i >= 0; i--){
        if(numero->bits[i] == '1'){
            inteiro += pow(2, potencia);
        }
        potencia += 1;
    }
    return inteiro;
}

Binario soma_binario(Binario n1, Binario n2){
    Binario resultado;
    bool vai_um = false;

    resultado = criar_binario("00");

    for(int i = BITS_SIZE-1; i >= 0; i--){
        if(n1->bits[i] == '0' && n2->bits[i] == '0' && vai_um == false){
            resultado->bits[i] = '0';
        }else if(n1->bits[i] == '0' && n2->bits[i] == '0' && vai_um == true){
            resultado->bits[i] = '1';
            vai_um = false;
        }else if(n1->bits[i] == '1' && n2->bits[i] == '0' && vai_um == false){
            resultado->bits[i] = '1';
        }else if(n1->bits[i] == '0' && n2->bits[i] == '1' && vai_um == false){
            resultado->bits[i] = '1';
        }else if(n1->bits[i] == '1' && n2->bits[i] == '1' && vai_um == false){
            resultado->bits[i] = '0';
            vai_um = true;
        }else if(n1->bits[i] == '1' && n2->bits[i] == '0' && vai_um == true){
            resultado->bits[i] = '0';
            vai_um = true;
        }else if(n1->bits[i] == '0' && n2->bits[i] == '1' && vai_um == true){
            resultado->bits[i] = '0';
            vai_um = true;
        }else if(n1->bits[i] == '1' && n2->bits[i] == '1' && vai_um == true){
            resultado->bits[i] = '1';
            vai_um = true;
        }
    }
    if(vai_um == true){
        zerar_binario(resultado);
        printf("Estouro de bits\n");
    }

    return resultado;
}

Binario leitura_binario(char* mensagem){
    Binario numero;
    char array[BITS_SIZE];

    printf("%s", mensagem);
    scanf("%s", array);
    numero = criar_binario(array);
    return numero;
}

void destruir_binario(Binario numero){
    free(numero);
}