#pragma once

class BinarySearchTree
{
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree& other);
	BinarySearchTree& operator=(const BinarySearchTree& other);
	~BinarySearchTree();

	void insert(int data);
	void remove(int data);

	bool find(int key) const;
	size_t size() const;

	void printSortedAsc() const;
	void printSortedDesc() const;

private:
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

private:
	TreeNode* root;

	TreeNode* copy(TreeNode* otherRoot);
	void clear(TreeNode* &treeRoot);

	void insertHelp(TreeNode* &treeRoot, int data);
	TreeNode* removeHelp(TreeNode* &treeRoot, int data);
	TreeNode* getMinNode(TreeNode* treeRoot);

	bool findHelp(TreeNode* treeRoot, int key) const;
	size_t sizeHelp(TreeNode* treeRoot) const;
  
	void printSortedAscHelp(TreeNode* treeRoot) const;
	void printSortedDescHelp(TreeNode* treeRoot) const;
};
