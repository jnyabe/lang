#include "merge_sort.h"


int MergeSort::sort(Array &array, std::vector<int> temp, int left, int right) const
{
	
	
	if (right - left < 1)
	{
		// do nothing, if only 1 elements
	} else {
		int mid = left + (right - left) / 2;
		// printf("sort(%d, %d)->sort(%d,%d) + sort(%d, %d)\n", left, right, left, mid, mid+1, right);
		sort(array, temp, left, mid);
		sort(array, temp, mid + 1, right);
		merge(array, temp, left, mid + 1, right);
	}
	return 0;
}

int MergeSort::merge(Array &array, std::vector<int> temp, int left, int mid, int right) const
{

	int tmp_pos  = left;
	int lc = left;
	int rc = mid;

	while ((lc <= mid - 1) && (rc <= right))
	{
		if (array[lc] <= array[rc])
		{
			temp[tmp_pos++] = array[lc++];
		} else {
			temp[tmp_pos++] = array[rc++];
		}
	}
	
	while (lc <= mid - 1)
	{
		temp[tmp_pos++] = array[lc++];
	}

	while (rc <= right)
	{
		temp[tmp_pos++] = array[rc++];
	}

	// printf("merge(%d-%d, %d-%d)\n\t", left, mid-1, mid, right);
	for (int i=left; i <= right; i++)
	{
		array[i] = temp[i];
		//		printf("%d,", array[i]);
	}
	//	printf("\n");

	return 0;
}


int MergeSort::Sort(Array &array) const
{
	std::vector<int> temp(array.Size());	
	sort(array, temp, 0, array.Size() -1);
	return 0;
}
