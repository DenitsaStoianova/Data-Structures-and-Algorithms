#pragma once
#include <string>

class BinaryTree
{
public:
	// Конструктори
	BinaryTree();
	BinaryTree(const BinaryTree& other);
	BinaryTree& operator=(const BinaryTree& other);
	~BinaryTree();

	// Добавяне на нов елемент в дървото (използваме път, състоящ се от символни низове, за да определим къде точно да добавим подадения елемент)
	// strPath е от вида: LLRLR - показва посоката, в която да се движим, за да стигнем до мястото, на което искаме да добавим елемент
	void addEelement(int data, const std::string& strPath);

	// Информативни функции
	int getRootData() const;
	int getCount() const;
	bool isEmpty() const;

private:
	struct TreeNode // Представяне на възел от дървото
	{
		int data; // Стойност на възела
		TreeNode* left; // Указател, който пази връзка към лявото поддърво на възела
		TreeNode* right; // Указател, който пази връзка към дясното поддърво на възела

		TreeNode(int data, TreeNode* left = nullptr, TreeNode* right = nullptr)
		{
			this->data = data;
			this->left = left;
			this->right = right;
		}
	};
private:
	// Указател към корена на дървото
	TreeNode* root;

	// Помощни функции за работа с конструкторите
	TreeNode* copy(TreeNode* otherRoot);
	void clear(TreeNode* &treeRoot);

	// Помощна функция за намиране на броя на възлите в дървото
	int getCountHelp(TreeNode* root) const;
};
