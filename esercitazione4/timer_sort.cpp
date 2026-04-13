#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#include "sort.hpp"
#include "randfiller.h"
#include "timecounter.h"

int main()
{
	timecounter tc;
	randfiller rf;
	for (int i=2; i<=13; i++)
	{
		int dim= std::pow(2,i);
		std::vector<int> V0(dim);
		rf.fill(V0, -1000, 1000);
		
		std::cout << "Dimensione: " << dim << "\n";
		
		std::vector<int>V=V0;
		tc.tic();
		std::sort(V.begin(),V.end());
		double t=tc.toc();
		std::cout << "Tempo sort classico: " << t << "\n";
		
		V=V0;
		tc.tic();
		bubble_sort(V);
		t=tc.toc();
		std::cout << "Tempo bubble sort: " << t << "\n";
		
		V=V0;
		tc.tic();
		insertion_sort(V);
		t=tc.toc();
		std::cout << "Tempo insertion sort: " << t << "\n";
		
		V=V0;
		tc.tic();
		selection_sort(V);
		t=tc.toc();
		std::cout << "Tempo selection sort: " << t << "\n\n";
		
		
	}
}