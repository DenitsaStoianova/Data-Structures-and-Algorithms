# What is binary tree?

```
A binary tree is an ordered tree in which every node has at most two children.
1. Every node has at most two children.
2. Each child node is labeled as being either a left child or a right child.
3. A left child precedes a right child in the ordering of children of a node.
The subtree rooted at a left or right child of an internal node is called the node’s left subtree or right subtree, respectively.
```

# Binary Tree Representation:

```
A tree is represented by a pointer to the topmost node in tree. If the tree is empty, then value of root is nullptr.
A Tree node contains following parts.
1. Data
2. Pointer to left child
3. Pointer to right child
```

***We can represent a tree node using structures:***

```
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
```

# Tree Terminology

```


```

# Main applications of trees:

```
1. Manipulate hierarchical data.
2. Make information easy to search.
3. Manipulate sorted lists of data.
4. As a workflow for compositing digital images for visual effects.
5. Router algorithms
6. Form of a multi-stage decision-making.
```

