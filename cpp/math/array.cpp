#include "array.h"

void print(const Array &a)
{
	printf("[");
	for(const auto& e: a)
	{
		printf("%d,", e);
	}
	printf("]\n");
}

void print(const ArrayList &list)
{
	printf("[\n");
	for(const auto& a: list)
	{
		printf("\t[");
		for(const auto& e: a)
		{
			printf("%d,", e);
		}		
		printf("],\n");
	}
	printf("]\n");
}

	
