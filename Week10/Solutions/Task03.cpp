#include "pch.h"
#include <iostream>
#include <queue>

struct TreeNode
{
	double data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(double data, TreeNode* left = nullptr, TreeNode* right = nullptr)
	{
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

void insertData(TreeNode* &root, const char* path, double data)
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

double sumOfAverages(TreeNode* &root)
{
	std::queue<TreeNode*> queue;
	queue.push(root);
	int size;
	double sum = 0;
	double levelSum = 0;
	double levelSize = 0;
	TreeNode* current = nullptr;

	while (!queue.empty())
	{
		size = queue.size();
		levelSum = 0;
		levelSize = size;
		while (size > 0)
		{
			current = queue.front();
			queue.pop();
			size--;
			levelSum += current->data;
			if (current->left != nullptr)
			{
				queue.push(current->left);
			}
			if (current->right != nullptr)
			{
				queue.push(current->right);
			}
		}
		sum += levelSum / levelSize;
	}
	return sum;
}

int main()
{
	TreeNode* root = nullptr;
	insertData(root, "", 9.2);
	insertData(root, "L", 5.1);
	insertData(root, "LL", 8);
	insertData(root, "LR", 6);
	insertData(root, "LRL", 4.5);
	insertData(root, "LRR", 7);
	insertData(root, "R", 2);
	insertData(root, "RL", 1);
	insertData(root, "RR", 8.9);
	insertData(root, "RRL", 3.7);

	std::cout << "Sum of averages: " << sumOfAverages(root) << "\n";

	return 0;
}
