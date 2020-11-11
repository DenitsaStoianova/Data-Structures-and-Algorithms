#pragma once
#include "pch.h"
#include "BinaryTree.h"
#include <iostream>

BinaryTree::BinaryTree()
{
	this->root = nullptr;
}

BinaryTree::TreeNode* BinaryTree::copy(TreeNode* otherRoot)
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

void BinaryTree::clear(TreeNode* &treeRoot)
{
	if (treeRoot == nullptr)
	{
		return;
	}
	this->clear(treeRoot->left);
	this->clear(treeRoot->right);
	delete treeRoot;
}

BinaryTree::BinaryTree(const BinaryTree& other)
{
	this->root = this->copy(other.root);
}

BinaryTree& BinaryTree::operator=(const BinaryTree& other)
{
	if (this != &other)
	{
		this->clear(this->root);
		this->root = this->copy(other.root);
	}
	return *this;
}

BinaryTree::~BinaryTree()
{
	this->clear(this->root);
}

void BinaryTree::addEelement(int data, const std::string& strPath)
{
	if (root == nullptr) // Ако дървото е празно
	{
		root = new TreeNode(data);
		return;
	}

	TreeNode* currentRoot = root;

	size_t size = strPath.size() - 1;
	for (size_t i = 0; i < size; i++) // Движим се по възлите в дървото
	{
		if (strPath[i] == 'L')
		{
			currentRoot = currentRoot->left;
		} 
		else if (strPath[i] == 'R')
		{
			currentRoot = currentRoot->right;
		}

		if (currentRoot == nullptr)
		{
			return;
		}
	}

	if (strPath[size] == 'L') // Добавяме подадения елемент според посочената позиция
	{
		currentRoot->left = new TreeNode(data);
	}
	else if (strPath[size] == 'R')
	{
		currentRoot->right = new TreeNode(data);
	}
}

int BinaryTree::getRootData() const
{
	if (this->root == nullptr)
	{
		throw new std::invalid_argument("Root is nullptr.");
	}
	return this->root->data;
}

int BinaryTree::getCount() const
{
	return this->getCountHelp(this->root);
}

int BinaryTree::getCountHelp(TreeNode* treeRoot) const
{
	if (treeRoot == nullptr)
	{
		return 0;
	}
	return 1 + getCountHelp(treeRoot->left) + getCountHelp(treeRoot->right);
}

bool BinaryTree::isEmpty() const
{
	return this->root == nullptr;
}
