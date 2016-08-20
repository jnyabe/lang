#include "bubble_sort.h"

int BubbleSort::Sort(Array &array) const
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
	return 0;
}
