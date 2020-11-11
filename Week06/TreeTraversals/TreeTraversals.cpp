#include "pch.h"
#include <iostream>

//има 3 основни начина за обхождане на дървета (префикса на всеки вид ни казва кога посещаваме възелът, на който се намираме)

struct TreeNode // Предсавяне на възел от дървото
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

// Preorder (Root, Left, Right) : 1 2 4 5 3 6
// първо посещаваме текущия възел, след това съответно лявото и дясното му поддърво
void preorderTraversal(TreeNode* &root)
{
	if (root == nullptr)
	{
		return;
	}

	std::cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

// Inorder (Left, Root, Right) : 4 2 5 1 6 3
// първо посещаваме лявото поддърво на възела, след това самия него и накрая дясното му поддърво
void inorderTraversal(TreeNode* &root)
{
	if (root == nullptr)
	{
		return;
	}

	inorderTraversal(root->left);
	std::cout << root->data << " ";
	inorderTraversal(root->right);
}

// Postorder (Left, Right, Root) : 4 5 2 6 3 1
// първо посещаваме лявото и дясното поддърво на възела и накрая - самия него
void postorderTraversal(TreeNode* &root)
{
	if (root == nullptr)
	{
		return;
	}

	postorderTraversal(root->left);
	postorderTraversal(root->right);
	std::cout << root->data << " ";
}

int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(6);

	std::cout << "\nPreorder: ";
	preorderTraversal(root);

	std::cout << "Inorder: ";
	inorderTraversal(root);

	std::cout << "\nPostorder: ";
	postorderTraversal(root);


	return 0;
}
