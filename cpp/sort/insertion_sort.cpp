#include "insertion_sort.h"


int InsertionSort::Sort(Array &array) const
{
	for(int i=1; i < array.Size(); i++)
	{
		for(int j=i; j > 0 && array[j-1] >  array[j]; j--)
		{
			array.Swap(j-1, j);
			//			array.Print("insert");
		}
	}
	return 0;
}

