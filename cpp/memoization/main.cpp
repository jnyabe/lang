#include <stdio.h>
#include <map>
#include <chrono>
#include <iostream>
using namespace std;

int fact(int n, map<int, int> *memo)
{
	if(memo)
	{
		auto it = memo->find(n);
		if(it != memo->end())
		{
			// look up memo
			return (*memo)[n];
		}
		if(n==0) {
			return 1;
		} else {
			int val = n * fact(n-1, memo);
			(*memo)[n] = val;
			return val;
		}		
	} else {
		if(n==0) {
			return 1;
		} else {
			int val = n * fact(n-1, memo);
			return val;
		}		
	}
}


int main(int argc, const char* argv[])
{
	std::map<int, int> memo;
	int num = 1000;
	int ret = 0;
	auto start = std::chrono::system_clock::now();
	for(int j=0; j < num; j++)
	{
		for(int i=0; i < 30; i++)
		{
			ret = fact(i, nullptr);
			// printf("%d!=%d\n", i, fact(i, nullptr));
		}
	}
	auto end = std::chrono::system_clock::now();

	auto dur = end - start;
	auto msec =
		std::chrono::duration_cast<std::chrono::microseconds>(dur).count();
	std::cout << "Simple: " << msec << " micro sec.\n";

	start = std::chrono::system_clock::now();
	for(int j=0; j < num; j++)
	{
		for(int i=0; i < 30; i++)
		{
			ret = fact(i, &memo);
			// printf("%d!=%d\n", i, fact(i, &memo));
		}
	}
	end = std::chrono::system_clock::now();

	dur = end - start;
	msec =
		std::chrono::duration_cast<std::chrono::microseconds>(dur).count();
	std::cout << "Memoization: " << msec << " micro sec.\n";
	
	return ret;
}
