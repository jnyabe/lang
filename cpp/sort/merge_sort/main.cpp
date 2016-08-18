#include "merge_sort.h"
#include <iostream>

int main(int argc, const char* argv[])
{
	MergeSort sort;
	
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
