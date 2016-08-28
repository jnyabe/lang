
#include "vector.h"


Container::DataType Vector::Get(int n) const
{
	return m_vec[n];
}

Container::DataType& Vector::operator[](int n)
{
	return m_vec[n];
}

Container::DataType Vector::Front(void) const
{
	return m_vec.front();
}

Container::DataType Vector::Back(void) const
{
	return m_vec.back();
}

void Vector::PushBack(Container::DataType n)
{
	m_vec.push_back(n);
}
void Vector::PushFront(Container::DataType n)
{
	m_vec.insert(m_vec.begin(), n);
}

void Vector::Insert(int idx, Container::DataType n)
{
	m_vec.insert(m_vec.begin() + idx, n);
}


void Vector::PopBack(void)
{
	m_vec.pop_back();
}

void Vector::PopFront(void)
{
	m_vec.erase(m_vec.begin());
}


void Vector::Delete(int idx)
{
	m_vec.erase(m_vec.begin() + idx);
}


void Vector::Dump(void) const
{
	printf("Vector[%lu]={", m_vec.size());
	for(unsigned long i=0; i < m_vec.size(); i++)
	{
		printf("%d,", m_vec[i]);
	}
	printf("}\n");
}
