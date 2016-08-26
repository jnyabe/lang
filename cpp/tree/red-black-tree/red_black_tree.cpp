#include "red_black_tree.h"

RedBlackTree::Node::~Node()
{
	
}


RedBlackTree::~RedBlackTree()
{
	// clean up all node
}

void RedBlackTree::Insert(int n)
{
	m_root = insertNode(n, m_root);
}

void RedBlackTree::Delete(int n)
{
	printf("Delete %d\n", n);
	m_root = deleteNode(n, m_root);
}

RedBlackTree::Node* RedBlackTree::Find(int n)
{
	return find(n);
}

void RedBlackTree::Dump(void) const
{
	NodeList nodeList = GetBFS(true);

	for(const auto& node:nodeList)
	{
		if(node)
		{
			printf("(%d)", node->m_value);
		} else {
			printf("\n");
		}
	}
	printf("\n");
}

RedBlackTree::NodeList RedBlackTree::GetDFS(void) const
{
	RedBlackTree::NodeList nodeList;
	return getDFS(m_root);
}

RedBlackTree::NodeList RedBlackTree::GetBFS(bool nullSep) const
{
	RedBlackTree::NodeList nodeList;
	RedBlackTree::NodeList target;	
	RedBlackTree::NodeList next;
	
	if(m_root)
	{
		target.push_back(m_root);
	}

	while(!target.empty())
	{
		next.clear();
		if(!nodeList.empty() && nullSep)
		{
			nodeList.push_back(nullptr);
		}
		
		for(const auto& node:target)
		{
			nodeList.push_back(node);
			if(node->m_left)  next.push_back(node->m_left);
			if(node->m_right) next.push_back(node->m_right);
		}
		target = next;
	}
	
	return nodeList;
}

RedBlackTree::Node* RedBlackTree::insertNode(int n, Node* node)
{
	if(node == nullptr)
	{
		return new Node(n);
	} else if (n < node->m_value) {
		node->m_left = insertNode(n, node->m_left);
	} else {
		node->m_right = insertNode(n, node->m_right);
	}
	return node;
}

RedBlackTree::Node* RedBlackTree::deleteNode(int n, Node* node)
{
	if(node == nullptr)
	{
		return nullptr;
	}

	if(n == node->m_value)
	{
		if(node->m_left == nullptr)
		{
			Node* temp = node->m_right;
			delete node;
			return temp;
		}
		
		if(node->m_right == nullptr)
		{
			Node* temp = node->m_left;
			delete node;
			return temp;
		}
		node->m_value = findMin(node->m_right)->m_value;
		node->m_right = deleteMin(node->m_right);
	} else if (n < node->m_value) {
		node->m_left = deleteNode(n, node->m_left);
	} else {
		node->m_right = deleteNode(n, node->m_right);
	}
	return node;
}

RedBlackTree::Node* RedBlackTree::find(int n)
{
	Node* node = m_root;

	while(node != nullptr)
	{
		if(node->m_value == n)
		{
			return node;
		}
		
		if(node->m_value < n)
		{
			node = node->m_right;
		}
		if(node->m_value > n)
		{
			node = node->m_left;
		}
	}
	// not found
	return nullptr;
}

RedBlackTree::Node* RedBlackTree::findMax(Node *node)
{
	Node* maxNode = node;

	if(node == nullptr)
	{
		return nullptr;
	}
	
	while(node->m_right != nullptr)
	{
		node = node->m_right;
	}
	
	return node;
}

RedBlackTree::Node* RedBlackTree::findMin(Node *node)
{
	Node* maxNode = node;
	if(node == nullptr)
	{
		return nullptr;
	}
	
	while(node->m_left != nullptr)
	{
		node = node->m_left;
	}
	return node;
}

RedBlackTree::Node* RedBlackTree::deleteMax(Node *node)
{
	if(node->m_right == nullptr)
	{
		Node* temp = node->m_left;
		delete node;
		return temp;
	} else {
		node->m_right = deleteMax(node->m_right);
	}
	return node;
}

RedBlackTree::Node* RedBlackTree::deleteMin(Node *node)
{
	if(node->m_left == nullptr)
	{
		Node* temp = node->m_right;
		delete node;
		return temp;
	} else {
		node->m_left = deleteMin(node->m_left);
	}
	return node;
}

RedBlackTree::NodeList RedBlackTree::getDFS(Node* node) const
{
	RedBlackTree::NodeList nodeList;
	
	if(node == nullptr)
	{
		return nodeList;
	}

	nodeList.push_back(node);
	nodeList.splice(nodeList.end(), std::move(getDFS(node->m_left)));
	nodeList.splice(nodeList.end(), std::move(getDFS(node->m_right)));	
	return nodeList;
}


