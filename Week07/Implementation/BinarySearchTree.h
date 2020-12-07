#pragma once

/*
Time complexity:
-> for all operations: O(h), h - height of tree
-> worst case: O(n), height becomes n - number of nodes
-> best case: O(logn), height becomes logn
*/

class BinarySearchTree
{
public:
	// Конструктори
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree& other);
	BinarySearchTree& operator=(const BinarySearchTree& other);
	~BinarySearchTree();

	// Добавяне и изтриване на елемент
	void insert(int data);
	void remove(int data);

	// Информативни функции
	bool find(int key) const;
	size_t size() const;

	// Принтиране в сортиран вид
	void printSortedAsc() const; // възходящо - ляво, корен, дясно
	void printSortedDesc() const; // низходящо - дясно, корен, ляво

private:
	struct TreeNode // Представяне на възел от дървото
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

private:
	TreeNode* root; // Указател към корена на дървото

	// Помощни функции за работа с конструкторите
	TreeNode* copy(TreeNode* otherRoot);
	void clear(TreeNode* &treeRoot);

	// Помощни функции
	void insertHelp(TreeNode* &treeRoot, int data);
	TreeNode* removeHelp(TreeNode* &treeRoot, int data);
	TreeNode* getMinNode(TreeNode* treeRoot);

	bool findHelp(TreeNode* treeRoot, int key) const;
	size_t sizeHelp(TreeNode* treeRoot) const;

	void printSortedAscHelp(TreeNode* treeRoot) const;
	void printSortedDescHelp(TreeNode* treeRoot) const;
};
