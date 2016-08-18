#ifndef _SORT_BASE_H_
#define _SORT_BASE_H_

#include "array.h"

class SortBase
{
private:
	int m_seed;
	
public:
	SortBase():m_seed(10) {}
	virtual ~SortBase() {}
	virtual std::string GetName(void) const = 0;
	virtual int Sort(Array& array) = 0;
	virtual void Test(Array& array);
};

#endif /* _SORT_BASE_H_ */
