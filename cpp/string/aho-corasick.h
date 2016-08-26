#ifndef _AHO_CORASICK_H_
#define _AHO_CORASICK_H_

#include "ss_base.h"

class AhoCorasick: public SSBase
{
	
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

	virtual int Search(const char* text, const char* pattern) const;
};

#endif /* _AHO_CORASICK_H_ */
