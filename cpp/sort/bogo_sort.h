#ifndef _BOGO_SORT_H_
#define _BOGO_SORT_H_

#include "sort_base.h"

class BogoSort: public SortBase
{
private:
	
public:
	BogoSort()
	{
		m_info[SORT_INFO_TYPE_NAME] = "Bogo Sort";
		m_info[SORT_INFO_TYPE_BEST_TIME_COMPLEXITTY] = "O(N))";
		m_info[SORT_INFO_TYPE_WORST_TIME_COMPLEXITTY] = "O(inf)";
		m_info[SORT_INFO_TYPE_AVERAGE_TIME_COMPLEXITTY] = "O(N * N !)";
		m_info[SORT_INFO_TYPE_WORST_SPACE_COMPLEXITTY] = "O(N)";
	}
	virtual ~BogoSort() {}
	virtual int Sort(Array &array) const;
};

#endif /* _BOGO_SORT_H_ */
