#ifndef _SELECTION_SORT_H_
#define _SELECTION_SORT_H_

#include "sort_base.h"

class SelectionSort: public SortBase
{
private:

public:
	SelectionSort()
	{
		m_info[SORT_INFO_TYPE_NAME] = "Selection Sort";
		m_info[SORT_INFO_TYPE_BEST_TIME_COMPLEXITTY] = "O(?))";
		m_info[SORT_INFO_TYPE_WORST_TIME_COMPLEXITTY] = "O(?)";
		m_info[SORT_INFO_TYPE_AVERAGE_TIME_COMPLEXITTY] = "O(?)";		
	}
	virtual ~SelectionSort() {}
	virtual int Sort(Array &array) const;
};

#endif /* _SELECTION_SORT_H_ */
