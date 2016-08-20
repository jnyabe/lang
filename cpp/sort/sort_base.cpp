#include <iostream>
#include "sort_base.h"


void SortBase::Test(Array& array) const
{
	array.Shuffle(m_seed);
	printf("Start '%s'\n", m_info[SORT_INFO_TYPE_NAME].c_str());	
	array.Print("[before]");
	Sort(array);
	printf("End\n");		
	array.Print("[after]");
	if(!IsSorted(array))
	{
		printf("[ERROR] Not Sorted!\n");
	}
#if 0
	for(int i=0; i < array.Size(); i++)
	{
		array[i] = array.Size();
	}
	array.Print("[before]");
	printf("Start '%s'\n", m_info[SORT_INFO_TYPE_NAME].c_str());	
	Sort(array);
	printf("End\n");		
	array.Print("[after]");
	if(!IsSorted(array))
	{
		printf("[ERROR] Not Sorted!\n");
	}
#endif
}

void SortBase::Help(void) const
{
	const char* label[] =
		{
			"Name: ",
			"Best Time Complexity",
			"Worst Time Complexity",
			"Average Time Complexity",
		};
	
	for(int i=0; i < SORT_INFO_TYPE_MAX; i++)
	{
		printf("%-25s: %s\n", label[i], m_info[i].c_str());
	}
}

int SortBase::Run(int argc, const char* argv[]) const
{
	if(argc <= 1)
	{
		Help();
		return 0;
	}

	try {
		Array array(std::stoi(argv[1]));
		Test(array);
	} catch(std::invalid_argument e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}

bool SortBase::IsSorted(const Array& array)
{
	bool isSorted = true;
	
	for(int i=1; i< array.Size(); i++)
	{
		if(array[i-1] > array[i])
		{
			isSorted =false;
			break;
		}
	}
	return isSorted;
}
