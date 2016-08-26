#include <iostream>
#include "ss_base.h"

int SSBase::Run(int argc, const char* argv[]) const
{
	int ret = 0;
	const char text[] = "ABC ABCDAB ABCDABCDABDE";
	const char pattern[] = "ABCDABD";
#if 0	
	if(argc <= 1)
	{
		Help();
		return 0;
	}
#endif	
	ret = Search(text, pattern);
	
	printf("[%-25s] %s '%s'(%d)\n",
		   m_info[SS_INFO_TYPE_NAME].c_str(),
		   (ret >= 0)? "Found":"Not Found", pattern, ret);

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
