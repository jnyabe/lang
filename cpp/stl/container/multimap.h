#ifndef __MULTIMAP_H__
#define __MULTIMAP_H__

#include <map>
#include "container.h"

class MultiMap: public Container
{
private:
	std::multimap<DataKey, DataValue> m_map;
	
public:
	MultiMap() {}

	virtual ~MultiMap() {}

	virtual int Size() const { return m_map.size();}
	
	virtual void Insert(const DataKey &key, const DataValue &val);
	virtual void Erase(const DataKey &key);
	virtual void Clear(void);
	virtual void Dump(void);
};

#endif /* __MULTIMAP_H__ */
