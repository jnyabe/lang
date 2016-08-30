#ifndef __MAP_H__
#define __MAP_H__

#include <map>
#include "container.h"

class Map: public Container
{
private:
	std::map<DataKey, DataValue> m_map;
	
public:
	Map() {}

	virtual ~Map() {}

	virtual int Size() const { return m_map.size();}
	
	virtual void Insert(const DataKey &key, const DataValue &val);
	virtual void Erase(const DataKey &key);
	virtual void Clear(void);
	virtual void Dump(void) const;
};

#endif /* __MAP_H__ */
