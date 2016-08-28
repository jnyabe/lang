
#include "Deque.h"


Container::DataType Deque::Get(int n) const
{
	return m_deq[n];
}

Container::DataType& Deque::operator[](int n)
{
	return m_deq[n];
}

Container::DataType Deque::Front(void) const
{
	return m_deq.front();
}

Container::DataType Deque::Back(void) const
{
	return m_deq.back();
}

void Deque::PushBack(Container::DataType n)
{
	m_deq.push_back(n);
}
void Deque::PushFront(Container::DataType n)
{
	m_deq.insert(m_deq.begin(), n);
}

void Deque::Insert(int idx, Container::DataType n)
{
	m_deq.insert(m_deq.begin() + idx, n);
}


void Deque::PopBack(void)
{
	m_deq.pop_back();
}

void Deque::PopFront(void)
{
	m_deq.erase(m_deq.begin());
}


void Deque::Delete(int idx)
{
	m_deq.erase(m_deq.begin() + idx);
}


void Deque::Dump(void) const
{
	printf("Deque[%lu]={", m_deq.size());
	for(unsigned long i=0; i < m_deq.size(); i++)
	{
		printf("%d,", m_deq[i]);
	}
	printf("}\n");
}
