#include <vector>
#include <numeric>
#include <random>
#include "red_black_tree.h"

int main(int argc, const char* argv[])
{
	RedBlackTree tree;
	int size = 10;
	if(argc > 1)
	{
		size = atoi(argv[1]);
	}
	std::vector<int> vals(size);
	std::iota(vals.begin(), vals.end(),0);
	std::random_shuffle(vals.begin(), vals.end());
	for(const auto& v: vals)
	{
		tree.Insert(v);
	}
	
	tree.Dump();
	for(const auto& v: vals)
	{
		tree.Delete(v);
		tree.Dump();
	}
	return 0;
}
