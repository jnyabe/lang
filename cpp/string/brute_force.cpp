#include "brute_force.h"

int BruteForceSearch::Search(const char* text, const char* pattern) const
{
	int idx = -1;
	int tlen = strlen(text);
	int plen = strlen(pattern);

	for(int i=0; i < tlen - plen; i++)
	{
		bool match = true;
		for(int j=0; j < plen; j++)
		{
			if(text[i+j] != pattern[j])
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
