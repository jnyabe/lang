#ifndef _BRUTE_FORCE_H_
#define _BRUTE_FORCE_H_

#include "ss_base.h"

class BruteForceSearch: public SSBase
{
	
public:
	/// @Brief Default constructor
	BruteForceSearch()
	{
		m_info[SS_INFO_TYPE_NAME] = "Brute Force";
		m_info[SS_INFO_TYPE_BEST_TIME_COMPLEXITTY] = "O(?)";
		m_info[SS_INFO_TYPE_WORST_TIME_COMPLEXITTY] = "O(?)";
		m_info[SS_INFO_TYPE_AVERAGE_TIME_COMPLEXITTY] = "O(?)";
		m_info[SS_INFO_TYPE_WORST_SPACE_COMPLEXITTY] = "O(?)";                
	}


	/// @Brief Destructor
	virtual ~BruteForceSearch() {}
	
	virtual int Search(const char* text, const char* pattern) const;
	
};

#endif /* _BRUTE_FORCE_H_ */
