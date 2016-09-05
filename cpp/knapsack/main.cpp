#include <vector>
#include <algorithm>
#include <random>
#include <iostream>

using namespace std;

struct Item
{
	int   id;
	float cost; 
	float weight;
};


void init(vector<Item> &items)
{
	random_device rnd;
	mt19937 mt(rnd());
	std::uniform_int_distribution<> rand10(1, 10);
	int id = 1;
	for(auto& i: items)
	{
		i.id = id++;
		i.cost   = rand10(mt);
		i.weight = rand10(mt);
	}	
}

void print(string label, vector<Item> &items)
{
	cout << label << "(" << items.size() << ")" <<endl;
	
	for(auto& i: items)
	{
		cout << "id(" << i.id << ")" ;
		cout << " cost("<< i.cost << ")" ;
		cout << " wight(" << i.weight << ")";
		cout << " cost/weight(" << i.cost/i.weight << ")";
		cout << endl;
	}	
}
int main(int argc, const char* argv[])
{
	int n   = 10; // num of items
	vector<Item> items(n);
	vector<Item> knapzak;
	
	float max_w = 10 * n / 2;
	float w = 0.0;
	
	init(items);
	
	sort(items.begin(), items.end(), [](const Item &a, const Item &b)
		 {return (a.cost/a.weight)>(b.cost/b.weight); });
	
	print("items", items);

	for(const auto& i: items)
	{
		if(w + i.weight <= max_w)
		{
			knapzak.push_back(i);
			w += i.weight;
		}
	}
	print("knapzack", knapzak);
	cout << "knapzack weight:" << w;
	
	return 0;
}
