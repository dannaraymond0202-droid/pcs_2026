#include <iostream>
#include "rational.hpp"
int main(){
    rational<int> r1(0,0);
    rational<int> r2(38,-8);
    rational<int> r3(57,21);
    rational<int> r4(34567,0);
    rational<int> r5(9876, 123);

    rational<int> s =r3 + r2;
    rational<int> t = r3 - r2;
    r5 *= r4;
    rational<int> p = r1 / r3;
   
    
    std::cout<<"\n La somma tra "<< r3 << " e "<<r2 <<" vale: "<<s<<"\n";
    std::cout<<"\n La differenza tra "<< r3 << " e "<<r2<< " vale: "<<t<<"\n";
    std::cout<<"\n L'incremento con il prodotto vale: "<<r5<<"\n";
    std::cout<<"\n Il rapporto tra "<< r1<< " e "<< r3 <<" vale: "<<p<<"\n";
    return 0;
}