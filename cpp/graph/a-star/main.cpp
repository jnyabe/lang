#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
// #include <queue>
#include <list>

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
	int from; // どこから来たのか
	int f;	  // 推定値 f = g + h
	int g;    // The cost of the path from the start node
	int h;    // Heuristic that estimates the cost of the
              // cheapest path from n to the goal.
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
		n.g    = -1; // unknown
		n.h    = 0;
		n.f    = -1; // unknown
		n.from = -1;
	}
	nodes[start].g = 0;
}

void dump(void)
{
	printf("--------------------------------------------\n");
	for(int i=0; i < 6; i++)
	{
		printf("Node[%d]: f=%d g=%d\n", i, nodes[i].f, nodes[i].g);
		//		for(int j=0; j < nodes[i].edges_to.size(); j++)
		//		{
		//printf("\t->%d(%d)\n", nodes[i].edges_to[j], nodes[i].edges_cost[j]);
		//}
	}
	printf("--------------------------------------------\n");	
}

void print_list(const std::string label, const list<int> &list)
{
	std::cout << "[" << label << "] ";
	for(auto i:list)
	{
		std::cout << i << ",";
	}
	std::cout << std::endl;
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

void print_list(const list<int>& list)
{
	for(const auto& i: list)
	{
		std::cout << i << ",";
	}
	std::cout << std::endl;
}

bool has_elem(const list<int>& list, int item)
{
	for(const auto& i: list)
	{
		if(i == item) return true;
	}
	return false;
}
int a_star(void)
{
	list<int> olist;
	list<int> clist;
    olist.push_back(start);

	nodes[start].f = 0;
	clist.clear();

	// f(n) = g(n) + h(n)
	// g(n): スタートノードからのnまでの最小コスト推定値
	// h(n): nからゴールノードまでの最小コスト推定値
	
	while(!olist.empty())
	{
		// print_list(olist);
		print_list("Open  List", olist);
		print_list("Close List", clist);
		
		int n = -1;
		int f = -1;

		for(const auto& i: olist)
		{
			// pick up the minimum f_n (n)
			if(f < 0  || f > (nodes[i].g + nodes[i].h))
			{
				n = i;
				f = nodes[i].g + nodes[i].h;
			}
		}
		printf("Node %d (f=%d)\n", n, f);
		if(n == goal)
		{
			break;
		}

		olist.erase(remove(olist.begin(), olist.end(), n));
		clist.push_back(n);

		for(int i=0; i < nodes[n].edges_to.size(); i++)
		{
			int m  = nodes[n].edges_to[i];

			//int tmp_f = nodes[n].g + nodes[m].h;
			nodes[m].h = 0; // distance from goal to successor.
			int f_ = nodes[n].g + nodes[n].edges_cost[i] + nodes[m].h;
			
			if(!has_elem(olist, m) && !has_elem(clist, m))
			{

				nodes[m].f = f_;
				nodes[m].g = nodes[m].f;
				nodes[m].from = n;
				olist.push_back(m);
			} else if(has_elem(olist, m) && (f_ < nodes[m].f))	{
				nodes[m].f = f_;
				nodes[m].g = nodes[m].f;
				nodes[m].from = n;
			} else if(has_elem(clist, m) && (f_ < nodes[m].f))	{
				nodes[m].f = f_;
				nodes[m].g = nodes[m].f;				
				nodes[m].from = n;
				olist.push_back(m);
			}		
		}
		dump();
	}

	return 0;
}

void trace(int n)
{
	int v = n;
	
	do {
		std::cout << v << "<-";
		v = nodes[v].from;		
	} while (v >= 0);
	
	std::cout<< std::endl;
}
int main(int argc, const char* argv[])
{
	int ret = 0;
	init();

	ret = a_star();
	printf("Goal cost: %d\n", nodes[goal].f);
	trace(goal);
	return ret;
}
