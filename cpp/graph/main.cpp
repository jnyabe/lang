#include "adj_list.h"
#include "dijkstra.h"
#include "a-star.h"



int main(int argc, const char* argv[])
{
	AdjList graph;
	graph.CreateSample();
	graph.Dump();
	return 0;
}
