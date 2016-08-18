#ifndef _INSERTION_SORT_H_
#define _INSERTION_SORT_H_

#include "sort_base.h"

class InsertionSort: public SortBase
{
public:
	InsertionSort() {}
	virtual ~InsertionSort() {}
	virtual std::string GetName(void) const;
	virtual int Sort(Array& array);
};
 
#endif /* _INSERTION_SORT_H_ */
