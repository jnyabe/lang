#ifndef _BUBBLE_SORT_H_
#define _BUBBLE_SORT_H_

#include "sort_base.h"

class BubbleSort: public SortBase
{
public:
	BubbleSort()
	{
		m_info[SORT_INFO_TYPE_NAME] = "Bubble Sort";
		m_info[SORT_INFO_TYPE_BEST_TIME_COMPLEXITTY] = "O(N^2)";
		m_info[SORT_INFO_TYPE_WORST_TIME_COMPLEXITTY] = "O(N^2)";
		m_info[SORT_INFO_TYPE_AVERAGE_TIME_COMPLEXITTY] = "O(N^2)";
	}
	
	virtual ~BubbleSort() {}
	virtual int Sort(Array &array) const;
};

#endif /* _BUBBLE_SORT_H_ */
