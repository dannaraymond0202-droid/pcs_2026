#include <algorithm> // per utilizzare 
#include <iostream> // per l'operzione << per la stampa
#include <set>
#include <list>// da capire al meglio che fanno queste librerie
#include <map> // da capire al meglio che fanno queste librerie


template<typename T>
class unidirected_edge{
private:
    T m_from;
    T m_to;

    public: 
        unidirected_edge(T node1, T node2){
            if(node1 == node2) {
                std::cout<<"Non puoi scrivere un arco con 2 nodi uguali"; 
            }
            m_from = std::min(node1, node2);
            m_to = std::max(node1, node2);
        }
        T from() const {return m_from; } // per restituire la funzione e.from() or e.to() 
        T to() const {return m_to; }


        bool operator<(const unidirected_edge& other) const{
            if(m_from<other.m_from){
                return true;
            }
            else if(m_from==other.m_from && m_to <other.m_to){
                return true;
            }
            else{
                return false;
            }

        }
        bool operator==(const unidirected_edge& other) const{ //questo const finale serve a a far capire al compilatore che con il l'operzione == non modifico niente 
            if(m_from==other.m_from && m_to==other.m_to) return true;
            else return false;
        }
        friend std::ostream&//serve per fagli capire cosa c'è a sinistra del <<
        operator<<(std::ostream& os, const unidirected_edge& edge){
            os<< edge.m_from<<"--->"<<edge.m_to;
           return os;
        }

};
        
