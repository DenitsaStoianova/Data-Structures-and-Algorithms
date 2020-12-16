#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <vector>

struct TreeNode
{
	int data;
	std::vector<TreeNode*> children;
};

int convertToNum(const char* &charArr)
{
	int num = 0;
	while (*charArr >= '0' && *charArr <= '9')
	{
		num = (num * 10) + (*charArr - '0');
		charArr++;
	}
	charArr--;
	return num;
}

TreeNode* constructTreeHelp(TreeNode* &root, const char* &charTree)
{
	root->data = convertToNum(charTree);
	charTree++;

	if (*charTree == '[')
	{
		charTree++;
		while (*charTree != ']')
		{
			if (*charTree == '(')
			{
				charTree++;
				TreeNode* child = new TreeNode();
				constructTreeHelp(child, charTree);
				root->children.push_back(child);
			}
			charTree++;
		}
		charTree++;
	}
	return root;
}

TreeNode* constructTree(const std::string& stringTree)
{
	TreeNode* root = new TreeNode();
	const char* charTree = stringTree.c_str() + 1;
	return constructTreeHelp(root, charTree);
}

void printLeaves(const std::vector<int>& leaves)
{
	std::cout << "[Leaves: ";
	size_t leavesSize = leaves.size();
	for (size_t i = 0; i < leavesSize; i++)
	{
		std::cout << leaves[i];
		(i != leavesSize - 1) ? std::cout << ", " : std::cout << "]\n";
	}
}

void printAtLevel(TreeNode* &root)
{
	std::queue<TreeNode*> queue;
	queue.push(root);
	std::vector<int> leaves;
	TreeNode* current = nullptr;
	int size;
	size_t childrenSize;
	int level = 0;

	while (!queue.empty())
	{
		size = queue.size();
		level++;
		while (size > 0)
		{
			current = queue.front();
			queue.pop();
			size--;
			childrenSize = current->children.size();

			if (childrenSize == 0)
			{
				leaves.push_back(current->data);
			}
			else
			{
				std::cout << "Node: " << current->data;
				std::cout << " [Level: " << level << "]";
				std::cout << " [Number of children: " << childrenSize << "; Children values: ";
				for (size_t i = 0; i < childrenSize; i++)
				{
					std::cout << current->children[i]->data;
					(i != childrenSize - 1) ? std::cout << ", " : std::cout << "]\n";
					queue.push(current->children[i]);
				}
			}
		}
	}

	printLeaves(leaves);
}

int main()
{
	std::string stringTree = "(10[(4[(9)(7)])(2)(5[(3)(4)(6)])(8)])";
	TreeNode* root = constructTree(stringTree);

	printAtLevel(root);

	return 0;
}
