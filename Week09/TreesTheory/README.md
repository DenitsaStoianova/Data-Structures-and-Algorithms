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

***A complete binary tree is just like a full binary tree, but with two major differences:
Every level must be completely filled
All the leaf elements must lean towards the left.
The last leaf element might not have a right sibling i.e. a complete binary tree doesn't have to be a full binary tree.***










