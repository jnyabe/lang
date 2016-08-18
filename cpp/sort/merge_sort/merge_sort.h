#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_

#include "sort_base.h"

class MergeSort: public SortBase
{
private:
	int MergeSort::sort(Array &array, int left, int right);
	
public:
	MergeSort() {}
	virtual ~MergeSort() {}
	virtual std::string GetName(void) const { return "MergeSort";} 
	virtual int Sort(Array &array);
};

#endif /* _MERGE_SORT_H_ */
