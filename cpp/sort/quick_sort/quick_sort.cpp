#include "quick_sort.h"


int QuickSort::sort(Array &array, int left, int right)
{
	// Best Time Complexity: O(N)
	// Average Time Complexity: O(N^2)
	// Worst Time Complexity: O(N^2)
	int pivot, l_hold, r_hold;
	l_hold = left;
	r_hold = right;
	pivot = array[left];

	while(left < right)
	{
		// pivotより大きい値はスキップ
		while((array[right] >= pivot) && (left < right))
			right--;
		
		// 小さい値がでてきた場合、左側へ移動
		if(left != right)
		{
			array[left] = array[right];
			left++;
		}

		
		while((array[left] <= pivot) && (left < right))
			left++;
		if(left != right)
		{
			array[right] = array[left];
			right--;
		}

	}
	
	array[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;
	if(left < pivot)
		sort(array, left, pivot-1);
	if(right < pivot)
		sort(array, pivot+1, right);
		
}

int QuickSort::Sort(Array &array)
{
	return sort(array, 0, array.Size() -1);
}
