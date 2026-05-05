#include <vector>
#pragma once


//Insertion modificato con gli indici per metterlo dentro a quicksort

template<typename I>
void Insertion(std::vector<I>& A, int p, int r){
    int N = r-p+1;
    if (N == 0 || N == 1){
    return;
    }
    for(int j = p+1; j<N; j += 1){
        I key = A[j];
        int i = j-1;  
        while(i>=p && A[i]>key){
            A[i+1] = A[i];
            i = i-1;
        }
        A[i+1] = key;
    }
}