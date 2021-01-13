#include "pch.h"
#include <iostream>
#include <vector>

struct TreeNode
{
	int data;
	std::vector<TreeNode*> children;
};

bool isDigit(char c)
{
	return c >= '0' && c <= '9';
}

int convertToNum(const char* &charArr)
{
	int charToNum = 0;
	while (isDigit(*charArr))
	{
		charToNum = (charToNum * 10) + (*charArr - '0');
		charArr++;
	}
	charArr--;
	return charToNum;
}

TreeNode* constructTreeHelp(TreeNode* &root, const char* &charTree)
{
	int data = convertToNum(charTree);
	root->data = data;
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

int countGreaterNodes(TreeNode* &root, int key)
{
	if (root == nullptr)
	{
		return 0;
	}

	int count = 0;
	if (root->data > key)
	{
		count++;
	}

	size_t size = root->children.size();
	for (size_t i = 0; i < size; i++)
	{
		count += countGreaterNodes(root->children[i], key);
	}

	return count;
}

int main()
{
	std::string stringTree = "(10[(4[(2)(6)])(3)(5[(9)(2)(7)])])";
	TreeNode* root = constructTree(stringTree);

	std::cout << countGreaterNodes(root, 6) << "\n";

	return 0;
}
