#ifndef _SHELL_SORT_H_
#define _SHELL_SORT_H_

#include "sort_base.h"

class ShellSort: public SortBase
{
private:

public:
	ShellSort()
	{
		m_info[SORT_INFO_TYPE_NAME] = "Shell Sort";
		m_info[SORT_INFO_TYPE_BEST_TIME_COMPLEXITTY] = "O(?))";
		m_info[SORT_INFO_TYPE_WORST_TIME_COMPLEXITTY] = "O(?)";
		m_info[SORT_INFO_TYPE_AVERAGE_TIME_COMPLEXITTY] = "O(?)";
	}
	virtual ~ShellSort() {}
	virtual int Sort(Array &array) const;
};

#endif /* _SHELL_SORT_H_ */