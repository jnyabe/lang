#ifndef _BUBBLE_SORT_H_
#define _BUBBLE_SORT_H_

#include "sort_base.h"

class BubbleSort: public SortBase
{
public:
	BubbleSort() {}
	virtual ~BubbleSort() {}
	virtual std::string GetName(void) const { return "BubbleSort";} 
	virtual int Sort(Array &array);
};

#endif /* _BUBBLE_SORT_H_ */
