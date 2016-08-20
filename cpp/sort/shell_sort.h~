#ifndef _HEAP_SORT_H_
#define _HEAP_SORT_H_

#include "sort_base.h"

class HeapSort: public SortBase
{
private:
	int siftDown(Array &array, int root, int bottom);
public:
	HeapSort() {}
	virtual ~HeapSort() {}
	virtual std::string GetName(void) const { return "HeapSort";} 
	virtual int Sort(Array &array);
};

#endif /* _HEAP_SORT_H_ */
