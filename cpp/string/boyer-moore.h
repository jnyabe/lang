#ifndef _BOYER_MOORE_H_
#define _BOYER_MOORE_H_

#include "ss_base.h"

class BoyerMoore: public SSBase
{
	
public:
	/// @Brief Default constructor
	BoyerMoore()
	{
		m_info[SS_INFO_TYPE_NAME] = "Boyer Moore";
		m_info[SS_INFO_TYPE_BEST_TIME_COMPLEXITTY] = "O(?)";
		m_info[SS_INFO_TYPE_WORST_TIME_COMPLEXITTY] = "O(?)";
		m_info[SS_INFO_TYPE_AVERAGE_TIME_COMPLEXITTY] = "O(?)";
		m_info[SS_INFO_TYPE_WORST_SPACE_COMPLEXITTY] = "O(?)";                
	}

	/// @Brief Destructor
	virtual ~BoyerMoore() {}

};

#endif /* _BOYER_MOORE_H_ */
