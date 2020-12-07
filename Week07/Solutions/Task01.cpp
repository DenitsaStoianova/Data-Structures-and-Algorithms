#include "pch.h"
#include <iostream>

struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int data, TreeNode* left = nullptr, TreeNode* right = nullptr)
	{
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

void insert(TreeNode* &root, int data)
{
	if (root == nullptr)
	{
		root = new TreeNode(data);
		return;
	}

	if (data < root->data)
	{
		insert(root->left, data);
	}
	else
	{
		insert(root->right, data);
	}
}

TreeNode* getMinNode(TreeNode* treeRoot) // най-малката стойност се намира възможно най-вляво
{
	TreeNode* current = treeRoot;
	while (current != nullptr && current->left != nullptr)
	{
		current = current->left;
	}
	return current;
}

TreeNode* removeByData(TreeNode* &treeRoot, int data)
{
	if (treeRoot == nullptr)
	{
		return nullptr;
	}

	if (data < treeRoot->data) // Първо стигаме до възела, който искаме да изтрием
	{
		treeRoot->left = removeByData(treeRoot->left, data);
	}
	else if (data > treeRoot->data)
	{
		treeRoot->right = removeByData(treeRoot->right, data);
	}
	else // data == treeRoot->data
	{
		if (treeRoot->left == nullptr) // Проверяваме дали възела, който искаме да изтрием има само десен наследник (обхваща и случая, когато възела няма наследници)
		{
			TreeNode* nodeToDel = treeRoot->right;
			delete treeRoot;
			return nodeToDel;
		}
		else if (treeRoot->right == nullptr) // Проверяваме дали възела, който искаме да изтрием има само ляв наследник
		{
			TreeNode* nodeToDel = treeRoot->left;
			delete treeRoot;
			return nodeToDel;
		}

		// Когато възела, който искаме да изтрием има 2 наследника - при изтриването му трябва да бъде запазена наредбата в дървото
		TreeNode* minValueNode = getMinNode(treeRoot->right); // за целта се намира най-малката стойност в дясното поддърво на възела
		treeRoot->data = minValueNode->data; // и възела, който искаме да изтрием приема тази стойност 
		treeRoot->right = removeByData(treeRoot->right, minValueNode->data); // след това отиваме да я изтрием от дървото  
	}
	return treeRoot;
}

int main()
{
	TreeNode* root = nullptr;
	insert(root, 10);
	insert(root, 4);
	insert(root, 2);
	insert(root, 7);
	insert(root, 6);
	insert(root, 9);
	insert(root, 15);
	insert(root, 13);
	insert(root, 18);
	insert(root, 14);

	root = removeByData(root, 4);

	return 0;
}
