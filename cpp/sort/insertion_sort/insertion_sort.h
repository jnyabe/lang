#ifndef _INSERTION_SORT_H_
#define _INSERTION_SORT_H_

#include "sort.h"

class InsertionSort: public Sort
{
public:
	InsertionSort() {}
	virtual ~InsertionSort() {}
	virtual std::string GetName(void) const;
	virtual int Exec(Array& array);
};
 
#endif /* _INSERTION_SORT_H_ */
