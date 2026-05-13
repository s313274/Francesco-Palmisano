#include <iostream>
#include "edge.hpp"
#include "graph.hpp"

int main()
{
	graph<int> g1;
	//creo un po' di archi per g1
	g1.add_edge(1, 2);
	g1.add_edge(1, 3);
	g1.add_edge(1, 4);
	g1.add_edge(2, 3);
	g1.add_edge(2, 5);
	g1.add_edge(3, 4);
	g1.add_edge(3, 6);
	g1.add_edge(4, 7);
	g1.add_edge(5, 6);
	g1.add_edge(5, 8);
	g1.add_edge(6, 7);
	g1.add_edge(6, 9);
	g1.add_edge(7, 10);
	g1.add_edge(8, 9);
	g1.add_edge(9, 10);
	
	//creo g2 con costruttore di copia e aggiungo altri nodi, di cui alcuni esistenti per verificare che non si creino copie
	graph<int> g2(g1);
	g2.add_edge(1, 3);
	g2.add_edge(3, 4);
	g2.add_edge(5, 6);
	g2.add_edge(7, 10);
	g2.add_edge(1, 10);
	g2.add_edge(2, 8);
	g2.add_edge(4, 9);
	g2.add_edge(5, 10);
	
	//stampo gli archi dei due grafi per verificarne l'inserimento e per testare all_edges
	std::cout << "archi di g1:\n";
	for (const edge<int>& e :g1.all_edges())
	{
		std::cout << e << ";";
	}
	std::cout << "\n\n";
	
	std::cout << "archi di g2:\n";
	for (const edge<int>& e :g2.all_edges())
	{
		std::cout << e << ";";
	}
	std::cout << "\n\n";
	
	//testo all_nodes:
	std::cout << "I nodi di g1 sono " << g1.all_nodes() << "\n";
	std::cout << "I nodi di g2 sono " << g2.all_nodes() << "\n\n";
	
	//testo neighbours(1) in entrambi i grafi per verificare che effettivamente siano diversi
	std::cout << "Vicini di 1 in g1: \n";
	for(int v:g1.neighbours(1))
	{
		std::cout << v << ", ";
	}
	std::cout << "\n";
	
	std::cout << "Vicini di 1 in g2: \n";
	for(int v:g2.neighbours(1))
	{
		std::cout << v << ", ";
	}
	std::cout << "\n\n";
	
	//cerco l'arco (7,10) in g1 e g2
	std::cout<< "L'arco (7,10) in g1 si trova in posizione " << g1.edge_number(7,10) << "\n";
	std::cout<< "L'arco (7,10) in g2 si trova in posizione " << g2.edge_number(7,10) << "\n\n";
	
	//stampo l'arco in posizione 5 di g1 e g2
	std::cout << "L'arco 5 di g1 è " << g1.edge_at(5) << "\n";
	std::cout << "L'arco 5 di g2 è " << g2.edge_at(5) << "\n";
	
	//testo l'operator-
	graph<int> g_diff= g2-g1;
	std::cout << "archi di g2-g1:\n";
	for (const edge<int>& e :g_diff.all_edges())
	{
		std::cout << e << ";";
	}
	std::cout << "\n\n";
}