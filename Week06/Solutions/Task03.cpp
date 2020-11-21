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

// дали всеки възел от двоично дърво е равен на сумата от лявото и дясното му дете
bool checkSum(TreeNode* &root)
{
	if (root == nullptr)
	{
		return true;
	}

	if (root->right != nullptr && root->left == nullptr && root->data != root->right->data)
	{
		return false;
	}
	else if (root->left != nullptr && root->right == nullptr && root->data != root->left->data)
	{
		return false;
	}
	else if (root->right != nullptr && root->left != nullptr && root->data != root->right->data + root->left->data)
	{
		return false;
	}	

	return checkSum(root->left) && checkSum(root->right);
}

// дали всеки възел от двоично дърво е равен на сумата от лявото и дясното му поддърво
int sum(TreeNode* &root)
{
	if (root == nullptr)
	{
		return 0;
	}

	return root->data + sum(root->left) + sum(root->right);
}

bool check(TreeNode* &root)
{
	if (root == nullptr || (root->left == nullptr && root->right == nullptr))
	{
		return true;
	}

	if (root->data != sum(root->left) + sum(root->right))
	{
		return false;
	}

	return check(root->left) && check(root->right);
}

int main()
{
	/*
	TreeNode* root = new TreeNode(10);
	root->left = new TreeNode(7);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(1);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(3);

	std::cout << checkSum(root) << "\n";
	*/
	
	TreeNode* root = new TreeNode(30);
	root->left = new TreeNode(10);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(6);
	root->right = new TreeNode(5);
	root->right->right = new TreeNode(5);

	std::cout << check(root) << "\n";
	

	return 0;
}
