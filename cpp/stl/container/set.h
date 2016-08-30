#ifndef __SET_H__
#define __SET_H__

#include <set>
#include "container.h"

class Set: public Container
{
private:
	std::set<DataType> m_set;

public:
	Set() {}

	virtual ~Set() {}

	virtual int Size() const { return m_set.size();}

	// random acccess
	virtual DataType Get(int n) const;

	virtual DataType& operator[](int n);
	
	// acccess head and tail
	virtual DataType Front(void) const;
	virtual DataType Back(void) const;

	// insert head and tail
	virtual void PushBack(DataType n);
	virtual void PushFront(DataType n);

	// insert any point
	virtual void Insert(int idx, DataType n);

	// delete head and tail
	virtual void PopBack(void);
	virtual void PopFront(void);

	// delete any poinrt
	virtual void Delete(int idx);

	virtual void Dump(void) const;
};

#endif /* __SET_H__ */
