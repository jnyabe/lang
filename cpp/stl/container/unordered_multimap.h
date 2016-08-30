#ifndef __UNORDERED_MULTI_MAP_H__
#define __UNORDERED_MULTI_MAP_H__

#include <unordered_map>
#include "container.h"

class UnorderedMultiMap: public Container
{
private:
	std::unordered_map<DataKey, DataValue> m_map;
	
public:
	UnorderedMultiMap() {}

	virtual ~UnorderedMultiMap() {}

	virtual int Size() const { return m_map.size();}
	
	virtual void Insert(const DataKey &key, const DataValue &val);
	virtual void Erase(const DataKey &key);
	virtual void Clear(void);
	virtual void Dump(void);
};

#endif /* __UNORDERED_MULTI_MAP_H__ */
