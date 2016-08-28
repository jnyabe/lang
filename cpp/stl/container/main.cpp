
#include <string>

// sequence container
#include "Array.h"
#include "Vector.h"
#include "Deque.h"

#include <list>
#include <forward_list> // C++11


#include <map>
#include <set>
//#include <multiset>

#include <queue>
//#include <priority_queue>
#include <stack>

using namespace std;


int main(int argc, const char* argv[])
{
	typedef int DataType;
	const int num = 20;

	// Sequence container
	Vector vec(num);
	Array  ary(20);
	Deque  deq(num);
	// vector<DataType>         vec(num, 0);

	list<DataType>           lis(num);
	forward_list<DataType>   fwl(num);

	vec.Dump();
	ary.Dump();
	deq.Dump();
	
	return 0;
}
