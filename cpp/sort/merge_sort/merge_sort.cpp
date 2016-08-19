#include "merge_sort.h"


int MergeSort::sort(Array &array, std::vector<int> temp, int left, int right)
{
	
	int mid;
	if (right- left <= 1) return 0;
	
	mid = left + (right - left) / 2;
	sort(array, temp, left, mid);
	sort(array, temp, mid + 1, right);
	
	merge(array, temp, left, mid + 1, right);

	return 0;
}

int MergeSort::merge(Array &array, std::vector<int> temp, int left, int mid, int right)
{
	int left_end, num_elements, tmp_pos;

	left_end = mid - 1;
	tmp_pos = left;

	num_elements = right - left + 1;
	
	while ((left <= left_end) && (mid <= right))
	{
		if (array[left] <= array[mid])
		{
			temp[tmp_pos] = array[left];
			++tmp_pos;
			++left;
		} else {
			temp[tmp_pos] = array[mid];
			++tmp_pos;
			++mid;
		}
	}
	
	while (left <= left_end)
	{
		temp[tmp_pos] = array[left];
		left++;
		tmp_pos++;
	}

	while (mid <= right)
	{
		temp[tmp_pos] = array[mid];
		mid++;
		tmp_pos++;
	}

	for (int i=0; i <= num_elements; i++)
	{
		array[right] = temp[right];
		right = right - 1;
	}
	
	return 0;
}


int MergeSort::Sort(Array &array)
{
	std::vector<int> temp(array.Size());	
	sort(array, temp, 0, array.Size() -1);
	return 0;
}
