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

void findMaxSumHelp(TreeNode* &root, int& maxSum, TreeNode* &resultNode)
{
	if (root == nullptr)
	{
		return;
	}

	int currentSum = root->data;
	int childrenSize = root->children.size();
	for (int i = 0; i < childrenSize; i++)
	{
		currentSum += root->children[i]->data;
		findMaxSumHelp(root->children[i], maxSum, resultNode);
	}

	if (currentSum > maxSum) 
	{
		maxSum = currentSum;
		resultNode = root; 
	}
}

int findMaxSum(TreeNode* &root)
{
	TreeNode* resultNode = nullptr;
	int maxSum = INT_MIN;
	findMaxSumHelp(root, maxSum, resultNode);
	return resultNode->data;
}

int main()
{
	std::string stringTree = "(1[(4[(2)(6)])(2)(5[(3)(4)(6)])])";
	TreeNode* root = constructTree(stringTree);


	std::cout << findMaxSum(root) << "\n";

	return 0;
}
