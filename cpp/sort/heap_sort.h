#ifndef _HEAP_SORT_H_
#define _HEAP_SORT_H_

#include "sort_base.h"

class HeapSort: public SortBase
{
private:
	int siftDown(Array &array, int root, int bottom) const;
public:
	HeapSort()
	{
		
	}
	virtual ~HeapSort() {}
	virtual int Sort(Array &array) const;
};

#endif /* _HEAP_SORT_H_ */
