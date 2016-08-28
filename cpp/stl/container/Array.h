#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <array>
#include "container.h"

class Array: public Container
{
private:
	std::array<DataType, 10> m_array;
public:
	Array() {}

	Array(int n): m_array(){}

	virtual ~Array() {}

	virtual int Size() const { return m_array.size();}
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

#endif /* __ARRAY_H__ */
