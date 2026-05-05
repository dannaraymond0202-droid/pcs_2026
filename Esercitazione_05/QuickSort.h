#include <vector>
#include <utility> // per usare swap
#include "Insertion.h"
#pragma once //per evitare l'errore di computazione per la duplicazione del file Insertion.h 

template <typename T>
int Partition(std::vector<T>& A, int p, int r){
    T x = A[r];
    int i = p - 1;
    for (int j = p; j<r; j++){
        if (A[j] <= x){
            i += 1;
            std::swap(A[i],A[j]);
        }
    }
    std::swap(A[i+1],A[r]);
    return i+1;
};


template <typename T>
void QuickSort(std::vector<T>& A, int p, int r,int soglia){
    if (p<r){
        if(r-p+1<= soglia){ //questa è la parte modificata per rendere il quicksort più efficate  
            Insertion(A,p,r);//nelle dimensioni piccole usando il metodo più veloce tra gli algoritmi quadraatici 
        }
        else{
            int q = Partition(A,p,r);
            QuickSort(A,p,q-1,soglia);
            QuickSort(A,q+1,r,soglia);
        }
    }
};
