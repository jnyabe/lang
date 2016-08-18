#include "sort.h"

void Sort::Test(Array& array)
{
	array.Shuffle(m_seed);
	printf("[%s]\n", GetName().c_str());
	array.Print("[before]");
	Exec(array);
	array.Print("[after]");
}
