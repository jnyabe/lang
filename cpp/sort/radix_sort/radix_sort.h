#ifndef _RADIX_SORT_H_
#define _RADIX_SORT_H_

#include "sort_base.h"

class RadixSort: public SortBase
{
public:
	RadixSort() {}
	virtual ~RadixSort() {}
	virtual std::string GetName(void) const { return "RadixSort";} 
	virtual int Sort(Array &array);
};

#endif /* _RADIX_SORT_H_ */
