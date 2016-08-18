#include <iostream>
#include "insertion_sort.h"


int main(int argc, const char* argv[])
{
	InsertionSort sort;
	
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
