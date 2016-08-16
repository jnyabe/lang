#include <vector>
#include <numeric>
#include <random>
#include "binary_tree.h"

int main(int argc, const char* argv[])
{
	BTree btree;
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
		btree.Insert(v);
	}
	BTree::NodeList dfs = btree.GetDFS();
	for(const auto& n: dfs) printf("%d,", n->m_value);
	printf("\n");
	BTree::NodeList bfs = btree.GetBFS();
	for(const auto& n: bfs) printf("%d,", n->m_value);
	printf("\n");
	btree.Dump();
	return 0;
}
