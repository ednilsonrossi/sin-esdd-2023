#include <stdio.h>
#define MAXSIZE 1000

void load_dataset(int array[], int size);
int search(int dataset[], int dataset_size, int key);

int main(int argc, char const *argv[]){
    srand( (unsigned) time(NULL) );
    int position;
    int array[MAXSIZE];
    
    load_dataset(array, MAXSIZE);
    position = search(array, MAXSIZE, rand() % 1000);
    if(position == -1){
        printf("Chave não encontrada.\n");
    }else{
        printf("Chave %d encontrada na posição: %d.\n", array[position], position);
    }
    

    return 0;
}

void load_dataset(int array[], int size){
    for(int index = 0; index < size; index += 1){
        array[index] = rand() % 1000;
    }
}

int search(int dataset[], int dataset_size, int key){
    if(dataset_size == 0){
        return -1;
    }
    if(dataset[dataset_size-1] == key){
        return dataset_size-1;
    }
    return search(dataset, dataset_size-1, key);
}