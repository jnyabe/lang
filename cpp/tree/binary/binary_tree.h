#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <list>

class BTree
{
public:
	class Node
	{
	public:		
		int   m_value;
		Node* m_left;
		Node* m_right;
		
		Node()
			: m_value(0),
			  m_left(nullptr),
			  m_right(nullptr) {}
			  
		Node(int n)
			: m_value(n),
			  m_left(nullptr),
			  m_right(nullptr) 	{}
		virtual ~Node();
		void Print(void) const;
	};

	typedef std::list<Node*> NodeList;
	
private:
	BTree::Node* m_root;
	BTree::Node* insertNode(int n, Node* node);
	BTree::Node* deleteNode(int n, Node* node);
	BTree::Node* find(int n);

	BTree::Node* findMax(Node *node);
	BTree::Node* findMin(Node *node);
	BTree::Node* deleteMax(Node *node);	
	BTree::Node* deleteMin(Node *node);
	
	NodeList getDFS(Node* node) const;
	
public:
	BTree(): m_root(nullptr) {}
	virtual ~BTree();
	void Insert(int n);
	void Delete(int n);
	BTree::Node* Find(int n);
	void Dump(void) const;
	NodeList GetDFS(void) const;
	NodeList GetBFS(bool nullSep = false) const;
};

#endif /* _BINARY_TREE_H_ */
