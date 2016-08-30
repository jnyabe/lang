#ifndef __UNORDERED_MAP_H__
#define __UNORDERED_MAP_H__

#include <unordered_map>
#include "container.h"

class UnorderedMap: public Container
{
private:
	std::unordered_map<DataKey, DataValue> m_map;
	
public:
	UnorderedMap() {}

	virtual ~UnorderedMap() {}

	virtual int Size() const { return m_map.size();}
	
	virtual void Insert(const DataKey &key, const DataValue &val);
	virtual void Erase(const DataKey &key);
	virtual void Clear(void);
	virtual void Dump(void);
};

#endif /* __UNORDERED_MAP_H__ */
