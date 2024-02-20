# Linked List
![image](https://github.com/HelanaNady/DataStructure/assets/84867341/14b90c3e-8d37-410e-bce4-cbacc41dbe3f)

## Resources

- [Linked lists in 4 minutes ](https://www.youtube.com/watch?v=F8AbOfQwl1c)
- [CS50 lec 05 - Data Structures](https://www.youtube.com/watch?v=0euvEdPwQnQ&t=4342s)
- [Singly-Linked Lists - CS50 Shorts](https://www.youtube.com/watch?v=zQI3FyWm144)
- [Doubly-Linked Lists - CS50 Shorts](https://www.youtube.com/watch?v=FHMPswJDCvU)
- [Linked Lists by Jenny](https://www.youtube.com/playlist?list=PLnccP3XNVxGrks-guEVjE1xj9V9YC5oQ7)
- [LinkedList - Leetcode problems playlist ](https://www.youtube.com/playlist?list=PLot-Xpze53leU0Ec0VkBhnf4npMRFiNcB)

## Contents
- [Singly linked list](#Singly-linked-list)
- doubly linked list
- circular linked list
- [Techniques for linked list problems](Techniques-for-linked-list-problems)

## For practice
**Leetcode** </br>
- [Singly linked list problems](https://leetcode.com/tag/linked-list/)
- [Doubly linked list problems](https://leetcode.com/tag/doubly-linked-list/l)

----

## Singly linked list

> [!Note]
> The main difference between ADT bag and ADT list is: an ADT bag is neither value oriented nor position oriented while the ADT list is position oriented. 
> 
> ADT bag is simply a container that holds objects in no order, while in ADT list you indicate the order, since they are both very similar we will cover the general functionality of both together.

<br/>

**Implemented:**
- [Node class](#Node)
- [Copy constructor](#Copy-constructor)
- [size](#size)
- [empty](#empty)
- [add](#add)
- [remove](#remove)
- [reverse](#reverse)


## Node 

```cpp
template <typename T>
class Node
{
public:
    T item;
    Node<T>* next;

    Node() : data(0), next(nullptr) {}
    Node(T value) : data(value), next(nullptr) {}
};
```
> [!WARNING] 
> It is a common mistake to think that before you can assign
> headPtr a value, you first must create a new Node object. This misconception is rooted in
> the belief that the variable headPtr does not exist if it does not point to a node. This is not
> at all true; headPtr is a pointer variable waiting to be assigned a value. Thus, for example, you can assign nullptr to headPtr without fi rst using new . In fact, the sequence: </br>
 > ```cpp
> headPtr = new Node; // An incorrect use of new
> headPtr = nullptr;
> ```
> destroys the content of the only pointer— headPtr—to the newly created node. Thus, you have needlessly created a new node and then made it
> inaccessible. This action creates a memory leak in your program and should be avoided!
----
## Copy constructor 
When copying an object involves only copying the values of its data members, the copy is called a shallow copy. If a shallow copy is sufficient, you can omit the copy constructor, in which case the compiler generates a copy constructor that performs a shallow copy. </br>
The copy constructor makes a copy of an object. It is invoked implicitly when you either pass an object to a function by value, return an object from a valued function, or define and initialize an object. </br>


![copyconstructor](https://github.com/HelanaNady/DataStructure/assets/137416623/47cb7c87-500f-4408-8d54-96e902cb9248)


If we need to create a copy of the linked chain, we must write own own copy constructor. That is, a deep copy is needed </br>

```cpp
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& aList)
{
    itemCount = aList->itemCount;
    Node<T>* origChainPtr = aList->headPtr;
    if (origChainPtr == nullptr)
        headPtr = nullptr; // Original bag is empty; so is copy
    else
    {
        // Copy first node
        headPtr = new Node<T>();
        headPtr->item = origChainPtr->item;
        // Copy remaining nodes
        Node<T>* newChainPtr = headPtr; // Last-node pointer
        while (origPtr != nullptr)
        {
            origChainPtr = origChainPtr->next; // Advance pointer
            // Get next item from original chain
            T nextItem = origChainPtr->item;
            // Create a new node containing the next item
            Node<T>* newNodePtr = new Node<T>(nextItem);
            // Link new node to end of new chain
            newChainPtr->next = newNodePtr;
            // Advance pointer to new last node
            newChainPtr = newChainPtr->next;
        } // end while
        newChainPtr->next = nullptr; // Flag end of new chain
    } // end if
} // end copy constructor
```

## size 

```cpp
template <typename T>
int LinkedList<T>::size() const
{
    int size = 0;
    Node<T>* currPtr = headPtr;
    while(currPtr != nullptr) 
    {
        currPtr = currPtr->next;
        size++;
    }
    return size;
}
```

## empty
returns true if empty

```cpp
template <typename T>
bool LinkedBAG<t>::isEmpty() const
{
    if (headPtr == nullptr)
        return true;
    return false;    
}
```

## add

There are many ways to add new nodes to the list, you can add the new node into a list right before its head, right after its last node, or between two adjacent nodes.

### Adding to the front

- Time complexity : O(1)
- This technique is used in stacks linked based implementation

```cpp
template <typename T>
bool LinkedList<T> :: add(const T& item)
{
    Node* newNode = new Node(item);
    newNode->next = headPtr;
    headPtr = newNode;
    itemCount++;
    return true;
}
```

### Adding to the back

#### Without  a tail pointer
- Time complexity: O(n)

```cpp
template <typename T>
bool LinkedList<T>::add(const T& item)
{
    Node* newNode = new Node(item);
    // Finding the last node
    Node* ptr = headPtr;
    while(ptr->next != nullptr)
        ptr = ptr->next;

    ptr->next = newNode;
    return true;
}
```


#### With a tail pointer
- Time complexity with tail pointer: O(1)
- This technique is used in Queues linked based implementation 

```cpp
template <typename T>
bool LinkedList<T>::add(const T& item)
{
    Node* newNode = new Node(item);

    if(headPtr == nullptr)
        headPtr = newNode;
    else 
        tailPtr->next = newNode;

    tailPtr = tailPtr->next;
    return true;
}

```

**Adding between two adjacent nodes**

```cpp
//will be implemented
```

## remove

There are several approaches to implementing the `remove` function in a linked list, each suited to different use cases and requirements: mainly you either remove by value or by position.
Removing by position can also be done in different ways: you can provide the index or allow removal only at one end of the linked list

We will cover here removing by value and by position, removal at one end is fairly easy and similar to adding logic also it is implemented in stacks and queues

**Removing by value** 

```cpp
bool LinkedList<T>::remove(const T& item)
{
    if(headPtr == nullptr)
        throw out_of_range("can not remove from an empty list");

    //check first if the removed item is the head node
    if(headPtr->item == item)
    {
        Node* newHead = headPtr->next;
        delete headPtr;
        headPtr = newHead;
        return true;
    }

    Node* prevPtr = headPtr;
    Node* currPtr = headPtr->next;

    while(currPtr != nullptr)
    {
        if(currPtr->item == item)
        {
            prevPtr->next = currPtr->next;
            delete currPtr;
            return true;
        }
        prevPtr = prevPtr->next;
        currPtr = currPtr->next;
    }

    return false; //if item not found
}

```

**Removing by position** 

![image](https://github.com/HelanaNady/DataStructure/assets/84867341/3f120f98-b70d-4067-8f21-c23c0290f4ee)


```cpp
// in progress, will be implemented
```


--- 

## reverse 
![RGIF2](https://github.com/HelanaNady/DataStructure/assets/84867341/38a6da52-5826-4cc6-9568-d8394bf4384c)

### using two pointers 

```cpp
template <typename T>
void LinkedBag<T> :: reverse()
{
    // If list is empty or contains only 1 node there is nothing to reverse
    if (headPtr == nullptr || headPtr->next == nullptr)
        return;  

    // We need two pointers to reverse list (singly linked list)
    Node<T>* prevPtr = nullptr;
    Node<T>* currPtr = headPtr;

    while (currPtr != nullptr)
    {
        Node<T>* temp = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr = currPtr;
        currPtr = temp;
    }
    headPtr = prevPtr;
}
```

### using recursion:

```cpp
template <typename T>
Node* reverse(Node<T>* headPtr)
{
    if (headPtr == nullptr || headPtr->next == nullptr)
        return headPtr;

    Node<T>* newHead = reverse(headPtr->next);
    headPtr->next->next = headPtr;
    headPtr->next = nullptr;
    return newHead;
}
```


# Techniques for linked list problems

- using two pointers
	- //prev and curr
	- fast and slow pointer
- Dummy node approach 
- Think recursively

> more things will be added as we progress

## Fast and slow pointer approach
[Fast and Slow pointer pattern in Linked list - article](https://medium.com/@arifimran5/fast-and-slow-pointer-pattern-in-linked-list-43647869ac99)

One of the most basic problems in linked lists is finding the middle node, a brute forces solution would be to loop through the linked list twice, but can that be further optimized. Imagine two cars one moving with twice the speed of the other, by the time the fast car reaches the end, the slow car will be at the middle.

Using this technique we start with two pointers at the head **slow pointer** and **fast pointer** : the slow pointer will move 1 step at a time and the fast one 2 steps.

![Pasted image 20240217142659](https://github.com/HelanaNady/DataStructure/assets/84867341/3fc7547e-efcf-448d-a3bb-0bf9330af177)


<br/> Another classic problem is detecting cycles in linked lists, if there is a cycle the fast pointer will eventually catch up with the slow pointer 

![Pasted image 20240217145700](https://github.com/HelanaNady/DataStructure/assets/84867341/158b9063-13a2-4fad-9bae-4e1ffbd2257e)

**Try solving the following problems:**
- [Remove nth node from the end of the Linked list ](https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/)
- [Linked List Cycle ](https://leetcode.com/problems/linked-list-cycle/)
- [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)
- [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)

<br/>

### Dummy node approach 

https://youtu.be/aloIxnZ4EvY?si=zVt0JYG_o1r3Ou03 <br/>

To avoid too many edge cases when inserting or deleting from a linked list a dummy node is used. Consider the following: an algorithm that traverses a linked list and deletes all nodes whose keys are negative and returns the new head 

#### Without using a dummy node

```cpp
Node* DeleteNegatives(Node* headPtr)
{
    Node* currPtr = headPtr;
    while (currPtr != nullptr && currPtr->item < 0) //Remove all -ve items from the head
    {
        headPtr = headPtr->next;
        delete currPtr;
        currPtr = headPtr;
    }

    if (headPtr == nullptr) 
        return headPtr; //all elements were negative
        
    // If we reached here without a return, then we have at least one non-negative node
    Node* prevPtr = headPtr;
    currPtr = prevPtr->next;
    
    while (currPtr != nullptr)
    {
        if (currPtr->item < 0)
        {
            prevPtr->next = currPtr->next;
            delete currPtr;
        }
        else
            prevPtr = currPtr;
            
        currPtr = prevPtr->next;
    }
    return headPtr;
}
```

#### With a dummy node 

```cpp
Node* deleteNegative(Node* headPtr)
{
    if(headPtr == nullptr)
        return headPtr;

    Node* dummy = new Node ();
    dummy->next = headPtr; 

    Node* prevPtr = dummy;
    Node* currPtr = headPtr;

    while(currPtr != nullptr)
    {
        if(currPtr->item < 0)
        {
            prevPtr->next = currPtr->next;
            delete currPtr;
        }
        else
            prevPtr = prevPtr->next;

        currPtr = prevPtr->next;
    }
    
    headPtr = dummy->next; //the new head is whatever that dummy nodes is pointing to
    delete dummy;
    return headPtr;
}
```

Note the difference between both approaches, not using a dummy node makes the code redundant

<br/>

### Think recursively
Linked lists are recursive data structures
![Pasted image 20240217022038](https://github.com/HelanaNady/DataStructure/assets/84867341/a03abb76-9147-49c9-bfdb-24d0d2bff92f)

-----

# Doubly linked list

![Pasted image 20240207183037](https://github.com/HelanaNady/DataStructure/assets/84867341/dcb083bd-033b-41e9-87a5-ad17b041b8c8)

Each node in doubly linked lists has 2 pointers: a pointer to the previous node and another to the next node. 

![image](https://github.com/HelanaNady/DataStructure/assets/84867341/3ab8e693-9a51-4a32-af15-478978fbe3bf)


---
# Circular linked list
![image](https://github.com/HelanaNady/DataStructure/assets/84867341/9d732db4-877d-4cf1-8d25-80c58b4c4634)



