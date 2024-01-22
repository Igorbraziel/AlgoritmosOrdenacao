#include <iostream>
#include <stdlib.h>

void MergeSort(int * vetor, int inicio, int fim){
    int meio;

    if(inicio < fim){
        meio = (inicio + fim) / 2;

        MergeSort(vetor, inicio, meio);
        MergeSort(vetor, meio + 1, fim);
        Merge(vetor, inicio, meio, fim);
    }
}

void Merge(int * vetor, int inicio, int meio, int fim){
    int com1 = inicio, com2 = meio + 1, comAuxiliar = 0;
    int vetorAuxiliar[fim - inicio + 1];    

    if(com1 <= meio, com2 <= fim){
        if(vetor[com1] <= vetor[com2]){
            vetorAuxiliar[comAuxiliar] = vetor[com1];
            com1++;
        } else{
            vetorAuxiliar[comAuxiliar] = vetor[com2];
            com2++;
        }
        comAuxiliar++;
    }

    while(com1 <= meio){ // caso tenha sobrado algum valor na primeira faixa ele será colocado no vetor auxiliar
        vetorAuxiliar[comAuxiliar] = vetor[com1];
        comAuxiliar++;
        com1++;
    }
}