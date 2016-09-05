#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

typedef int DataType;


void print(const vector<DataType> &data)
{
	for(const auto& e: data)
	{
		cout << e << ",";
	}
	cout << endl;
}

void shiftUp(vector<DataType> &data, DataType n)
{
	data.push_back(n);
	int i = data.size() - 1;
	for(;;)
	{
	}
}

void shiftDown(vector<DataType> &data, DataType n)
{
	data.push_front(n);
}

int main(int argc, const char* argv[])
{
	int ret = 0;
	vector<DataType> data(20);

	iota(data.begin(), data.end(), 0);
	
	print(data);
	
	return ret;
}
