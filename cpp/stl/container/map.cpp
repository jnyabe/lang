#include "map.h"

void Map::Insert(const DataKey &key, const DataValue &val)
{
	m_map[key] = val;
}

void Map::Erase(const DataKey &key)
{
	auto itr = m_map.find(key);
	if(itr != m_map.end())
		m_map.erase(itr);
}

void Map::Clear(void)
{
}

void Map::Dump(void)
{
	printf("Map[%lu]={", m_map.size());
	for(auto itr = m_map.begin(); itr != m_map.end();itr++)
	{
        printf("%d:%s,"
			   ,itr->first
			   ,itr->second.c_str());
    }
	printf("}\n");
}


