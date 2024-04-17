# Binary Search Trees
![Pasted image 20240406040826](https://github.com/HelanaNady/DataStructures/assets/84867341/e58c9f33-9fe4-4130-8229-1807bd72152c)

Binary search trees are a special type of binary trees that satisfies the following at any node:
- All nodes in left subtree are smaller than root node 
- All nodes in the right subtree are greater than root node

## Contents 
- [Functions](#Functions)
- [Useful videos](#Useful-videos)
- [Useful articles](#Useful-articles)
- [For practice](#For-practice)

## Functions
- [Searching](#Search)
- Finding minimum
- Finding maximum
- [Insertion](#Insertion) 
- [Removing an item](#Remove) 

---

### Search

![bst-searching](https://github.com/HelanaNady/DataStructures/assets/84867341/db781cf1-3c6f-4c9c-8f19-031eeec5a012)

### Insertion

- We search for the right place to insert the new node by having a private method that gets called recursively 
- Note that here it is assumed that no duplicate values are allowed in the BST

![bst-insertion](https://github.com/HelanaNady/DataStructures/assets/84867341/a6cca796-770c-4d78-9db9-4eae10e46276)

#### insertInOrder

```cpp
template<class T>
BinaryNode<T>* BinarySearchTree<T>::insertInorder(BinaryNode<T>* subTreePtr, T target)
{
    if (subTreePtr == nullptr)
        subTreePtr = new BinaryNode<T>(target);
    else if ( target < subTreePtr->getItem())
        subTreePtr->setLeft(insertInorder(subTreePtr->getLeftChild(), target));
    else
        subTreePtr->setRight(insertInorder(subTreePtr->getRightChild(), target));

    return subTreePtr;
}
```

#### add()
- The public method that allocates calls InsertInOrder() 

```cpp
template <typename T>
bool BinarySearchTree<T>::add(const T& newItem)
{
	rootPtr = insertInOrder(rootPtr, newItem);
	return true;
}
```

> [!note]
> taking the output of a preoder traversal of a binray search tree and using it with inserInOrder will create a binary tree similar to the orignal one -> in fact this is used in the copy constructor of the tree 

### Remove 

Removing an element is more tricky than inserting we have three possible scenarios for the node to delete it can be: 
- A leaf node 
- A parent node with one child
- A parent node with 2 children nodes

*First case is quiet easy just remove the node itself by setting it to null and nothing extra need to be done* 

![image](https://github.com/HelanaNady/DataStructures/assets/84867341/935674fb-ba45-4825-8585-6342e1208dab)

*Second case: can further be divided into another two cases -> has only left child or has only the right child (both has the same solution due to symmetry)*

![image](https://github.com/HelanaNady/DataStructures/assets/84867341/3fa78133-6fe8-4ecb-9fa8-821670d84f69)

Suppose you delete that node that will leave the child node without a parent so to avoid that we  first swap parent node we want to delete with the child node -> the node we want to delete is now a leaf node and we are back to the first case 

*Third case: when the node is a parent node with 2 children*

![image](https://github.com/HelanaNady/DataStructures/assets/84867341/7cbe9d0c-9b3a-4c89-92f4-4e721dfcedc0)

> we won't be deleting the node itself directly, just like we did with case 2 we will find another node that is easier to delete and swap their items, lets call the node we want to delete N and the Node that will take its place M 

**Steps:**
1. Locate another node M that is easier to remove from the tree than the node N 
2. Copy the item that is in M to N , thus effectively removing from the tree the item originally in N 
3. Remove the node M from the tree

**Now the problem has changed to how can we find node M that satisfy the following:**
- must be greater than all elements in left sub-tree 
- must be smaller than all elements in the right sub-tree

**There are two nodes that satisifay both conditions:**
- Maximum node in the left subtree "inorder predecessor" -> rightmost child of the left subtree
- Minimum node in the right subtree "inorder successor" -> leftmost child of the rightsubtree

For example for 20:
- Inorder predecessor is 19 
- Inorder successor is 30 

<br>

**To find inorder predecessor:**
```cpp
BinaryNode<T>* current = rootPtr->getLeftChild();

while (current->getRightChild())
    current = current->getRightChild();
```

**To find inorder successor:** 
```cpp
BinaryNode<T>* current = rootPtr->getRightChild();

while (current->getLeftChild())
    current = current->getLeftChild();
```

**Recursive remove function (private)**

```cpp
template<typename T>
inline BinaryNode<T>* BinarySearchTree<T>::removeValue(BinaryNode<T>* rootPtr, const T& target, bool& success)
{
    if (rootPtr == nullptr)
        return nullptr;
    else if (target < rootPtr->getItem())
        rootPtr->setLeft(removeValue(rootPtr->getLeftChild(), target, success));
    else if (target > rootPtr->getItem())
        rootPtr->setRight(removeValue(rootPtr->getRightChild(), target, success));

    else // target is found 
    {
        if (rootPtr->getLeftChild() == nullptr)
        {
            BinaryNode<T>* temp = rootPtr->getRightChild();
            delete rootPtr;
            return temp;
        }

        else if (rootPtr->getRightChild() == nullptr)
        {
            BinaryNode<T>* temp = rootPtr->getLeftChild();
            delete rootPtr;
            return temp;
        }

        else // find min in the right subtree (in left subtree of it)
        {
            success = true;

            BinaryNode<T>* current = rootPtr->getRightChild();
            T newItem = current->getItem();

            while (current->getLeftChild())
                current = current->getLeftChild();
            rootPtr->setItem(newItem);
            rootPtr->setRight(removeValue(rootPtr->getRightChild(), newItem, success));
        }
    }
    return rootPtr;
}
```

- Now the public method that calls it, returns true if element was found and deleted 

```cpp
template<class T>
bool BinarySearchTree<T>::remove(const T& anEntry)
{
    bool success = false;
    removeValue(rootPtr, anEntry, success);
    return success;
}
```
-----

## Useful Videos
- [Intro to Binary Search Trees | William Fiset ](https://www.youtube.com/watch?v=JfSdGQdAzq8)
- [Binary Search Tree Insertion | William Fiset](https://www.youtube.com/watch?v=LwpLXm3eb6A)
- [BST Search Leetcode problem - recursive & iterative solution | neetcode ](https://www.youtube.com/watch?v=Cpg8f79luEA)
- [Binary Search Tree removal | William Fiset](https://www.youtube.com/watch?v=8K7EO7s_iFE)
- [BST removal Leetcode problem solution | neetcode](https://www.youtube.com/watch?v=LFzAoJJt92M&t=350s)
- [Balanced Binary Search tree rotations | William Fiset](https://www.youtube.com/watch?v=q4fnJZr8ztY)

## Useful Articles
- [Everything about binary search trees | medium ](https://praharshbhatt.medium.com/everything-about-binary-search-trees-insertion-deletion-searching-time-complexity-b1fd42976e77)

## For practice
- [Coding Interview Questions | TakeUforward](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)
- [Binary Tree leetcode problem set](https://leetcode.com/tag/binary-tree/)

---


# AVL Trees

Normal BST can quickly become imbalanced as its affected by the order by which we insert items into the tree 

Consider a simple example where we insert items in increasing or decreasing order it will quickly lead to an an unbalanced binary tree ex: 10, 20, 30, 40, 50, 60

There are man types of self balancing trees one of them is AVL trees

*The heights of the left and right subtrees of any node in a balanced binary tree differ by no more than*

Balance of AVL tree = Height of left subtree - Height of right subtree , -1 <= h <= 1

The basic strategy of the AVL algorithm is to monitor the shape of the binary search tree after each insertion or deletion if the tree becomes imbalanced we "rotate" it


**If the tree is left heavy**

![Pasted image 20240417200538](https://github.com/HelanaNady/DataStructures/assets/84867341/a6cd039c-1ae0-4718-b492-483eae22d3bc)

**If the tree is right heavy**
![Pasted image 20240417200632](https://github.com/HelanaNady/DataStructures/assets/84867341/ef12a17a-4915-4b70-90a4-862e8be563d8)

----

![Pasted image 20240417201236](https://github.com/HelanaNady/DataStructures/assets/84867341/17b04dff-0f86-421c-8da1-93777e69467d)

![Pasted image 20240417201309](https://github.com/HelanaNady/DataStructures/assets/84867341/540ef184-c32b-4a7f-bc1b-db8e7a801578)

![Pasted image 20240417201352](https://github.com/HelanaNady/DataStructures/assets/84867341/29f6df37-e6b4-4c90-9a36-8ca0c3d577dd)

![Pasted image 20240417201420](https://github.com/HelanaNady/DataStructures/assets/84867341/5e3d4983-8c3e-446e-90c6-d2600f4a614f)


