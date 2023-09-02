#include "binario.h"

int main(int argc, char const *argv[])
{
    Binario binario, outro, soma;

    binario = criar_binario("1111");
    imprime_binario(binario);
    printf("\nInteiro: %d\n", binario_to_int(binario));

    outro = criar_binario("1");
    imprime_binario(outro);
    printf("\nInteiro: %d\n", binario_to_int(outro));

    soma = soma_binario(binario, outro);
    imprime_binario(soma);
    printf("\nInteiro: %d\n", binario_to_int(soma));

    destruir_binario(binario);
    binario = leitura_binario("Digite binário: ");
    imprime_binario(binario);
    printf("\nInteiro: %d\n", binario_to_int(binario));
    destruir_binario(binario);


    //Realizar a soma de 4 binários informados pelo usuário.
    zerar_binario(soma);
    for(int i = 0; i < 4; i++){
        binario = leitura_binario("Digite o binário: ");
        soma = soma_binario(binario, soma);
    }
    printf("Resultado da soma: ");
    imprime_binario(soma);
    printf("\nInteiro: %d\n", binario_to_int(soma));



    destruir_binario(binario);
    destruir_binario(outro);
    destruir_binario(soma);
    return 0;
}
