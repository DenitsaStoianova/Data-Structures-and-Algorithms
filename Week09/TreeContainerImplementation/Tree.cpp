#include "pch.h"
#include "Tree.h"
#include <iostream>

Tree::Tree()
{
	this->root = nullptr; 
}

Tree::TreeNode* Tree::copy(TreeNode* otherRoot)
{
	if (otherRoot == nullptr)
	{
		return nullptr; 
	}

	TreeNode* copyRoot = new TreeNode();
	copyRoot->data = otherRoot->data;
	size_t childrenSize = otherRoot->children.size();
	for (size_t i = 0; i < childrenSize; i++)
	{
		copyRoot->children.push_back(this->copy(otherRoot->children[i]));
	}
	return copyRoot;
}

Tree::Tree(const Tree& other)
{
	this->root = this->copy(other.root);
}

void Tree::clear(TreeNode* &treeRoot)
{
	if (treeRoot == nullptr)
	{
		return;
	}

	size_t childrenSize = treeRoot->children.size(); 
	for (size_t i = 0; i < childrenSize; i++)        
	{
		this->clear(treeRoot->children[i]);
	}
	delete treeRoot;
}

Tree& Tree::operator=(const Tree& other)
{
	if (this != &other)
	{
		this->clear(this->root);
		this->root = this->copy(other.root);
	}
	return *this;
}

Tree::~Tree()
{
	this->clear(this->root);
}

bool Tree::find(int key) const
{
	return this->findHelp(this->root, key);
}

bool Tree::findHelp(TreeNode* treeRoot, int key) const
{
	if (treeRoot == nullptr)
	{
		return false; 
	}

	if (treeRoot->data == key)
	{
		return true;
	}

	size_t childrenSize = treeRoot->children.size();
	for (size_t i = 0; i < childrenSize; i++)
	{
		if (this->findHelp(treeRoot->children[i], key)) 
		{
			return true; 
		}
	}
	return false;
}				

size_t Tree::getSize() const
{
	return this->getSizeHelp(this->root);
}

size_t Tree::getSizeHelp(TreeNode* treeRoot) const
{
	if (treeRoot == nullptr)
	{
		return 0;
	}

	size_t count = 1; 
	size_t childrenSize = treeRoot->children.size();
	for (size_t i = 0; i < childrenSize; i++)
	{
		count += getSizeHelp(treeRoot->children[i]); 
	}
	return count; 
}

void Tree::print() const
{
	this->printHelp(this->root);
	std::cout << "\n";
}

void Tree::printHelp(TreeNode* treeRoot) const
{
	if (treeRoot == nullptr)
	{
		return;
	}

	std::cout << treeRoot->data << " ";
	size_t childrenSize = treeRoot->children.size();
	for (size_t i = 0; i < childrenSize; i++)
	{
		this->printHelp(treeRoot->children[i]);
	}
}
