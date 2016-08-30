#ifndef __LIST_H__
#define __LIST_H__

#include <list>
#include "sequence_container.h"

class List: public SequenceContainer
{
private:
	std::list<DataType> m_list;

public:
	List() {}

	List(int num):m_list(num) {}

	virtual ~List() {}

	virtual int Size() const { return m_list.size();}
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

#endif /* __LIST_H__ */
