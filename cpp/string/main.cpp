#include "kmp.h"
#include "boyer-moore.h"
#include "aho-corasick.h"

#include <list>

int main(int argc, const char* argv[])
{
	std::list<std::shared_ptr<SSBase>> ss;
	
	ss.push_back(std::make_shared<Kmp>());
	ss.push_back(std::make_shared<BoyerMoore>());
	ss.push_back(std::make_shared<AhoCorasick>());
	
	
	for(auto& s: ss)
	{
		s->Run(argc, argv);
	}
	
	return 0;
}
