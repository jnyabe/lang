#include "bogo_sort.h"

int BogoSort::Sort(Array &array) const
{
	while(!IsSorted(array))
	{
		array.Shuffle();
	}
	return 0;
}
