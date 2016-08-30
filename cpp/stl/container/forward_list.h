#ifndef __FORWARD_LIST_H__
#define __FORWARD_LIST_H__

#include <forward_list>
#include "sequence_container.h"

class ForwardList: public SequenceContainer
{
private:
	std::forward_list<DataType> m_list;

public:
	ForwardList() {}

	ForwardList(int num):m_list(num) {}

	virtual ~ForwardList() {}

	virtual int Size() const { return std::distance(m_list.begin(), m_list.end());}
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

#endif /* __FORWARD_LIST_H__ */
