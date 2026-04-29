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
	
		insertion_sort(V);
		
		if (!is_sorted(V))
		{
			return EXIT_FAILURE;
		}
	}
	
	std::vector<std::string> S= {"beta","alfa","omega","gamma"};
	insertion_sort(S);
	if (!is_sorted(S))
	{
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;

}