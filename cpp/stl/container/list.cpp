#include "List.h"

SequenceContainer::DataType List::Get(int n) const
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

SequenceContainer::DataType& List::operator[](int n)
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

SequenceContainer::DataType List::Front(void) const
{
	return m_list.front();
}

SequenceContainer::DataType List::Back(void) const
{
	return m_list.back();
}

void List::PushBack(SequenceContainer::DataType n)
{
	m_list.push_back(n);
}
void List::PushFront(SequenceContainer::DataType n)
{
	m_list.push_front(n);
}

void List::Insert(int idx, SequenceContainer::DataType n)
{
	auto itr = m_list.begin();
	for(int i=0; i < idx && itr != m_list.end(); i++)
	{
		++itr;
	}
	m_list.insert(itr, n);
}


void List::PopBack(void)
{
	m_list.pop_back();
}

void List::PopFront(void)
{
	m_list.pop_front();
}


void List::Delete(int idx)
{
	auto itr = m_list.begin();
	for(int i=0; i < idx && itr != m_list.end() ; i++)
	{
		++itr;
	}
	if(itr != m_list.end())
	{
		m_list.erase(itr);
	}
}


void List::Dump(void) const
{
	printf("List[%lu]={", m_list.size());
	for(const auto& e: m_list)
	{
		printf("%d,", e);
	}
	printf("}\n");
}
