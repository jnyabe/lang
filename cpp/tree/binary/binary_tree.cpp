#include <list>
#include "binary_tree.h"

BTree::Node::~Node()
{
	printf("delete %d\n", m_value);
}


BTree::~BTree()
{
	// clean up all node
}

void BTree::Insert(int n)
{
	Node* node = new Node(n);
	Node* parent = nullptr;
	Node** ptr = &m_root;

	while(*ptr != nullptr)
	{
		if((*ptr)->m_value < n)
		{
			parent = (*ptr);
			ptr = &((*ptr)->m_right);
		} else {
			parent = (*ptr);			
			ptr = &((*ptr)->m_left);
		}
	}
	if(parent)
	{
		// fprintf(stderr, "Insert %d (%p) as %d (%p)'s child\n", n, node , parent->m_value, parent);
	} else {
		// fprintf(stderr, "Insert %d (%p) as root\n", n, node);
	}

	*ptr = node;
	node->m_parent = parent;
}

void BTree::Delete(int n)
{
	Node* node = find(n);

	if(node == nullptr)
	{
		return;
	}
	
	// no children
	if(node->m_left == nullptr && node->m_right == nullptr)
	{
		if(node->m_parent)
		{
			// set nullptr to the link fomr parent
			Node** ref = (node->m_parent->m_left == node)?
				&(node->m_parent->m_left) : &(node->m_parent->m_right);
			*ref = nullptr;
		} else {
			m_root = nullptr;
		}
		// delete node.
		delete node;
		return;
	}

	// 1 child
	if(node->m_left == nullptr || node->m_right == nullptr)
	{
		Node* child = (node->m_left)? node->m_left: node->m_right;
		if(node->m_parent)
		{
			// set nullptr to the link fomr parent
			Node** ref = (node->m_parent->m_left == node)?
				&(node->m_parent->m_left) : &(node->m_parent->m_right);
			*ref = child;
			child->m_parent = node->m_parent;
		} else {
			m_root = child;
			child->m_parent = nullptr;
		}
		// delete node.
		delete node;
		return;
	}

	// 2 children
	// printf("** CANNOT DELETE %d**\n", node->m_value);
	Node* replace = findMax(node->m_left);
	printf("%d will be replace with %d\n",
		   node->m_value, replace->m_value);
	if(replace)
	{
		replace->m_parent->m_right = replace->m_left;
		if(replace->m_left)
		{
			replace->m_left->m_parent  = replace->m_parent;
		}

		replace->m_left  = node->m_left;
		replace->m_right = node->m_right;
		
		if(node->m_parent)
		{
			Node** ref = (node->m_parent->m_left == node)?
				&(node->m_parent->m_left) : &(node->m_parent->m_right);
			*ref = replace;
			replace->m_parent = node->m_parent;
		} else {
			m_root = replace;
			replace->m_parent = nullptr;
		}
		
		delete node;
		return;
	} else {
		printf("No max!!!\n");
	}
}

BTree::Node* BTree::Find(int n)
{
	return find(n);
}

void BTree::Dump(void) const
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

BTree::NodeList BTree::GetDFS(void) const
{
	BTree::NodeList nodeList;
	return getDFS(m_root);
}

BTree::NodeList BTree::GetBFS(bool nullSep) const
{
	BTree::NodeList nodeList;
	BTree::NodeList target;	
	BTree::NodeList next;
	
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

BTree::Node* BTree::find(int n)
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

BTree::Node* BTree::findMax(Node *node)
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

BTree::Node* BTree::findMin(Node *node)
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
BTree::NodeList BTree::getDFS(Node* node) const
{
	BTree::NodeList nodeList;
	
	if(node == nullptr)
	{
		return nodeList;
	}

	nodeList.push_back(node);
	nodeList.splice(nodeList.end(), std::move(getDFS(node->m_left)));
	nodeList.splice(nodeList.end(), std::move(getDFS(node->m_right)));	
	return nodeList;
}


