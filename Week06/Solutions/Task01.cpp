#include "pch.h"
#include <iostream>
#include <algorithm>

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

// 1 - Намиране на височината на дървото
int findHeight(TreeNode* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	int leftHeight = findHeight(root->left);
	int rightHeight = findHeight(root->right);

	return 1 + std::max(leftHeight, rightHeight);
}

// 2. Намиране на нивото на което се намира даден възел от дървото
int findLevel(TreeNode* &root, TreeNode* &nodeToFind, int level)
{
	if (root == nullptr)
	{
		return 0;
	}

	if (root == nodeToFind)
	{
		return level;
	}

	int leftLevel = findLevel(root->left, nodeToFind, level + 1);
	if (leftLevel != 0)
	{
		return leftLevel;
	}
	return findLevel(root->right, nodeToFind, level + 1);
}

// 3. Намиране на сумата на всички възли
int findSum(TreeNode* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	return root->data + findSum(root->left) + findSum(root->right);
}

// 4.  Намиране на броя на всички възли
int findCount(TreeNode* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	return 1 + findCount(root->left) + findCount(root->right);
}

// 5. Намиране на броя на всички вътрешни възли
int findInternalNodesCount(TreeNode* root)
{
	if (root == nullptr || (root->left == nullptr && root->right == nullptr))
	{
		return 0;
	}

	return 1 + findInternalNodesCount(root->left) + findInternalNodesCount(root->right);
}


int main()
{
	TreeNode* root = new TreeNode(8);
	root->left = new TreeNode(3);
	root->left->left = new TreeNode(9);
	root->left->right = new TreeNode(6);
	root->left->right->left = new TreeNode(4);
	root->left->right->right = new TreeNode(7);
	root->right = new TreeNode(2);
	root->right->right = new TreeNode(5);
	root->right->left = new TreeNode(7);

	std::cout << findHeight(root) << "\n";
	std::cout << findLevel(root, root->left->right, 1) << "\n";
	std::cout << findSum(root) << "\n";
	std::cout << findCount(root) << "\n";
	std::cout << findInternalNodesCount(root) << "\n";

	return 0;
}
