#include "List.h"

std::list<Container::DataType>::iterator& List::getNth(int n)
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
	return itr;
}
Container::DataType List::Get(int n) const
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

Container::DataType& List::operator[](int n)
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

Container::DataType List::Front(void) const
{
	return m_list.front();
}

Container::DataType List::Back(void) const
{
	return m_list.back();
}

void List::PushBack(Container::DataType n)
{
	m_list.push_back(n);
}
void List::PushFront(Container::DataType n)
{
	m_list.push_front(n);
}

void List::Insert(int idx, Container::DataType n)
{
	m_list.insert(m_list.begin() + idx, n);
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
	m_list.erase(m_list.begin() + idx);
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
