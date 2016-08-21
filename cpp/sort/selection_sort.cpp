#include "selection_sort.h"

int SelectionSort::Sort(Array &array) const
{
	/// @note バブルソートによく似たアルゴリズムですが、選択ソートは交
	/// 換対象のインデックスを保持しておいて、各ループでの交換回数を最
	/// 大1回としているので、選択ソートの方が高速です。
	
	for(int i=0; i < array.Size() - 1;i++)
	{
		int min = i;
		for(int j=i; j < array.Size();j++)
		{
			if(array[j] < array[min]) min = j;
		}
		array.Swap(i, min);
	}
	return 0;
}
