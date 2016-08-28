#include "brute_force.h"
#include "kmp.h"
#include "bm.h"
#include "aho_corasick.h"
#include "rabin_karp.h"

#include <list>

int main(int argc, const char* argv[])
{
	
	std::list<std::shared_ptr<SSBase>> ss;
	ss.push_back(std::make_shared<BruteForceSearch>());
	ss.push_back(std::make_shared<Kmp>());
	ss.push_back(std::make_shared<Bm>());
	// ss.push_back(std::make_shared<AhoCorasick>());
	// ss.push_back(std::make_shared<RabinKarp>());

	const char* test[][2] =
		{
			{"ABC ABCDAB ABCDABCDABDE", "ABCDABD"}, // Wiki sample
			{"abaababababbb", "ababb"}, // Capm Network sample
			{"GCTCACTGAGCGCTCGT", "GCTCG"} // Capm Network sample (2)
		};

	for(auto& t: test)
	{
		printf("Seach '%s' in '%s'\n", t[1], t[0]);
		for(auto& s: ss)
		{
			s->Run(t[0], t[1]);
		}
	}
	
	return 0;
}
