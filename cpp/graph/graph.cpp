#include "graph.h"
#include <stdio.h>

void Graph::CreateSample(void)
{
#if 0
	int G[6][6] =
		{
 		 //  1, 2, 3, 4, 5, 6
			0, 1, 1, 0, 0, 1,   // 1 to ?
			1, 0, 1, 1, 0, 0,   // 2 to ?
			1, 1, 0, 1, 0, 1,   // 3 to ?
			0, 1, 1, 0, 1, 0,   // 4 to ?
			0, 0, 0, 1, 0, 1,   // 5 to ?
			1, 0, 1, 0, 1, 0,   // 6 to ?
		};
#else
	// http://qiita.com/edo_m18/items/0588d290a19f2afc0a84
	int G[6][6] =
		{
 		 //  1, 2, 3, 4, 5, 6
			0, 5, 4, 2, 0, 0,   // 1 to ?
			5, 0, 2, 1, 0, 6,   // 2 to ?
			4, 2, 0, 3, 2, 0,   // 3 to ?
			2, 0, 3, 0, 6, 0,   // 4 to ?
			0, 0, 2, 6, 0, 4,   // 5 to ?
			0, 6, 0, 0, 4, 0,   // 6 to ?
		};
#endif
	for(int i=0; i < 6; i++)
	{
		// AddVertex(i);
		for(int j=0; j< 6; j++)
		{
			if (G[i][j])
			{
				//				printf("add %d->%d\n", i+1, j+1);
				AddEdge(i+1, j+1, G[i][j]);
			}
		}
	}
}
