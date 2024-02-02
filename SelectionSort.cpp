#include <iostream>
#include <stdlib.h>

void troca(int * a, int * b){
    int temp;

    temp = (*a);
    (*a) = (*b);
    (*b) = temp;
}

void SelectionSort(int * vetor, int tamanho){
    int i, j, indice;

    for(i = 0; i < tamanho; i++){
        for(j = i; j < tamanho; j++){
            if(j == i){
                indice = j;
            } else if(vetor[j] < vetor[indice]){
                indice = j;
            }
        }
        troca(&vetor[i], &vetor[indice]);
    }
}

void VectorShow(int * vetor, int tamanho){
    int i;

    for(i = 0; i < tamanho; i++){
        std::cout << vetor[i] << " ";
    }

    std::cout << "\n\n";
}

int main(){
    int vetor[7] = {7, 4, 5, 9, 8, 2, 1};

    VectorShow(vetor, 7);

    SelectionSort(vetor, 7);

    VectorShow(vetor, 7);

    return 0;
}