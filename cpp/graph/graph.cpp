#include "graph.h"


void Graph::CreateSample(void)
{
	int adjecency[7][7] =
		{
 		 // 0, 1, 2, 3, 4, 5, 6
			0, 0, 0, 0, 0, 0, 0,   // 0 (dummy)
			0, 0, 1, 1, 0, 0, 1,   // 1 to ?
			0, 1, 0, 1, 1, 0, 0,   // 2 to ?
			0, 1, 1, 0, 1, 0, 1,   // 3 to ?
			0, 0, 1, 1, 0, 1, 0,   // 4 to ?
			0, 0, 0, 0, 1, 0, 1,   // 5 to ?
			0, 1, 0, 1, 0, 1, 0,   // 6 to ?
		};
	
	for(int i=1; i <= 6; i++)
	{
		AddVertex(i);
		for(int j=1; j<= 6; j++)
		{
			if (adjecency[i][j]) AddEdge(i, j);
		}
	}
}
