#include <iostream>
#include <vector>
#include <iomanip>
#include "timecounter.cpp"
#include "timecounter.h"
#include "randfiller.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "Bubble.h"
#include "Selection.h"
#include "Insertion.h"
#pragma once //per evitare l'errore computazionale di insertion.h duplicato

int main(){
    timecounter tc;
    randfiller rf;
    double t_B;  
    double t_S;
    double t_I;
    double t_Q;
    double t_M;
    double t_SO;
    std::cout<<std::scientific;
    std::cout<<std::setprecision(4);
    std::cout<<"Size \t"<<"Bubble \t \t"<<"Selection \t"<<"Insert   \t"<<"Quick \t \t"<<"Merge \t  \t" <<"std::sort \n"; 
    for(int size = 2; size<=100; size+= 1){ // per la verifica con bubble selection e insetion con quick e merge
        const int N =100;
        std::vector<std::vector<int>> vecvec(N);
        std::vector<int> vec(size);
        rf.fill(vec, -1000, 1000);
        for(int i = 0; i<100; i++){
            vecvec[i] = vec;
        }
        tc.tic();
        for (int j = 0; j<100; j++){
            Bubble(vecvec[j]);
        }
        t_B = tc.toc(); //tempo totale per calcolare il tempo di esecuzione su 100 vettori con Bubblesort


        std::vector<int> vec1(size);
        rf.fill(vec1, -1000, 1000);
        for(int i = 0; i<100; i++){
            vecvec[i] = vec1;
        }
            tc.tic();
        for (int j = 0; j<100; j++){
            Selection(vecvec[j]);
        }
        t_S = tc.toc();// tempo totale per calcolare il tempo di esecuzione su 100 vettori con Selection
        

        std::vector<int> vec2(size);
        rf.fill(vec2, -1000, 1000);
        for(int i = 0; i<100; i++){
            vecvec[i] = vec2;
        }
        tc.tic();
        for (int j = 0; j<100; j++){
            Insertion(vecvec[j],0,vecvec[j].size()-1);//per la modifica del quicksort ho dovuto mettere 0 e l'ultimo elemento
        }
        t_I = tc.toc();// tempo totale per calcolare il tempo di esecuzione su 100 vettori con Insertion


        std::vector<int> vec3(size);
        rf.fill(vec3, -1000, 1000);
        for(int i = 0; i<100; i++){
            vecvec[i] = vec3;
        }
        tc.tic();
        for (int j = 0; j<100; j++){
            QuickSort(vecvec[j], 0, vecvec[j].size()-1, 25);
        }
        t_Q = tc.toc();// tempo totale per calcolare il tempo di esecuzione su 100 vettori con Quinksort
        
        std::vector<int> vec4(size);
        rf.fill(vec4, -1000, 1000);
        for(int i = 0; i<100; i++){
            vecvec[i] = vec4;
        }  
        tc.tic();
        for (int j = 0; j<100; j++){
            MergeSort(vecvec[j], 0, vecvec[j].size()-1);
        }
        t_M = tc.toc();// tempo totale per calcolare il tempo di esecuzione su 100 vettori con Mergesort
    

        std::vector<int> vec5(size);
        rf.fill(vec5, -1000, 1000);
        for(int i = 0; i<100; i++){
            vecvec[i] = vec5;
        }
        tc.tic();
        for (int j = 0; j<100; j++){
            std::sort(vecvec[j].begin(),vecvec[j].end());
        }
        t_SO= tc.toc(); // tempo totale per calcolare il tempo di esecuzione su 100 vettori con std::sort
      
        //ho notato dal mio terminale che la soglia dove gli algoritmi logaritmici sono più veloci è 25. Quindi ho modificato il quicksort per renderlo più efficiente nelle dimensioni piccole 
        std::cout<<size<<"\t"<<t_B/100<<"\t"<<t_S/100<<"\t"<<t_I/100<<"\t"<<t_Q/100<<"\t"<<t_M/100<<"\t"<<t_SO/100<<"\n";
   }
}
//Ho notato che usando cmake normale il tempi alla dimensione 100 sono nell'ordine di 10^-05-10^-06
//usando il debug, ovvero un controllo più approfondito dei codici si ha dei tempi nell'ordine di 10^-05-10^-06
//usando il release, ovvero il più affidabile per il calcolo del tempo dato che cerca di arrivare direttamnte alla soluzione, si ha dei tempi all'ordine di 10^-07-10^-06 
//notando che con il comando release si hanno dei tempi indicativamente 10 volte più piccoli.  