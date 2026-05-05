#include <vector>
//#include <limits> //per descivere l'inf in R e L

template <typename T>
void Merge(std::vector<T>& A,int p,int q,int r){
    int n1 = q-p+1;
    int n2 = r-q;
    std::vector<T> L(n1 + 1);// divido il vettore 
    std::vector<T> R(n2 + 1);
    for (int i = 0; i< n1; i++) {
        L[i] = A[p+i];
    }
    for (int j = 0; j< n2;j++) {
        R[j] = A[q+j+1];
    }
    //L[n1] = std::numeric_limits<T>::max();
    //R[n2] = std::numeric_limits<T>::max(); 
    int i = 0;
    int j = 0; // Ho evitato di mettere i limiti per non avere problemi con le stringe 
    for(int k = p; k<=r; k++){//quindi ho manipolato gli indici
        if((L[i]<=R[j] || j>=n2) && i<n1){
            //la condizione verifica che L[i] <= R[j] o che j>=n2  
            A[k] = L[i]; // ed entra nel solo con i<n1 se no qui da un crash
            i +=1;
        }
        else{ //quindi banalmente iniziando con i,j = 0 entra nel else solo per R L[i]>R[j]
            A[k] = R[j];//il che incrementa j e modifica A
            j +=1;
        }
    }
};

template <typename T>
void MergeSort(std::vector<T>& A,int p,int r){
    if (p<r){ // questa è la condizione centrale del Merge che verifica quando l'ordinamento è concluso
        int q = p + (r-p)/2;
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,r);
    }
};




