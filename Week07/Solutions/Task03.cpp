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

void addGreatersSumHelp(TreeNode* &root, int sum)
{
	if (root == nullptr)
	{
		return;
	}

	addGreatersSumHelp(root->right, sum);

	sum += root->data;
	root->data = sum;

	addGreatersSumHelp(root->left, sum);
}

void addGreatersSum(TreeNode* &root)
{
	int sum = 0;
	addGreatersSumHelp(root, sum);
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

	addGreatersSum(root);

	return 0;
}
