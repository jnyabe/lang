#include "../common/array.h"
#include <iostream>

static void insertion_sort(Array &array)
{
	// Best Time Complexity: O(N)
	// Average Time Complexity: O(N^2)
	// Worst Time Complexity: O(N^2)
	for(int i=1; i < array.Size(); i++)
	{
		for(int j=i; j > 0 && array[j-1] >  array[j]; j--)
		{
			array.Swap(j-1, j);
			array.Print("insert");
		}
	}
}

int main(int argc, const char* argv[])
{
	for(int i=1; i < argc; i++)
	{
		try {
			Array array(std::stoi(argv[i]));
			array.Shuffle(10);
			array.Print("[before insertion_sort]");
			insertion_sort(array);
			array.Print("[after insertion_sort]");
		} catch(std::invalid_argument e) {
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}
