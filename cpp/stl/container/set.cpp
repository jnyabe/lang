#include "set.h"


void Set::Insert(const DataKey &key, const DataValue &value)
{
	m_set.insert(key);
}

void Set::Erase(const DataKey &key)
{
	m_set.erase(key);
}

void Set::Dump(void)
{
	printf("Set[%lu]={", m_set.size());
	for(const auto &k: m_set)
	{
		printf("%d,", k);
	}
	printf("}\n");
}





