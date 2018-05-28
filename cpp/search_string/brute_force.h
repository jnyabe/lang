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
		m_info[SS_INFO_TYPE_BEST_TIME_COMPLEXITTY]   = "O(mn)";
		m_info[SS_INFO_TYPE_WORST_TIME_COMPLEXITTY]   = "O(mn)";
		m_info[SS_INFO_TYPE_AVERAGE_TIME_COMPLEXITTY] = "O(mn)";
		m_info[SS_INFO_TYPE_WORST_SPACE_COMPLEXITTY]  = "O(?)";                
	}


	/// @Brief Destructor
	virtual ~BruteForceSearch() {}

	/// @brief Search 'pattern' string in 'text' string
	/// @param[in] text string to be searched from
	/// @param[in] pattern string to be searched
	/// @retval index of pattern (if found)
	/// @retval -1 (if not found)
	virtual int Search(const std::string& text, const std::string &pattern);

	virtual int Search(const std::string& text
					   , const std::vector<std::string> &pattern);
};

#endif /* _BRUTE_FORCE_H_ */
