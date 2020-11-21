#include "pch.h"
#include <iostream>
#include <vector>

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

// 1. Всички възможни пътища

void printArrPath(int* arrPath, int plen)
{
	for (int i = 0; i < plen; i++)
	{
		std::cout << arrPath[i] << " ";
	}
	std::cout << "\n";
}

void printAllPathsHelp(TreeNode* &root, int* arrPath, int plen)
{
	if (root == nullptr)
	{
		return;
	}

	arrPath[plen++] = root->data;

	if (root->left == nullptr && root->right == nullptr)
	{
		printArrPath(arrPath, plen);
		return;
	}

	printAllPathsHelp(root->left, arrPath, plen);
	printAllPathsHelp(root->right, arrPath, plen);
}

void printAllPaths(TreeNode* &root)
{
	int path[1000];
	printAllPathsHelp(root, path, 0);
}

// 2. Пътя от корена на дървото до даден възел

bool pathFromRootToNode(TreeNode* &root, TreeNode* &node, int* arr, int index)
{
	if (root == nullptr)
	{
		return false;
	}

	arr[index++] = root->data;

	if (root == node)
	{
		printArrPath(arr, index);
		return true;
	}

	if (pathFromRootToNode(root->left, node, arr, index) ||
		pathFromRootToNode(root->right, node, arr, index)) 
	{
		return true;
	}
	return false;
}

bool findPath(TreeNode* &root, TreeNode* &node)
{
	int arr[1000];
	return pathFromRootToNode(root, node, arr, 0);
}

// Сумата на най-дългия път
void findSumHelp(TreeNode* &root, int sum, int length, int &maxSum, int &maxLength)
{
	if (root == nullptr)
	{
		if (length > maxLength)
		{
			maxLength = length;
			maxSum = sum;
		}
		else if (length == maxLength && sum > maxSum)
		{
			maxSum = sum;
		}
		return;
	}

	sum += root->data;

	findSumHelp(root->left, sum, length + 1, maxSum, maxLength);
	findSumHelp(root->right, sum, length + 1, maxSum, maxLength);
}

int findLongestSum(TreeNode* &root)
{
	if (root == nullptr)
	{
		return 0;
	}

	int maxSum = INT_MIN, maxLength = 0;
	findSumHelp(root, 0, 1, maxSum, maxLength);
	return maxSum;
}

int main()
{
	TreeNode* root = new TreeNode(8);
	root->left = new TreeNode(3);
	root->left->left = new TreeNode(9);
	root->left->right = new TreeNode(6);
	root->left->right->left = new TreeNode(4);
	root->left->right->left->left = new TreeNode(10);
	root->left->right->right = new TreeNode(7);
	root->right = new TreeNode(2);
	root->right->right = new TreeNode(5);
	root->right->left = new TreeNode(1);

	printAllPaths(root);

	findPath(root, root->left->right->right);

	std::cout << findLongestSum(root) << "\n";

	return 0;
}
