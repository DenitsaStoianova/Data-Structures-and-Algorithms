#pragma once
#include <iostream>

/*
Представяне на дървото:
			      1                             1
			    / | \                          /
			   2  3  4                        2___3___4
			  / \    |          ->           /       /
			 5   6   7                      5___6   7
			/ \                            /
		       8   9                          8___9
*/

class Tree
{
public:
// Конструктори
	Tree();
	Tree(const Tree& other);
	Tree& operator=(const Tree& other);
	~Tree();

// Информативни функции
	bool find(int key) const;
	size_t getSize() const;
	void print() const;

private:
	struct TreeNode // Представяне на възел от дървото
	{
		int data; // Стойност на възела
		TreeNode* child; // Указател към най-левия наследник на възела
		TreeNode* sibling; // Указател към левия брат на възела

		TreeNode(int data, TreeNode* child = nullptr, TreeNode* sibling = nullptr)
		{
			this->data = data;
			this->child = child;
			this->sibling = sibling;
		}
	};

private:
	TreeNode* root; // Указател към корена на дървото

// Помощни функции за работа с конструкторите
	TreeNode* copy(TreeNode* treeRoot);
	void clear(TreeNode* &treeRoot);

// Помощни функции
	bool findHelp(TreeNode* treeRoot, int key) const;
	size_t getSizeHelp(TreeNode* treeRoot) const;
	void printHelp(TreeNode* r) const;
};
