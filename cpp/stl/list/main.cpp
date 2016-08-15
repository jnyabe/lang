#include <stdio.h>
#include <list>

pint main(int argc, const char* argv[])
{
	std::list<int> intList;
	const int listSize = 10;
	for(int i=0; i < listSize; i++)
	{
		intList.push_back(i);
	}

	intList.sort([](int& a, int& b) { return a<b;} );
		
	for(const auto& i: intList)
	{
		printf("%d,", i);
	}
	
	return 0;
}
