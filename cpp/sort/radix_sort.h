#ifndef _RADIX_SORT_H_
#define _RADIX_SORT_H_

#include "sort_base.h"

class RadixSort: public SortBase
{
public:
	RadixSort()
	{
		m_info[SORT_INFO_TYPE_NAME] = "Radix Sort";
		m_info[SORT_INFO_TYPE_BEST_TIME_COMPLEXITTY] = "O(?)";
		m_info[SORT_INFO_TYPE_WORST_TIME_COMPLEXITTY] = "O(?)";
		m_info[SORT_INFO_TYPE_AVERAGE_TIME_COMPLEXITTY] = "O(?)";   		
	}
	virtual ~RadixSort() {}
	virtual int Sort(Array &array) const;
};

#endif /* _RADIX_SORT_H_ */
