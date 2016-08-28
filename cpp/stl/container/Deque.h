#ifndef __DEQUE_H__
#define __DEQUE_H__

#include <queue>
#include "container.h"

class Deque: public Container
{
private:
	std::deque<DataType> m_deq;
public:
	Deque() {}

	Deque(int n): m_deq(n){}

	virtual ~Deque() {}

	virtual int Size() const { return m_deq.size();}
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

#endif /* __DEQUE_H__ */
