#include <iostream>
#include <vector>

#include "sort.hpp"
#include "randfiller.h"

int main()
{
	randfiller rf;	
	for (int i=1; i<100; i++)
	{
		int dim=8*i;
		std::vector<int> V(dim);
		rf.fill(V, -1000, 1000);
	
		quick_insertion_sort(V, 0, V.size() - 1);
		
		if (!is_sorted(V))
		{
			return EXIT_FAILURE;
		}
	}
		
	std::vector<std::string> S= {"beta","alfa","omega","gamma"};
	quick_insertion_sort(S, 0, S.size()-1);
	if (!is_sorted(S))
	{
		return EXIT_FAILURE;
	}
	
	return EXIT_SUCCESS;

}