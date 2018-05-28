#ifndef _KMP_H_
#define _KMP_H_

#include <vector>
#include "ss_base.h"

/// @brief Knuth–Morris–Pratt algorithm
class Kmp: public SSBase
{
private:
	
	static void createNextTable(const std::string& pattern,
								  std::vector<int>& table);
public:
	/// @Brief Default constructor
	Kmp()
	{
		m_info[SS_INFO_TYPE_NAME] = "KMP";
		m_info[SS_INFO_TYPE_BEST_TIME_COMPLEXITTY] = "O(n)";
		m_info[SS_INFO_TYPE_WORST_TIME_COMPLEXITTY] = "O(?)";
		m_info[SS_INFO_TYPE_AVERAGE_TIME_COMPLEXITTY] = "O(?)";
		m_info[SS_INFO_TYPE_WORST_SPACE_COMPLEXITTY] = "O(?)";                
	}

	/// @Brief Destructor
	virtual ~Kmp() {}

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

#endif /* _KMP_H_ */
