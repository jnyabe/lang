#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_

#include "sort_base.h"

class MergeSort: public SortBase
{
private:
	int sort(Array &array, std::vector<int> temp, int left, int right) const;
	int merge(Array &array, std::vector<int> temp, int left, int mid, int right) const;
public:
	MergeSort()
	{
		m_info[SORT_INFO_TYPE_NAME] = "Merge Sort";
		m_info[SORT_INFO_TYPE_BEST_TIME_COMPLEXITTY] = "O(N Log(N))";
		m_info[SORT_INFO_TYPE_WORST_TIME_COMPLEXITTY] = "O(N Log(N))";
		m_info[SORT_INFO_TYPE_AVERAGE_TIME_COMPLEXITTY] = "O(N Log(N))";
	}
	virtual ~MergeSort() {}

	virtual int Sort(Array &array) const;
};

#endif /* _MERGE_SORT_H_ */
