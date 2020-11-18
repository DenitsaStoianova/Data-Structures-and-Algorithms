#include "pch.h"
#include "BinarySearchTree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree()
{
	this->root = nullptr;
}

BinarySearchTree::TreeNode* BinarySearchTree::copy(TreeNode* otherRoot)
{
	if (otherRoot == nullptr)
	{
		return nullptr;
	}

	TreeNode* copyRoot = new TreeNode(otherRoot->data);
	copyRoot->left = this->copy(otherRoot->left);
	copyRoot->right = this->copy(otherRoot->right);
	return copyRoot;
}

void BinarySearchTree::clear(TreeNode* &treeRoot)
{
	if (treeRoot == nullptr)
	{
		return;
	}

	this->clear(treeRoot->left); 
	this->clear(treeRoot->right);
	delete treeRoot;
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& other)
{
	this->root = this->copy(other.root);
}

BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree& other)
{
	if (this != &other)
	{
		this->clear(this->root);
		this->root = this->copy(other.root);
	}
	return *this;
}

BinarySearchTree::~BinarySearchTree()
{
	this->clear(this->root);
}

void BinarySearchTree::insert(int data)
{
	this->insertHelp(this->root, data);
}

void BinarySearchTree::insertHelp(TreeNode* &treeRoot, int data)
{
	if (treeRoot == nullptr)
	{
		treeRoot = new TreeNode(data);
		return;
	}

	if (data < treeRoot->data)
	{
		this->insertHelp(treeRoot->left, data);
	}
	else
	{
		this->insertHelp(treeRoot->right, data);
	}
}

void BinarySearchTree::remove(int data)
{
	this->removeHelp(this->root, data);
}

BinarySearchTree::TreeNode* BinarySearchTree::removeHelp(TreeNode* &treeRoot, int data)
{
	if (treeRoot == nullptr)
	{
		return nullptr;
	}

	if (data < treeRoot->data)
	{
		treeRoot->left = this->removeHelp(treeRoot->left, data);
	}
	else if (data > treeRoot->data)
	{
		treeRoot->right = this->removeHelp(treeRoot->right, data);
	}
	else // data == treeRoot->data
	{
		if (treeRoot->left == nullptr)
		{
			TreeNode* nodeToDel = treeRoot->right;
			delete treeRoot;
			return nodeToDel;
		}
		else if (treeRoot->right == nullptr)
		{
			TreeNode* nodeToDel = treeRoot->left;
			delete treeRoot;
			return nodeToDel;
		}

		TreeNode* minValueNode = getMinNode(treeRoot->right);
		treeRoot->data = minValueNode->data;
		treeRoot->right = this->removeHelp(treeRoot->right, minValueNode->data);
	}
	return treeRoot;
}

BinarySearchTree::TreeNode* BinarySearchTree::getMinNode(TreeNode* treeRoot)
{
	TreeNode* current = treeRoot;
	while (current != nullptr && current->left != nullptr)
	{
		current = current->left;
	}
	return current;
}

bool BinarySearchTree::find(int key) const
{
	return this->findHelp(this->root, key);
}

bool BinarySearchTree::findHelp(TreeNode* treeRoot, int key) const
{
	if (treeRoot == nullptr)
	{
		return false;
	}

	if (treeRoot->data == key)
	{
		return true;
	}

	if (key < treeRoot->data)
	{
		return this->findHelp(treeRoot->left, key);
	}
	else
	{
		return this->findHelp(treeRoot->right, key);
	}
}

size_t BinarySearchTree::size() const
{
	return this->sizeHelp(this->root);
}

size_t BinarySearchTree::sizeHelp(TreeNode* treeRoot) const
{
	if (treeRoot == nullptr)
	{
		return 0;
	}

	return 1 + this->sizeHelp(treeRoot->left) + this->sizeHelp(treeRoot->right);
}

void BinarySearchTree::printSortedAsc() const
{
	this->printSortedAscHelp(this->root);
	std::cout << std::endl;
}

void BinarySearchTree::printSortedAscHelp(TreeNode* treeRoot) const
{
	if (treeRoot == nullptr)
	{
		return;
	}

	this->printSortedAscHelp(treeRoot->left);
	std::cout << treeRoot->data << " ";
	this->printSortedAscHelp(treeRoot->right);
}

void BinarySearchTree::printSortedDesc() const
{
	this->printSortedDescHelp(this->root);
	std::cout << std::endl;
}

void BinarySearchTree::printSortedDescHelp(TreeNode* treeRoot) const
{
	if (treeRoot == nullptr)
	{
		return;
	}

	this->printSortedDescHelp(treeRoot->right);
	std::cout << treeRoot->data << " ";
	this->printSortedDescHelp(treeRoot->left);
}
