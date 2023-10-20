#include "tad_projeto.h"
#include "conjunto.h"

int main(int argc, char const *argv[]){
    
    Conjunto projetos;

    init(&projetos);

    insert(projetos, criar(123, 1000.0));
    insert(projetos, criar(234, 2000.0));
    insert(projetos, criar(345, 1500.0));
    insert(projetos, criar(456, 1900.0));
    insert(projetos, criar(567, 3000.0));
    insert(projetos, criar(678, 5000.0));
    insert(projetos, criar(890, 8000.0));
    insert(projetos, criar(901, 1000.0));
    insert(projetos, criar(923, 10000.0));

    for(int i=0; i != size(projetos); i++){
        printf("%s\n", paraImpressao(getAt(projetos, i)));
    }
}
