#include <queue>
#include "aho_corasick.h"

AhoCorasick::Node*
AhoCorasick::buildPMA(const std::vector<std::string> &patterns)
{
	Node* root = new Node;
	Node* now;
	
	root->next[0] = root;

	for(int i=0; i < patterns.size(); i++)
	{
		now = root;
		for(int j=0; j < patterns[i].size(); j++)
		{
			if(now->next[(int)patterns[i][j]] == 0) {
				now->next[(int)patterns[i][j]] = new Node;
				now = now->next[(int)patterns[i][j]];
			}
			now->matched.push_back(i);
		}
	}

	std::queue<Node*> que;
	for(int i=0; i < 256; i++)
	{
		if(!root->next[i]) root->next[i] = root;
        else {
            root->next[i]->next[0] = root;
            que.push(root->next[i]);
        }
    }

	while(!que.empty()) {
        now = que.front(); que.pop();
        for(int i = 1; i < 256; i++) {
            if(now->next[i]){
                Node *nxt = now->next[0];
                while(!nxt->next[i]) nxt = nxt->next[0];
                now->next[i]->next[0] = nxt->next[i];
                // now->next[i]->matched = set_union(now->next[i]->matched, nxt->next[i]->matched);
                que.push(now->next[i]);
            }
        }
    }	
	return root;
}

int AhoCorasick::Search(const std::string& text, const std::string &pattern)
{
	int idx = -1;
	std::vector<std::string> patterns;
	patterns.push_back(pattern);
	Node* pma = buildPMA(patterns);

	delete pma;
	return idx;
}

int AhoCorasick::Search(const std::string& text
				  , const std::vector<std::string> &pattern)
{
	int idx = -1;
	return idx;	
}
