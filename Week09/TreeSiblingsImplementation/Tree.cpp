#include "pch.h"
#include "Tree.h"
#include <iostream>

Tree::Tree()
{
	this->root = nullptr;
}

Tree::TreeNode* Tree::copy(TreeNode* treeRoot)
{
	if (treeRoot == nullptr)
	{
		return nullptr;
	}

	TreeNode* copyRoot = new TreeNode(treeRoot->data);
	copyRoot->child = this->copy(treeRoot->child);
	copyRoot->sibling = this->copy(treeRoot->sibling);
	return copyRoot;
}

Tree::Tree(const Tree& other)
{
	this->root = copy(other.root);
}

void Tree::clear(TreeNode* &treeRoot)
{
	if (treeRoot == nullptr)
	{
		return;
	}
	this->clear(treeRoot->child);
	this->clear(treeRoot->sibling);
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

	return this->findHelp(treeRoot->child, key) || this->findHelp(treeRoot->sibling, key);
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
	count += this->getSizeHelp(treeRoot->child) + this->getSizeHelp(treeRoot->sibling);
	return count;
}

void Tree::print() const
{
	this->printHelp(this->root);
	std::cout << "\n";
}

void Tree::printHelp(TreeNode* root) const
{
	if (root == nullptr)
	{
		return;
	}

	std::cout << root->data << " ";
	this->printHelp(root->child);
	this->printHelp(root->sibling);
}
