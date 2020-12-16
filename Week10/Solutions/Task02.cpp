#include "pch.h"
#include <iostream>
#include <queue>

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

void insertData(TreeNode* &root, const char* path, int data)
{
	if (root == nullptr)
	{
		root = new TreeNode(data);
		return;
	}

	if (*path == 'L')
	{
		insertData(root->left, path + 1, data);
	}
	else // R
	{
		insertData(root->right, path + 1, data);
	}
}

void findMaxSum(TreeNode* &root)
{
	std::queue<TreeNode*> queue;
	queue.push(root);
	int size;
	int sum = 0;
	int maxSum = 0;
	int level = 0;
	int maxLevel;
	TreeNode* current = nullptr;

	while (!queue.empty())
	{
		size = queue.size();
		level++;
		sum = 0;
		while (size > 0)
		{
			current = queue.front();
			queue.pop();
			size--;
			sum += current->data;
			if (current->left != nullptr)
			{
				queue.push(current->left);
			}
			if (current->right != nullptr)
			{
				queue.push(current->right);
			}
		}

		if (sum > maxSum)
		{
			maxSum = sum;
			maxLevel = level;
		}
	}

	std::cout << "Level: " << maxLevel << " Sum: " << maxSum << "\n";
}

int main()
{
	TreeNode* root = nullptr;
	insertData(root, "", 9);
	insertData(root, "L", 5);
	insertData(root, "LL", 8);
	insertData(root, "LR", 6);
	insertData(root, "LRL", 4);
	insertData(root, "LRR", 7);
	insertData(root, "R", 2);
	insertData(root, "RL", 1);
	insertData(root, "RR", 3);
	insertData(root, "RRL", 9);

	findMaxSum(root);

	return 0;
}
