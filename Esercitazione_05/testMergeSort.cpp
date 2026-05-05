#include <vector>
#include <iostream>
#include "is_sorted.h"
#include "MergeSort.h"
#include "randfiller.h"


int main(){
    randfiller rf;
    for (int i = 1; i<100;i++){
        std::vector<int> intero(1);
        rf.fill(intero,0,1000);
        int size = intero[0];
        std::vector<std::vector<int>> vecvec(size);
        for (int j = 0; j<size;j++){
            rf.fill(intero,0,1000);//genero una dimensione casuale per la dimensione per i vettori dentro i vettor
            int size1 = intero[0];
            std::vector<int> a(size1);
            rf.fill(a,-1000,1000);// riempio con numeri casuali il vettore interno 
            vecvec[j] = a;
        }

        std::vector<int> vec(size);
        rf.fill(vec,-1000,1000);
        int p = 0;
        int r = size - 1;
        MergeSort(vec,p,r);
        MergeSort(vecvec,p,r);
        bool x = is_sorted(vec);
        bool z = is_sorted(vecvec);
        if(x == false || z == false){
            for(int j=0;j<size;j++){
                std::cout<<vec[j]<<"; ";
            }
            std::cout<<"\n";
            return EXIT_FAILURE;
        }
    }
    std::vector<std::string> prova = {"Zefiro", "Altalena", "Bussola", "Crepuscolo", "Dinamite", "Eclissi", "Fogliame", "Girasole", "Ipotesi", "Labirinto", "Mosaico", "Nuvola"};
    MergeSort(prova,0 , prova.size()-1); // 0 e .size()-1 rappresnetano p ed r;
    bool y = is_sorted(prova);
    if (y == false){
        std::cout<<"c'è qualcosa di sbagliato";
    return EXIT_FAILURE;
    }

    std::cout<<"Tutto funziona \n";
    return EXIT_SUCCESS;


}
