#include "unordered_multimap.h"

void UnorderedMultiMap::Insert(const DataKey &key, const DataValue &val)
{
	m_map[key] = val;
}

void UnorderedMultiMap::Erase(const DataKey &key)
{
	auto itr = m_map.find(key);
	if(itr != m_map.end())
		m_map.erase(itr);
}

void UnorderedMultiMap::Clear(void)
{
}

void UnorderedMultiMap::Dump(void)
{
	printf("UnorderedMultiMap[%lu]={", m_map.size());
	for(auto itr = m_map.begin(); itr != m_map.end();itr++)
	{
        printf("%d:%s,"
			   ,itr->first
			   ,itr->second.c_str());
    }
	printf("}\n");
}



