#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void converter(char*);

int main(int argc, char const *argv[]){
    
    char string[] = "25 de agosto. Sexta-feira linda!";

    printf("Frase antes: \n\t%s\n", string);
    converter(string);
    printf("Frase depois: \n\t%s\n", string);

    return 0;
}

void converter(char* string_ptr){

    while(*string_ptr != '\0' ){                    // o '\0' é o final da string
        if(islower(*string_ptr)){
            *string_ptr = toupper(*string_ptr);     //converte em maiúsculo
        }
        string_ptr++;      //desloca o ponteiro para a posição seguinte do array/string
    }
}