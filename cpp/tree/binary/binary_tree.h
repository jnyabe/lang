#include "binary_tree.h"

class BTree
{
private:
	class Node
	{
		friend class BTree;
	private:
		int  m_value;
		Node* m_left;
		Node* m_right;
		Node* m_parent;		
	public:
		Node(): m_value(0), m_left(nullptr), m_right(nullptr), m_parent(nullptr {}		
																		Node(int n): m_value(n), m_left(nullptr), m_right(nullptr) , m_parent(nullptr) {}
		virtual ~Node() {}
	};

	Node* m_root;

	Node* find(int n);
public:
	BTree(): m_root(nullptr) {}
	virtual ~BTree();
	void Insert(int n);
	void Delete(int n);
	void Find();
	void Dump(void) const;
};

#endif /* _BINARY_TREE_H_ */
