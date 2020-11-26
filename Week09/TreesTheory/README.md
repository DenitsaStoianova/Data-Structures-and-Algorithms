# Different Types Of Binary Trees

# Full Binary Tree

***A full Binary tree is a special type of binary tree in which every parent node/internal node has either two or no children:***

```
	             A 
                   /   \
                  B     C
                       / \ 
                      F   G 
                     / \
                    H   I
```

***Full Binary Tree Properties:***

```
I -> number of internal nodes
N -> the total number of nodes
L -> number of leaves
λ -> number of levels
```
```
1. The number of leaves is I + 1.

2. The total number of nodes is 2*I + 1.

3. The number of internal nodes is (N – 1) / 2.

4. The number of leaves is (N + 1) / 2.

5. The total number of nodes is 2*L – 1.

6. The number of internal nodes is L – 1.

7. The number of leaves is at most 2^(λ - 1).
```

# Perfect Binary Tree

***A perfect binary tree is a type of binary tree in which every internal node has exactly two child nodes and all the leaf nodes are at the same level:***

```
	             A 
                   /   \
                  B     C
                 / \    / \ 
                D   E  F   G 
```

***Perfect Binary Tree Properties:***

```
H -> height of tree
N -> the total number of nodes
```
```
1. All the internal nodes have a degree of 2.

2. The number of nodes is 2^(H + 1) – 1.

3. The height is log(N + 1) – 1 = Θ(ln(N)).

4. The number of leaf nodes is 2^H.

5. The average depth of a node is Θ(ln(N)).
```

# Complete Binary Tree

***A complete binary tree is just like a full binary tree, but with two major differences - 1) Every level must be completely filled, 2) All the leaf elements must lean towards the left, 3) The last leaf element might not have a right sibling i.e. a complete binary tree doesn't have to be a full binary tree.***

```
	             A 
                   /   \
                  B     C
                 / \   / 
                D   E F   
```

***How a Complete Binary Tree is Created?***

```
1. Select the first element of the list to be the root node. (no. of elements on level-I: 1)

2. Put the second element as a left child of the root node and the third element as the right child. (no. of elements on level-II: 2)

3. Put the next two elements as children of the left node of the second level. Again, put the next two elements as children of the right node of the second level (no. of elements on level-III: 4) elements).

4. Keep repeating until you reach the last element.
```

***A complete binary tree has an interesting property that we can use to find the children and parents of any node.***

```
- If the index of any element in the array is I
- The element in the index 2*I + 1 will become the left child 
- The element in 2*I + 2 index will become the right child. 
- Also, the parent of any element at index I is given by the lower bound of (I-1)/2.
```

# Degenerate or Pathological Tree

***A degenerate or pathological tree is the tree having a single child either left or right:***

```
	             A 
                   /   
                  B     
                   \    
                    C
		     \
		      D
```

# Skewed Binary Tree

***A skewed binary tree is a pathological/degenerate tree in which the tree is either dominated by the left nodes or the right nodes. 
Thus, there are two types of skewed binary tree: left-skewed binary tree and right-skewed binary tree.***

***Left-skewed binary tree:**

```
	            A 
                   /   
                  B     
                 /   
                C
	       /
	      D
```

***Right-skewed binary tree:**

```
	            A 
                     \
		      B
		       \
		        C
			 \
			  D
```



