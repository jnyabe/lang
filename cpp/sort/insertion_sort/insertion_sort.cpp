#include "insertion_sort.h"

std::string InsertionSort::GetName(void) const
{
	return "InsertionSort";
}

int InsertionSort::Exec(Array &array)
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
	return 0;
}

