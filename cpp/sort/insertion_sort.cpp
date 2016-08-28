#include "insertion_sort.h"


void InsertionSort::sort1(Array& array) const
{
	// simple
	for(int i=1; i < array.Size(); i++)
	{
		for(int j=i; j > 0 && array[j-1] >  array[j]; j--)
		{
			array.Swap(j-1, j);
			//			array.Print("insert");
		}
	}	
}

void InsertionSort::sort2(Array& array) const
{
	// inline
	for(int i=1; i < array.Size(); i++)
	{
		for(int j=i; j > 0 && array[j-1] > array[j]; j--)
		{
			int t = array[j];
			array[j] = array[j-1];
			array[j-1] = t;
		}
	}	
}

void InsertionSort::sort3(Array& array) const
{
	for(int i=1; i < array.Size(); i++)
	{
		int t = array[i]; // *) move from the internal loop
		int j;
		for(j=i; j > 0 && array[j-1] > t; j--)
			array[j] = array[j-1];
		array[j] = t;	  // *) move from the internal loop	
	}		
}

int InsertionSort::Sort(Array &array) const
{
	sort3(array);
	return 0;
}

