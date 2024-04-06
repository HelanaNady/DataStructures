# BinaryTrees
A ***tree data structure*** is a hierarchical [nonlinear](https://www.geeksforgeeks.org/difference-between-linear-and-non-linear-data-structures/) structure that is used to represent and organize data in a way that is easy to navigate and search. It is a collection of nodes that are connected by edges and has a hierarchical relationship between the nodes.
## Contents 
- [Important terminologies](#important-terminologies)
- [Types of trees](#Types-of-trees)
- [Heights of a Binary Tree](#Heights-of-a-Binary-Tree)
- [The ADT Binary Tree implementations](#The-ADT-Binary-Tree-implementations)
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
- [Binary Search Tree BST](https://github.com/HelanaNady/DataStructures/blob/Trees-changes/ValueOrientedTrees.md#binary-search-trees)
- [AVL Trees](https://github.com/HelanaNady/DataStructures/blob/Trees-changes/ValueOrientedTrees.md#avl-trees)

----
## Generic Trees
Generic trees are a collection of nodes where each node is a data structure that consists of records and a list of references to its children(duplicate references are not allowed). Unlike the linked list, each node stores the address of multiple nodes. Every node stores address of its children and the very first node’s address will be stored in a separate pointer called root.

The Generic trees are the N-ary trees which have the following properties: 

 1) Many children at every node.</br>
2) The number of nodes for each node is not known in advance.<br>
[For more info](https://www.geeksforgeeks.org/generic-treesn-array-trees/)

## Binary Trees
 A binary Tree is defined as a Tree data structure with at most 2 children. Since each element in a binary tree can have only 2 children, we typically name them the left and right child.
 Types of BTs: </br>
 - Full BT (based on number of nodes) </br>
![Screenshot 2024-04-01 020310](https://github.com/HelanaNady/DataStructures/assets/137416623/9a869627-b0d5-4d66-97ac-c570987690d0)

 all nodes that are at a level less than h have two children each. </br>
 
 - Complete BT (based on levels completion) </br>
![Screenshot 2024-04-01 020358](https://github.com/HelanaNady/DataStructures/assets/137416623/d1bc4e09-e160-4808-90cf-60a1f597886d)

 A complete binary tree of height h is a binary tree that is full down to level h – 1, with level h filled in from left to right. </br>
 
 - Balanced BT (based on levels completion) </br>
![image](https://github.com/HelanaNady/DataStructures/assets/137416623/bbd05f55-3c13-4391-b6f4-67ebee9b4663) </br>
 A binary tree is height balanced, or simply balanced, if the height of any node’s right sub-tree differs from the height of the node’s left subtree by no more than 1.
-------
## Heights of a Binary Tree
*for a BT with n nodes*
- Max height :
```math
h = n
```
- min height --> Fill each level of tree as completely as possible 
```math
h = ceil (log_2(n + 1) )
```
 *for a BT with height h*
 - max number of nodes : 
 ```math
n = 2^{h} - 1
```
- min number of nodes : 
```math
n = h
```

----
## The ADT Binary Tree implementations 
- [Binary Node class](#BinaryNode)
- [BinaryTreeInterface class](#BinaryTreeInterface)
- [BinaryNodeTree ](#BinaryNodeTree)
### BinaryNode

```cpp
template <typename T>
class BinaryNode
{
private:
	T item; // Data portion
	BinaryNode<T>* leftChildPtr; // Pointer to left child
	BinaryNode<T>* rightChildPtr; // Pointer to right child
public:
	BinaryNode();
	BinaryNode(const T& anItem, BinaryNode<T>* leftPtr = nullptr, BinaryNode<T>* rightPtr = nullptr);
	void setItem(const T& anItem);
	T getItem() const;
	bool isLeaf() const;
	BinaryNode<T>* getLeftChildPtr() const;
	BinaryNode<T>* getRightChildPtr() const;
	void setLeftChildPtr(BinaryNode<T>* leftPtr);
	void setRightChildPtr(BinaryNode<T>* rightPtr);
};

```

### BinaryTreeInterface

```cpp
#include "BinaryNode.h"

template <typename T>
class BinaryTreeInterface
{
public:
	/** Tests whether this binary tree is empty.
	@return True if the binary tree is empty, or false if not. */
	virtual bool isEmpty() const = 0;
	/** Gets the height of this binary tree.
	@return The height of the binary tree. */
	virtual int getHeight() const = 0;
	/** Gets the number of nodes in this binary tree.
	@return The number of nodes in the binary tree. */
	virtual int getNumberOfNodes() const = 0;
	/** Gets the data that is in the root of this binary tree.
	@pre The binary tree is not empty.
	@post The root’s data has been returned, and the binary tree is unchanged.
	@return The data in the root of the binary tree. */
	virtual T getRootData() const = 0;
	/** Replaces the data item in the root of this binary tree
	with the given data, if the tree is not empty. However, if the tree is empty, 
	inserts a new root node containing the given data into the tree. 
	@pre None.
	@post The data in the root of the binary tree is as given.
	@param newData The data for the root. */
	virtual void setRootData(const T& newData) = 0;
	/** Adds a new node containing the given data to this binary tree.
	@param newData The data for the new node.
	@post The binary tree contains a new node.
	@return True if the addition is successful, or false not. **/
		virtual bool add(const T & newData) = 0;
	/** Removes the node containing the given data item from this binary tree.
	@param data The data value to remove from the binary tree.
	@return True if the removal is successful, or false not. */
		virtual bool remove(const T & data) = 0;
	/** Removes all nodes from this binary tree.*/
	virtual void clear() = 0;
	/** Gets a specific entry in this binary tree.
	@post The desired entry has been returned, and the binary tree
	is unchanged. If no such entry was found, an exception is thrown.
	@param anEntry The entry to locate.
	@return The entry in the binary tree that matches the given entry.
	@throw NotFoundException if the given entry is not in the tree. */
	virtual T getEntry(const T& anEntry) const throw(NotFoundException) = 0;
	/** Tests whether a given entry occurs in this binary tree.
	@post The binary search tree is unchanged.
	@param anEntry The entry to find.
	@return True if the entry occurs in the tree, or false if not. */
	virtual bool contains(const T& anEntry) const = 0;
	/** Traverses this binary tree in preorder (inorder, postorder) and
	calls the function visit once for each node.
	@param visit A client-defined function that performs an operation on
	or with the data in each visited node. */
	virtual void preorderTraverse(void visit(T&)) const = 0;
	virtual void inorderTraverse(void visit(T&)) const = 0;
	virtual void postorderTraverse(void visit(T&)) const = 0;
};
```
### BinaryNodeTree 
- Functions implemented:
	- [constructors](#constructors)
	- [copyTree(..)](copyTree)
	- [destroyTree(..) and destructor](#destroyTree)
	- [getHeightHelper(..) and getHeight()](#getHeightHelper)
	- [getNumberOfNodesHelper() and getNumberOfNodes()](#getNumberOfNodesHelper)
	- [balancedAdd(..) and add(..)](#balancedAdd)
	- [Depth First Traversing](#Depth-First-Traversing)
	- [Breadth First Traversing](#Breadth-First-Traversing)
- header file:
>[!Note]
>public ADT methods usually are not themselves
 recursive, but rather call a recursive method that is either private or protected. We do this to hide the
 underlying data structure from the client.

```cpp
#include "BinaryTreeInterface.h"
#include "BinaryNode.h"

template <typename T>
class BinaryNodeTree : public BinaryTreeInterface<T>
{
public:
	BinaryNode<T>* rootPtr;
	BinaryNodeTree();
	BinaryNodeTree(const T rootItem, const BinaryNodeTree<T>* leftTreePtr = nullptr, const BinaryNodeTree<T>* rightTreePtr = nullptr);
	BinaryNodeTree(const BinaryNodeTree<T>& aTree); //copy constructor
	virtual ~BinaryNodeTree();
	
	//-------------
	// Public Interface methods section
	//-------------
	bool isEmpty() const;
	int getHeight() const;
	int getNumberOfNodes() const;
	T getRootData() const throw(PrecondViolatedExcep);
	void setRootData(const T& newData);
	bool add(const T& newData); // Adds a node
	bool remove(const T& data); // Removes a node
	void clear();
	T getEntry(const T& anEntry) const throw(NotFoundException);
	bool contains(const T& anEntry) const;

	void preorderTraverse() const;
	void inorderTraverse() const;
	void postorderTraverse() const;
	void levelorderTraverse() const;
	
	//-------------
	// Protected utility helper (recursive) methods
	//-------------
	int getHeightHelper(BinaryNode<T>* subTreePtr) const;
	int getNumberOfNodesHelper(BinaryNode<T>* subTreePtr) const;
	void destroyTree(BinaryNode<T>* subTreePtr);
	BinaryNode<T>* balancedAdd(BinaryNode<T>* subTreePtr, BinaryNode<T>* newNodePtr);
	BinaryNode<T>* removeValue(BinaryNode<T>* subTreePtr, const T target, bool& success);
	BinaryNode<T>* moveValuesUpTree(BinaryNode<T>* subTreePtr);
	BinaryNode<T>* findNode(BinaryNode<T>* treePtr, const T& target, bool& success) const;
	BinaryNode<T>* copyTree(const BinaryNode<T>* treePtr) const;

	void preorder(BinaryNode<T>* treePtr) const;
	void inorder(BinaryNode<T>* treePtr) const;
	void postorder(BinaryNode<T>* treePtr) const;
	void levelorder(BinaryNode<T>* treePtr) const;
};
```

-------
### copyTree
uses a **recursive** preorder traversal to copy each node in the tree. By copying each node as soon as the traversal visits it, copyTree can make an exact copy of the original tree. To make the copy distinct from the original tree, the new nodes must be linked together by using new pointers. That is, you cannot simply copy the pointers in the nodes of the original tree. The result is a deep copy of the tree.
```cpp
template<typename T>
inline BinaryNode<T>* BinaryNodeTree<T>::copyTree(const BinaryNode<T>* treePtr) const
{
	BinaryNode<T>* newTreePtr = nullptr;
	if (treePtr)
	{
		newTreePtr = new BinaryNode<T>*(treePtr->getItem());

		newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
		newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
	}
	return newTreePtr;
}
```
The copy constructor then uses this method as follows:
```cpp
template<typename T>
inline BinaryNodeTree<T>::BinaryNodeTree(const BinaryNodeTree<T>& aTree)
{
	rootPtr = copyTree(aTree.rootPtr);
}
```

---
### destroyTree
the protected method destroyTree , which the destructor calls, uses a recursive postorder
traversal to delete each node in the tree. A postorder traversal is appropriate here because you can delete a node only after you have fi rst traversed and deleted both of its subtrees.
```cpp
template<typename T>
inline void BinaryNodeTree<T>::destroyTree(BinaryNode<T>* subTreePtr)
{
	if (subTreePtr)
	{
		destroyTree(subTreePtr->getLeftChildPtr());
		destroyTree(subTreePtr->getRightChildPtr());
		delete subTreePtr;
	}
}
```

The destructor only needs to call it:

```cpp
template<typename T>
inline BinaryNodeTree<T>::~BinaryNodeTree()
{
	destroyTree(rootPtr);
}
```

-----
### getHeightHelper
```cpp
template<typename T>
inline int BinaryNodeTree<T>::getHeightHelper(BinaryNode<T>* subTreePtr) const
{
	if (subTreePtr)
	{
		int left = getHeightHelper(subTreePtr->getLeftChildPtr());
		int right = getHeightHelper(subTreePtr->getRightChildPtr());
		return 1 + std::max(x, y);
	}
	else
		return 0;
}
```

while getHeight() just calls it.

-----
### getNumberOfNodesHelper

similar to getting the height of a tree
```cpp
template<typename T>
inline int BinaryNodeTree<T>::getNumberOfNodesHelper(BinaryNode<T>* subTreePtr) const
{
	if (subTreePtr)
	{
		return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + getNumberOfNodes(subTreePtr->getRightChildPtr());
	}
	else
		return 0;
}
```
while getNumberOfNodes() just calls it.

---
### balancedAdd
Adds the new node so that the resulting tree is balanced (to the shorter subtree)
```cpp
template<typename T>
inline BinaryNode<T>* BinaryNodeTree<T>::balancedAdd(BinaryNode<T>* subTreePtr, BinaryNode<T>* newNodePtr)
{
	if (subTreePtr == nullptr)
		return newNodePtr;
	BinaryNode<T>* leftPtr = subTreePtr->getLeftChildPtr();
	BinaryNode<T>* rightPtr = subTreePtr->getRightChildPtr(); 
	if (getHeightHelper(rightPtr) < getHeightHelper(leftPtr))
	{
		leftPtr = balancedAdd(leftPtr, newNodePtr);
		subTreePtr->setLeftChildPtr(leftPtr);
	}
	else
	{
		rightPtr = balanced(rightPtr, newNodePtr);
		subTreePtr->setRightChildPtr(rightPtr);
	}

	return subTreePtr;
}
```
 
 while The add(..) function creates the new node and calls it as follows:
 ```cpp
 template<typename T>
inline bool BinaryNodeTree<T>::add(const T& newData)
{
	BinaryNode<T>* newNodePtr = new BinaryNode(newData);
	rootPtr = balancedAdd(rootPtr, newNodePtr);
	return true;
}
```

-----
### Depth first traversing 

- #### preorder traversing

![preorder](https://github.com/HelanaNady/DataStructures/assets/137416623/13dafe33-c7e7-4642-b757-a65ca0acc3bf)
 </br>
```cpp
template<typename T>
inline void BinaryNodeTree<T>::preorder(BinaryNode<T>* treePtr) const
{
	if (treePtr)
	{
		// Do something supposedly, print
		std::cout << treePtr->getItem() << " ";
		preorder(treePtr->getLeftChildPtr());
		preorder(treePtr->getRightChildPtr());
	}
}
```

- #### postorder traversing

![postorder](https://github.com/HelanaNady/DataStructures/assets/137416623/04c63ad3-d0dc-415e-8e56-69c2d69d3dbb)


```cpp
template<typename T>
inline void BinaryNodeTree<T>::postorder(BinaryNode<T>* treePtr) const
{
	if (treePtr)
	{
		preorder(treePtr->getLeftChildPtr()); 
		preorder(treePtr->getRightChildPtr()); 
		// Do something supposedly, print
		std::cout << treePtr->getItem() << " "; 
	}
}
```

- #### inorder traversing
![inorder](https://github.com/HelanaNady/DataStructures/assets/137416623/6a0c1b00-1701-4fb6-b156-63bcb9287ab9)


```cpp
template<typename T>
inline void BinaryNodeTree<T>::inorder(BinaryNode<T>* treePtr) const
{
	if (treePtr)
	{
		preorder(treePtr->getLeftChildPtr());
		// Do something supposedly, print
		std::cout << treePtr->getItem() << " "; 
		preorder(treePtr->getRightChildPtr()); 
	}
}
```

> while the three public traversal functions just call them

### Breadth first traversing


A queue is needed to store the address of the skipped nodes. </br>
![levelorder](https://github.com/HelanaNady/DataStructures/assets/137416623/33383513-7a1b-4540-81ee-422372c1328d)


```cpp
template<typename T>
inline void BinaryNodeTree<T>::levelorder(BinaryNode<T>* treePtr) const
{
	std::queue<BinaryNode<T>*> Nodesqueue;
	Nodesqueue.push(rootPtr);

	while (!Nodesqueue.empty())
	{
		BinaryNode<T>* currentPtr = Nodesqueue.front();
		// Do something supposedly, print
		std::cout << currentPtr->getItem() << " ";
		if (currentPtr->getLeftChildPtr())
			Nodesqueue.push(currentPtr->getLeftChildPtr());
		if (currentPtr->getRightChildPtr())
			Nodesqueue.push(currentPtr->getRightChildPtr());
	}
}
```

## Useful articles 
- [geeksforgeeks intro to trees ds](https://www.geeksforgeeks.org/introduction-to-tree-data-structure-and-algorithm-tutorials/)
- [4 ways to traverse binary trees](https://dev.to/abdisalan_js/4-ways-to-traverse-binary-trees-with-animations-5bi5)

## Useful videos 
- [Binary Tree Algorithms crash course | FreeCodeCamp.](https://youtu.be/fAAZixBzIAI?si=vqc78enJtVhrr8kS)
- [Simplest Binary Tree Traversal trick for preorder inorder postorder](https://www.youtube.com/watch?v=WLvU5EQVZqY&pp=ygUMYmluYXJ5IHRyZWVz )
- [Converting to Binary Trees](https://youtu.be/TE2-Zs2QTTw?si=bZyLPhIJ3VGC1LqO)
- [Tree Traversals | William Fiset](https://www.youtube.com/watch?v=k7GkEbECZK0&list=PLDV1Zeh2NRsB6SWUrDFW2RmDotAfPbeHu&index=27)
- [Breadth First Traversal | Coderbyte](https://www.youtube.com/watch?v=dfaKCrJ2HAk)
- [Depth First Traversal | Coderbyte](https://www.youtube.com/watch?v=fPz40W9mfCg)
- [Trees leetcode playlist | neetcode](https://www.youtube.com/playlist?list=PLot-Xpze53ldg4pN6PfzoJY7KsKcxF1jg)


## For practice
- [Coding Interview Questions | TakeUforward](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)
- [Binary Tree leetcode problem set](https://leetcode.com/tag/binary-tree/)

