
#include "unidirected_graph.hpp"
#include <iostream>
#include <set>

int main(){
    unidirected_edge<int> arco(3, 8);
    unidirected_edge<int> arco1(0,2);
    unidirected_graph<int> G;
    if (8 == arco.from()) return(EXIT_FAILURE);
    if (0 == arco1.to()) return(EXIT_FAILURE);

    G.add_edge(4,7); // da provare semplicemnte con gli archi.
    G.add_edge(3,8);
    G.add_edge(1,8);
    std::set<int> n = G.all_nodes();
    std::set<unidirected_edge<int>> e = G.all_edges();

    std::set<int> f = {1, 8, 7, 4,3}; // per i test
    std::set<unidirected_edge<int>> p = {{7,4}, {8,3}, {1,8}};// per i test
    if (n != f || e != p) return(EXIT_FAILURE);

    std::cout << "Nodi vicini a 8: { ";
    for (const auto& ni : G.neighbours(8)) {
        std::cout << ni << " "; // Stampo ogni singolo intero
    }
    std::cout << "}" << "\n Archi di G: {";
    for(const auto& ei : e) {
        std::cout<< ei<< " ";
    }

    std::cout<<"}";
    std::set<int> v = G.neighbours(8);
    std::set<int> u = {1 ,3}; // per i test
    if (u != v) return(EXIT_FAILURE);
    

    unidirected_graph<int> G1;
    G1.add_edge(4,7);
    G1.add_edge(9,8);
    G1.add_edge(10,16);
    unidirected_graph<int> G2 = G1-G;
    std::cout << "Nodi di G1-G: { ";
    for (const auto& ni : G2.all_nodes()) {
        std::cout << ni << " "; // Stampo ogni singolo intero
    }
    std::cout << "}" << "\n Archi: {";
    for(const auto& ei : G2.all_edges()) {
        std::cout<< ei<< " ";
    }
    std::cout<<"}";

    std::set<int> n2 = G2.all_nodes(); 
    std::set<unidirected_edge<int>> e2 = G2.all_edges();
    std::set<int> f2 = {9,10, 16, 8}; // per i test
    std::set<unidirected_edge<int>> p2 = {{9,8}, {10,16}};// per i test
    if (n2 != f2 || e2 != p2) return(EXIT_FAILURE);


return(EXIT_SUCCESS);
}
