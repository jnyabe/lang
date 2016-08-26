#ifndef _KMP_H_
#define _KMP_H_

#include "ss_base.h"

/// @brief Knuth–Morris–Pratt algorithm
class Kmp: public SSBase
{
	
public:
	/// @Brief Default constructor
	Kmp()
	{
		m_info[SS_INFO_TYPE_NAME] = "KMP";
		m_info[SS_INFO_TYPE_BEST_TIME_COMPLEXITTY] = "O(?)";
		m_info[SS_INFO_TYPE_WORST_TIME_COMPLEXITTY] = "O(?)";
		m_info[SS_INFO_TYPE_AVERAGE_TIME_COMPLEXITTY] = "O(?)";
		m_info[SS_INFO_TYPE_WORST_SPACE_COMPLEXITTY] = "O(?)";                
	}

	/// @Brief Destructor
	virtual ~Kmp() {}

	virtual int Search(const char* text, const char* pattern) const;
};

#endif /* _KMP_H_ */
