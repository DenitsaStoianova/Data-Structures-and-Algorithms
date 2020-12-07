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

TreeNode* findLowestCommonAncestor(TreeNode* &root, int node1Data, int node2Data)
{
	if (root == nullptr)
	{
		return nullptr;
	}

	if (node1Data < root->data && node2Data < root->data)
	{
		return findLowestCommonAncestor(root->left, node1Data, node2Data);
	}

	if (node1Data > root->data && node2Data > root->data)
	{
		return findLowestCommonAncestor(root->right, node1Data, node2Data);
	}

	return root;
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

	TreeNode* lca = findLowestCommonAncestor(root, 6, 2);
	std::cout << lca->data << "\n";

	return 0;
}
