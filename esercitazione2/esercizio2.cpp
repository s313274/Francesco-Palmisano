#include <iostream>
#include <algorithm>
#include <cmath>

int main()
{
	static const int N=20;
	double v[N] = {12.5, -3.2, 45.0, 7.8, -10.25, 0.0, 33.1, -1.5, 22.9, 100.4, -50.0, 14.2, 8.8, -0.75, 66.3, 19.1, -12.4, 5.5, 41.2, -9.9}; //Inizializzazione vettore con N=20 elementi "causali"
	
	double max_v = v[0]; 
	double min_v = v[0]; 
	double somma = 0.0; //Inizializzo il massimo, il minimo e la somma
	
	for (int i=0; i<N; i++)
	{
		max_v=std::max(max_v,v[i]); //per ogni i, salvo in max/min il valore maggiore/minore tra max_v/min_v e v[i]
		min_v=std::min(min_v,v[i]);
		somma += v[i]; //aggiungo l'elemento i-esimo alla somma
	} //in questo ciclo ho calcolato minimo, massimo e somma (per la media e la deviazione standard)
	
	double media = somma / N; //calcolo la media
	
	double scarto=0.0; //inizializzo lo scarto
	for (int i=0; i<N; i++)
	{
		scarto+= (v[i]-media)*(v[i]-media); 
	}//calcolo lo scarto
	double ds= sqrt(scarto/N); //calcolo la deviazione standard
	
	std::cout << "Valore minimo: " << min_v << "\n";
	std::cout << "Valore massimo: " << max_v << "\n";
	std::cout << "Media: " << media << "\n";
	std::cout << "Deviazione standard: " << ds << "\n";
	
	return 0;
}

//utilizzo IA: l'intelligenza artificiale generativa è stata utilizzata per chiarire alcuni dubbi di forma (in particolare sulla sintassi corretta da utilizzare in alcuni punti del codice) e per approfondire e chiarire alcuni concetti. Il codice è interamente scritto a mano. 