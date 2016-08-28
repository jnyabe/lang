#include "array.h"
#include <iostream>
#include <algorithm>
#include <random>


Array::Array()
	: m_array(10)
{
	std::iota(m_array.begin(), m_array.end(), 0);
}

Array::Array(int size)
	: m_array(size)
{
	std::iota(m_array.begin(), m_array.end(), 0);
}

Array::Array(const Array& array)
	: m_array(array.m_array.size())
{
	std::copy(array.m_array.begin(), array.m_array.end(), back_inserter(this->m_array));
}

Array::~Array()
{
	
}
void Array::Shuffle(void)
{
	std::random_device rnd;
	std::mt19937 mt(rnd());
	std::shuffle(m_array.begin(), m_array.end(), mt);
}

void Array::Shuffle(int seed)
{
	std::mt19937 mt(seed);
	std::shuffle(m_array.begin(), m_array.end(), mt);
}

void Array::Swap(int left, int right)
{
	int tmp;
	tmp = m_array[left];
	m_array[left] = m_array[right];
	m_array[right] = tmp;
}

void Array::Print(std::string label) const
{
	std::cout << label;
	std::cout << "(" << m_array.size() << ")" << ":";
	std::copy(m_array.begin(), m_array.end(),
			  std::ostream_iterator<int>(std::cout, ","));
	std::cout << std::endl; 	
}

Array& Array::operator=(const Array& array)
{
	this->m_array.clear();
	std::copy(array.m_array.begin(), array.m_array.end(), back_inserter(this->m_array));
	return *this;
}
