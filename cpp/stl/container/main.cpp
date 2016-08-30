#include <string>

// sequence container
#include <list>
#include "array.h"
#include "vector.h"
#include "deque.h"
#include "list.h"
#include "forward_list.h"

#include "set.h"
#include "map.h"
#include "multimap.h"
#include "unordered_map.h"
#include "unordered_multimap.h"

// container adapter
#include <stack>
#include <queue>
//#include <priority_queue>


using namespace std;


int main(int argc, const char* argv[])
{
	const int num = 20;
	std::list<std::shared_ptr<SequenceContainer>> scontainer;
	std::list<std::shared_ptr<Container>> container;

	// Sequence container
	scontainer.push_back(std::make_shared<Vector>(num));
	scontainer.push_back(std::make_shared<Array>(num)); // C++11
	scontainer.push_back(std::make_shared<Deque>(num));
	scontainer.push_back(std::make_shared<List>(num));
	scontainer.push_back(std::make_shared<ForwardList>(num)); // C++11

	for(auto c: scontainer)
	{
		for(int i=0; i< num; i++)
			(*c)[i] = i;
		c->Dump();
	}

	container.push_back(std::make_shared<Set>());
	container.push_back(std::make_shared<Map>());
	container.push_back(std::make_shared<MultiMap>());
	container.push_back(std::make_shared<UnorderedMap>());
	container.push_back(std::make_shared<UnorderedMultiMap>());		

	for(auto c: container)
	{

		for(int i=0; i< num; i++)
		{
			char value[32];
			snprintf(value, sizeof(value), "v%02d", i);
			(*c).Insert(i, value);
		}
		c->Dump();
		for(int i=0; i< num; i+=2)
		{
			(*c).Erase(i);
		}
		c->Dump();
	}

	return 0;
}
