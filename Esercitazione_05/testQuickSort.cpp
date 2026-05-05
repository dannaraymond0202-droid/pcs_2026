#include <vector>
#include <iostream>
#include "QuickSort.h"
#include "is_sorted.h"
#include "randfiller.h"

int main(){
    randfiller rf;
    for(int i = 1;i < 101; i++){
        std::vector<int> intero(1);
        rf.fill(intero,0,1000);
        int size = intero[0];
        std::vector<std::vector<int>> vecvec(size);
        for (int j = 0; j<size;j++){
            rf.fill(intero,0,1000);//genero una dimensione casuale per la dimensione per i vettori dentro i vettori
            int size1 = intero[0];
            std::vector<int> a(size1);
            rf.fill(a,-1000,1000);// riempio con numeri casuali il vettore interno 
            vecvec[j] = a;
        }

        std::vector<int> vec(size);
        rf.fill(vec,-1000,1000);
        int p = 0;
        int r = size - 1;
        QuickSort(vec, p, r,100000);  //L'ultimo termine della funzione QuickSort rappresenta la soglia secondo il quale l'algoritmi di ordinamento quatratici sono più veloci rispetto al quicksort.
        QuickSort(vecvec,p,r,100000); //Dato che io voglio testare proprio che il test funzioni voglio la soglia pari ad un numero maggiaro della taglia del vettore testato
        bool x = is_sorted(vec);
        bool z = is_sorted(vecvec);
        if (x == false || z == false){
            std::cout<<"c'è qualcosa di sbagliato nei numeri";
            return EXIT_FAILURE;
        }
    }
    std::vector<std::string> prova = {"Zefiro", "Altalena", "Bussola", "Crepuscolo", "Dinamite", "Eclissi", "Fogliame", "Girasole", "Ipotesi", "Labirinto", "Mosaico", "Nuvola"};
    QuickSort(prova,0 , prova.size()-1,100000); // 0 e .size()-1 rappresentano p ed r;
    bool y = is_sorted(prova);
    if (y == false){
        std::cout<<"c'è qualcosa di sbagliato nelle stringhe";
        return EXIT_FAILURE;
    }

    std::cout<<"è tutto giusto";
    return EXIT_SUCCESS;
}

