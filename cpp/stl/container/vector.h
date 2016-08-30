#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <vector>
#include "sequence_container.h"

class Vector: public SequenceContainer
{
private:
	std::vector<DataType> m_vec;
public:
	Vector() {}

	Vector(int n): m_vec(n){}

	virtual ~Vector() {}

	virtual int Size() const { return m_vec.size();}
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

#endif /* __VECTOR_H__ */
