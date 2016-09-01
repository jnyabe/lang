#include "heap_sort.h"

int HeapSort::upheap(Array &array, int n) const
{
	while(n > 0)
	{
		int m = parent(n);
		if(array[m] < array[n])
		{
			array.Swap(m, n);
		} else {
			break;
		}
		n = m;
	}
	return 0;
}

int HeapSort::downheap(Array &array, int n) const
{
	int ret = 0;
	int m = 0;
	int tmp = 0;

	for(;;)
	{
		int lc = leftChild(m);
		int rc = rightChild(m);
		
		if(lc >= n)
		{
			break;
		}
		
		if(array[lc] > array[tmp])
		{
			tmp = lc;
		}
		
		if((rc < n) && (array[rc] > array[tmp]))
		{
			tmp = rc;
		}

		if(tmp == m)
		{
			break;
		}
		array.Swap(tmp, m);
		m = tmp;
	}
	return ret;
}

int HeapSort::siftUp(Array &array, int n) const
{
	int ret =0;
	int i = n;
	// 0 -> 1,2 -> 1->3,4  2->5,6
	// a -> 2*a + 1, 2*a + 2
	for(;;)
	{
		if(i==0) break; // reach root
		int p = (i - 1) / 2; // parent
		
		if(array[p] <= array[i]) break;
		array.Swap(p, i);
		i = p;
	}
	return ret;
}

int HeapSort::siftDown(Array &array, int n) const
{
	int ret = 0;
	int i = 0; // root

	for(;;)
	{
		int c = 2 * i + 1;
		if(c > n)
		{
			break;  // no child
		}
		
		if(c + 1 <= n)
		{
			// two chilren
			if(array[c + 1] < array[c])
			{
				c++;
			}
		}

		if(array[c] <= array[i]) break;
		array.Swap(c, i);
		i = c;
	}
	
	return ret;
}

int HeapSort::siftDown(Array &array, int root, int bottom) const
{
	int done, maxChild, temp;
	done = 0;
	
	// bottomは変らない..
	// rootが、子の方へ移動
	while((root * 2 <= bottom) && (!done))
	{
		// root * 2     : left child
		// root * 2 + 1 : right child
		
		if(root * 2 == bottom) {
			// (bottomが、rootの左側の子の場合)
			maxChild = root * 2;
		} else if (array[root * 2] > array[root * 2 + 1]) {
			maxChild = root * 2;
		} else {
			maxChild = root * 2 + 1;
		}
		// maxChildは、より大きな値を持つ方の子

		if(array[root] < array[maxChild]) {
			// printf("Swap %d and %d\n", array[root], array[maxChild]);
			array.Swap(root, maxChild);
			root = maxChild;
		} else {
			done = 1;
		}
	}
	return 0;
}

int HeapSort::sort0(Array &array) const
{
	// wikipedia
	int i=0;

	// arrayの先頭から順に、ヒープを成長させる
	//  0  1  2  3 | 4  5 ..
	// [ ][ ][ ][ ] [ ][ ]
	// ヒープ       | 未処理の入力
	// 配列全部がヒープにいれかわるまで繰りかえす
	
	while(++i < array.Size())
	{
		// array[i]に、ヒープに新しくデータがあるものとして...
		// 先頭からarray[i]までがヒープになるよう再構成する
		array.Print("Ins " + std::to_string(array[i]));
		upheap(array, i);
	}

	// arrayの先頭か順に、ヒープから取り出して並べる
	//  0  1  2 | 3   4  5 ..
	// [ ][ ][ ] [ ] [ ][ ]
	//  ヒープ   | ソート済みの配列
	//         <===

	// ヒープが全部配列に入れかわるまで繰りかえす
	while(--i> 0)
	{
		/// ヒープの先頭要素を、配列に移動すると同時に、ヒープの最後の
		/// 要素を、ヒープの先頭に移動する
		array.Swap(0,i);

		/// array[0]に、ヒープの最後から移動されたデータがあるものとし
		/// てaray[i-1]までがヒープになるように再構成
		downheap(array, i);
	}
	return 0;
}

int HeapSort::sort1(Array &array) const
{
	// create heap with bottom-up
	for(int i = (array.Size() - 1) / 2 ; i >=0; i--)
	{
		siftDown(array, i, array.Size());
		// array.Print("[sift_down]");
	}
	
	// array.Print("[afer sift_down]");

	// heap sort
	for(int i= array.Size() - 1; i> 0; i--)
	{
		array.Swap(0, i);
		siftDown(array, 0, i-1);
		// array.Print("[heap]");		
	}
	return 0;
}

int HeapSort::Sort(Array &array) const
{
	return sort0(array);
}
