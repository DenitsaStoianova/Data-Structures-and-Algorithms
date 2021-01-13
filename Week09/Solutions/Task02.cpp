#include "pch.h"
#include <iostream>
#include <vector>
#include <string>

struct TreeNode
{
	char data;
	std::vector<TreeNode*> children;
};

// 1. Конструиране на дърво с много наследници от символен низ
TreeNode* constructTreeHelp(TreeNode* &root, const char* &charTree)
{
	char ch = *charTree;
	root->data = ch;
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

// 2. Превръщане на дърво с много наследници в символен низ
void convertToStringHelp(TreeNode* &root, std::string& res)
{
	if (root == nullptr)
	{
		return;
	}

	res += root->data;
	size_t size = root->children.size();
	if (size > 0)
	{
		res += "[";
		for (size_t i = 0; i < size; i++)
		{
			res += "(";
			convertToStringHelp(root->children[i], res);
			res += ")";
		}
		res += "]";
	}
}

const std::string convertToString(TreeNode* &root)
{
	std::string resultString;
	resultString += '(';
	convertToStringHelp(root, resultString);
	resultString += ')';

	return resultString;
}

int main()
{
	std::string stringTree = "(A[(C[(H)(F)])(B)(P[(K)(M)(V)])])";
	TreeNode* tree = constructTree(stringTree);

	std::string convertedTree = convertToString(tree);
	std::cout << convertedTree;

	return 0;
}
