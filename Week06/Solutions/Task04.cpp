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

int findLeftBoundSum(TreeNode* root) 
{
	if (root->left == nullptr && root->right == nullptr)
	{
		return root->data;
	}

	if (root->left != nullptr) 
	{						  
		return root->data + findLeftBoundSum(root->left);
	}
	else
	{
		return root->data + findLeftBoundSum(root->right);
	}
}

int findRightBoundSum(TreeNode* root)
{
	if (root->left == nullptr && root->right == nullptr)
	{
		return root->data;
	}

	if (root->right != nullptr)
	{
		return root->data + findRightBoundSum(root->right);
	}
	else
	{
		return root->data + findRightBoundSum(root->left);
	}
}

int findBoundsSum(TreeNode* root)
{
	int leftSum = 0, rightSum = 0;
	if (root->left != nullptr)
	{
		leftSum = findLeftBoundSum(root->left);
	}
	if (root->right != nullptr)
	{
		rightSum = findRightBoundSum(root->right);
	}
	return root->data + leftSum + rightSum;
}

int sumAllNodes(TreeNode* root)
{
	if (root == nullptr)
	{
		return 0;
	}
	return root->data + sumAllNodes(root->left) + sumAllNodes(root->right);
}

bool hasSameSum(TreeNode* &root)
{
	int boundsSum = findBoundsSum(root);
	int innerNodesSum = sumAllNodes(root) - boundsSum;
	return boundsSum == innerNodesSum;
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
	root->right->left = new TreeNode(1);
	root->right->right->left = new TreeNode(9);

	std::cout << hasSameSum(root) << "\n";

	return 0;
}
