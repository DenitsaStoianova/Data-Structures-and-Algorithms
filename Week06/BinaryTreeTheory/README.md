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
         	     A
                   /   \
                  B     C
                 / \   / \ 
                D   E F   G 
                   / \
                  H   I
		  
1. Root - The root is the special node from which all other nodes "descend". Each tree has a single root node.
   Root: A
2. Path - A path is a sequence of edges between nodes.
   Path between nodes A and H - A B E H
3. Siblings - Nodes with the same parent are siblings.
   Siblings: D and E, F and G
4. Ancestor of node n - Any node y on the (unique) path from root r to node n is an ancestor of node n. Every node is an ancestor of itself.
   Ancestors of F: C A
5. Descendent of n - Any node y for which n is an ancestor of y. Every node is an descendent of itself.
   Descendens of B: D and E
6. Subtrees of node n - Subtrees of node n are the trees whose roots are the children of n.
   Subtrees of A: 
         	  B         C
                 / \   	   / \ 
                D   E	  F   G 
                   / \
                  H   I
7. Degree of node n - The degree of node n is the number of children node n has.
   Degree of C: 2
8. Leaf node - A leaf node is a node with no children.
   Leaf nodes: D H I F G
9. External node - An external node is a node with no children (same as a leaf node).
   External nodes: D H I F G
10. Internal node - An internal node is a nonleaf node.
    Internal nodes: B E F C
11. Depth of node n - The depth of node n is the length of the path from root to node n.
    Depth of E: 3
12. Level d - Level d is the nodes at depth d.
    Level of tree: 4
13. Height of tree T - The height of tree T is the largest depth of any node in T.
    Height of tree: 4
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

