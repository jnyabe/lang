#include "../common/array.h"
#include <iostream>

void bubble_sort(Array &array)
{
	// n * (n-1) / 2
	for(int i=0; i < array.Size() - 1 ; i++)
	{
		for(int j=i + 1; j < array.Size(); j++)
		{
			if(array[i] > array[j])
			{
				array.Swap(i, j);
			}
		}
	}
}


int main(int argc, const char* argv[])
{
	for(int i=1; i < argc; i++)
	{
		try {
			Array array(std::stoi(argv[i]));
			array.Shuffle();
			
			array.Print("[before sort]");

			bubble_sort(array);
			
			array.Print("[after sort]");
		} catch(std::invalid_argument e) {
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}
