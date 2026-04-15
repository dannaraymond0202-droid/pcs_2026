#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "randfiller.h"
#include "is_sorted.h"
#include "Selection.h"




int main() {
    randfiller rf;
    for (int i=1; i < 100; i += 1){
        
        std::vector<int> intero(1);   
        rf.fill(intero , 0 , 1000);   
        int size = intero[0];     //creo un numero singolo  
    
        std::vector<int> vec(size);  //creo il vettore di dimensione casuale




        rf.fill(vec, 0, 1000);
        Selection(vec);
        bool x = is_sorted(vec);
        if(x == false){
            std::cout<<"\n c'è qualcosa di sbagliato";
            return(EXIT_FAILURE);
        }
        
    }

    std::vector<std::string> vec_str = {"Zefiro", "Altalena", "Bussola", "Crepuscolo", "Dinamite", "Eclissi", "Fogliame", "Girasole", "Ipotesi", "Labirinto", "Mosaico", "Nuvola"};
    Selection(vec_str);
    bool y = is_sorted(vec_str);
    if(!y){
        std::cout<<"\n c'è qualcosa di sbalgiato " <<"\n";
        return EXIT_FAILURE;
    }

    std::cout<<"\n è tutto giusto";
    return(EXIT_SUCCESS);
}   