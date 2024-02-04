# Linked List
![2024-02-04](https://github.com/HelanaNady/DataStructure/assets/84867341/3d686016-6a54-45ce-9e4f-34386f164d4d)


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

## Functions implemented:

- [size](#size)
- empty
- value_at(index)
- push_front(value)
- push_back(value)
- pop_back()
- front()
- back()
- erase(index)
- reverse()
- remove_value(value) 

----
## Node 

```cpp
class Node
{
public:
    int num;
    Node *next;
    Node()
    {
        num = 0;
        next = NULL;
    }
    Node(int num)
    {
        this->num = num;
        next = NULL;
    }
};
```

## size 

```cpp
int LinkedList :: size()
{
    int size = 0;
    Node *ptr = head;

    while (ptr != nullptr)
    {
        size++;
        ptr = ptr->next;
    }
    return size;
}
```
## empty

```cpp

bool empty()
{
    if (head == nullptr)
        return true;
    else
        return false;
}
```

## push_front 
- Time complexity = O(1)

```cpp
void push_front(int num)
{
    // allocate a new node for num
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

## push_back()
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

    // if node inserted isn't the first one -> iterate till u reach end of list (NULL)
    Node *ptr = head;
    while (ptr->next != nullptr)
    {
        ptr = ptr->next;
    }
    // exit while loop when next is null, set it to point to new node inserted
    ptr->next = newNode;
}
```

## reverse 

Using two pointers: 
```cpp
void reverse()
{
    // if list is empty or contains only 1 node there is nothing to reverse
    if (size() <= 1)
        return;

    // we need two pointers to reverse list (again because this is singly linked list)
    Node *prev = NULL;
    Node *current = head;

    while (current) // current != nullptr
    {
        // node 1 -> node 2 -> node 3
        // prev      current   temp

        Node *temp = current->next;
        current->next = prev;
        // move pointers
        prev = current;
        current = temp;
    }
}
```
Using recursion:
//to be implemented 

## remove
```cpp

void remove(int num)
{
    if (head == NULL)
    {
        cout << "list is empty nothing to delete! \n";
        return;
    }

    if (head->num == num)
    {
        delete head;
        head = nullptr;
        return;
    }

    // assuming element deleted isn't the first node at the list
    Node *ptr1 = head;       
    Node *ptr2 = head->next; 

    while (ptr2 != nullptr)
    {
        if (ptr2->num == num)
        {
            // ptr1 -> ptr2 (to be deleted) -> node3
            // connect ptr1 with the node 3
            ptr1->next = ptr2->next;
            delete ptr2;
            ptr2 = nullptr;
            return;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
}
```








