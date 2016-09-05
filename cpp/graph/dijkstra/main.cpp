#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int G[6][6] =
	{
		//  1, 2, 3, 4, 5, 6
		0, 5, 4, 2, 0, 0,   // 1 to ?
		5, 0, 2, 0, 0, 6,   // 2 to ?
		4, 2, 0, 3, 2, 0,   // 3 to ?
		2, 0, 3, 0, 6, 0,   // 4 to ?
		0, 0, 2, 6, 0, 4,   // 5 to ?
		0, 6, 0, 0, 4, 0,   // 6 to ?
	};

struct Node {
	vector<int> edges_to;
	vector<int> edges_cost;
	int from;   // どこから来たのか
	bool done;  // 確定ずみ 
	int cost;   // コスト
};


Node nodes[6];

int start = 0; // start node
int goal  = 5; // goal node

void init()
{
	for(int i=0; i  < 6; i++)
	{
		for(int j=0; j < 6; j++)
		{
			if(G[i][j]>0)
			{
				nodes[i].edges_to.push_back(j);
				nodes[i].edges_cost.push_back(G[i][j]);
			}
		}
	}
	
	for(auto &n: nodes)
	{
		n.done = false;
		n.cost = -1;
		n.from = -1;
	}
	nodes[start].cost = 0;
}

void dump(void)
{
	printf("--------------------------------------------\n");
	for(int i=0; i < 6; i++)
	{
		printf("Node[%d]: done=%-5s: cost: %d\n"
			   , i, nodes[i].done?"true":"false", nodes[i].cost);
		for(int j=0; j < nodes[i].edges_to.size(); j++)
		{
			printf("\t->%d(%d)\n", nodes[i].edges_to[j], nodes[i].edges_cost[j]);
		}
	}
	printf("--------------------------------------------\n");	
}

void out_dotfile(const char* dotfile)
{
	FILE* fp = fopen(dotfile, "w");
	
	int offset = 0;
	fprintf(fp, "graph g {\n");
	for(int i=0; i < 6; i++)
	{
		
		for(int j=0; j < nodes[i].edges_to.size(); j++)
		{
			if(i > nodes[i].edges_to[j])
			{
				continue; // reduce duplication
			}
			fprintf(fp, "%d--%d [label=%d]\n",
				   i + offset,
				   nodes[i].edges_to[j] + offset,
				   nodes[i].edges_cost[j]);
		}
	};
	
	fprintf(fp, "}\n");
	fclose(fp);
}

int main(int argc, const char* argv[])
{
	init();
	// out_dotfile("graph.dot");

	priority_queue<int, vector<int>, function<bool(int, int)>>
		pq([&](int a, int b){ return (nodes[a].cost > nodes[b].cost); });

	pq.push(0);
	
	while(!pq.empty())
	{
		int doneNode = pq.top(); 		// find done node
		pq.pop();
		printf("doneNode:%d\n", doneNode);
		nodes[doneNode].done = true; // 確定ノードとする

		for(int i=0; i < nodes[doneNode].edges_to.size(); i++)
		{
			int to = nodes[doneNode].edges_to[i];
			int cost = nodes[doneNode].cost + nodes[doneNode].edges_cost[i];
			if(nodes[to].cost < 0 || cost < nodes[to].cost)
			{
				nodes[to].cost = cost;
				nodes[to].from = doneNode;

				// TBD:
				// if pq does not have 'to', ....
				pq.push(to);
			}
		}
	}

	std::cout << "Min cost: " << nodes[goal].cost << std::endl;

	int from = goal;
	while(from>=0)
	{
		std::cout << from << "<-";
		from = nodes[from].from;
	}
	std::cout << std::endl;
	return 0;
}
