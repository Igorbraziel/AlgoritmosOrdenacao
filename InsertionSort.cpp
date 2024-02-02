#include <iostream>
#include <stdlib.h>
#include <stdio.h>

void InsertionSort(int * vetor, int tamanho){
    int i, j, aux;
    i = 1;
    while(i < tamanho){
        j = i - 1;
        aux = vetor[i];
        while(j >= 0 && vetor[j] > aux){
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = aux;
        i++;
    }
}

void VectorShow(int * vetor, int tamanho){
    int i;

    for(i = 0; i < tamanho; i++){
        printf("%c ", vetor[i]);
    }

    std::cout << "\n\n";
}


int main(){
    int vetor[6] = {'o', 'r', 'd', 'e', 'n', 'a'};

    VectorShow(vetor, 6);

    InsertionSort(vetor, 6);

    VectorShow(vetor, 6);

    return 0;
}