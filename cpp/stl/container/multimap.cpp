#include "multimap.h"

void MultiMap::Insert(const DataKey &key, const DataValue &val)
{
	m_map.insert(std::make_pair(key, val));
}

void MultiMap::Erase(const DataKey &key)
{
	auto itr = m_map.find(key);
	if(itr != m_map.end())
		m_map.erase(itr);
}

void MultiMap::Clear(void)
{
}

void MultiMap::Dump(void)
{
	printf("MultiMap[%lu]={", m_map.size());
	for(auto itr = m_map.begin(); itr != m_map.end();itr++)
	{
        printf("%d:%s,"
			   ,itr->first
			   ,itr->second.c_str());
    }
	printf("}\n");
}



