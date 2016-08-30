#include <string>

// sequence container
#include <list>
#include "array.h"
#include "vector.h"
#include "deque.h"
#include "list.h"
#include "forward_list.h"

#include <set>
#include <map>


// container adapter
#include <stack>
#include <queue>



//#include <multiset>


//#include <priority_queue>


using namespace std;


int main(int argc, const char* argv[])
{
	const int num = 20;
	std::list<std::shared_ptr<SequenceContainer>> container;

	// Sequence container
	container.push_back(std::make_shared<Vector>(num));
	container.push_back(std::make_shared<Array>(num)); // C++11
	container.push_back(std::make_shared<Deque>(num));
	container.push_back(std::make_shared<List>(num));
	container.push_back(std::make_shared<ForwardList>(num)); // C++11

	for(auto c: container)
	{
		for(int i=0; i< num; i++)
			(*c)[i] = i;
		c->Dump();
	}

	return 0;
}
