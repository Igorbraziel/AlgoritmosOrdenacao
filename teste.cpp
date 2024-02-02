#include <iostream>
#include <stdlib.h>

void troca(int * a, int * b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

//////////////////////////////////////////////////

void Merge(int * vetor, int inicio, int meio, int fim){
    int com1 = inicio, com2 = meio + 1;
    int aux = 0;
    int vetorAuxiliar[fim - inicio + 1];

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]){
            vetorAuxiliar[aux] = vetor[com1];
            com1++;
        } else{
            vetorAuxiliar[aux] = vetor[com2];
            com2++;
        }
        aux++;
    }

    while(com1 <= meio){
        vetorAuxiliar[aux] = vetor[com1];
        com1++;
        aux++;
    }

    while(com2 <= fim){
        vetorAuxiliar[aux] = vetor[com2];
        com2++;
        aux++;
    }

    aux = 0;

    for(com1 = inicio; com1 <= fim; com1++){
        vetor[com1] = vetorAuxiliar[aux];
        aux++;
    }
}

void MergeSort(int * vetor, int inicio, int fim){
    int meio;

    if(inicio < fim){
        meio = (fim + inicio) / 2;

        MergeSort(vetor, inicio, meio);
        MergeSort(vetor, meio + 1, fim);
        Merge(vetor, inicio, meio, fim);
    }
}

//////////////////////////////////////////////////

int particao(int * vetor, int inicio, int fim){
    int pivo = vetor[fim];
    int i = inicio, j;

    for(j = inicio; j <= fim - 1; j++){
        if(vetor[j] <= pivo){
            troca(&vetor[i], &vetor[j]);
            i++;
        }
    }
    troca(&vetor[fim], &vetor[i]);
    return i;
}

void QuickSort(int * vetor, int inicio, int fim){
    int posicaoPivo;

    if(inicio < fim){
        posicaoPivo = particao(vetor, inicio, fim);
        QuickSort(vetor, inicio, posicaoPivo - 1);
        QuickSort(vetor, posicaoPivo + 1, fim);
    }
}

///////////////////////////////////////////////////

void InsertionSort(int * vetor, int tamanho){
    int i, j, auxiliar;

    for(i = 1; i < tamanho; i++){
        j = i - 1;
        auxiliar = vetor[i];
        while(j >= 0 && vetor[j] > auxiliar){
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = auxiliar;
    }
}

///////////////////////////////////////////////////

void BubbleSort(int * vetor, int tamanho){
    int i, j;

    for(i = tamanho - 1; i > 0; i--){
        for(j = 0; j < i - 1; j++){
            if(vetor[j] > vetor[j + 1]){
                troca(&vetor[j], &vetor[j + 1]);
            }
        }
    }
}


///////////////////////////////////////////////////

void SelectionSort(int * vetor, int tamanho){
    int i, j, chave;

    for(i = 0; i < tamanho; i++){
        for(j = i; j < tamanho; j++){
            if(i == j){
                chave = j;
            } else if(vetor[j] < vetor[chave]){
                chave = j;
            }
        }
        troca(&vetor[i], &vetor[chave]);
    }
}


///////////////////////////////////////////////////

void VectorShow(int * vetor, int tamanho){
    int i;

    for(i = 0; i < tamanho; i++){
        std::cout << vetor[i] << " ";
    }

    std::cout << "\n\n";
}

int main(){
    int vetor[50] = {74, 32, 18, 95, 61, 45, 87, 23, 9, 52,
                     67, 3, 28, 50, 14, 89, 42, 36, 71, 6,
                     97, 19, 55, 81, 39, 64, 10, 49, 92, 27,
                     12, 83, 58, 21, 75, 1, 46, 78, 33, 68,
                     93, 17, 24, 63, 30, 57, 8, 70, 4, 98};

    VectorShow(vetor, 50);

    SelectionSort(vetor, 50);

    VectorShow(vetor, 50);

    return 0;
}