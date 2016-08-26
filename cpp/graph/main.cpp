#include "adj_list.h"
#include "adj_matrix.h"
#include "dijkstra.h"
#include "a-star.h"



int main(int argc, const char* argv[])
{

	// AdjList graph;
	AdjMatrix graph;	
	graph.CreateSample();
	graph.Dump();
	graph.Clear();
	graph.Dump();

	return 0;
}
