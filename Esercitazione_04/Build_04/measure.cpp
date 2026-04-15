#include <iostream>
#include <vector>
#include <iomanip> //per scrivere in modo ordinato il terminale
#include "timecounter.cpp"
#include "Selection.h"
#include "Bubble.h"
#include "Insertion.h"
#include "randfiller.h"

int main(){
    timecounter tc;
    randfiller rf;
    std::cout<<std::left
        << std::setw(10) << "Size"  // i numeri dentro il setw() servono per dare i spazi da una colonna e l'altra.
        << std::setw(15) << "Bubble" 
        << std::setw(15) << "Insertion" 
        << std::setw(15) << "Selection" 
        << std::setw(15) << "STD::SORT" << std::endl;
    std::cout<<std::string(70,'-')<<"\n";
    for(int i = 4; i<=8192; i *=2){
        std::vector<int> vec(i);
        rf.fill(vec,0,10000);//creo il vettore di dimensione i= 4 8 16 ... 8192
        tc.tic();
        Bubble(vec);    
        double t_B = tc.toc();  //calcolo il tempo per bubble
 
        
        rf.fill(vec,0,10000);

        tc.tic();
        Insertion(vec);
        double t_I = tc.toc(); //calcolo il tempo per Insertion
        

        
        rf.fill(vec,0,10000);
        tc.tic();
        Selection(vec);
        double t_S = tc.toc(); //calcolo il tempo per selection

        
        rf.fill(vec,0,10000);
        tc.tic();
        std::sort(vec.begin(),vec.end()); 
        double t_SORT = tc.toc(); // calcolo il tempo per SORT
        std::cout<< std::left <<std::setw(10)<<i
            <<std::scientific<<std::setprecision(3) // max 3 numeri e usando std::scientific lo obbligo ad usare e^..
            <<std::setw(15)<<t_B
            <<std::setw(15)<<t_I
            <<std::setw(15)<<t_S
            <<std::setw(15)<<t_SORT<<"\n"; //come si vede dal terminale il più veloce è sempre std::sort per ogni dimensione da 4 8 16 ... 8192
    }
}

