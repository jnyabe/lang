#include "quick_sort.h"
#include <iostream>

int main(int argc, const char* argv[])
{
	QuickSort sort;
	
	for(int i=1; i < argc; i++)
	{
		try {
			Array array(std::stoi(argv[i]));
			sort.Test(array);
		} catch(std::invalid_argument e) {
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}
