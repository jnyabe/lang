#include <stdio.h>
#include <string>

int main(int argc, const char* argv[])
{
	int m, n;
	
	if(argc < 3)
	{
		return -1;
	}
	m = std::stoi(argv[1]);
	n = std::stoi(argv[2]);
	printf("gcd(%d,%d):", m, n);
	int gcd = 0;
	if(m < n)
	{
		int tmp = m;
		m = n;
		n = tmp;
	}

	// Euclidean Algorithm
	while(n!=0)
	{
		int n_ = m % n;
		m = n;
		n = n_;
	}
	printf("%d\n", m);
	
	return 0;
}
