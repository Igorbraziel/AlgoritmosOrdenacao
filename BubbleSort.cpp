#include <iostream>
#include <stdlib.h>

void troca(int * a, int * b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort1(int * vetor, int tamanho){
    int i, j, auxiliar;

    for(i = tamanho - 1; i > 0; i--){
        for(j = 0; j < i; j++){
            if(vetor[j] > vetor[j + 1]){
                troca(&vetor[j], &vetor[j + 1]);
            }
        }
    }
}

void BubbleSort2(int * vetor, int tamanho){
    int i, ordem = 0;

    while(true){
        for(i = 0; i < tamanho - 1; i++){
            if(vetor[i] > vetor[i + 1]){
                troca(&vetor[i], &vetor[i + 1]);
            } else{
                ordem++;
            }
        }
        if(ordem == tamanho - 1) break;
        ordem = 0;
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
    int vetor[7] = {75, 44, 55, 9, 8, 212, 121};

    VectorShow(vetor, 7);

    BubbleSort2(vetor, 7);

    VectorShow(vetor, 7);

    return 0;
}