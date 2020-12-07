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

// За да превърнем двоично дърво в двоично наредено може да създадем масив, който съдържа стойностите на възлите на двоичното дърво
// след това да го сортираме и да построим дърво от сортирания масив, използвайки обхождането ляво, корен, дясно

void treeToArrInorder(TreeNode* &root, int* arr, int &index)
{
	if (root == nullptr)
	{
		return;
	}

	treeToArrInorder(root->left, arr, index);
	arr[index++] = root->data;
	treeToArrInorder(root->right, arr, index);
}

void bubbleSort(int* arr, int size)
{
	bool found = true;
	for (int i = 0; i < size - 1; i++)
	{
		found = false;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
				found = true;
			}
		}
		if (!found)
		{
			break;
		}
	}
}

void arrToTreeInorder(TreeNode* &root, int* arr, int &index)
{
	if (root == nullptr)
	{
		return;
	}

	arrToTreeInorder(root->left, arr, index);
	root->data = arr[index++];
	arrToTreeInorder(root->right, arr, index);
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
	root->right->left = new TreeNode(10);

	int arr[1000];
	int index = 0;
	treeToArrInorder(root, arr, index);

	bubbleSort(arr, index);

	index = 0;
	arrToTreeInorder(root, arr, index);

	return 0;
}
