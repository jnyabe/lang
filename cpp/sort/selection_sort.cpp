#include "selection_sort.h"

int SelectionSort::Sort(Array &array) const
{


	for(int i=0; i < array.Size() - 1;i++)
	{
		for(int j=i; j < array.Size();j++)
		{
			if(array[j] < array[i])
				array.Swap(i, j);
		}
	}
	return 0;
}
