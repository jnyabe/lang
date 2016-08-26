#ifndef _RED_BLACK_TREE_H_
#define _RED_BLACK_TREE_H_

#include <list>

/// @brief Red Black tree
class RedBlackTree
{
public:
	class Node
	{
	public:
		enum Color
			{
				BLACK,
				RED,
			};
		int   m_value;
		Color m_color;
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
	RedBlackTree::Node* m_root;
	RedBlackTree::Node* insertNode(int n, Node* node);
	RedBlackTree::Node* deleteNode(int n, Node* node);
	RedBlackTree::Node* find(int n);

	RedBlackTree::Node* findMax(Node *node);
	RedBlackTree::Node* findMin(Node *node);
	RedBlackTree::Node* deleteMax(Node *node);	
	RedBlackTree::Node* deleteMin(Node *node);
	
	NodeList getDFS(Node* node) const;
	
public:
	RedBlackTree(): m_root(nullptr) {}
	virtual ~RedBlackTree();
	void Insert(int n);
	void Delete(int n);
	RedBlackTree::Node* Find(int n);
	void Dump(void) const;
	NodeList GetDFS(void) const;
	NodeList GetBFS(bool nullSep = false) const;
};

#endif /* _RED_BLACK_TREE_H_ */
