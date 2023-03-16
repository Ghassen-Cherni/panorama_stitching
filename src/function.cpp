#include "function.h"
#include <math.h>
#include <iostream>


void print()
{
	int i{5};
	while(i >= 0){
		int j = i;
		while(j >= 0){
			std::cout << j << " ";
			j--;
		}
		i--;
		std::cout << '\n';


	}


}


