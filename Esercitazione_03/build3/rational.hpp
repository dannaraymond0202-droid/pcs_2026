#include "string"
#include "iostream"
#include <cmath>

template<typename I> requires std::integral<I>
class rational {
     
private:
    int MCD(int a, int b){//metodo di eulero per il Mcd
        if (abs(a)<abs(b)){
            int r = 1;
            while(r!=0){
                r = abs(b)%abs(a);
                b = abs(a);
                a = r; 
            }
        }
        else{
            int r = 1;
            while (r!=0){
                r = abs(a)%abs(b);
                a = abs(b);
                b = r;
            }
        }
        return std::max(a,b);
    }

public:
    I numerator;
    I denominator;
    std::string identity;
    friend std::ostream&//creo una stringa per la stampa utilizando l'operatore <<
    operator<<(std::ostream& os, const rational r){
        if (r.identity == "NaN" || r.identity == "Inf"){
            os << r.identity;
        }
        else if (r.numerator == 0){
            os<<0;
        }
        else {
            os << r.numerator<<"/"<<r.denominator;
        }
        return os;
    }


    rational();
    rational(int num, int den){
        
    if (num == 0 && den == 0) {
        identity = "NaN";
    }
    else if (den == 0){
        identity = "Inf";
   }

    else{
        int mcd = MCD(num,den);
        num  = num/mcd;
        den = den/mcd;
        numerator = num;
        denominator = den;
        identity = " ";
    }
    
    if (denominator<0){
            denominator = - denominator;
            numerator = -numerator; // per far spuntare il meno all'inizio della frazione e non a metà
    }    
    
    }
    //somma:
    rational operator+=(const rational& other) {//incremento di una razionale
        I new_num;
        I new_den;
        std::string new_ide;
        if (identity == "NaN" || other.identity == "NaN"){
            new_ide = "NaN";
        }
        else if (identity == "Inf" || other.identity == "Inf"){
            new_ide = "Inf";
        }
        else{
            new_num  = (numerator * other.denominator) + (other.numerator * denominator);
            new_den  = denominator * other.denominator;
            if(new_num != 0){//questo if è importante perché se no nella funzine MCD divide per 0
                int mcd = MCD(new_num,new_den);
                new_num /= mcd;
                new_den /= mcd;
            }
        }       
        numerator = new_num;
        denominator = new_den;
        identity = new_ide;
        return *this;
    }
    rational operator+(const rational& other) const{//normale somma creando una nuova variabile
        rational risultato = *this;
        risultato += other;
        return risultato;
    }

    //differenza:
    rational operator-=(const rational& other) {
        I new_num; 
        I new_den;
        std::string new_ide;
        if (identity == "NaN" || other.identity == "NaN"){
            new_ide = "NaN";
            }
        else if (identity == "Inf" || other.identity == "Inf"){
            new_ide = "Inf";
        }
        else{
            new_num = (numerator * other.denominator) - (other.numerator * denominator);
            new_den = denominator * other.denominator;
            if ( new_num != 0){
                int mcd = MCD(new_num,new_den);
                new_num /= mcd;
                new_den /= mcd;
            }
        }
        numerator = new_num;
        denominator = new_den;
        identity = new_ide; 
        return *this;   
    }

    rational operator-(const rational& other) const{
        rational risultato = *this;
        risultato -= other;
        return risultato;
    }


    //prodotto:
    rational operator*=(const rational& other){
        I new_num;
        I new_den;
        std::string new_ide;
        if (identity == "NaN" || other.identity == "NaN"){
            new_ide = "NaN";
        }
        else if (identity == "Inf" || other.identity == "Inf"){
            new_ide = "Inf";
        }
        else{
            new_num = numerator * other.numerator;
            new_den = denominator * other.denominator;
            if (new_num != 0){           
                int mcd = MCD(new_num,new_den);
                new_num /= mcd;
                new_den /= mcd;
            }
        }    
        numerator = new_num;
        denominator = new_den;
        identity = new_ide; 
        return *this;
    }

    rational operator*(const rational& other) const{
        rational risultato = *this;
        risultato *= other;
        return risultato;
    }


    //divisione:
    rational operator/=(const rational& other) {
        
        I new_num;
        I new_den;
        std::string new_ide;
        if (identity == "NaN" || other.identity == "NaN"){
            new_ide = "NaN";
        }
        else if (identity == "Inf" || other.identity == "Inf"){
            new_ide = "Inf";
            }
        else{
            new_num = numerator * other.denominator;
            new_den = denominator * other.numerator;
            if(new_num != 0){
                int mcd = MCD(new_num,new_den);
                new_num /= mcd;
                new_den /= mcd;
            
                if (new_den<0){
                    new_den = - new_den;
                    new_num = -new_num; 
                }// ho messo nella divisione questo if in più perché per come l'ho definita il numero poteva andare al denominatore 
            }
        }
        numerator = new_num;
        denominator = new_den;
        identity = new_ide; 
        return *this;
    }

    rational operator/(const rational& other) const{
        rational risultato = *this;
        risultato /= other;
        return risultato;
    }
    
    I num() const {return numerator;}
    I den() const {return denominator;}//per avere nel main rispettivamente il numeratore e il denominatore con ul comando r.num()
};
         
