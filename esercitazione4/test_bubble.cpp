#include <iostream>
#include <vector>
#include <string>

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
	
		bubble_sort(V);
		
		if (!is_sorted(V))
		{
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
	
	std::vector<std::string> S= {"beta","alfa","omega","gamma"};
	bubble_sort(S);
	if (!is_sorted(S))
	{
		return EXIT_FAILURE;
	}
}