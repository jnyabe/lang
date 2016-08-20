#include <assert.h>
#include "quick_sort.h"


int QuickSort::sort0(Array &array, int left, int right) const
{
	int pivot, l_hold, r_hold;
	l_hold = left;
	r_hold = right;
	pivot = array[left];

	printf("sort(%d-%d)\n", left, right);
	// 0. |p|.................|.|
	//     l                   r
	// 1. |p|...........|S|bbbbb|
	//     l             r  <-    right--
	// 3. |S|...........|S|bbbbb|
	//       l           r
	// 4. |S|ssss|B|....|S|bbbbb|
	//     ->     l      r
	// 5. |S|ssss|B|....|B|bbbbb|
	//            l ...r
	
	while(left < right)
	{
		while((array[right] >= pivot) && (left < right))
			right--;
		
		if(left != right)
		{
			array[left++] = array[right];
		}

		while((array[left] <= pivot) && (left < right))
			left++;
		
		if(left != right)
		{
			array[right--] = array[left];
		}
	}

	assert(left==right);
	
	array[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;
	
	if(left < pivot)
		sort0(array, left, pivot-1);
	if(pivot < right)
		sort0(array, pivot+1, right);
	
	return 0;
}


int QuickSort::sort1(Array &array, int left, int right) const
{
	if(left >= right)
	{
		// do nothing if less than 1 elements
		return 0;
	}
	
	/// @note Nico Lomuto method
	int m = left;
	printf("sort(%d-%d)\n", left, right);	
	for(int i= left + 1; i <= right; i++)
	{
		if(array[i] < array[left])
		{
			array.Swap(++m, i);
		}
	}
	array.Swap(left, m);
	
	sort1(array, left, m - 1);
	sort1(array, m + 1,right);
	return 0;
}

int QuickSort::sort2(Array &array, int left, int right) const
{
	if(left >= right)
	{
		// do nothing if less than 1 elements
		return 0;
	}
	
	/// @note Bob Sedgewick method 
	int m = right + 1;
	printf("sort(%d-%d)\n", left, right);
	
	for(int i= right; i >= left; i--)
	{
		if(array[i] >= array[left])
		{
			array.Swap(--m, i);
		}
	}
	
	sort2(array, left, m - 1);
	sort2(array, m + 1,right);
	return 0;
}

int QuickSort::sort3(Array &array, int left, int right) const
{
	if(left >= right)
	{
		// do nothing if less than 1 elements
		return 0;
	}

	int t = array[left];
	int i = left;
	int j = right + 1;
	
	for(;;)
	{
		do {
			i++;
		} while (i <= right && array[i] < t);
		do {
			j--;
		} while (array[j] > t);
		if(i>j)
		{
			break;
		}
		array.Swap(i,j);
	}

	array.Swap(left, j);
	sort3(array, left, j - 1);
	sort3(array, j + 1,right);
	
	return 0;
}

int QuickSort::Sort(Array &array) const
{
	int ret = 0;
	switch (m_type)
	{
	case AlgorithmType_0:
		ret = sort0(array, 0, array.Size() -1);			
		break;
	case AlgorithmType_Lomuto:
		ret = sort1(array, 0, array.Size() -1);	
		break;
	case AlgorithmType_Sedgewick:
		ret = sort2(array, 0, array.Size() -1);	
		break;
	case AlgorithmType_3:
		break;						
	default:
		break;
	}
	return 0;
}
