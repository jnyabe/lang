#include "unordered_map.h"

void UnorderedMap::Insert(const DataKey &key, const DataValue &val)
{
	m_map[key] = val;
}

void UnorderedMap::Erase(const DataKey &key)
{
	auto itr = m_map.find(key);
	if(itr != m_map.end())
		m_map.erase(itr);
}

void UnorderedMap::Clear(void)
{
}

void UnorderedMap::Dump(void)
{
	printf("UnorderedMap[%lu]={", m_map.size());
	for(auto itr = m_map.begin(); itr != m_map.end();itr++)
	{
        printf("%d:%s,"
			   ,itr->first
			   ,itr->second.c_str());
    }
	printf("}\n");
}



