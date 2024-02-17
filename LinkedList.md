# Linked List
![image](https://github.com/HelanaNady/DataStructure/assets/84867341/14b90c3e-8d37-410e-bce4-cbacc41dbe3f)

## Resources (in progress)

- [Linked lists in 4 minutes ](https://www.youtube.com/watch?v=F8AbOfQwl1c)
- [CS50 lec 05 - Data Structures](https://www.youtube.com/watch?v=0euvEdPwQnQ&t=4342s)
- [Singly-Linked Lists - CS50 Shorts](https://www.youtube.com/watch?v=zQI3FyWm144)
- [Doubly-Linked Lists - CS50 Shorts](https://www.youtube.com/watch?v=FHMPswJDCvU)
- [LinkedList - Leetcode problems playlist ](https://www.youtube.com/playlist?list=PLot-Xpze53leU0Ec0VkBhnf4npMRFiNcB)

## To be covered
- singly linked list
  -   without tail pointer
  -   with tail pointer
-   doubly linked list

## To be added 
- more leetcode / interview questions 
----
## For practice
**Leetcode** </br>
- [Singly linked list problems](https://leetcode.com/tag/linked-list/)
- [Doubly linked list problems](https://leetcode.com/tag/doubly-linked-list/l)
----

## Functions implemented:
- [Copy constructor](#Copy-constructor)
- [size](#size)
- [empty](#empty)
- [push_front(num)](#push_front)
- [push_back(num)](#push_back)
- [Insert_at(Node* previous, num)](https://github.com/HelanaNady/DataStructure/blob/main/LinkedList.md#insert_atnodepreviousnum)
- [pop_front](#pop_front)
- [pop_back](#pop_back)
- [value_at(index)](#value_atindex)
- [erase(index)](#eraseindex)
- [remove_value](#remove_value)
- [reverse](#reverse)

> // a note i will edit all functions to templates + put a style for the code </br>
------
## Node 

```cpp
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

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
template< class t>
LinkedBag<t>::LinkedBag(const LinkedBag<t>& aBag)
{
	itemCount = aBag->itemCount;
	Node<t>* origChainPtr = aBag->headPtr
		if (origChainPtr == nullptr)
			headPtr = nullptr; // Original bag is empty; so is copy
		else
		{
			// Copy first node
			headPtr = new Node<t>();
			headPtr->Item = origChainPtr->Item;
			// Copy remaining nodes
			Node<t>* newChainPtr = headPtr; // Last-node pointer
			while (origPtr != nullptr)
			{
				origChainPtr = origChainPtr->Next; // Advance pointer
				// Get next item from original chain
				t nextItem = origChainPtr->Item;
				// Create a new node containing the next item
				Node<t>* newNodePtr = new Node<t>(nextItem);
				// Link new node to end of new chain
				newChainPtr->Next = newNodePtr;
				// Advance pointer to new last node
				newChainPtr = newChainPtr->Next;
			} // end while
			newChainPtr->Next = nullptr; // Flag end of new chain
		} // end if
} // end copy constructor
```
---
-
## size 
returns the number of data elements in the list

```cpp
template <typename T>
int LinkedBag<T>::size() const
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

## push_front 

- Time complexity = O(1)

```cpp
template <typename T>
void LinkedBag<T> :: push_front(const T& item)
{
    Node* newNode = new Node(item);
    newNode->next = headPtr;
    headPtr = newNode;
    //itemCount++; ??
}
```

## push_back

- Time complexity = O(n)
  
```cpp
template <typename T>
void LinkedBag<T> :: push_back(const T& iteam)
{
    Node* newNode = new Node(item);

    //find the last node
    Node* ptr = headPtr;
    while (ptr->next != nullptr)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}
```
## Insert_at(Node*previous,num)
inserts a value after a certain node

```cpp
template <typename T>
Void LinkedList<T> :: Insert_at(Node* previous,T num)
{
	//check if previous node is NULL
	if (!previous)
	{
		cout << "previous can't be null\n"; 
		return;
	}
	//Prepare a new node
	Node* newnode = new Node(num);
	//insertion
	newnode->Next = previous->next;
	previous->next = newnode;
}
```

## pop_front

```cpp
int pop_front()
{
    if (head == nullptr)
    {
        throw out_of_range("can not pop from an empty list");
    }

    int num = head->num;
    Node *temp = head;
    head = head->next;
    delete temp;
    return num;
}
```

## pop_back

```cpp
int pop_back()
{
    if (head == nullptr)
    {
        throw out_of_range("can not pop from an empty list");
    }

    int num;
    
    if (head->next == nullptr)
    {
        num = head->num;
        delete head;
        head = nullptr;
        return num;
    }

    Node *prev = head;
    Node *curr = head->next;

    while (curr->next != nullptr)
    {
        prev = prev->next;
        curr = curr->next;
    }

    num = curr->num;
    prev->next = curr->next;
    delete curr;
    return num;
}
```

## value_at(index)

```cpp
int value_at(int index)
{
    if (index >= size())
    {
        throw out_of_range("index out of range");
    }

    // Keep iterating and count until u find that index
    Node *ptr = head;
    int count = 0;
    while (count != index)
    {
        count++;
        ptr = ptr->next;
    }
    return ptr->num;
}

```
----

![image](https://github.com/HelanaNady/DataStructure/assets/84867341/3f120f98-b70d-4067-8f21-c23c0290f4ee)

## erase(index)
```cpp
void erase(int index)
{
    if (index >= size())
    {
        throw out_of_range("index out of range");
    }

    // Deleting element at head
    if (index == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    
    Node *prev = nullptr;
    Node *curr = head;
    int count = 0;
    while (count != index)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }
    prev->next = curr->next;
    delete curr;
}

```
## remove_value

```cpp
void remove(int num)
{
    if (head == nullptr)
    {
        cout << "list is empty nothing to delete! \n";
        return;
    }

    if (head->num == num)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    
    Node *prev = head;       
    Node *curr = head->next; 

    while (curr != nullptr)
    {
        if (curr->num == num)
        {
            prev->next = curr->next;
            delete curr;
            return;
        }
        prev = prev->next;
        curr = curr->next;
    }
}
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

----


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

### Dummy node approach 

https://youtu.be/aloIxnZ4EvY?si=zVt0JYG_o1r3Ou03 <br/>

To avoid too many edge cases when inserting or deleting from a linked list a dummy node is used. Consider the following: an algorithm that traverses a linked list and deletes all nodes whose keys are negative and returns the new head 

#### Without using a dummy node

```cpp
Node* DeleteNegatives(Node* head)
{
    if (head == nullptr) 
        return head;

    Node* currPtr = head;
    while (ptr != nullptr && L->data < 0) //Remove all -ve items from the head
    {
        currPtr = head;
        head = head->next;
        delete currPtr;
    }

    if (head == nullptr) 
        return head; //all elements were negative
    // If we reached here without a return, then we have at least one non-negative node

    Node* prevPtr = head;
    currPtr = prev->next;
    while (currPtr != nullptr)
    {
        if (ptr->data < 0)
        {
            prevPtr->next = currPtr->next;
            delete ptr;
        }
        else
        {
            prev = currPtr;
        }
        currPtr = prevPtr->next;
    }
    return head;
}
```

#### With a dummy node 

```cpp
Node* deleteNegative(Node* head)
{
    if(head == nullptr)
        return head;

    Node* dummy = new Node ();
    dummy->next = head;

    Node* prevPtr = dummy;
    Node* currPtr = head;

    while(currPtr != nullptr)
    {
        if(currPtr->data < 0)
        {
            prevPtr->next = currPtr->next;
            delete currPtr;
        }
        else
            prevPtr = prevPtr->next;

        currPtr = prevPtr->next;
    }
    
    head = dummy->next; //the new head is whatever that dummy nodes is pointing to
    delete dummy;
    return head;
}
```

Note the difference between both approaches, not using a dummy node makes the code harder and more redundant.

-----
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



