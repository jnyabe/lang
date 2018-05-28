#ifndef _BM_H_
#define _BM_H_

#include <vector>
#include "ss_base.h"

/// @Brief Boyer Moore
class Bm: public SSBase
{
	void createSkipTable(const std::string& pattern, std::vector<int> &table);
public:
	/// @Brief Default constructor
	Bm()
	{
		m_info[SS_INFO_TYPE_NAME] = "BM";
		m_info[SS_INFO_TYPE_BEST_TIME_COMPLEXITTY] = "O(?)";
		m_info[SS_INFO_TYPE_WORST_TIME_COMPLEXITTY] = "O(?)";
		m_info[SS_INFO_TYPE_AVERAGE_TIME_COMPLEXITTY] = "O(?)";
		m_info[SS_INFO_TYPE_WORST_SPACE_COMPLEXITTY] = "O(?)";                
	}

	/// @Brief Destructor
	virtual ~Bm() {}

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

#endif /* _BM_H_ */
