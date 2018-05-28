#include "bm.h"

void Bm::createSkipTable(const std::string& pattern, std::vector<int> &table)
{
	table.resize(256, pattern.size()); // assume ASCII

	for(int i=0; i < pattern.size() - 1; i++)
	{
		table[pattern[i]] = pattern.size() - i -1;
	}
}

int Bm::Search(const std::string& text, const std::string &pattern)
{
	int idx = -1;
	int i, j;
	std::vector<int> table;

	createSkipTable(pattern, table);
	
	i = j = pattern.size() - 1;

	while((i < text.size()) && (j >= 0))
	{
		if(!IsEqual(text, i, pattern, j))
		{
			i += (table[text[i]] > pattern.size() - j)?
				table[text[i]]: pattern.size() - j;
			j = pattern.size() - 1;
		} else {
			j--;
			i--;
		}
	}
	
	if( j < 0)
	{
		idx = i+1;
	}
	return idx;
}

int Bm::Search(const std::string& text
				  , const std::vector<std::string> &pattern)
{
	int idx = -1;
	return idx;	
}
