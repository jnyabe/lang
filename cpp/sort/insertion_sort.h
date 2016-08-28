#ifndef _INSERTION_SORT_H_
#define _INSERTION_SORT_H_

#include "sort_base.h"

class InsertionSort: public SortBase
{
private:
	void sort1(Array& array) const;
	void sort2(Array& array) const;
	void sort3(Array& array) const;
public:
	InsertionSort()
	{
		m_info[SORT_INFO_TYPE_NAME] = "Insertion Sort";
		m_info[SORT_INFO_TYPE_BEST_TIME_COMPLEXITTY] = "O(N)";
		m_info[SORT_INFO_TYPE_WORST_TIME_COMPLEXITTY] = "O(N^2)";
		m_info[SORT_INFO_TYPE_AVERAGE_TIME_COMPLEXITTY] = "O(N^2)";
		m_info[SORT_INFO_TYPE_WORST_SPACE_COMPLEXITTY] = "O(1)";		
	}
	virtual ~InsertionSort() {}
	virtual int Sort(Array& array) const;
};
 
#endif /* _INSERTION_SORT_H_ */
