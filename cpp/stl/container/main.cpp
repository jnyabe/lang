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


// container adapter
#include <stack>
#include <queue>



//#include <multiset>


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
	
	// Set
	Set s;
	for(int i=0; i < num; i++)
	{
		s.Insert(i, "");
	}
	
	s.Dump();
	// Map
	return 0;
}
