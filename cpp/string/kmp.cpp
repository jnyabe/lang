#include <vector>
#include "kmp.h"

void Kmp::createNextTable(const std::string& pattern, std::vector<int> &table)
{
	table.resize(pattern.size());
	
	// @make KMP next table
	
	table[0] = 0;
	
	for(int i=1, j=0 ; i < pattern.size(); i++)
	{
		if(pattern[i] != pattern[j])
		{
			table[i] = 0;
			j = 0;
		} else {
			table[i] = ++j;
		}
	}
	printf("\tKMP Next table:");
	for(int i=0; i < pattern.size(); i++)
	{
		printf("%c(%d),", pattern[i], table[i]);
	}
	printf("\n");
}

int Kmp::Search(const std::string& text, const std::string &pattern)
{
	int idx = -1;

	std::vector<int> nextTbl;

	createNextTable("ABC", nextTbl);
	createNextTable("ABCD", nextTbl);
	createNextTable("ABCDE", nextTbl);
	createNextTable(pattern, nextTbl);
	
	for(int m=0; m < text.size() - pattern.size();)
	{
		for(int i=0; i < pattern.size();)
		{
			if(IsEqual(text,m, pattern, i))
			{
				m++;
				i++;
				if(i == pattern.size())
				{
					return m - i;
				}
			} else if (i == 0) {
				m++;
			} else {
				i = nextTbl[i - 1];
			}
		}
	}	
	return idx;
}

int Kmp::Search(const std::string& text
				  , const std::vector<std::string> &pattern)
{
	int idx = -1;
	return idx;	
}
