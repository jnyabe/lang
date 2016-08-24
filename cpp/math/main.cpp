#include <stdio.h>
#include <numeric>
#include "array.h"
#include "math.h"

	
int main(int argc, const char* argv[])
{
	int ret = 0;
	Array a(10);
	ArrayList p, c;
	int r = 3;

	std::iota(a.begin(), a.end(), 0);
	print(a);
	
	p = Math::Permutation(a, r);
	if(ret < 0)
	{
		printf("Permutation: %#x\n", ret);
	}
	print(p);
	printf("# of perm:%d\n", Math::NumOfPermutation(a.size(), r));

	c = Math::Combination(a, r);
	if(ret < 0)
	{
		printf("Combination: %#x\n", ret);
	}
	print(c);
	printf("# of comb:%d\n", Math::NumOfCombination(a.size(), r));
	return ret;
}
