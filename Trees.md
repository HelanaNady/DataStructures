# Trees
A ***tree data structure*** is a hierarchical [nonlinear](https://www.geeksforgeeks.org/difference-between-linear-and-non-linear-data-structures/) structure that is used to represent and organize data in a way that is easy to navigate and search. It is a collection of nodes that are connected by edges and has a hierarchical relationship between the nodes.
## Contents 
- [Important terminologies](#important-terminologies)
- [Types of trees](#Types-of-trees)
- [Heights of a Binary Tree](#Heights-of-a-Binary-Tree)
- [Useful videos](#Useful-videos)
- [Useful articles](#Useful-articles)
- [For practice](#For-practice)
- 
![2024-02-09 (1)](https://github.com/HelanaNady/DataStructure/assets/84867341/dd08963e-4437-48af-b03b-9d19593e677e)
## Important terminologies 
- ***Parent Node:*** The node which is a predecessor of a node is called the parent node of that node. 
- ***Child Node:*** The node which is the immediate successor of a node is called the child node of that node. 
- ***Root Node:*** The topmost node of a tree or the node which does not have any parent node is called the root node.
> A non-empty tree must contain exactly one root node and exactly one path from the root to all other nodes of the tree.
- **Leaf Node or External Node:** The nodes which do not have any child nodes are called leaf nodes. 
- **Ancestor of a Node:*** Any predecessor nodes on the path of the root to that node are called Ancestors of that node. 
- ***Descendant:*** A node x is a descendant of another node y if and only if y is an ancestor of x.
- ***Sibling:*** Children of the same parent node are called siblings. 
- ***Level of a node:*** The count of edges on the path from the root node to that node. The root node has level 0.
- ***Internal node:*** A node with at least one child is called Internal Node.
- ***Neighbour of a Node:*** Parent or child nodes of that node are called neighbors of that node.
- ***Subtree***: Any node of the tree along with its descendant.

----
## Types of Trees
#### Position oriented :
- [Generic Trees (N-ary Tree)](#Generic-Trees)
- [Binary Trees](#Binary-Trees)
#### Value oriented :
- [Binary Search Tree BST](#BST)
- [AVL Trees](#AVL-Trees)

----
## Generic Trees
Generic trees are a collection of nodes where each node is a data structure that consists of records and a list of references to its children(duplicate references are not allowed). Unlike the linked list, each node stores the address of multiple nodes. Every node stores address of its children and the very first node’s address will be stored in a separate pointer called root.

The Generic trees are the N-ary trees which have the following properties: 

 1) Many children at every node.</br>
2) The number of nodes for each node is not known in advance.<br>
[For more info](https://www.geeksforgeeks.org/generic-treesn-array-trees/)

## Binary Trees
 A binary Tree is defined as a Tree data structure with at most 2 children. Since each element in a binary tree can have only 2 children, we typically name them the left and right child.
 Types of BTs:
 - Full BT (based on number of nodes)
![[Pasted image 20240401020321.png]]
 all nodes that are at a level less than h have two children each.
 
 - Complete BT (based on levels completion)
 ![[Pasted image 20240401020402.png]]
 A complete binary tree of height h is a binary tree that is full down to level h – 1, with level h filled in from left to right.
 
 - Balanced BT (based on levels completion)
 ![[Pasted image 20240401020905.png]]
 A binary tree is height balanced, or simply balanced, if the height of any node’s right sub-tree differs from the height of the node’s left subtree by no more than 1.
-----
## Heights of a Binary Tree
*for a BT with n nodes*
- Max height :
$h = n$
- min height --> Fill each level of tree as completely as possible 
$h = ceil (log_2(n + 1) )$
 *for a BT with height h*
 - max number of nodes :
 $n = 2^{h} - 1$
- min number of nodes :
$n = h$

----
## The ADT Binary Tree
-----

## Useful articles 
- [geeksforgeeks intro to trees ds](https://www.geeksforgeeks.org/introduction-to-tree-data-structure-and-algorithm-tutorials/)
- 
