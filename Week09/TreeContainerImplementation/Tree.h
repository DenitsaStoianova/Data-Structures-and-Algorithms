#pragma once
#include <vector>

/*
Представяне на дървото:
                     10
                   /  |  \
                  4   3   5 
                 / \    / | \ 
                2   6  9  2  7
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
		std::vector<TreeNode*> children; // Вектор, който пази указателите към преките наследници на възела							
	}; // използваме вектор, защото всеки възел може да има произволен брой наследници

private:
	TreeNode* root; // Указател към корена на дървото

// Помощни функции за работа с конструкторите
	TreeNode* copy(TreeNode* treeRoot); 
	void clear(TreeNode* &treeRoot);

// Помощни функции
	bool findHelp(TreeNode* treeRoot, int key) const; 
	size_t getSizeHelp(TreeNode* treeRoot) const;
	void printHelp(TreeNode* treeRoot) const;
};
