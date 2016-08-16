#include "binary_tree.h"

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

	if(node->parent)
	{
		
	}
}

void BTree::Find()
{
	
}

void BTree::Dump() const
{
	
}


Node* BTree::find(int n)
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

