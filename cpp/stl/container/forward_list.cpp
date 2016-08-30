#include "forward_list.h"

SequenceContainer::DataType ForwardList::Get(int n) const
{
	int i=0;
	for(auto itr = m_list.begin(); itr != m_list.end(); ++itr)
	{
		if(i==n)
		{
			return *itr;
		}
		i++;
	}
	return 0;
}

SequenceContainer::DataType& ForwardList::operator[](int n)
{
	int i=0;
	auto itr = m_list.begin();
	for(; itr != m_list.end(); ++itr)
	{
		if(i==n)
		{
			break;
		}
		i++;
	}
	return *itr;
}

SequenceContainer::DataType ForwardList::Front(void) const
{
	return m_list.front();
}

SequenceContainer::DataType ForwardList::Back(void) const
{

	auto itr  = m_list.begin();
	auto prev = itr;
	while(itr != m_list.end())
	{
		prev = itr;
		itr++;
	}
	return *prev;
}

void ForwardList::PushBack(SequenceContainer::DataType n)
{
	auto itr  = m_list.begin();
	auto prev = itr;
	while(itr != m_list.end())
	{
		prev = itr;
		itr++;
	}
	m_list.insert_after(prev, n);
}
void ForwardList::PushFront(SequenceContainer::DataType n)
{
	m_list.push_front(n);
}

void ForwardList::Insert(int idx, SequenceContainer::DataType n)
{
	auto itr = m_list.begin();
	for(int i=0; i < idx && itr != m_list.end(); i++)
	{
		++itr;
	}
	m_list.insert_after(itr, n);
}


void ForwardList::PopBack(void)
{
	auto itr  = m_list.begin();
	auto prev = itr;
	auto pprev = itr;
	while(itr != m_list.end())
	{
		pprev = prev;
		prev = itr;
		itr++;
	}
	m_list.erase_after(pprev);	
}

void ForwardList::PopFront(void)
{
	m_list.pop_front();
}


void ForwardList::Delete(int idx)
{
	auto itr = m_list.begin();
	for(int i=0; i < idx - 1 && itr != m_list.end() ; i++)
	{
		++itr;
	}
	if(itr != m_list.end())
	{
		m_list.erase_after(itr);
	}
}


void ForwardList::Dump(void) const
{
	printf("ForwardList[%d]={", Size());
	for(const auto& e: m_list)
	{
		printf("%d,", e);
	}
	printf("}\n");
}
