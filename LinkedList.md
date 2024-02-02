# Linked List

- singly linked list
  -   without tail pointer
  -   with tail pointer
-   doubly linked list
  
----

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
----
## Size 

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
----
