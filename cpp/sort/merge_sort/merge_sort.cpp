#include "merge_sort.h"

int MergeSort::sort(Array &array, int left, int right)
{
	std::vector temp[array.Size()];

	if(left >= right)
		return 0;
	
	int mid = (left + right) / 2;
	sort(array, left, mid);
	sort(array, mid + 1, right);
	
}

int MergeSort::Sort(Array &array)
{
	return 0;
}
