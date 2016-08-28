#include <iostream>
#include "ss_base.h"

bool SSBase::IsEqual(const std::string& text, int m,
					 const std::string &pattern, int i)
{
	if(m_debug)
	{
		printf("\tCompare text:%c(%d), pattern:%c(%d)\n",
			   text[m], m, pattern[i], i);
	}
	m_num_comparison++;
	return (text[m] == pattern[i]);
}

int SSBase::Run(const char* text, const char* pattern)
{
	int ret = 0;


	m_num_comparison = 0;
	ret = Search(text, pattern);
	
	printf("[%-25s] %s '%s'(%d): # of comp: %d\n",
		   m_info[SS_INFO_TYPE_NAME].c_str(),
		   (ret >= 0)? "Found":"Not Found", pattern, ret, m_num_comparison);

	return ret;
}

void SSBase::Help(void) const
{
	const char* label[] =
		{
			"[%s]\n",
			"\tBest Time Complexity    : %s\n",
			"\tWorst Time Complexity   : %s\n",
			"\tAverage Time Complexity : %s\n",
			"\tWorst Space Complexity  : %s\n",
		};
	
	for(int i=0; i < SS_INFO_TYPE_MAX; i++)
	{
		printf(label[i], m_info[i].c_str());
	}
	
	return;
}
