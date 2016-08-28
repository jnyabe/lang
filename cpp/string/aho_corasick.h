#ifndef _AHO_CORASICK_H_
#define _AHO_CORASICK_H_

#include <vector>
#include <string>

#include "ss_base.h"

class AhoCorasick: public SSBase
{
private:
	// @brief Pattern Match Automaton
	struct Node
	{
		Node* next[256];
		Node* failure;
		std::vector<int> matched;
		Node(): failure(nullptr)
		{
			memset(next, 0, sizeof(Node*) * sizeof(next));
		}
	};

	Node* buildPMA(const std::vector<std::string> &patterns);
	void* match(const std::vector<std::string> &patterns);	
	
public:
	/// @Brief Default constructor
	AhoCorasick()
	{
		m_info[SS_INFO_TYPE_NAME] = "Aho Corasick";
		m_info[SS_INFO_TYPE_BEST_TIME_COMPLEXITTY] = "O(?)";
		m_info[SS_INFO_TYPE_WORST_TIME_COMPLEXITTY] = "O(?)";
		m_info[SS_INFO_TYPE_AVERAGE_TIME_COMPLEXITTY] = "O(?)";
		m_info[SS_INFO_TYPE_WORST_SPACE_COMPLEXITTY] = "O(?)";                
	}

	/// @Brief Destructor
	virtual ~AhoCorasick() {}

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

#endif /* _AHO_CORASICK_H_ */
