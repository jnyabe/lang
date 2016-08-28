#include <vector>
#include <iostream>
#include <random>
#include <cmath>

using namespace std;

void init(vector<int> &v)
{
	for(auto& e: v)
	{
		e = rand() % 100;
	}
	sort(v.begin(), v.end());
}

void print(vector<int> v)
{
	for(const auto& e: v)
	{
		cout << e << ",";
	}
	cout << endl;
}

int find(const vector<int>& v, int val, int& numComp)
{

	int idx = -1; // not found
	int l = 0;                // left end
	int r = v.size() - 1;     // right end
	numComp = 0;
	
	while(l <= r)
	{
		int m = (l + r) / 2;
		numComp++;
		if(v[m] == val)
		{
			idx = m;
			break;
		} else if (v[m] < val) {
			l = m + 1;
		} else if (v[m] > val) {
			r = m - 1;
		}
	}
	return idx;
}

int rfind(const vector<int>& v, int val, int l, int r)
{
	if(l <= r)
	{
		int m = (l + r) / 2;
		if(v[m] == val)
		{
			return m;
		} else if (v[m] < val) {
			return rfind(v, val, m + 1, r);
		} else if (v[m] > val) {
			return rfind(v, val, l, m - 1);
		}
	} 
	return -1;
}



int main(int argc, const char* argv[])
{

	vector<int> v(20);
	init(v);
	print(v);
	int numComp = 0;
	for(int i=0; i< 10; i++)
	{
		// int idx = find(v, i);
		//int idx = rfind(v, i, 0, v.size()-1);
		int idx = find(v, i, numComp);
		printf("Seach %d: idx=%d(#comp=%d) Log(n)=%d\n",
			   i, idx, numComp, log(20));
	}
		
	return 0;
}
