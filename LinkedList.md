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
- [size](#size)
- [empty](#empty)
- [push_front(num)](#push_front)
- [push_back(num)](#push_back)
- [Insert_at(Node* previous, num)](https://github.com/HelanaNady/DataStructure/blob/main/LinkedList.md#insert_atnodepreviousnum)
- [pop_front](#pop_front)
- [pop_back](#pop_back)
- [value_at(index)](https://github.com/HelanaNady/DataStructure/blob/main/LinkedList.md#value_at(index))
- [erase(index)](https://github.com/HelanaNady/DataStructure/blob/main/LinkedList.md#erase(index))
- [remove_value](#remove_value)
- [reverse](#reverse)

> // a note i will edit all functions to templates + put a style for the code </br>
------
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

## size 
returns the number of data elements in the list

```cpp
template <typename T>
int LinkedList<T>::size() 
{
    int size = 0;
    Node<T> *ptr = head;

    while(ptr != nullptr) 
    {
        size++;
        ptr = ptr->next;
    }
    return size;
}

```
## empty
returns true if empty

```cpp
bool empty()
{
    if (head == nullptr)
    {
        return true;
    }

    else
    {
        return false;    
    }
}
```

## push_front 

- Time complexity = O(1)

```cpp
void push_front(int num)
{
    // Allocate a new node for num
    Node *newNode = new Node(num);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}
```



## push_back

- Time complexity = O(n)
```cpp
void push_back(int num)
{
    Node *newNode = new Node(num);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    // if node inserted isn't the first one -> iterate till u reach end of list
    Node *ptr = head;
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
void reverse()
{
    // If list is empty or contains only 1 node there is nothing to reverse
    if (head == nullptr || head->next == nullptr)
    {
        return;  
    }

    // We need two pointers to reverse list (singly linked list)
    Node *prev = nullptr;
    Node *curr = head;

    while (curr != nullptr)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}
```

### using recursion:

```cpp
Node *reverse(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *newHead = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}
```


# Doubly linked list

![Pasted image 20240207183037](https://github.com/HelanaNady/DataStructure/assets/84867341/dcb083bd-033b-41e9-87a5-ad17b041b8c8)

Each node in doubly linked lists has 2 pointers: a pointer to the previous node and another to the next node. 

![image](https://github.com/HelanaNady/DataStructure/assets/84867341/3ab8e693-9a51-4a32-af15-478978fbe3bf)


----

