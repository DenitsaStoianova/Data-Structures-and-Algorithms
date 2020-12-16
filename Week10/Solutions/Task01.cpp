#include "pch.h"
#include <iostream>
#include <string>
#include <queue>

struct TreeNode
{
	std::string data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(const std::string& data, TreeNode* left = nullptr, TreeNode* right = nullptr)
	{
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

// Рекурсивно добавяне на нов елемент в дървото
//(използваме път, състоящ се от char елементи, за да определим къде точно да добавим подадения елемент)
// path е от вида: LLRLR - показва посоката, в която да се движим, за да стигнем до мястото, на което искаме да добавим елемент
void insertData(TreeNode* &root, const char* path, const std::string& data)
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
	else
	{
		insertData(root->right, path + 1, data);
	}
}

// Итеративно добавяне на нов елемент в дървото
void addEelement(TreeNode* &root, const std::string& strPath, const std::string& data)
{
	if (root == nullptr) 
	{
		root = new TreeNode(data);
		return;
	}

	TreeNode* currentRoot = root;

	size_t size = strPath.size() - 1;
	for (size_t i = 0; i < size; i++) 
	{
		if (strPath[i] == 'L')
		{
			currentRoot = currentRoot->left;
		}
		else if (strPath[i] == 'R')
		{
			currentRoot = currentRoot->right;
		}

		if (currentRoot == nullptr)
		{
			return;
		}
	}

	if (strPath[size] == 'L')
	{
		currentRoot->left = new TreeNode(data);
	}
	else if (strPath[size] == 'R')
	{
		currentRoot->right = new TreeNode(data);
	}
}

void makeSentences(TreeNode* &root)
{
	std::queue<TreeNode*> queue;
	queue.push(root);
	int level = 0;
	int size;
	std::string levelSentence;
	TreeNode* current = nullptr;

	while (!queue.empty())
	{
		size = queue.size(); // запазваме си броя на елементите на текущото ниво
		level++;
		levelSentence = ""; // защото искаме да конструираме ново изречение за всяко ниво
		while (size > 0) // премахваме всеки елемени от текущото ниво и добавяме неговите наследници в опашката
		{
			current = queue.front(); // премахваме първия възел от опашката и го обработваме
			queue.pop();
			size--;

			levelSentence += current->data + " ";

			if (current->left != nullptr) // в опашката добавяме наследниците на премахнатия първия възел (ако има такива)
			{
				queue.push(current->left);
			}
			if (current->right != nullptr)
			{
				queue.push(current->right);
			}
		}

		std::cout << level << " -> " << levelSentence << "\n";
	}
}

int main()
{
	TreeNode* root = nullptr;
	insertData(root, "", "tree");
	insertData(root, "L", "binary");
	insertData(root, "LL", "they");
	insertData(root, "LLL", "they");
	insertData(root, "LLR", "have");
	insertData(root, "LR", "are");
	insertData(root, "LRR", "at");
	insertData(root, "R", "trees");
	insertData(root, "RL", "very");
	insertData(root, "RLL", "most");
	insertData(root, "RLR", "two");
	insertData(root, "RR", "cool");
	insertData(root, "RRR", "children");

	makeSentences(root);

	return 0;
}

