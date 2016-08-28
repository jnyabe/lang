#include "brute_force.h"

int BruteForceSearch::Search(const std::string& text, const std::string &pattern)
{
	int idx = -1;
	
	for(int i=0; i < text.size() - pattern.size(); i++)
	{
		bool match = true;
		for(int j=0; j < pattern.size(); j++)
		{
			
			if(!IsEqual(text, i + j, pattern, j))
			{
				match = false;
				break;
			}
		}
		if(match)
		{
			idx = i;
			break;
		}
	}
			
	return idx;
}

int BruteForceSearch::Search(const std::string& text
							 , const std::vector<std::string> &pattern)
{
	int idx = -1;
	return idx;
}
