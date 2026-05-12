#include <algorithm>
#include <iostream> 
#include <set>
#include <list>
#include <map> 
#include "unidirected_edge.hpp"



template<typename T>
class unidirected_graph{
private:
    std::set<T> g_node; //per inserire dei nodie la libreria set li ordina e non aggiunge duplicati
    std::set<unidirected_edge<T>> g_edge; //ordina gli archi definiti sopra e non aggiunge duplicati
    std::map<T, std::set<T>> g_near;//per i nodi vicini 
    std::map<unidirected_edge<T>, size_t> g_edge_to_id; // indiciza gli arci del grafo e id restituisce l'id di una arco preciso 
    std::map<size_t, unidirected_edge<T>> g_id_to_edge; // fa esattamente l'inverso 
    size_t g_next_edge_id;
    //size_t è un int ma solo positivo e con una spazio della memoria non sempre 32 bit ma variabile.


public:
    unidirected_graph() : g_next_edge_id(0) {} // costruisco di default il grafo  
    unidirected_graph(const unidirected_graph& other) = default;

    void add_edge(const T& a,const T& b){
        unidirected_edge<T> e(a,b);
        if(g_edge.insert(e).second) { // verifico se esiste l'arco da a a b
            g_node.insert(a);
            g_node.insert(b); // creo i nodi 

            g_near[a].insert(b); // questi due comandi servono per inizilizzare il la mappa near
            g_near[b].insert(a); 
            g_edge_to_id[e] = g_next_edge_id; // essenziale per gli "indici"
            g_id_to_edge.insert({g_next_edge_id, e});
            g_next_edge_id ++;
        }
    }
    std::set<T> neighbours(const T& n) const{
        auto it = g_near.find(n); // it è un iteratore che mi indica se esiste la posizione nella mappa (nodi, vicini)
        if (it != g_near.end()) return (*it).second;
        return std::set<T>{};         //*it non indica un puntatore sulla memoria ma sulla mappa e con .second mi restituisce i valori della chiave associata. mentre con .fist mi avrebbe restituito la parola chiave stessa.
    }

    std::set<unidirected_edge<T>> all_edges() const{
        return g_edge;
    }
    std::set<T> all_nodes() const{
        return g_node;
    }

    size_t edge_number(const unidirected_edge<T>& e) const{ //trovo l'id dell'arco
        return g_edge_to_id.at(e); // la funziona at cerca la parola chiave e restituisce il suo valore 
    }                              // quindi in questo coso cerca l'arco e e restituisce id che ha.

    unidirected_edge<T> edge_at(size_t id) const{ // fa l'operazione opposta
        return g_id_to_edge.at(id); // ovvimente la stessa cosa ma cerca l'id e restituisce l'arco
    }

    unidirected_graph operator-(const unidirected_graph& other) const{
        unidirected_graph result;
        for (const auto& e :g_edge){ // questo tipo di for è come in python ovvero for e in g_edge. facendo assumere e ogni arco dentro g_edge
            if (other.g_edge.find(e) == other.g_edge.end()){ // la funziona .find(e) restituisce .end() se non trova l'arco e in other.g_edge
                result.add_edge(e.from(), e.to());// se e non è in other allora aggiunge l'arco nel risultato. 
            }
        }
        return result;
    }
};
