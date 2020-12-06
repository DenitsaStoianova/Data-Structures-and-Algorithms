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

// Едно двоично дърво е Full Binary Tree ако всеки негов възел има 0 или 2 деца
bool isFull(TreeNode* &root)
{
	if (root == nullptr)
	{
		return true;
	}

	if ((root->left == nullptr && root->right != nullptr)
	  ||(root->right == nullptr && root->left != nullptr))
	{
		return false;
	}

	return isFull(root->left) && isFull(root->right);
}

// Едно двоично дърво е Perfect Binary Tree ако всеки вътрешен възел
// има точно 2 деца и всички листа са на едно ниво
int findLeftmostLeafLevel(TreeNode* &root)
{
	if (root == nullptr)
	{
		return 0;
	}

	if (root->left != nullptr)
	{
		return 1 + findLeftmostLeafLevel(root->left);
	}
	else
	{
		return 1 + findLeftmostLeafLevel(root->right);
	}
}

bool isPerfectHelp(TreeNode* &root, int leftmostLeaflevel, int currLevel)
{
	if (root == nullptr)
	{
		return true;
	}

	currLevel++;

	if (root->left == nullptr && root->right == nullptr)
	{
		return leftmostLeaflevel == currLevel;
	}

	if (root->left == nullptr || root->right == nullptr)
	{
		return false;
	}

	return isPerfectHelp(root->left, leftmostLeaflevel, currLevel)
		&& isPerfectHelp(root->right, leftmostLeaflevel, currLevel);
}

bool isPerfect(TreeNode* &root)
{
	int level = findLeftmostLeafLevel(root);
	return isPerfectHelp(root, level, 0);
}

// Едно двоично дърво е Complete Binary Tree когато
// всички нива освен последното са напълно запълнени и 
// възлите на последното ниво са възможно най-вляво

// Ако представим дървото като масив и i е индекса на текущия елемент, то
// 2*i + 1 е индекса на лявото му дете, а 2*i + 2 - на дясното

int countNodes(TreeNode* &root)
{
	if (root == nullptr)
	{
		return 0;
	}
	return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isCompleteHelp(TreeNode* &root, int index, int countOfNodes)
{
	if (root == nullptr)
	{
		return true;
	}

	if (index >= countOfNodes)
	{
		return false;
	}

	return isCompleteHelp(root->left, 2 * index + 1, countOfNodes) &&
		isCompleteHelp(root->right, 2 * index + 2, countOfNodes);
}

bool isComplete(TreeNode* &root)
{
	int count = countNodes(root);
	return isCompleteHelp(root, 0, count);
}

int main()
{
	TreeNode* root = new TreeNode(8);
	root->left = new TreeNode(3);
	root->left->left = new TreeNode(9);
	root->left->right = new TreeNode(6);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(7);

	std::cout << isFull(root) << "\n";
	std::cout << isPerfect(root) << "\n";
	std::cout << isComplete(root) << "\n";

	return 0;
}
