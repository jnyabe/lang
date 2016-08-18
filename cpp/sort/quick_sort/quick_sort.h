#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

#include "sort_base.h"

class QuickSort: public SortBase
{
private:
	int sort(Array &array, int left, int right);
public:
	QuickSort() {}
	virtual ~QuickSort() {}
	virtual std::string GetName(void) const { return "QuickSort";} 
	virtual int Sort(Array &array);
};

#endif /* _QUICK_SORT_H_ */
