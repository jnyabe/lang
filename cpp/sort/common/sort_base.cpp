#include "sort_base.h"

void SortBase::Test(Array& array)
{
	array.Shuffle(m_seed);
	printf("[%s]\n", GetName().c_str());
	array.Print("[before]");
	Sort(array);
	array.Print("[after]");
}
