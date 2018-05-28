#ifndef _RABIN_KARP_H_
#define _RABIN_KARP_H_

#include "ss_base.h"

/// @Brief Rabin Karp string search algorithm
class RabinKarp: public SSBase
{
	
public:
	/// @Brief Default constructor
	RabinKarp()
	{
		m_info[SS_INFO_TYPE_NAME] = "Rabin Karp";
		m_info[SS_INFO_TYPE_BEST_TIME_COMPLEXITTY] = "O(?)";
		m_info[SS_INFO_TYPE_WORST_TIME_COMPLEXITTY] = "O(?)";
		m_info[SS_INFO_TYPE_AVERAGE_TIME_COMPLEXITTY] = "O(?)";
		m_info[SS_INFO_TYPE_WORST_SPACE_COMPLEXITTY] = "O(?)";                
	}

	/// @Brief Destructor
	virtual ~RabinKarp() {}

	/// @brief Search 'pattern' string in 'text' string
	/// @param[in] text string to be searched from
	/// @param[in] pattern string to be searched
	/// @retval index of pattern (if found)
	/// @retval -1 (if not found)
	virtual int Search(const std::string& text, const std::string &pattern);

		/// @brief Search multiple 'pattern's string in 'text' string
	/// @param[in] text string to be searched from
	/// @param[in] patterns a list of string to be searched
	/// @retval index of pattern (if found)
	/// @retval -1 (if not found)
	virtual int Search(const std::string& text
					   , const std::vector<std::string> &pattern);
};

#endif /* _RABIN_KARP_H_ */
