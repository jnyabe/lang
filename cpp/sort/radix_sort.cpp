#include "radix_sort.h"

int RadixSort::Sort(Array &array) const
{
	int maxRadix = 100; 
	std::vector<int> rad(array.Size()); // for stroring mod
	std::vector<int> tmp(array.Size()); // 

	for(int m=1; m <= maxRadix; m*=10)
	{
		for(int i=0; i < array.Size();i++)
		{
			rad[i] = (array[i] / m) % 10;
		}
		
		int k = 0;
		for(int i=0; i < 10; i++)
		{
			for(int j=0; j < array.Size(); j++)
			{
				if(rad[j] == i)
				{
					tmp[k++] = array[j]; // copy array to tmp based on 'mod'
				}
			}
		}
		
		for(int i=0; i< array.Size(); i++)
		{
			array[i] = tmp[i];   // copy tmp back to array
		}
		// array.Print("->");
	}
	return 0;
}
