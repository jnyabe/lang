#include "adj_list.h"
#include "adj_matrix.h"
#include "dijkstra.h"
#include "a-star.h"

#include <iostream>

int main(int argc, const char* argv[])
{
	int ret = 0;
	// AdjList graph;
	AdjMatrix graph;
	Vertex s(1);
	Vertex g(6);
	Path path;
	Dijkstar dijkstar;
	graph.CreateSample();

	// graph.Dump();
	
	ret = dijkstar.GetShortestPath(graph, s, g, path);

	for(const auto& v: path)
	{
		std::cout << v.m_id << "->";
	}
	return ret;
}
