
#include "array.h"


SequenceContainer::DataType Array::Get(int n) const
{
	return m_array[n];
}

SequenceContainer::DataType& Array::operator[](int n)
{
	return m_array[n];
}

SequenceContainer::DataType Array::Front(void) const
{
	return m_array.front();
}

SequenceContainer::DataType Array::Back(void) const
{
	return m_array.back();
}

void Array::PushBack(SequenceContainer::DataType n)
{
	// m_array.push_back(n);
}
void Array::PushFront(SequenceContainer::DataType n)
{
	// m_array.insert(m_array.begin(), n);
}

void Array::Insert(int idx, SequenceContainer::DataType n)
{
	// m_array.insert(m_array.begin() + idx, n);
}


void Array::PopBack(void)
{
	// m_array.pop_back();
}

void Array::PopFront(void)
{
	// m_array.erase(m_array.begin());
}


void Array::Delete(int idx)
{

}


void Array::Dump(void) const
{
	printf("Array[%lu]={", m_array.size());
	for(unsigned long i=0; i < m_array.size(); i++)
	{
		printf("%d,", m_array[i]);
	}
	printf("}\n");
}
