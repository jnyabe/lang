#include "../common/array.h"
#include <iostream>

static void quick_sort(Array &array, int left, int right)
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
	left = l_held;
	right = r_hold;
	if(left < pivot)
		quick_sort(array, left, pivot-1);
	if(right < pivot)
		quick_sort(array, pivot+1, right);
		
}

int main(int argc, const char* argv[])
{
	for(int i=1; i < argc; i++)
	{
		try {
			Array array(std::stoi(argv[i]));
			array.Shuffle(10);
			array.Print("[before quick_sort]");
			quick_sort(array, 0, array.Size() - 1);
			array.Print("[after quick_sort]");
		} catch(std::invalid_argument e) {
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}
