#ifndef __SET_H__
#define __SET_H__

#include <set>
#include "container.h"

class Set: public Container
{
private:
	std::set<DataKey> m_set;

public:
	Set() {}

	virtual ~Set() {}

	virtual int Size() const { return m_set.size();}


	virtual void Insert(const DataKey &key, const DataValue &value);

	// erase any poinrt
	virtual void Erase(const DataKey &key);

	virtual void Dump(void);
};

#endif /* __SET_H__ */
