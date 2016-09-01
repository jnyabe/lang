#ifndef _HEAP_SORT_H_
#define _HEAP_SORT_H_

#include "sort_base.h"

class HeapSort: public SortBase
{
private:
	
	inline int leftChild(int i) const { return (i+1) * 2 - 1; }
	inline int rightChild(int i) const { return (i+1) * 2;}
	inline int parent(int i) const { return (i+1) / 2 - 1; }
	
	// from wiki
	int upheap(Array &array, int n) const;
	int downheap(Array &array, int n) const;
	
	int siftDown(Array &array, int root, int bottom) const;
	int siftDown(Array &array, int n) const;
	int siftUp(Array &array, int n) const;

	int sort0(Array &array) const;
	int sort1(Array &array) const;
public:
	HeapSort()
	{
		m_info[SORT_INFO_TYPE_NAME] = "Heap Sort";
		m_info[SORT_INFO_TYPE_BEST_TIME_COMPLEXITTY]    = "O(N Log(N))";
		m_info[SORT_INFO_TYPE_WORST_TIME_COMPLEXITTY]   = "O(N Log(N))";
		m_info[SORT_INFO_TYPE_AVERAGE_TIME_COMPLEXITTY] = "O(N Log(N))";
		m_info[SORT_INFO_TYPE_WORST_SPACE_COMPLEXITTY]  = "O(1)";
	}
	virtual ~HeapSort() {}
	virtual int Sort(Array &array) const;
};

#endif /* _HEAP_SORT_H_ */
