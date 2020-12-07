#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

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

int convertToNum(const std::string& str, int& index)
{
	int charToNum = 0;
	while (str[index] != ' ')
	{
		charToNum = (charToNum * 10) + (str[index] - '0');
		index++;
	}
	index++;
	return charToNum;
}

void skipSymbols(const std::string& str, int& index)
{
	int size = str.size();
	while (index != size - 1 && str[index] != '(')
	{
		index++;
	}
}

// Конструиране на двоично дърво от символин низ
void constructTreeFromStrHelp(TreeNode* &root, const std::string& stringTree, int& index)
{
	if (stringTree[index] == '(' && stringTree[index + 1] != ')')
	{
		index++;
	}
	if (index == stringTree.size() - 1 || (stringTree[index] == '(' && stringTree[++index] == ')'))
	{
		skipSymbols(stringTree, index);
		return;
	}

	int charToNum = convertToNum(stringTree, index);
	root = new TreeNode(charToNum);
	constructTreeFromStrHelp(root->left, stringTree, index);
	constructTreeFromStrHelp(root->right, stringTree, index);
}

void constructTreeFromStr(TreeNode* &root, const std::string& stringTree)
{
	int index = 0;
	constructTreeFromStrHelp(root, stringTree, index);
}

// Проверка дали двоично дърво е двоично наредено
bool isBSTHelp(const TreeNode* root, int min, int max)
{
	bool result = true;
	if (root->left == nullptr && root->right == nullptr)
	{
		return root->data >= min && root->data < max;
	}

	if (root->left != nullptr)
	{
		result = result && isBSTHelp(root->left, min, root->data);
	}

	if (root->right != nullptr)
	{
		result = result && isBSTHelp(root->right, root->data, max);
	}

	return result;
}

bool isBST(const TreeNode* root)
{
	return isBSTHelp(root, INT_MIN, INT_MAX);
}

// Превръщане на двоично дърво в символен низ
void reverseString(std::string& res, int count)
{
	char temp;
	for (int i = 0; i < count / 2; i++)
	{
		temp = res[i];
		res[i] = res[count - 1 - i];
		res[count - 1 - i] = temp;
	}
}

void convertNumberToString(std::string& str, int number)
{
	int count = 0;
	std::string res;
	while (number != 0)
	{
		res += number % 10 + '0';
		number /= 10;
		count++;
	}
	reverseString(res, count);
	str += res;
}

void convertTreeToStr(TreeNode* &root, std::string& stringTree)
{
	if (root == nullptr)
	{
		stringTree += " ()";
		return;
	}

	stringTree += stringTree.empty() ? "(" : " (";
	convertNumberToString(stringTree, root->data);

	convertTreeToStr(root->left, stringTree);
	convertTreeToStr(root->right, stringTree);
	stringTree += ")";
}

void checkTree(const std::string& infileName, const std::string& outfileName)
{
	std::ifstream infile(infileName);

	if (!infile.is_open())
	{
		std::cout << "Unable to open " << infileName << " file.\n";
		return ;
	}

	std::string stringTree;
	std::getline(infile, stringTree);

	infile.close();

	TreeNode* root = nullptr;
	constructTreeFromStr(root, stringTree);

	std::string isBstResult = isBST(root) ? "Is Binary Search Tree" : "Is Not Binary Search Tree";
	
	std::string treeToString;
	convertTreeToStr(root, treeToString);

	std::ofstream outfile(outfileName);

	if (!outfile.is_open())
	{
		std::cout << "Unable to open " << outfileName << " file.\n";
		return;
	}

	outfile << treeToString << "\n";
	outfile << isBstResult;

	outfile.close();
}

int main()
{
	checkTree("inputfile.txt", "outputfile.txt");

	return 0;
}
