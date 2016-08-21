#include <iostream>
#include "ss_base.h"

int SSBase::Run(int argc, const char* argv[]) const
{
	if(argc <= 1)
	{
		Help();
		return 0;
	}
	
	try {
		
		
	} catch(std::invalid_argument e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
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
