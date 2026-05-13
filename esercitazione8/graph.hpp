#pragma once
#include <iostream>
#include "edge.hpp"
#include <set>
#include <vector>

template <typename T> requires std::integral<T>

class graph
{
	private:
	std::set<edge<T>> edges_; //identifichiamo i grafi in base a quali sono i loro archi
	
	public:
	
	//Costruttori:
	
	//grafo vuoto:
	graph()
	{
	}
	
	//grafo contenente un set di archi
	graph(const std::set<edge<T>>& s) : edges_(s)
	{
	}
	
	//di copia
	graph(const graph& g) : edges_(g.edges_)
	{
	}
	
	//metodo neighbours
	std::vector<T> neighbours(const T n) const
	{
		std::vector<T> neig;
		for(const edge<T>& e : edges_)
		{
			if(e.from()==n)
			{
				neig.push_back(e.to());
			}
			else if (e.to()==n)
			{
				neig.push_back(e.from());
			}
		}
		return neig;
		
	}
	
	//metodo add_edge
	void add_edge(T a, T b)
	{
		edge<T> e(a,b);
		edges_.insert(e);
	}
	
	//metodo all_edges(). restituisce un vector con tutti gli edges
	std::vector<edge<T>> all_edges() const
	{
		return std::vector<edge<T>> (edges_.begin(), edges_.end());
	}
	
	//metodo all_nodes: suppongo che esistano tutti i nodi dal numero 1 fino al nodo più alto contenuto in un arco. scorro quindi tutti gli archi per trovare il più alto m e lo salvo in un int
	T all_nodes() const
	{
		T m=0;
		for (const edge<T>& e : edges_)
		{
			if(e.from()>m)
			{
				m=e.from();
			}
			if (e.to()>m)
			{
				m=e.to();
			}
			
		}
		return m;
	}
	
	//metodo edge_number
	int edge_number(T a, T b) const
	{
		edge<T> r(a,b);
		auto N=edges_.find(r); //il metodo .find(r) cerca r in edges_. se find(r) non trova r in edges_, avremo N==edges_.end()
		if (N==edges_.end()) 
		{
			std::cout << "Il grafo non contiene l'arco " << r << "\n";
			return -1;
		}
		return std::distance(edges_.begin(),N);
	}
	
	//metodo edge_at
	edge<T> edge_at(T n) const //scorre il set edges_ fino all'n-esima posizione e ne restituisce il valore. se n è troppo grande, restituisce un edge (0,0)
	{
		int count=0;
		for(const edge<T> e: edges_)
		{
			if(count==n)
			{
				return e;
			}
			count++;
		}
		std::cout << "Indice non valido! \n";
		return edge<T>(0,0);
	}
	
	//operator-
	graph<T> operator-(graph<T>& g2) const
	{
		graph<T> sub;
		for (const edge<T>& e:edges_)
		{
			//usiamo find(e): per ciascun e (arco di "g1"), verifico che e non sia contenuto in g2 (quindi find(e) restituisce end(), ed in tal caso lo aggiungo a sub con il metodo add_edge()
			if(g2.edges_.find(e)==g2.edges_.end())
			{
				sub.add_edge(e.from(),e.to());
			}
		}
		return sub;
	}
};

//Utilizzo IA: l'intelligenza artificiale generativa è stata utilizzata per chiarire alcuni dubbi di forma (in particolare sulla sintassi corretta da utilizzare in alcuni punti del codice) e per avere una migliore comprensione del funzionamento dei contenitori. Il codice è interamente scritto a mano. 