#include <iostream>
#include <stdlib.h>

void troca(int * x, int * y){
    int temp;

    temp = (*x);
    (*x) = (*y);
    (*y) = temp;
}

int particao(int * vetor, int inicio, int fim){
    int pivo = vetor[fim];
    int i = inicio - 1;
    int j;

    for(j = inicio; j <= fim - 1; j++){
        if(vetor[j] <= pivo){
            i = i + 1;
            troca(&vetor[i], &vetor[j]);
        }
    }
    troca(&vetor[i + 1], &vetor[fim]);
    return i + 1;
}

void QuickSort(int * vetor, int inicio, int fim){
    int posicaoPivo;
    if(inicio < fim){
        posicaoPivo = particao(vetor, inicio, fim);
        QuickSort(vetor, inicio, posicaoPivo - 1);
        QuickSort(vetor, posicaoPivo + 1, fim);
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
    int vetor[8] = {2, 8, 7, 1,  3, 5, 6, 4};

    VectorShow(vetor, 8);

    QuickSort(vetor, 0, 8 - 1);

    VectorShow(vetor, 8);

    return 0;
}