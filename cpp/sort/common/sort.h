#ifndef _SORT_H_
#define _SORT_H_

#include "array.h"

class Sort
{
private:
	int m_seed;
	
public:
	Sort():m_seed(10) {}
	virtual ~Sort() {}
	virtual std::string GetName(void) const = 0;
	virtual int Exec(Array& array) = 0;
	virtual void Test(Array& array);
};

#endif /* _SORT_UTIL_H_ */
